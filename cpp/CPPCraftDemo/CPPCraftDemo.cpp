#include "stdafx.h"

#include <assert.h>
#include <chrono>
#include <iostream>

#include "DataBaseFunctionality.h"
#include "DataBaseUtility.h"

int main(int argc, _TCHAR* argv[])
{
    using namespace std::chrono;

    // populate a bunch of data
    auto data = DBUtility::PopulateDummyData("testdata", 1000);

    // Find a record that contains and measure the perf
    auto timerFindRecord = steady_clock::now();
    auto filteredSet = DBFunctionality::QBFindMatchingRecords(data, "column1", "testdata500");
    auto filteredSet2 = DBFunctionality::QBFindMatchingRecords(data, "column2", "24");

    double dTotalTimeFind = double((steady_clock::now() - timerFindRecord).count()) * steady_clock::period::num / steady_clock::period::den;
    std::cout << "Profiler FIND Record: " << dTotalTimeFind << std::endl;

    // Delete record with id 24
    auto timerDeleteRecord = steady_clock::now();
    DBFunctionality::DeleteRecordByID(data, 24);

    double dTotalTimeErase = double((steady_clock::now() - timerDeleteRecord).count()) * steady_clock::period::num / steady_clock::period::den;
    std::cout << "Profiler DELETE Record: " << dTotalTimeErase << std::endl;
    std::cout << "TOTAL TIME OPERATIONS : " << dTotalTimeFind + dTotalTimeErase << std::endl;

    // Search for the record with id 24
    auto containerSearchingID24 = DBFunctionality::QBFindMatchingRecords(data, "column0", "24");
    std::cout << "Is containerSearchingID24 empty ? : " << containerSearchingID24.empty() << std::endl;


    // make sure that the function is correct
    assert(filteredSet.size() == 1);
	return 0;
}

