#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using namespace std;

class Vertex {
public:
    Vertex(string name);
    string getTitle() const;  // Get the name of the vertex

private:
    string m_name;  // The name of the vertex
};

#endif // VERTEX_H
