#include"Window.h"
#include"pch.h"
#include"Core/Application.h"
#include"Core/Logger/Logger.h"
#define GLAD_GL_IMPLEMENTATION
#include"glad/gl.h"
#include"GLFW/glfw3.h"

namespace PowEngine
{
	GLFWPlatformWindow::GLFWPlatformWindow() : mWindow(nullptr)
	{

	}
	GLFWPlatformWindow::~GLFWPlatformWindow()
	{
	}


	bool GLFWPlatformWindow::Init(const ApplicationConfiguration& config, EventDispatcher* eventDispatcher)
	{

		if (!glfwInit()) 
		{ 
			CORE_LOG_CRITICAL("init glfw failed");
			return false;
		}
		// else: set up glfw property for OpenGL 4.3 core
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR ,4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR ,3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(config.Width, config.Height, config.Title, nullptr, nullptr);
		if (!mWindow)
		{
			CORE_LOG_CRITICAL("create Window failed");
			glfwTerminate();
			return false;
		}

		CORE_LOG_INFO("created window success");

		glfwMakeContextCurrent(mWindow);

		mData.Dispatcher = eventDispatcher;

		glfwSetWindowUserPointer(mWindow, &mData);

		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);

			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			data->Width = width;
			data->Height = height;
			WindowResizedEvent eventContext(width, height);
			data->Dispatcher->DispatchEventListener<WindowResizedEvent>(eventContext);
			});

		if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
			CORE_LOG_CRITICAL("Glad loaded failed");
			glfwTerminate();
			return false;
		}
		CORE_LOG_INFO("Glad loaded success");

		return true;
	}
	void GLFWPlatformWindow::Shutdown()
	{
		glfwTerminate();
	}
	void GLFWPlatformWindow::SwapBuffer()
	{
		glClearColor(0, 0.5, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(mWindow);
	}
	void GLFWPlatformWindow::PollEvent()
	{
		glfwPollEvents();
	}
	bool GLFWPlatformWindow::ShouldClose()
	{
		return glfwWindowShouldClose(mWindow);
	}
}