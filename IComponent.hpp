#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include "GameObject.hpp"

class GameObject;

class IComponent
{
protected :

    GameObject *m_parent;

public:
    IComponent();

    virtual bool attach(GameObject *) = 0;

    virtual ~IComponent();
};

#endif // !_COMPONENT_HPP_
