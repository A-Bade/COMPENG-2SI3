#ifndef TESTPOLY_H_
#define TESTPOLY_H_

#include "Poly.h"
#include <vector>
#include <string>
#include <random>
using namespace std;

enum class TestType
{
	CONSTRUCTOR_DUMMY_HEADER,
	CONSTRUCTOR_DEGREE_TERMSNO,
	CONSTRUCTOR_PARAMETERS_CHECK,
	CONSTRUCTOR_PARAMETERS_NOCHECK,
	ADD_FIRST,
	ADD_MIDDLE,
	ADD_LAST,
	WITH_ADD_NOCHECK,
	WITH_ADD_CHECK,
	WITH_DELETE_NOCHECK,
	WITH_DELETE_CHECK,
	WITH_UPDATE_NOCHECK,
	WITH_UPDATE_CHECK,
	FIRST_MORE_ITEMS,
	TWO_SAME_SIZE,
	FIRST_LESS_ITEMS,
	SECOND_NONZERO_NOCHECK,
	SECOND_NONZERO_CHECK,
	SECOND_ZERO_NOCHECK,
	SECOND_ZERO_CHECK,
	BOTH_NONZERO_NOCHECK,
	BOTH_NONZERO_CHECK,
	BOTH_ZERO_NOCHECK,
	BOTH_ZERO_CHECK,
	RESULT_ZERO_NOCHECK,
	RESULT_ZERO_CHECK,
	FIRST_NONZERO_NOCHECK,
	FIRST_NONZERO_CHECK,
	FIRST_ZERO_NOCHECK,
	FIRST_ZERO_CHECK,
	MULTIPLY_NONZERO_NOCHECK,
	MULTIPLY_NONZERO_CHECK,
	MULTIPLY_ZERO_NOCHECK,
	MULTIPLY_ZERO_CHECK,
	DUPLICATE_NONZERO_NOCHECK,
	DUPLICATE_NONZERO_CHECK,
	DUPLICATE_ZERO_NOCHECK,
	DUPLICATE_ZERO_CHECK,
	EVALUATE_NONZERO,
	EVALUATE_ZERO,
};

class TestPoly
{
private:
	int MAX_DEGREE = 1000;
	double MAX_COEFF = 100;
	int MAX_EVAL_DEGREE = 20;
	double MAX_EVAL_COEFF = 10;
	int MAX_RUN = 50;
	vector<int> MAX_SIZE_ARRAY = { 1, 5, 10 };
	std::mt19937 gen;

public:
	TestPoly();
	TestPoly(int max_degree, double max_coeff, int max_eval_degree, double max_eval_coeff, int max_run, vector<int> max_size_array);
	void testConstructorDefault(double& total, double& full);
	void testConstructorParameters(double& total, double& full);
	void testAddMono(double& total, double& full);
	void testAddPoly(double& total, double& full);
	void testMultiplyMono(double& total, double& full);
	void testMultiplyPoly(double& total, double& full);
	void testDuplicate(double& total, double& full);
	void testEvaluate(double& total, double& full);

public:
	bool testConstructorDefault(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testConstructorParameters(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testAddMono(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	bool testAddPoly(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	bool testMultiplyMono(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testMultiplyPoly(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	bool testDuplicate(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testEvaluate(vector<int> sizes, int maxRun, TestType mainTestType, string msg);

	bool testConstructorExd(vector<int> deg, vector<double> coeff, bool checkFlag, string msg);
	bool testAddMonoExd(vector<int> deg, vector<double> coeff, int d, double c, bool checkFlag, string msg);
	bool testAddPolyExd(vector<int> degSrc, vector<double> coeffSrc, vector<int> degDst, vector<double> coeffDst, bool checkFlag, string msg);
	bool testMultiplyMonoExd(vector<int> deg, vector<double> coeff, int d, double c, bool checkFlag, string msg);
	bool testMultiplyPolyExd(vector<int> degDst, vector<double> coeffDst, vector<int> degSrc, vector<double> coeffSrc, bool checkFlag, string msg);
	bool testDuplicateExd(vector<int> deg, vector<double> coeff, bool checkFlag, string msg);
	bool testEvaluateExd(vector<int> deg, vector<double> coeff, int num, string msg);

	string poly2String(Poly p);
	string vector2String(vector<int> num);
	string vector2String(vector<double> num);
	void addVector(vector<int>& degDst, vector<double>& coeffDst, vector<int> degSrc, vector<double> coeffSrc);
	vector<int> generateDegreeVec(int len, int maxDegree);
	vector<double> generateCoeffVec(int len, int maxCoeff);
	int generateOneRandomNumber(vector<int> numVec, int  minDegree, int maxDegree, bool isInFlag);
};

#endif /* TESTPOLY_H_ */
