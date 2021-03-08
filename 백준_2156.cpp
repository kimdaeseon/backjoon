#include <iostream>
using namespace std;

int numberOfJucie;
int amountOfJucie[10001];

int proccess(int number, int isDrank, int board[][3]);

int main() {
	cin >> numberOfJucie;
	int board[10001][3];
	for (int i = 1; i < numberOfJucie + 1; i++) {
		cin >> amountOfJucie[i];
		board[i][0] = { -1 };
		board[i][1] = { -1 };
		board[i][2] = { -1 };
	}

	int a;
	int b;
	int c;
	int max;
	for (int i = 1; i < numberOfJucie; i++) {
		a = proccess(i, 0, board);
		b = proccess(i, 1, board);
		c = proccess(i, 2, board);
	}
	a = proccess(numberOfJucie, 0, board);
	b = proccess(numberOfJucie, 1, board);
	c = proccess(numberOfJucie, 2, board);
	max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
	cout << max;

	return 0;
}

int proccess(int number, int isDrank, int board[][3]) {
	
	int a;
	int b;
	int c;
	int max;
	if (number == 0) {
		return 0;
	}
	if (board[number][isDrank] != -1) {
		return board[number][isDrank];
	}
	else {
		if (isDrank == 2) {
			// 전에도 마시고 이번에도 마셔야함
			board[number][isDrank] = proccess(number - 1, 1, board) + amountOfJucie[number];
		}
		else if (isDrank == 1) {
			// 전에 안마시고 이번에 마셔야함
			board[number][isDrank] = proccess(number - 1, 0, board) + amountOfJucie[number];
		}
		else {
			// 이번에 마시면 안댐
			a = proccess(number - 1, 0, board);
			b = proccess(number - 1, 1, board);
			c = proccess(number - 1, 2, board);
			max = (a > b) ? ((a > c) ? a : c) : ((b > c)? b : c);
			board[number][isDrank] = max;
		}
		return board[number][isDrank];
	}
}