#ifndef TESTHUGEINTEGER_H_
#define TESTHUGEINTEGER_H_

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "HugeInteger.h"
using namespace std;

enum class TestType
{
	EMPTY,
	VALID_STRING,
	INVALID_STRING_IN_THE_MIDDLE,
	INVALID_STRING_AT_THE_BEGINNING,
	INVALID_STRING_AT_THE_END,
	EMPTY_STRING,
	LEADING_ZERO_NEGATIVE_INVALID,
	VALID_POSITIVE_NUMBER,
	INVALID_ZERO,
	INVALID_NEGATIVE_NUMBER,
	WITHOUT_CARRY,
	WITH_CARRY,
	RANDOM_NUMBER,
	TWO_NUMBERS_HAVE_SAME_SIZE,
	FISRT_NUMBER_HAS_LARGER_SIZE,
	SECOND_NUMBER_HAS_LARGER_SIZE,
	EQUAL,
	LARGER,
	SMALLER,
	SAME_SIGN_WITHOUT_BORROW_CARRY,
	SAME_SIGN_WITH_BORROW_CARRY,
	DIFF_SIGN_WITHOUT_BORROW_CARRY,
	DIFF_SIGN_WITH_BORROW_CARRY,
	ZERO,
	ZERO_EQUAL_ZERO,
	POSITIVE_OR_NEGATIVE_EQUAL_POSITIVE_OR_NEGATIVE,
	NEGATIVE_GREATER_NEGATIVE,
	POSITIVE_GREATER_POSITIVE,
	POSITIVE_GREATER_ZERO,
	POSITIVE_GREATER_NEGATIVE,
	NEGATIVE_LESS_NEGATIVE,
	POSITIVE_LESS_POSITIVE,
	NEGATIVE_LESS_ZERO,
	NEGATIVE_LESS_POSITIVE,
	SAME_SIGN_WITHOUT_CARRY,
	SAME_SIGN_WITH_CARRY,
	DIFF_SIGN_WITHOUT_CARRY,
	DIFF_SIGN_WITH_CARRY,
};

class TestHugeInteger
{
private:
	unsigned int NUM_DISPLAY = 1000;
	unsigned int MAX_RUN = 50;
	unsigned int MAX_INVALID_STRING = 5;
	vector<int> MAX_SIZE_ARRAY = {1, 1000, 5000};
	std::mt19937 gen;

public:
	TestHugeInteger(int num_display = 1000, int max_run = 50, int max_invalid_string = 5, vector<int> size_array = {1,1000,5000});
	// For lab 1
	double testConstructorString();
	double testConstructorNumber();
	double testPositiveAddition();
	// For lab 2
	double testAdditionSubtraction();
	double testCompareTo();
	double testMultiplication();

private:
	int testConstructorString(vector<int> sizes, int maxRun, TestType testType, string msg);
	int testConstructorStringExd(string number, bool validFlag, string msg);
	int testConstructorNumber(vector<int> sizes, int maxRun, TestType testType, string msg);
	int testConstructorNumberExd(int size, bool validFlag, string msg);
	int testPositiveAddition(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	int testPositiveAdditionExd(string number1, string number2, string msg);
	int testAdditionSubtraction(vector<int> sizes, int maxRun, bool addFlag, TestType mainTestType, TestType subTestType, string msg);
	int testAdditionSubtractionExd(string number1, string number2, bool addFlag, string msg);
	int testCompareTo(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	int testCompareToExd(string number1, string number2, string msg);
	int testMultiplication(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	int testMultiplicationExd(string number1, string number2, string msg);
	string getInvalidString(int n);
	string positiveRandomString(int size, int minInt, int maxInt);
	string randomString(int size);
	string removeLeadingZeros(string val);
};

#endif /* TESTHUGEINTEGER_H_ */
