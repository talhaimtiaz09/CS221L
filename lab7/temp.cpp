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
    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }
    void preorder(node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    node **getroot()
    {
        return &this->root;
    }
    void levelOrderTraversal(node *root)
    {
        int height = this->height(root);

        for (int i = 1; i <= height; i++)
        {
            printCurrentLevel(root, i);
        }
    }

    vector<int> diagonalTraversalUtil(node *root)
    {
        vector<int> diagonalVals;
        if (!root)
            return diagonalVals;

        queue<node *> q;
        node *temp = root;
        while (temp)
        {
            diagonalVals.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                temp = temp->right;
            else
            {
                if (!q.empty())
                {
                    temp = q.front();
                    q.pop();
                }
                else
                    temp = NULL;
            }
        }

        return diagonalVals;
    }

    void diagonalTraversal()
    {
        cout << endl
             << "Diagonal Traversal: ";
        vector<int> v = this->diagonalTraversalUtil(this->root);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
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
    bst b;
    b.insert(*(b.getroot()), 8);
    b.insert(*(b.getroot()), 3);
    b.insert(*(b.getroot()), 10);
    b.insert(*(b.getroot()), 1);
    b.insert(*(b.getroot()), 6);
    b.insert(*(b.getroot()), 14);
    b.insert(*(b.getroot()), 4);
    b.insert(*(b.getroot()), 7);
    b.insert(*(b.getroot()), 13);
    cout << "preorder: ";
    b.postorder(*(b.getroot()));
    cout << endl
         << "LevelOrderTraversal: ";
    b.levelOrderTraversal(*(b.getroot()));
    cout << endl;

    b.diagonalTraversal();

    cout << "height: " << b.height(*(b.getroot()));

    return 0;
}