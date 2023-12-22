#include "pch.h"
#include "Unit.h"

namespace wk
{
	Unit::Unit(const std::string& image, int x, int y, int v) :
		mImage(image), mXPosition(x), mYPosition(y), mVelocity(v)
	{
	}

	Unit::Unit(std::string&& image, int x, int y, int v) :
		mImage(std::move(image)), mXPosition(x), mYPosition(y), mVelocity(v)
	{
	}

	int Unit::GetWidth() const
	{
		return mImage.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mImage.GetHeight();
	}

	int Unit::GetXCoord() const
	{
		return mXPosition;
	}

	int Unit::GetYCoord() const
	{
		return mYPosition;
	}

	void Unit::SetCoords(int x, int y)
	{
		mXPosition = x;
		mYPosition = y;
	}

	void Unit::UpdateXCoords(int amount)
	{
		mXPosition += amount;
	}

	void Unit::UpdateYCoords(int amount)
	{
		mYPosition += amount;
	}

	void Unit::UpdateXPos()
	{
		mXPosition += mVelocity;
	}

	void Unit::UpdateYPos()
	{
		mYPosition += mVelocity;
	}

	void Unit::UpdateXNeg()
	{
		mXPosition -= mVelocity;
	}

	void Unit::UpdateYNeg()
	{
		mYPosition -= mVelocity;
	}

	//void Unit::SetPicture(const Picture& pic)
	//{
	//	mImage.SetCurrentPicture()
	//}

	int Unit::GetVelocity() const
	{
		return mVelocity;
	}

	void Unit::SetVelocity(int v)
	{
		mVelocity = v;
	}


	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int left_a{ a.mXPosition };
		int right_a{ a.mXPosition + a.mImage.GetWidth() };
		int left_b{ b.mXPosition };
		int right_b{ b.mXPosition + b.mImage.GetWidth() }; // int right_b{ b.mXPosition + b.mXPosition.GetWidth() };

		bool x_intersection{ (left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b) };

		int bot_a{ a.mYPosition };
		int top_a{ a.mYPosition + a.mImage.GetHeight() };
		int bot_b{ b.mYPosition };
		int top_b{ b.mYPosition + b.mImage.GetHeight() }; //int top_b{ b.mYPosition + b.mXPosition.GetHeight() };

		bool y_intersection{ (bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b) };

		return x_intersection and y_intersection;
	}
}