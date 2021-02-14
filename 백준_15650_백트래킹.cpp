#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


void Swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* arr, int nArr) {
	for (int i = 0; i < nArr; i++) {
		for (int j = 0; j < nArr - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}


void check(int* arr, int num) {

	int* arr2 = new int[num];
	bool check = true;
	for (int i = 0; i < num; i++) {
		arr2[i] = arr[i];
	}
	BubbleSort(arr, num);
	for (int i = 0; i < num; i++) {
		if (arr2[i] != arr[i])
			check = false;
	}
	if (check == true)
	{
		for (int i = 0; i < num; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}


}


void make(queue<int>* q, queue<int>* s, int num, int num2, int num3) {   //  ù���� Ʈ��(������� ������ ����) ���� �Լ�
	int arr[9];
	int count = 0;

	for (int i = num2; i > 0; i--) {
		if (!q[i].empty()) {
			arr[count] = q[i].front();
			count++;
		}
	}
	bool check = true;
	for (int i = num3; i <= num2; i++) {
		for (int j = 0; j < count; j++) {
			if (i == arr[j]) {
				check = false;
				break;
			}
		}
		if (check == true)
			q[num].push(i);
		check = true;
	}


	if (num == 0)
		return;
	else
		return make(q, s, num - 1, num2, num3);

}
void make2(queue<int>* q, queue<int>* s, int num, int num2, int num3) {   // ù���� �� �ܰ������θ� �����ϴ� �Լ�
	int arr[9];
	int count = 0;

	for (int i = num2; i > 0; i--) {
		if (!q[i].empty()) {
			arr[count] = q[i].front();
			count++;
		}
	}
	bool check = true;
	for (int i = num3; i <= num2; i++) {
		for (int j = 0; j < count; j++) {
			if (i == arr[j]) {
				check = false;
				break;
			}
		}
		if (check == true)
			q[num].push(i);
		check = true;
	}
	return;
}
void process(queue<int>* q, queue<int>* s, int num, int num2, int num3, int num4) {  // �Ǵ��Լ�

	if (q[num].empty())
		return;
	if (q[num4].empty()) {
		q[num4 + 1].pop();
		process(q, s, num, num2, num3, num4 + 1);
		make2(q, s, num4, num2, num3);
	}
}
void show(queue<int>* q, queue<int>* s, int num, int num2, int num3)    // ����Լ�
{
	for (;;) {
		if (q[num].empty())
			break;
		int* j = new int[num];
		int a = 0;
		for (int i = num; i > 0; i--) {
			//cout << q[i].front() << " ";
			j[a] = q[i].front();
			a++;
		}
		check(j, num);
		q[1].pop();
		process(q, s, num, num2, num3, 1);
	}
}



int main()
{
	queue<int> q[10];
	queue<int>* s;
	queue<int> lol;
	s = &lol;

	int num;
	int num2;
	cin >> num >> num2;
	make(q, s, num2, num, 1);
	show(q, s, num2, num, 1);





	return 0;
}