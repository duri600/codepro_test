#include <iostream>
#include <algorithm>
using namespace std;

int N;//손님 수
int P[10000 + 10];//음식 값
int T[10000 + 10];//예약 희망 시간
int reserve_T[10000];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		cin >> T[i];
	}
}

int compare(int a, int b) {
	if (a > b)return 1;
	else return 0;
}

int transform(int time, int temp_price) {
	if (reserve_T[time] == 0)
	{
		reserve_T[time] = temp_price;
		return -1;
	}
	else
	{
		if (reserve_T[time] >= temp_price) // 기존에 예약된 음식 값이 새로 온 음식 값보다 높을 때. 
		{
			return temp_price;
		}
		else
		{
			int temp = reserve_T[time];
			reserve_T[time] = temp_price;
			return temp;
		}
	}
}

void max_profit() {
	int temp_price;
	for (int i = 0; i < N; i++)
	{
		if (reserve_T[T[i]] == 0)
		{
			reserve_T[T[i]] = P[i];
		}
		else
		{
			// 이미 그 시간에 예약된 사람이 있으면 기존에 있던 음식 값과 현재 들어온 음식 값을 비교한다.
			// 비교하여 기존 값이 크면 예약 시간을 하나 낮춰서 대입. 기존 값이 작으면 기존 값을 빼내고 현재 값 대입.
			// while문으로 k가 0까지 갈때까지 반복하도록 k번째 index와 음식 값을 return
			temp_price = P[i];
			while (T[i] > 0)
			{
				temp_price = transform(T[i], temp_price);
				T[i]--;
				if (temp_price < 0)
				{
					break;
				}
			}

		}
	}
}

int max_profit_sum()
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (T[i] > max)
		{
			max = T[i];
		}
	}

	int max_sum = 0;
	for (int i = 0; i <= max; i++)
	{
		max_sum = max_sum + reserve_T[i];
	}

	return max_sum;
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	max_profit();

	ans = max_profit_sum();

	cout << ans << endl;	//	정답 출력
	return 0;
}
