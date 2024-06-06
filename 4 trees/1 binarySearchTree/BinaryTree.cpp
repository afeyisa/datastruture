// author Feyisa kenenisa
// 2024
// filename BinaryTree.cpp

// This comment is added just to remaind that the data going to be 
// stored in BST must support operator like <,> and == 

#include<iostream>
using namespace std;

class BinaryTree
{
public:

    struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    };

    TreeNode *root;

    void deleteNode(int,TreeNode*&);
    void destroySubTree(TreeNode*);
    void makeDeletion(TreeNode*&);
    void displayInorder(TreeNode*);
    void displayPreorder(TreeNode*);
    void displayPostorder(TreeNode*);
    void insertNode(int);
    bool searchNode(int);

    void remove(int);
    void showNodeInOrder(void);
    void showNodePreOrder();
    void showNodePostOrder();


    BinaryTree();
    ~BinaryTree();
};



//finds the place where delete the node
void BinaryTree::deleteNode(int num, TreeNode *& nodeptr)
{    /*constriants must be known to delete the node means conditions be 
     fulfilled to delete the intended node*/

    if (num < nodePtr->value)
    {
        deleteNode(num, nodePtr->left);
    }

    else if (num > nodePtr->value)
    {
        deleteNode(num, nodePtr->right);
    }

    else
    makeDeletion(nodePtr);
}



void BinaryTree::makeDeletion(TreeNode *&nodeptr)
{
    /* possible node that going to be deleted 

    1 Node whith no child means leaf:
        set the parent pointer to null and delete that node 
        from the memory

    2 Node with one child (only left or only right)
        point the parent's pointer which is pointing to the node to node's 
        child and delete the node from the memory

    3 Node with two child
        find minimum value in right child
        reattach from the left subtree from the node 
        attach to left of min minimum
        delete node
 */

    if(!nodeptr->left && !nodeptr->right)
    {
        TreeNode *temp = nodeptr;
        nodeptr = nullptr;
        delete temp;
    }
    else if(!nodeptr->left && nodeptr->right)
    {
        TreeNode * temp = nodeptr;
        nodeptr = nodeptr->right;
        delete temp;
    }
    else if(nodeptr->left && !nodeptr->right)
    {
         TreeNode * temp = nodeptr;
         nodeptr =  nodeptr->left;
         delete temp;

    }
    else if(nodeptr->left && nodeptr->right)
    {

        /*
        //frist option
        TreeNode temp = nodeptr->right;
        while(temp->left)
        {
            temp = temp->left;
        }
        
        temp->left = nodeptr->left;
        TreeNode temp = nodeptr;
        nodeptr = nodeptr->right;
        delete temp;
        
        */

        // second option, i think this is better way to delete a node!
        TreeNode parent    = nodeptr;
        TreeNode successor = nodeptr->right;

        while(successor->left)
        { 
            parent    = successor;
            successor = successor->left;

        }

        nodeptr->value = successor->value;

        if(successor->right)
        {
            parent->left = successor->right;
        }
        else{
            parent->left =  nullptr;
        }
        delete successor;

    }
    else{
        cout<<"no node to delete"<<endl;
    }
}





void BinaryTree::displayInorder(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        displayInorder(nodePtr->left);
        cout<<nodePtr->value<<endl;
        displayInorder(nodePtr->right);
    }
}


void BinaryTree::displayPreorder(TreeNode *nodePtr)
{
    if(nodePtr)
    {        
        cout<<nodePtr->value<<endl;
        displayInorder(nodePtr->left);
        displayInorder(nodePtr->right);
    }
}


void BinaryTree::displayPostorder(TreeNode *)
{
    if(nodePtr)
    {        
        displayInorder(nodePtr->left);
        displayInorder(nodePtr->right);
        cout<<nodePtr->value<<endl;

    }
}



void BinaryTree::insertNode(int num)
{   /*
    1 create a new TreeNode with new value
    2 set left and right pointers to NULL
    3 check if the tree is empty mean root is nullptr
    4 if not root point it to new TreeNode
    5 but if there a nodes in the tree find the proper insertion point for new TreeNode
    */
/*FINDING PROPER PLACE FOR NEW TREENODE TO BE INSERTED*/
/*  1.  If the value of new TreeNode is less than root's value
        new TreeNode will be inserted to left subtree of root otherwise it will be inserted
        to the right one 
    2.  after deciding the path to take continue comparing until child pointer set to null to be found and that is where 
        new TreeNode will be inserted */

    TreeNode * newNode = new TreeNode;
    newNode->value = num;
    newNode->left  = nullptr;
    newNode->right = nullptr;

    if(!root){
        root = newNode;
    }
    else {
        TreeNode * nodePtr = root;
        while(nodePtr != nullptr)
        {
            if ( newNode->value < nodePtr->value )
            {   
                if(nodePtr->left == nullptr)
                {
                    nodePtr->left = newNode;
                    break;
                }
                nodePtr = nodePtr->left;

            }

            else if (newNode->value > nodePtr->value)
            {
                if(nodePtr->right==nullptr)
                {
                    nodePtr->right=newNode;
                    break;
                }
                nodePtr=nodePtr->right;
            }
            else{
                cout<<"duplicate values are found the tree"<<endl;
                break;
            }
        }

    }


}



/*   Find the node which has the same value with the given value
*/
bool BinaryTree::searchNode(int num)
{
    /*  compare the value of node with num 
        if they are equal return true
        if the value of node is greater than num take left path
        if the value of node is less than num take right path
        return false if null node reached

    */

   TreeNode *nodePtr = root;

    bool res = false;

   while(nodePtr)
   {
    if(nodePtr->value == num)
    {
        res = true;
        break;
    }
    else if(nodePtr->value < num)
    {
        nodePtr = nodePtr->right;
    }
    else id(nodePtr->value > num)
    {
        nodePtr=nodePtr->left;
    }
   }
    return res;
}


//conistructor
BinaryTree::BinaryTree()
{
    root = nullptr;
}

// distructor
BinaryTree::~BinaryTree()
{
    destroySubTree(root);
}
// subtree distructor
void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
     if(nodePtr)
    {        
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        delete nodeptr;

    }

}


/* *************** logical *************/
void BinaryTree::showNodeInOrder(void)
{
    displayInorder(root);
}

void BinaryTree::showNodePreOrder()
{
    displayPreorder(root);
}

void BinaryTree::showNodePostOrder()
{
    displayPostorder(root);
}
void BinaryTree::remove(int num)
{
    deleteNode(num,root);

}