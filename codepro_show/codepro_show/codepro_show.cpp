#include <iostream>
#include <queue>
using namespace std;

int N;//���� ��
int S;//���� ���� ��ȣ
int M;
int front = 0;
int rear = 0;
int list[10000];

void InputData() {
	cin >> N >> S >> M;
}

int front_list(){return list[front];}
void push(int x) {
	list[rear] = x;
	rear = (rear + 1) % N;
}
void pop() {
	front = (front + 1) % N;
}

void Processing() {
	// initialization
	for (int i = 0; i < N; i++)
	{
		if (S + i > N)
		{
			list[i] = S + i - N;
		}
		else
		{
			list[i] = S + i;
		}
		rear++;
	}

	// solve
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			push(front_list());
			pop();
		}
		cout << front_list() << " ";
		pop();
	}
	cout << endl;


}

int main() {

	InputData();//	�Է� �Լ�

	//	�ڵ带 �ۼ��ϼ���

	Processing();

	return 0;
}