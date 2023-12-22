#pragma once

#include"pch.h"
#include"Utilities.h"
#include"RendererImplementation.h"
#include"Shader.h"
#include"Picture.h"

namespace wk
{
	class WANKEL_API Renderer
	{
	public:
		Renderer();

		void Init();

		void Draw(int x, int y, Picture& pic);

		void Clear();

	private:
		std::unique_ptr<RendererImplementation> mImplementation;
	};
}