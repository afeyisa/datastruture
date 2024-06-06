/* steps 
1 pick a starting node
2 if possible, visit an adjacent unvisited vertes, mark it and push it on the stack
3 if there are no unvisited nodes then pop a vertex off the stack 
if it is not empty and repeat step2
step 4 if the stack is empty you are done
stack contains path taken to reach current node

*/

#include <iostream>
#include "AdjecentGraph.cpp"
#include <stack>
#include <list>
#include <vector>
using namespace std;
class DFS
{
private:
    /* data */
public:
    DFS(int ,Graph);
    ~DFS();
};

DFS::DFS( int startVertex,Graph G)
    {

        vector<bool> visited(G.numVertices, false);
        stack<int> stack;
        stack.push(startVertex);
        
       // cout<<naibors[0]<<endl;
              
        while (!stack.empty())
        {
            int vertex = stack.top();
            stack.pop();
            list<int> naibors= G.Vertices[vertex].toArray();
            if (!visited[vertex]) 
            {
                cout << "Visited " << vertex << endl;
                visited[vertex] = true;
            } 

            for (auto it = naibors.rbegin(); it != naibors.rend(); ++it) {
            if (!visited[*it]) {
                stack.push(*it);
            }
        }
            
        }
    }


DFS::~DFS()
{
}
int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.printGraph();

    DFS dfs (1,graph);

    return 0;

    //result should be
    /*
    Vertex 0:->1->4
    Vertex 1:->0->2->3->4
    Vertex 2:->1->3
    Vertex 3:->1->2->4
    Vertex 4:->0->1->3
    */
   // dfs reuslts


   }