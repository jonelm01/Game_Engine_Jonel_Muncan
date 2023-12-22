#pragma once

#include "Utilities.h"

namespace wk
{
	class WANKEL_API KeyPressed
	{
	public:
		KeyPressed(int kcode);

		int GetKeyCode() const;

	private: 
		int mKeyCode;
	};

	class WANKEL_API KeyReleased
	{
	public:
		KeyReleased(int kcode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class WANKEL_API WindowClosed
	{
		
	};
}