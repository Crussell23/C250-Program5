#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
using namespace std;

int main()
{
    WeightedGraph myGraph(10);
    Vertex* startNode;
    Vertex* aVertex;
    startNode = new Vertex("A");
    myGraph.addVertex(startNode);
    aVertex = new Vertex("B");
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("C");
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("D");
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("E");
    myGraph.addVertex(aVertex);

    myGraph.addEdge(0, 3, 60);  // A -> D weight 60 (directed edge)
    myGraph.addEdge(0, 2, 12);  // A -> C weight 12 (directed edge)
    myGraph.addEdge(1, 0, 10);  // B -> A weight 10 (directed edge)
    myGraph.addEdge(2, 1, 20);  // C -> B weight 20 (directed edge)
    myGraph.addEdge(2, 3, 32);  // C -> D weight 32 (directed edge)
    myGraph.addEdge(4, 0, 7);   // E -> A weight 7 (directed edge)


    // DFS and BFS from E
    cout << "\nDFS from E: ";
    myGraph.DFS(myGraph.getVertexByName("E"));
    cout << "\nBFS from E: ";
    myGraph.BFS(myGraph.getVertexByName("E"));

    // Ask user for source and destination
    string source, destination;
    cout << "\nEnter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> destination;

    // Check if a path exists between source and destination
    myGraph.checkPath(source, destination);

    return 0;
}
