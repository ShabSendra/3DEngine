#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "GameObject.hpp"

class Scene
{
private :
    std::vector<GameObject *> m_objects;

public:
    Scene();

    bool initialize();
    bool instantiate(GameObject *object);

    void update();
    void draw();
    const std::vector<GameObject *> &getObjects() const;

    ~Scene();
};

#endif // !_SCENE_HPP_
