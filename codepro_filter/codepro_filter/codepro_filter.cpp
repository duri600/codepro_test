#include <iostream>
using namespace std;

int N;	// ������ ��
int R[11]; // �ݻ��� ����
int P[11]; // ������ ����

void InputData(void) {
	cin >> N;
	for (int i = 1; i <= N; i++)  cin >> R[i] >> P[i];
}

int main() {
	int ans = -1;
	InputData(); // �Է��Լ�

	// �ڵ带 �ۼ� �ϼ���

	cout << ans << endl;//���
	return 0;
}

