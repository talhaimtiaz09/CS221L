#include <iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    int height;
    // constructor
    node(int _val = 0)
    {
        val = _val;
        left = right = NULL;
        height = 1;
    }
};

class avl
{

public:
    node *root;
    // constructor
    avl()
    {
        root = NULL;
    }

    int getheight(node *_node)
    {
        // return height parameter of given node
        if (_node)
            return _node->height;
        else
            return 0;
    }

    int findMax(int a, int b)
    {
        // return a if it is greater than b , else return b
        if (a > b)
            return a;
        else
            return b;
    }

    int getBalance(node *_node)
    {
        // returns the difference of height of left of node and right of node
        if (_node)
        {
            return getheight(_node->left) - getheight(_node->right);
        }
        else
            return 0;
    }

    node *leftRotate(node *_node)
    {
        // left rotation function
        node *nodeRight = _node->right;
        node *temp = nodeRight->left;

        nodeRight->left = _node;
        _node->right = temp;

        _node->height = findMax(getheight(_node->left), getheight(_node->right)) + 1;
        nodeRight->height = findMax(getheight(nodeRight->left), getheight(nodeRight->right)) + 1;
        return nodeRight;
    }
    node *rightRotate(node *_node)
    {
        // right rotation function
        node *_nodeLeft = _node->left;
        node *temp = _nodeLeft->right;

        _nodeLeft->right = _node;
        _node->left = temp;

        _nodeLeft->height = findMax(getheight(_nodeLeft->left), getheight(_nodeLeft->right)) + 1;
        _node->height = findMax(getheight(_node->left), getheight(_node->right)) + 1;
        return _nodeLeft;
    }
    node *leftRightRotate(node *_root)
    {
        // first rotate left then rotate right
        _root->left = leftRotate(_root->left);
        return rightRotate(_root);
    }
    node *rightLeftRotate(node *_root)
    {
        // first rotate right then rotate left
        _root->right = rightRotate(_root->right);
        return leftRotate(_root);
    }

    node *simpleInsert(int _val, node *_root)
    {
        // first recursively traverse to correct position in tree
        if (_root == NULL)
            return (new node(_val));
        else if (_val < _root->val)
            _root->left = simpleInsert(_val, _root->left);
        else if (_val > _root->val)
            _root->right = simpleInsert(_val, _root->right);

        return _root;
    }
    node *balancedInsert(int _val, node *_root)
    {
        // first recursively traverse to correct position in tree and then balancing it
        if (_root == NULL)
            return (new node(_val));
        else if (_val < _root->val)
            _root->left = balancedInsert(_val, _root->left);
        else if (_val > _root->val)
            _root->right = balancedInsert(_val, _root->right);
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
            // first left rotate then right
            return leftRightRotate(_root);
        }
        // right-left case
        else if (balance < -1 && _val < _root->right->val)
        { // first right rotate then left
            return rightLeftRotate(_root);
        }

        return _root;
    }

    node *minValueNode(node *_node)
    {
        node *temp = _node;

        // loop down to find the leftmost leaf
        while (temp && temp->left != NULL)
            temp = temp->left;

        return temp;
    }

    node *deleteNode(struct node *root, int key)
    {
        // base case
        if (root == NULL)
            return root;

        // If the key to be deleted is
        // smaller than the root's
        // key, then it lies in left subtree
        if (key < root->val)
            root->left = deleteNode(root->left, key);

        // If the key to be deleted is
        // greater than the root's
        // key, then it lies in right subtree
        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
        else
        {
            // node has no child
            if (root->left == NULL and root->right == NULL)
                return NULL;

            // node with only one child or no child
            else if (root->left == NULL)
            {
                node *temp = root->right;
                delete (root);
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete (root);
                return temp;
            }

            // node with two children
            struct node *temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    void inOrder(node *root)
    {
        // Inorder Traversal
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->val << " ";
            inOrder(root->right);
        }
    }

    void preOrder(node *root)
    {
        // preOrder Traversal
        if (root != NULL)
        {
            cout << root->val << " ";
            preOrder(root->left);
            preOrder(root->right);
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
        {
            cout << "_";
            return;
        }
        if (lvl == 1)
        {
            cout << root->val << " ";
        }
        else if (lvl > 1)
        {
            printCurrLvlNodes(root->left, lvl - 1);
            cout << "\t";
            printCurrLvlNodes(root->right, lvl - 1);
            cout << "\t";
            // cout<<"r";
        }
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
    ~avl()
    {
        delete (root);
    }
};

int main()
{
    //Reg 2021468
    //Name: M. Talha Imtiaz
    
    // Khoobsoorat code
    //  intialization
    avl ub_tree, b_tree;

    // simple insertion without balance
    ub_tree.root = ub_tree.simpleInsert(10, ub_tree.root);
    ub_tree.root = ub_tree.simpleInsert(20, ub_tree.root);
    ub_tree.root = ub_tree.simpleInsert(30, ub_tree.root);
    ub_tree.root = ub_tree.simpleInsert(40, ub_tree.root);
    ub_tree.root = ub_tree.simpleInsert(50, ub_tree.root);
    ub_tree.root = ub_tree.simpleInsert(25, ub_tree.root);

    cout << "---------------\n";
    cout << "Unbalanced Tree\n";
    cout << "---------------\n";
    cout << "inOrder : ";
    ub_tree.inOrder(ub_tree.root);
    cout << "\nApproximate shape of tree: \n";
    ub_tree.BfsPrint();

    // Balanced insertion
    b_tree.root = b_tree.balancedInsert(10, b_tree.root);
    b_tree.root = b_tree.balancedInsert(20, b_tree.root);
    b_tree.root = b_tree.balancedInsert(30, b_tree.root);
    b_tree.root = b_tree.balancedInsert(40, b_tree.root);
    b_tree.root = b_tree.balancedInsert(50, b_tree.root);
    b_tree.root = b_tree.balancedInsert(25, b_tree.root);
    cout << "-------------\n";
    cout << "Balanced Tree\n";
    cout << "-------------\n";
    cout << "inOrder : ";
    b_tree.inOrder(b_tree.root);
    cout << "\nApproximate shape of tree: \n";
    b_tree.BfsPrint();

    // deletion
    cout << "\n--------------\n";
    cout << "After deletion";
    cout << "\n--------------\n";
    b_tree.deleteNode(b_tree.root, 30);
    cout << "\nApproximate shape of tree: \n";
    b_tree.BfsPrint();
    return 0;
}