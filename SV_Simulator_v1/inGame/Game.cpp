#include "Game.h"


//*******************************
Game::Game() {
	date = 1;
	
	InitializeGame();
}
Game::~Game() {
	EndGame();
}
//*******************************




//여기서 부터 작성 가능 *********************
void Game::InitializeGame() {
	// 게임 초기화 관련 코드 작성


}

void Game::Oneday() {
	date += 1;

	// 1일 단위로 진행되는 연산 코드 작성

}

void Game::EndGame() {
	// 게임 종료시 필요한 코드 작성

}

