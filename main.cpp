#include "DynamicArray.h"
#include "StaticArray.h"
#include <iostream>
#include "VectorArray.h"
#include <string>
#include <memory>


int main()
{
    std::unique_ptr<IArray<int>> pArray;
    try
    {
        int mode = 0;
        printf("Choose array type:\n1 - Static\n2 - Dynamic\n3 - Vector\n");
        std::cin >> mode;

        switch (mode)
        {
            case 1:
                pArray = std::make_unique<StaticArray<int, 256>>();
                break;
            case 2:
                pArray = std::make_unique<DynamicArray<int>>();
                break;
            case 3:
                pArray = std::make_unique<VectorArray<int>>();
                break;
            default: throw "WRONG MODE";
        }

        for (int i = 0; i < 101; i++)
        {
            pArray->push_back(i);
            printf("%d ", i);
        }

        size_t index = 0;
        int     val;

        printf("\nEnter index insert to: ");
        std::cin >> index;

        printf("Enter value: ");
        std::cin >> val;

        pArray->insert(index, val);
        printf("Index of last suitable number: %zu\n",
               pArray->find_last([](const int& num) ->bool
                                 {
                                     if (abs(num) < 10)
                                         return false;
                                     auto tmp =  std::to_string(abs(num));

                                     return tmp.front() == tmp.back();
                                 }));


        pArray->remove_if([](const int& num){return !(num % 5);});

        for (int i = 0; i < pArray->GetSize(); i++)
            printf("%d ", (*pArray)[i]);
    }
    catch (const char* ptr)
    {
        printf("Error: %s", ptr);
    }

}