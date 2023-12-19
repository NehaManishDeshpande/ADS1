#include <iostream>
using namespace std;
#define SPACE 10

// BST
//  RECURSIVE

class TreeNode
{

public:
    int value; // also called key or data
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

    void preprint(TreeNode *r) // NLR
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->value << " ";
        preprint(r->left);
        preprint(r->right);
    }

    void inprint(TreeNode *r) // LNR
    {
        if (r == NULL)
        {
            return;
        }
        inprint(r->left); // 1.
        cout << r->value << " ";
        inprint(r->right); // 2.

        // 1. 2. when we swap these two statements it becomes  reverse in-order
    }

    void postprint(TreeNode *r) // LRN
    {
        if (r == NULL)
        {
            return;
        }
        postprint(r->left);
        postprint(r->right);
        cout << r->value << " ";
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

    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << r->value << " ";
        }
        else
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(r, i);
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
        return r;
    }

    void mirror(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        else
        {
            TreeNode *temp;

            /* do the subtrees */
            mirror(node->left);
            mirror(node->right);

            /* swap the pointers in this node */
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }

    int totalNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = totalNodes(root->left);
        int r = totalNodes(root->right);

        return 1 + l + r;
    }

    int getLeafCount(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (node->left == NULL && node->right == NULL)
        {
            return 1;
        }
        else
        {
            return getLeafCount(node->left) + getLeafCount(node->right);
        }
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
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print" << endl;
        cout << "5. Inorder" << endl;
        cout << "6. Preorder" << endl;
        cout << "7. Postorder" << endl;
        cout << "8. Height" << endl;
        cout << "9. Mirror" << endl;
        cout << "10. Total nodes" << endl;
        cout << "11. Total leaf nodes" << endl;
        cout << "12. clear" << endl;
        cout << "13. Exit" << endl;
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
            cout << "Enter node value : " << endl;
            cin >> val;
            n1 = b1.search(b1.root, val);
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
        case 4:
            b1.print(b1.root, 5);
            break;
        case 5:
            b1.inprint(b1.root);     //in order
            cout << "\n";
            break;
        case 6:
            b1.preprint(b1.root);    //pre order
            cout << "\n";
            break;
        case 7:
            b1.postprint(b1.root);   //post order
            cout << "\n";
            // b1.printBFS(b1.root); // BFS
            // cout << endl;
            break;

        case 8:
            cout << "The height : " << b1.height(b1.root) << endl;
            break;

        case 9:
            cout << "The mirror image : " << endl;
            b1.mirror(b1.root);
            b1.print(b1.root, 5);

            break;

        case 10:
            cout << "Number of nodes : " << b1.totalNodes(b1.root) << endl;

            break;

        case 11:
            cout << "Total leaf nodes : " << b1.getLeafCount(b1.root) << endl;
            break;

        case 12:
            system("cls");
            break;

        case 13:
            exit(0);
            break;

        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (op != 0);

    return 0;
}