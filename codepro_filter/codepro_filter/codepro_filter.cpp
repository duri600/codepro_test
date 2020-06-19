#include <iostream>
using namespace std;

int N;	// 필터의 수
int R[11]; // 반사의 정도
int P[11]; // 투과의 정도

void InputData(void) {
	cin >> N;
	for (int i = 1; i <= N; i++)  cin >> R[i] >> P[i];
}

int main() {
	int ans = -1;
	InputData(); // 입력함수

	// 코드를 작성 하세요

	cout << ans << endl;//출력
	return 0;
}

