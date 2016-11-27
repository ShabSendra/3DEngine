#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_

#include <DirectXMath.h>

struct Transform
{
    Transform();
    ~Transform();

    DirectX::XMFLOAT3 position;
};

#endif // !_TRANSFORM_HPP_

