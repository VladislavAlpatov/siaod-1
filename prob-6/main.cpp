//
// Created by alpat on 29.03.2023.
//
#include <string>


bool isBalanced(const std::string& s, int index = 0, int open = 0)
{
    if (index == s.size())
        return open == 0;

    if (s[index] == '(')
        return isBalanced(s, index + 1, open + 1);

    if (s[index] != ')')
        return isBalanced(s, index + 1, open);

    if (open > 0)
        return isBalanced(s, index + 1, open - 1);

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
bool CheckIfDevBySelfNumberRecursive(int iNumber)
{
    if (!iNumber)
        return true;
    auto iLastDigit = iNumber % 10;

    if (!iLastDigit or iNumber % iLastDigit)
        return false;

    return CheckIfDevBySelfNumberRecursive(iNumber / 10);
}
int main()
{
    if (CheckIfDevBySelfNumberRecursive(93665))
        printf("ok\n");
}
