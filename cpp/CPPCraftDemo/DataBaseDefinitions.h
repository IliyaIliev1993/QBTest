/*File holding all the definitions needed for the properly implementation*/
#pragma once
#include <list>
#include <unordered_map>

/**
Holding the Columns
*/
enum class EColumns
{
    eColumn0,
    eColumn1,
    eColumn2,
    eColumn3
};

/**
    Represents Container mapped data std::string - columns, enum - columns
*/
std::unordered_map<std::string, EColumns>m_uMapColumnContainer =
{
    {"column0", EColumns::eColumn0},
    {"column1", EColumns::eColumn1},
    {"column2", EColumns::eColumn2},
    {"column3", EColumns::eColumn3}
};

/**
    Represents a Record Object
*/
struct QBRecord
{
    unsigned int unColumn0 = 0; /*Unique ID Column*/
    std::string strColumn1 = "N/A";
    long nColumn2 = 0;
    std::string strColumn3 = "N/A";
};

/**
    Represents a Container Collection of Records
*/
typedef std::list<QBRecord> QBRecordCollection;

