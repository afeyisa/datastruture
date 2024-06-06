#include <iostream>
#include <vector>
#include <list>
using namespace std;
#ifndef LinkedList_H
#define LinkedList_H
#endif


template <class T>
class LinkedList
{
    private:	// Declare a structure for the list
    friend class Stack;
    
    public:	
    struct ListNode	
    {
        T value;		
        struct ListNode *next;	
        
    }; 	

    ListNode *head;	// List head pointer

    LinkedList(void)	// Constructor
    { 
        head = NULL; 
        
    }	

    ~LinkedList(void); // Destructor
    void appendNode(T);	
    void insertNode(T);	
    void deleteNode(T);	
    void addNodeFront(T);
    void insertByIndex(T,int );
    void displayList(void);
    bool hasCycle(void);
    list<T> toArray();
    
};


// append node
template <class T>
void LinkedList<T>::appendNode(T num)
{	
    ListNode *newNode, *nodePtr; // Allocate a new node & store num
    newNode = new ListNode;	
    newNode->value = num;	
    newNode->next = NULL; // If there are no nodes in the list
    // make newNode the first node
    if (!head)		
    head = newNode;	
    else	// Otherwise, insert newNode at end
    {		// Initialize nodePtr to head of list
    nodePtr = head;		// Find the last node in the list
    while (nodePtr->next)			
       nodePtr = nodePtr->next;		
    // Insert newNode as the last node
    nodePtr->next = newNode;
    }
}


// distructor
template <class T>
LinkedList<T>::~LinkedList(void)
{
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;		
        nodePtr = nextNode;	
        
    }
}

//display list
template <class T>
void LinkedList<T>::displayList(void)
{
    ListNode *nodePtr;
    nodePtr = head;	
    while (nodePtr)
    {
        cout<<"->"<<nodePtr->value;		
        nodePtr = nodePtr->next;
    }
}
template <class T>

list<T> LinkedList<T>::toArray(){
    list<T> arr;
    ListNode *nodePtr;
    nodePtr = head;	
    while (nodePtr)
    {
       arr.push_back(nodePtr->value);		
        nodePtr = nodePtr->next;
    }
    return arr;
}

//insert Node
template <class T>
void LinkedList<T>::insertNode(T num)
{
    ListNode *newNode, *nodePtr, *previousNode;
    // Allocate a new node & store Num
    newNode = new ListNode;
    newNode->value = num;
    // If there are no nodes in the list
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else	// Otherwise, insert newNode.
    {
	  // Initialize nodePtr to head of list
      nodePtr = head;
      // Skip all nodes whose value member is less
	  // than num.
    while (nodePtr != NULL && nodePtr->value < num)
    {	
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }
     // If the new mode is to be the 1st in the list,
     // insert it before all other nodes.
    if (previousNode == NULL)
	{
	    head = newNode;
	    newNode->next = nodePtr;
	}
	else
	{
	    previousNode->next = newNode;
	    newNode->next = nodePtr;
	}
	}
}
//*************************************************************************************************************
// done by Feyisa kenenisa Id NO UGR/6442/13
// inserting the node to exsiting list by index
template<class T>
    void LinkedList<T>::insertByIndex(T val,int index){
        // creating temporary node which needed to be inserted
        ListNode*temp=new ListNode();
        temp->value=val;
        // declaring the pointers and initialing them to the head of the list and its next 
        // assuming the head of the list is always not null;
        ListNode*pev=head,*nxt=head->next;

        // inserts at index zero
       if(index==0){
        temp->next=head;
        head=temp;
       }

        else{
        int count=1;
        // getting at the index
        while(count<index){

        
            if (nxt->next==nullptr){// inserting at the end of list;
                nxt->next=temp;
                return;}
            nxt=nxt->next;
            pev=pev->next;
            count++;
        }
        
        //inserting at the middle of the list
         temp->next=nxt;
         pev->next=temp;
        }
    }
// checking if a circle in the given list
template<class T>
    bool LinkedList<T> ::hasCycle() {
// declaring the pointers
    ListNode *slow;
    ListNode *fast;
    // initializing the pointers ot the head of the list
    if (head!=nullptr){ 
        slow = head;
        fast = head;}

    else{return false;} // if there is no node
    //catching the slow pointer with fast pointer if there is cycle in the list
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
        
       }
       return false;
 
    }


// done by Feyisa kenenisa  Id NO UGR/6442/13
//************************************************************************************************************




template <class T>
void LinkedList<T>::deleteNode(T num)
{
    ListNode *nodePtr, *previousNode;
    // If the list is empty, do nothing.
    if (!head)
       return;
       // Determine if the first node is the one.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list	
        nodePtr = head;
        // Skip all nodes whose value member is
		// not equal to num	
        while (nodePtr != NULL && nodePtr->value != num)
        {	
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Link the previous node to the node after
		// nodePtr, then delete nodePtr.
        previousNode->next = nodePtr->next;
        delete nodePtr;
        }
} 
template <class T>
void LinkedList<T>::addNodeFront(T num)
{	
    ListNode *newNode, *nodePtr; // Allocate a new node & store num
    newNode = new ListNode;	
    newNode->value = num;	
    newNode->next = NULL; // If there are no nodes in the list
    // make newNode the first node
    if (!head)		
    head = newNode;	
    else	// Otherwise, insert newNode at end
    {		// Initialize nodePtr to head of list
    nodePtr = head;		
    head=newNode;
    newNode->next = nodePtr;
    }
}














