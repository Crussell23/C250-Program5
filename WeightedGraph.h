#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"
#include <string>

class WeightedGraph
{
public:
    WeightedGraph(int);
    bool isEmpty();
    void addVertex(Vertex*);
    void addEdge(int, int, int);
    bool isFull();
    void DFS(Vertex*);
    void BFS(Vertex*);
    void checkPath(std::string source, std::string destination);  // Check path and length
    int computeDFSCost(Vertex*);  // Computes the total cost of DFS traversal from a vertex
    int computeBFSCost(Vertex*);  // Computes the total cost of BFS traversal from a vertex
    Vertex* getVertexByName(std::string name);  // Gets a vertex by its name

protected:
    int indexIs(Vertex*);
    void clearMarks();
    void doDFS(Vertex* aVertex, std::vector<Vertex*>& path, int& totalCost);
    void doBFS(Vertex* aVertex, std::vector<Vertex*>& path, int& totalCost);

private:
    static const int NULL_EDGE = 0;
    int m_numVertices;
    int m_maxVertices;
    std::vector<Vertex*> m_vertices;
    std::vector<std::vector<int>> m_edges;
    std::vector<bool> m_marks;

    int dfsCostHelper(Vertex*);  // Helper function to compute DFS cost
};

#endif // WEIGHTEDGRAPH_H
