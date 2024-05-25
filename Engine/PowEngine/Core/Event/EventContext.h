#pragma once
#include"pch.h"

namespace PowEngine
{
	class POW_API EventContext
	{
	public:
		virtual ~EventContext() = default;
	};

	class POW_API WindowResizedEvent : public EventContext
	{
	private:
		int32_t mWidth, mHeight;
	public:
		WindowResizedEvent(int32_t width, int32_t height): mWidth(width), mHeight(height){}
		POW_FORCE_INLINE int32_t GetWidth() const { return mWidth; };
		POW_FORCE_INLINE int32_t GetHeight() const { return mHeight; };

	};
	class POW_API KeyPressedEvent : public EventContext {
	public:
		KeyPressedEvent(int32_t keyCode) : mKeyCode(keyCode) {}
		POW_FORCE_INLINE int32_t GetKeyCode() const { return mKeyCode; }
	private:
		int32_t mKeyCode;
	};

	class POW_API KeyHeldEvent : public EventContext {
	public:
		KeyHeldEvent(int32_t keyCode) : mKeyCode(keyCode) {}
		POW_FORCE_INLINE int32_t GetKeyCode() const { return mKeyCode; }
	private:
		int32_t mKeyCode;
	};

	class POW_API KeyReleasedEvent : public EventContext {
	public:
		KeyReleasedEvent(int32_t keyCode) : mKeyCode(keyCode) {}
		POW_FORCE_INLINE int32_t GetKeyCode() const { return mKeyCode; }
	private:
		int32_t mKeyCode;
	};

	class POW_API MouseMovedEvent : public EventContext {
	public:
		MouseMovedEvent(double x, double y, double offsetX, double offsetY) :
			xPosition(x), yPosition(y),
			xOffset(offsetX), yOffset(offsetY) {}
		POW_FORCE_INLINE double GetX() const { return xPosition; }
		POW_FORCE_INLINE double GetY() const { return yPosition; }
		POW_FORCE_INLINE double GetOffsetX() const { return xOffset; }
		POW_FORCE_INLINE double GetOffsetY() const { return yOffset; }
	private:
		double xPosition, yPosition;
		double xOffset, yOffset;
	};

	class POW_API MouseScrolledEvent : public EventContext {
	public:
		MouseScrolledEvent(double offsetX, double offsetY) : xOffset(offsetX), yOffset(offsetY) {}
		POW_FORCE_INLINE double GetOffsetX() const { return xOffset; }
		POW_FORCE_INLINE double GetOffsetY() const { return yOffset; }
	private:
		double xOffset, yOffset;
	};

	class POW_API MouseButtonPressedEvent : public EventContext {
	public:
		MouseButtonPressedEvent(int32_t button) : mButton(button) {}
		POW_FORCE_INLINE int32_t GetButton() const { return mButton; }
	private:
		int32_t mButton;
	};

	class POW_API MouseButtonHeldEvent : public EventContext {
	public:
		MouseButtonHeldEvent(int32_t button) : mButton(button) {}
		POW_FORCE_INLINE int32_t GetButton() const { return mButton; }
	private:
		int32_t mButton;
	};

	class POW_API MouseButtonReleasedEvent : public EventContext {
	public:
		MouseButtonReleasedEvent(int32_t button) : mButton(button) {}
		POW_FORCE_INLINE int32_t GetButton() const { return mButton; }
	private:
		int32_t mButton;
	};
}
