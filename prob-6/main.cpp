//
// Created by alpat on 29.03.2023.
//
#include <string>
#include <iostream>
#include "LinkedList.h"


bool IsBalanced(LinkedList<char>& s, int index = 0, int open = 0)
{
    if (index == s.Size())
        return open == 0;

    if (s.At(index) == '(')
        return IsBalanced(s, index + 1, open + 1);

    if (s.At(index) != ')')
        return IsBalanced(s, index + 1, open);

    if (open > 0)
        return IsBalanced(s, index + 1, open - 1);

    return false;
}

bool CheckIfDevBySelfNumber(int iNumber)
{
    int tmp = iNumber;

    while (tmp)
    {
        const auto last = tmp % 10;
        if (!last or iNumber % last)
            return false;
        tmp /= 10;
    }
    return true;
}
bool CheckIfDevBySelfNumberRecursive(int originalNum, int num)
{
	auto iLast = num % 10;
	num /= 10;

	if (num == 0)
		return true;

	if (iLast == 0 or originalNum % iLast)
		return false;

	if(CheckIfDevBySelfNumberRecursive(originalNum, num))
		return true;

	return false;
}
int main()
{
	while (true)
	{
		printf("\n0 - Check balance of bracket\n1 - Check self number digits divisibility\nChoose operation: ");
		int iMode;
		std::cin >> iMode;

		if (iMode == 0)
		{
			std::string exrp;
			printf("Enter mathematics expression: ");
			std::cin >> exrp;
			LinkedList<char> tmp;

			for (auto chr : exrp)
				tmp.PushBack(chr);

			(IsBalanced(tmp)) ? printf("Expression is balanced\n") : printf("Expression is not balanced\n");
			continue;
		}
		int val = 0;
		int iRecursive;
		printf("Enter value: ");
		std::cin >> val;
		printf("Use recursive algorithm? [0 - no | 1 - yes]: ");
		std::cin >> iRecursive;

		if ((iRecursive) ? CheckIfDevBySelfNumberRecursive(val, val) : CheckIfDevBySelfNumber(val))
		{
			printf("All self digits of number dived it!\n");
		}
		else
		{
			printf("Nope :(\n");
		}

	}

}
