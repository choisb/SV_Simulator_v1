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




//���⼭ ���� �ۼ� ���� *********************
void Game::InitializeGame() {
	// ���� �ʱ�ȭ ���� �ڵ� �ۼ�


}

void Game::Oneday() {
	date += 1;

	// 1�� ������ ����Ǵ� ���� �ڵ� �ۼ�

}

void Game::EndGame() {
	// ���� ����� �ʿ��� �ڵ� �ۼ�

}

