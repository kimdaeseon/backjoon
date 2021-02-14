#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



void make2(queue<int>* q, int num, int num2, int num3) {   // 첫번재 후 단계적으로만 생성하는 함수
	for (int i = num3; i <= num2; i++) {
		q[num].push(i);
	}
	return;
}
void make(queue<int>* q, int num, int num2, int num3) {   //  첫번재 트리(나름대로 열심히 만듬) 제조 함수
	make2(q, num, num2, num3);
	if (num == 0)
		return;
	else
		return make(q, num - 1, num2, num3);

}
void process(queue<int>* q, int num, int num2, int num3, int num4) {  // 판단함수

	if (q[num].empty())
		return;
	if (q[num4].empty()) {
		q[num4 + 1].pop();
		process(q,  num, num2, num3, num4 + 1);
		make2(q,  num4, num2, num3);
	}
}
void show(queue<int>* q,  int num, int num2, int num3)    // 출력함수
{
	int* j = new int[num];
	int* arr = new int[num];
	bool check = true;
	for (;;) {
		if (q[num].empty())
			break;
		
		int a = 0;
		for (int i = num; i > 0; i--) {
			j[a] = q[i].front();
			arr[a] = q[i].front();
			a++;
		}
		sort(arr, arr + num);
		for (int i = 0; i < num; i++) {
			if (arr[i] != j[i]) {
				check = false;
				break;
			}
		}
		if (check == true)
		{
			for (int i = 0; i < num; i++) {
				cout << arr[i] << " ";
			}
			cout << '\n';
		}
		check = true;
		q[1].pop();
		process(q, num, num2, num3, 1);
	}
}

int main()
{
	queue<int> q[9];

	int num;
	int num2;
	cin >> num >> num2;
	make(q, num2, num, 1);
	show(q, num2, num, 1);

	return 0;
}