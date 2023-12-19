#include <iostream>
using namespace std;

class Node
{

public:
    int key;
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class DoubleyLinkedList
{

public:
    Node *head;

    DoubleyLinkedList()
    {
        head = NULL;
    }
    DoubleyLinkedList(Node *n)
    {
        head = n;
    }

    // 1. nodeExists()
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL) // this while loop will always check whole list
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. append() - end of list
    void append(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node exists" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else if (head != NULL)
            {
                Node *ptr = head;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                n -> prev = ptr;
                cout << "Node appended" << endl;
            }
        }
    }

    //3. prepend node - at start of list
    void prepend(Node *n)
    {
        if (nodeExists(n -> key) != NULL)
        {
            cout << "Node already exists" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node prepended" << endl;
            }
            else
            {
            head -> prev = n;
            n -> next = head;
            head = n;
            cout << "Node prepended" << endl;
            }
        }
        
    }

    //4. insert node
    void insert(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists" << endl;
        }
        else
        {
            if (nodeExists(n -> key) != NULL)
            {
                cout << "node exists" << endl;
            }
            else
            {
                Node *nextnode = ptr -> next;
                
                //inserting at the end
                if (nextnode == NULL)
                {
                    ptr -> next = n;
                    n -> prev = ptr;
                    cout << "Node inserted" << endl;
                }

                //inserting in between
                else
                {
                    n -> next = nextnode;
                    nextnode -> prev = n;
                    n -> prev = ptr;
                    ptr -> next = n;
                    cout << "Node inserted" << endl;
                }
                
            }
        }
    }

    //5. delete node
    void deletenode(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Node exists" << endl;
        }
        else
        {
            if (head == NULL)
            {
                cout << "List is empty" << endl;
            }
            else if (head != NULL)
            {
                if (head -> key == k)
                {
                    head = head -> next;
                    cout << "Node unlinked" << endl;
                }
                else
                {
                    Node *nextnode = ptr -> next;
                    Node *prevnode = ptr -> prev;

                    //delete at end
                    if (nextnode == NULL)
                    {
                        prevnode -> next = NULL;
                        cout << "Node deleted" << endl;
                    }
                    //delete in between
                    else
                    {
                        prevnode -> next = nextnode;
                        nextnode -> prev = prevnode;
                        cout << "Node deleted" << endl;
                    }
                }
            }
            
        }
    }
    //6. Update node
    void update(int k, int d)
    {
        Node *ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "Node doesn't exists" << endl;
        }
        else
        {
            ptr -> data = d;
            cout << "data updated" << endl;
        }
    }

    //7. printlist
    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;

            while (temp != NULL)
            {
                cout << "( " << temp -> key << " , " << temp -> data << " )" << endl;
                temp = temp -> next;
            }
            
        }
    }
};


int main()
{
    DoubleyLinkedList obj;
    int option;
    int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.append(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prepend(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      obj.insert(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deletenode(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.update(key1, data1);

      break;
    case 6:
      obj.print();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
    return 0;
}