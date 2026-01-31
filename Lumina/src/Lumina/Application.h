#pragma once

#include "Core.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
// #include <vulkan/vulkan.h>

namespace Lumina
{

class LUMINA_API Application
{
  public:
    Application();
    virtual ~Application();

    void Run();

  private:
    // Initialization methods
    void InitWindow();
    void InitVulkan();
    void InitImGui();

    // Vulkan setup methods
    void CreateInstance();
    void SetupDebugMessenger();
    void CreateSurface();
    void PickPhysicalDevice();
    void CreateLogicalDevice();
    void CreateSwapChain();
    void CreateImageViews();
    void CreateRenderPass();
    void CreateFramebuffers();
    void CreateCommandPool();
    void CreateCommandBuffers();
    void CreateSyncObjects();
    VkDescriptorPool CreateDescriptorPool();

    // Command buffer helpers
    VkCommandBuffer BeginSingleTimeCommands();
    void EndSingleTimeCommands(VkCommandBuffer commandBuffer);

    // Rendering methods
    void DrawFrame();
    void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    // Cleanup methods
    void CleanupImGui();
    void CleanupVulkan();
    void CleanupWindow();

  private:
    // GLFW
    GLFWwindow* m_Window = nullptr;

    // Vulkan core
    VkInstance m_Instance = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT m_DebugMessenger = VK_NULL_HANDLE;
    VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
    VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
    VkDevice m_Device = VK_NULL_HANDLE;
    VkQueue m_GraphicsQueue = VK_NULL_HANDLE;
    uint32_t m_GraphicsQueueFamily = 0;

    // Swap chain
    VkSwapchainKHR m_SwapChain = VK_NULL_HANDLE;
    std::vector<VkImage> m_SwapChainImages;
    std::vector<VkImageView> m_SwapChainImageViews;
    std::vector<VkFramebuffer> m_SwapChainFramebuffers;
    VkExtent2D m_SwapChainExtent;

    // Rendering
    VkRenderPass m_RenderPass = VK_NULL_HANDLE;
    VkCommandPool m_CommandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> m_CommandBuffers;

    // Synchronization
    VkSemaphore m_ImageAvailableSemaphore = VK_NULL_HANDLE;
    VkSemaphore m_RenderFinishedSemaphore = VK_NULL_HANDLE;
    VkFence m_InFlightFence = VK_NULL_HANDLE;
};

Application* CreateApplication();

} // namespace Lumina
