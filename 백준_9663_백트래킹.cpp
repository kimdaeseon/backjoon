#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct pos {
	int x;
	int y;
};

//유망한지 판단
bool IsVaild(int board[], pos a, int length, int depth) {
	int diff;
	for(int i = 0 ; i < depth; i++){
		diff = depth - i;
		if (a.x == board[i] + diff) return false;
		if (a.x == board[i] - diff) return false;
		if (board[i] == a.x) return false;
	}
	return true;
}
//깊이우선탐색
void DFS(int board[] ,stack<pos>& s, int length, int depth) {
	int x = s.top().x;
	int y = s.top().y;
	board[y] = x;
	s.pop();
	for (int i = 0; i < length; i++) {
		pos a;
		a.x = i;
		a.y = depth;
		if(IsVaild(board, a, length, depth))
			s.push(a);
	}
}


int main() {
	// num = 체스판의 크기
	int length;
	int count = 0;
	cin >> length;
	// 처음에는 스택으로 놓여있는 퀸의 위치를 나타내려고했으나
	// 시간초과가 나왔고
	// int 배열을 통해 표현하는 방법으로 바꾸고 시간문제 해결
	int* board = new int[length];
	stack<pos> s;
	for (int i = 0; i < length; i++) {
		pos x;
		x.x = i;
		x.y = 0;
		s.push(x);
	}
	while (!s.empty()) {
		if (s.top().y == length - 1) {
			count++;
			s.pop();
			continue;
		}
		DFS(board, s, length, s.top().y + 1);
	}
	cout << count;
	delete board;
}