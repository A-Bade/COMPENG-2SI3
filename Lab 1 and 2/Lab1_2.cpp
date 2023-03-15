#include <iostream>
#include "TestHugeInteger.h"
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
#include <string>
#include <chrono>

using namespace std::chrono;

using namespace std;





void runningTimeCompare()
{
	int MAXRUN = 800; // Tune it such that durationMs >= 500
	int MAXNUMINTS = 100; // at least 100
	system_clock::time_point startTime, endTime;
	double runTime=0.0;
	double durationMs=0.0;
	int n = 10;
	for (int numInts=0; numInts < MAXNUMINTS; numInts++){
		HugeInteger huge1(n); //creates a random integer of n digits
		HugeInteger huge2(n); //creates a random integer of n digits
		startTime = system_clock::now();
		for(int numRun=0; numRun < MAXRUN; numRun++){
			HugeInteger huge3 = huge2.compareTo(huge1);
		}
		endTime = system_clock::now();
		durationMs = (duration<double, std::milli>(endTime - startTime)).count();
		runTime += durationMs / ((double)MAXRUN);
	}
	runTime = runTime/((double)MAXNUMINTS);

	cout << runTime <<endl;


for (int numInts=0; numInts < MAXNUMINTS; numInts++){
	HugeInteger huge1(n); //creates a random integer of n digits
	HugeInteger huge2(n); //creates a random integer of n digits

	cpp_int i(huge1.toString());
	cpp_int j(huge2.toString());

	cpp_int ans;
	startTime = system_clock::now();
	for(int numRun=0; numRun < MAXRUN; numRun++){
		ans = i<j;
	}
	endTime = system_clock::now();
	durationMs = (duration<double, std::milli>(endTime - startTime)).count();
	runTime += durationMs / ((double)MAXRUN);
}
runTime = runTime/((double)MAXNUMINTS);

cout << runTime <<endl;
}

int main() {
	//runTimeTest();
	runningTimeCompare();


    // when test failed, the size of number <= NUM_DISPLAY, display the number
    unsigned int num_display = 1000;
    // iterate the MAX_SIZE_ARRAY MAX_RUN times
    unsigned int max_run = 50;
    // use for generating invalid string for constructor 1 (with string input)
    unsigned int max_invalid_string = 5;
    // different size for test
    vector<int> max_size_array = {1,20,50,500,5000};

    double totalMark = 0;

    string demoLab = "Lab2"; // set to Lab1 or Lab2

    TestHugeInteger thi(num_display, max_run, max_invalid_string, max_size_array);

    if (demoLab == "Lab1"){
        totalMark += thi.testConstructorString();
        totalMark += thi.testConstructorNumber();
        totalMark += thi.testPositiveAddition();
    }else{
        totalMark += thi.testAdditionSubtraction();
        totalMark += thi.testCompareTo();
        totalMark += thi.testMultiplication();
    }

    cout << "******************************" << endl;
    cout << "*** FINAL TOTAL MARK IS " << totalMark << " ***" << endl;
    cout << "******************************" << endl;

	return 0;
}
