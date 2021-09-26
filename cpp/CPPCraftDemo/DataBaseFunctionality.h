/*File holding all the functionality*/
#pragma once
#include <string>
#include <iterator>
#include "DataBaseDefinitions.h"

namespace DBFunctionality
{
    /**
        Return records that contains a string in the StringValue field
        records - the initial set of records to filter
        matchString - the string to search for
    */
    QBRecordCollection QBFindMatchingRecords(const QBRecordCollection& containerRecords, const std::string& strColumnName, const std::string& strMatchString)
    {
        QBRecordCollection containerResult;
        EColumns& eCurrentColumn = m_uMapColumnContainer[strColumnName];

        for (const auto& element : containerRecords)
        {
            switch (eCurrentColumn)
            {

            case EColumns::eColumn0:
            {
                const auto& unMatchValue = std::stoul(strMatchString);
                if (unMatchValue == element.unColumn0)
                {
                    containerResult.emplace_back(element);
                }
                break;
            }

            case EColumns::eColumn1:
            {
                if (std::strstr(element.strColumn1.c_str(), strMatchString.c_str()))
                {
                    containerResult.emplace_back(element);
                }
                break;
            }

            case EColumns::eColumn2:
            {
                const auto& nMatchValue = std::stol(strMatchString);
                if (nMatchValue == element.nColumn2)
                {
                    containerResult.emplace_back(element);
                }
                break;
            }

            case EColumns::eColumn3:
            {
                if (std::strstr(element.strColumn3.c_str(), strMatchString.c_str()))
                {
                    containerResult.emplace_back(element);
                }
                break;
            }

            default:
                break;
            }
        }

        return containerResult;
    }

    /**
        Deletes the given Record Object (with id - unID) from the container QBRecordCollection
    */
    void DeleteRecordByID(QBRecordCollection& containerRecords, const unsigned int& unID)
    {
        std::list<QBRecord>::iterator it = containerRecords.begin();
        for (const auto& element : containerRecords)
        {
            if (element.unColumn0 == unID)
            {
                containerRecords.erase(it);
                break;
            }
            it++;
        }
    }
};
