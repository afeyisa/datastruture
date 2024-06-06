//by feyisa kenenisa

// duplicates are not allowed in AVL
// rotations are used to keep avl balanced while inserting new node
// left rotation and right rotation
// Left rotation => certain nodes from right subtree move to
// left subtree, the root of the right subtree becomes the new root of the reconstructed tree
// Right rotation => certain nodes from the left subtree moves to right subtree
// the root of left subtree becomes the new root of reconstructed subtree


//template <class T>
#include<iostream>
using namespace std;
class AVL
{
public:
struct AVLNode
{
    int value;
    int balenceFactor;
    AVLNode *left;
    AVLNode *right;
};
    AVLNode *root;
    AVL(/* args */);
    ~AVL();
    void rotateToLeft(AVLNode*);
    void rotateToright(AVLNode*);
    void balanceFromLeft(AVLNode*);
    void balanceFromRight(AVLNode*);
    void insertIntoAVL(int );
};

AVL::AVL(/* args */)
{
    root = nullptr;
}

AVL::~AVL()
{
}


void AVL::rotateToLeft(AVLNode *root)
{
/* take the right child of the root
    set root pointer to the left pointer of 
    the right child 
    set right child to root
*/
    AVLNode *ptr;
    if(root == nullptr)
    {
        cout<<"error in the tree"endl;
    }
    else if(root->right == nullptr)
    {
        cout<<"no right subtree"
    }
    else
    {
        ptr = root->right;
        root->right = ptr->left;
        ptr->left = root;
        root = ptr;
    }

}


void AVL::rotateToright(AVLNode* root)
{
    /* take lift child of the root let say as L
        set right child of L to root's left child
        set L's right child to root
        set L as a root
    */
     AVLNode *ptr;
    if(root == nullptr)
    {
        cout<<"error in the tree"endl;
    }
    else if(root->left == nullptr)
    {
        cout<<"no left subtree"
    }
    else
    {
        ptr = root->left;
        root-left = ptr->right;
        ptr->right = root;
        root = ptr;

    }
}


void AVL::balanceFromLeft(AVLNode * root)
{
    /*take root left child let say as L
        check balance factor of L let say as B
        case  B = 1
        set balance factor of L to Zero
        set balance factor of root to zero
        rotate to right
        case  B = 0
        case  B = -1
    */
}



void AVL::balanceFromRight(AVLNode *)
{

}


void AVL::insertIntoAVL(int num)
{
}
