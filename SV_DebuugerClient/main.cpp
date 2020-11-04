#include "interface.h"
#include <Windows.h>

#include <fstream>
#include <iostream>

int main()
{
	LPCTSTR message;
	// 0: ��� Debug log ��� X
	// 1: Debug log ��� o , function log ��� x
	// 2: Debug log ��� o , function log ��� o
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