#include "TestHugeInteger.h"
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

TestHugeInteger::TestHugeInteger(int num_display, int max_run, int max_invalid_string, vector<int> size_array)
{
	this->NUM_DISPLAY = num_display;
	this->MAX_RUN = max_run;
	this->MAX_INVALID_STRING = max_invalid_string;
	this->MAX_SIZE_ARRAY = size_array;
	this->gen.seed(std::time(nullptr));
}

double TestHugeInteger::testConstructorString()
{
    /*
    Six test cases for constructor with string (Total marks: 6, 1 mark for each)
    1) valid string: e.g., 123 [1 mark]
    2) invalid string in the middle: e.g., 12^%12 [1 mark]
    3) invalid string at the beginning: e.g., %$123 [1 mark]
    4) invalid string at the end: e.g., 1234*& [1 mark]
    5) empty string: "" [1 mark]
    6) leading zero negative invalid: e.g., 0000-1234 [1 mark]
    */

    double totalMark = 0;
    double case_1_mark = 1;
    double case_2_mark = 1;
    double case_3_mark = 1;
    double case_4_mark = 1;
    double case_5_mark = 1;
    double case_6_mark = 1;
    double markSum = 0;

    vector<double> caseMarks =  { case_1_mark, case_2_mark, case_3_mark, case_4_mark, case_5_mark, case_6_mark};
    vector<string> caseMsg = { "valid string",
                               "invalid string in the middle",
                               "invalid string at the beginning",
                               "invalid string at the end",
                               "empty string",
                               "leading zero negative invalid"};
    vector<TestType> caseTestType = { TestType::VALID_STRING,
                                      TestType::INVALID_STRING_IN_THE_MIDDLE,
                                      TestType::INVALID_STRING_AT_THE_BEGINNING,
                                      TestType::INVALID_STRING_AT_THE_END,
                                      TestType::EMPTY_STRING,
                                      TestType::LEADING_ZERO_NEGATIVE_INVALID };

    int fails = 0;
    int each_fail = 0;
    int maxRun = MAX_RUN;
    vector<int> sizes = MAX_SIZE_ARRAY;
    string msg;

    cout << "BEGIN TEST CONSTRUCTOR WITH STRING" << endl;

    for (size_t idx = 0; idx < caseTestType.size(); idx++) {
        // Test cases:
        // 1) valid string : e.g. 123[1 mark]
        // 2) invalid string in the middle : e.g. 12 ^ %12[1 mark]
        // 3) invalid string at the beginning : e.g.% $123[1 mark]
        // 4) invalid string at the end : e.g. 1234 * &[1 mark]
        // 5) empty string : ""[1 mark]
        // 6) leading zero negative invalid : e.g. 0000 - 1234[1 mark]
        markSum += caseMarks[idx];

        msg = "Constructor with STRING for " + caseMsg[idx];
        each_fail = testConstructorString(sizes, maxRun, caseTestType[idx], msg);
        fails += each_fail;
        if (each_fail == 0) {
            totalMark += caseMarks[idx];
            cout << "Test cases in " << msg << " success ( +" << caseMarks[idx] << " ) " << endl;
        }
        else {
            cerr << "Test cases in " << msg << " fail ( -" << caseMarks[idx] << " ) " << endl;
        }
    }

    if (fails == 0) {
        cout << "Test constructor with string PASS: ALL" << endl;
    }
    else {
        cerr << "Test constructor with string FAILED for " << fails << " case(s)" << endl;
    }

    cout << "END TEST CONSTRUCTOR WITH STRING, TOTAL MARK IS " << totalMark << "/" << markSum << endl;

    return totalMark;
}

double TestHugeInteger::testConstructorNumber()
{
    /*
    Three test cases for constructor with number (Total marks: 3)
    1) valid positive number, e.g., 12 [1 mark]
    2) invalid zero [1 mark]
    3) invalid negative number, e.g., -13 [1 mark]
    */
    double totalMark = 0;
    double case_1_mark = 1;
    double case_2_mark = 1;
    double case_3_mark = 1;
    double markSum = 0;

    vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark};
    vector<string> caseMsg = { "valid positive number",
                               "invalid zero",
                               "invalid negative number"};
    vector<TestType> caseTestType = { TestType::VALID_POSITIVE_NUMBER,
                                      TestType::INVALID_ZERO,
                                      TestType::INVALID_NEGATIVE_NUMBER };

    int fails = 0;
    int each_fail = 0;
    int maxRun = MAX_RUN;
    vector<int> sizes = MAX_SIZE_ARRAY;
    string msg;

    cout << "BEGIN TEST CONSTRUCTOR WITH NUMBER" << endl;

    for (size_t idx = 0; idx < caseTestType.size(); idx++) {
        // Test cases:
        // 1) valid positive number, e.g. 12[1 mark]
        // 2) invalid zero[1 mark]
        // 3) invalid negative number, e.g. - 13[1 mark]
        markSum += caseMarks[idx];

        msg = "Constructor with NUMBER for " + caseMsg[idx];
        each_fail = testConstructorNumber(sizes, maxRun, caseTestType[idx], msg);
        fails += each_fail;
        if (each_fail == 0) {
            totalMark += caseMarks[idx];
            cout << "Test cases in " << msg << " success ( +" << caseMarks[idx] << " ) " << endl;
        }
        else {
            cerr << "Test cases in " << msg << " fail ( -" << caseMarks[idx] << " ) " << endl;
        }
    }

    if (fails == 0) {
        cout << "Test constructor with number PASS: ALL" << endl;
    }
    else {
        cerr << "Test constructor with number FAILED for " << fails << " case(s)" << endl;
    }

    cout << "END TEST CONSTRUCTOR WITH NUMBER, TOTAL MARK IS " << totalMark << "/" << markSum << endl;

    return totalMark;
}

double TestHugeInteger::testPositiveAddition()
{
    /*
    Three test cases for positive addition (Total marks: 13)
    1) cases without carry
        i)two numbers have same size, e.g., "111222" + "222111" [1.5 mark]
        ii)fisrt number has larger size, e.g.,"111222" + "33" [1.5 mark]
        iii)second number has larger size, e.g., "22" + "111333" [1.5 mark]
    2) cases with carry
        i)two numbers have same size, e.g., "99999999999" + "99999999999" [2.5 mark]
        ii)fisrt number has larger size, e.g., "99999999999" + "1" [2.5 mark]
        iii)second number has larger size, e.g., "55" + "555555555555" [2.5 mark]
    3) random number addition [1 mark]
        n digit random number adds m digit random number
    */
    int fails = 0;
    int each_fail = 0;
    int maxRun = MAX_RUN;
    vector<int> sizes = MAX_SIZE_ARRAY;

    double totalMark = 0;
    double case_1_1_mark = 1.5;
    double case_1_2_mark = 1.5;
    double case_1_3_mark = 1.5;
    double case_2_1_mark = 2.5;
    double case_2_2_mark = 2.5;
    double case_2_3_mark = 2.5;
    double case_3_mark = 1;
    double markSum = 0;

    vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark,case_1_3_mark}, // cases without carry
                                         {case_2_1_mark,case_2_2_mark,case_2_3_mark}, // cases with carry
                                         {case_3_mark} }; // random number addition
    vector<string> mainCaseMsg = { "without carry",
                                   "with carry",
                                   "random number" };
    vector<string> subCaseMsg = { "two numbers have same size",
                                  "fisrt number has larger size",
                                  "second number has larger size" };
    vector<TestType> mainCaseTestType = { TestType::WITHOUT_CARRY,
                                          TestType::WITH_CARRY,
                                          TestType::RANDOM_NUMBER };
    vector<TestType> subCaseTestType = { TestType::TWO_NUMBERS_HAVE_SAME_SIZE,
                                         TestType::FISRT_NUMBER_HAS_LARGER_SIZE,
                                         TestType::SECOND_NUMBER_HAS_LARGER_SIZE };


    string msg;

    cout << "BEGIN TEST POSITIVE ADDITION" << endl;

    for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
        // main cases:
        // 1) cases without carry
        // 2) cases with carry
        if (mainIdx == mainCaseTestType.size() - 1) { // 3) random number addition
            markSum += caseMarks[mainIdx][0];
            msg = "Positive Addition for " + mainCaseMsg[mainIdx];
            each_fail = testPositiveAddition(sizes, maxRun, mainCaseTestType[mainIdx], TestType::EMPTY, msg);
            fails += each_fail;
            if (each_fail == 0) {
                totalMark += caseMarks[mainIdx][0];
                cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][0] << " ) " << endl;
            }
            else {
                cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][0] << " ) " << endl;
            }
            continue;
        }

        for (size_t subIdx = 0; subIdx < subCaseTestType.size(); subIdx++) {
            // sub cases: (test addition and subtraction)
            // i)two numbers have same size
            // ii)fisrt number has larger size
            // iii)second number has larger size
            markSum += caseMarks[mainIdx][subIdx];
            msg = "Positive Addition for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
            each_fail = testPositiveAddition(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
            fails += each_fail;
            if (each_fail == 0) {
                totalMark += caseMarks[mainIdx][subIdx];
                cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
            }
            else {
                cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
            }
        }
    }

    if (fails == 0) {
        cout << "Test positive addition PASS: ALL" << endl;
    }
    else {
        cerr << "Test positive addition FAILED for " << fails << " case(s)" << endl;
    }
    cout << "END TEST POSITIVE ADDITION, TOTAL MARK IS " << totalMark << "/" << markSum << endl;

    return totalMark;
}

