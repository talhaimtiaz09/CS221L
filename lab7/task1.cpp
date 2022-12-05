#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node(int _val = 0)
    {
        left = right = NULL;
        this->val = _val;
    }
};

class bst
{
public:
    node *root;

    bst()
    {
        root = NULL;
    }
    void insert(node *&root, int val)
    {
        if (root == NULL)
        {
            root = new node(val);
            return;
        }
        else if (root->val > val)
            insert(root->left, val);
        else
            insert(root->right, val);
    }
    int height(node *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int lh = height(root->left);
            int rh = height(root->right);
            if (lh > rh)
                return (lh + 1);
            else
                return (rh + 1);
        }
    }
    node **getroot()
    {
        return &this->root;
    }
    void OddlevelOrderTraversal(node *root)
    {
        int height = this->height(root);

        for (int i = 1; i <= height; i+=2)
        {
            printCurrentLevel(root, i);
        }
    }



    void printCurrentLevel(node *root, int lvl)
    {
        if (root == NULL)
            return;
        else if (lvl == 1)
            cout << root->val << " ";
        else
        {
            printCurrentLevel(root->left, lvl - 1);
            printCurrentLevel(root->right, lvl - 1);
        }
    }
};
int main()
{
        bst b1, b2;

    // test case not balanced
     b1.insert(*(b1.getroot()), 8);
     b1.insert(*(b1.getroot()), 3);
     b1.insert(*(b1.getroot()), 10);
     b1.insert(*(b1.getroot()), 1);
     b1.insert(*(b1.getroot()), 6);
     b1.insert(*(b1.getroot()), 14);
     b1.insert(*(b1.getroot()), 4);
     b1.insert(*(b1.getroot()), 7);
     b1.insert(*(b1.getroot()), 13);

    // test case 2 balanced
    b2.insert(*(b2.getroot()), 10);
    b2.insert(*(b2.getroot()), 8);
    b2.insert(*(b2.getroot()), 13);
    b2.insert(*(b2.getroot()), 7);
    b2.insert(*(b2.getroot()), 9);
    b2.insert(*(b2.getroot()), 12);
    b2.insert(*(b2.getroot()), 14);
    
     cout    << "OddLevelOrderTraversal: ";
    b1.OddlevelOrderTraversal(*(b1.getroot()));
    cout << endl;
     cout    << "OddLevelOrderTraversal: ";
    b2.OddlevelOrderTraversal(*(b2.getroot()));
    cout << endl;


    return 0;
}