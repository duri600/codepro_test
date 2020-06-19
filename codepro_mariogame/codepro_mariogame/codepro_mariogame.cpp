#include <iostream>
using namespace std;

int N;//버섯 수
int P[150000 + 10];//버섯 값

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
}

int mushroom() {
	int sum;

	sum = P[0];
	for (int i = 1; i < N; i++)
	{
		if (P[i - 1] < P[i])
		{
			sum = sum - P[i - 1] + P[i];
		}
	}
	return sum;
}

int main() {
	int ans = 0;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	ans = mushroom();

	cout << ans << endl;	//	정답 출력
	return 0;
}
