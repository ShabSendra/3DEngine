#include "GameObject.hpp"


GameObject::GameObject() : m_active(true), m_name{}, m_parent{}, m_components{}
{
}

GameObject::GameObject(float x, float y, float z) : m_active(true), m_name{}, m_parent{}, m_components{}
{
}


const std::string &GameObject::getName() const
{
    return m_name;
}

bool GameObject::isActive() const
{
    return m_active;
}


GameObject::~GameObject()
{
}
