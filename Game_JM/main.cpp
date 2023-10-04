#include"Wankel.h"
#include <iostream>

class MyGame : public wk::WankelApp<MyGame>
{
public:
	virtual void OnUpdate() override {
		std::cout << "Wankel running" << std::endl;
	}

};

WANKEL_APPLICATION_START(MyGame);
//int main()
//{
//MyGame::Init();
//MyGame::RunInterface();
//return(0);
//}




