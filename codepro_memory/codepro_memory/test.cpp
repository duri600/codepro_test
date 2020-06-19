
#include "./lib/ControlSystem.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * TemperatureSensor interface
 * 감지된 온도 변화 값을 가져올 수 있는 장치 인터페이스
 *
class TemperatureSensor
{
public:
	/**
	 * 센서가 감지한 온도 변화 값을 반환한다.
	 * @return 감지된 온도 변화 값
	 *
	virtual int getTemperatureChange() = 0;
};
*/

/**
 * 엔진 온도를 조절기를 제어하는 class (테스트 대상)
 *
 *
class EngineControlSystem
{
	TemperatureSensor& sensor_;

public:
	/**
	 * 온도제어기를 초기화
	 * @param sensor: 사용할 온도 센서 장치 드라이버
	 *
	EngineControlSystem(TemperatureSensor& sensor) : sensor_(sensor)
	{
		...
	}

	/**
	 * 테스트 대상. 일정 주기로 온도변화를 감지하고 현재 상태를 고려하여 온도조절모드를 결정한다. 그리고 누적부하량을 계산한다.
	 * @return 누적된 부하량
	 *
	int controlTemperature()
	{
		// 구현 코드는 대략 아래와 유사하다.
		tempChange = getTemperatureChange() // 측정한 온도변화  status = 온도변화에따른_현재상태

		비상모드_작동조건검사()

		if 비상모드_작동조건 then
			mode = emergencyMode;
		else if 정지모드_작동조건 then
			mode = stopMode;
		else
			mode = 현재상태에따른_온도조절모드

		부하량 = 부하량계산(mode);
		누적부하량 += 부하량

		return 누적부하량;
	}
	...
};
*/



/* [문제 1. 작성 내용] */
// 조건을 만족하는 테스트 입력을 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: {입력 개수 N, 온도변화 1, 온도변화 2, ... ,  온도변화 N}
// 예를 들어, { 7, -20, -20, -1, 3, 20, 20, 0 } 는
// 온도변화가  -20, -20, -1, 3, 20, 20, 0  순으로 측정됨을 의미한다.
int testInput_example[] = { 7, -20, -20, -1, 3, 20, 20, 0 };

//TODO: 문제1.(1-1) - 최종 누적부하량이 50이 되는 상황
int testInput_1_1[] = { 17, -20, -20, -1, 3, 20, 20, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0 /*FIXME*/ };

//TODO: 문제1.(1-2) - '현재 온도가 -20도 미만 또는 60도 초과인 경우'에 의해서 비상모드에 진입하고, 최종 누적비용이 59가 되는 상황
int testInput_1_2[] = { 16, -20, -20, -1, 3, 20, 20, 0 , -3 , -4, -5, 11, 3, -5, -3, 1, 1 /*FIXME*/ };

//TODO: 문제1.(1-3) - 비상모드를 두 번 이하로 발생시키면서 최종 누적부하량이 38 이하가 되는 상황
int testInput_1_3[] = { 0 /*FIXME*/ };



// [문제2. 테스트 코드 작성]
// NOTE: 작성한 코드가 실행된 후 메모리 누수가 발생할 경우 오답 처리됨

struct myInput : public TemperatureSensor
{
public:
	myInput(int* input) : input_(input) {}
	int getTemperatureChange() {
		return input_[count++];
	}

private:
	int* input_;
	int count = 0;

};

void test_2_1()
{
	// TODO: 항목 2-1. 
	// 온도변화 값이 순차적으로 5, -10, -5, 1, 10, 20, 15 순으로 측정되는 경우를 재현하는 코드를 작성하라.
	int key[] = {5, -10, -5, 1, 10, 20, 15};

	myInput input(key);
	EngineControlSystem ECS(input);

	for (int i = 0; i < 7; i++)
	{
		ECS.controlTemperature();
	}
}

void test_2_2()
{
	// TODO: 항목 2-2. 
	// 온도변화 값이 순차적으로 -20, -15, 5, 0, -2, -3, 10, 20, 20 순으로 측정되는 경우를 재현하는 코드를 작성하라.
	int key[] = { -20, -15, 5, 0, -2, -3, 10, 20, 20 };

	myInput input(key);
	EngineControlSystem ECS(input);

	for (int i = 0; i < 9; i++)
	{
		ECS.controlTemperature();
	}
}

// main 함수는 작성한 테스트 케이스를 실행하여 확인하는 용도로 사용한다.
// 필요에 따라서 마음대로 변경하어도 무방하다. main 함수의 내용은 채점과 무관하다.
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