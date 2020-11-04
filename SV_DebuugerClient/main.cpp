#include "interface.h"
#include <Windows.h>

#include <fstream>
#include <iostream>

int main()
{
	LPCTSTR message;
	// 0: 모든 Debug log 출력 X
	// 1: Debug log 출력 o , function log 출력 x
	// 2: Debug log 출력 o , function log 출력 o
	SV_Interface_InitGame(500, 1);

	SV_Interface_PlayGame();

	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		message = SV_Interface_GetData();
		std::cout <<  message << std::endl;
	}
	SV_Interface_EndGame();
}