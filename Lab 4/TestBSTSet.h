#ifndef TESTBSTSET_H_
#define TESTBSTSET_H_

#include "BSTSet.h"
#include "TNode.h"
#include <vector>
#include <string>
#include <random>
#include <set>
using namespace std;

enum class TestType
{
	CONSTRUCTOR_NO_REPITITION,
	CONSTRUCTOR_WITH_REPITITION,
	ISIN_NOT_IN_EMPTY,
	ISIN_NOT_IN_NONEMPTY,
	ISIN_IN_NONEMPTY,
	ADD_IN_EMPTY,
	ADD_IN_NONEMPTY,
	ADD_NOTHING_IN_NONEMPTY,
	REMOVE_NOTHING_IN_EMPTY,
	REMOVE_IN_NONEMPTY,
	REMOVE_NOTHING_IN_NONEMPTY,
	UNION_EMPTY,
	UNION_COMMON_ELEMENTS,
	UNION_NO_COMMON_ELEMENTS,
	INTERSECTION_EMPTY,
	INTERSECTION_COMMON_ELEMENTS,
	INTERSECTION_NO_COMMON_ELEMENTS,
	DIFFERENCE_EMPTY,
	DIFFERENCE_COMMON_ELEMENTS,
	DIFFERENCE_NO_COMMON_ELEMENTS,
	SIZE_EMPTY,
	SIZE_NO_REPETITIONS,
	SIZE_WITH_REPETITIONS,
	HEIGHT_EMPTY,
	HEIGHT_NO_REPETITIONS,
	HEIGHT_WITH_REPETITIONS,
	PRINTNONREC_EMPTY,
	PRINTNONREC_NO_REPETITIONS,
	PRINTNONREC_WITH_REPETITIONS,
	PRINTLEVELORDER_EMPTY,
	PRINTLEVELORDER_NO_REPETITIONS,
	PRINTLEVELORDER_WITH_REPETITIONS,
	BONUS_INCREASE_DECREASE,
	BONUS_RANDOM,
	BONUS_UNION,
	BONUS_INTERSECTION,
	BONUS_DIFFERENCE
};

class TestBSTSet
{
private:
	int MAX_RUN = 50;
	vector<int> MAX_SIZE_ARRAY = { 1, 5, 10, 50};
	std::mt19937 gen;

public:
	TestBSTSet();
	TestBSTSet(int max_run, vector<int> max_size_array);
	void testConstructor(double& total, double& full);
	void testIsIn(double& total, double& full);
	void testAdd(double& total, double& full);
	void testRemove(double& total, double& full);
	void testUnion(double& total, double& full);
	void testIntersection(double& total, double& full);
	void testDifference(double& total, double& full);
	void testSize(double& total, double& full);
	void testHeight(double& total, double& full);
	void testPrintNonRec(double& total, double& full);
	void testPrintLevelOrder(double& total, double& full);
	void testBonus(double& total, double& full);

private:
	bool testConstructor(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testIsIn(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testAdd(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testRemove(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testUnion(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testIntersection(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testDifference(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testSize(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testHeight(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testPrintNonRec(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testPrintLevelOrder(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testBonus(vector<int> sizes, int maxRun, TestType mainTestType, string msg);

	bool testConstructorExd(vector<int> input, bool checkFlag, string msg);
	bool testIsInExd(vector<int> input, int num, bool checkFlag, string msg);
	bool testAddExd(vector<int> input, int num, bool checkFlag, string msg);
	bool testRemoveExd(vector<int> input, int num, bool checkFlag, string msg);
	bool testUnionExd(vector<int> input1, vector<int> input2, bool checkFlag, string msg);
	bool testIntersectionExd(vector<int> input1, vector<int> input2, bool checkFlag, string msg);
	bool testDifferenceExd(vector<int> input1, vector<int> input2, bool checkFlag, string msg);
	bool testSizeExd(vector<int> input, bool checkFlag, string msg);
	bool testHeightExd(vector<int> input, bool checkFlag, string msg);
	bool testPrintNonRecExd(vector<int> input, bool checkFlag, string msg);
	bool testPrintLevelOrderExd(vector<int> input, bool checkFlag, string msg);
	bool testBonusExd(vector<int> input, bool checkFlag, string msg);

	string set2String(std::set<int>& s);
	string vector2String(vector<int> num);
	string printBSTSet2String(BSTSet& s);
	string printNonRec2String(BSTSet& s);
	string printLevelOrder2String(BSTSet& s);
	void getLevelElements(TNode* subroot, vector<vector<int>>& res, int h);
	string getLevelOrder(BSTSet& s, int size, int& h);
	vector<int> generateWithRepetitionVec(int start, int end, int repLen);

};

#endif /* TESTBSTSET_H_ */
