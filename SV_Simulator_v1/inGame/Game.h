#pragma once

class Game {
private:
	int date;

	/// <summary>
	/// Game�� ���õ� �͵��� �ʱ�ȭ �ϴ� �Լ�. �Ϲ������� �����ڿ��� ȣ��.
	/// </summary>
	void InitializeGame();
	/// <summary>
	/// ���� ���� ���� �Ҹ��ڷ� ���� ȣ���.
	/// </summary>
	void EndGame();



public:
	Game();	

	/// <summary>
	/// 1�� ������ ȣ��Ǵ� �Լ�
	/// </summary>
	void Oneday();
	int Today() { return date; };

	~Game();

//���⼭ ���� �ۼ����ּ���.******************************************

private:

public:

protected:

};