
/* owner Feyisa kenenisa
thank you lord Jesus! I was happy when I comeplete this code*/

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;
#include "../2 linked list/LinkedList.h"
using namespace std;
class Graph {
private:
   
public:
    // Constructor
     int numVertices;
    LinkedList<int> *Vertices;
    Graph(int vertices) :  numVertices (vertices)
    {
       Vertices = new LinkedList<int> [vertices];   
    }
    
    // Add edge
    void addEdge(int src, int dest) {
      
        Vertices[src].appendNode(dest);
        Vertices[dest].appendNode(src); // Remove this line for a directed graph
    }

    // Print the graph
    void printGraph() {
         for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            
            Vertices[i].displayList();
            cout << endl;
       }
    }

};



// int main() {
//     Graph graph(5);
//     graph.addEdge(0, 1);
//     graph.addEdge(0, 4);
//     graph.addEdge(1, 2);
//     graph.addEdge(1, 3);
//     graph.addEdge(1, 4);
//     graph.addEdge(2, 3);
//     graph.addEdge(3, 4);
//     graph.printGraph();
//     graph.DFS(1);
//     return 0;
// }
