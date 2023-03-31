//
// Created by vladislav on 11.03.23.
//

#include "ExamTable.h"

void ExamTable::AddFromUser()
{
    ExamNode newNode{};
    printf("Enter Student last name: ");
    std::cin >> newNode.m_sStudentLastName;

    printf("Enter Student initials: ");
    std::cin >> newNode.m_sStudentInitials;

    printf("Enter Student credit book id: ");
    std::cin >> newNode.m_iCreditBookId;

    printf("Enter Student exam score: ");
    std::cin >> newNode.m_iExamScore;

    printf("Enter exam timestamp: ");
    std::cin >> newNode.m_sExamDateStamp;

    data.push_back(newNode);
}

void ExamTable::Print()
{
    printf("TABLE|Teacher %s %s|Institute code %d|Topic code %d|Size %d\n", m_sTeacherName, m_sTeacherInitials,m_iInstituteCode, m_iTopicCode, data.GetSize());

    for (int i = 0; i < data.GetSize(); i++)
    {
        printf("[%d] Student %s %s|Score %d|Book id %d|TimeStamp %s\n",i, data[i].m_sStudentLastName,data[i].m_sStudentInitials,data[i].m_iExamScore, data[i].m_iCreditBookId,data[i].m_sExamDateStamp);
    }
}
