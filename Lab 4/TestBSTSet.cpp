#include "TestBSTSet.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

TestBSTSet::TestBSTSet()
{
	this->gen.seed((unsigned int)std::time(nullptr));
}

TestBSTSet::TestBSTSet(int max_run, vector<int> max_size_array)
{
	this->MAX_RUN = max_run;
	this->MAX_SIZE_ARRAY = max_size_array;
	this->gen.seed((unsigned int)std::time(nullptr));
}

void TestBSTSet::testConstructor(double& total, double& full)
{
	/*
	Two main test cases for constructor (2 marks each subcase, total 4 marks)
	1. initialize with no repeated elements
	2. initialize with repeated elements
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2;
	double case_2_mark = 2;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark };
	vector<string> mainCaseMsg = { "no repetitions",
								   "repetitions" };

	vector<TestType> mainCaseTestType = { TestType::CONSTRUCTOR_NO_REPITITION,
										  TestType::CONSTRUCTOR_WITH_REPITITION };

	string msg;

	cout << "BEGIN TEST CONSTRUCTOR" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "constructor with " + mainCaseMsg[mainIdx];
		result = testConstructor(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test constructor PASS: ALL" << endl;
	}
	else {
		cerr << "Test constructor FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST CONSTRUCTOR, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testIsIn(double& total, double& full)
{
	/*
	Three main test cases for isIn (2 marks each subcase, total 6 marks)
	1. not in an empty set
	2. not in a non empty set
	3. in a non empty set
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2;
	double case_2_mark = 2;
	double case_3_mark = 2;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "not in an empty set",
								   "not in a non empty set",
								   "in a non empty set" };

	vector<TestType> mainCaseTestType = { TestType::ISIN_NOT_IN_EMPTY,
										  TestType::ISIN_NOT_IN_NONEMPTY,
										  TestType::ISIN_IN_NONEMPTY };

	string msg;

	cout << "BEGIN TEST ISIN" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "isIn for " + mainCaseMsg[mainIdx];
		result = testIsIn(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test isIn PASS: ALL" << endl;
	}
	else {
		cerr << "Test isIn FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST ISIN, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testAdd(double& total, double& full)
{
	/*
	Three main test cases for add (2 marks each subcase, total 6 marks)
	1. add in an empty set
	2. add in a non empty set
	3. do nothing in a non empty set
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2;
	double case_2_mark = 2;
	double case_3_mark = 2;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "adding in an empty set",
								   "adding in a non empty set",
								   "doing nothing in a non empty set" };

	vector<TestType> mainCaseTestType = { TestType::ADD_IN_EMPTY,
										  TestType::ADD_IN_NONEMPTY,
										  TestType::ADD_NOTHING_IN_NONEMPTY };

	string msg;

	cout << "BEGIN TEST ADD" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "add with " + mainCaseMsg[mainIdx];
		result = testAdd(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test add PASS: ALL" << endl;
	}
	else {
		cerr << "Test add FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST ADD, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testRemove(double& total, double& full)
{
	/*
	Three main test cases for remove (2 marks each subcase, total 6 marks)
	1. do nothing in an empty set
	2. remove in a non empty set
	3. do nothing in a non empty set
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2;
	double case_2_mark = 2;
	double case_3_mark = 2;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "doing nothing in an empty set",
								   "removing in a non empty set",
								   "doing nothing in a non empty set" };

	vector<TestType> mainCaseTestType = { TestType::REMOVE_NOTHING_IN_EMPTY,
										  TestType::REMOVE_IN_NONEMPTY,
										  TestType::REMOVE_NOTHING_IN_NONEMPTY };

	string msg;

	cout << "BEGIN TEST REMOVE" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "remove with " + mainCaseMsg[mainIdx];
		result = testRemove(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test remove PASS: ALL" << endl;
	}
	else {
		cerr << "Test remove FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST REMOVE, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testUnion(double& total, double& full)
{
	/*
	Three main test cases for Union (3 marks each subcase, total 9 marks)
	1. with empty set
	2. with common elements
	3. with no common elements
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "common elements",
								   "no common elements" };

	vector<TestType> mainCaseTestType = { TestType::UNION_EMPTY,
										  TestType::UNION_COMMON_ELEMENTS,
										  TestType::UNION_NO_COMMON_ELEMENTS };

	string msg;

	cout << "BEGIN TEST UNION" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "Union with " + mainCaseMsg[mainIdx];
		result = testUnion(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test Union PASS: ALL" << endl;
	}
	else {
		cerr << "Test Union FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST UNION, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testIntersection(double& total, double& full)
{
	/*
	Three main test cases for intersection (3 marks each subcase, total 9 marks)
	1. with empty set
	2. with common elements
	3. with no common elements
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "common elements",
								   "no common elements" };

	vector<TestType> mainCaseTestType = { TestType::INTERSECTION_EMPTY,
										  TestType::INTERSECTION_COMMON_ELEMENTS,
										  TestType::INTERSECTION_NO_COMMON_ELEMENTS };

	string msg;

	cout << "BEGIN TEST INTERSECTION" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "intersection with " + mainCaseMsg[mainIdx];
		result = testIntersection(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test intersection PASS: ALL" << endl;
	}
	else {
		cerr << "Test intersection FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST INTERSECTION, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testDifference(double& total, double& full)
{
	/*
	Three main test cases for difference (3 marks each subcase, total 9 marks)
	1. with empty set
	2. with common elements
	3. with no common elements
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "common elements",
								   "no common elements" };

	vector<TestType> mainCaseTestType = { TestType::DIFFERENCE_EMPTY,
										  TestType::DIFFERENCE_COMMON_ELEMENTS,
										  TestType::DIFFERENCE_NO_COMMON_ELEMENTS };

	string msg;

	cout << "BEGIN TEST DIFFERENCE" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "difference with " + mainCaseMsg[mainIdx];
		result = testDifference(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test difference PASS: ALL" << endl;
	}
	else {
		cerr << "Test difference FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST DIFFERENCE, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testSize(double& total, double& full)
{
	/*
	Three main test cases for size (2 marks each subcase, total 6 marks)
	1. with empty set
	2. with no repetitions
	3. with repetitions
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2;
	double case_2_mark = 2;
	double case_3_mark = 2;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "no repetitions",
								   "repetitions" };

	vector<TestType> mainCaseTestType = { TestType::SIZE_EMPTY,
										  TestType::SIZE_NO_REPETITIONS,
										  TestType::SIZE_WITH_REPETITIONS };

	string msg;

	cout << "BEGIN TEST SIZE" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "size with " + mainCaseMsg[mainIdx];
		result = testSize(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test size PASS: ALL" << endl;
	}
	else {
		cerr << "Test size FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST SIZE, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testHeight(double& total, double& full)
{
	/*
	Three main test cases for height (2 marks each subcase, total 6 marks)
	1. with empty set
	2. with no repetitions
	3. with repetitions
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2;
	double case_2_mark = 2;
	double case_3_mark = 2;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "no repetitions",
								   "repetitions" };

	vector<TestType> mainCaseTestType = { TestType::HEIGHT_EMPTY,
										  TestType::HEIGHT_NO_REPETITIONS,
										  TestType::HEIGHT_WITH_REPETITIONS };

	string msg;

	cout << "BEGIN TEST HEIGHT" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "height with " + mainCaseMsg[mainIdx];
		result = testHeight(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test height PASS: ALL" << endl;
	}
	else {
		cerr << "Test height FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST HEIGHT, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testPrintNonRec(double& total, double& full)
{
	/*
	Three main test cases for printNonRec (3 marks each subcase, total 9 marks)
	1. with empty set
	2. with no repetitions
	3. with repetitions
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "no repetitions",
								   "repetitions" };

	vector<TestType> mainCaseTestType = { TestType::PRINTNONREC_EMPTY,
										  TestType::PRINTNONREC_NO_REPETITIONS,
										  TestType::PRINTNONREC_WITH_REPETITIONS };

	string msg;

	cout << "BEGIN TEST PRINTNONREC" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "printNonRec with " + mainCaseMsg[mainIdx];
		result = testPrintNonRec(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test printNonRec PASS: ALL" << endl;
	}
	else {
		cerr << "Test printNonRec FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST PRINTNONREC, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testPrintLevelOrder(double& total, double& full)
{
	/*
	Three main test cases for printLevelOrder (3 marks each subcase, total 9 marks)
	1. with empty set
	2. with no repetitions
	3. with repetitions
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty set",
								   "no repetitions",
								   "repetitions" };

	vector<TestType> mainCaseTestType = { TestType::PRINTLEVELORDER_EMPTY,
										  TestType::PRINTLEVELORDER_NO_REPETITIONS,
										  TestType::PRINTLEVELORDER_WITH_REPETITIONS };

	string msg;

	cout << "BEGIN TEST PRINTLEVELORDER" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "printLevelOrder with " + mainCaseMsg[mainIdx];
		result = testPrintLevelOrder(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test printLevelOrder PASS: ALL" << endl;
	}
	else {
		cerr << "Test printLevelOrder FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST PRINTLEVELORDER, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestBSTSet::testBonus(double& total, double& full)
{
	/*
	Five main test cases for bonus (3 marks each subcase, total 15 marks)
	1. with increasing/decreasing elements
	2. with random elements
	3. with Union
	4. with intersection
	5. with difference
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double case_4_mark = 3;
	double case_5_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark, case_4_mark, case_5_mark };
	vector<string> mainCaseMsg = { "increasing/decreasing elements",
								   "random elements",
								   "Union",
								   "intersection",
								   "difference" };

	vector<TestType> mainCaseTestType = { TestType::BONUS_INCREASE_DECREASE,
										  TestType::BONUS_RANDOM,
										  TestType::BONUS_UNION,
										  TestType::BONUS_INTERSECTION,
										  TestType::BONUS_DIFFERENCE };

	string msg;

	cout << "BEGIN TEST BONUS" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "bonus with " + mainCaseMsg[mainIdx];
		result = testBonus(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test bonus PASS: ALL" << endl;
	}
	else {
		cerr << "Test bonus FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST BONUS, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

bool TestBSTSet::testConstructor(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::CONSTRUCTOR_NO_REPITITION: {
				vector<int> input = generateWithRepetitionVec(1, largeSize, 0);
				result = testConstructorExd(input, false, msg);
				break;
			}
			case TestType::CONSTRUCTOR_WITH_REPITITION: {
				vector<int> input = generateWithRepetitionVec(1, largeSize, smallSize);
				result = testConstructorExd(input, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testIsIn(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			int len = dist(gen);

			switch (mainTestType) {
			case TestType::ISIN_NOT_IN_EMPTY: {
				vector<int> input;
				uniform_int_distribution<> distNum(1, len);
				int num = distNum(gen);
				result = testIsInExd(input, num, false, msg);
				break;
			}
			case TestType::ISIN_NOT_IN_NONEMPTY: {
				vector<int> input = generateWithRepetitionVec(1, len, 0);
				uniform_int_distribution<> distNum(len + 1, len * 2);
				int num = distNum(gen);
				result = testIsInExd(input, num, false, msg);
				break;
			}
			case TestType::ISIN_IN_NONEMPTY: {
				vector<int> input = generateWithRepetitionVec(1, len, 0);
				uniform_int_distribution<> distNum(1, len);
				int num = distNum(gen);
				result = testIsInExd(input, num, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testAdd(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			int len = dist(gen);

			switch (mainTestType) {
			case TestType::ADD_IN_EMPTY: {
				vector<int> input;
				uniform_int_distribution<> distNum(1, len);
				int num = distNum(gen);
				result = testAddExd(input, num, false, msg);
				break;
			}
			case TestType::ADD_IN_NONEMPTY: {
				vector<int> input = generateWithRepetitionVec(1, len, 0);
				uniform_int_distribution<> distNum(len + 1, len * 2);
				int num = distNum(gen);
				result = testAddExd(input, num, false, msg);
				break;
			}
			case TestType::ADD_NOTHING_IN_NONEMPTY: {
				vector<int> input = generateWithRepetitionVec(1, len, 0);
				uniform_int_distribution<> distNum(1, len);
				int num = distNum(gen);
				result = testAddExd(input, num, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testRemove(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			int len = dist(gen);

			switch (mainTestType) {
			case TestType::REMOVE_NOTHING_IN_EMPTY: {
				vector<int> input;
				uniform_int_distribution<> distNum(1, len);
				int num = distNum(gen);
				result = testRemoveExd(input, num, false, msg);
				break;
			}
			case TestType::REMOVE_IN_NONEMPTY: {
				vector<int> input = generateWithRepetitionVec(1, len, 0);
				uniform_int_distribution<> distNum(1, len);
				int num = distNum(gen);
				result = testRemoveExd(input, num, false, msg);
				break;
			}
			case TestType::REMOVE_NOTHING_IN_NONEMPTY: {
				vector<int> input = generateWithRepetitionVec(1, len, 0);
				uniform_int_distribution<> distNum(len + 1, len * 2);
				int num = distNum(gen);
				result = testRemoveExd(input, num, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testUnion(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::UNION_EMPTY: {
				vector<int> input1;
				vector<int> input2 = generateWithRepetitionVec(1, smallSize, 0);
				result = testUnionExd(input1, input1, false, msg); // empty Union empty
				if (result == false) { break; }
				result = testUnionExd(input1, input2, false, msg); // empty Union non empty
				if (result == false) { break; }
				result = testUnionExd(input2, input1, false, msg); // non empty Union empty
				break;
			}
			case TestType::UNION_COMMON_ELEMENTS: {
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				uniform_int_distribution<> distStart(1, smallSize);
				int start = distStart(gen);
				vector<int> input2 = generateWithRepetitionVec(start, largeSize, 0);
				result = testUnionExd(input1, input2, false, msg);
				break;
			}
			case TestType::UNION_NO_COMMON_ELEMENTS: {
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				vector<int> input2 = generateWithRepetitionVec(smallSize+1, largeSize, 0);
				result = testUnionExd(input1, input2, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testIntersection(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::INTERSECTION_EMPTY: {
				vector<int> input1;
				vector<int> input2 = generateWithRepetitionVec(1, smallSize, 0);
				result = testIntersectionExd(input1, input1, false, msg); // empty intersection empty
				if (result == false) { break; }
				result = testIntersectionExd(input1, input2, false, msg); // empty intersection non empty
				if (result == false) { break; }
				result = testIntersectionExd(input2, input1, false, msg); // non empty intersection empty
				break;
			}
			case TestType::INTERSECTION_COMMON_ELEMENTS: {
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				uniform_int_distribution<> distStart(1, smallSize);
				int start = distStart(gen);
				vector<int> input2 = generateWithRepetitionVec(start, largeSize, 0);
				result = testIntersectionExd(input1, input2, false, msg);
				break;
			}
			case TestType::INTERSECTION_NO_COMMON_ELEMENTS: {
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				vector<int> input2 = generateWithRepetitionVec(smallSize + 1, largeSize, 0);
				result = testIntersectionExd(input1, input2, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testDifference(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::DIFFERENCE_EMPTY: {
				vector<int> input1;
				vector<int> input2 = generateWithRepetitionVec(1, smallSize, 0);
				result = testDifferenceExd(input1, input1, false, msg); // empty difference empty
				if (result == false) { break; }
				result = testDifferenceExd(input1, input2, false, msg); // empty difference non empty
				if (result == false) { break; }
				result = testDifferenceExd(input2, input1, false, msg); // non empty difference empty
				break;
			}
			case TestType::DIFFERENCE_COMMON_ELEMENTS: {
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				uniform_int_distribution<> distStart(1, smallSize);
				int start = distStart(gen);
				vector<int> input2 = generateWithRepetitionVec(start, largeSize, 0);
				result = testDifferenceExd(input1, input2, false, msg);
				break;
			}
			case TestType::DIFFERENCE_NO_COMMON_ELEMENTS: {
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				vector<int> input2 = generateWithRepetitionVec(smallSize + 1, largeSize, 0);
				result = testDifferenceExd(input1, input2, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}


bool TestBSTSet::testSize(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::SIZE_EMPTY: {
				vector<int> input;
				result = testSizeExd(input, false, msg);
				break;
			}
			case TestType::SIZE_NO_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, smallSize, 0);
				result = testSizeExd(input, false, msg);
				break;
			}
			case TestType::SIZE_WITH_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, largeSize, smallSize);
				result = testSizeExd(input, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testHeight(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::HEIGHT_EMPTY: {
				vector<int> input;
				result = testHeightExd(input, false, msg);
				break;
			}
			case TestType::HEIGHT_NO_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, smallSize, 0);
				result = testHeightExd(input, false, msg);
				break;
			}
			case TestType::HEIGHT_WITH_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, largeSize, smallSize);
				result = testHeightExd(input, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testPrintNonRec(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::PRINTNONREC_EMPTY: {
				vector<int> input;
				result = testPrintNonRecExd(input, false, msg);
				break;
			}
			case TestType::PRINTNONREC_NO_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, smallSize, 0);
				result = testPrintNonRecExd(input, false, msg);
				break;
			}
			case TestType::PRINTNONREC_WITH_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, largeSize, smallSize);
				result = testPrintNonRecExd(input, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testPrintLevelOrder(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::PRINTLEVELORDER_EMPTY: {
				vector<int> input;
				result = testPrintLevelOrderExd(input, false, msg);
				break;
			}
			case TestType::PRINTLEVELORDER_NO_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, smallSize, 0);
				result = testPrintLevelOrderExd(input, false, msg);
				break;
			}
			case TestType::PRINTLEVELORDER_WITH_REPETITIONS: {
				vector<int> input = generateWithRepetitionVec(1, largeSize, smallSize);
				result = testPrintLevelOrderExd(input, false, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testBonus(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::BONUS_INCREASE_DECREASE: {
				vector<int> input1(smallSize);
				vector<int> input2(smallSize);
				for (int i = 0; i < smallSize; i++) {
					input1[i] = i;
					input2[i] = smallSize - 1 - i;
				}
				result = testBonusExd(input1, false, msg);
				if (result == false) { break; }
				result = testBonusExd(input2, false, msg);
				break;
			}
			case TestType::BONUS_RANDOM: {
				// no repetition
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				result = testBonusExd(input1, false, msg);
				if (result == false) { break; }

				// with repetition
				vector<int> input2 = generateWithRepetitionVec(1, largeSize, smallSize);;
				result = testBonusExd(input2, false, msg);
				break;
			}
			case TestType::BONUS_UNION: {
				// with common elements
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				uniform_int_distribution<> distStart(1, smallSize);
				int start = distStart(gen);
				vector<int> input2 = generateWithRepetitionVec(start, largeSize, 0);
				result = testUnionExd(input1, input2, true, msg);
				if (result == false) { break; }

				// without common elements
				vector<int> input3 = generateWithRepetitionVec(smallSize + 1, largeSize, 0);
				result = testUnionExd(input1, input3, true, msg);
				break;
			}
			case TestType::BONUS_INTERSECTION: {
				// with common elements
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				uniform_int_distribution<> distStart(1, smallSize);
				int start = distStart(gen);
				vector<int> input2 = generateWithRepetitionVec(start, largeSize, 0);
				result = testIntersectionExd(input1, input2, true, msg);
				if (result == false) { break; }

				// without common elements
				vector<int> input3 = generateWithRepetitionVec(smallSize + 1, largeSize, 0);
				result = testIntersectionExd(input1, input3, true, msg);
				break;
			}
			case TestType::BONUS_DIFFERENCE: {
				// with common elements
				vector<int> input1 = generateWithRepetitionVec(1, smallSize, 0);
				uniform_int_distribution<> distStart(1, smallSize);
				int start = distStart(gen);
				vector<int> input2 = generateWithRepetitionVec(start, largeSize, 0);
				result = testDifferenceExd(input1, input2, true, msg);
				if (result == false) { break; }

				// without common elements
				vector<int> input3 = generateWithRepetitionVec(smallSize + 1, largeSize, 0);
				result = testDifferenceExd(input1, input3, true, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}

		}

		if (testFail)
			break;
	}

	return result;
}

bool TestBSTSet::testConstructorExd(vector<int> input, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {

		if (input.empty()) {
			BSTSet p;
			TNode* root = p.getRoot();
			if (root != NULL) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "root should be NULL" << endl;
			}
		}
		else {
			BSTSet p(input);
			std::set<int> setExp(input.begin(), input.end());

			string strGet = printBSTSet2String(p);
			string strExp = set2String(setExp);

			if (strGet != strExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector= " << vector2String(input) << endl;
				cerr << "Output   BSTSet= " << strGet << endl;
				cerr << "Expected BSTSet= " << strExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testIsInExd(vector<int> input, int num, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {

		if (input.empty()) {
			BSTSet p;
			bool result = p.isIn(num);
			if (result == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector= " << vector2String(input) << endl;
				cerr << "Input number= " << num << endl;
				cerr << "Output   isIn= " << result << endl;
				cerr << "Expected isIn= " << false << endl;
			}
		}
		else {
			BSTSet p(input);
			std::set<int> setExp(input.begin(), input.end());

			bool resGet = p.isIn(num);
			bool resExp = setExp.count(num);

			string strGet = printBSTSet2String(p);
			string strExp = set2String(setExp);

			if (resGet != resExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector= " << vector2String(input) << endl;
				cerr << "Input number= " << num << endl;
				cerr << "Output   isIn= " << resGet << endl;
				cerr << "Expected isIn= " << resExp << endl;
				cerr << "Output   BSTSet= " << strGet << endl;
				cerr << "Expected BSTSet= " << strExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
		cerr << "Input number= " << num << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
		cerr << "Input number= " << num << endl;
	}

	return passFlag;
}

bool TestBSTSet::testAddExd(vector<int> input, int num, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {

		if (input.empty()) {
			BSTSet p;
			std::set<int> setExp;

			p.add(num);
			setExp.insert(num);

			string strGet = printBSTSet2String(p);
			string strExp = set2String(setExp);

			if (strGet != strExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector= " << vector2String(input) << endl;
				cerr << "Added number= " << num << endl;
				cerr << "Output   BSTSet= " << strGet << endl;
				cerr << "Expected BSTSet= " << strExp << endl;
			}
		}
		else {
			BSTSet p(input);
			std::set<int> setExp(input.begin(), input.end());

			p.add(num);
			setExp.insert(num);

			string strGet = printBSTSet2String(p);
			string strExp = set2String(setExp);

			if (strGet != strExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector= " << vector2String(input) << endl;
				cerr << "Added number= " << num << endl;
				cerr << "Output   BSTSet= " << strGet << endl;
				cerr << "Expected BSTSet= " << strExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
		cerr << "Added number= " << num << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
		cerr << "Added number= " << num << endl;
	}

	return passFlag;
}

bool TestBSTSet::testRemoveExd(vector<int> input, int num, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {

		if (input.empty()) {
			BSTSet p;
			std::set<int> setExp;

			bool resGet = p.remove(num);
			bool resExp = setExp.erase(num);

			string strGet = printBSTSet2String(p);
			string strExp = set2String(setExp);

			if ((resGet != resExp) || (strGet != strExp)) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input  vector= " << vector2String(input) << endl;
				cerr << "Remove number= " << num << endl;
				cerr << "Output   BSTSet= " << strGet << endl;
				cerr << "Expected BSTSet= " << strExp << endl;
				cerr << "Output   state= " << resGet << endl;
				cerr << "Expected state= " << resExp << endl;
			}
		}
		else {
			BSTSet p(input);
			std::set<int> setExp(input.begin(), input.end());

			bool resGet = p.remove(num);
			bool resExp = setExp.erase(num);

			string strGet = printBSTSet2String(p);
			string strExp = set2String(setExp);

			if ((resGet != resExp) || (strGet != strExp)) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input  vector= " << vector2String(input) << endl;
				cerr << "Remove number= " << num << endl;
				cerr << "Output   BSTSet= " << strGet << endl;
				cerr << "Expected BSTSet= " << strExp << endl;
				cerr << "Output   state= " << resGet << endl;
				cerr << "Expected state= " << resExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input  vector= " << vector2String(input) << endl;
		cerr << "Remove number= " << num << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  vector= " << vector2String(input) << endl;
		cerr << "Remove number= " << num << endl;
	}

	return passFlag;
}

bool TestBSTSet::testUnionExd(vector<int> input1, vector<int> input2, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet setDst(input1);
		BSTSet setSrc(input2);
		std::set<int> setExp1(input1.begin(), input1.end());
		std::set<int> setExp2(input2.begin(), input2.end());
		std::set<int> resExp = setExp1;

		setDst.Union(setSrc);
		resExp.insert(setExp2.begin(), setExp2.end());

		string strGet = printBSTSet2String(setDst);
		string strExp = set2String(resExp);

		if (strGet != strExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector1= " << vector2String(input1) << endl;
			cerr << "Input vector2= " << vector2String(input2) << endl;
			cerr << "Output   v1.Union(v2)= " << strGet << endl;
			cerr << "Expected v1.Union(v2)= " << strExp << endl;
		}

		if (checkFlag && passFlag) {
			int hGet = setDst.height();
			int hExp = -1;
			int sizeExp = resExp.size();
			if (sizeExp > 0)
				hExp = floor(log2(sizeExp));

			if (hGet != hExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector1= " << vector2String(input1) << endl;
				cerr << "Input vector2= " << vector2String(input2) << endl;
				cerr << "Output   height= " << hGet << endl;
				cerr << "Expected height= " << hExp << endl;
				cerr << "Output   v1.Union(v2)= " << strGet << endl;
				cerr << "Expected v1.Union(v2)= " << strExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector1= " << vector2String(input1) << endl;
		cerr << "Input vector2= " << vector2String(input2) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector1= " << vector2String(input1) << endl;
		cerr << "Input vector2= " << vector2String(input2) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testIntersectionExd(vector<int> input1, vector<int> input2, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet setDst(input1);
		BSTSet setSrc(input2);
		std::set<int> setExp1(input1.begin(), input1.end());
		std::set<int> setExp2(input2.begin(), input2.end());
		std::set<int> resExp;

		setDst.intersection(setSrc);
		std::set_intersection(setExp1.begin(), setExp1.end(), setExp2.begin(), setExp2.end(), std::inserter(resExp, resExp.begin()));

		string strGet = printBSTSet2String(setDst);
		string strExp = set2String(resExp);

		if (strGet != strExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector1= " << vector2String(input1) << endl;
			cerr << "Input vector2= " << vector2String(input2) << endl;
			cerr << "Output   v1.intsec(v2)= " << strGet << endl;
			cerr << "Expected v1.intsec(v2)= " << strExp << endl;
		}

		if (checkFlag && passFlag) {
			int hGet = setDst.height();
			int hExp = -1;
			int sizeExp = resExp.size();
			if (sizeExp > 0)
				hExp = floor(log2(sizeExp));

			if (hGet != hExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector1= " << vector2String(input1) << endl;
				cerr << "Input vector2= " << vector2String(input2) << endl;
				cerr << "Output   height= " << hGet << endl;
				cerr << "Expected height= " << hExp << endl;
				cerr << "Output   v1.intsec(v2)= " << strGet << endl;
				cerr << "Expected v1.intsec(v2)= " << strExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector1= " << vector2String(input1) << endl;
		cerr << "Input vector2= " << vector2String(input2) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector1= " << vector2String(input1) << endl;
		cerr << "Input vector2= " << vector2String(input2) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testDifferenceExd(vector<int> input1, vector<int> input2, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet setDst(input1);
		BSTSet setSrc(input2);
		std::set<int> setExp1(input1.begin(), input1.end());
		std::set<int> setExp2(input2.begin(), input2.end());
		std::set<int> resExp;

		setDst.difference(setSrc);
		std::set_difference(setExp1.begin(), setExp1.end(), setExp2.begin(), setExp2.end(), std::inserter(resExp, resExp.begin()));

		string strGet = printBSTSet2String(setDst);
		string strExp = set2String(resExp);

		if (strGet != strExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector1= " << vector2String(input1) << endl;
			cerr << "Input vector2= " << vector2String(input2) << endl;
			cerr << "Output   v1.diff(v2)= " << strGet << endl;
			cerr << "Expected v1.diff(v2)= " << strExp << endl;
		}

		if (checkFlag && passFlag) {
			int hGet = setDst.height();
			int hExp = -1;
			int sizeExp = resExp.size();
			if (sizeExp > 0)
				hExp = floor(log2(sizeExp));

			if (hGet != hExp) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Input vector1= " << vector2String(input1) << endl;
				cerr << "Input vector2= " << vector2String(input2) << endl;
				cerr << "Output   height= " << hGet << endl;
				cerr << "Expected height= " << hExp << endl;
				cerr << "Output   v1.diff(v2)= " << strGet << endl;
				cerr << "Expected v1.diff(v2)= " << strExp << endl;
			}
		}

	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector1= " << vector2String(input1) << endl;
		cerr << "Input vector2= " << vector2String(input2) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector1= " << vector2String(input1) << endl;
		cerr << "Input vector2= " << vector2String(input2) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testSizeExd(vector<int> input, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet resGet(input);
		std::set<int> resExp(input.begin(), input.end());

		// check the size
		int sizeGet = resGet.size();
		int sizeExp = resExp.size();

		string strGet = printBSTSet2String(resGet);
		string strExp = set2String(resExp);

		if ((sizeGet != sizeExp) || (strGet != strExp)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   size= " << sizeGet << endl;
			cerr << "Expected size= " << sizeExp << endl;
			cerr << "Output   BSTSet= " << strGet << endl;
			cerr << "Expected BSTSet= " << strExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testHeightExd(vector<int> input, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet resGet(input);
		std::set<int> resExp(input.begin(), input.end());

		int hGet = resGet.height();
		int hExp = 0;
		string strTmp = getLevelOrder(resGet, resExp.size(), hExp);

		string strGet = printBSTSet2String(resGet);
		string strExp = set2String(resExp);

		if (strGet != strExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   BSTSet= " << strGet << endl;
			cerr << "Expected BSTSet= " << strExp << endl;
		}
		else if (hGet != hExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   BSTSet= " << strGet << endl;
			cerr << "Expected BSTSet= " << strExp << endl;
			cerr << "Output   height= " << hGet << endl;
			cerr << "Expected height= " << hExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testPrintNonRecExd(vector<int> input, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet resGet(input);
		std::set<int> resExp(input.begin(), input.end());

		string strGet = printNonRec2String(resGet);
		string strExp = set2String(resExp);

		if (strGet != strExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   Non Rec= " << strGet << endl;
			cerr << "Expected Non Rec= " << strExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testPrintLevelOrderExd(vector<int> input, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet resGet(input);
		std::set<int> resExp(input.begin(), input.end());

		string strGet = printLevelOrder2String(resGet);
		int h = 0;
		string strExp = getLevelOrder(resGet, resExp.size(), h);

		string strBSTGet = printBSTSet2String(resGet);
		string strBSTExp = set2String(resExp);

		if (strBSTGet != strBSTExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   BSTSet= " << strBSTGet << endl;
			cerr << "Expected BSTSet= " << strBSTExp << endl;
		}
		else if (strGet != strExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   Level Order= " << strGet << endl;
			cerr << "Expected Level Order= " << strExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}

	return passFlag;
}

bool TestBSTSet::testBonusExd(vector<int> input, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		BSTSet resGet(input);
		std::set<int> resExp(input.begin(), input.end());

		int hGet = resGet.height();
		int hExp = -1;
		int sizeExp = resExp.size();
		if (sizeExp > 0)
			hExp = floor(log2(sizeExp));

		int hReal = 0;
		string strTmp = getLevelOrder(resGet, resExp.size(), hReal);

		string strBSTGet = printBSTSet2String(resGet);
		string strBSTExp = set2String(resExp);

		if (strBSTGet != strBSTExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   BSTSet= " << strBSTGet << endl;
			cerr << "Expected BSTSet= " << strBSTExp << endl;
		}
		else if ((hGet != hExp) || (hGet != hReal)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input vector= " << vector2String(input) << endl;
			cerr << "Output   BSTSet= " << strBSTGet << endl;
			cerr << "Expected BSTSet= " << strBSTExp << endl;
			cerr << "Real     height= " << hReal << endl;
			cerr << "Output   height= " << hGet << endl;
			cerr << "Expected height= " << hExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input vector= " << vector2String(input) << endl;
	}

	return passFlag;
}

vector<int> TestBSTSet::generateWithRepetitionVec(int start, int end, int repLen)
{
	if (start > end)
		throw std::invalid_argument("start > end");

	int len = end - start + 1;
	vector<int> vec(len);
	uniform_int_distribution<> dist(0, len - 1);

	for (int i = 0; i < len; i++) {
		vec[i] = start + i;
	}

	// vector shuffle
	for (int i = len - 1; i >= 0; i--) {
		std::swap(vec[dist(gen)], vec[i]);
	}

	if (repLen > 0) {
		vec.resize(len + repLen);

		for (int i = len; i < len + repLen; i++) {
			vec[i] = vec[dist(gen)];
		}
	}

	return vec;
}

string TestBSTSet::set2String(std::set<int>& s)
{
	string str = "";

	if (!s.empty()){
		for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
			str = str + to_string(*it) + ",";
	}

	return str;
}

string TestBSTSet::printBSTSet2String(BSTSet& s)
{
	std::stringstream buffer;

	// Redirect std::cout to buffer
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	s.printBSTSet();

	// Restore original buffer before exiting
	std::cout.rdbuf(prevcoutbuf);
	std::string str = buffer.str();

	return str;
}

string TestBSTSet::printNonRec2String(BSTSet& s)
{
	std::stringstream buffer;

	// Redirect std::cout to buffer
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	s.printNonRec();

	// Restore original buffer before exiting
	std::cout.rdbuf(prevcoutbuf);
	std::string str = buffer.str();

	return str;
}

string TestBSTSet::printLevelOrder2String(BSTSet& s)
{
	std::stringstream buffer;

	// Redirect std::cout to buffer
	std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
	//s.printLevelOrder(); // delete this test case

	// Restore original buffer before exiting
	std::cout.rdbuf(prevcoutbuf);
	std::string str = buffer.str();

	return str;
}

string TestBSTSet::vector2String(vector<int> num)
{
	std::ostringstream oss;
	oss << "[";

	if (num.size() == 1) {
		oss << num[0];
	}
	else if (num.size() > 1) {
		std::copy(num.begin(), num.end() - 1, std::ostream_iterator<int>(oss, ","));
		oss << num.back();
	}

	oss << "]";

	return oss.str();
}

void TestBSTSet::getLevelElements(TNode* subroot, vector<vector<int>>& res, int h)
{
	if (subroot == NULL)
		return;
	else {
		(res[h]).push_back(subroot->element);
		h++;
		getLevelElements(subroot->left, res, h);
		getLevelElements(subroot->right, res, h);
	}
}

string TestBSTSet::getLevelOrder(BSTSet& s, int size, int& h)
{
	if (size == 0) {
		h = -1;
		return "";
	}

	vector<vector<int>> result(size);
	TNode* root = s.getRoot();
	getLevelElements(root, result, 0);

	string str = "";
	h = -1;
	for (int i = 0; i < size; i++) {
		for (size_t j = 0; j < result[i].size(); j++) {
			str = str + to_string(result[i][j]) + ",";
		}
		if (result[i].size() > 0)
			h++;
	}
	return str;
}
