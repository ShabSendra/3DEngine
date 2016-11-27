#include <d3d11.h>

#include "Vertex.hpp"


D3D11_INPUT_ELEMENT_DESC layout[] =
{
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};
UINT numElements = ARRAYSIZE(layout);

Vertex::Vertex() : pos {}
{
}

Vertex::Vertex(float x, float y, float z) : pos(x, y, z)
{
}

Vertex::~Vertex()
{
}
