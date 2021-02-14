#include <iostream>
using namespace std;

/*
�����̴� �ڽ��� ���ÿ��� MN���� ���� ���簢������ �������� �ִ� M*N ũ���� ���带 ã�Ҵ�. 
� ���簢���� ���������� ĥ���� �ְ�, �������� ������� ĥ���� �ִ�.
�����̴� �� ���带 �߶� 8*8 ũ���� ü�������� ������� �Ѵ�.

ü������ �������� ����� �����Ƽ� ĥ���� �־�� �Ѵ�. ��ü������, 
�� ĭ�� �������� ��� �� �ϳ��� ��ĥ�Ǿ� �ְ�, 
���� �����ϴ� �� ���� �簢���� �ٸ� ������ ĥ���� �־�� �Ѵ�. 
���� �� ���Ǹ� ������ ü������ ��ĥ�ϴ� ���� �� �������̴�.
�ϳ��� �� ���� �� ĭ�� ����� ���, �ϳ��� �������� ����̴�.

���尡 ü����ó�� ĥ���� �ִٴ� ������ ���, 
�����̴� 8*8 ũ���� ü�������� �߶� �Ŀ� �� ���� ���簢���� �ٽ� ĥ�ؾ߰ڴٰ� �����ߴ�. 
�翬�� 8*8 ũ��� �ƹ������� ��� �ȴ�. 
�����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢���� �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� M�� �־�����. N�� M�� 8���� ũ�ų� ����,
50���� �۰ų� ���� �ڿ����̴�. 
��° �ٺ��� N���� �ٿ��� ������ �� ���� ���°� �־�����. 
B�� �������̸�, W�� ����̴�.

���
ù° �ٿ� �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢�� ������ �ּڰ��� ����Ѵ�.
*/

int checkWhite(char** chess, int garo, int saero) {
	int result = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			if (((i + j) % 2) == 0)
			{
				if (chess[garo + i][saero + j] == 'B')
					result++;
			}
			if (((i + j) % 2) == 1)
			{
				if (chess[garo + i][saero + j] == 'W')
					result++;
			}
		}
	}

	return result;
}

int checkBlack(char** chess, int garo, int saero) {
	int result = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			if (((i + j) % 2) == 0)
			{
				if (chess[garo + i][saero + j] == 'W')
					result++;
			}
			if (((i + j) % 2) == 1)
			{
				if (chess[garo + i][saero + j] == 'B')
					result++;
			}
		}
	}

	return result;

}

int main() {
	int garo, saero, result, temp = 0;
	char** chess;
	cin >> garo >> saero;
	result = garo * saero;
	chess = new char* [garo];
	for (int i = 0; i < garo; i++) {
		chess[i] = new char[saero + 1];
		chess[i][saero] = NULL;
		cin >> chess[i];
	}

	for (int i = 0; i < garo - 7; i++) {
		for (int j = 0; j < saero - 7; j++) {
			temp = checkWhite(chess, i, j);
			if (temp > checkBlack(chess, i, j)) {
				temp = checkBlack(chess, i, j);
			}
			if (temp < result)
				result = temp;
		}
	}

	cout << result;

	return 0;
}