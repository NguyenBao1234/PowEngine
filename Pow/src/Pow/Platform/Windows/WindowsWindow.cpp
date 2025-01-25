//Copyright POW Game std
#include "powpch.h"
#include "WindowsWindow.h"

namespace POW
{

	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	static bool bGLFWInitialized = false;
	void WindowsWindow::Init(const WindowProperties& props)
	{
		wData.Title = props.Title;
		wData.Height = props.Height;
		wData.Width = props.Width;
		PE_CORE_TRACE("Creating Window '{0}': w = {1}; h = {2}", wData.Title, wData.Width, wData.Height);
		if (!bGLFWInitialized)
		{
			int Success = glfwInit();
			POW_CORE_ASSERT(Success, "glfw Init failed");
			bGLFWInitialized = true;
			PE_CORE_INFO("Initialized glfw");
			//Modern Configuration for avoiding mistakes
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //  OpenGL 3.x
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //  OpenGL 3.3
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //core profile
			PE_CORE_INFO("Configured glfw")
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		POW_CORE_ASSERT(m_Window, "Failed to create GLFW window");
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &wData);
		SetVSync(true);
		//_____________Set up GLFW Callback :__________

	}
	
	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
		glfwShowWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);//No calculate time to wait for greater FPS, but Tear Vertical Visual

		wData.bVSync = enabled;
	}

	

	void WindowsWindow::ShutDown()
	{
		//glfwTerminate();
		glfwDestroyWindow(m_Window);
	}

}
