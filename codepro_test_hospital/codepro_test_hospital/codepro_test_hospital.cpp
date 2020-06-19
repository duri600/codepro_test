//#include <stdio.h>
//#include "./lib/HeartRateMonitor.h"
//
///* [���� 1. �ۼ� ����] */
//// ������ �����ϴ� �׽�Ʈ �Է��� �Ʒ� �迭�� �߰��Ͻÿ�. (�迭�� �̸��� ���Ƿ� �����ϴ� ��� ä���� ���� ó����)
//
//// �� �׽�Ʈ ���̽��� ����: {�Է� ���� N, ����ڵ��� 1, ����ڵ��� 2, ... ,  ����ڵ��� N}
//// ���� ���, { 5, 82, 65, 47, 43, 49 } ��
//// ����ڵ����� 82, 65, 47, 43, 49 ������ �������� �ǹ��Ѵ�.
//
///*
//����͸� ���и� �ǹ��ϴ� ���
//
//#define MONITORING_FAILED    (0x80000000)
//*/
//
//// ���� Testcase : '[ ��� �߻� �� �� ]'�� �ش��ϴ� �׽�Ʈ �Է� ��
//unsigned int sampleInput[] = { 10, 82, 65, 47, 43, 49, 43, 65, MONITORING_FAILED, 70, 68 };
//
///*
//TODO: ����1-1
//  - ���� ��� ������ 14���̸鼭
//  - 50~59 Ȥ�� 80~89 ������ �ش��ϴ� ����ڵ����� �����Ǵ� ��Ȳ�� �ݵ�� �� �� �߻��Ǹ�
//  - 100�̻� Ȥ�� 44���� ������ �ش��ϴ� ����ڵ����� �����Ǵ� ��Ȳ�� �ݵ�� �� �� �߻��ϴ� ��Ȳ
//*/
//unsigned int testInput_1_1[] = { 9, 51, 81, 46,101,47,61,91,MONITORING_FAILED,63};
//
///*
//TODO: ���� 1-2
//  - ���� ��� ������ 4���̸鼭
//  - ��� ������ 20�� �̻��� �Ǿ� ��� �ѹ� �̻� �߻���Ű��, (��, ����͸� ���а� ���� 3�� �̻� �߻��ϴ� ��츦 ����� �� ��)
//  - ���� ����ڵ����� ���� ���� �����Ǵ� ���� �ѹ� �̻� �߻��ϴ� ��Ȳ
//*/
//unsigned int testInput_1_2[] = { 12, MONITORING_FAILED, 51, 46, 101, 42, 46,61,62,63,64,57,61};
//
//
//// �׽�Ʈ ����� �Ʒ� �ּ��� ���� �����Ǿ� �ִ�. 
//// �ʿ��� ��� �Ʒ� �ּ��� ������ �����Ͽ� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�.
///*
// * ���� ������̹Ƿ� �� �ּ��� Ǯ� �Ʒ� �ڵ带 ����ؼ��� �ȵȴ�.  (HeartRateMonitor.h�� ���Ե� ������)
// * �Ʒ� �ּ��� �����Ͽ� ����ϴ� ��� ���������� �������� �ʴ´�.
//
//
//
///*
// * HeartRateSensor class
// * ���� ������ ����ڵ��� ���� ��ȯ�ϴ� �������̽�
// *
//
//class HeartRateSensor
//{
//public:
//	/*
//	 * ȣ�� �� ���� ������ ���� �ڵ����� ��ȯ�Ѵ�.
//	 * @return ���� ���� �ڵ����� ��Ÿ���� ���� ��. Ȥ�� ���� ���н� MONITORING_FAILED ��ȯ
//	 *
//	virtual unsigned int getHeartbeat() = 0;
//};
//
//
///**
// * HeartRateMonitor class
// * ���� �ڵ� �� ����͸� (�׽�Ʈ ���)
// *
// *
//class HeartRateMonitor
//{
//public:
//	/*
//	 * ȯ�� ���� ��� ����� �ʱ�ȭ�ϴ� �Լ�
//	 * ������� �� ���� ������ ��� �ʱ�ȭ �Ѵ�
//	 * (�ش� �������� ����ϴ� ������ �Ʒ� �����ڿ��� �ʱ�ȭ ���� �����Ѵ�.)
//	 *
//	HeartRateMonitor(HeartRateSensor& sensor) : sensor_(sensor) {
//		... �ʱ�ȭ �ڵ�
//	}
//
//	/**
//	 * ȣ��� �� ���� ������ ���� ���� �ڵ� ���� ���ͼ� ������ ������ ���� '��� ����'�� ����Ѵ�. (�׽�Ʈ ���)
//	 * @return ���� ���� ���� '��� ����'
//	 *
//	int calculateWarningScore()
//	{
//		// ���� ������ �뷫 �Ʒ��� ����.
//		heart_beat = sensor_.getHeartbeat();
//
//		if(heart_beat == MONITORING_FAILED)
//		{
//			failed_conti_cnt++;
//			if(failed_conti_cnt >= 3)
//			{
//				stable_conti_cnt = 0; warning_score = 20;
//			}
//			return warning_score;
//		}
//		else failed_conti_cnt = 0;
//
//		if(60<=heart_beat && heart_beat <= 79)
//		{
//			stable_conti_cnt++;
//			if(stable_conti_cnt>=3) stable_conti_cnt = 3;
//
//			switch(stable_conti_cnt)
//			{
//				case 1: warning_score -= 2; break;
//				case 2: warning_score -= 3; break;
//				case 3: warning_score -= 5; break;
//			}
//			if(warning_score<0) warning_score = 0;
//		}
//		else
//		{
//			stable_conti_cnt = 0;
//			if((80<=heart_beat && heart_beat <= 89) || (50<=heart_beat && heart_beat <= 59))
//				warning_score += 1;
//			else if((90<=heart_beat && heart_beat <= 99) || (45<=heart_beat && heart_beat <= 49))
//				warning_score += 3;
//			else if((100<=heart_beat) || (heart_beat <= 44))
//				warning_score += 7;
//			if(warning_score>20) warning_score = 20;
//		}
//		return warning_score;
//	}
//
//	...
//
//};
//*/
//
//
//// [����2. �׽�Ʈ �ڵ� �ۼ�]
//// NOTE: �ۼ��� �ڵ尡 ����� �� �޸� ������ �߻��� ��� ���� ó����
//class my_Test : public HeartRateSensor
//{
//public:
//	my_Test(unsigned int* input) : input_(input) {}
//
//	unsigned int getHeartbeat() {
//		return input_[count_++];
//	}
//
//private:
//	unsigned int* input_;
//	int count_ = 0;
//};
//
//void test_2_1(void)
//{
//	// TODO: ����2-1
//	// ���� �ڵ� ���� 59 - 101 - 86 - 78 - ����͸� ���� - 75 ������ �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
//	// ��, ä�� �� test_2_1()�� ȣ��ǹǷ�, test_2_1()�� ȣ������ �� �ʿ��� �׽�Ʈ ������ ��� ����� �� �ֵ��� �ۼ��ؾ� �Ѵ�.
//	unsigned int input[] = { 59,101,86,78,MONITORING_FAILED,75 };
//
//	my_Test test(input);
//	HeartRateMonitor HRM_test(test);
//
//	for (int i = 0; i < 6; i++)
//	{
//		HRM_test.calculateWarningScore();
//	}
//}
//
//
//void test_2_2(void)
//{
//	// TODO: ���� 2-2
//	// ���� �ڵ� ���� 67 - 75 - 61 - ����͸� ���� - 55 - 45 - 40 - 39 - 37 ������ �����Ǵ� ��츦 �����ϴ� �ڵ带 �ۼ��϶�.
//	// ��, ä�� �� test_2_2()�� ȣ��ǹǷ�, test_2_2()�� ȣ������ �� �ʿ��� �׽�Ʈ ������ ��� ����� �� �ֵ��� �ۼ��ؾ� �Ѵ�.
//	unsigned int input[] = { 67,75,61,MONITORING_FAILED,55,45,40,39,37 };
//
//	my_Test test(input);
//	HeartRateMonitor HRM_test(test);
//
//	for (int i = 0; i < 9; i++)
//	{
//		HRM_test.calculateWarningScore();
//	}
//}
//
//// �Ʒ� main �Լ��� �ۼ��� �׽�Ʈ ���̽��� �����Ͽ� Ȯ���ϴ� �뵵�� ����� �� �ִ�. (�ʿ信 ���� ������� �����Ͼ ����)
//// NOTE: main �Լ��� ������ ä���� Ȱ����� �����Ƿ� ���ۿ� �� �ʿ��� �ڵ带 main �Լ����� �ۼ��ؼ��� �ȵȴ�.
//int main(void)
//{
//	printTestInputResult("Sample Input", sampleInput);
//
//	printTestInputResult("Test_1_1 Input", testInput_1_1);
//	printTestInputResult("Test_1_2 Input", testInput_1_2);
//
//	test_2_1();
//	test_2_2();
//
//	return 0;
//}
#define MONITORING_FAILED 1
#include <iostream>
using namespace std;
int main(void)
{
	unsigned int input[] = { 59,101,86,78,MONITORING_FAILED,75 };
	
	cout << sizeof(input) << endl;

	cout << sizeof(input) / sizeof(int) << endl;
	return 0;
}


