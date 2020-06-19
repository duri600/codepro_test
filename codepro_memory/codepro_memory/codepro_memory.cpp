#include <cstdio>
#include <cstring>
#include <locale>
#include <vector>
#include "lib/MemoryAllocator.h"

// �׽�Ʈ ����� �Ʒ� �ּ��� ���� �����Ǿ� �ִ�. 
// �ʿ��� ��� �Ʒ� �ּ��� ������ �����Ͽ� �׽�Ʈ ���̽� �Է°� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�. 
// NOTE: �׽�Ʈ ��� �ڵ�� ���忡 �̹� ���ԵǾ� ������ �Ʒ� �ּ��� �����Ͽ� ������� ���ÿ�.

/**
 * ��� ����
 *
#define MAX_REQ_LIMIT	(50)
#define MEMORY_SIZE		(20)
*/

/**
 * Communicator class
 * �Էµ� ��û�� �������� ����� ������ �� �ִ� �������̽�
 *
 *
class Communicator
{
public:
	/**
	 * ȣ���� �� ���� �޽��� ť�� �ִ� ��û�� �ϳ� ������ ��û ���� �޾ƿ´�.
	 * @return ���� ��û ��
	 *
	virtual int getReqInput() = 0;

	/**
	 * ó�� ����� �����Ѵ�.
	 * @param result ������ ��
	 *
	virtual void send(int result) = 0;
};

*/


/*
 * [�׽�Ʈ ���] �޸� �Ҵ� ���
 *
class MemoryAllocator {
public:
	/**
	 * �޸𸮸� �Ҵ��ϰ� �ݳ��ϴ� ����� �ʱ�ȭ
	 *
	 * @param io �Ҵ�/���� ��û�� �ް� ����� �����ϴ� ��� �������̽�
	 *
	MemoryAllocator(Communicator& io) : io_(io) {	}

	/**
	 * ��û�� �����ͼ� �޸� �Ҵ�/���� ó���� �� ����, ����� �����Ѵ�.
	 *
	void processRequest() {
		int command = io_.getReqInput();

		int size = abs(command  % 10);
		int id = abs(command / 10);

		int result;
		if (command < 0)
			result = deallocate(id, size);
		else
			result = allocate(id, size);

		io_.send(result);
	}
private:

	/**
	 * �Ҵ��� �޸𸮸� ã�Ƽ� ��ȯ�� ũ�⸸ŭ �����Ѵ�.
	 * @param id �Ҵ��� �޸� id
	 * @param size ��ȯ�� ũ��
	 *
	int deallocate(int id, int size) {
		int position = findSpaceById(id);  // id�� �Ҵ�� �޸� ���� ��ġ ��ȯ

		for (int i = 0; i < size; ++i)
			memoryBlock[position+i] = 0;

		totalAllocated  -= size;
		return 0;
	}

	/**
	 * ũ�� ��ŭ ���������� �����ִ� �޸𸮸� �Ҵ��Ѵ�.
	 * @param id �Ҵ��� �޸� id
	 * @param size �Ҵ��� ũ��
	 * @return �Ҵ翡 �����ϴ� ��� �����ϴ� ��ġ, ������ ��� -1
	 *
	int allocate(int id, int size) {
		int firstFreePosition = findFirstFreeSpace(size);  // size��ŭ ���������� �����ִ� ������ ù ��ġ�� ��ȯ, ������ ��� -1
		if (firstFreePosition < 0)
			return FAILED;

		for (int i = 0; i < size; ++i)
			memoryBlock[firstFreePosition+i] = id;

		totalAllocated += size;

		return firstFreePosition;
	}

	...

	Communicator& io_;
	int memoryBlock[20] = {0, };
	int totalAllocated = 0;
}
*/



/* [���� 1. �ۼ� ����] */
// �׽�Ʈ ���̽��� �Ʒ� �迭�� �߰��Ͻÿ�. (�迭�� �̸��� ���Ƿ� �����ϴ� ��� ä���� ���� ó����)
// �� �׽�Ʈ ���̽��� ����: { �Է� ����, �Է� ��û �� 1, �Է� ��û �� 2, ... , �Է� ��û �� N }

// �׽�Ʈ ���̽� ��) �Է� ��û���� 14, 38, -14, 22, 43, 16 ������ ���� ���
int sampleInput_keys[MAX_REQ_LIMIT + 1] = { 6, 14, 38, -14, 22, 43, 16 };

int test_1_1_keys[MAX_REQ_LIMIT + 1] = { 6, 14, 38, -14, 22, 43, 16 };  //TODO: ����1.(1-1) - ���� ���� �뷮�� 10KB�� �Ǵ� ��Ȳ
int test_1_2_keys[MAX_REQ_LIMIT + 1] = { 6, 14, 38, -14, 22, 43, 16 };  //TODO: ����1.(1-2) - ���� ���� �뷮�� 6KB������ �������� 4KB�� ������ ���� ��Ȳ


