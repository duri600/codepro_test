#include <iostream>

/* [문제 1. 작성 내용] */
/*
	조건을 만족하는 테스트 입력을 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)

	각 테스트 케이스의 형식: { 입력 개수 N, 이벤트 1, 이벤트 2, ... ,  이벤트 N}
	단, 입력 개수 N은 20이하이고, 이벤트 1은 반드시 고정값 4 이어야 한다.
	예를 들어, { 10, 4, 5, 6, 7, 3, -7, -6, 2, -5, -2 }는
	이벤트가 4, 5, 6, 7, 3, -7, -6, 2, -5, -2 순으로 발생함을 의미한다.
*/

/*
	이벤트가 4, 5, 6, 7, 3, -7, -6, 2, -5, -2 순으로 발생해서
	점유레벨이 5 2 2 1 1 2 2 2 3 4 순으로 변하는 테스트 입력 예
*/
int testInput_example[] = { 10, 4, 5, 6, 7, 3, -7, -6, 2, -5, -2 };


/*
TODO: 문제1-1
  - 4번 프로세스의 CPU 점유레벨 3이 연속으로 3초 이상 나오는 상황
*/
int testInput_1_1[] = { 13, 4, 5, 6, 7, 3, -7, -6, 2, -5, -2, 2,1,-2};

/*
TODO: 문제1-2
  - 4번 프로세스의 CPU 점유레벨 변화의 일부가 5, 4, 3 순으로 나오는 상황
  - 단, 값이 연속으로 동일한 경우 하나의 값으로 본다.
  - 예를 들어 4, 5, 4, 4, 4, 3, 2, 2, 1, 2 와 같이 나온 경우 연속으로 동일한 값을 제거하면 4, 5, 4, 3, 2, 1, 2 가 되며 중간에 5, 4, 3 이 존재하므로 가능한 경우이다.
*/
int testInput_1_2[] = { 13, 4, 5, 6, 7, 3, -7, -6, 2, -5, -2, -3, 3, 2 };
/*
TODO: 문제1-3
  - 4번 프로세스의 CPU 점유레벨 변화의 일부가 3, 4, 5 순으로 나오는 상황
  - (1-2)와 마찬가지로 값이 연속으로 동일한 경우 하나의 값으로 처리해야 한다.
*/
int testInput_1_3[] = {11,  4, 5, 6, 7, 3, -7, -6, 2, -5, -2, -3 };


#include "./lib/Scheduler.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 코드를 작성하시오.
/*
 * 구현 참고용이므로 본 주석을 풀어서 아래 코드를 사용해서는 안된다.  (Scheduler.h에 포함된 내용임)
 * 아래 주석을 해제하여 사용하는 경우 정상적으로 동작하지 않는다.

/*
 * EventHelper class
 * 프로세스 실행과 종료 등의 이벤트 정보를 얻을 수 있는 인터페이스
 *

class EventHelper
{
public:
	/*
	 * 호출 시 최근에 발생한 이벤트를 반환한다.
	 * @return 발생한 프로세스 이벤트를 표현하는 값
	 *
	virtual int getProcessEvent() = 0;
};


/**
 * Scheduler class
 * 프로세스 스케줄링을 담당하는 모듈 (테스트 대상)
 *
class Scheduler
{
public:
	/*
	 * 프로세스 스케줄러 모듈을 초기화
	 * 프로세스 상태 등 관련 값들을 모두 초기화 한다
	 * (해당 로직에서 사용하는 변수는 아래 생성자에서 초기화 됨을 가정한다.)
	 *
	Scheduler(EventHelper& helper) : helper_(helper) {
		... 초기화 코드
	}

	/**
	 * 현재 수행해야 하는 이벤트에 따라 해당 프로세스를 실행 또는 종료시키고, 4번 프로세스의 CPU 점유율과 점유레벨을 계산한다. (테스트 대상)
	 * @return 처리에 성공하면 true, 예외 조건으로 실패하면 false
	 *
	bool operateScheduler()
	{
		event = helper_.getProcessEvent() // 발생한 이벤트

		첫 이벤트가 4가 아니면 에러를 리턴

		if 이벤트가_음수 then
			프로세스 번호 = 이벤트의 절대값
			현재 동일한 번호의 프로세스가 없을 시 에러를 리턴
			해당 번호의 프로세스 종료
		else
			프로세스 번호 = 이벤트값
			현재 동일한 번호의 프로세스가 있을 시 에러를 리턴
			해당 번호의 프로세스 실행

		ratio = 4번 프로세스의 CPU 점유율을 계산
		level = 4번 프로세스의 CPU 점유레벨을 계산

		이벤트에 따라 변경되는 level을 계산하여 상태 기록
	}

	...

};
*/




// [문제2. 테스트 코드 작성]
// NOTE: 작성한 코드가 실행된 후 메모리 누수가 발생할 경우 오답 처리됨
struct myTest : public EventHelper
{
public:
	myTest(int* input) : input_(input){}

	int getProcessEvent() {
		return input_[count++];
	}
private:
	int* input_;
	int count = 0;
};

void test_2_1()
{
	// TODO: 항목 2-1. 
	// 이벤트가 순차적으로 4, 5, 6, 3, 2, -5, -6, -3, -2 순으로 발생하는 경우를 재현하는 코드를 작성하라.
	// 단, 채점 시 test_2_1()만 호출되므로, test_2_1()을 호출했을 때 필요한 테스트 동작이 모두 수행될 수 있도록 작성해야 한다.
	int key[] = { 4, 5, 6, 3, 2, -5, -6, -3, -2 };

	myTest input(key);
	Scheduler Schedule(input);

	for (int i = 0; i < 9; i++)
	{
		Schedule.operateScheduler();
	}

}

void test_2_2()
{
	// TODO: 항목 2-2. 
	// 이벤트가 순차적으로 4, 3, 2, -2, 5, -5, 6, 7, -7, -3, -6 순으로 발생하는 경우를 재현하는 코드를 작성하라.
	// 단, 채점 시 test_2_2()만 호출되므로, test_2_2()을 호출했을 때 필요한 테스트 동작이 모두 수행될 수 있도록 작성해야 한다.
	int key[] = { 4, 3, 2, -2, 5, -5, 6, 7, -7, -3, -6 };

	myTest input(key);
	Scheduler Schedule(input);

	for (int i = 0; i < 11; i++)
	{
		Schedule.operateScheduler();
	}
}




// 아래 main 함수는 작성한 테스트 케이스를 실행하여 확인하는 용도로 사용할 수 있다. (필요에 따라서 마음대로 변경하어도 무방)
// NOTE: main 함수의 내용은 채점시 활용되지 않으므로 동작에 꼭 필요한 코드를 main 함수에만 작성해서는 안된다.
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