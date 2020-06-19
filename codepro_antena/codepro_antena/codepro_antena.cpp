#include <iostream>
#include <stack>
using namespace std;

int N;//�ۼ��� ���׳� ��
int H[100000 + 10];//�ۼ��� ���׳� ����
stack<int> group;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
}

int antena() {
	int connect = 0;
	for (int i = 0; i < N; i++)
	{
		while (!group.empty() && (group.top() < H[i]))
		{
			connect++;
			group.pop();
		}

		if (!group.empty())
		{
			connect++;
			if (group.top() == H[i]) group.pop();
		}

		group.push(H[i]);
	}

	return connect;
}

int main() {
	int ans = -1;
	InputData();//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	ans = antena();

	cout << ans << endl;//���
	return 0;
}
