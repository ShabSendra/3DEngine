#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

#include "Transform.hpp"
#include "IComponent.hpp"

class IComponent;

class GameObject
{

private:
    bool                    m_active;
    Transform               m_transform;
    std::string             m_name;

    GameObject              *m_parent;
    std::vector<IComponent *>  m_components;

public:
    GameObject();
    GameObject(float x, float y, float z);

    // Creates a templated version of the fuction only for types derived from Component
    template <class T>
    std::enable_if_t<std::is_base_of<IComponent, T>::value, void>
        addComponent()
    {
        T *component = new T();
        if (component->attach(this))
            m_components.push_back(component);
        else
            delete component;
    }

    const std::string &getName() const;
    bool isActive() const;

    ~GameObject();
};


#endif // !_GAMEOBJECT_HPP_