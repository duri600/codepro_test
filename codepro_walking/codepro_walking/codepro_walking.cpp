#include <iostream>
#include <vector>
using namespace std;

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)
int position[100000 + 10];
int count_N[100000 + 10];

void InputData() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> P[i] >> S[i];
	}
}

int walking(){
	for (int time = 0; time <= T; time++)
	{
		if (time == 0)
		{
			for (int i = 0; i < N; i++)
			{
				position[i] = P[i];
				count_N[i] = 1;
			}
		}
		else
		{
			for (int i = N - 1; i >= 0; i--)
			{
				if (position[i] != -1)
				{
					position[i] = position[i] + S[i];
					if (i < N - 1) {
						if (position[i] >= position[i + 1])
						{
							position[i] = position[i + 1];
							count_N[i] = 0;
						}
					}
				}
			}
		}
	}
	
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = sum + count_N[i];
	}
	return sum;
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	ans = walking();

	cout << ans << endl;	//	정답 출력
	return 0;
}