double TestHugeInteger::testAdditionSubtraction()
{
    /*
    Three main test cases for addition and subtraction (Total marks: 15, for each sub test case, 0.5 mark for both add & subtract)
    1) same input sizes
        i)same sign without borrow or carry
        ii)same sign with borrow or carry
        iii)different sign without borrow or carry
        iv)different sign with borrow or carry
        v)zero
    2) the size of first input integer larger than second
        i)same sign without borrow or carry
        ii)same sign with borrow or carry
        iii)different sign without borrow or carry
        iv)different sign with borrow or carry
        v)zero
    3) the size of first input integer less than second
        i)same sign without borrow or carry
        ii)same sign with borrow or carry
        iii)different sign without borrow or carry
        iv)different sign with borrow or carry
        v)zero
    */
    int fails = 0;
    int each_fail = 0;
    int maxRun = MAX_RUN;
    vector<int> sizes = MAX_SIZE_ARRAY;

    double totalMark = 0;
    double case_1_1_mark = 1;
    double case_1_2_mark = 1;
    double case_1_3_mark = 1;
    double case_1_4_mark = 1;
    double case_1_5_mark = 1;
    double case_2_1_mark = 1;
    double case_2_2_mark = 1;
    double case_2_3_mark = 1;
    double case_2_4_mark = 1;
    double case_2_5_mark = 1;
    double case_3_1_mark = 1;
    double case_3_2_mark = 1;
    double case_3_3_mark = 1;
    double case_3_4_mark = 1;
    double case_3_5_mark = 1;
    double markSum = 0;

    vector<vector<double>> caseMarks =    { {case_1_1_mark,case_1_2_mark,case_1_3_mark,case_1_4_mark,case_1_5_mark}, // same size
                                            {case_2_1_mark,case_2_2_mark,case_2_3_mark,case_2_4_mark,case_2_5_mark}, // the size of first input integer larger than second
                                            {case_3_1_mark,case_3_2_mark,case_3_3_mark,case_3_4_mark,case_3_5_mark} }; // the size of first input integer less than second
    vector<string> mainCaseMsg = { "same size",
                                   "first size larger",
                                   "second size larger" };
    vector<string> subCaseMsg = { "same sign without borrow or carry",
                                  "same sign with borrow or carry",
                                  "different sign without borrow or carry",
                                  "different sign with borrow or carry",
                                  "zero" };
    vector<TestType> mainCaseTestType = { TestType::EQUAL,
                                          TestType::LARGER,
                                          TestType::SMALLER };
    vector<TestType> subCaseTestType = { TestType::SAME_SIGN_WITHOUT_BORROW_CARRY,
                                         TestType::SAME_SIGN_WITH_BORROW_CARRY,
                                         TestType::DIFF_SIGN_WITHOUT_BORROW_CARRY,
                                         TestType::DIFF_SIGN_WITH_BORROW_CARRY,
                                         TestType::ZERO };
    string msg;

    cout << "BEGIN TEST ADDITION AND SUBTRACTION" << endl;

    for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
        // main cases:
        // 1) same input sizes
        // 2) the size of first input integer larger than second
        // 3) the size of first input integer less than second
        for (size_t subIdx = 0; subIdx < subCaseTestType.size(); subIdx++) {
            // sub cases: (test addition and subtraction)
            // i)same sign without borrow or carry
            // ii)same sign with borrow or carry
            // iii)different sign without borrow or carry
            // iv)different sign with borrow or carry
            // v)zero
            markSum += caseMarks[mainIdx][subIdx];
            bool addFlag = true;
            msg = "Addition for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
            each_fail = testAdditionSubtraction(sizes, maxRun, addFlag, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
            fails += each_fail;
            if (each_fail == 0) {
                totalMark += caseMarks[mainIdx][subIdx] / 2;
                cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] / 2 << " ) " << endl;
            }
            else {
                cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] / 2 << " ) " << endl;
            }
            msg = "Subtraction for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
            each_fail = testAdditionSubtraction(sizes, maxRun, !addFlag, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
            fails += each_fail;
            if (each_fail == 0) {
                totalMark += caseMarks[mainIdx][subIdx] / 2;
                cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] / 2 << " ) " << endl;
            }
            else {
                cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] / 2 << " ) " << endl;
            }
        }
    }

    if (fails == 0) {
        cout << "Test addition and subtraction PASS: ALL" << endl;
    }
    else {
        cerr << "Test addition and subtraction FAILED for " << fails << " case(s)" << endl;
    }

    cout << "END TEST ADDITION AND SUBTRACTION, TOTAL MARK IS " << totalMark << "/" << markSum << endl;

    return totalMark;
}