// [����2. �ۼ� ����]
// ���ϴ� ��û ���� ������ �� �ֵ��� fake/stub�� �����Ͽ� ���õ� ��Ȳ�� �����ϴ� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�.
// NOTE: ��� �ڵ� ���� �� �޸� ������ �߻��ϸ� ���� ó����
struct myFake : public Communicator
{
	myFake(int* test_input) : test_input_(test_input) {}

	int getReqInput() {
		return test_input_[count++];
	}

	void send(int result) {

	}

private:
	int* test_input_;
	int count = 0;
};


void test_2_1(void)
{
	// TODO: // ����2.(2-1)
	// ��û ���� �Է��� ������ ������� �߻��ϴ� ��Ȳ: 12 -> 24 -> 38 -> -38 -> -12
	int key[] = { 12,24,38,-38,-12 };

	myFake input(key);
	MemoryAllocator MA(input);

	for (int i = 0; i < 5; i++)
	{
		MA.processRequest();
	}
}

void test_2_2(void)
{
	// TODO: ����2.(2-2) 
	// ��û ���� �Է��� ������ ������� �߻��ϴ� ��Ȳ: 18 -> 21 -> -18 -> 33 -> 41 -> -33
	int key[] = { 18,21,-18,33,41,-33 };

	myFake input(key);
	MemoryAllocator MA(input);

	for (int i = 0; i < 6; i++)
	{
		MA.processRequest();
	}
}

// ������ ���� ���ǵ� TestCase�� �Է� �޾Ƽ� 
// �ش� input���� ��û���� �߻��ϴ� ��Ȳ�� �����ϰ�, ���������� ���۵Ǵ� �����  expected�� ���Ͽ� �����ϴ� �ڵ带 �����϶�.
// ��, expected�� ������ Ȯ���ϴ� verify API�� �ݵ�� �Ʒ��� API�� �̿��ϵ��� �Ѵ�.

//void assertEquals(int expected, int actual);
int test_out = 0;



void test_2_3(std::vector<int> inputReqs, int expected) {
	// TODO: ���� 2-3
	struct myInput : public Communicator
	{
		myInput(std::vector<int>& inputReqs_) {
			k = inputReqs_.begin();
		}

		int getReqInput() {
			return *k++;
		}

		void send(int result) {
			test_out = result;
		}

	private:
		std::vector<int>::iterator k;
	};

	myInput input(inputReqs);
	MemoryAllocator MA(input);

	for (auto key : inputReqs) {
		MA.processRequest();
	}

	//assertEquals(expected, send�� ���� ���޵Ǵ� �� �� ������ ��);
	assertEquals(expected, test_out);

}


/* [���� 3. �ۼ� ����] */
// ��� �䱸���� ��� ó���� �� ���� ��� ���� ��Ȳ�� �ĺ��ؼ� �ش� ��Ȳ�� ǥ���ϴ� �׽�Ʈ ���̽��� �Ʒ� �迭�� �߰��Ͻÿ�. (�迭�� �̸��� ���Ƿ� �����ϴ� ��� ä���� ���� ó����)
// ���õ� ���Ŀ� ���� �ʴ� �Է��� ���ٰ� �����ϰ�, 
// ������ �������� 1���� �����Ͽ� �߰��Ѵ�.

/* �׽�Ʈ ���̽��� ����:
{
	�׽�Ʈ ���̽� ��,
	{
		{ �Է� ����, �Է� ��û �� 1, �Է� ��û �� 2, ..., �Է� ��û �� N },
		...
		{ �Է� ����, �Է� ��û �� 1, �Է� ��û �� 2, ..., �Է� ��û �� N },
	}
};
*/

typedef int InputSequence[MAX_REQ_LIMIT];

struct ExceptionalCases {
	int numberOfCases;
	InputSequence inputKeys[10];
};


// TODO: ���� 3
ExceptionalCases test_3_cases = {

	1, /* FIXME */
	{
		{ 0,  /* FIXME */},
		/* FIXME */
	}
};


// ��������� �����ϰ� ���� �ڵ尡 �ִٸ� �Ʒ� main()�� �ۼ��Ͽ� Ȱ���� �� �ִ�.
// main �Լ��� �ڵ�� ä���� ������ ����.
int main()
{
	printTestInputResult("Sample Input", sampleInput_keys);
	printTestInputResult("Test_1_1 Input", test_1_1_keys);
	printTestInputResult("Test_1_2 Input", test_1_2_keys);

	test_2_1();
	test_2_2();

	return 0;
}