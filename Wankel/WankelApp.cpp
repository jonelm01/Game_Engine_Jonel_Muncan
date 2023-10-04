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
		while (mShouldContinue)
		{
			OnUpdate();
		}
	}

	template<typename T>
	void WankelApp<T>::OnUpdate()
	{
	}
}
