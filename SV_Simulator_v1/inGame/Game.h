#pragma once

class Game {
private:
	int date;

	/// <summary>
	/// Game과 관련된 것들을 초기화 하는 함수. 일반적으로 생성자에서 호출.
	/// </summary>
	void InitializeGame();
	/// <summary>
	/// 게임 종료 직적 소멸자로 부터 호출됨.
	/// </summary>
	void EndGame();



public:
	Game();	

	/// <summary>
	/// 1일 단위로 호출되는 함수
	/// </summary>
	void Oneday();
	int Today() { return date; };

	~Game();

//여기서 부터 작성해주세요.******************************************

private:

public:

protected:

};