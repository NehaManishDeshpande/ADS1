 #include<malloc.h>
 #include<stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
};
 
struct ListNode* create(struct ListNode* node, int data){
    struct ListNode* temp =  (struct ListNode *)malloc(sizeof(struct ListNode *));
    temp->val = data;
    temp->next = NULL;
} 

struct ListNode* insert(struct ListNode* node, int data){
    node->next = (struct ListNode *)malloc(sizeof(struct ListNode *));
    node = node->next;
    node = create(node, data);

    return node;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode *));
    res->val = 0;
    res->next = NULL;
    struct ListNode *result = res;
    struct ListNode *p = list1, *q = list2;
    while(p != NULL && q != NULL){
          
          if(p->val <= q->val){
              result->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
              result = result->next;
              result->val = p->val;
              result->next = NULL;
              p = p->next;
          }
          else if(p->val > q->val){
              result->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
              result = result->next;
              result->val = q->val;
              q = q->next;
          }
    }
    while(p != NULL){
        result->next = (struct ListNode *)malloc(sizeof(struct ListNode *));
        result = result->next;
        result->val = p->val;
        p = p->next;
    }
    while(q != NULL){
        result->next = (struct ListNode *)malloc(sizeof(struct ListNode *));
        result = result->next;
        result->val = q->val;
        q = q->next;
    }

    return (res->next);
}