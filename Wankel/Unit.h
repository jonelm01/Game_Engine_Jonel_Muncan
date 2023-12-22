#pragma once

#include"Utilities.h"
#include"Picture.h"

namespace wk
{
	class WANKEL_API Unit
	{
	public:
		Unit(const std::string & image, int x, int y, int v);
		Unit(std::string&& image, int x, int y, int v);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;

		void SetCoords(int x, int y);
		void UpdateXCoords(int amount);
		void UpdateYCoords(int amount);

		void UpdateXPos();
		void UpdateYPos();
		void UpdateXNeg();
		void UpdateYNeg();

		int GetVelocity() const;
		void SetVelocity(int v);

		//void SetPicture(const Picture& pic);


	private:
		Picture mImage;

		int mXPosition;
		int mYPosition;
		int mVelocity;														//speed 

		template<typename T> friend class WankelApp;
		friend WANKEL_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	WANKEL_API bool UnitsOverlap(const Unit& a, const Unit& b);
}