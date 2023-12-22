#include"pch.h"
#include "WankelApp.h"
#include "Utilities.h"
#include"./include/Wankel.h"

#include"Shader.h"
#include"Picture.h"
#include"Renderer.h"

namespace wk
{
	template<typename T>
	WankelApp<T>::WankelApp()
	{
		mWindow.Create("Game JM", 1920, 1080);
		mRenderer.Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler();  });
	}

	template<typename T>
	void WankelApp<T>::Init()
	{
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template<typename T>
	void WankelApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void WankelApp<T>::Run()
	{	
		wk::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		mNextFrameTime = std::chrono::steady_clock::now();
		
		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void WankelApp<T>::OnUpdate()
	{

	}

	template<typename T>
	void WankelApp<T>::Draw(int x, int y, Picture& pic)
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void WankelApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}

	template<typename T>
	void WankelApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void WankelApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void WankelApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void WankelApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}



}