double TestHugeInteger::testCompareTo()
{
    /*
    Three main test cases for compareTo (Total marks: 5)
    1) two inputs are equal
        i)  0==0 [0.5 mark]
        ii) -==-/+==+ [0.5 mark]
    2) first input larger than second input
        i)  ->- [0.5 mark]
        ii) +>+ [0.5 mark]
        iii)+>0 [0.5 mark]
        iv) +>- [0.5 mark]
    3) first input smaller than second input
        i)  -<- [0.5 mark]
        ii) +<+ [0.5 mark]
        iii)-<0 [0.5 mark]
        iv) -<+ [0.5 mark]
    */
    int fails = 0;
    int each_fail = 0;
    int maxRun = MAX_RUN;
    vector<int> sizes = MAX_SIZE_ARRAY;

    double totalMark = 0;
    double case_1_1_mark = 0.5;
    double case_1_2_mark = 0.5;
    double case_2_1_mark = 0.5;
    double case_2_2_mark = 0.5;
    double case_2_3_mark = 0.5;
    double case_2_4_mark = 0.5;
    double case_3_1_mark = 0.5;
    double case_3_2_mark = 0.5;
    double case_3_3_mark = 0.5;
    double case_3_4_mark = 0.5;
    double markSum = 0;

    vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark}, // two inputs are equal
                                         {case_2_1_mark,case_2_2_mark,case_2_3_mark,case_2_4_mark}, // first input larger than second input
                                         {case_3_1_mark,case_3_2_mark,case_3_3_mark,case_3_4_mark} }; // first input smaller than second input
    vector<string> mainCaseMsg = { "equal",
                                   "first larger",
                                   "first smaller" };
    vector<vector<string>> subCaseMsg = { {"zero = zero","positive/negative = positive/negative"},
                                          {"negative > negative","positive > positive","positive > zero","positive > negative"},
                                          {"negative < negative","positive < positive","negative < zero","negative < positive"} };
    vector<TestType> mainCaseTestType = { TestType::EQUAL,
                                          TestType::LARGER,
                                          TestType::SMALLER };
    vector<vector<TestType>> subCaseTestType = { {TestType::ZERO_EQUAL_ZERO,TestType::POSITIVE_OR_NEGATIVE_EQUAL_POSITIVE_OR_NEGATIVE},
                                                 {TestType::NEGATIVE_GREATER_NEGATIVE,TestType::POSITIVE_GREATER_POSITIVE,TestType::POSITIVE_GREATER_ZERO,TestType::POSITIVE_GREATER_NEGATIVE},
                                                 {TestType::NEGATIVE_LESS_NEGATIVE,TestType::POSITIVE_LESS_POSITIVE,TestType::NEGATIVE_LESS_ZERO,TestType::NEGATIVE_LESS_POSITIVE} };
    string msg;

    cout << "BEGIN TEST COMPARETO" << endl;

    for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
        // main cases:
        // 1) two inputs are equal
        // 2) first input larger than second input
        // 3) first input smaller than second input
        for (size_t subIdx = 0; subIdx < subCaseTestType[mainIdx].size(); subIdx++) {
            // sub cases:
            // 1) 0==0, -+==+- [1 mark]
            // 2) ->-, +>+, +>0, +>- [2 mark]
            // 3) -<-, +<+, -<0, -<+ [2 mark]
            markSum += caseMarks[mainIdx][subIdx];
            msg = "Compare for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[mainIdx][subIdx];
            each_fail = testCompareTo(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[mainIdx][subIdx], msg);
            fails += each_fail;
            if (each_fail == 0) {
                totalMark += caseMarks[mainIdx][subIdx];
                cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
            }
            else {
                cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
            }
        }
    }

    if (fails == 0) {
        cout << "Test compareTo PASS: ALL" << endl;
    }
    else {
        cerr << "Test compareTo FAILED for " << fails << " case(s)" << endl;
    }

    cout << "END TEST COMPARETO, TOTAL MARK IS " << totalMark << "/" << markSum << endl;

    return totalMark;
}

double TestHugeInteger::testMultiplication()
{
    /*
    Three main test cases for multiplication (Total marks: 15, 1 mark for each)
    1) same input sizes
        i)same sign without carry
        ii)same sign with carry
        iii)different sign without carry
        iv)different sign with carry
        v)multiply zero
    2) the size of first input integer larger than second
        i)same sign without carry
        ii)same sign with carry
        iii)different sign without carry
        iv)different sign with carry
        v)multiply zero
    3) the size of first input integer less than second
        i)same sign without carry
        ii)same sign with carry
        iii)different sign without carry
        iv)different sign with carry
        v)multiply zero
    */
    int fails = 0;
    int each_fail = 0;
    int maxRun = MAX_RUN;
    vector<int> sizes = MAX_SIZE_ARRAY;

    double totalMark = 0;
    double case_1_1_mark = 1;
    double case_1_2_mark = 1;
    double case_1_3_mark = 1;
    double case_1_4_mark = 1;
    double case_1_5_mark = 1;
    double case_2_1_mark = 1;
    double case_2_2_mark = 1;
    double case_2_3_mark = 1;
    double case_2_4_mark = 1;
    double case_2_5_mark = 1;
    double case_3_1_mark = 1;
    double case_3_2_mark = 1;
    double case_3_3_mark = 1;
    double case_3_4_mark = 1;
    double case_3_5_mark = 1;
    double markSum = 0;

    vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark,case_1_3_mark,case_1_4_mark,case_1_5_mark}, // same size
                                         {case_2_1_mark,case_2_2_mark,case_2_3_mark,case_2_4_mark,case_2_5_mark}, // the size of first input integer larger than second
                                         {case_3_1_mark,case_3_2_mark,case_3_3_mark,case_3_4_mark,case_3_5_mark} }; // the size of first input integer less than second
    vector<string> mainCaseMsg = { "same size",
                                   "first size larger",
                                   "second size larger" };
    vector<string> subCaseMsg = { "same sign without carry",
                                  "same sign with carry",
                                  "different sign without carry",
                                  "different sign with carry",
                                  "multiply zero" };
    vector<TestType> mainCaseTestType = { TestType::EQUAL,
                                          TestType::LARGER,
                                          TestType::SMALLER };
    vector<TestType> subCaseTestType = { TestType::SAME_SIGN_WITHOUT_CARRY,
                                         TestType::SAME_SIGN_WITH_CARRY,
                                         TestType::DIFF_SIGN_WITHOUT_CARRY,
                                         TestType::DIFF_SIGN_WITH_CARRY,
                                         TestType::ZERO };
    string msg;

    cout << "BEGIN TEST MULTIPLICATION" << endl;

    for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
        // main cases:
        // 1) same input sizes
        // 2) the size of first input integer larger than second
        // 3) the size of first input integer less than second
        for (size_t subIdx = 0; subIdx < subCaseTestType.size(); subIdx++) {
            // sub cases:
            // i)same sign without carry
            // ii)same sign with carry
            // iii)different sign without carry
            // iv)different sign with carry
            // v)multiply zero
            markSum += caseMarks[mainIdx][subIdx];
            msg = "Multiplication for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
            each_fail = testMultiplication(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
            fails += each_fail;
            if (each_fail == 0) {
                totalMark += caseMarks[mainIdx][subIdx];
                cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
            }
            else {
                cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
            }
        }
    }

    if (fails == 0) {
        cout << "Test multiplication PASS: ALL" << endl;
    }
    else {
        cerr << "Test multiplication FAILED for " << fails << " case(s)" << endl;
    }

    cout << "END TEST MULTIPLICATION, TOTAL MARK IS " << totalMark << "/" << markSum << endl;

    return totalMark;
}

int TestHugeInteger::testConstructorString(vector<int> sizes, int maxRun, TestType testType, string msg)
{
    int failNum = 0;
    bool validFlag = true;

    for (int n = 0; n < maxRun; n++) {
        bool testFail = false;
        for (size_t i = 0; i < sizes.size(); i++) {
            //random_device dev;
            //mt19937 gen(std::time(nullptr));
            uniform_int_distribution<> dist(1, sizes[i]);
            uniform_int_distribution<> distInvalid(1, MAX_INVALID_STRING);
            int leftSize = dist(gen);
            int rightSize = dist(gen);
            int invalidSize = distInvalid(gen);

            string leftNumber = positiveRandomString(leftSize, 0, 9);
            string rightNumber = positiveRandomString(rightSize, 0, 9);
            string invalidString = getInvalidString(invalidSize);

            switch (testType) {
            case TestType::VALID_STRING: {
                validFlag = true;
                string number = randomString(sizes[i]);
                failNum += testConstructorStringExd(number, validFlag, msg);
                break;
            }
            case TestType::INVALID_STRING_IN_THE_MIDDLE: {
                validFlag = false;
                string number = leftNumber + invalidString + rightNumber;
                failNum += testConstructorStringExd(number, validFlag, msg);
                break;
            }
            case TestType::INVALID_STRING_AT_THE_BEGINNING: {
                validFlag = false;
                while (invalidString.length() == 1 && invalidString.at(0) == '-') {
                    // the minus is valid at the beginning of valid positive string
                    invalidString = getInvalidString(distInvalid(gen));
                }
                string number = invalidString + rightNumber;
                failNum += testConstructorStringExd(number, validFlag, msg);
                break;
            }
            case TestType::INVALID_STRING_AT_THE_END: {
                validFlag = false;
                string number = leftNumber + invalidString;
                failNum += testConstructorStringExd(number, validFlag, msg);
                break;
            }
            case TestType::EMPTY_STRING: {
                validFlag = false;
                string number = "";
                failNum += testConstructorStringExd(number, validFlag, msg);
                break;
            }
            case TestType::LEADING_ZERO_NEGATIVE_INVALID: {
                validFlag = false;
                string number = "";
                for (int k = 0; k < leftSize; k++)
                    number += '0';
                number += '-';
                number += rightNumber;
                failNum += testConstructorStringExd(number, validFlag, msg);
                break;
            }
            default:
                throw std::invalid_argument("[testConstructorString] testType error");
            }

            if (failNum > 0) {
                testFail = true;
                failNum = 1; // just conunt one fail case
                break;
            }
        }
        if (testFail)
            break;
    }

    return failNum;
}

