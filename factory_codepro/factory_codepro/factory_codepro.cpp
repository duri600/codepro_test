#include <iostream>
#include <queue>
using namespace std;

int N, M;//���� ��, ���� ���� ��
int A[5000], B[5000], D[5000];//���� A, ���� B, �Ÿ� D
int S[5000][5000];

#define IMP (int)(1e9)

void InputData() {
	int i;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> A[i] >> B[i] >> D[i];
		S[A[i]][B[i]] = S[B[i]][A[i]] = D[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			if (!S[i][j]) S[i][j] = S[j][i] = IMP;
		}
	}

}

int solve()
{
	for (int k = 1; k <= N; k++)
	{
		for (int s = 1; s <= N; s++)
		{
			for (int e = 1; e <= N; e++)
			{
				S[s][e] = S[s][e] > (S[s][k] + S[k][e]) ? (S[s][k] + S[k][e]) : S[s][e];
			}
		}
	}
	int min = IMP;
	for (int y = 1; y <= N; y++)
	{
		int max = 0;
		for (int x = 1; x <= N; x++)
		{
			max = max < S[y][x] ? S[y][x] : max;
		}
		min = min > max ? max : min;
	}
	return min;
}

int main() {
	int ans = -1;
	InputData();//	�Է� �Լ�
	ans = solve();


	//	�ڵ带 �ۼ��ϼ���


	cout << ans << endl;//	���� ���
	return 0;
}