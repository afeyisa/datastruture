#include<iostream>
using namespace std;

// Definition of MaxHeap class
class Maxheap
{
private:
    // Private members can be added here if needed
public:
    // Current number of elements in the heap
    int currentSize = 0;
    // Maximum size of the heap array
    int arreySize = 10;
    // Array to hold heap elements
    int heapArrey[10];
    
    // Constructor
    Maxheap();
    // Destructor
    ~Maxheap();
    
    // Function to insert a new value into the heap
    void insert(int value);
    // Function to remove and return the maximum element from the heap
    int pop();
    // Function to restore the heap property by trickling down the element at the given index
    void trickleDown(int index);
    // Function to restore the heap property by trickling up the element at the given index
    void tricleUp(int index);
    // Function to display all elements of the heap
    void displayHeap();
};

// Constructor implementation
Maxheap::Maxheap()
{
    // Initialize the heap if necessary 
}

// Destructor implementation
Maxheap::~Maxheap()
{
    // Clean up resources if necessary 
}

// Function to remove and return the maximum element from the heap
int Maxheap::pop()
{
    /* 
    Formulas for heap:
    - Parent of node at index i: (i-1)/2
    - Left child of node at index i: 2*i+1
    - Right child of node at index i: 2*i+2
    */

    // If the heap is empty, return -1
    if (currentSize == 0) return -1;
    
    // Store the root value (maximum element)
    int root = heapArrey[0];
    // Replace the root with the last element in the heap
    heapArrey[0] = heapArrey[currentSize - 1];
    // Restore the heap property by trickling down the new root element
    trickleDown(0);
    // Decrease the size of the heap
    currentSize = currentSize - 1;
    // Return the original root value
    return root;
}

// Function to restore the heap property by trickling down the element at the given index
void Maxheap::trickleDown(int index)
{
    int top = heapArrey[index];
    // Check if the node at the given index has children
    while (currentSize > 2 * index + 2) // Check if the node has both left and right children
    {
        int largerChild;
        int tempIndex;
        // Determine the larger of the two children
        if (heapArrey[2 * index + 1] > heapArrey[2 * index + 2])
        {
            tempIndex = 2 * index + 1; // Left child
            largerChild = heapArrey[tempIndex];
        }
        else
        {
            tempIndex = 2 * index + 2; // Right child
            largerChild = heapArrey[tempIndex];
        }
        // If the top element is larger than the larger child, the heap property is restored
        if (top > largerChild) break;
        // Move the larger child up
        heapArrey[index] = largerChild;
        // Move to the next index
        index = tempIndex;
    }
    // Place the top element in its correct position
    heapArrey[index] = top;
}

// Function to insert a new value into the heap
void Maxheap::insert(int value)
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
void Maxheap::tricleUp(int index)
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
    // While the current index is not the root and the bottom element is larger than its parent
    while (index > 0 && bottom > heapArrey[parent])
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
void Maxheap::displayHeap()
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
    // Create a MaxHeap object
    Maxheap test = Maxheap();

    // Insert elements into the heap
    test.insert(12);
    test.insert(9);
    test.insert(13);
    test.insert(17);
    test.insert(10);
    test.insert(19);
    test.insert(14);
    
    
   test.displayHeap();
   cout<<endl;
   
   
    // Remove and print the maximum elements from the heap
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;

    return 0;
}
