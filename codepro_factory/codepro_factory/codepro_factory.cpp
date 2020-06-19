#include <iostream>
using namespace std;

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량

void Input_Data(void) {
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> C[i] >> Y[i];
	}
}

long long factory()
{
	long long cost = C[0];
	long long sum = cost * Y[0];

	// i번째 비용 + 보관비용 < i + 1번째 비용 이라면 -> i번째 날에 i+1번째 재고까지 다사는게 이득
	// i번째 비용 + 보관비용 > i + 1번째 비용 이라면 -> i번째에는 i번째만 사는것이 이득

	for (int i = 1; i < N; i++)
	{
		cost += S;
		if (cost > C[i]) //
		{
			cost = C[i];
		}
		sum += cost * Y[i];

	}

	return sum;
}

int main() {
	long long ans = -1;
	Input_Data();		// 입력 함수

	// TODO : 코드를 작성하세요
	ans = factory();

	cout << ans << endl;	// 정답 출력
	return 0;
}
