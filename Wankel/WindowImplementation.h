#pragma once

#include"pch.h"
#include"Events.h"

namespace wk
{
	class WindowImplementation
	{
	public:
		virtual void Create(const std::string& name, int width, int height) = 0;

		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc) = 0;
		virtual void SetWindowCloseCallback(std::function<void()>& callbackFunc) = 0;

		virtual ~WindowImplementation() {};
	};
}