#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#define WIN32_LEAN_AND_MEAN

#include "RendererManager.hpp"
#include "Scene.hpp"

class Engine
{
public:
    Engine();

    bool initialize(HINSTANCE hInstance, int nCmdShow);
    bool run();
    bool shutdown();

    ~Engine();

private:
    Scene       m_scene;
};

#endif // !_ENGINE_HPP_