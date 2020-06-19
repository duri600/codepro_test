#include <iostream>
using namespace std;

int N; //��
int S; //�������
int C[50010]; //����
int Y[50010]; //�뷮

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

	// i��° ��� + ������� < i + 1��° ��� �̶�� -> i��° ���� i+1��° ������ �ٻ�°� �̵�
	// i��° ��� + ������� > i + 1��° ��� �̶�� -> i��°���� i��°�� ��°��� �̵�

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
	Input_Data();		// �Է� �Լ�

	// TODO : �ڵ带 �ۼ��ϼ���
	ans = factory();

	cout << ans << endl;	// ���� ���
	return 0;
}
