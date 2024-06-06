#include<iostream>
using namespace std;

// Definition of MinHeap class
class MinHeap
{
private:
    // Private members can be added here if needed
public:
    // Constructor
    MinHeap();
    // Destructor
    ~MinHeap();
    
    // Current number of elements in the heap
    int currentSize = 0;
    // Maximum size of the heap array
    int arreySize = 10;
    // Array to hold heap elements
    int heapArrey[10];
  
    // Function to insert a new value into the heap
    void insert(int value);
    // Function to remove and return the minimum element from the heap
    int pop();
    // Function to restore the heap property by trickling down the element at the given index
    void trickleDown(int index);
    // Function to restore the heap property by trickling up the element at the given index
    void tricleUp(int index);
    // Function to display all elements of the heap
    void displayHeap();
};

// Constructor implementation
MinHeap::MinHeap()
{
    // Initialize the heap if necessary (currently empty)
}

// Destructor implementation
MinHeap::~MinHeap()
{
    // Clean up resources if necessary (currently nothing to clean)
}

// Function to remove and return the minimum element from the heap
int MinHeap::pop()
{ 
   /* 
   Formulas for heap:
   - Parent of node at index i: (i-1)/2
   - Left child of node at index i: 2*i+1
   - Right child of node at index i: 2*i+2
   */

   // If the heap is empty, return -1
   if (currentSize == 0) return -1;
   
   // Store the root value (minimum element)
   int root = heapArrey[0];
   // Replace the root with the last element in the heap
   heapArrey[0] = heapArrey[currentSize-1];
   // Restore the heap property by trickling down the new root element
   trickleDown(0);
   // Decrease the size of the heap
   currentSize = currentSize - 1;
   // Return the original root value
   return root;
}

// Function to restore the heap property by trickling down the element at the given index
void MinHeap::trickleDown(int index)
{
    int top = heapArrey[index];
    // Check if the node at the given index has children
    while (currentSize > 2*index + 2) // Check if the node has both left and right children
    {
        int smallerChild;
        int tempIndex;
        // Determine the smaller of the two children
        if (heapArrey[2*index + 1] < heapArrey[2*index + 2])
        {
            tempIndex = 2*index + 1; // Left child
            smallerChild = heapArrey[tempIndex];
        }
        else
        {
            tempIndex = 2*index + 2; // Right child
            smallerChild = heapArrey[tempIndex];
        }
        // If the top element is smaller than the smaller child, the heap property is restored
        if (top < smallerChild) break;
        // Move the smaller child up
        heapArrey[index] = smallerChild;
        // Move to the next index
        index = tempIndex;
    }
    // Place the top element in its correct position
    heapArrey[index] = top;
}

// Function to insert a new value into the heap
void MinHeap::insert(int value)
{
    // If the heap is full, print an error message and return
    if (currentSize == arreySize) 
    {
        cout << "heap is full" << endl;
        return;
    }
    // Place the new value at the end of the heap
    heapArrey[currentSize] = value;
    // Restore the heap property by trickling up the new element
    tricleUp(currentSize);
    // Increase the size of the heap
    currentSize++;
}

// Function to restore the heap property by trickling up the element at the given index
void MinHeap::tricleUp(int index)
{
   /* 
   Formulas for heap:
   - Parent of node at index i: (i-1)/2
   - Left child of node at index i: 2*i+1
   - Right child of node at index i: 2*i+2
   */

   // Find the parent index
   int parent = (index - 1) / 2;
   // Store the bottom element
   int bottom = heapArrey[index];
   // While the current index is not the root and the bottom element is smaller than its parent
   while (index > 0 && bottom < heapArrey[parent])
   {
       // Move the parent down
       heapArrey[index] = heapArrey[parent];
       // Move up to the parent index
       index = parent;
       // Recalculate the parent index
       parent = (index - 1) / 2;
   }
   // Place the bottom element in its correct position
   heapArrey[index] = bottom;
}

// Function to display all elements of the heap
void MinHeap::displayHeap()
{
    // Loop through the heap array and print each element
    for (int i = 0; i < currentSize; i++)
    {
        cout << heapArrey[i] << endl;
    }
}

// Main function
int main()
{
    // Create a MinHeap object
    MinHeap test = MinHeap();

    // Insert elements into the heap
    test.insert(15);
    test.insert(7);
    test.insert(5);
    test.insert(20);
    test.insert(15);
    test.insert(31);
    test.insert(28);
    test.insert(25);
    test.insert(23);
    test.insert(1);
   
    // Remove and print the minimum elements from the heap
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;

    return 0;
}
