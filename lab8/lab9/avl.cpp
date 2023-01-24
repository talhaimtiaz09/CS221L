#include <iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    int height;

    node(int _val = 0)
    {
        val = _val;
        left = right = NULL;
        height = 1 ;
    }
};

class avl
{

public:
    node *root;
    avl()
    {
        root = NULL;
    }

    int getheight(node *_node)
    {
        if (_node)
            return _node->height;
        else
            return 0;
    }

    int findMax(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }

    int getBalance(node *_node)
    {
        if (_node)
        {
            return getheight(_node->left) - getheight(_node->right);
        }
        else
            return 0;
    }

    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = findMax(getheight(x->left), getheight(x->right)) + 1;
        y->height = findMax(getheight(y->left), getheight(y->right)) + 1;
        return y;
    }
    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        x->right = y;
        y->left = T2;

        x->height = findMax(getheight(x->left), getheight(x->right)) + 1;
        y->height = findMax(getheight(y->left), getheight(y->right)) + 1;
        return x;
    }
    node *insert(int _val, node *_root)
    {
        if (_root == NULL)
            return (new node(_val));
        else if (_val < _root->val)
            _root->left = insert(_val, _root->left);
        else if (_val > _root->val)
            _root->right = insert(_val, _root->right);
        else
            return _root;

        _root->height = 1 + findMax(getheight(_root->left), getheight(_root->right));

        int balance = getBalance(_root);
        // left-left case
        if (balance > 1 && _val < _root->left->val)
        {
            return rightRotate(_root);
        }
        // right-right case
        else if (balance < -1 && _val > _root->right->val)
        {
            return leftRotate(_root);
        }
        // left-right case
        else if (balance > 1 && _val > _root->left->val)
        {
            _root->left = leftRotate(_root->left);
            return rightRotate(_root);
        }
        // right-left case
        else if (balance < -1 && _val < _root->right->val)
        {
            _root->right = rightRotate(_root->right);
            return leftRotate(_root);
        }

        return _root;
    }

    void inOrder(node *root)
    {
        if (root != NULL)
        {
            cout << root->val << " ";
            inOrder(root->left);
            inOrder(root->right);
        }
    }
};

int main()
{
    avl tree;
    tree.root = tree.insert(10, tree.root);
    tree.root = tree.insert(20, tree.root);
    tree.root = tree.insert(30, tree.root);
    tree.root = tree.insert(40, tree.root);
    tree.root = tree.insert(50, tree.root);
    tree.root = tree.insert(25, tree.root);


    cout<<"-----\n";
    tree.inOrder(tree.root);
    return 0;
}