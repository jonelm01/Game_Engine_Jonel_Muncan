#pragma once
#include"Utilities.h"
#include"GameWindow.h"

namespace wk
{
	template<typename T>
	class WankelApp
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

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
}

#include"WankelApp.cpp"

