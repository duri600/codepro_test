#include <cstdio>
#include <cstring>
#include <locale>
#include <vector>
#include "./lib/LabelPrinter.h"

// �׽�Ʈ ����� �Ʒ� �ּ��� ���� �����Ǿ� �ִ�. 
// �ʿ��� ��� �Ʒ� �ּ��� ������ �����Ͽ� �׽�Ʈ �Է°� �׽�Ʈ �ڵ带 �ۼ��Ͻÿ�. 
// NOTE: �׽�Ʈ ��� �ڵ�� ���忡 �̹� ���ԵǾ� ������ �Ʒ� �ּ��� �����Ͽ� ������� ���ÿ�.

/**
 * Input class
 * �Էµ� Ű ������ ������ �� �ִ� ��ġ �������̽�
 *
class Input
{
public:
	/**
	 * �Էµ� Ű ������ ������ �� �ִ� ��ġ �������̽�
	 * @return �Էµ� Ű ���� ȣ�� �� �� ���� �ϳ� �� ��ȯ
	 *
	virtual char getKeyInput() = 0;
};
*/

/**
 * LCD�� Ŀ���� ���ڸ� ǥ���ϴ� �������̽�
 *
 * @param buffer ����� ���ڰ� �ִ� ���� ��ġ. ������ �ּҺ��� 15�ڸ� �о LCD�� ǥ���Ѵ�. (������ ��ȿ�� ���� �ʿ�)
 * @param cursurPosition Ŀ���� ǥ���� ��ġ. 0�� ��� ���� ����, 15�� ��� ���� ������ ��迡 Ŀ���� ǥ���Ѵ�. -1�� ��쿡�� LCD�� Ŀ���� ǥ������ �ʴ´�.

void writeLcd(char* buffer, int cursurPosition);
*/

/**
 * LabelPrinter class
 * �� �����͸� ���� (�׽�Ʈ ���)
 *
class LabelPrinter
{
public:
	/**
	 * �� �����͸� �����ϴ� ����� �ʱ�ȭ
	 * ���� LCD�� �Է� ���� ���� �ʱ�ȭ�ϴ� ������ ���ԵǾ� �ִ�.
	 *
	LabelPrinter(Input& inputDevice) : input_(inputDevice) {}

	/**
	 * �׽�Ʈ ����� �� ������ �������� �Է��� ó���ϰ� ����� LCD�� ����Ѵ�.
	 *
	void processInput()
	{
		char key = input_.getKeyInput();

		switch (key)
		{
		case KEY_LEFT:
			--cursorPos_;
			break;
		case KEY_RIGHT:
			if (!isalpha(displayBuffer_[cursorPos_]))
				break;
			++cursorPos_;
			break;
		case KEY_BACKSPACE:
			for (int i = cursorPos_; i <= strlen(displayBuffer_); ++i)
				displayBuffer_[i-1] = displayBuffer_[i];
			--cursorPos_;
			break;
		default:
			for (int i = strlen(displayBuffer_); i >= cursorPos_; --i)
				displayBuffer_[i+1] = displayBuffer_[i];
			displayBuffer_[cursorPos_] = key;
			++cursorPos_;
			break;
		}

		writeLcd(displayBuffer_, cursorPos_);
	}

private:
	Input& input_;
	char displayBuffer_[16] = { 0, };
	int cursorPos_ = 0;
};
*/

/*
�Է� Ű�� ������ �� ����� ���.

#define KEY_LEFT    '1'
#define KEY_RIGHT   '2'
#deifne KEY_DELETE  '3'
*/

/* [���� 1. �ۼ� ����] */
// �׽�Ʈ ���̽��� �Ʒ� �迭�� �߰��Ͻÿ�. (�迭�� �̸��� ���Ƿ� �����ϴ� ��� ä���� ���� ó����)
// �� �׽�Ʈ ���̽��� ����: { �Է� ����, �Է� Ű1, �Է� Ű2, ... , �Է� Ű N }

// ���� Testcase : ������ '[ Ű �Է� ������ �� ]' �� �׽�Ʈ �ϱ� ���� ����
// �� �����Ϳ� �Է��� Ű ���� �ǹ� (ù��° ��Ҵ� �� �����Ϳ� �Է��� Ű ���� ����)
char sampleInput_keys[MAX_KEY_LIMIT + 1] = { 10,'A','B',KEY_LEFT,'X',KEY_RIGHT,KEY_BACKSPACE,KEY_RIGHT,KEY_LEFT,KEY_LEFT,KEY_BACKSPACE };

//TODO: (����1-1) - ���� ����� : ABCDEF
char test_1_1_keys[MAX_KEY_LIMIT + 1] = { 11, 'A', 'B', 'C', 'D' ,'E','F','G',KEY_BACKSPACE, KEY_LEFT,KEY_RIGHT,KEY_RIGHT};

//TODO: (����1-2) - �ʱ� ���� : ABCD, Ŀ�� ��ġ : B�� C ����, ���� ����� : PABDOEL
char test_1_2_keys[MAX_KEY_LIMIT + 1] = { 12, KEY_LEFT, KEY_LEFT,'P',KEY_RIGHT,KEY_RIGHT ,KEY_RIGHT,KEY_BACKSPACE,KEY_RIGHT ,'O','E','L',KEY_RIGHT};

