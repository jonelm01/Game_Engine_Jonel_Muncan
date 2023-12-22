#pragma once
#include"pch.h"
#include"Utilities.h"
#include"PictureImplementation.h"

namespace wk
{
	class WANKEL_API Picture
	{
	public:
		Picture(const std::string& picturePath);
		Picture(std::string&& picturePath);

		int GetWidth() const;
		int GetHeight() const;
		
		void Bind();

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}