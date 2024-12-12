#include "Vertex.h"

Vertex::Vertex(string name) {
    m_name = name;
}

string Vertex::getTitle() const {
    return m_name;
}
