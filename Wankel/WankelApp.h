#pragma once
#include"Utilities.h"

namespace wk
{
	template<typename T>
	class WANKEL_API WankelApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;

	private:
		WankelApp();

		inline static WankelApp* sInstance{ nullptr };

		bool mShouldContinue{ true };
	};
}

#include"WankelApp.cpp"

/*
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
}*/