#include "pch.h"
#include "interface.h"


void SV_Run()
{
	SV_DebugLog("SV_Run() - start", FuncType);

	thread_run = true;

	while (!thread_exit)
	{
		if (oneDayCycle < MINCYCLE) {
			SV_ErrorLog("SV_Run(): oneDayCycle의 크기가 MINCYCLE 보다 작습니다.");
			break;
		}

		Sleep(oneDayCycle);

		if (game == nullptr) {
			SV_ErrorLog("SV_Run(): game 인스턴스의 nullptr 값을 참조 시도를 하여, Thread를 종료합니다.");
			break;
		}
		game->Oneday();
	}

	thread_run = false;

	SV_DebugLog("SV_Run() - end", FuncType);
}

void SV_WriteJson()
{
	SV_DebugLog("SV_WriteJson", FuncType);
	root["Date"] = game->Today();
	jsonDocument = Json::writeString(wbuilder, root);
}

void SV_Interface_InitGame(unsigned int _cycle, int _debugMode)
{

	if (isInit)
		return;

	if (thread_run) {
		SV_ErrorLog("thread가 작동중일때 InitGame()이 호출되었습니다.");
		return;
	}

	//**************************
	//game 생성 및 초기화

	if(game == nullptr)
		game = new Game();

	//**************************

	switch (_debugMode) {
	case 2:
		fDebugMode = true;
		lDebugMode = true;

	case 1:
		fDebugMode = false;
		lDebugMode = true;

	default:
		fDebugMode = false;
		lDebugMode = false;

	}

	
	oneDayCycle = max(MINCYCLE, _cycle);

	thread_exit = false;
	thread_run = false;
	isInit = true;
}

void SV_Interface_PlayGame()
{
	SV_DebugLog("SV_Interface_PlayGame()", FuncType);

	if (!isInit)
		return;

	if (thread_run)
		return;


	thread_exit = false;
	std::thread Simulator(SV_Run);
	Simulator.detach();
}
LPCTSTR SV_Interface_GetData()
{
	SV_DebugLog("SV_Interface_GetData()", FuncType);

	SV_WriteJson();

	return (LPCTSTR) jsonDocument.c_str();
}


LPCTSTR SV_Interface_EnforcePolicy()
{
	SV_DebugLog("SV_Interface_GetData()", FuncType);

	if (!isInit)
		return nullptr;
	if (!thread_run)
		return nullptr;

	return SV_Interface_GetData();
}



void SV_Interface_EndGame()
{
	SV_DebugLog("SV_Interface_EndGame()", FuncType);

	thread_exit = true;
	thread_run = false;
	isInit = false;
	lDebugMode = false;
	fDebugMode = false;

	//**************************
	//game 해제

	delete game;
	game = nullptr;

	//**************************

}

void SV_DebugLog(const char* _str, int _type)
{
	if (_type == FuncType && !fDebugMode)
		cout << "SV_LOG: " << _str << endl;

	else if (_type == LogType && lDebugMode)
		cout << "SV_LOG: " << _str << endl;
}

void SV_ErrorLog(const char* _str)
{
	cout << "SV_ERO: "<<_str << endl;
}