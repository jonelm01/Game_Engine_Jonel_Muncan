#include"pch.h"
#include"GameWindow.h"
#include"GLFWCode/GLFWImplementation.h"

namespace wk
{
	GameWindow::GameWindow()
	{
#ifdef WANKEL_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif WANKEL_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif WANKEL_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif
	}

	void GameWindow::Create(const std::string& name, int width, int height)
	{
		mImplementation->Create(name, width, height);
	}

	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	void GameWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}
}