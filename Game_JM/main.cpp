#include"Wankel.h"

#include <iostream>

class MyGame : public wk::WankelApp<MyGame>
{
public:
	MyGame()
	{
		SetKeyPressedCallback([this](const wk::KeyPressed& e) {OnKeyPress(e);  });
		SetKeyReleasedCallback([this](const wk::KeyReleased& e) {OnKeyRelease(e);  });
	}


	virtual void OnUpdate() override 
	{
		////////////////////////////////////////////////////////////Check Win Condition
		if (mWinCount == 3) {
			Draw(0, 280, mWinScreen);
		}

		////////////////////////////////////////////////////////////When game not won
		else {
			Draw(0, 0, mBG);
			Draw(0, 810, Sun0);
			Draw(mEnemy);

			if (EnemyRight) { //if enemy going right
				mEnemy.UpdateXPos();
			}
			else { //if enemy going left
				mEnemy.UpdateXNeg();
			}
			EnemySteps++;

			/////////////////////////////////////////////////////////Enemy Movement
			if (mEnemy.GetXCoord() >= (mBG.GetWidth()  - mEnemy.GetWidth()) && EnemyRight) {
				EnemyRight = false;
				EnemySteps = 0;
				if (mEnemy.GetYCoord() > mEnemy.GetHeight())
					mEnemy.UpdateYNeg();
			}
			else if (mEnemy.GetXCoord() <= 0 && !EnemyRight) {
				EnemyRight = true;
				EnemySteps = 0;
				if (mEnemy.GetYCoord() > mEnemy.GetHeight())
					mEnemy.UpdateYNeg();
			}
			/////////////////////////////////////////////////////////Character Draw & Collision
			if (mDirection == 1) {
				Draw(mPR);
				if (wk::UnitsOverlap(mPR, mEnemy)) {
					DamageY = mPR.GetYCoord();
					DamageX = mPR.GetXCoord();
					mPU.SetCoords(CenterX, 0);
					mPL.SetCoords(CenterX, 0);
					mPR.SetCoords(CenterX, 0);
					mLives--;
					Draw(DamageX, DamageY, Explosion);
				}
			}
			else if (mDirection == -1) {
				Draw(mPL);
				if (wk::UnitsOverlap(mPL, mEnemy)) {
					DamageY = mPL.GetYCoord();
					DamageX = mPL.GetXCoord();
					mPU.SetCoords(CenterX, 0);
					mPL.SetCoords(CenterX, 0);
					mPR.SetCoords(CenterX, 0);
					mLives--;
					Draw(DamageX, DamageY, Explosion);
				}
			}
			else {
				mDirection = 0;
				Draw(mPU);
				if (wk::UnitsOverlap(mPU, mEnemy)) {
					DamageY = mPU.GetYCoord();
					DamageX = mPU.GetXCoord();
					mPU.SetCoords(CenterX, 0);
					mPL.SetCoords(CenterX, 0);
					mPR.SetCoords(CenterX, 0);
					mLives--;
					Draw(DamageX, DamageY, Explosion);
				}
			}

			/////////////////////////////////////////////////////////////Character TopScreen "Collision"
			if (mPU.GetYCoord() >= 1000) {
				mWinCount++;
				int vel = mEnemy.GetVelocity();
				mEnemy.SetVelocity(vel + 5);
				mPU.SetCoords(CenterX, 0);
				mPL.SetCoords(CenterX, 0);
				mPR.SetCoords(CenterX, 0);
			}
			////////////////////////////////////////////////////////////Display Lives
			if (mLives == 3) {
				Draw(mBG.GetWidth() - m3Lives.GetWidth(), 0, m3Lives);
			}
			else if (mLives == 2) {
				Draw(mBG.GetWidth() - m2Lives.GetWidth(), 0, m2Lives);
			}
			else if (mLives == 1) {
				Draw(mBG.GetWidth() - m3Lives.GetWidth(), 0, m1Lives);
			}
			else {
				Draw(mBG.GetWidth() - m0Lives.GetWidth(), 0, m0Lives);
			}
		}
		////////////////////////////////////////////////////////////Game Over display
		if (mLives == 0) {
			Draw(0, 0, mGameOver);
		}
	}
	

	void OnKeyPress(const wk::KeyPressed& e)
	{
		if (e.GetKeyCode() == WANKEL_KEY_RIGHT)
		{
			mDirection = 1;
			mPU.UpdateXPos();
			mPL.UpdateXPos();
			mPR.UpdateXPos();
		}
		else if (e.GetKeyCode() == WANKEL_KEY_LEFT)
		{
			mDirection = -1;
			mPU.UpdateXNeg();
			mPL.UpdateXNeg();
			mPR.UpdateXNeg();
		}
		else if (e.GetKeyCode() == WANKEL_KEY_UP)
		{
			mDirection = 0;
			mPU.UpdateYPos();
			mPL.UpdateYPos();
			mPR.UpdateYPos();
		}
		else if (e.GetKeyCode() == WANKEL_KEY_DOWN)
		{
			mDirection = 0;
			mPU.UpdateYNeg();
			mPL.UpdateYNeg();
			mPR.UpdateYNeg();
		}
	}


	void OnKeyRelease(const wk::KeyReleased& e)
	{
		mDirection = 0; //when key released, set character to face up
	}


private:
	////////////////////////////////////////////////////////////Win Variables
	unsigned int mWinCount{ 0 };
	wk::Picture mWinScreen{ "../Assets/Pictures/Win.png" };
	const int CenterX{ 860 };


	////////////////////////////////////////////////////////////Lives Counter Variables
	unsigned int mLives{ 3 };
	wk::Picture m3Lives{ "../Assets/Pictures/Lives_3.png"};
	wk::Picture m2Lives{ "../Assets/Pictures/Lives_2.png" };
	wk::Picture m1Lives{ "../Assets/Pictures/Lives_1.png" };
	wk::Picture m0Lives{ "../Assets/Pictures/Lives_0.png" };
	wk::Picture mGameOver{ "../Assets/Pictures/GameOver.png" };


	////////////////////////////////////////////////////////////Player Variables
	wk::Unit mPU{ "../Assets/Pictures/GU.png", CenterX, 0, 100 };
	wk::Unit mPL{"../Assets/Pictures/GL.png", CenterX, 0, 100};
	wk::Unit mPR{"../Assets/Pictures/GR.png", CenterX, 0, 100 };

	int mDirection{ 0 };


	////////////////////////////////////////////////////////////Enemy Variables
	wk::Unit mEnemy{"../Assets/Pictures/Enemy.png", 20, 800, 15};
	bool EnemyRight{ true };
	unsigned int EnemySteps{ 0 };


	////////////////////////////////////////////////////////////Extra Pictures for collision and sun
	wk::Picture Sun0{ "../Assets/Pictures/sun_0.png" };
	wk::Picture Explosion{ "../Assets/Pictures/Explosion.png" };
	wk::Picture mBG{ "../Assets/Pictures/BG1.png" };


	//bool CountInc{ true };
	int DamageX{ 0 };
	int DamageY{ 0 };
	int x{ 100 };
	int y{ 100 };
};

WANKEL_APPLICATION_START(MyGame);
