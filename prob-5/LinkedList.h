//
// Created by Vladislav on 23.03.2023.
//

#pragma once
#include <iterator>



template<class Type>
class LinkedList
{
    class Node;
public:
    template<class... Args>
    LinkedList(Args... args)
    {
        Type tmp[] = {args...};

        for (size_t i = 0; i < sizeof...(args); i++)
            PushBack(std::move(tmp[i]));
    }
    void PushBack(Type val)
    {
        auto pNewNode = new Node(val);
        m_szSize++;
        if (!m_pStartNode)
        {
            m_pStartNode = pNewNode;
            m_pEndNode = pNewNode;
            return;
        }
        m_pEndNode->m_pNext = pNewNode;
        m_pEndNode = pNewNode;
    }
    size_t Size() const
    {
        return m_szSize;
    }
    Type& At(size_t szIndex)
    {
        return GetNodeByIndex(szIndex)->m_data;
    }
    void Clip(size_t szBegin, size_t szEnd)
    {
        auto pStart = GetNodeByIndex(szBegin-1);
        auto pEnd   = GetNodeByIndex(szEnd+1);

        for (auto it = pStart->m_pNext; it != pEnd;)
        {
            const auto pNext = it->m_pNext;
            delete it;

            it = pNext;
            m_szSize--;
        }
        pStart->m_pNext = pEnd;

    }
    Node* GetNodeByIndex(size_t szIndex)
    {
        auto pCurrent = m_pStartNode;

        for (size_t i = 0; i < szIndex; i++)
            pCurrent = pCurrent->m_pNext;

        return pCurrent;
    }
    void Sort()
    {
        for (size_t i = 0; i < m_szSize - 1 ; ++i)
            for (size_t j =0; j < m_szSize - i - 1; ++j)
            {
                auto& a = At(j);
                auto& b = At(j+1);

                if (a > b)
                    std::swap(a, b);
            }

    }
private:
    size_t m_szSize = 0;
    Node* m_pStartNode = nullptr;
    Node* m_pEndNode = nullptr;

    class Node
    {
    public:
        Node(Type data)
        {
            m_data = data;
        }

        Node* m_pNext = nullptr;

        Type  m_data;
    };


};