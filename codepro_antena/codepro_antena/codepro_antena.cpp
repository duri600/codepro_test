#include <iostream>
#include <stack>
using namespace std;

int N;//송수신 안테나 수
int H[100000 + 10];//송수신 안테나 높이
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
	InputData();//	입력 함수

	//	코드를 작성하세요
	ans = antena();

	cout << ans << endl;//출력
	return 0;
}
