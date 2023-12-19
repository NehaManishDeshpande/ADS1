#include<iostream>
using namespace std;

//create node class and then its object
//create singlylinkedlist class objects to link these nodes
//6 different operations on singly linked list
class Node
{
    public:
        int key; //use to access each node individually
        int data;
        Node *next; //it would point to object of the type Node

    Node()
    {
        key = 0;
        data = 0;
        next = NULL; //address is pointing to nothing
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{

public:
    Node *head; //singlyll object will points to head of the node

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    //1. Check if node exits using key value

    Node* nodeExists(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL)  //null meand uptil end of node  //IT IS THE LOGIC OF TRAVERSING
        {
            if(ptr -> key == k)
            {
            temp = ptr;
            }
            ptr = ptr -> next;
        }
        return temp;
    }

    //2. appending node - attach a node at the end

    void append(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node Exits try another" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }
            else
            {
                Node* ptr = head;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                    
                }
                ptr -> next = n;                
                cout << "Node Appended" << endl;
            }
            
        }
        
    }

    //3. Prepend node - attach a node at the start
    void prepend(Node *n)
    {
        if(nodeExists(n -> key) != NULL)
        {
            cout << "Node Exits enter another" << endl;
        }
        else
        {
            n -> next = head;
            head = n;
            cout << "Node prepended" << endl;
        }
    }

    //4. Inserting a node after a particular node in list
    void insert(int k, Node *n)
    {
        Node *ptr = nodeExists(k);

        if(ptr == NULL)
        {
            cout << "No such key" << endl;
        }
        else
        {
            if(nodeExists(n -> key) != NULL)
            {
                cout << "Node Exits enter another" << endl;
            }
            else
            {
                n -> next = ptr -> next;
                ptr -> next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
 
    //5. Delete node by unique key
    void deletenode(int k)
    {
        if(head == NULL)
        {
            cout << "list is empty" << endl;
        }
        else if(head != NULL)
        {
            if(head -> key == k)
            {
            head = head -> next;
            cout << "Node unlinked" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prev = head;
                Node *curr = head -> next;

                while (curr != NULL)
                {
                    if(curr -> key == k)
                    {
                    temp = curr;
                    curr = NULL;
                    }
                    else
                    {
                        prev = prev -> next;
                        curr = curr -> next;
                    }
                }

                if(temp != NULL)
                {
                    prev -> next = temp -> next;
                    cout << "Node unlinked" << endl;
                }
                else
                {
                    cout << "Node doesn't exist" << endl;
                }
                
            }
        }
    }

    //6. Update data
    void update(int k, int d)
    {
        Node *ptr = nodeExists(k);

        if (ptr != NULL)
        {
            ptr -> data = d;
            cout << "Data Updated" << endl;
        }
        else
        {
            cout << "Key doesn't exist" << endl;
        }
    }

    //7. Printing the list

    void printlist()
    {
        if(head == NULL)
        {
            cout << "No nodes in the list" << endl;
        }
        else
        {
            cout << "The list : " << endl;
            Node *temp = head;

            while (temp != NULL)
            {
                cout <<"( " << temp -> key <<" , " << temp -> data << " )"<< endl;
                temp = temp -> next;
            }
            
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int op;
    int key1, k1, data1;

    do
    {
        cout << "1.append()\n2.prepend()\n3.insert()\n4.delete()\n5.update()\n6.print()\n7.clear screen\n" << endl;
        cin >> op;
        Node *n1 = new Node();

        switch (op)
        {
        case 1:
            cout << "Enter key and data : " << endl;
            cin >> key1 >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.append(n1);
            break;
        
        case 2:
            cout << "Enter key and data : " << endl;
            cin >> key1 >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.prepend(n1);
            break;

        case 3:
            cout << "Enter key of the node after which you want the node to be: " << endl;
            cin >> k1;
            cout << "Enter key and data of new node: " << endl;
            cin >> key1 >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.insert(k1, n1);
            break;

        case 4:
            cout << "Enter key of node : "<< endl;
            cin >> k1;
            s.deletenode(k1);
            break;

        case 5:
            cout << "Enter key and new data : " << endl;
            cin >> key1 >> data1;
            s.update(key1, data1);
            break;

        case 6:
            s.printlist();
            break;

        case 7:
            system("cls");
            break;
        
        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (op != 0);
    
    return 0;
}