int TestHugeInteger::testConstructorNumber(vector<int> sizes, int maxRun, TestType testType, string msg)
{
    int failNum = 0;
    bool validFlag = true;

    for (int n = 0; n < maxRun; n++) {
        bool testFail = false;
        for (size_t i = 0; i < sizes.size(); i++) {
            //random_device dev;
            //mt19937 gen(std::time(nullptr));
            uniform_int_distribution<> dist(1, sizes[i]);

            int size = dist(gen);

            switch (testType) {
            case TestType::VALID_POSITIVE_NUMBER: {
                validFlag = true;
                failNum += testConstructorNumberExd(size, validFlag, msg);
                break;
            }
            case TestType::INVALID_ZERO: {
                validFlag = false;
                failNum += testConstructorNumberExd(0, validFlag, msg);
                break;
            }
            case TestType::INVALID_NEGATIVE_NUMBER: {
                validFlag = false;
                failNum += testConstructorNumberExd(-size, validFlag, msg);
                break;
            }
            default:
                throw std::invalid_argument("[testConstructorNumber] testType error");
            }

            if (failNum > 0) {
                testFail = true;
                failNum = 1; // just conunt one fail case
                break;
            }
        }
        if (testFail)
            break;
    }

    return failNum;
}

int TestHugeInteger::testPositiveAddition(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
    int failNum = 0;

    for (int n = 0; n < maxRun; n++) {
        bool testFail = false;
        for (size_t i = 0; i < sizes.size(); i++) {
            //random_device dev;
            //mt19937 gen(std::time(nullptr));
            uniform_int_distribution<> distSamll(1, sizes[i]);

            int smallSize = distSamll(gen);

            uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
            int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

            switch (mainTestType) {
            case TestType::WITHOUT_CARRY: {
                switch (subTestType) {
                case TestType::TWO_NUMBERS_HAVE_SAME_SIZE: {
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(smallSize, 0, 5);
                    failNum += testPositiveAdditionExd(number1P_0_4, number2P_0_5, msg);
                    break;
                }
                case TestType::FISRT_NUMBER_HAS_LARGER_SIZE: {
                    string number1P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(smallSize, 0, 5);
                    failNum += testPositiveAdditionExd(number1P_0_4, number2P_0_5, msg);
                    break;
                }
                case TestType::SECOND_NUMBER_HAS_LARGER_SIZE: {
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(largeSize, 0, 5);
                    failNum += testPositiveAdditionExd(number1P_0_4, number2P_0_5, msg);
                    break;
                }
                default:
                    throw std::invalid_argument("[testPositiveAddition] WITHOUT_CARRY subTestType error");
                }
                break;
            }
            case TestType::WITH_CARRY: {
                switch (subTestType) {
                case TestType::TWO_NUMBERS_HAVE_SAME_SIZE: {
                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number2P_5_9 = positiveRandomString(smallSize, 5, 9);
                    failNum += testPositiveAdditionExd(number1P_5_9, number2P_5_9, msg);
                    break;
                }
                case TestType::FISRT_NUMBER_HAS_LARGER_SIZE: {
                    string number1P_5_9 = positiveRandomString(largeSize, 5, 9);
                    string number2P_5_9 = positiveRandomString(smallSize, 5, 9);
                    failNum += testPositiveAdditionExd(number1P_5_9, number2P_5_9, msg);
                    break;
                }
                case TestType::SECOND_NUMBER_HAS_LARGER_SIZE: {
                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number2P_5_9 = positiveRandomString(largeSize, 5, 9);
                    failNum += testPositiveAdditionExd(number1P_5_9, number2P_5_9, msg);
                    break;
                }
                default:
                    throw std::invalid_argument("[testPositiveAddition] WITH_CARRY subTestType error");
                }
                break;
            }
            case TestType::RANDOM_NUMBER: {
                largeSize = distSamll(gen);
                string number1P = positiveRandomString(smallSize, 0, 9);
                string number2P = positiveRandomString(largeSize, 0, 9);
                failNum += testPositiveAdditionExd(number1P, number2P, msg);
                break;
            }
            default:
                throw std::invalid_argument("[testPositiveAddition] mainTestType error");
            }

            if (failNum > 0) {
                testFail = true;
                failNum = 1; // just conunt one fail case
                break;
            }
        }
        if (testFail)
            break;
    }

    return failNum;
}

