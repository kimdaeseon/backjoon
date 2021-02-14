#include <iostream>
using namespace std;


/*
����
� �ڿ��� N�� ���� ��, 
�� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�. 
� �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�. ���� ���, 
245�� �������� 256(=245+2+4+5)�� �ȴ�. ���� 245�� 256�� �����ڰ� �ȴ�. 
����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�. 
�ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.

�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1 �� N �� 1,000,000)�� �־�����.

���
ù° �ٿ� ���� ����Ѵ�. �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.
*/


int makeNum(int num) {
	int arr[8] = { 0 };
	int temp = num;
	int sum = 0;
	int i = 0;
	while (true) {
		if (temp == 0)
			break;
		arr[i] = temp % 10;
		temp /= 10;
		i++;
	}
	for (int j = 0; j < 8; j++)
	{
		sum += arr[j];
	}
	return (num + sum);
}

int main() {
	int num, result;
	cin >> num;

	for (int i = 0; i <= 1000000; i++) {
		if (makeNum(i) == num) {
			result = i;
			break;
		}
	}

	cout << result << endl;
	return 0;
}