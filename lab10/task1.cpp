#include <iostream>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    // constructor
    node(int _val = 0)
    {
        val = _val;
        left = right = NULL;
    }
};

class BST
{
    node *root;

public:
    // constructor
    BST()
    {
        root = NULL;
    }

    node *insert(int _val, node *&root)
    {
        // Recursive insertion
        if (root == NULL)
        {
            root = new node(_val);
            return root;
        }
        // go left of tree of if aval is smaller
        if (_val < root->val)
            root->left = insert(_val, root->left);
        else
            // right of tree of value is greater
            root->right = insert(_val, root->right);
        return root;
    }

    void printLevelOrderNodesCount()
    {
        // function to print no. of nodes at each level of whole bianry tree
        int height = getHeight(root);
        for (int i = 1; i <= height; i++)
            cout << "No. of nodes at " << i << " Level: " << NodeAtCurrentLevel(i) << endl;
    }

    int NodeAtCurrentLevel(int lvl)
    {
        // utillity function to call countNode() function
        int height = getHeight(root);
        int count = 0;
        if (lvl <= height && lvl >= 0)
            countNodes(root, lvl, count);
        else
            cout << "Invalid level\n";
        return count;
    }
    void countNodes(node *root, int lvl, int &count)
    {
        // recursively go to required depth/height and count no. of nodes at that level
        if (root == NULL)
            return;
        if (lvl == 1)
        {
            count++;
        }
        else if (lvl > 1)
        {
            countNodes(root->left, lvl - 1, count);
            countNodes(root->right, lvl - 1, count);
        }
    }

    void BfsPrint()
    {
        // function to print nodes at each level of whole bianry tree
        cout << "\n--Tree--\n\n";
        int height = getHeight(root);
        for (int i = 1; i <= height; i++)
        {
            for (int j = height - i; j >= 0; j--)
                cout << " ";
            printCurrLvlNodes(root, i);
            cout << endl;
        }
        cout << endl;
    }

    void printCurrLvlNodes(node *root, int lvl)
    {
        // recursively go to required depth/height and print nodes at that level
        if (root == NULL)
            return;
        if (lvl == 1)
        {
            cout << root->val << " ";
        }
        else if (lvl > 1)
        {
            printCurrLvlNodes(root->left, lvl - 1);
            printCurrLvlNodes(root->right, lvl - 1);
        }
    }

    int getHeight(node *_node)
    {
        // funciton to find height of given node
        if (_node == NULL)
            return 0;
        else
        {
            int left_height = getHeight(_node->left);
            int right_height = getHeight(_node->right);

            if (left_height > right_height)
                return (left_height + 1);
            else
                return (right_height + 1);
        }
    }

    void inorder(node *root)
    {
        // inoreder traversal
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    void deleteTree(node *node)
    {
        if (node)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
    node *&getRoot()
    {
        return root;
    }

    // Destructor
    ~BST()
    {
        delete (root);
    }
};

int main()
{
    // Reg 2021468
    // Name: M. Talha Imtiaz

    // KHOOBSOORAT CODE
    //  intialization
    BST tree;
    // insertion
    tree.insert(8, tree.getRoot());
    tree.insert(3, tree.getRoot());
    tree.insert(10, tree.getRoot());
    tree.insert(1, tree.getRoot());
    tree.insert(6, tree.getRoot());
    tree.insert(14, tree.getRoot());
    tree.insert(4, tree.getRoot());
    tree.insert(7, tree.getRoot());
    tree.insert(13, tree.getRoot());

    tree.BfsPrint();
    // printing no. of nodes at current level (from root to leaf of tree)
    tree.printLevelOrderNodesCount();

    return 0;
}