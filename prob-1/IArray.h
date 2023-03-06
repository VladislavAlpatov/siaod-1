//
// Created by alpat on 14.02.2023.
//
#pragma once

template<typename Type>
class IArray
{
public:
    virtual void insert(const size_t& index, const Type& val) = 0;
    virtual void remove_if(bool(check)(const Type& val)) = 0;
    virtual void push_back(const Type& val) = 0;
    virtual Type& operator[](const size_t& index) = 0;
    virtual size_t find_last(bool(check)(const Type& val)) = 0;
    virtual size_t GetSize() const = 0;
    virtual ~IArray() = default;
};
