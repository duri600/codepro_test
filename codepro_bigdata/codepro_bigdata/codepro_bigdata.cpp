#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;					//	모델명의 개수
char str[10010][21];	//	모델명 저장
int call_cnt[10010];	// same string counter
int call_ind[10010][10010];	// same string index
vector<vector<int>> call_ind_v(10010);

void Solve() {
	int unique = 1;

	for (int i = 0; i < N - 1; i++)
	{
		if (str[i][0] == 0)continue;
		call_cnt[i] = 1;
		call_ind_v[i].push_back(i);

		for (int j = i + 1; j < N; j++)
		{
			if (str[j][0] == 0)continue;
			if (strcmp(str[i],str[j]) == 0) // 같은 문자열이 나왔을 경우
			{
				str[j][0] = 0;
				call_cnt[i]++;
				call_ind_v[i].push_back(j);
				unique = 0;
			}
		}
	}

	if (unique == 1)
		cout << "unique" << endl;
	else
	{
		int max_cnt = 1;
		for (int i = 0; i < N / 2; i += max_cnt)
		{
			max_cnt = 1;
			int max_ind = 0;
			for (int k = 0; k < N; k++)
			{
				if (max_cnt < call_cnt[k])
				{
					max_cnt = call_cnt[k];
					max_ind = k;
					call_cnt[k] = 0;
				}
			}

			cout << str[max_ind] << " ";
			for (auto n : call_ind_v[max_ind]) 
			{
				cout << n + 1 << " ";
			}
			cout << endl;
		}
	}
}

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
}

int main() {

	InputData();		//	입력 함수

	Solve();			//	문제 풀이

	return 0;
}