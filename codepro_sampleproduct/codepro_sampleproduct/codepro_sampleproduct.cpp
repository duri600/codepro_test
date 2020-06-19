#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int N;//제품 수
struct st {
	int X, ID;//위치, 아이디
};
st A[50010];
map <int, int> A_Map;
map <int, vector<int>> ID_Map;
map <int, vector<int>>::iterator iter;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].X >> A[i].ID;
	}
}

bool compare(const st& a1, const st& a2) {
	if (a1.X < a2.X) { return true; }
	else { return false; }
}

int Picture(int min_index) {
	//cout << A_Map.find(min_index)->irst << endl;
	return 0;
}

int check_ID() {
	sort(A, A + N, compare);

	// make ID map
	for (int i = 0; i < N; i++)
	{
		ID_Map[A[i].ID].push_back(A[i].X);
	}
	int ID = ID_Map.size();
	return ID;
}

int check_length() {

	int N_ID = check_ID();
	int ID_count = 0;
	int* ID_visit;
	int front = 0;
	int front_ID = A[front].ID;
	int length = 0;

	// 새로운 A[i].ID를 받아서 만약에 ID count에 없으면 ID버퍼에 저장하고 카운트 올리고 다음 index로 넘어간다. 최초 ID의 X값을 저장
		// 만약 ID count에 있다면 바로 index를 올린다..
		// ID의 count 값이 N_ID와 같으면 현재 i값과 최초 ID의 x값의 차를 return

	for (int i = 0; i < N; i++)
	{
		// i번째 인풋을 받아 A[i].ID
		// front_ID와 A[i].ID를 비교해 -> 같아? 그러면 front를 하나 뒤로 미뤄 A[front+1].ID / 달라? ID_visit에 투입! ID_count를 하나 증가시켜 -> 여기서 잠깐!!!! 만약 ID_count가 N_ID랑 같다면!!! length계산하고 front를 증가시킨다. 그리고 원래있던 front를 하나 증가시킨다.
		if (front_ID == A[i].ID)
		{
			front++;
			front_ID = A[front].ID;
		}














		for (int j = 0; j < ID_count; j++)
		{
			if (A[i].ID != ID_visit[j])
			{
				
			}
		}




		if (ID_count == N_ID) // ID_count가 다 차면 길이 출력
		{
			length = i - front;
			front++;
			front_ID = A[front].ID;
		}
		else // 다 차지 않았을 때
		{
			if (A[i].ID == front_ID) // 
			{
				front++;
				front_ID = A[front].ID;
			}
		}
		

		// 새로 들어온 ID로 인해 ID_count가 N_ID와 같아지면 front와 현재 index를 뺀다
	}



	return length;

	
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	ans = check_ID();

	cout << ans << endl;	//	정답 출력
	return 0;
}
