#include <iostream>
using namespace std;

int N;//���簢�� ���� ũ��
int X, Y;//������ ���޵Ǵ� ���� ��ǥ, ����, ����
int map[20][20];//���� ����
int pipe;//������ ��
int visit[20][20];

//Up Down Left Right
int pipe_case[12][4] = { {0,0,0,0},{0,0,1,1},{1,1,0,0},{0,1,0,1},{0,1,1,0},{1,0,1,0},
				{1,0,0,1},{1,1,0,1},{0,1,1,1},{1,1,1,0},{1,0,1,1},{1,1,1,1} };
int r_rot[4] = { -1,1,0,0 };
int c_rot[4] = { 0,0,-1,1 };
int next_pipe[] = { 1,0,3,2 };

void Input_Data(void) {
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}

void Pipe_search(int row, int col) {
	visit[row][col] = 1;
	pipe--;
	for (int rot = 0; rot < 4; rot++)
	{
		int next_r = row + r_rot[rot];
		int next_c = col + c_rot[rot];
		if ((next_r < 0) || (next_c < 0) || (next_r > N) || (next_c > N))continue;
		if (visit[next_r][next_c] == 1)continue;
		if ((pipe_case[map[row][col]][rot] == 1) && pipe_case[map[next_r][next_c]][next_pipe[rot]] == 1)
		{
			Pipe_search(next_r, next_c);
		}
	}
	
}

int new_town()
{
	pipe = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 0) pipe++;
		}
	}

	Pipe_search(Y, X);
	return pipe;
}

int main() {
	int ans = -1;
	Input_Data();		//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���
	ans = new_town();

	cout << ans << endl;	//	���� ���
	return 0;
}
