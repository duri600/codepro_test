#include <iostream>
#include <stack>
using namespace std;

int N;//�ǹ� ��
int H[80010];//�ǹ� ����
stack<int> building;

void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
}

long long roofTop() {
	int count = 0;
	
	for (int i = 0; i < N; i++)
	{
		while (!building.empty())
		{
			if (H[i] < building.top())
			{
				break;
			}
			else
			{
				building.pop();
			}
		}
		count += building.size();
		building.push(H[i]);

	}

	return count;
}

int main() {
	long long ans = -1;
	Input_Data();		//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	ans = roofTop();

	cout << ans << endl;	//	���� ���
	return 0;
}
