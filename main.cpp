#include "DynamicArray.h"
#include "StaticArray.h"
#include "VectorArray.h"


#include <iostream>
#include <string>
#include <memory>
#include <random>

void PrintArray(std::unique_ptr<IArray<int>>& pArr)
{
    for (int i = 0; i < pArr->GetSize(); i++)
        printf("%d ", (*pArr)[i]);
    printf("\n");
}

void Payload(std::unique_ptr<IArray<int>>& pArr)
{
    size_t index = 0;
    int     val;

    while (true)
    {
        int mode = 0;
        printf("1 - Insert\n2 -Find magic number \n3 - remove element if (num % 5)\n4 - Print array\n Choose operation: ");
        std::cin >> mode;

        switch (mode)
        {
            case 1:
                printf("\nEnter index insert to: ");
                std::cin >> index;

                printf("Enter value: ");
                std::cin >> val;

                pArr->insert(index, val);
                break;
            case 2:
                printf("Index of last suitable number: %zu\n", pArr->find_last([](const int& num) ->bool
                                                                               {
                                                                                   if (abs(num) < 10)
                                                                                       return false;
                                                                                   auto tmp =  std::to_string(abs(num));

                                                                                   return tmp.front() == tmp.back();
                                                                               }));
                break;
            case 3:
                pArr->remove_if([](const int& num){return !(num % 5);});
                break;
            case 4:
                PrintArray(pArr);
                break;
            default:
                return;
        }
    }
}

std::unique_ptr<IArray<int>> MakeArrayByMode(const int mode)
{
    switch (mode)
    {
        case 1: return std::make_unique<StaticArray<int, 256>>();
        case 2: return std::make_unique<DynamicArray<int>>();
        case 3: return std::make_unique<VectorArray<int>>();
        default: throw "WRONG MODE";
    }
}

void ManualArraySet(std::unique_ptr<IArray<int>>& pArr)
{
    printf("Enter numbers: ");
    std::string data;

    while (true)
    {
        try
        {
            std::cin >> data;
            pArr->push_back(std::stoi(data));
        }
        catch (...)
        {
            return;
        }

    }
}

void AutomaticArraySet(std::unique_ptr<IArray<int>>& pArr)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(-1000,1000);

    for (int i = 0; i < 10; i++)
        pArr->push_back(uni(rng));
}

int main()
{
    try
    {
        int mode = 0;
        printf("Choose array type:\n1 - Static\n2 - Dynamic\n3 - Vector\n");
        std::cin >> mode;

        auto pArray = MakeArrayByMode(mode);


        int iTestMode = 0;
        printf("Set mode [0-manual|1-auto]:");

        std::cin >> iTestMode;
        (!iTestMode) ? ManualArraySet(pArray) : AutomaticArraySet(pArray);

        Payload(pArray);

    }
    catch (const char* ptr)
    {
        printf("Error: %s", ptr);
    }

}