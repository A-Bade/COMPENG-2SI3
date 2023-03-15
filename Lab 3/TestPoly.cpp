#include "TestPoly.h"
#include "Poly.h"
#include <iostream>
#include <ctime>
#include <set>
#include <sstream>
#include <iterator>
using namespace std;

TestPoly::TestPoly()
{
	this->gen.seed((unsigned int)std::time(nullptr));
}

TestPoly::TestPoly(int max_degree, double max_coeff, int max_eval_degree, double max_eval_coeff, int max_run, vector<int> max_size_array)
{
	this->MAX_DEGREE = max_degree;
	this->MAX_COEFF = max_coeff;
	this->MAX_EVAL_DEGREE = max_eval_degree;
	this->MAX_EVAL_COEFF = max_eval_coeff;
	this->MAX_RUN = max_run;
	this->MAX_SIZE_ARRAY = max_size_array;
	this->gen.seed((unsigned int)std::time(nullptr));
}

void TestPoly::testConstructorDefault(double& total, double& full)
{
	/*
	Two main test cases for constructor default (2 marks each subcase, total 4 marks)
	1. check for dummy header
	2. with getDegree/getTermsNo
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
	vector<string> mainCaseMsg = { "dummy header",
								   "getDegree/getTermsNo"};

	vector<TestType> mainCaseTestType = { TestType::CONSTRUCTOR_DUMMY_HEADER,
										  TestType::CONSTRUCTOR_DEGREE_TERMSNO};

	string msg;

	cout << "BEGIN TEST CONSTRUCTOR DEFAULT" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
			markSum += caseMarks[mainIdx];
			msg = "constructor default for " + mainCaseMsg[mainIdx];
			result = testConstructorDefault(sizes, maxRun, mainCaseTestType[mainIdx], msg);
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
		cout << "Test constructor default PASS: ALL" << endl;
	}
	else {
		cerr << "Test constructor default FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST CONSTRUCTOR DEFAULT, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testConstructorParameters(double& total, double& full)
{
	/*
	Two main test cases for constructor parameters (2 marks each subcase, total 4 marks)
	1. no getDegree/getTermsNo
	2. with getDegree/getTermsNo
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
	vector<string> mainCaseMsg = { "no getDegree/getTermsNo",
								   "with getDegree/getTermsNo" };
	vector<TestType> mainCaseTestType = { TestType::CONSTRUCTOR_PARAMETERS_NOCHECK,
										  TestType::CONSTRUCTOR_PARAMETERS_CHECK };

	string msg;

	cout << "BEGIN TEST CONSTRUCTOR PARAMETERS" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "constructor parameters for " + mainCaseMsg[mainIdx];
		result = testConstructorParameters(sizes, maxRun, mainCaseTestType[mainIdx], msg);
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
		cout << "Test constructor parameters PASS: ALL" << endl;
	}
	else {
		cerr << "Test constructor parameters FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST CONSTRUCTOR PARAMETERS, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testAddMono(double& total, double& full)
{
	/*
	Three main test cases for addMono (2 marks each subcase, total 18 marks)
	(each test case tested without/with getDegree/getTermsNo)
	1) add first
		i)add item
		ii)delete item
		iii)update item
	2) add middle
		i)without delete
		ii)with delete
		iii)with update
	3) add last
		i)without delete
		ii)with delete
		iii)with update
	*/
	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_1_mark = 1.5;
	double case_1_2_mark = 0.5;
	double case_1_3_mark = 1.5;
	double case_1_4_mark = 0.5;
	double case_1_5_mark = 1.5;
	double case_1_6_mark = 0.5;
	double case_2_1_mark = 1.5;
	double case_2_2_mark = 0.5;
	double case_2_3_mark = 1.5;
	double case_2_4_mark = 0.5;
	double case_2_5_mark = 1.5;
	double case_2_6_mark = 0.5;
	double case_3_1_mark = 1.5;
	double case_3_2_mark = 0.5;
	double case_3_3_mark = 1.5;
	double case_3_4_mark = 0.5;
	double case_3_5_mark = 1.5;
	double case_3_6_mark = 0.5;
	double markSum = 0;

	vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark,case_1_3_mark,case_1_4_mark,case_1_5_mark,case_1_6_mark},
										 {case_2_1_mark,case_2_2_mark,case_2_3_mark,case_2_4_mark,case_2_5_mark,case_2_6_mark},
										 {case_3_1_mark,case_3_2_mark,case_3_3_mark,case_3_4_mark,case_3_5_mark,case_3_6_mark} };
	vector<string> mainCaseMsg = { "add first",
								   "add middle",
								   "add end" };
	vector<string> subCaseMsg = { "add item, no getDegree/getTermsNo",
								  "add item, with getDegree/getTermsNo",
								  "delete item, no getDegree/getTermsNo",
								  "delete item, with getDegree/getTermsNo",
								  "update item, no getDegree/getTermsNo",
							      "update item, with getDegree/getTermsNo" };
	vector<TestType> mainCaseTestType = { TestType::ADD_FIRST,
										  TestType::ADD_MIDDLE,
										  TestType::ADD_LAST };
	vector<TestType> subCaseTestType = { TestType::WITH_ADD_NOCHECK,
										 TestType::WITH_ADD_CHECK,
										 TestType::WITH_DELETE_NOCHECK,
										 TestType::WITH_DELETE_CHECK,
										 TestType::WITH_UPDATE_NOCHECK,
										 TestType::WITH_UPDATE_CHECK };
	string msg;

	cout << "BEGIN TEST ADDMONO" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		for (size_t subIdx = 0; subIdx < subCaseTestType.size(); subIdx++) {
			markSum += caseMarks[mainIdx][subIdx];
			msg = "addMono for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
			result = testAddMono(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
			fails += (result == false);
			if (result == true) {
				totalMark += caseMarks[mainIdx][subIdx];
				cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
			else {
				cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
		}
	}

	if (fails == 0) {
		cout << "Test addMono PASS: ALL" << endl;
	}
	else {
		cerr << "Test addMono FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST ADDMONO, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testAddPoly(double& total, double& full)
{
	/*
	Three main test cases for addPoly (2 marks each subcase, total 14 marks)
	(each test case tested without/with getDegree/getTermsNo)
	1) first poly has more items
		i)second is non-zero
		ii)second is zero
	2) two polys have same size
		i)both are non-zero
		ii)both are zero
		iii)result is zero
	3) first poly has less items
		i)first is non-zero
		ii)first is zero
	*/
	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_1_mark = 1.5;
	double case_1_2_mark = 0.5;
	double case_1_3_mark = 1.5;
	double case_1_4_mark = 0.5;
	double case_2_1_mark = 1.5;
	double case_2_2_mark = 0.5;
	double case_2_3_mark = 1.5;
	double case_2_4_mark = 0.5;
	double case_2_5_mark = 1.5;
	double case_2_6_mark = 0.5;
	double case_3_1_mark = 1.5;
	double case_3_2_mark = 0.5;
	double case_3_3_mark = 1.5;
	double case_3_4_mark = 0.5;
	double markSum = 0;

	vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark,case_1_3_mark,case_1_4_mark},
										 {case_2_1_mark,case_2_2_mark,case_2_3_mark,case_2_4_mark,case_2_5_mark,case_2_6_mark},
										 {case_3_1_mark,case_3_2_mark,case_3_3_mark,case_3_4_mark}};
	vector<string> mainCaseMsg = { "first poly has more items",
								   "two polys have same size",
								   "first poly has less items" };
	vector<vector<string>> subCaseMsg = { {"second is non-zero, no getDegree/getTermsNo",
										   "second is non-zero, with getDegree/getTermsNo",
										   "second is zero, no getDegree/getTermsNo",
										   "second is zero, with getDegree/getTermsNo"},
										  {"both are non-zero, no getDegree/getTermsNo",
										   "both are non-zero, with getDegree/getTermsNo",
										   "both are zero, no getDegree/getTermsNo",
										   "both are zero, with getDegree/getTermsNo",
										   "result is zero, no getDegree/getTermsNo",
										   "result is zero, with getDegree/getTermsNo" },
										  {"first is non-zero, no getDegree/getTermsNo",
										   "first is non-zero, with getDegree/getTermsNo",
										   "first is zero, no getDegree/getTermsNo",
										   "first is zero, with getDegree/getTermsNo"} };
	vector<TestType> mainCaseTestType = { TestType::FIRST_MORE_ITEMS,
										  TestType::TWO_SAME_SIZE,
										  TestType::FIRST_LESS_ITEMS };
	vector<vector<TestType>> subCaseTestType = { {TestType::SECOND_NONZERO_NOCHECK,TestType::SECOND_NONZERO_CHECK,TestType::SECOND_ZERO_NOCHECK,TestType::SECOND_ZERO_CHECK},
												 {TestType::BOTH_NONZERO_NOCHECK,TestType::BOTH_NONZERO_CHECK,TestType::BOTH_ZERO_NOCHECK,TestType::BOTH_ZERO_CHECK,TestType::RESULT_ZERO_NOCHECK,TestType::RESULT_ZERO_CHECK},
												 {TestType::FIRST_NONZERO_NOCHECK,TestType::FIRST_NONZERO_CHECK,TestType::FIRST_ZERO_NOCHECK,TestType::FIRST_ZERO_CHECK} };
	string msg;

	cout << "BEGIN TEST ADDPOLY" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		for (size_t subIdx = 0; subIdx < subCaseTestType[mainIdx].size(); subIdx++) {
			markSum += caseMarks[mainIdx][subIdx];
			msg = "addPoly for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[mainIdx][subIdx];
			result = testAddPoly(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[mainIdx][subIdx], msg);
			fails += (result == false);
			if (result == true) {
				totalMark += caseMarks[mainIdx][subIdx];
				cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
			else {
				cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
		}
	}

	if (fails == 0) {
		cout << "Test addPoly PASS: ALL" << endl;
	}
	else {
		cerr << "Test addPoly FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST ADDPOLY, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testMultiplyMono(double& total, double& full)
{
	/*
	Three main test cases for multiplyMono (3 marks each subcase, total 6 marks)
	(each test case tested without/with getDegree/getTermsNo)
	1) multiply non-zero
	2) multiply zero
	*/
	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2.5;
	double case_2_mark = 0.5;
	double case_3_mark = 2.5;
	double case_4_mark = 0.5;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark, case_4_mark };
	vector<string> mainCaseMsg = { "multiply non-zero, no getDegree/getTermsNo",
								   "multiply non-zero, with getDegree/getTermsNo",
								   "multiply zero, no getDegree/getTermsNo",
								   "multiply zero, with getDegree/getTermsNo" };
	vector<TestType> mainCaseTestType = { TestType::MULTIPLY_NONZERO_NOCHECK,
										  TestType::MULTIPLY_NONZERO_CHECK,
										  TestType::MULTIPLY_ZERO_NOCHECK,
										  TestType::MULTIPLY_ZERO_CHECK, };
	string msg;

	cout << "BEGIN TEST MULTIPLYMONO" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "multiplyMono for " + mainCaseMsg[mainIdx];
		result = testMultiplyMono(sizes, maxRun, mainCaseTestType[mainIdx], msg);
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
		cout << "Test multiplyMono PASS: ALL" << endl;
	}
	else {
		cerr << "Test multiplyMono FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST MULTIPLYMONO, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testMultiplyPoly(double& total, double& full)
{
	/*
	Three main test cases for multiplyPoly (2 marks each subcase, total 12 marks)
	(each test case tested without/with getDegree/getTermsNo)
	1) first poly has more items
		i)second is non-zero
		ii)second is zero
	2) two polys have same size
		i)both are non-zero
		ii)both are zero
	3) first poly has less items
		i)first is non-zero
		ii)first is zero
	*/
	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_1_mark = 1.5;
	double case_1_2_mark = 0.5;
	double case_1_3_mark = 1.5;
	double case_1_4_mark = 0.5;
	double case_2_1_mark = 1.5;
	double case_2_2_mark = 0.5;
	double case_2_3_mark = 1.5;
	double case_2_4_mark = 0.5;
	double case_3_1_mark = 1.5;
	double case_3_2_mark = 0.5;
	double case_3_3_mark = 1.5;
	double case_3_4_mark = 0.5;
	double markSum = 0;

	vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark,case_1_3_mark,case_1_4_mark},
										 {case_2_1_mark,case_2_2_mark,case_2_3_mark,case_2_4_mark},
										 {case_3_1_mark,case_3_2_mark,case_3_3_mark,case_3_4_mark} };
	vector<string> mainCaseMsg = { "first poly has more items",
								   "two polys have same size",
								   "first poly has less items" };
	vector<vector<string>> subCaseMsg = { {"second is non-zero, no getDegree/getTermsNo",
										   "second is non-zero, with getDegree/getTermsNo",
										   "second is zero, no getDegree/getTermsNo",
										   "second is zero, with getDegree/getTermsNo"},
										  {"both are non-zero, no getDegree/getTermsNo",
										   "both are non-zero, with getDegree/getTermsNo",
										   "both are zero, no getDegree/getTermsNo",
										   "both are zero, with getDegree/getTermsNo"},
										  {"first is non-zero, no getDegree/getTermsNo",
										   "first is non-zero, with getDegree/getTermsNo",
										   "first is zero, no getDegree/getTermsNo",
										   "first is zero, with getDegree/getTermsNo"} };
	vector<TestType> mainCaseTestType = { TestType::FIRST_MORE_ITEMS,
										  TestType::TWO_SAME_SIZE,
										  TestType::FIRST_LESS_ITEMS };
	vector<vector<TestType>> subCaseTestType = { {TestType::SECOND_NONZERO_NOCHECK,TestType::SECOND_NONZERO_CHECK,TestType::SECOND_ZERO_NOCHECK,TestType::SECOND_ZERO_CHECK},
												 {TestType::BOTH_NONZERO_NOCHECK,TestType::BOTH_NONZERO_CHECK,TestType::BOTH_ZERO_NOCHECK,TestType::BOTH_ZERO_CHECK},
												 {TestType::FIRST_NONZERO_NOCHECK,TestType::FIRST_NONZERO_CHECK,TestType::FIRST_ZERO_NOCHECK,TestType::FIRST_ZERO_CHECK} };
	string msg;

	cout << "BEGIN TEST MULTIPLYPOLY" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		for (size_t subIdx = 0; subIdx < subCaseTestType[mainIdx].size(); subIdx++) {
			markSum += caseMarks[mainIdx][subIdx];
			msg = "multiplyPoly for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[mainIdx][subIdx];
			result = testMultiplyPoly(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[mainIdx][subIdx], msg);
			fails += (result == false);
			if (result == true) {
				totalMark += caseMarks[mainIdx][subIdx];
				cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
			else {
				cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
		}
	}

	if (fails == 0) {
		cout << "Test multiplyPoly PASS: ALL" << endl;
	}
	else {
		cerr << "Test multiplyPoly FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST MULTIPLYPOLY, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testDuplicate(double& total, double& full)
{
	/*
	Two main test cases for duplicate (3 marks each subcase, total 6 marks)
	(each test case tested without/with getDegree/getTermsNo)
	1) duplicate non-zero
	2) duplicate zero
	*/
	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 2.5;
	double case_2_mark = 0.5;
	double case_3_mark = 2.5;
	double case_4_mark = 0.5;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark, case_4_mark };
	vector<string> mainCaseMsg = { "duplicate non-zero, no getDegree/getTermsNo",
								   "duplicate non-zero, with getDegree/getTermsNo",
								   "duplicate zero, no getDegree/getTermsNo",
								   "duplicate zero, with getDegree/getTermsNo" };
	vector<TestType> mainCaseTestType = { TestType::DUPLICATE_NONZERO_NOCHECK,
										  TestType::DUPLICATE_NONZERO_CHECK,
										  TestType::DUPLICATE_ZERO_NOCHECK,
										  TestType::DUPLICATE_ZERO_CHECK };
	string msg;

	cout << "BEGIN TEST DUPLICATE" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "duplicate for " + mainCaseMsg[mainIdx];
		result = testDuplicate(sizes, maxRun, mainCaseTestType[mainIdx], msg);
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
		cout << "Test duplicate PASS: ALL" << endl;
	}
	else {
		cerr << "Test duplicate FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST DUPLICATE, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestPoly::testEvaluate(double& total, double& full)
{
	/*
	Three main test cases for evaluate (3 marks each subcase, total 6 marks)
	1) evaluate with non-zero poly
	2) evaluate zero poly
	*/
	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark };
	vector<string> mainCaseMsg = { "evaluate with non-zero poly",
								   "evaluate zero poly" };
	vector<TestType> mainCaseTestType = { TestType::EVALUATE_NONZERO,
										  TestType::EVALUATE_ZERO };

	string msg;

	cout << "BEGIN TEST EVALUATE" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "evaluate for " + mainCaseMsg[mainIdx];
		result = testEvaluate(sizes, maxRun, mainCaseTestType[mainIdx], msg);
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
		cout << "Test evaluate PASS: ALL" << endl;
	}
	else {
		cerr << "Test evaluate FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST EVALUATE, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

bool TestPoly::testConstructorDefault(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			switch (mainTestType) {
			case TestType::CONSTRUCTOR_DUMMY_HEADER: {
				Poly p; // call default constructor
				PolyNode* head = p.getHead();

				if (head == NULL) {
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "No dummy header" << endl;
					result = false;
				}
				else if (head->next != NULL) {
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "head->next should be null" << endl;
					result = false;
				}
				else {
					result = true;
				}
				break;
			}
			case TestType::CONSTRUCTOR_DEGREE_TERMSNO: {
				Poly p; // call default constructor
				int degree = p.getDegree();
				int termsNo = p.getTermsNo();

				if (degree != -1) {
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "Output   degree= " << degree << endl;
					cerr << "Expected degree= " << -1 << endl;
					result = false;
				}
				else if (termsNo != 0) {
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "Output   termsNo= " << termsNo << endl;
					cerr << "Expected termsNo= " << 0 << endl;
					result = false;
				}
				else {
					result = true;
				}
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

bool TestPoly::testConstructorParameters(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_DEGREE;
	int maxCoeff = (int)MAX_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			int len = dist(gen);

			switch (mainTestType) {
			case TestType::CONSTRUCTOR_PARAMETERS_NOCHECK: {
				vector<int> deg = generateDegreeVec(len, maxDegree);
				vector<double> coeff = generateCoeffVec(len, maxCoeff);
				result = testConstructorExd(deg, coeff, false, msg);
				break;
			}
			case TestType::CONSTRUCTOR_PARAMETERS_CHECK: {
				vector<int> deg = generateDegreeVec(len, maxDegree);
				vector<double> coeff = generateCoeffVec(len, maxCoeff);
				result = testConstructorExd(deg, coeff, true, msg);
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

bool TestPoly::testAddMono(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_DEGREE;
	int maxCoeff = (int)MAX_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			int len = dist(gen);
			if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
				continue;
			}
			switch (mainTestType) {
			case TestType::ADD_FIRST:{
				switch (subTestType) {
				case TestType::WITH_ADD_NOCHECK:
				case TestType::WITH_ADD_CHECK: {
					if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
						continue;
					}
					vector<int> deg = generateDegreeVec(len, maxDegree); // maxDegree > len
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg and coeff not exist.
					uniform_int_distribution<> distDeg(deg[0], maxDegree+1);

					int d = distDeg(gen); // deg[0]~maxDegree+1
					double c = generateCoeffVec(1, maxCoeff)[0]; // not 0
					if (subTestType == TestType::WITH_ADD_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				case TestType::WITH_DELETE_NOCHECK:
				case TestType::WITH_DELETE_CHECK: {
					if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
						continue;
					}
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, get the highest deg
					int d = deg[0];
					double c = -coeff[0];
					if (subTestType == TestType::WITH_DELETE_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				case TestType::WITH_UPDATE_NOCHECK:
				case TestType::WITH_UPDATE_CHECK: {
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg and coeff already exist.
					int d = deg[0];
					double c = coeff[0];
					if (subTestType == TestType::WITH_UPDATE_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				default:
					break;
				}
				break;
			}
			case TestType::ADD_MIDDLE: {
				switch (subTestType) {
				case TestType::WITH_ADD_NOCHECK:
				case TestType::WITH_ADD_CHECK: {
					if (len < 3) {
						continue;
					}
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg and coeff not exist.
					if ((deg[0] - deg.back()) == (len - 1)) { // cannot add in middle
						continue;
					}
					int d = generateOneRandomNumber(deg, deg.back(), deg[0], false); // deg[0]~maxDegree
					double c = generateCoeffVec(1, maxCoeff)[0]; // not 0
					if (subTestType == TestType::WITH_ADD_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);
					break;
				}
				case TestType::WITH_DELETE_NOCHECK:
				case TestType::WITH_DELETE_CHECK: {
					if (len < 3) {
						continue;
					}
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg in them.
					uniform_int_distribution<> distIdx(1, len - 2); // make sure deg.size()-2 >= 1
					int idx = distIdx(gen);
					int d = deg[idx];
					double c = -coeff[idx];
					if (subTestType == TestType::WITH_DELETE_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);
					break;
				}
				case TestType::WITH_UPDATE_NOCHECK:
				case TestType::WITH_UPDATE_CHECK: {
					if (len < 3) {
						continue;
					}
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg and coeff not in them.
					uniform_int_distribution<> distIdx(1, len - 2); // make sure deg.size()-2 >= 1
					int idx = distIdx(gen);
					int d = deg[idx];
					double c = coeff[idx];
					if (subTestType == TestType::WITH_UPDATE_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				default:
					break;
				}
				break;
			}
			case TestType::ADD_LAST: {
				switch (subTestType) {
				case TestType::WITH_ADD_NOCHECK:
				case TestType::WITH_ADD_CHECK: {
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg and coeff not in them.
					if (deg.back() < 1) {
						continue;
					}
					uniform_int_distribution<> distDeg(0, deg.back()-1); // deg: 0 ~ deg.back()-1
					int d = distDeg(gen);
					double c = generateCoeffVec(1, maxCoeff)[0]; // no 0
					if (subTestType == TestType::WITH_ADD_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				case TestType::WITH_DELETE_NOCHECK:
				case TestType::WITH_DELETE_CHECK: {
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg already exist.
					int d = deg.back();
					double c = -coeff.back();
					if (subTestType == TestType::WITH_DELETE_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				case TestType::WITH_UPDATE_NOCHECK:
				case TestType::WITH_UPDATE_CHECK: {
					vector<int> deg = generateDegreeVec(len, maxDegree);
					vector<double> coeff = generateCoeffVec(len, maxCoeff);
					// now, generate deg already exist.
					int d = deg.back();
					double c = coeff.back();
					if (subTestType == TestType::WITH_UPDATE_NOCHECK)
						result = testAddMonoExd(deg, coeff, d, c, false, msg);
					else
						result = testAddMonoExd(deg, coeff, d, c, true, msg);

					break;
				}
				default:
					break;
				}
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

bool TestPoly::testAddPoly(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_DEGREE;
	int maxCoeff = (int)MAX_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::FIRST_MORE_ITEMS: {
				switch (subTestType) {
				case TestType::SECOND_NONZERO_NOCHECK:
				case TestType::SECOND_NONZERO_CHECK: {
					if ((largeSize > (maxDegree + 1)) || (largeSize > (2 * maxCoeff)) || (smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(largeSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(largeSize, maxCoeff);
					vector<int> degSrc = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(smallSize, maxCoeff);

					if (subTestType == TestType::SECOND_NONZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				case TestType::SECOND_ZERO_NOCHECK:
				case TestType::SECOND_ZERO_CHECK: {
					if ((smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc;
					vector<double> coeffSrc;

					if (subTestType == TestType::SECOND_ZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				default:
					break;
				}
				break;
			}
			case TestType::TWO_SAME_SIZE: {
				switch (subTestType) {
				case TestType::BOTH_NONZERO_NOCHECK:
				case TestType::BOTH_NONZERO_CHECK: {
					if ((smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(smallSize, maxCoeff);

					if (subTestType == TestType::BOTH_NONZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				case TestType::BOTH_ZERO_NOCHECK:
				case TestType::BOTH_ZERO_CHECK: {
					vector<int> degDst;
					vector<double> coeffDst;
					vector<int> degSrc;
					vector<double> coeffSrc;

					if (subTestType == TestType::BOTH_ZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				case TestType::RESULT_ZERO_NOCHECK:
				case TestType::RESULT_ZERO_CHECK: {
					if ((smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc = degDst;
					vector<double> coeffSrc = coeffDst;

					for (size_t n = 0; n < coeffSrc.size(); n++)
						coeffSrc[n] = -coeffSrc[n];

					if (subTestType == TestType::RESULT_ZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				default:
					break;
				}
				break;
			}
			case TestType::FIRST_LESS_ITEMS: {
				switch (subTestType) {
				case TestType::FIRST_NONZERO_NOCHECK:
				case TestType::FIRST_NONZERO_CHECK: {
					if ((largeSize > (maxDegree + 1)) || (largeSize > (2 * maxCoeff)) || (smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc = generateDegreeVec(largeSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(largeSize, maxCoeff);

					if (subTestType == TestType::FIRST_NONZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				case TestType::FIRST_ZERO_NOCHECK:
				case TestType::FIRST_ZERO_CHECK: {
					if ((largeSize > (maxDegree + 1)) || (largeSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst;
					vector<double> coeffDst;
					vector<int> degSrc = generateDegreeVec(largeSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(largeSize, maxCoeff);

					if (subTestType == TestType::FIRST_ZERO_NOCHECK)
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testAddPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				default:
					break;
				}
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

bool TestPoly::testMultiplyMono(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_DEGREE;
	int maxCoeff = (int)MAX_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			int len = dist(gen);
			if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
				continue;
			}
			switch (mainTestType) {
			case TestType::MULTIPLY_NONZERO_NOCHECK:
			case TestType::MULTIPLY_NONZERO_CHECK: {
				vector<int> deg = generateDegreeVec(len, maxDegree);
				vector<double> coeff = generateCoeffVec(len, maxCoeff);
				uniform_int_distribution<> distDeg(0, maxDegree);
				int d = distDeg(gen); // 0~maxDegree
				double c = generateCoeffVec(1, maxCoeff)[0]; // not 0

				if (mainTestType == TestType::MULTIPLY_NONZERO_NOCHECK)
					result = testMultiplyMonoExd(deg, coeff, d, c, false, msg);
				else
					result = testMultiplyMonoExd(deg, coeff, d, c, true, msg);

				break;
			}
			case TestType::MULTIPLY_ZERO_NOCHECK:
			case TestType::MULTIPLY_ZERO_CHECK: {
				vector<int> deg = generateDegreeVec(len, maxDegree);
				vector<double> coeff = generateCoeffVec(len, maxCoeff);
				uniform_int_distribution<> distDeg(0, maxDegree);
				int d = distDeg(gen); // 0~maxDegree
				double c = 0;

				if (mainTestType == TestType::MULTIPLY_ZERO_NOCHECK)
					result = testMultiplyMonoExd(deg, coeff, d, c, false, msg);
				else
					result = testMultiplyMonoExd(deg, coeff, d, c, true, msg);

				// zero * zero
				deg.clear();
				coeff.clear();

				bool result2 = false;
				if (mainTestType == TestType::MULTIPLY_ZERO_NOCHECK)
					result2 = testMultiplyMonoExd(deg, coeff, d, c, false, msg);
				else
					result2 = testMultiplyMonoExd(deg, coeff, d, c, true, msg);

				result = result && result2;

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

bool TestPoly::testMultiplyPoly(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_DEGREE;
	int maxCoeff = (int)MAX_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> distSmall(1, sizes[j]);
			int smallSize = distSmall(gen);
			uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
			int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

			switch (mainTestType) {
			case TestType::FIRST_MORE_ITEMS: {
				switch (subTestType) {
				case TestType::SECOND_NONZERO_NOCHECK:
				case TestType::SECOND_NONZERO_CHECK: {
					if ((largeSize > (maxDegree + 1)) || (largeSize > (2 * maxCoeff)) || (smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(largeSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(largeSize, maxCoeff);
					vector<int> degSrc = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(smallSize, maxCoeff);

					if (subTestType == TestType::SECOND_NONZERO_NOCHECK)
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				case TestType::SECOND_ZERO_NOCHECK:
				case TestType::SECOND_ZERO_CHECK: {
					if ((smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc;
					vector<double> coeffSrc;

					if (subTestType == TestType::SECOND_ZERO_NOCHECK)
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				default:
					break;
				}
				break;
			}
			case TestType::TWO_SAME_SIZE: {
				switch (subTestType) {
				case TestType::BOTH_NONZERO_NOCHECK:
				case TestType::BOTH_NONZERO_CHECK: {
					if ((smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(smallSize, maxCoeff);

					if (subTestType == TestType::BOTH_NONZERO_NOCHECK)
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				case TestType::BOTH_ZERO_NOCHECK:
				case TestType::BOTH_ZERO_CHECK: {
					vector<int> degDst;
					vector<double> coeffDst;
					vector<int> degSrc;
					vector<double> coeffSrc;

					if (subTestType == TestType::BOTH_ZERO_NOCHECK)
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);

					break;
				}
				default:
					break;
				}
				break;
			}
			case TestType::FIRST_LESS_ITEMS: {
				switch (subTestType) {
				case TestType::FIRST_NONZERO_NOCHECK:
				case TestType::FIRST_NONZERO_CHECK: {
					if ((largeSize > (maxDegree + 1)) || (largeSize > (2 * maxCoeff)) || (smallSize > (maxDegree + 1)) || (smallSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst = generateDegreeVec(smallSize, maxDegree);
					vector<double> coeffDst = generateCoeffVec(smallSize, maxCoeff);
					vector<int> degSrc = generateDegreeVec(largeSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(largeSize, maxCoeff);

					if (subTestType == TestType::FIRST_NONZERO_NOCHECK)
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);
					break;
				}
				case TestType::FIRST_ZERO_NOCHECK:
				case TestType::FIRST_ZERO_CHECK: {
					if ((largeSize > (maxDegree + 1)) || (largeSize > (2 * maxCoeff))) {
						continue;
					}
					vector<int> degDst;
					vector<double> coeffDst;
					vector<int> degSrc = generateDegreeVec(largeSize, maxDegree);
					vector<double> coeffSrc = generateCoeffVec(largeSize, maxCoeff);

					if (subTestType == TestType::FIRST_ZERO_NOCHECK)
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, false, msg);
					else
						result = testMultiplyPolyExd(degDst, coeffDst, degSrc, coeffSrc, true, msg);
					break;
				}
				default:
					break;
				}
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

bool TestPoly::testDuplicate(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_DEGREE;
	int maxCoeff = (int)MAX_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			switch (mainTestType) {
			case TestType::DUPLICATE_NONZERO_NOCHECK:{
				uniform_int_distribution<> dist(1, sizes[j]);
				int len = dist(gen);
				if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
					continue;
				}
				vector<int> deg = generateDegreeVec(len, maxDegree);
				vector<double> coeff = generateCoeffVec(len, maxCoeff);
				result = testDuplicateExd(deg, coeff, false, msg);
				break;
			}
			case TestType::DUPLICATE_NONZERO_CHECK: {
				uniform_int_distribution<> dist(1, sizes[j]);
				int len = dist(gen);
				if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
					continue;
				}
				vector<int> deg = generateDegreeVec(len, maxDegree);
				vector<double> coeff = generateCoeffVec(len, maxCoeff);
				result = testDuplicateExd(deg, coeff, true, msg);
				break;
			}
			case TestType::DUPLICATE_ZERO_NOCHECK: {
				vector<int> deg;
				vector<double> coeff;
				result = testDuplicateExd(deg, coeff, false, msg);
				break;
			}
			case TestType::DUPLICATE_ZERO_CHECK: {
				vector<int> deg;
				vector<double> coeff;
				result = testDuplicateExd(deg, coeff, true, msg);
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

bool TestPoly::testEvaluate(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	int maxDegree = MAX_EVAL_DEGREE;
	int maxCoeff = (int)MAX_EVAL_COEFF;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			switch (mainTestType) {
			case TestType::EVALUATE_NONZERO: {
				uniform_int_distribution<> dist(1, sizes[j]);
				int len = dist(gen);
				uniform_int_distribution<> distVal(0, 4);
				int val = distVal(gen);
				if ((len > (maxDegree + 1)) || (len > (2 * maxCoeff))) {
					continue;
				}
				vector<int> deg = generateDegreeVec(val, maxDegree);
				vector<double> coeff = generateCoeffVec(val, maxCoeff);

				result = testEvaluateExd(deg, coeff, val, msg);
				break;
			}
			case TestType::EVALUATE_ZERO: {
				vector<int> deg;
				vector<double> coeff;
				uniform_int_distribution<> distVal(0, 4);
				int val = distVal(gen);
				result = testEvaluateExd(deg, coeff, val, msg);

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

bool TestPoly::testConstructorExd(vector<int> deg, vector<double> coeff, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		Poly p(deg, coeff);

		// check the sorted linked list
		vector<int> degGet;
		vector<double> coeffGet;

		PolyNode* pn = p.getHead();

		if (pn != NULL) {
			while (pn->next != NULL) {
				pn = pn->next;
				degGet.push_back(pn->deg);
				coeffGet.push_back(pn->coeff);
			}
		}
		else {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "No dummy header" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
		}

		if (passFlag == true && (deg != degGet || coeff != coeffGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input  degree= " << vector2String(deg) << endl;
			cerr << "output degree= " << vector2String(degGet) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "output coeff= " << vector2String(coeffGet) << endl;
		}

		if (checkFlag) {
			// check the getDegree() and getTermsNo()
			int getDegGet = p.getDegree();
			int getTermsNoGet = p.getTermsNo();

			int getDegExp = 0;
			int getTermsNoExp = 0;

			if (deg.size() == 0) {
				getDegExp = -1;
				getTermsNoExp = 0;
			}
			else {
				getDegExp = deg[0];
				getTermsNoExp = deg.size();
			}

			if (getDegGet != getDegExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getDegree error" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				cerr << "Output   getDegree= " << getDegGet << endl;
				cerr << "Expected getDegree= " << getDegExp << endl;
			}

			if (getTermsNoGet != getTermsNoExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getTermsNo error" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				cerr << "Output   getTermsNO= " << getTermsNoGet << endl;
				cerr << "Expected getTermsNO= " << getTermsNoExp << endl;
			}
		}

	}
	catch (const std::exception& e){
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
	}
	catch (...){
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
	}

	return passFlag;
}

bool TestPoly::testAddMonoExd(vector<int> deg, vector<double> coeff, int d, double c, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		Poly p(deg, coeff);

		p.addMono(d, c);

		vector<int> degExp=deg;
		vector<double> coeffExp=coeff;

		for (size_t i = 0; i < deg.size(); i++) {
			if (deg[i] < d) {
				if (i == 0) {
					degExp.insert(degExp.begin(), d);
					coeffExp.insert(coeffExp.begin(), c);
				}
				else {
					degExp.insert(degExp.begin() + i, d);
					coeffExp.insert(coeffExp.begin() + i, c);
				}
				break;
			}
			else if (deg[i] == d) {
				coeffExp[i] += c;
				if (coeffExp[i] == 0) {
					degExp.erase(degExp.begin() + i);
					coeffExp.erase(coeffExp.begin() + i);
				}
				break;
			}
			else if (deg[i] > d) {
				if (i == deg.size() - 1) {
					degExp.push_back(d);
					coeffExp.push_back(c);
					break;
				}
			}
		}

		vector<int> degGet;
		vector<double> coeffGet;

		PolyNode* pn = p.getHead();

		if (pn != NULL) {
			while (pn->next != NULL) {
				pn = pn->next;
				degGet.push_back(pn->deg);
				coeffGet.push_back(pn->coeff);
			}
		}
		else {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "No dummy header" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "Input d= " << d << endl;
			cerr << "Input c= " << c << endl;
		}

		if (passFlag == true && (degExp != degGet || coeffExp != coeffGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "Input d= " << d << endl;
			cerr << "Input c= " << c << endl;
			cerr << "Output   degree= " << vector2String(degGet) << endl;
			cerr << "Expected degree= " << vector2String(degExp) << endl;
			cerr << "Output   coeff= " << vector2String(coeffGet) << endl;
			cerr << "Expected coeff= " << vector2String(coeffExp) << endl;
		}

		if (checkFlag) {
			// check the getDegree() and getTermsNo()
			int getDegGet = p.getDegree();
			int getTermsNoGet = p.getTermsNo();

			int getDegExp = 0;
			int getTermsNoExp = 0;

			if (degExp.size() == 0) {
				getDegExp = -1;
				getTermsNoExp = 0;
			}
			else {
				getDegExp = degExp[0];
				getTermsNoExp = degExp.size();
			}

			if (getDegGet != getDegExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getDegree error" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				cerr << "Input d= " << d << endl;
				cerr << "Input c= " << c << endl;
				cerr << "Output   getDegree= " << getDegGet << endl;
				cerr << "Expected getDegree= " << getDegExp << endl;
			}

			if (getTermsNoGet != getTermsNoExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getTermsNo error" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				cerr << "Input d= " << d << endl;
				cerr << "Input c= " << c << endl;
				cerr << "Output   getTermsNO= " << getTermsNoGet << endl;
				cerr << "Expected getTermsNO= " << getTermsNoExp << endl;
			}
		}

	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
		cerr << "Input d= " << d << endl;
		cerr << "Input c= " << c << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
		cerr << "Input d= " << d << endl;
		cerr << "Input c= " << c << endl;
	}

	return passFlag;
}

bool TestPoly::testAddPolyExd(vector<int> degDst, vector<double> coeffDst, vector<int> degSrc, vector<double> coeffSrc, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		Poly pDst(degDst, coeffDst);
		Poly pSrc(degSrc, coeffSrc);

		pDst.addPoly(pSrc);

		vector<int> degExp;
		vector<double> coeffExp;

		size_t s = 0, d = 0;

		while (s < degSrc.size() && d < degDst.size()) {
			if (degSrc[s] > degDst[d]) {
				degExp.push_back(degSrc[s]);
				coeffExp.push_back(coeffSrc[s]);
				s++;
			}
			else if (degSrc[s] == degDst[d]) {
				if ((coeffSrc[s] + coeffDst[d]) != 0) {
					degExp.push_back(degSrc[s]);
					coeffExp.push_back(coeffSrc[s] + coeffDst[d]);
				}
				s++;
				d++;
			}
			else if (degSrc[s] < degDst[d]) {
				degExp.push_back(degDst[d]);
				coeffExp.push_back(coeffDst[d]);
				d++;
			}
		}

		while (s < degSrc.size()) {
			degExp.push_back(degSrc[s]);
			coeffExp.push_back(coeffSrc[s]);
			s++;
		}

		while (d < degDst.size()) {
			degExp.push_back(degDst[d]);
			coeffExp.push_back(coeffDst[d]);
			d++;
		}

		vector<int> degGet;
		vector<double> coeffGet;

		PolyNode* pn = pDst.getHead();

		if (pn != NULL) {
			while (pn->next != NULL) {
				pn = pn->next;
				degGet.push_back(pn->deg);
				coeffGet.push_back(pn->coeff);
			}
		}
		else {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "No dummy header" << endl;
			cerr << "Input destination degree= " << vector2String(degDst) << endl;
			cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
			cerr << "Input source degree= " << vector2String(degSrc) << endl;
			cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
		}

		if (passFlag == true && (degExp != degGet || coeffExp != coeffGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input destination degree= " << vector2String(degDst) << endl;
			cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
			cerr << "Input source degree= " << vector2String(degSrc) << endl;
			cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
			cerr << "Output   degree= " << vector2String(degGet) << endl;
			cerr << "Expected degree= " << vector2String(degExp) << endl;
			cerr << "Output   coeff= " << vector2String(coeffGet) << endl;
			cerr << "Expected coeff= " << vector2String(coeffExp) << endl;
		}

		if (checkFlag) {
			// check the getDegree() and getTermsNo()
			int getDegGet = pDst.getDegree();
			int getTermsNoGet = pDst.getTermsNo();

			int getDegExp = 0;
			int getTermsNoExp = 0;

			if (degExp.size() == 0) {
				getDegExp = -1;
				getTermsNoExp = 0;
			}
			else {
				getDegExp = degExp[0];
				getTermsNoExp = degExp.size();
			}

			if (getDegGet != getDegExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getDegree error" << endl;
				cerr << "Input destination degree= " << vector2String(degDst) << endl;
				cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
				cerr << "Input source degree= " << vector2String(degSrc) << endl;
				cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
				cerr << "Output   getDegree= " << getDegGet << endl;
				cerr << "Expected getDegree= " << getDegExp << endl;
			}

			if (getTermsNoGet != getTermsNoExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getTermsNo error" << endl;
				cerr << "Input destination degree= " << vector2String(degDst) << endl;
				cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
				cerr << "Input source degree= " << vector2String(degSrc) << endl;
				cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
				cerr << "Output   getTermsNO= " << getTermsNoGet << endl;
				cerr << "Expected getTermsNO= " << getTermsNoExp << endl;
			}
		}

	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input destination degree= " << vector2String(degDst) << endl;
		cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
		cerr << "Input source degree= " << vector2String(degSrc) << endl;
		cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input destination degree= " << vector2String(degDst) << endl;
		cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
		cerr << "Input source degree= " << vector2String(degSrc) << endl;
		cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
	}

	return passFlag;
}

bool TestPoly::testMultiplyMonoExd(vector<int> deg, vector<double> coeff, int d, double c, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		Poly p(deg, coeff); // deg can be empty

		p.multiplyMono(d,c);

		vector<int> degExp=deg;
		vector<double> coeffExp=coeff;

		if (c == 0) {
			degExp.clear();
			coeffExp.clear();
		}
		else {
			for (size_t i = 0; i < deg.size(); i++) {
				degExp[i] += d;
				coeffExp[i] *= c;
			}
		}

		vector<int> degGet;
		vector<double> coeffGet;

		PolyNode* pn = p.getHead();

		if (pn != NULL) {
			while (pn->next != NULL) {
				pn = pn->next;
				degGet.push_back(pn->deg);
				coeffGet.push_back(pn->coeff);
			}
		}
		else {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "No dummy header" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "Input d= " << d << endl;
			cerr << "Input c= " << c << endl;
		}

		if (passFlag == true && (degExp != degGet || coeffExp != coeffGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "Input d= " << d << endl;
			cerr << "Input c= " << c << endl;
			cerr << "Output   degree= " << vector2String(degGet) << endl;
			cerr << "Expected degree= " << vector2String(degExp) << endl;
			cerr << "Output   coeff= " << vector2String(coeffGet) << endl;
			cerr << "Expected coeff= " << vector2String(coeffExp) << endl;
		}

		if (checkFlag) {
			// check the getDegree() and getTermsNo()
			int getDegGet = p.getDegree();
			int getTermsNoGet = p.getTermsNo();

			int getDegExp = 0;
			int getTermsNoExp = 0;

			if (degExp.size() == 0) {
				getDegExp = -1;
				getTermsNoExp = 0;
			}
			else {
				getDegExp = degExp[0];
				getTermsNoExp = degExp.size();
			}

			if (getDegGet != getDegExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getDegree error" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				cerr << "Input d= " << d << endl;
				cerr << "Input c= " << c << endl;
				cerr << "Output   getDegree= " << getDegGet << endl;
				cerr << "Expected getDegree= " << getDegExp << endl;
			}

			if (getTermsNoGet != getTermsNoExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getTermsNo error" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				cerr << "Input d= " << d << endl;
				cerr << "Input c= " << c << endl;
				cerr << "Output   getTermsNO= " << getTermsNoGet << endl;
				cerr << "Expected getTermsNO= " << getTermsNoExp << endl;
			}
		}

	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
		cerr << "Input d= " << d << endl;
		cerr << "Input c= " << c << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
		cerr << "Input d= " << d << endl;
		cerr << "Input c= " << c << endl;
	}

	return passFlag;
}

bool TestPoly::testMultiplyPolyExd(vector<int> degDst, vector<double> coeffDst, vector<int> degSrc, vector<double> coeffSrc, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		Poly pDst(degDst, coeffDst);
		Poly pSrc(degSrc, coeffSrc);

		pDst.multiplyPoly(pSrc);

		// check the sorted linked list
		vector<int> degExp;
		vector<double> coeffExp;

		for (size_t i = 0; i < degSrc.size(); i++) {
			vector<int> degTmp = degDst;
			vector<double> coeffTmp = coeffDst;
			for (size_t j = 0; j < degDst.size(); j++) {
				degTmp[j] += degSrc[i];
				coeffTmp[j] *= coeffSrc[i];
			}
			addVector(degExp, coeffExp, degTmp, coeffTmp);
		}

		vector<int> degGet;
		vector<double> coeffGet;

		PolyNode* pn = pDst.getHead();

		if (pn != NULL) {
			while (pn->next != NULL) {
				pn = pn->next;
				degGet.push_back(pn->deg);
				coeffGet.push_back(pn->coeff);
			}
		}
		else {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "No dummy header" << endl;
			cerr << "Input destination degree= " << vector2String(degDst) << endl;
			cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
			cerr << "Input source degree= " << vector2String(degSrc) << endl;
			cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
		}

		if (passFlag == true && (degExp != degGet || coeffExp != coeffGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input destination degree= " << vector2String(degDst) << endl;
			cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
			cerr << "Input source degree= " << vector2String(degSrc) << endl;
			cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
			cerr << "Output   degree= " << vector2String(degGet) << endl;
			cerr << "Expected degree= " << vector2String(degExp) << endl;
			cerr << "Output   coeff= " << vector2String(coeffGet) << endl;
			cerr << "Expected coeff= " << vector2String(coeffExp) << endl;
		}

		if (checkFlag) {
			// check the getDegree() and getTermsNo()
			int getDegGet = pDst.getDegree();
			int getTermsNoGet = pDst.getTermsNo();

			int getDegExp = 0;
			int getTermsNoExp = 0;

			if (degExp.size() == 0) {
				getDegExp = -1;
				getTermsNoExp = 0;
			}
			else {
				getDegExp = degExp[0];
				getTermsNoExp = degExp.size();
			}

			if (getDegGet != getDegExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getDegree error" << endl;
				cerr << "Input destination degree= " << vector2String(degDst) << endl;
				cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
				cerr << "Input source degree= " << vector2String(degSrc) << endl;
				cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
				cerr << "Output   getDegree= " << getDegGet << endl;
				cerr << "Expected getDegree= " << getDegExp << endl;
			}

			if (getTermsNoGet != getTermsNoExp && passFlag == true) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "getTermsNo error" << endl;
				cerr << "Input destination degree= " << vector2String(degDst) << endl;
				cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
				cerr << "Input source degree= " << vector2String(degSrc) << endl;
				cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
				cerr << "Output   getTermsNO= " << getTermsNoGet << endl;
				cerr << "Expected getTermsNO= " << getTermsNoExp << endl;
			}
		}

	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input destination degree= " << vector2String(degDst) << endl;
		cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
		cerr << "Input source degree= " << vector2String(degSrc) << endl;
		cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input destination degree= " << vector2String(degDst) << endl;
		cerr << "Input destination  coeff= " << vector2String(coeffDst) << endl;
		cerr << "Input source degree= " << vector2String(degSrc) << endl;
		cerr << "Input source  coeff= " << vector2String(coeffSrc) << endl;
	}

	return passFlag;
}

bool TestPoly::testDuplicateExd(vector<int> deg, vector<double> coeff, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		Poly pSrc(deg, coeff);
		Poly pDst;
		pSrc.duplicate(pDst);

		vector<int> degSrcGet;
		vector<double> coeffSrcGet;

		PolyNode* ps = pSrc.getHead();

		if (ps != NULL) {
			while (ps->next != NULL) {
				ps = ps->next;
				degSrcGet.push_back(ps->deg);
				coeffSrcGet.push_back(ps->coeff);
			}
		}

		vector<int> degDstGet;
		vector<double> coeffDstGet;
		PolyNode* pd = pDst.getHead();
		if (pd != NULL) {
			while (pd->next != NULL) {
				pd = pd->next;
				degDstGet.push_back(pd->deg);
				coeffDstGet.push_back(pd->coeff);
			}
		}

		if ((degDstGet != degSrcGet) || (coeffDstGet != coeffSrcGet) || (degDstGet != deg) || (coeffDstGet != coeff)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "Source    degree= " << vector2String(degSrcGet) << endl;
			cerr << "Duplicate degree= " << vector2String(degDstGet) << endl;
			cerr << "Source    coeff= " << vector2String(coeffSrcGet) << endl;
			cerr << "Duplicate coeff= " << vector2String(coeffDstGet) << endl;
		}
		else {
			ps = pSrc.getHead();
			pd = pDst.getHead();
			// check the header address
			if (ps == NULL || pd == NULL) {
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "No dummy header" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				passFlag = false;
			}
			else if (ps == pd && ps != NULL) {
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Same address for dummy header" << endl;
				cerr << "Input degree= " << vector2String(deg) << endl;
				cerr << "Input  coeff= " << vector2String(coeff) << endl;
				passFlag = false;
			}
			// check the element address
			while (passFlag == true && ps != NULL && ps->next != NULL && pd->next != NULL) {
				ps = ps->next;
				pd = pd->next;
				if (ps == pd && ps != NULL) {
					passFlag = false;
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "Input degree= " << vector2String(deg) << endl;
					cerr << "Input  coeff= " << vector2String(coeff) << endl;
					cerr << "Same address for item:" << endl;
					cerr << "Source    degree= " << ps->deg << endl;
					cerr << "Duplicate degree= " << pd->deg << endl;
					cerr << "Source    coeff = " << ps->coeff << endl;
					cerr << "Duplicate coeff = " << pd->coeff << endl;
				}
			}
			if (checkFlag) {
				// check the getDegree()
				int getDegSrc = pSrc.getDegree();
				int getDegDst = pDst.getDegree();
				if (((getDegSrc != getDegDst) || (getDegSrc < -1)) && (passFlag == true)) {
					passFlag = false;
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "Not duplicate degree or invalid degree" << endl;
					cerr << "Input degree= " << vector2String(deg) << endl;
					cerr << "Input  coeff= " << vector2String(coeff) << endl;
					cerr << "Source    degree= " << getDegSrc << endl;
					cerr << "Duplicate degree= " << getDegDst << endl;
				}

				// check the getTermsNo()
				int getTermsNoSrc = pSrc.getTermsNo();
				int getTermsNoDst = pDst.getTermsNo();
				if (((getTermsNoSrc != getTermsNoDst) || (getTermsNoSrc < 0)) && (passFlag == true)) {
					passFlag = false;
					cerr << "Error in " << msg << " ->" << endl;
					cerr << "Not duplicate terms NO. or invalid terms NO." << endl;
					cerr << "Input degree= " << vector2String(deg) << endl;
					cerr << "Input  coeff= " << vector2String(coeff) << endl;
					cerr << "Source    getTermsNO= " << getTermsNoSrc << endl;
					cerr << "Duplicate getTermsNO= " << getTermsNoDst << endl;
				}
			}

		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
	}

	return passFlag;
}

bool TestPoly::testEvaluateExd(vector<int> deg, vector<double> coeff, int num, string msg)
{
	bool passFlag = true;
	try {
		Poly p(deg, coeff);

		vector<int> degGet;
		vector<double> coeffGet;

		double evalGet = p.evaluate(num);

		double evalExp = 0;

		for (size_t i = 0; i < deg.size(); i++) {
			evalExp += (coeff[i] * std::pow((double)num, deg[i]));
		}

		if (evalExp != evalGet) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input degree= " << vector2String(deg) << endl;
			cerr << "Input  coeff= " << vector2String(coeff) << endl;
			cerr << "Input    val= " << num << endl;
			cerr << "Output   evaluation= " << evalGet << endl;
			cerr << "Expected evaluation= " << evalExp << endl;
		}

	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
		cerr << "Input  val= " << num << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input degree= " << vector2String(deg) << endl;
		cerr << "Input  coeff= " << vector2String(coeff) << endl;
		cerr << "Input  val= " << num << endl;
	}

	return passFlag;
}

vector<int> TestPoly::generateDegreeVec(int len, int maxDegree)
{
	if (len > (maxDegree + 1))
		throw std::invalid_argument("len > (maxDegree + 1)");

	uniform_int_distribution<> dist(0, maxDegree); // degree should be non-negative

	std::set<int, std::greater<int>> numSet;

	while (numSet.size() < len)
	{
		int num = dist(gen);
		numSet.insert(num);
	}

	vector<int> numVec(numSet.begin(), numSet.end());
	return numVec;
}

vector<double> TestPoly::generateCoeffVec(int len, int maxCoeff)
{
	if (len > (2*maxCoeff))
		throw std::invalid_argument("len > (2*maxCoeff)");

	uniform_int_distribution<> dist(-maxCoeff, maxCoeff);

	vector<double> numVec;

	while (numVec.size() < len)
	{
		int num = dist(gen);
		if (num == 0) { // coeff cannot be zero
			continue;
		}
		numVec.push_back(num);
	}

	return numVec;
}

int TestPoly::generateOneRandomNumber(vector<int> numVec, int  minDegree, int maxDegree, bool isInFlag)
{
	uniform_int_distribution<> dist(minDegree, maxDegree);

	std::set<int, std::greater<int>> numSet(numVec.begin(), numVec.end());

	int num = 0;

	if (isInFlag) {
		do {
			num = dist(gen);
		} while (!numSet.count(num)); // not in the set;
	}
	else {
		do {
			num = dist(gen);
		} while (numSet.count(num)); // in the set;
	}

	return num;
}

string TestPoly::vector2String(vector<int> num)
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

string TestPoly::vector2String(vector<double> num)
{
	std::ostringstream oss;
	oss << "[";

	if (num.size() == 1) {
		oss << num[0];
	}
	else if (num.size() > 1) {
		std::copy(num.begin(), num.end() - 1, std::ostream_iterator<double>(oss, ","));
		oss << num.back();
	}

	oss << "]";

	return oss.str();
}

string TestPoly::poly2String(Poly p)
{
	PolyNode* pn = p.getHead();
	std::stringstream result;
	result << "degree=" << p.getDegree();
	while (pn->next != NULL) {
		pn = pn->next;
		result << ";a(" << pn->deg << ")=" << pn->coeff;
	}
	return result.str();
}

void TestPoly::addVector(vector<int>& degDst, vector<double>& coeffDst, vector<int> degSrc, vector<double> coeffSrc)
{
	vector<int> degExp;
	vector<double> coeffExp;

	if (degDst.size() == 0) {
		degDst = degSrc;
		coeffDst = coeffSrc;
		return;
	}
	else if (degSrc.size() == 0) {
		return;
	}

	size_t s = 0, d = 0;

	while (s < degSrc.size() && d < degDst.size()) {
		if (degSrc[s] > degDst[d]) {
			degExp.push_back(degSrc[s]);
			coeffExp.push_back(coeffSrc[s]);
			s++;
		}
		else if (degSrc[s] == degDst[d]) {
			if ((coeffSrc[s] + coeffDst[d]) != 0) {
				degExp.push_back(degSrc[s]);
				coeffExp.push_back(coeffSrc[s] + coeffDst[d]);
			}
			s++;
			d++;
		}
		else if (degSrc[s] < degDst[d]) {
			degExp.push_back(degDst[d]);
			coeffExp.push_back(coeffDst[d]);
			d++;
		}
	}

	while (s < degSrc.size()) {
		degExp.push_back(degSrc[s]);
		coeffExp.push_back(coeffSrc[s]);
		s++;
	}

	while (d < degDst.size()) {
		degExp.push_back(degDst[d]);
		coeffExp.push_back(coeffDst[d]);
		d++;
	}

	degDst = degExp;
	coeffDst = coeffExp;
}
