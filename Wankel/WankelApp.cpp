#include"pch.h"
#include "WankelApp.h"

namespace wk
{
	template<typename T>
	WankelApp<T>::WankelApp()
	{

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
		mWindow.Create("Game JM", 1000, 800);
		while (mShouldContinue)
		{
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void WankelApp<T>::OnUpdate()
	{
	}
}
