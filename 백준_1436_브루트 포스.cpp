/*
666은 종말을 나타내는 숫자라고 한다. 
따라서, 많은 블록버스터 영화에서는 666이 들어간 제목을 많이 사용한다. 
영화감독 숌은 세상의 종말 이라는 시리즈 영화의 감독이다. 
조지 루카스는 스타워즈를 만들 때, 스타워즈 1, 스타워즈 2, 스타워즈 3, 스타워즈 4, 스타워즈 5, 스타워즈 6과 같이 이름을 지었고, 
피터 잭슨은 반지의 제왕을 만들 때, 반지의 제왕 1, 반지의 제왕 2, 반지의 제왕 3과 같이 영화 제목을 지었다.

하지만 숌은 자신이 조지 루카스와 피터 잭슨을 뛰어넘는다는 것을 보여주기 위해서 영화 제목을 좀 다르게 만들기로 했다.

종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수를 말한다. 
제일 작은 종말의 숫자는 666이고, 그 다음으로 큰 수는 1666, 2666, 3666, .... 과 같다.

따라서, 숌은 첫 번째 영화의 제목은 세상의 종말 666, 
두 번째 영화의 제목은 세상의 종말 1666 이렇게 이름을 지을 것이다. 
일반화해서 생각하면, N번째 영화의 제목은 세상의 종말 (N번째로 작은 종말의 숫자) 와 같다.

숌이 만든 N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오.
숌은 이 시리즈를 항상 차례대로 만들고, 다른 영화는 만들지 않는다.

입력
첫째 줄에 숫자 N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 N번째 영화의 제목에 들어간 수를 출력한다.
*/

#include <iostream>
using namespace std;

bool thisIs666(long long int num)
{
	int count = 0;
	long long int temp = num;
	int* arr1;
	int* arr2;
	while (true) {
		count++;
		if (temp / 10 == 0)
			break;
		temp /= 10;
	}
	arr1 = new int[count];
	arr2 = new int[count];
	temp = num;
	for (int i = 0; i < count; i++) {
		arr1[i] = temp % 10;
		temp /= 10;
	}
	for (int i = 0; i < count; i++) {
		arr2[i] = arr1[count - 1 - i];
	}

	for (int i = 0; i < count-2; i++)
	{
		if (arr2[i] == 6)
			if (arr2[i + 1] == 6)
				if (arr2[i + 2] == 6) {
					delete arr1, arr2;
					return true;
				}
	}
	delete arr1;
	delete arr2;
	return false;
}

int main() {

	int target;
	int count = 0;
	cin >> target;
	long long int num = 666;
	while (true) {

		if (thisIs666(num) == true) {
			num += 1;
			count++;
		}
		else if (thisIs666(num) == false) {
			num += 1;
		}

		if (target == count) {
			num -= 1;
			break;
		}
	}
	cout << num;

	return 0;
}