#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int N;//��ǰ ��
struct st {
	int X, ID;//��ġ, ���̵�
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

	// ���ο� A[i].ID�� �޾Ƽ� ���࿡ ID count�� ������ ID���ۿ� �����ϰ� ī��Ʈ �ø��� ���� index�� �Ѿ��. ���� ID�� X���� ����
		// ���� ID count�� �ִٸ� �ٷ� index�� �ø���..
		// ID�� count ���� N_ID�� ������ ���� i���� ���� ID�� x���� ���� return

	for (int i = 0; i < N; i++)
	{
		// i��° ��ǲ�� �޾� A[i].ID
		// front_ID�� A[i].ID�� ���� -> ����? �׷��� front�� �ϳ� �ڷ� �̷� A[front+1].ID / �޶�? ID_visit�� ����! ID_count�� �ϳ� �������� -> ���⼭ ���!!!! ���� ID_count�� N_ID�� ���ٸ�!!! length����ϰ� front�� ������Ų��. �׸��� �����ִ� front�� �ϳ� ������Ų��.
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




		if (ID_count == N_ID) // ID_count�� �� ���� ���� ���
		{
			length = i - front;
			front++;
			front_ID = A[front].ID;
		}
		else // �� ���� �ʾ��� ��
		{
			if (A[i].ID == front_ID) // 
			{
				front++;
				front_ID = A[front].ID;
			}
		}
		

		// ���� ���� ID�� ���� ID_count�� N_ID�� �������� front�� ���� index�� ����
	}



	return length;

	
}

int main() {
	int ans = -1;

	InputData();			//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	ans = check_ID();

	cout << ans << endl;	//	���� ���
	return 0;
}
