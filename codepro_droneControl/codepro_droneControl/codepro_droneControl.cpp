#include <stdio.h>
#include "./lib/DroneController.h"


POS sensorTable[8] = { { 0,0 },{ 1,10 },{ 2,6 },{ 4,1 },{ 5,5 },{ 6,10 },{ 7,8 },{ 8,2 } };

/**
* drone.h���� �뷫������ �Ʒ��� ���� ������ �Լ��� ���ǰ� �ִ�.
* ���� ������̹Ƿ� �� �ּ��� Ǯ� �Ʒ� �ڵ带 ����ؼ��� �ȵȴ�. (drone.h�� ���Ե� ������)
* �Ʒ� �ּ��� �����Ͽ� ����ϴ� ��� ���������� �������� �ʴ´�.
*/

/**
 * (y, x) ��ǥ�� ǥ���ϴ� �ڷᱸ��
 *
typedef struct pos {
	int y;
	int x;
} POS;

/**
 * ȭ�� ���� ���� �������̽�
 *
class FireSensor
{
public:
	/**
	 * ���� ȭ�縦 ������ ������ ��ġ ���� ��ȯ
	 * @return POS Ÿ���� (y, x) ��ǥ. ���� ���, 1�� �������� ȭ�縦 ������ ��� {1, 10}�� ��ȯ
	 *
	virtual POS getSensorPosition() = 0;
};

/**
 * ��� ���� �ý��� (�׽�Ʈ ���)
 *
class DroneController
{
	POS currentDrone1_ = { 0,0 };
	POS currentDrone2_ = { 10,10 };

	FireSensor* sensor_;
	...
public:
	DroneController(FireSensor* sensor) : sensor_(sensor) { ... }

	/**
	 * ȭ�簡 �߻��� ��ġ�� ���ͼ� ���� ��а��� ��ġ�� ����Ͽ� ���� ����� ����� �����ϴ� �Լ� (�׽�Ʈ ���)
	 * ���� ��ġ ����� ���� ���õ� ����� ��ġ�� �����صд�. (���õ� ����� �ش� ��ǥ�� �̵����� ����)
	 * @return ȭ�簡 �߻��� ���� ���� ����� ����� ��ȣ. 1 Ȥ�� 2
	 *
	int selectDrone()
	{
		POS sensed = sensor_->getSensorPosition();  // ȭ���� ������ ������ ��ġ ȹ��

		int dx = currentDrone1_.x - sensed.x;
		int dy = currentDrone1_.y - sensed.y;
		int dist1 = dx*dx + dy*dy;

		dx = currentDrone2_.x - sensed.x;
		dy = currentDrone2_.y - sensed.y;
		int dist2 = dx*dx + dy*dy;

		if (dist2 >= dist1)
		{
			currentDrone1_ = sensed;
			return 1;
		}
		else
		{
			currentDrone2_ = sensed;
			return 2;
		}
	}
	...
}
*/

// ����1.	
// ���� �迭�� Format - ȭ�簨�� ������ȣ�� �־��� ������� ���� �Ǿ��� ��, �⵿�ϴ� ����� ��ȣ�� ������� ���
// ���� ���, ����� 1, 1, 2, 2, 1 ������ �⵿�Ѵٸ� { 1, 1, 2, 2, 1 }�� ���

int expectedResult_1_1[5] = { 2, 2, 2, 1, 1 };  //TODO: ���� (1-1) 1, 2, 5, 3, 7 ������ ���� ����
int expectedResult_1_2[5] = { 1, 2, 2, 1, 1 };  //TODO: ���� (1-2) 7, 6, 5, 4, 3 ������ ���� ����

// ���� 2.
// �� ������ �ش��ϴ� TC�� ����
// TC�迭�� Format : �־��� ������� ����� ���忡 �湮�� �ϱ� ���� ���� �Ǿ� �ϴ� ȭ�缾���� ��ȣ�� ������� ���
// ��) 2, 2, 1, 2, 2�� ������ ����� ���忡 �湮�ϱ� ���ؼ��� 1,2,3,4,5������ ������ �����Ǿ�� �ϹǷ� {1, 2, 3, 4, 5} ����
int testInput_example[5] = { 1, 2, 3, 4, 5 };

int testInput_2_1[5] = { 3, 7, 4, 2, 1 }; //TODO: ���� (2-1) 1, 1, 1, 1, 1 => 1�� ��и� �⵿�ϴ� ���
int testInput_2_2[5] = { 5, 6, 4, 2, 1}; //TODO: ���� (2-2) 2, 2, 2, 2, 2 => 2�� ��и� �⵿�ϴ� ���
int testInput_2_3[5] = { 3, 7, 6, 5, 4}; //TODO: ���� (2-3) 1, 1, 2, 2, 1 => 1, 2�� ���� �⵿�ϴ� ���
int testInput_2_4[5] = { 2, 5, 6, 3, 1}; //TODO: ���� (2-4) 1, 2, 2, 1, 2 => 1, 2�� ���� �⵿�ϴ� ���


// ���� 3. �׽�Ʈ �ڵ� �ۼ�
class test_drone : public FireSensor
{
public:
	test_drone(int* Input) : input_(Input) {}
	POS getSensorPosition() {
		return sensorTable[input_[count++]];
	}

private:
	int* input_;
	int count = 0;
};

void test_3_1()
{
	// TODO: �׸� 3-1. 
	// ȭ�� ��ġ�� ���� 1, 7, 2, 3, 5 ������ �����Ǵ� ��Ȳ�� �����ϴ� �׽�Ʈ �ڵ�
	int sensor_loc[] = { 1,7,2,3,5 };

	test_drone test(sensor_loc);
	DroneController control(&test);

	for (int i = 0; i < 5; i++)
	{
		control.selectDrone();
	}
}

void test_3_2()
{
	// TODO: �׸� 3-2. 
	// ȭ�� ��ġ�� ���� 3, 1, 4, 6, 2 ������ �����Ǵ� ��Ȳ�� �����ϴ� �׽�Ʈ �ڵ�
	int sensor_loc[] = { 3,1,4,6,2 };

	test_drone test(sensor_loc);
	DroneController control(&test);

	for (int i = 0; i < 5; i++)
	{
		control.selectDrone();
	}
}

// ��������� �����ϰ� ���� �ڵ尡 �ִٸ� �Ʒ� main()�� �ۼ��Ͽ� Ȱ���� �� �ִ�.
// main �Լ��� �ڵ�� ä���� ������ ����.
int main()
{
	printInputResult("example", testInput_example);
	printInputResult("2-1", testInput_2_1);
	printInputResult("2-2", testInput_2_2);
	printInputResult("2-3", testInput_2_3);
	printInputResult("2-4", testInput_2_4);

	return 0;
}
