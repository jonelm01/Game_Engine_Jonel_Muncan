#pragma once
#ifdef WK_DEBUG==2
	#define WK_ERROR(x)std::cout<<x<<std::endl;
	#define WK_LOG(x)std::cout<<x<<std::endl;
#elif WK_DEBUG==1
	#define WK_ERROR(x)std::cout<<x<<std::endl;
	#define WK_LOG(x)
#else
	#define WK_ERROR(x)
	#define WK_LOG(x)
#endif
#ifdef WANKEL_MSCPP
	#ifdef WANKEL_LIB
		#define WANKEL_API __declspec(dllexport)
	#else
		#define WANKEL_API __declspec(dllimport)
	#endif
#else
	#define WANKEL_API
#endif
#define WANKEL_APPLICATION_START(ClassName)\
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}