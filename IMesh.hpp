#ifndef _MESH_HPP_
#define _MESH_HPP_

#include "IComponent.hpp"

class IMesh : public IComponent
{
public:
    IMesh();

    virtual bool attach(GameObject *parent) override {
        return true;
    }
    virtual void draw() = 0;

    virtual ~IMesh();
};

#endif // !_MESH_HPP_