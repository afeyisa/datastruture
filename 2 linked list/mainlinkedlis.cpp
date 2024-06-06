// Authoer Feyisa Kenenisa
#include <iostream>
#include "LinkedList.h"
using namespace std;
int main(void){
    LinkedList<float> list;
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    list.insertNode(10.5);
    cout << "Here are the initial values:\n";
    list.insertByIndex(40,2);
    list.displayList();
    cout<<list.hasCycle()<<endl;

    // cout << endl;
    // cout << "Now after deleting the node in the middle.\n";
    // list.deleteNode(7.9);
    // list.displayList();
    // cout << endl;
    // cout << "Now deleting the last node.\n";	
    // cout << "Here are the nodes left.\n";	
    // list.deleteNode(12.6);
    // list.displayList();
    // cout << endl;
    // cout << "Now deleting the only remaining node.\n";
    // cout << "Here are the nodes left.\n";
    // list.deleteNode(2.5);
    // list.displayList();
    return 0;
}
