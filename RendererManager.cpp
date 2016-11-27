#include "RendererManager.hpp"

#include "WindowManager.hpp"

using Manager::RendererManager;

RendererManager RendererManager::m_instance;

RendererManager::RendererManager()
{
}

bool RendererManager::initialize()
{
    HRESULT hr;

    //Describe our Buffer
    DXGI_MODE_DESC bufferDesc;

    ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

    bufferDesc.Width = Manager::WindowManager::getInstance().getWidth();
    bufferDesc.Height = Manager::WindowManager::getInstance().getHeight();
    bufferDesc.RefreshRate.Numerator = 60;
    bufferDesc.RefreshRate.Denominator = 1;
    bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    // Describe the swap chain
    DXGI_SWAP_CHAIN_DESC swapChainDesc;

    ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    swapChainDesc.BufferDesc = bufferDesc;
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.SampleDesc.Quality = 0;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount = 1;
    swapChainDesc.OutputWindow = Manager::WindowManager::getInstance().getMainWindow();
    swapChainDesc.Windowed = TRUE;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    //Create our SwapChain and Device
    hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
        D3D11_SDK_VERSION, &swapChainDesc, &m_swapChain, &m_d3d11Device, NULL, &m_d3d11DevCon);

    //Create our BackBuffer
    ID3D11Texture2D* BackBuffer;
    hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer);

    //Create our Render Target
    hr = m_d3d11Device->CreateRenderTargetView(BackBuffer, NULL, &m_renderTargetView);
    BackBuffer->Release();

    //Set our Render Target
    m_d3d11DevCon->OMSetRenderTargets(1, &m_renderTargetView, NULL);

    return true;
}

bool RendererManager::drawScene(const std::vector<GameObject *> &gameObjects)
{
    //Clear our backbuffer to the updated color
    float bgColor[4] = { 0.0f, 1.0f, 0.0f, 1.0f };

    m_d3d11DevCon->ClearRenderTargetView(m_renderTargetView, bgColor);

    //Present the backbuffer to the screen
    m_swapChain->Present(0, 0);
    return true;
}

const ID3D11Device *RendererManager::getDevice() const
{
    return m_d3d11Device;
}

RendererManager::~RendererManager()
{
    //Release the COM Objects we created
    m_swapChain->Release();
    m_d3d11Device->Release();
    m_d3d11DevCon->Release();
    m_renderTargetView->Release();
}
