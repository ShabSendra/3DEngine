#include "Scene.hpp"

#include "Cube.hpp"
#include "RendererManager.hpp"


Scene::Scene()
{
}

bool Scene::initialize()
{

    return true;
}

bool Scene::instantiate(GameObject *object)
{
    m_objects.push_back(object);
    return true;
}

void Scene::update()
{
}

void Scene::draw()
{
    Manager::RendererManager::getInstance().drawScene(m_objects);
}

const std::vector<GameObject *> &Scene::getObjects() const
{
    return m_objects;
}

Scene::~Scene()
{
    for (std::vector<GameObject *>::const_iterator it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        delete *it;
    }
}
