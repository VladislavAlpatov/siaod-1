//
// Created by vladislav on 11.03.23.
//


#include <string>
#include "ExamTable.h"
#include <iostream>


int main()
{
    ExamTable table;


    printf("Enter table info <last name>, <initials>, <topic code>, <institute code>: ");
    std::cin >> table.m_sTeacherName >> table.m_sTeacherInitials >> table.m_iTopicCode >> table.m_iInstituteCode;

    while (true)
    {
        printf("0 - Add new student\n1 - Edit Student\n2 - Count not visited\n3 - Remove not allowed\n4 - Print tabel\nChoose operation: ");
        int iOperation;
        std::cin >> iOperation;
        if (iOperation == 0)
        {
            table.AddFromUser();
        }
        else if (iOperation == 1)
        {
            int iBookId;
            printf("Enter book id: ");
            std::cin >> iBookId;

            for (int i = 0; i < table.data.GetSize(); i++)
                if (table.data[i].m_iCreditBookId == iBookId)
                {
                    auto& student = table.data[i];
                    printf("New last name: ");
                    memset(student.m_sStudentLastName, 0, 64);
                    std::cin >> student.m_sStudentLastName;

                    printf("New initials: ");
                    memset(student.m_sStudentInitials, 0, 64);
                    std::cin >> student.m_sStudentInitials;

                    printf("New score: ");
                    std::cin >> student.m_iExamScore;

                    printf("New timestamp: ");
                    memset(student.m_sExamDateStamp, 0, 64);
                    std::cin >> student.m_sExamDateStamp;
                    break;
                }
        }
        else if (iOperation == 2)
        {
            int ct = 0;

            for (int i = 0; i < table.data.GetSize(); i++)
                if (table.data[i].m_iExamScore == ExamScore::NotVisited)
                    ct++;
            printf("Not visited: %d\n", ct);
        }
        else if (iOperation == 3)
        {
            table.data.remove_if([](const ExamNode& node) -> bool {return node.m_iExamScore == ExamScore::NotAllowed;});
        }
        else if (iOperation == 4)
        {
            table.Print();
        }
    }
}