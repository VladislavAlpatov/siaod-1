//
// Created by alpat on 20.04.2023.
//
#include "Stack.h"
#include "LinkedList.h"
#include "StaticArray.h"
#include <string>
#include <iostream>
#include <memory>


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

void Payload()
{
	int iMode = 0;
	std::unique_ptr<IStack<int>> stack;

	printf("Choose stack type [0 - static | 1 - linked list]: ");
	std::cin >> iMode;
	if (!iMode)
		stack = std::make_unique<Stack<StaticArray<int, 256>, int>>();
	else
		stack = std::make_unique<Stack<LinkedList<int>,int>>();

	enum Operation : int
	{
		PUSH,
		PRINT_TOP,
		POP,
		CHECK,
	};


	while (true)
	{
		int iOperation = 0;

		printf("0 - Push\n1 - Print top element\n2 - Pop element\n3 - Check if stack empty\nChoose operation: ");
		std::cin >> iOperation;


		if (iOperation == PUSH)
		{
			int iNumber = 0;
			printf("Enter a number: ");
			std::cin >> iNumber;

			stack->Push(iNumber);

		}
		else if (iOperation == POP)
			stack->Pop();
		else if (iOperation == CHECK)
			(stack->IsEmpty()) ? printf("Stack is empty\n") : printf("Stack is not empty\n");
		else if (iOperation == PRINT_TOP)
			printf("Top value is: %d\n", stack->GetTop());

	}
}
void Payload2()
{
	while (true)
	{
		std::string num1, num2;

		printf("Enter number a and b: ");
		std:: cin >> num1 >> num2;

		printf("Sum is %s\n", SumNumbersAsString<Stack<LinkedList<char>,char>>(num1, num2).c_str());
	}

}
int main()
{
	printf("0 - Stack simulation\n1 - Sum numbers\nChoose operation: ");
	int iOpr;
	std::cin >> iOpr;

	(!iOpr) ? Payload() : Payload2();
}