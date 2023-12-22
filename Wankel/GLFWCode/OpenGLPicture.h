#pragma once

#include"pch.h"
#include"PictureImplementation.h"

namespace wk
{
	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& picturePath);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void Bind() override;

		~OpenGLPicture();

		//void SetCurrentPicture(unsigned int picID);
		//unsigned int GetCurrentPicture() const;


	private:
		unsigned int mPictureProgram;

		int mWidth;
		int mHeight;
	};
}