//TODO: (����1-3) - �ʱ� ���� : OOER, Ŀ�� ��ġ : W�� E ����, ���� ����� : OOEOL , ���� Ŀ�� ��ġ : ����° ���� 'E'�� �׹��� ����'O' ����
char test_1_3_keys[MAX_KEY_LIMIT + 1] = { 14, KEY_BACKSPACE, KEY_LEFT,KEY_BACKSPACE,'O',KEY_RIGHT,KEY_RIGHT ,KEY_RIGHT,KEY_RIGHT,KEY_BACKSPACE,'O','L',KEY_LEFT,KEY_LEFT};


/* [���� 2. �ۼ� ����] */
// NOTE: ��� �ڵ� ���� �� �޸� ������ �߻��ϸ� ���� ó����

class test_Input : public Input
{
public:
	test_Input(char* seq_input) : input_(seq_input) {}

	char getKeyInput() {
		return input_[index++];
	}

private:
	char* input_;
	int index = 0;
};

void test_2_1(void)
{
	// TODO: (����2-1)
	// Ű �Է��� ������ ������� �߻��ϴ� ��Ȳ - ('A' ������ Ű) -(���� Ŀ�� �̵�Ű) -('P' ������ Ű) -(���� Ű)
	char seq_in[] = { 'A',KEY_LEFT,'P',KEY_BACKSPACE };

	test_Input input(seq_in);
	LabelPrinter print(input);

	for (int i = 0; i < sizeof(seq_in); i++)
	{
		print.processInput();
	}
}

void test_2_2(void)
{
	// TODO: (����2-2) 
	// Ű �Է��� ������ ������� �߻��ϴ� ��Ȳ - ('L' ������ Ű) -('O' ������ Ű) - (���� Ŀ�� �̵�Ű) -(���� Ű) -(������ Ŀ�� �̵�Ű) -('X'������ Ű)
	char seq_in[] = { 'L','O',KEY_LEFT,KEY_BACKSPACE,KEY_RIGHT,'X' };

	test_Input input(seq_in);
	LabelPrinter print(input);

	for (int i = 0; i < sizeof(seq_in); i++)
	{
		print.processInput();
	}
}


// (����2-3) ������ ���� ���ǵ� TestCase�� �Է� �޾Ƽ� 
// �ش� input���� Ű �Է��� �߻��ϴ� ��Ȳ�� �����ϰ�, Ű �Է��� ���� �� LCD�� ǥ�õǴ� ����� expected�� ���Ͽ� �����ϴ� �ڵ带 �����϶�.
// ��, expected�� ������ Ȯ���ϴ� verify API�� �ݵ�� �Ʒ��� API�� �̿��ϵ��� �Ѵ�.

//void assertEquals(const char* expected, const char* actual);

const char* key_dummy = "";
/**
 * LCD�� Ŀ���� ���ڸ� ǥ���ϴ� �������̽� writeLcd�� �ش��ϴ� dummy
 */
void writeLcd(const char* buffer, int cursurPosition)
{
	// TODO: (����2-3) �ʿ��� test-double spy�� ���������� LabelPrinter�� ����� ������ �� ����
	key_dummy = buffer;
}


using KeySequence = std::vector<char>;
/**
 * @param {KeySequence} inputKeys: processInput()�� �Էµ� Ű����
 * @param {string} expected: �Է�(inputKeys)�� ����, processInput()�� ���� ��� ���ڿ�
 */
void test_2_new(const KeySequence& inputKeys, const std::string& expected)
{
	// TODO: (����2-3)
	// �־��� Input(inputKeys)������ LabelPrinter�� ���۽�Ű��, �� ����� �־��� ���� �����(expected)�� �����ϴ� �׽�Ʈ �ڵ带 �ۼ��϶�.
	class test_Input_new : public Input
	{
	public:
		test_Input_new(decltype(inputKeys) new_test) {
			k = new_test.begin();
		}

		char getKeyInput() {
			return *k++;
		}

	private:
		KeySequence::const_iterator k;
	};

	test_Input_new Input(inputKeys);
	LabelPrinter print(Input);
	for (auto n : inputKeys)
	{
		print.processInput();
	}

	// ���� ����� ������ ���� �Լ�(assertEquals)�� ���� ���� �� �� �ִ�.
	// assertEquals(expected, actualResult);
	assertEquals(expected.c_str(), key_dummy);
	key_dummy = "";
}




/* [���� 3. �ۼ� ����] */
// ��� �䱸���� ��� ó���� �� ���� ��� ���� ��Ȳ�� ǥ���ϴ� �׽�Ʈ ���̽��� �Ʒ� �迭�� �߰��Ͻÿ�. (�迭�� �̸��� ���Ƿ� �����ϴ� ��� ä���� ���� ó����)
/* �׽�Ʈ ���̽��� ����:
{
	�׽�Ʈ ���̽� ��,
	{
		{ �Է� ����, �Է� Ű1, �Է� Ű2, ..., �Է� Ű N },
		...
		{ �Է� ����, �Է� Ű1, �Է� Ű2, ..., �Է� Ű N }
	}
};
*/

