#include<iostream>
using namespace std;
#define SPACE 10

class TreeNode
{

public:
    int value;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    string color;

    TreeNode()
    {
        value = 0;
    }

    TreeNode(int v)
    {
        value = v;
    }
};

class RED_BLACK
{
public:
    TreeNode *root;
    RED_BLACK() 
    {
        root = NULL;
    }
    
   void insert(TreeNode *n1)
    {
        if (root == NULL)
        {
            root = n1;
            root-> color = "B";
            cout << "Node inserted" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (n1->value == temp->value)
                {
                    cout << "Already exists" << endl;
                    return;
                }
                else if ((n1->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = n1;
                    n1 -> parent = temp;
                    cout << "Node Inserted" << endl;
                    return;
                }
                else if (n1->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((n1->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = n1;
                    n1 -> parent = temp;
                    cout << "Node Inserted" << endl;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void print(TreeNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += SPACE; // increase distance between levels

        print(r->right, space); // process right child first
        cout << endl;

        for (int i = SPACE; i < space; i++) // print current node after space count
        {
            cout << " ";
        }
        cout << r->value << "\n";
        print(r->left, space); // process left child
    }
};
int main()
{
    int op, val;
    RED_BLACK b1;
    do
    {
        cout << "Choose:" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "2. Print" << endl;

        cout << endl;
        cin >> op;

        // object is created on head memory and this is the pointer which is pointing to that object
        TreeNode *n1 = new TreeNode();
        switch (op)
        {
        case 1:
            cout << "Enter node value : " << endl;
            cin >> val;
            n1->value = val;
            b1.insert(n1);
            break;

        case 2:
            b1.print(b1.root, 5);
            break;

        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (op != 0);

    return 0;
}
