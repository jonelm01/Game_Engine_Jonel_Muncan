#include"pch.h"
#include "Picture.h"
#include"GLFWCode/OpenGLPicture.h"

namespace wk
{
		Picture::Picture(const std::string& picturePath)
		{
#ifdef WANKEL_MSCPP
			mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#elif WANKEL_APPLE
			mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#elif WANKEL_LINUX
			mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#endif
		}

		Picture::Picture(std::string&& picturePath)
		{
#ifdef WANKEL_MSCPP
			mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#elif WANKEL_APPLE
			mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#elif WANKEL_LINUX
			mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#endif
		}

		int Picture::GetWidth() const
		{
			return mImplementation->GetWidth();
		}

		int Picture::GetHeight() const
		{
			return mImplementation->GetHeight();
		}

		void Picture::Bind()
		{
			mImplementation->Bind();
		}
		
}
