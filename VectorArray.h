//
// Created by alpat on 14.02.2023.
//

#pragma once
#include "IArray.h"
#include <vector>
template<typename Type>
class VectorArray : public std::vector<Type> , public IArray<Type>
{
public:
    void insert(const size_t &index, const Type &val) override
    {
        if (index >= this->size() or index < 0)
            throw "Segfault";

        std::vector<Type>::insert(this->begin()+index, val);
    }

    void remove_if(bool (*check)(const Type &)) override
    {
        for (size_t i = 0; i < this->size(); i++)
            if (check(this->at(i)))
                this->erase(this->begin()+i);

    }

    void push_back(const Type &val) override
    {
        std::vector<Type>::push_back(val);
    }

    ~VectorArray() override = default;

    Type& operator[](const size_t& index) override
    {
        return std::vector<int>::operator[](index);
    }
    size_t GetSize() const override {return this->size();}
    size_t find_last(bool (*check)(const Type &)) override
    {
        for (int i = this->size()-1; i >= 0; i--)
            if (check(this->at(i)))
                return i;
        throw "NotFound";
    }
};