int TestHugeInteger::testAdditionSubtraction(vector<int> sizes, int maxRun, bool addFlag, TestType mainTestType, TestType subTestType, string msg)
{
    int failNum = 0;

    for (int n = 0; n < maxRun; n++) {
        bool testFail = false;
        for (size_t i = 0; i < sizes.size(); i++) {
            //random_device dev;
            //mt19937 gen(std::time(nullptr));
            uniform_int_distribution<> distSamll(1, sizes[i]);

            int smallSize = distSamll(gen);

            uniform_int_distribution<> distLarge(smallSize+1, smallSize*2);
            int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

            switch (mainTestType) {
            case TestType::EQUAL: {
                switch (subTestType) {
                case TestType::SAME_SIGN_WITHOUT_BORROW_CARRY: {
                    // same input sizes
                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(smallSize, 0, 5);
                    string number1N_5_9 = "-" + number1P_5_9;
                    string number1N_0_4 = "-" + number1P_0_4;
                    string number2N_0_5 = "-" + number2P_0_5;
                    if (addFlag) {
                        //not test +/+
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2N_0_5, addFlag, msg); // -/- : addition no carry
                    }
                    else {
                        //test subtraction: +/+,-/-
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2P_0_5, addFlag, msg); // +/+ : subtraction no borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2N_0_5, addFlag, msg); // -/- : subtraction no borrow
                    }
                    break;
                }
                case TestType::SAME_SIGN_WITH_BORROW_CARRY: {
                    // same input sizes
                    string numberMS_5_9 = positiveRandomString(1, 5, 9); // most significant digit
                    string numberMS_1_4 = positiveRandomString(1, 1, 4); // most significant digit

                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number1P9_0_4 = numberMS_5_9 + number1P_0_4;
                    string number2P1_5_9 = numberMS_1_4 + number2P_5_9;

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number1N9_0_4 = "-" + number1P9_0_4;
                    string number2N_5_9 = "-" + number2P_5_9;
                    string number2N1_5_9 = "-" + number2P1_5_9;

                    if (addFlag) {
                        //not test +/+
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2N_5_9, addFlag, msg); // -/- : addition carry
                    }
                    else {
                        //test subtraction: +/+,-/-
                        failNum += testAdditionSubtractionExd(number1P9_0_4, number2P1_5_9, addFlag, msg); // +/+ : subtraction borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N9_0_4, number2N1_5_9, addFlag, msg); // -/- : subtraction borrow
                    }
                    break;
                }
                case TestType::DIFF_SIGN_WITHOUT_BORROW_CARRY: {
                    // same input sizes
                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(smallSize, 0, 5);

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number1N_0_4 = "-" + number1P_0_4;
                    string number2N_0_5 = "-" + number2P_0_5;
                    if (addFlag) {
                        //test addition: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2N_0_5, addFlag, msg); // +/- : addition no borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2P_0_5, addFlag, msg); // -/+ : addition no borrow
                    }
                    else {
                        //test subtraction: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2N_0_5, addFlag, msg); // +/- : subtraction no carry
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2P_0_5, addFlag, msg); // -/+ : subtraction no carry
                    }
                    break;
                }
                case TestType::DIFF_SIGN_WITH_BORROW_CARRY: {
                    // same input sizes
                    string numberMS_5_9 = positiveRandomString(1, 5, 9); // most significant digit
                    string numberMS_1_4 = positiveRandomString(1, 1, 4); // most significant digit

                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number1P9_0_4 = numberMS_5_9 + number1P_0_4;
                    string number2P1_5_9 = numberMS_1_4 + number2P_5_9;

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number1N9_0_4 = "-" + number1P9_0_4;
                    string number2N_5_9 = "-" + number2P_5_9;
                    string number2N1_5_9 = "-" + number2P1_5_9;

                    if (addFlag) {
                        //test addition: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P9_0_4, number2N1_5_9, addFlag, msg); // +/- : addition borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N9_0_4, number2P1_5_9, addFlag, msg); // -/+ : addition borrow
                    }
                    else {
                        //test subtraction: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2N_5_9, addFlag, msg); // +/- : subtraction carry
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2P_5_9, addFlag, msg); // -/+ : subtraction carry
                    }
                    break;
                }
                case TestType::ZERO: {
                    // same input sizes
                    string number = randomString(1);
                    failNum += testAdditionSubtractionExd("0", "0", addFlag, msg); // 0+/-0
                    if (failNum > 0) { break; }
                    failNum += testAdditionSubtractionExd(number, "0", addFlag, msg);  // n+/-0
                    if (failNum > 0) { break; }
                    failNum += testAdditionSubtractionExd("0", number, addFlag, msg);  // 0+/-n
                    if (failNum > 0) { break; }
                    if (addFlag == false) {
                        number = randomString(smallSize);
                        failNum += testAdditionSubtractionExd(number, number, addFlag, msg); // n-n
                    }
                    break;
                }
                default:
                    throw std::invalid_argument("[testAdditionSubtraction] EQUAL subTestType error");
                }
                break;
            }
            case TestType::LARGER: {
                switch (subTestType) {
                case TestType::SAME_SIGN_WITHOUT_BORROW_CARRY: {
                    // the size of first input integer larger than second
                    string number1P_5_9 = positiveRandomString(largeSize, 5, 9);
                    string number1P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(smallSize, 0, 5);

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number1N_0_4 = "-" + number1P_0_4;
                    string number2N_0_5 = "-" + number2P_0_5;
                    if (addFlag) {
                        //test addition: -/-, not test +/+
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2N_0_5, addFlag, msg); // -/- : addition no carry
                    }
                    else {
                        //test subtraction: +/+,-/-
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2P_0_5, addFlag, msg); // +/+ : subtraction no borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2N_0_5, addFlag, msg); // -/- : subtraction no borrow
                    }
                    break;
                }
                case TestType::SAME_SIGN_WITH_BORROW_CARRY: {
                    // the size of first input integer larger than second
                    string number1P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number1P_5_9 = positiveRandomString(largeSize, 5, 9);
                    string number2P_5_9 = positiveRandomString(smallSize, 5, 9);

                    string number1N_0_4 = "-" + number1P_0_4;
                    string number1N_5_9 = "-" + number1P_5_9;
                    string number2N_5_9 = "-" + number2P_5_9;

                    if (addFlag) {
                        //test addition: -/-, not test +/+
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2N_5_9, addFlag, msg); // -/- : addition carry
                    }
                    else {
                        //test subtraction: +/+, -/-
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2P_5_9, addFlag, msg); // +/+ : subtraction borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2N_5_9, addFlag, msg); // -/- : subtraction borrow
                    }
                    break;
                }
                case TestType::DIFF_SIGN_WITHOUT_BORROW_CARRY: {
                    // the size of first input integer larger than second
                    string number1P_5_9 = positiveRandomString(largeSize, 5, 9);
                    string number1P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(smallSize, 0, 5);

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number1N_0_4 = "-" + number1P_0_4;
                    string number2N_0_5 = "-" + number2P_0_5;
                    if (addFlag) {
                        //test addition: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2N_0_5, addFlag, msg); // +/- : addition no borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2P_0_5, addFlag, msg); // -/+ : addition no borrow
                    }
                    else {
                        //test subtraction: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2N_0_5, addFlag, msg); // +/- : subtraction no carry
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2P_0_5, addFlag, msg); // -/+ : subtraction no carry
                    }
                    break;
                }
                case TestType::DIFF_SIGN_WITH_BORROW_CARRY: {
                    // the size of first input integer larger than second
                    string number1P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number1P_5_9 = positiveRandomString(largeSize, 5, 9);
                    string number2P_5_9 = positiveRandomString(smallSize, 5, 9);

                    string number1N_0_4 = "-" + number1P_0_4;
                    string number1N_5_9 = "-" + number1P_5_9;
                    string number2N_5_9 = "-" + number2P_5_9;

                    if (addFlag) {
                        //test addition: +/-,-/+,
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2N_5_9, addFlag, msg); // +/- : addition borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2P_5_9, addFlag, msg); // -/+ : addition borrow
                    }
                    else {
                        //test subtraction: +/+,+/-,-/+,-/-
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2N_5_9, addFlag, msg); // +/- : subtraction carry
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2P_5_9, addFlag, msg); // -/+ : subtraction carry
                    }
                    break;
                }
                case TestType::ZERO: {
                    // the size of first input integer larger than second
                    string number = randomString(largeSize);
                    failNum += testAdditionSubtractionExd(number, "0", addFlag, msg); // n+/-0
                    break;
                }
                default:
                    throw std::invalid_argument("[testAdditionSubtraction] LARGER subTestType error");
                }
                break;
            }
            case TestType::SMALLER: {
                switch (subTestType) {
                case TestType::SAME_SIGN_WITHOUT_BORROW_CARRY: {
                    // the size of first input integer less than second
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(largeSize, 0, 5);
                    string number2P_5_9 = positiveRandomString(largeSize, 5, 9);

                    string number1N_0_4 = "-" + number1P_0_4;
                    string number2N_0_5 = "-" + number2P_0_5;
                    string number2N_5_9 = "-" + number2P_5_9;

                    if (addFlag) {
                        //test addition: -/-, not test +/+
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2N_0_5, addFlag, msg); // -/- : addition no carry
                    }
                    else {
                        //test subtraction: +/+,-/-
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2P_5_9, addFlag, msg); // +/+ : subtraction no borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2N_5_9, addFlag, msg); // -/- : subtraction no borrow
                    }
                    break;
                }
                case TestType::SAME_SIGN_WITH_BORROW_CARRY: {
                    // the size of first input integer less than second
                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number2P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number2P_5_9 = positiveRandomString(largeSize, 5, 9);

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number2N_0_4 = "-" + number2P_0_4;
                    string number2N_5_9 = "-" + number2P_5_9;

                    if (addFlag) {
                        //test addition: -/-, not test +/+
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2N_5_9, addFlag, msg); // -/- : addition carry
                    }
                    else {
                        //test subtraction: +/+,-/-
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2P_0_4, addFlag, msg); // +/+ : subtraction borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2N_0_4, addFlag, msg); // -/- : subtraction borrow
                    }
                    break;
                }
                case TestType::DIFF_SIGN_WITHOUT_BORROW_CARRY: {
                    // the size of first input integer less than second
                    string number1P_0_4 = positiveRandomString(smallSize, 0, 4);
                    string number2P_0_5 = positiveRandomString(largeSize, 0, 5);
                    string number2P_5_9 = positiveRandomString(largeSize, 5, 9);

                    string number1N_0_4 = "-" + number1P_0_4;
                    string number2N_0_5 = "-" + number2P_0_5;
                    string number2N_5_9 = "-" + number2P_5_9;

                    if (addFlag) {
                        //test addition: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2N_5_9, addFlag, msg); // +/- : addition no borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2P_5_9, addFlag, msg); // -/+ : addition no borrow
                    }
                    else {
                        //test subtraction: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_0_4, number2N_0_5, addFlag, msg); // +/- : subtraction no carry
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_0_4, number2P_0_5, addFlag, msg); // -/+ : subtraction no carry
                    }
                    break;
                }
                case TestType::DIFF_SIGN_WITH_BORROW_CARRY: {
                    // the size of first input integer less than second
                    string number1P_5_9 = positiveRandomString(smallSize, 5, 9);
                    string number2P_0_4 = positiveRandomString(largeSize, 0, 4);
                    string number2P_5_9 = positiveRandomString(largeSize, 5, 9);

                    string number1N_5_9 = "-" + number1P_5_9;
                    string number2N_0_4 = "-" + number2P_0_4;
                    string number2N_5_9 = "-" + number2P_5_9;

                    if (addFlag) {
                        //test addition: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2N_0_4, addFlag, msg); // +/- : borrow
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2P_0_4, addFlag, msg); // -/+ : borrow
                    }
                    else {
                        //test subtraction: +/-,-/+
                        failNum += testAdditionSubtractionExd(number1P_5_9, number2N_5_9, addFlag, msg); // +/- : carry
                        if (failNum > 0) { break; }
                        failNum += testAdditionSubtractionExd(number1N_5_9, number2P_5_9, addFlag, msg); // -/+ : carry
                    }
                    break;
                }
                case TestType::ZERO: {
                    // the size of first input integer less than second
                    string number = randomString(largeSize);
                    failNum += testAdditionSubtractionExd("0", number, addFlag, msg); // 0+/-n
                    break;
                }
                default:
                    throw std::invalid_argument("[testAdditionSubtraction] SMALLER subTestType error");
                }
                break;
            }
            default:
                throw std::invalid_argument("[testAdditionSubtraction] mainTestType error");
            }

            if (failNum > 0) {
                testFail = true;
                failNum = 1; // just conunt one fail case
                break;
            }
        }
        if (testFail)
            break;
    }
    return failNum;
}

