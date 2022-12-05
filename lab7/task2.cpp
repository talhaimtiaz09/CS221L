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
    int leavesLevel(node *root, bool &b)
    {

        if (!root)
            return 0;

        int h = this->height(root);

        int lh = leavesLevel(root->left, b);
        int rh = leavesLevel(root->right, b);

        if (lh != rh)
            b = false;

        return h;
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
    //bools
    bool isAtSameLvl1 = true;
    bool isAtSameLvl2 = true;

    //function call
    b1.leavesLevel(*(b1.getroot()), isAtSameLvl1);
    b2.leavesLevel(*(b2.getroot()), isAtSameLvl2);



    cout << "Tree 1: \n";
    if (isAtSameLvl1)
        cout << "yes all the leaves are at same level\n";
    else
        cout << "NO all the leaves are not at same level\n";
        
    cout << "Tree 2: \n";
    if (isAtSameLvl2)
        cout << "yes all the leaves are at same level\n";
    else
        cout << "NO all the leaves are not at same level\n";

    return 0;
}