#include <iostream>
using namespace std;

int N;//���� ��
int P[150000 + 10];//���� ��

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

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	ans = mushroom();

	cout << ans << endl;	//	���� ���
	return 0;
}
