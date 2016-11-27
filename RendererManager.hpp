#ifndef _RENDERERMANAGER_HPP_
#define _RENDERERMANAGER_HPP_

#include <vector>

#include <windows.h>
#include <d3d11.h>

#include "IMesh.hpp"

namespace Manager
{

class RendererManager
{
public:
    RendererManager(const RendererManager &) = delete;
    RendererManager&operator=(const RendererManager&) = delete;

    bool initialize();
    bool drawScene(const std::vector<GameObject *> &gameObjects);

    const ID3D11Device *getDevice() const;

    static RendererManager &getInstance()
    {
        return m_instance;
    }

    ~RendererManager();

private:
    RendererManager();

    static RendererManager m_instance;

    IDXGISwapChain*         m_swapChain;
    ID3D11Device*           m_d3d11Device;
    ID3D11DeviceContext*    m_d3d11DevCon;
    ID3D11RenderTargetView* m_renderTargetView;
};

}

#endif // !_RENDERERMANAGER_HPP_