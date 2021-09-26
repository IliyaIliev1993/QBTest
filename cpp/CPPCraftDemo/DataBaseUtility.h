/*File holding all the utilities*/
#pragma once
#include "DataBaseDefinitions.h"

namespace DBUtility
{
    /**
        Utility to populate a record collection
        prefix - prefix for the string value for every record
        numRecords - number of records to populate in the collection
    */
    QBRecordCollection PopulateDummyData(const std::string& strPrefix, unsigned int unNumRecords)
    {
        QBRecordCollection containerData;
        for (unsigned int i = 0; i < unNumRecords; i++)
        {
            QBRecord currentRecord = { i, strPrefix + std::to_string(i), i % 100, std::to_string(i) + strPrefix };
            containerData.emplace_back(currentRecord);
        }
        return containerData;
    }
};
