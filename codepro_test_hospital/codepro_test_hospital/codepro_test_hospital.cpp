//#include <stdio.h>
//#include "./lib/HeartRateMonitor.h"
//
///* [문제 1. 작성 내용] */
//// 조건을 만족하는 테스트 입력을 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
//
//// 각 테스트 케이스의 형식: {입력 개수 N, 심장박동수 1, 심장박동수 2, ... ,  심장박동수 N}
//// 예를 들어, { 5, 82, 65, 47, 43, 49 } 는
//// 심장박동수가 82, 65, 47, 43, 49 순으로 측정됨을 의미한다.
//
///*
//모니터링 실패를 의미하는 상수
//
//#define MONITORING_FAILED    (0x80000000)
//*/
//
//// 샘플 Testcase : '[ 경고 발생 논리 예 ]'에 해당하는 테스트 입력 예
//unsigned int sampleInput[] = { 10, 82, 65, 47, 43, 49, 43, 65, MONITORING_FAILED, 70, 68 };
//
///*
//TODO: 문제1-1
//  - 최종 경고 점수가 14점이면서
//  - 50~59 혹은 80~89 구간에 해당하는 심장박동수가 감지되는 상황이 반드시 두 번 발생되며
//  - 100이상 혹은 44이하 구간에 해당하는 심장박동수가 감지되는 상황이 반드시 한 번 발생하는 상황
//*/
//unsigned int testInput_1_1[] = { 9, 51, 81, 46,101,47,61,91,MONITORING_FAILED,63};
//
///*
//TODO: 문제 1-2
//  - 최종 경고 점수가 4점이면서
//  - 경고 점수가 20점 이상이 되어 경고를 한번 이상 발생시키며, (단, 모니터링 실패가 연속 3번 이상 발생하는 경우를 만들면 안 됨)
//  - 정상 심장박동수가 연속 세번 감지되는 일이 한번 이상 발생하는 상황
//*/
//unsigned int testInput_1_2[] = { 12, MONITORING_FAILED, 51, 46, 101, 42, 46,61,62,63,64,57,61};
//
//
//// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
//// 필요한 경우 아래 주석의 내용을 참고하여 테스트 코드를 작성하시오.
///*
// * 구현 참고용이므로 본 주석을 풀어서 아래 코드를 사용해서는 안된다.  (HeartRateMonitor.h에 포함된 내용임)
// * 아래 주석을 해제하여 사용하는 경우 정상적으로 동작하지 않는다.
//
//
//
///*
// * HeartRateSensor class
// * 현재 측정된 심장박동수 값을 반환하는 인터페이스
// *
//
//class HeartRateSensor
//{
//public:
//	/*
//	 * 호출 시 현재 감지된 심장 박동수를 반환한다.
//	 * @return 현재 심장 박동수를 나타내는 정수 값. 혹은 감지 실패시 MONITORING_FAILED 반환
//	 *
//	virtual unsigned int getHeartbeat() = 0;
//};
//
//
///**
// * HeartRateMonitor class
// * 심장 박동 수 모니터링 (테스트 대상)
// *
// *
//class HeartRateMonitor
//{
//public:
//	/*
//	 * 환자 상태 경고 모듈을 초기화하는 함수
//	 * 누적경고값 등 관련 값들을 모두 초기화 한다
//	 * (해당 로직에서 사용하는 변수는 아래 생성자에서 초기화 됨을 가정한다.)
//	 *
//	HeartRateMonitor(HeartRateSensor& sensor) : sensor_(sensor) {
//		... 초기화 코드
//	}
//
//	/**
//	 * 호출될 때 마다 센서로 부터 심장 박동 수를 얻어와서 정해진 로직에 따라 '경고 점수'를 계산한다. (테스트 대상)
//	 * @return 현재 누적 계산된 '경고 점수'
//	 *
//	int calculateWarningScore()
//	{
//		// 로직 구현은 대략 아래와 같다.
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
//// [문제2. 테스트 코드 작성]
//// NOTE: 작성한 코드가 실행된 후 메모리 누수가 발생할 경우 오답 처리됨
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
//	// TODO: 문제2-1
//	// 심장 박동 수가 59 - 101 - 86 - 78 - 모니터링 실패 - 75 순으로 측정되는 경우를 재현하는 코드를 작성하라.
//	// 단, 채점 시 test_2_1()만 호출되므로, test_2_1()을 호출했을 때 필요한 테스트 동작이 모두 수행될 수 있도록 작성해야 한다.
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
//	// TODO: 문제 2-2
//	// 심장 박동 수가 67 - 75 - 61 - 모니터링 실패 - 55 - 45 - 40 - 39 - 37 순으로 측정되는 경우를 재현하는 코드를 작성하라.
//	// 단, 채점 시 test_2_2()만 호출되므로, test_2_2()을 호출했을 때 필요한 테스트 동작이 모두 수행될 수 있도록 작성해야 한다.
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
//// 아래 main 함수는 작성한 테스트 케이스를 실행하여 확인하는 용도로 사용할 수 있다. (필요에 따라서 마음대로 변경하어도 무방)
//// NOTE: main 함수의 내용은 채점시 활용되지 않으므로 동작에 꼭 필요한 코드를 main 함수에만 작성해서는 안된다.
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


