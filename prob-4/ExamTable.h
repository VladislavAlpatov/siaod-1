                             //
// Created by vladislav on 11.03.23.
//

#pragma once
#include <string>


enum ExamScore : int
{
    NotVisited = 1,
    Exceptable,
    Good,
    Splendid,
    NotAllowed = 6
};
struct ExamNode
{
public:
    ExamNode(int iExamScore, const std::string& sStudentLastName, const std::string&sStudentInitials, int iCreditBookId, const std::string&sExamDate)
    {
        m_iExamScore = iExamScore;
        m_sStudentLastName = sStudentLastName;
        m_sStudentInitials = sStudentInitials;
        m_iCreditBookId = iCreditBookId;
        m_sExamDateStamp = sExamDate;
    }
    ExamNode() = default;
    int m_iExamScore;
    std::string m_sStudentLastName;
    std::string m_sStudentInitials;
    int m_iCreditBookId;
    std::string m_sExamDateStamp;
};

class ExamTable
{

};