int TestHugeInteger::testCompareTo(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
    int failNum = 0;

    for (int n = 0; n < maxRun; n++) {
        bool testFail = false;
        for (size_t i = 0; i < sizes.size(); i++) {
            //random_device dev;
            //mt19937 gen(std::time(nullptr));
            uniform_int_distribution<> distSamll(1, sizes[i]);

            int smallSize = distSamll(gen);
            uniform_int_distribution<> distLarge(smallSize+1, smallSize*2);
            int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

            switch (mainTestType) {
            case TestType::EQUAL:
                // 0==0, -==-, +==+
                switch (subTestType) {
                case TestType::ZERO_EQUAL_ZERO: {
                    failNum += testCompareToExd("0", "0", msg); // 0==0
                    break;
                }
                case TestType::POSITIVE_OR_NEGATIVE_EQUAL_POSITIVE_OR_NEGATIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 9);
                    string numberN1 = "-" + numberP1;
                    failNum += testCompareToExd(numberN1, numberN1, msg); // -==-
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberP1, numberP1, msg); // +==+
                    break;
                }
                default:
                    throw std::invalid_argument("[testCompareTo] EQUAL subTestType error");
                }
                break;

            case TestType::LARGER:
                // ->-, +>+, +>0, +>-
                switch (subTestType) {
                case TestType::NEGATIVE_GREATER_NEGATIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 4);
                    string numberP2 = positiveRandomString(smallSize, 5, 9);
                    string numberP3 = positiveRandomString(largeSize, 0, 9);
                    string numberN1 = "-" + numberP1;
                    string numberN2 = "-" + numberP2;
                    string numberN3 = "-" + numberP3;

                    failNum += testCompareToExd(numberN1, numberN2, msg); // same size
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberN1, numberN3, msg); // different size
                    break;
                }
                case TestType::POSITIVE_GREATER_POSITIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 4);
                    string numberP2 = positiveRandomString(smallSize, 5, 9);
                    string numberP3 = positiveRandomString(largeSize, 0, 9);

                    failNum += testCompareToExd(numberP2, numberP1, msg); // same size
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberP3, numberP1, msg); // different size
                    break;
                }
                case TestType::POSITIVE_GREATER_ZERO: {
                    string numberP1 = positiveRandomString(smallSize, 0, 9);

                    failNum += testCompareToExd(numberP1, "0", msg);
                    break;
                }
                case TestType::POSITIVE_GREATER_NEGATIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 4);
                    string numberP2 = positiveRandomString(smallSize, 5, 9);
                    string numberP3 = positiveRandomString(largeSize, 0, 9);
                    string numberN1 = "-" + numberP1;
                    string numberN2 = "-" + numberP2;
                    string numberN3 = "-" + numberP3;

                    failNum += testCompareToExd(numberP1, numberN2, msg); // same size
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberP1, numberN3, msg); // different size
                    break;
                }
                default:
                    throw std::invalid_argument("[testCompareTo] LARGER subTestType error");
                }
                break;

            case TestType::SMALLER:
                // -<-, +<+, -<0, -<+
                switch (subTestType) {
                case TestType::NEGATIVE_LESS_NEGATIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 4);
                    string numberP2 = positiveRandomString(smallSize, 5, 9);
                    string numberP3 = positiveRandomString(largeSize, 0, 9);
                    string numberN1 = "-" + numberP1;
                    string numberN2 = "-" + numberP2;
                    string numberN3 = "-" + numberP3;

                    failNum += testCompareToExd(numberN2, numberN1, msg); // same size
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberN3, numberN1, msg); // different size
                    break;
                }
                case TestType::POSITIVE_LESS_POSITIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 4);
                    string numberP2 = positiveRandomString(smallSize, 5, 9);
                    string numberP3 = positiveRandomString(largeSize, 0, 9);

                    failNum += testCompareToExd(numberP1, numberP2, msg); // same size
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberP1, numberP3, msg); // different size
                    break;
                }
                case TestType::NEGATIVE_LESS_ZERO: {
                    string numberP1 = positiveRandomString(smallSize, 0, 9);
                    string numberN1 = "-" + numberP1;

                    failNum += testCompareToExd(numberN1, "0", msg);
                    break;
                }
                case TestType::NEGATIVE_LESS_POSITIVE: {
                    string numberP1 = positiveRandomString(smallSize, 0, 4);
                    string numberP2 = positiveRandomString(smallSize, 5, 9);
                    string numberP3 = positiveRandomString(largeSize, 0, 9);
                    string numberN1 = "-" + numberP1;
                    string numberN2 = "-" + numberP2;
                    string numberN3 = "-" + numberP3;

                    failNum += testCompareToExd(numberN2, numberP1, msg); // same size
                    if (failNum > 0) { break; }
                    failNum += testCompareToExd(numberN3, numberP1, msg); // different size
                    break;
                }
                default:
                    throw std::invalid_argument("[testCompareTo] SMALLER subTestType error");
                }
                break;

            default:
                throw std::invalid_argument("[testCompareTo] mainTestType error");
            }

            if (failNum > 0) {
                testFail = true;
                failNum = 1; // just conunt one fail case
                break;
            }
        }
        if (testFail)
            break;
    }
    return failNum;
}

