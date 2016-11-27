#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include <DirectXMath.h>

struct Vertex
{
    Vertex();
    Vertex(float x, float y, float z);
    ~Vertex();

    DirectX::XMFLOAT3 pos;
};

#endif // !_VERTEX_HPP_
