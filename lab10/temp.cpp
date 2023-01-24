#include <iostream>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    //  contructor
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
        // recursive insertion
        if (root == NULL)
        {
            root = new node(_val);
            return root;
        }
        // go on left root if value is smaller
        if (_val < root->val)
            root->left = insert(_val, root->left);
        else
            // go on right root if value is greater
            root->right = insert(_val, root->right);
        return root;
    }

    int calculateSumDifference()
    {
        // function to calculate the sum of nodes at each level
        //  and then return their difference
        int height = getHeight(root);
        int odd = 0, even = 0;
        for (int i = 1; i <= height; i++)
        {

            if (i % 2 == 0)
            {
                even += NodeAtCurrentLevel(i);
            }
            else
            {
                odd += NodeAtCurrentLevel(i);

            }
        }

        return abs(odd - even);
    }

    int NodeAtCurrentLevel(int lvl)
    {
        // utility funciotn to sum nodes at current level
        int height = getHeight(root);
        int sum = 0;
        if (lvl <= height && lvl >= 0)
            sumNodes(root, lvl, sum);
        else
            cout << "Invalid level\n";

        return sum;
    }
    void sumNodes(node *root, int lvl, int &sum)
    {
        // Calculating sum of nodes at given level
        if (root == NULL)
            return;
        if (lvl == 1)
        {
            sum += root->val;
        }
        else if (lvl > 1)
        {
            sumNodes(root->left, lvl - 1, sum);
            sumNodes(root->right, lvl - 1, sum);
        }
    }

    int getHeight(node *_node)
    {
        // Recursivley calculate the height of given node
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
        // Inorder TRAVERSAL
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    node *&getRoot()
    {
        return root;
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
    // Destructor
    ~BST()
    {
        delete (root);
    }
};

int main()
{

    BST tree;
    // insertion
    tree.insert(3, tree.getRoot());
    tree.insert(1, tree.getRoot());
    tree.insert(8, tree.getRoot());
    tree.insert(10, tree.getRoot());
    tree.insert(4, tree.getRoot());
    tree.insert(13, tree.getRoot());
    tree.insert(7, tree.getRoot());

    cout<<"inOrder: ";
    tree.inorder(tree.getRoot());

    int diff = tree.calculateSumDifference();
    cout << "\nDifference of sum of nodes at even and odd levels: " << diff << endl;

    return 0;
}