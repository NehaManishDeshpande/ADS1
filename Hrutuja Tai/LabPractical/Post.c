#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s", t.name);
    for(int i=0; i< t.offices_count; i++){
        printf("\n\t%d:",i);
        for(int j=0; j< t.offices->packages_count; j++){
            printf("\n\t\t%s",t.offices->packages[j].id);
        }
    } 
}


void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    town *s = source, *d = target;

    int s_index = source_office_index, t_index = target_office_index;

    int s_pack_count = (s->offices[s_index].packages_count);
    int d_pack_count = (d->offices[t_index].packages_count);

    int d_max = (s->offices[t_index].max_weight);
    int d_min = (s->offices[t_index].min_weight);

    for(int i=0; i < s_pack_count; i++){

        if((s->offices[s_index].packages->weight >= d_min) && (s->offices[s_index].packages->weight <= d_max)){

            d->offices[t_index].packages = realloc(d->offices[t_index].packages, sizeof(package*));

            d->offices[t_index].packages[(d_pack_count)] = s->offices[s_index].packages[i];

            (d_pack_count)++;
            (s_pack_count)--;
        }

        for(int x=0; x<(s_pack_count-1);x++)
        {
        s->offices[s_index].packages[i+x] = s->offices[s_index].packages[i+x+1];
        // free(s->offices[s_index].packages_count);
        // s->offices[s_index].packages = realloc(s->offices[s_index].packages , sizeof(package)*((s->offices[s_index].packages_count)));
        }
    }	
}

town town_with_most_packages(town* towns, int towns_count) {
    int A[towns_count];
    for(int i=0; i<towns_count; i++){
        A[i] = 0;
        int sum = 0;
        for(int j=0; j < towns[i].offices_count; j++){
            sum += towns[i].offices[j].packages_count;
        }
        A[i] = sum;
    }

    int max=0, max_index=-1;
    for(int i=0; i<towns_count; i++){
        if( max < A[i]){
            max = A[i];
            max_index = i;
        }
    }
    return towns[max_index];
}

town* find_town(town* towns, int towns_count, char* name) {
    int town_index = -1;
    for(int i=0; i<towns_count; i++){
        if (strcmp(name, towns[i].name) == 0){
            town_index = i;
            break;
        }
           
    }
    return (&towns[town_index]);
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
