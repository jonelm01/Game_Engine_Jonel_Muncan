#include"pch.h"
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "stb_image.h"

#include"OpenGLPicture.h"

#include "../Utilities.h"

namespace wk
{ 
	OpenGLPicture::OpenGLPicture(const std::string& picturePath)
	{
		glGenTextures(1, &mPictureProgram);
		glBindTexture(GL_TEXTURE_2D, mPictureProgram);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;

		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(picturePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); 
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			WK_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}

	int OpenGLPicture::GetWidth() const
	{
		return mWidth;
	}

	int OpenGLPicture::GetHeight() const
	{
		return mHeight;
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mPictureProgram);
	}

	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mPictureProgram);
	}

	
	//void OpenGLPicture::SetCurrentPicture(unsigned int picID)
	//{
	//	mPictureProgram = picID;
	//}

	//unsigned int OpenGLPicture::GetCurrentPicture() const
	//{
	//	return mPictureProgram;
	//}
	
}
