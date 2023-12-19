#include <iostream>
using namespace std;
#define SPACE 10

// BST
//  NON RECURSIVE

class TreeNode
{

public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{

public:
    TreeNode *root;

    BST()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(TreeNode *n1)
    {
        if (root == NULL)
        {
            root = n1;
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

    // ITERATIVE SEARCH NOT RECURSION USING LOOPS HERE
    TreeNode *search(int val)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (val == temp->value)
                {
                    return temp;
                }
                else if (val < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
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
    BST b1;
    do
    {
        cout << "Choose:" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;

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
            cout << "Enter node value : " << endl;
            cin >> val;
            n1 = b1.search(val);
            if (n1 != NULL)
            {
                cout << "Value Found" << endl;
            }
            else
            {
                cout << "Value NOT Found" << endl;
            }
            break;

        case 3:
            b1.print(b1.root, 5);
            break;

        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (op != 0);

    return 0;
}