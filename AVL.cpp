#include <iostream>
using namespace std;
#define SPACE 10

// AVL TREE

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

    TreeNode *insert(TreeNode *r, TreeNode *n1)
    {
        if (r == NULL)
        {
            r = n1;
            return r;
        }
        else if (n1->value < r->value)
        {
            r->left = insert(r->left, n1);
        }
        else if (n1->value > r->value)
        {
            r->right = insert(r->right, n1);
        }
        else
        {
            cout << "No duplicate values allowed" << endl;
        }

        int bf = getBalanceFactor(r);

        if (bf > 1 && n1->value < r->left->value)
        {
            return rightRotate(r);
        }
        if (bf < -1 && n1->value > r->right->value)
        {
            return leftRotate(r);
        }
        if (bf > 1 && n1->value > r->left->value)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        if (bf < -1 && n1->value < r->right->value)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    int getBalanceFactor(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        return height(r->left) - height(r->right);
    }

    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = x->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return x;
    }

    int height(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }

    TreeNode *minValNode(TreeNode *r)
    {
        TreeNode *current = r;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, int v)
    {
        // base case
        if (r == NULL)
        {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted
        else
        {
            // node with only one child or no child
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minValNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }

        int bf = getBalanceFactor(r);
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
        {
            return rightRotate(r);
        }
        else if (bf == 2 && getBalanceFactor(r->left) == -1)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        else if (bf == -2 && getBalanceFactor(r->right) <= -0)
        {
            return leftRotate(r);
        }
        else if (bf == -2 && getBalanceFactor(r->right) == 1)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    TreeNode *search(TreeNode *r, int val)
    {
        if (r == NULL || r -> value == val)
        {
            return r;
        }
        else if (val < r->value)
        {
            return search(r -> left, val);
        }
        else 
        {
            return search(r -> right, val);
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
        cout << "2. Delete Node" << endl;
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
            b1.root = b1.insert(b1.root, n1);
            break;

        case 2:
            cout << "DELETE" << endl;
            cout << "Enter node value : ";
            cin >> val;
            n1 = b1.search(b1.root, val);
            if (n1 != NULL)
            {
                b1.deleteNode(b1.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
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