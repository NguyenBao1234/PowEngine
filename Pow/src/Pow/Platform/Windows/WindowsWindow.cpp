//Copyright POW Game std
#include "powpch.h"
#include "WindowsWindow.h"
#include <Pow/Events/ApplicationEvent.h>
#include <Pow/Events/KeyEvent.h>
#include <Pow/Events/MouseEvent.h>

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
	//trong namespace k can chat che nhu class, nen k can khai bao trong header
	static void LogGLFWErrorCb(int error, const char* description)
	{
		PE_CORE_ERR("GLFW Error ({0}): {1}", error, description);
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
			glfwSetErrorCallback(LogGLFWErrorCb);
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
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, false);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, true);
						data.EventCallback(event);
						break;
					}
				}
			});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
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
