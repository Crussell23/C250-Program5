#include "WeightedGraph.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size);
    for (int i = 0; i < size; i++) {
        m_vertices[i] = NULL;
    }
    m_marks.resize(size);
    m_edges.resize(size, vector<int>(size, 0));
}

void WeightedGraph::addVertex(Vertex* aVertex)
{
    m_vertices[m_numVertices] = aVertex;
    for (int i = 0; i < m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    int row = indexIs(m_vertices[fromVertex]);
    int column = indexIs(m_vertices[toVertex]);
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex)
{
    int i = 0;
    while (i < m_numVertices) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
        i++;
    }
    return -1;
}

void WeightedGraph::clearMarks()
{
    for (int i = 0; i < m_numVertices; i++) {
        m_marks[i] = false;
    }
}

void WeightedGraph::doDFS(Vertex* aVertex, std::vector<Vertex*>& path, int& cost)
{
    int ix, ix2;
    if (aVertex == NULL) return;

    // Add the current vertex to the path
    path.push_back(aVertex);

    ix = indexIs(aVertex);
    m_marks[ix] = true;

    // Traverse all adjacent vertices
    for (int i = 0; i < m_numVertices; i++) {
        ix2 = indexIs(m_vertices[i]);

        // Only visit unmarked vertices and valid edges
        if (m_edges[ix][ix2] != NULL_EDGE && m_marks[ix2] == false) {
            cost += m_edges[ix][ix2];  // Add the edge weight to the cost
            doDFS(m_vertices[i], path, cost);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    std::vector<Vertex*> path;
    int cost = 0;

    doDFS(aVertex, path, cost);

    // Print the DFS path and cost only once
    cout << "DFS Path from " << aVertex->getTitle() << ": ";
    for (auto& vertex : path) {
        cout << vertex->getTitle() << " ";
    }
    cout << endl;
    cout << "Total Cost: " << cost << endl;
}

void WeightedGraph::doBFS(Vertex* aVertex, std::vector<Vertex*>& path, int& cost)
{
    int ix, ix2;
    queue<Vertex*> que;

    ix = indexIs(aVertex);
    m_marks[ix] = true;
    que.push(aVertex);

    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();

        // Add the current vertex to the path
        path.push_back(node);

        ix = indexIs(node);
        for (int i = 0; i < m_numVertices; i++) {
            ix2 = indexIs(m_vertices[i]);

            if (m_edges[ix][ix2] != NULL_EDGE && m_marks[ix2] == false) {
                cost += m_edges[ix][ix2];  // Add the edge weight to the cost
                m_marks[ix2] = true;
                que.push(m_vertices[i]);
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    std::vector<Vertex*> path;
    int cost = 0;

    doBFS(aVertex, path, cost);

    // Print the BFS path and cost only once
    cout << "BFS Path from " << aVertex->getTitle() << ": ";
    for (auto& vertex : path) {
        cout << vertex->getTitle() << " ";
    }
    cout << endl;
    cout << "Total Cost: " << cost << endl;
}


Vertex* WeightedGraph::getVertexByName(string name)
{
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i]->getTitle() == name) {
            return m_vertices[i];
        }
    }
    return nullptr;
}

void WeightedGraph::checkPath(string source, string destination)
{
    Vertex* src = getVertexByName(source);
    Vertex* dest = getVertexByName(destination);

    if (src == nullptr || dest == nullptr) {
        cout << "Invalid source or destination node." << endl;
        return;
    }

    vector<Vertex*> path;
    int totalCost = 0;

    // Perform DFS to find a path
    clearMarks();
    doDFS(src, path, totalCost);

    bool pathFound = false;
    for (Vertex* v : path) {
        if (v == dest) {
            pathFound = true;
            break;
        }
    }

    if (pathFound) {
        cout << "Path from " << source << " to " << destination << " found!" << endl;
        cout << "Path: ";
        for (Vertex* v : path) {
            cout << v->getTitle() << " ";
        }
        cout << "\nTotal Cost: " << totalCost << endl;
    } else {
        cout << "No path found from " << source << " to " << destination << "." << endl;
    }
}
