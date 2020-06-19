#include <iostream>
#include <algorithm>
using namespace std;

int N;//�մ� ��
int P[10000 + 10];//���� ��
int T[10000 + 10];//���� ��� �ð�
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
		if (reserve_T[time] >= temp_price) // ������ ����� ���� ���� ���� �� ���� ������ ���� ��. 
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
			// �̹� �� �ð��� ����� ����� ������ ������ �ִ� ���� ���� ���� ���� ���� ���� ���Ѵ�.
			// ���Ͽ� ���� ���� ũ�� ���� �ð��� �ϳ� ���缭 ����. ���� ���� ������ ���� ���� ������ ���� �� ����.
			// while������ k�� 0���� �������� �ݺ��ϵ��� k��° index�� ���� ���� return
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

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	max_profit();

	ans = max_profit_sum();

	cout << ans << endl;	//	���� ���
	return 0;
}
