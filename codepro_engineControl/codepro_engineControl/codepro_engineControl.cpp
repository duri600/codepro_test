
#include "./lib/ControlSystem.h"

// �׽�Ʈ ����� �Ʒ� �ּ��� ���� �����Ǿ� �ִ�. 
// �ʿ��� ��� �Ʒ� �ּ��� ������ �����Ͽ� �׽�Ʈ �Է°� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�. 
// NOTE: �׽�Ʈ ��� �ڵ�� ���忡 �̹� ���ԵǾ� ������ �Ʒ� �ּ��� �����Ͽ� ������� ���ÿ�.

/**
 * TemperatureSensor interface
 * ������ �µ� ��ȭ ���� ������ �� �ִ� ��ġ �������̽�
 *
class TemperatureSensor
{
public:
	/**
	 * ������ ������ �µ� ��ȭ ���� ��ȯ�Ѵ�.
	 * @return ������ �µ� ��ȭ ��
	 *
	virtual int getTemperatureChange() = 0;
};
*/

/**
 * ���� �µ��� �����⸦ �����ϴ� class (�׽�Ʈ ���)
 *
 *
class EngineControlSystem
{
	TemperatureSensor& sensor_;

public:
	/**
	 * �µ�����⸦ �ʱ�ȭ
	 * @param sensor: ����� �µ� ���� ��ġ ����̹�
	 *
	EngineControlSystem(TemperatureSensor& sensor) : sensor_(sensor)
	{
		...
	}

	/**
	 * �׽�Ʈ ���. ���� �ֱ�� �µ���ȭ�� �����ϰ� ���� ���¸� ����Ͽ� �µ�������带 �����Ѵ�. �׸��� �������Ϸ��� ����Ѵ�.
	 * @return ������ ���Ϸ�
	 *
	int controlTemperature()
	{
		// ���� �ڵ�� �뷫 �Ʒ��� �����ϴ�.
		tempChange = getTemperatureChange() // ������ �µ���ȭ  status = �µ���ȭ������_�������

		�����_�۵����ǰ˻�()

		if �����_�۵����� then
			mode = emergencyMode;
		else if �������_�۵����� then
			mode = stopMode;
		else
			mode = ������¿�����_�µ��������

		���Ϸ� = ���Ϸ����(mode);
		�������Ϸ� += ���Ϸ�

		return �������Ϸ�;
	}
	...
};
*/



/* [���� 1. �ۼ� ����] */
// ������ �����ϴ� �׽�Ʈ �Է��� �Ʒ� �迭�� �߰��Ͻÿ�. (�迭�� �̸��� ���Ƿ� �����ϴ� ��� ä���� ���� ó����)
// �� �׽�Ʈ ���̽��� ����: {�Է� ���� N, �µ���ȭ 1, �µ���ȭ 2, ... ,  �µ���ȭ N}
// ���� ���, { 7, -20, -20, -1, 3, 20, 20, 0 } ��
// �µ���ȭ��  -20, -20, -1, 3, 20, 20, 0  ������ �������� �ǹ��Ѵ�.
int testInput_example[] = { 7, -20, -20, -1, 3, 20, 20, 0 };

//TODO: ����1.(1-1) - ���� �������Ϸ��� 50�� �Ǵ� ��Ȳ
int testInput_1_1[] = { 10, -20, -20, -1, 3, 20, 20, 0, 3,3,0};

//TODO: ����1.(1-2) - '���� �µ��� -20�� �̸� �Ǵ� 60�� �ʰ��� ���'�� ���ؼ� ����忡 �����ϰ�, ���� ��������� 59�� �Ǵ� ��Ȳ
int testInput_1_2[] = { 13, -20, -20, -1, 3, 20, 20, 0, 3,3,0 ,3,3,0};

//TODO: ����1.(1-3) - ����带 �� �� ���Ϸ� �߻���Ű�鼭 ���� �������Ϸ��� 38 ���ϰ� �Ǵ� ��Ȳ
int testInput_1_3[] = { 8,-20, -1, -1, -1, 5, 5, 20, 0 };



// [����2. �׽�Ʈ �ڵ� �ۼ�]
// NOTE: �ۼ��� �ڵ尡 ����� �� �޸� ������ �߻��� ��� ���� ó����
class my_test : public TemperatureSensor
{
public:
	my_test(int* input) : input_(input) {}
	int getTemperatureChange() {
		return input_[index++];
	}

private:
	int* input_;
	int index = 0;

};
void test_2_1()
{
	// TODO: �׸� 2-1. 
	// �µ���ȭ ���� ���������� 5, -10, -5, 1, 10, 20, 15 ������ �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
	int temp_in[] = { 5, -10, -5, 1, 10, 20, 15 };

	my_test temp_test(temp_in);
	EngineControlSystem ECS_test(temp_test);

	for (int i = 0; i < 7; i++)
	{
		ECS_test.controlTemperature();
	}

}

void test_2_2()
{
	// TODO: �׸� 2-2. 
	// �µ���ȭ ���� ���������� -20, -15, 5, 0, -2, -3, 10, 20, 20 ������ �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
	int temp_in[] = { -20, -15, 5, 0, -2, -3, 10, 20, 20 };

	my_test temp_test(temp_in);
	EngineControlSystem ECS_test(temp_test);

	for (int i = 0; i < 9; i++)
	{
		ECS_test.controlTemperature();
	}
}

// main �Լ��� �ۼ��� �׽�Ʈ ���̽��� �����Ͽ� Ȯ���ϴ� �뵵�� ����Ѵ�.
// �ʿ信 ���� ������� �����Ͼ �����ϴ�. main �Լ��� ������ ä���� �����ϴ�.
int main(void)
{
	printTestInputResult("input_example", testInput_example);
	printTestInputResult("input_1_1", testInput_1_1);
	printTestInputResult("input_1_2", testInput_1_2);
	printTestInputResult("input_1_3", testInput_1_3);

	test_2_1();

	test_2_2();

	return 0;
}