int TestHugeInteger::testMultiplication(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
    int failNum = 0;

    for (int n = 0; n < maxRun; n++) {
        bool testFail = false;
        for (size_t i = 0; i < sizes.size(); i++) {
            //random_device dev;
            //mt19937 gen(std::time(nullptr));
            uniform_int_distribution<> distSamll(1, sizes[i]);

            int smallSize = distSamll(gen);
            uniform_int_distribution<> distLarge(smallSize + 1, smallSize * 2);
            int largeSize = distLarge(gen);  // generate a number [smallSzie+1,2*smallSzie]

            int firstSize = 0;
            int secondSize = 0;

            switch (mainTestType) {
            case TestType::EQUAL: {
                // same input sizes
                firstSize = smallSize;
                secondSize = smallSize;
                break;
            }
            case TestType::LARGER: {
                // the size of first input integer larger than second
                firstSize = largeSize;
                secondSize = smallSize;
                break;
            }
            case TestType::SMALLER: {
                // the size of first input integer less than second
                firstSize = smallSize;
                secondSize = largeSize;
                break;
            }
            default:
                throw std::invalid_argument("[testMultiplication] mainTestType error");
            }

            switch (subTestType) {
            case TestType::SAME_SIGN_WITHOUT_CARRY: {
                string number1P_0_3 = positiveRandomString(firstSize, 0, 3);
                string number2P_0_3 = positiveRandomString(secondSize, 0, 3);
                string number1N_0_3 = "-" + number1P_0_3;
                string number2N_0_3 = "-" + number2P_0_3;

                failNum += testMultiplicationExd(number1P_0_3, number2P_0_3, msg); // +/+ : no carry
                if (failNum > 0) { break; }
                failNum += testMultiplicationExd(number1N_0_3, number2N_0_3, msg); // -/- : no carry
                break;
            }
            case TestType::SAME_SIGN_WITH_CARRY: {
                string number1P_4_9 = positiveRandomString(firstSize, 4, 9);
                string number2P_4_9 = positiveRandomString(secondSize, 4, 9);
                string number1N_4_9 = "-" + number1P_4_9;
                string number2N_4_9 = "-" + number2P_4_9;

                failNum += testMultiplicationExd(number1P_4_9, number2P_4_9, msg); // +/+ : carry
                if (failNum > 0) { break; }
                failNum += testMultiplicationExd(number1N_4_9, number2N_4_9, msg); // -/- : carry
                break;
            }
            case TestType::DIFF_SIGN_WITHOUT_CARRY: {
                string number1P_0_3 = positiveRandomString(firstSize, 0, 3);
                string number2P_0_3 = positiveRandomString(secondSize, 0, 3);
                string number1N_0_3 = "-" + number1P_0_3;
                string number2N_0_3 = "-" + number2P_0_3;

                failNum += testMultiplicationExd(number1P_0_3, number2N_0_3, msg); // +/- : no carry
                if (failNum > 0) { break; }
                failNum += testMultiplicationExd(number1N_0_3, number2P_0_3, msg); // -/+ : no carry
                break;
            }
            case TestType::DIFF_SIGN_WITH_CARRY: {
                string number1P_4_9 = positiveRandomString(firstSize, 4, 9);
                string number2P_4_9 = positiveRandomString(secondSize, 4, 9);
                string number1N_4_9 = "-" + number1P_4_9;
                string number2N_4_9 = "-" + number2P_4_9;

                failNum += testMultiplicationExd(number1P_4_9, number2N_4_9, msg); // +/- : carry
                if (failNum > 0) { break; }
                failNum += testMultiplicationExd(number1N_4_9, number2P_4_9, msg); // -/+ : carry
                break;
            }
            case TestType::ZERO: {
                if (firstSize == secondSize) {
                    // same input sizes
                    string number = randomString(1);
                    failNum += testMultiplicationExd("0", "0", msg); // 0*0
                    if (failNum > 0) { break; }
                    failNum += testMultiplicationExd(number, "0", msg); // n*0
                    if (failNum > 0) { break; }
                    failNum += testMultiplicationExd("0", number, msg); // 0*n
                }
                else if (firstSize > secondSize) {
                    // the size of first input integer larger than second
                    string number = randomString(firstSize);
                    failNum += testMultiplicationExd(number, "0", msg); // n*0
                }
                else if (firstSize < secondSize) {
                    // the size of first input integer less than second
                    string number = randomString(secondSize);
                    failNum += testMultiplicationExd("0", number, msg); // 0*n
                }
                break;
            }
            default:
                throw std::invalid_argument("[testMultiplication] subTestType error");
            }

            if (failNum > 0) {
                testFail = true;
                failNum = 1; // just conunt one fail case
                break;
            }
        }
        if (testFail)
            break;
    }
    return failNum;
}

int TestHugeInteger::testConstructorStringExd(string number, bool validFlag, string msg)
{
    int failNum = 0;

    if (validFlag) {
        // valid case test
        try {
            HugeInteger x(number);
            string xStr = x.toString();
            if (number != xStr) {
                cerr << "Error in " << msg << " ->" << endl;
                if (number.length() <= NUM_DISPLAY) {
                    cerr << "Input  string: " << number << endl;
                    cerr << "Output string: " << xStr << endl;
                }
                else {
                    cerr << "Display size limited: " << NUM_DISPLAY << endl;
                }
                failNum++;
            }
        }
        catch (const std::exception& e) {
            cerr << "Error in " << msg << " ->" << endl;
            cerr << e.what() << endl;
            cerr << "Input  string:" << number << endl;
            failNum++;
        }
        catch (...) {
        	cerr << "Error in " << msg << " ->" << endl;
            cerr << "Unknown exception" << endl;
            failNum++;
        }
    }
    else {
        // invalid case test
        try {
            HugeInteger x(number);

            // not detect the invalid string
            string xStr = x.toString();
            cerr << "Error in " << msg << " ->" << endl;
            if (number.length() <= NUM_DISPLAY) {
                cerr << "Input  string: " << number << endl;
                cerr << "Output string: " << xStr << endl;
            }
            else {
                cerr << "Display size limited: " << NUM_DISPLAY << endl;
            }
            failNum++;
        }
        catch (...) {
            // success
        }
    }

    return failNum;
}

int TestHugeInteger::testConstructorNumberExd(int size, bool validFlag, string msg)
{
    int failNum = 0;

    if (validFlag) {
        // valid case test
        try {
            HugeInteger x(size);

            // Check whether x is valid or not
            string xStr = x.toString();
            cpp_int y(xStr);
            string yStr = y.str();
            size_t numLength = 0;
            if (yStr.at(0) == '-') // negative number
                numLength = yStr.length() - 1;
            else
                numLength = yStr.length();

            if (numLength != size) {
                cerr << "Error in " << msg << " ->" << endl;
                if (size < 0 || size <= NUM_DISPLAY) {
                    cerr << "Input    size: " << size << endl;
                    cerr << "Output string: " << xStr << endl;
                }
                else {
                    cerr << "Display size limited: " << NUM_DISPLAY << endl;
                }
                failNum++;
            }
        }
        catch (const std::exception& e) {
            cerr << "Error in " << msg << " ->" << endl;
            cerr << e.what() << endl;
            cerr << "Input  size: " << size << endl;
            failNum++;
        }
        catch (...) {
        	cerr << "Error in " << msg << " ->" << endl;
            cerr << "Unknown exception" << endl;
            failNum++;
        }
    }
    else {
        // invalid case test
        try {
            HugeInteger x(size);

            // not detect the invalid string
            string xStr = x.toString();
            cerr << "Error in " << msg << " ->" << endl;
            if (size < 0 || size <= NUM_DISPLAY) {
                cerr << "Input    size: " << size << endl;
                cerr << "Output string: " << xStr << endl;
            }
            else {
                cerr << "Display size limited: " << NUM_DISPLAY << endl;
            }
            failNum++;
        }
        catch (...) {
            // success
        }
    }

    return failNum;
}

