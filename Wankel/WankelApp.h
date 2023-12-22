#pragma once

#include"Utilities.h"
#include"GameWindow.h"
#include"Renderer.h"
#include"Picture.h"
#include"Unit.h"

namespace wk
{
	constexpr int FPS{ 60 };

	template<typename T>
	class WankelApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		static void Draw(int x, int y, Picture& pic);
		static void Draw(Unit& item);

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		void DefaultWindowCloseHandler();

		friend typename T;

	private:
		WankelApp();

		inline static WankelApp* sInstance{ nullptr };

		GameWindow mWindow;

		Renderer mRenderer;

		bool mShouldContinue{ true };

		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

#include"WankelApp.cpp"

