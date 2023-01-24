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
        // function to print& calculate the sum of nodes at each level
        //  and then return their difference
        int height = getHeight(root);
        // ts1: temporay sum1
        // ts2: temporay sum2
        int odd = 0, even = 0, ts1 = 0, ts2 = 0;

        cout << "\n--Tree--\n\n";
        for (int i = 1; i <= height; i++)
        {
            for (int j = height - i; j >= 0; j--)
                cout << " ";
            printCurrLvlNodes(root, i);

            if (i % 2 == 0)
            {
                even += NodeAtCurrentLevel(i);
                cout << "\t--sum: " << even - ts1 << endl;
                ts1 += even;
            }
            else
            {
                odd += NodeAtCurrentLevel(i);
                cout << "\t--sum: " << odd - ts2 << endl;
                ts2 += odd;
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

    int diff = tree.calculateSumDifference();
    cout << "\nDifference of sum of nodes at even and odd levels: " << diff << endl;

    return 0;
}