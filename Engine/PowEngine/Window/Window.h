#pragma once
struct GLFWwindow;

namespace PowEngine
{
	enum EWindowPlatformSpec
	{
		GLFW,
		SDL,
		None,
	};
	//
	class EventDispatcher;
	struct WindowData
	{
		int32_t Width, Height;
		EventDispatcher* Dispatcher;
	};
	class NativeWindow
	{
	public:
		virtual ~NativeWindow() = default;
		virtual bool Init( const struct ApplicationConfiguration&, EventDispatcher*) = 0;
		virtual void Shutdown() = 0;
		virtual void SwapBuffer() = 0;
		virtual void PollEvent() = 0;
		virtual bool ShouldClose() = 0;
	protected:
		NativeWindow() = default;
		NativeWindow(NativeWindow&) = default;
	};

	class GLFWPlatformWindow : public NativeWindow
	{
	public:
		GLFWPlatformWindow();
		~GLFWPlatformWindow();
		virtual bool Init( const struct ApplicationConfiguration&, EventDispatcher*)override;
		virtual void Shutdown()override;
		virtual void SwapBuffer()override;
		virtual void PollEvent()override;
		virtual bool ShouldClose()override;
	private:
		GLFWwindow* mWindow;
		WindowData mData;
	};

}