int TestHugeInteger::testPositiveAdditionExd(string number1, string number2, string msg)
{
    int failNum = 0;

    try {
        cpp_int y1(number1);
        cpp_int y2(number2);

        HugeInteger x1(number1);
        HugeInteger x2(number2);

        cpp_int y3 = y1 + y2;
        HugeInteger x3 = x1.add(x2);

        string y3Str = y3.str();
        //For Lab1, the leading zeros are ok, don't deduct marks.
        string x3Str = removeLeadingZeros(x3.toString());
        //string x3Str = x3.toString();

        if (y3Str != x3Str) {
            cerr << "Error in " << msg << " ->" << endl;
            if (y3Str.length() <= NUM_DISPLAY) {
                cerr << "Input1(+): " << number1 << endl;
                cerr << "Input2(+): " << number2 << endl;
                cerr << "Expected output= " << y3Str << endl;
                cerr << "Current  output= " << x3Str << endl;
            }
            else {
                cerr << "Display size limited: " << NUM_DISPLAY << endl;
            }
            failNum++;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error in " << msg << " ->" << endl;
        cerr << e.what() << endl;
        cerr << "Input1(+): " << number1 << endl;
        cerr << "Input2(+): " << number2 << endl;
        failNum++;
    }
    catch (...) {
    	cerr << "Error in " << msg << " ->" << endl;
        cerr << "Unknown exception" << endl;
        failNum++;
    }

    return failNum;
}

int TestHugeInteger::testAdditionSubtractionExd(string number1, string number2, bool addFlag, string msg)
{
    int failNum = 0;
    string opSign = "";

    if (addFlag) {
        opSign = "+";
    }
    else {
        opSign = "-";
    }

    try {
        cpp_int y1(number1);
        cpp_int y2(number2);

        HugeInteger x1(number1);
        HugeInteger x2(number2);

        if (addFlag) {
        	cpp_int y3 = y1 + y2;
        	HugeInteger x3 = x1.add(x2);
        	string y3Str = y3.str();
        	string x3Str = x3.toString();
            if (y3Str != x3Str) {
                cerr << "Error in " << msg << " ->" << endl;
                if (y3Str.length() <= NUM_DISPLAY) {
                    cerr << "Input1(" << opSign << "): " << number1 << endl;
                    cerr << "Input2(" << opSign << "): " << number2 << endl;
                    cerr << "Expected output= " << y3Str << endl;
                    cerr << "Current  output= " << x3Str << endl;
                }
                else {
                    cerr << "Display size limited: " << NUM_DISPLAY << endl;
                }
                failNum++;
            }
        }
        else {
        	cpp_int y3 = y1 - y2;
        	HugeInteger x3 = x1.subtract(x2);
        	string y3Str = y3.str();
        	string x3Str = x3.toString();
            if (y3Str != x3Str) {
                cerr << "Error in " << msg << " ->" << endl;
                if (y3Str.length() <= NUM_DISPLAY) {
                    cerr << "Input1(" << opSign << "): " << number1 << endl;
                    cerr << "Input2(" << opSign << "): " << number2 << endl;
                    cerr << "Expected output= " << y3Str << endl;
                    cerr << "Current  output= " << x3Str << endl;
                }
                else {
                    cerr << "Display size limited: " << NUM_DISPLAY << endl;
                }
                failNum++;
            }
        }
    }
    catch (const std::exception& e) {
        cerr << "Error in " << msg << " ->" << endl;
        cerr << e.what() << endl;
        cerr << "Input1(" << opSign << "): " << number1 << endl;
        cerr << "Input2(" << opSign << "): " << number2 << endl;
        failNum++;
    }
    catch (...) {
    	cerr << "Error in " << msg << " ->" << endl;
        cerr << "Unknown exception" << endl;
        failNum++;
    }
    return failNum;
}

int TestHugeInteger::testCompareToExd(string number1, string number2, string msg)
{
    int failNum = 0;

    try {
        cpp_int y1(number1);
        cpp_int y2(number2);
        int y3 = (y1 == y2)? 0 : (y1 > y2 ? 1:-1);

        HugeInteger x1(number1);
        HugeInteger x2(number2);
        int x3 = x1.compareTo(x2);

        if (y3 != x3) {
            cerr << "Error in " << msg << " ->" << endl;
            size_t maxLen = max(number1.length(), number2.length());
            if (maxLen <= NUM_DISPLAY) {
                cerr << "Input1(>=<): " << number1 << endl;
                cerr << "Input2(>=<): " << number2 << endl;
                cerr << "Expected output= " << y3 << endl;
                cerr << "Current  output= " << x3 << endl;
            }
            else {
                cerr << "Display size limited: " << NUM_DISPLAY << endl;
            }
            failNum++;
        }
    }
    catch (const std::exception& e) {
    	cerr << "Error in " << msg << " ->" << endl;
        cerr << e.what() << endl;
        cerr << "Input1(>=<): " << number1 << endl;
        cerr << "Input2(>=<): " << number2 << endl;
        failNum++;
    }
    catch (...) {
    	cerr << "Error in " << msg << " ->" << endl;
        cerr << "Unknown exception" << endl;
        failNum++;
    }
    return failNum;
}

int TestHugeInteger::testMultiplicationExd(string number1, string number2, string msg)
{
    int failNum = 0;

    try {
        cpp_int y1(number1);
        cpp_int y2(number2);
        cpp_int y3 = y1 * y2;
        string y3Str = y3.str();

        HugeInteger x1(number1);
        HugeInteger x2(number2);
        HugeInteger x3 = x1.multiply(x2);
        string x3Str = x3.toString();

        if (y3Str != x3Str) {
            cerr << "Error in " << msg << " ->" << endl;
            if (y3Str.length() <= NUM_DISPLAY) {
                cerr << "Input1(x): " << number1 << endl;
                cerr << "Input2(x): " << number2 << endl;
                cerr << "Expected output= " << y3Str << endl;
                cerr << "Current  output= " << x3Str << endl;
            }
            else {
                cerr << "Display size limited: " << NUM_DISPLAY << endl;
            }
            failNum++;
        }
    }
    catch (const std::exception& e) {
    	cerr << "Error in " << msg << " ->" << endl;
        cerr << e.what() << endl;
        cerr << "Input1(x): " << number1 << endl;
        cerr << "Input2(x): " << number2 << endl;
        failNum++;
    }
    catch (...) {
    	cerr << "Error in " << msg << " ->" << endl;
        cerr << "Unknown exception" << endl;
        failNum++;
    }
    return failNum;
}

string TestHugeInteger::getInvalidString(int n)
{
    //random_device dev;
    //mt19937 gen(std::time(nullptr));
    uniform_int_distribution<> dist(32, 126);

    string invalidString;
    for (int i = 0; i < n;) {
        int number = dist(gen);
        if ((number >= 48 && number <= 57)) {
            // valid char
            continue;
        }
        else {
            invalidString += (char)(number);
            i++;
        }
    }
    return invalidString;
}

string TestHugeInteger::positiveRandomString(int size, int minInt, int maxInt)
{
    //random_device dev;
    //mt19937 gen(std::time(nullptr));
    uniform_int_distribution<> dist(minInt, maxInt);

    string rand_string = "";

    if (minInt < 0 || maxInt > 9 || (minInt > maxInt))
        throw std::out_of_range("positiveRandomString input min/max error");

    if (size < 1) {
        throw std::out_of_range("positiveRandomString input size should >= 1");
    }
    else {
        // The first number cannot be zero
        int initNum = dist(gen);
        while (initNum == 0)
        {
            initNum = dist(gen);
        }

        rand_string += to_string(initNum);

        for (int i = 1; i <= size - 1; i++) {
            int next_digit = dist(gen); // Other numbers can be zero
            rand_string = rand_string + to_string(next_digit);
        }
    }

    return rand_string;
}

string TestHugeInteger::randomString(int size)
{
    //random_device dev;
    //mt19937 gen(std::time(nullptr));
    uniform_int_distribution<> dist(0, 9);

    string rand_string = "";
    if (size < 1) {
        throw std::out_of_range("randomString input size should >= 1");
    }
    else if (size == 1) {
        rand_string += to_string(dist(gen));
    }
    else {
        // The first number cannot be zero
        int initNum = dist(gen);
        while (initNum == 0)
        {
            initNum = dist(gen);
        }

        rand_string += to_string(initNum);

        for (int i = 1; i <= size - 1; i++) {
            int next_digit = dist(gen); // Other numbers can be zero
            rand_string = rand_string + to_string(next_digit);
        }
    }

    if (dist(gen) < 5 && rand_string.at(0) != '0') { // don't generate "-0"
        rand_string = "-" + rand_string;
    }
    return rand_string;
}

string TestHugeInteger::removeLeadingZeros(string val)
{
    size_t len = val.length();
    string newVal = "";
    for (unsigned int i = 0; i < len; i++) {
        if (i == len - 1) {
            newVal = val.substr(i);
        }
        else if (val.at(i) != '0') {
            newVal = val.substr(i);
            break;
        }
    }
    return newVal;
}
