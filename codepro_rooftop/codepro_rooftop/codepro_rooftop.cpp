#include <iostream>
#include <stack>
using namespace std;

int N;//건물 수
int H[80010];//건물 높이
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
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
	ans = roofTop();

	cout << ans << endl;	//	정답 출력
	return 0;
}
