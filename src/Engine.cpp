#include "Engine.hpp"
#include "Image.hpp"
#include <glm/glm.hpp>
#include "Utils.hpp"

vk::Engine::Engine()
{
	m_isRunning = false;
	m_lastFrameTime = 0.0;
}

bool vk::Engine::Initialize()
{
	std::cout << "=========================== CONTROLS ===========================================" << std::endl;
	std::cout << "** Right-Mouse to Activate & Deactivate Camera" << std::endl;
	std::cout << "** Camera - WSADQE " << std::endl;
	std::cout << "** Key 5 to Enable/Disable accumulation (Accumulation is up to 1000 frames) " << std::endl;
	std::cout << "** Use on-screen GUI to Enable and Disable ReSTIR and adjust settings" << std::endl;
	std::cout << "================================================================================" << std::endl;

	if (m_context.MakeContext(1920, 1080))
	{
		m_isRunning = true;
	}

	// std::printf("Engine initialized\n");
	m_Renderer = std::make_unique<Renderer>(m_context);

	return m_isRunning;
}


void vk::Engine::Shutdown()
{
	m_Renderer->Destroy();
	m_Renderer.reset();
	m_context.Destroy(); // Free vulkan device, allocator, window
}

void vk::Engine::Run()
{
	while (m_isRunning && !glfwWindowShouldClose(m_context.window))
	{
		double currentFrameTime = glfwGetTime();
		deltaTime = currentFrameTime - m_lastFrameTime;
		m_lastFrameTime = currentFrameTime;

		glfwPollEvents();
		Update(deltaTime);
		Render();
	}

	Shutdown();
}

void vk::Engine::Update(double deltaTime)
{
	//m_Renderer->Update(deltaTime);
}

void vk::Engine::Render()
{
	m_Renderer->Render(deltaTime);
}
