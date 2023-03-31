                             //
// Created by vladislav on 11.03.23.
//

#pragma once
#include <string>
#include "DynamicArray.h"
#include <iostream>


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
    ExamNode() = default;
    int m_iExamScore;
    char m_sStudentLastName[64];
    char  m_sStudentInitials[64];
    int m_iCreditBookId;
    char m_sExamDateStamp[64];
};

struct ExamTable
{
    int m_iInstituteCode;
    int m_iTopicCode;
    char m_sTeacherName[64]= {};
    char m_sTeacherInitials[4]= {};
    DynamicArray<ExamNode> data;

    void AddFromUser();
    void Print();
};