typedef char InputSequence[MAX_KEY_LIMIT];


struct ExceptionalCases {
	int numberOfCases;
	InputSequence inputKeys[10];
};


// TODO: (����3)
ExceptionalCases test_3_cases = {
	3, /* FIXME */
	{
		{1, KEY_LEFT/* FIXME */}, {1,KEY_BACKSPACE}, {16,'a','b','c','d','a','b','c','d','a','b','c','d','a','b','c','d'}
		/* FIXME */
	}
};


/* [���� 4. �ۼ� ����] */
/**
 * LCD �� �ٿ� Ŀ���� ���ڸ� ǥ���ϴ� �������̽�
 *
 * @line ����� �� ��ġ. 0�̸� ���� ����, 1�̸� �ι�° �ٿ� ����Ѵ�.
 * @param buffer ����� ���ڰ� �ִ� ���� ��ġ. ������ �ּҺ��� 15�ڸ� �о line�� �ش��ϴ� �ٿ� ǥ���Ѵ�. (������ ��ȿ�� ���� �ʿ�).
				 a-z, A-Z ���� ���� ����ϸ� 0�� ��ĭ���� ����Ѵ�.
 * @param cursurPosition Ŀ���� ǥ���� ��ġ. 0�� ��� line�� �ش��ϴ� ���� ���� ����, 15�� ��� line�� �ش��ϴ� ���� ���� ������ ��迡 Ŀ���� ǥ���Ѵ�. -1�� ��쿡�� line�� �ش��ϴ� �ٿ��� Ŀ���� ǥ������ �ʴ´�.

void writeLine(int line, char* buffer, int cursurPosition);

��� ��
	writeLine(0, ..., 0); // ù��° �� ���� ���ʿ� Ŀ���� ǥ��
	writeLine(1, ..., 15); // �ι�° �� ���� �����ʿ� Ŀ���� ǥ��

	writeLine(0, ..., -1); writeLine(1, ..., 0); ù��° �ٿ��� Ŀ���� ǥ������ �ʰ� �ι�° �� ���� ���ʿ� Ŀ���� ǥ��
*/

// TODO: (����4) �䱸������ �����ϵ��� �Ʒ� Ŭ������ �ڵ带 �����Ͻÿ�.
class LabelPrinterExt
{
public:
	/**
	 * �� �����͸� �����ϴ� ����� �ʱ�ȭ
	 * ���� LCD�� �Է� ���� ���� �ʱ�ȭ�ϴ� ������ ���ԵǾ� �ִ�.
	 */
	LabelPrinterExt(Input& inputDevice) : input_(inputDevice) {}

	/**
	 * �׽�Ʈ ����� �� ������ �������� �Է��� ó���ϰ� ����� LCD�� ����Ѵ�.
	 * Ű�� �ϳ� �Էµ� �� ���� ȣ��ȴ�.
	 */
	void processInput()
	{
		char key = input_.getKeyInput();

		switch (key)
		{
		case KEY_LEFT:
			--cursorPos_;
			break;
		case KEY_RIGHT:
			if (!isalpha(displayBuffer_[cursorPos_]))
				break;
			++cursorPos_;
			break;
		case KEY_BACKSPACE:
			for (int i = cursorPos_; i <= strlen(displayBuffer_); ++i)
				displayBuffer_[i - 1] = displayBuffer_[i];
			--cursorPos_;
			break;
		default:
			for (int i = strlen(displayBuffer_); i >= cursorPos_; --i)
				displayBuffer_[i + 1] = displayBuffer_[i];
			displayBuffer_[cursorPos_] = key;
			++cursorPos_;
			break;
		}

		// TODO: �Ʒ��� ���� writeLine�� ȣ���ؼ� LCD�� ����Ѵ�.
		// writeLine(0, displayBuffer_, cursorPos_); // ���� ���  
		// writeLine(1, ...); // �Ʒ��� ���
		writeLine(0, displayBuffer_, cursorPos_ < 15 ? cursorPos_ : -1);
		writeLine(1, displayBuffer_ + 15, cursorPos_ < 15 ? -1 : cursorPos_ - 15);
	}

private:
	Input& input_;
	char displayBuffer_[31] = { 0, };
	int cursorPos_ = 0;
};


// ��������� �����ϰ� ���� �ڵ尡 �ִٸ� �Ʒ� main()�� �ۼ��Ͽ� Ȱ���� �� �ִ�.
// main �Լ��� �ڵ�� ä���� ������ ����.
int main()
{
	printTestInputResult("Sample Input", "", 0, sampleInput_keys);

	printTestInputResult("Test_1_1 Input", "", 0, test_1_1_keys);
	printTestInputResult("Test_1_2 Input", "ABCD", 2, test_1_2_keys);
	printTestInputResult("Test_1_3 Input", "POWER", 3, test_1_3_keys);

	test_2_1();
	test_2_2();

	return 0;
}