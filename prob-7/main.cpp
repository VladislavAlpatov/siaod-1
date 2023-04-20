//
// Created by alpat on 20.04.2023.
//
#include "Stack.h"
#include "LinkedList.h"
#include "StaticArray.h"
#include <string>
#include <iostream>


template<typename StackType>
std::string SumNumbersAsString(const std::string& num1, const std::string& num2)
{
	StackType stack1;
	StackType stack2;
	std::string result;
	int iCarry = 0;

	for (const auto chr : num1)
		stack1.Push(chr);

	for (const auto chr : num2)
		stack2.Push(chr);

	while (!stack1.IsEmpty() or !stack2.IsEmpty() or iCarry)
	{
		const auto digit1 = (!stack1.IsEmpty()) ? stack1.Pop()-'0' : 0;
		const auto digit2 = (!stack2.IsEmpty()) ? stack2.Pop()-'0' : 0;

		const auto total = digit1+digit2+iCarry;

		iCarry = total / 10;
		result = std::to_string(total%10) + result;
	}
	return result;
}


int main()
{
	auto out = SumNumbersAsString<Stack<LinkedList<char>,char>>("110", "10");

	std::cout << out;
}