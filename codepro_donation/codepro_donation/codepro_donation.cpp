#include <iostream>
using namespace std;

int N;//직원 수
int M;//기부금 총액
int A[1000010];//직원 별 성과급

void InputData() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

int donation_sum(int max_donate) {
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if ((A[i] - max_donate) > 0)
		{
			sum += (A[i] - max_donate);
		}
	}
	return sum;
}

int cal_max(int max_donate) {
	int max_fin;
	int maximum = max_donate;
	int while_flag = 1;
	int state = 0;
	while (while_flag)
	{
		int cal_sum = donation_sum(maximum);
		if (cal_sum > M)
		{
			if (state == 0)
				maximum = maximum + 1;
			else if(state == 1)
			{
				max_fin = maximum;
				while_flag = 0;
			}
		}
		else if (cal_sum < M)
		{
			maximum = maximum - 1;
			state = 1;
		}
		else if (cal_sum == M)
		{
			max_fin = maximum;
			while_flag = 0;
		}
	}
	return max_fin;
}


int main() {
	int ans = 0;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	int max_donation_init;
	int total_A = 0;
	for (int i = 0; i < N; i++)
	{
		total_A += A[i];
	}
	max_donation_init = total_A / N;

	ans = cal_max(max_donation_init);
	

	cout << ans << endl;	//	정답 출력
	return 0;
}
