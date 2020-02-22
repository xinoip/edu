#include <iostream>
#include <string>
#include "GTUVector.h"
#include "GTUVector.cpp"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GlobalFunctions.h"

using namespace bugraStl;

void testGTUContainer(GTUContainer<int> &v, std::string name)
{
    std::cout << "==================================\n";
    std::cout << "Start of " << name << " test!\n\n";

    std::cout << "max_size(): " << v.max_size() << "\n";
    std::cout << "size(): " << v.size() << "\n";
    std::cout << "empty(): " << v.empty() << "\n-\n";

    std::cout << "Inserting values to " << name << "... \n";
    try
    {
        v.insert(5);
        v.insert(6);
        v.insert(7);
        v.insert(8);
        v.insert(3);
        v.insert(16);
        v.insert(321);
        v.insert(245);
        v.insert(-15);
        v.insert(32);
        v.insert(27);
        v.insert(56);
        v.insert(245);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    std::cout << "Insertion done! \n-\n";

    std::cout << "Printing " << name << "... \n";
    printContainer<int>(v.cbegin(), v.cend());
    std::cout << "Printing done! \n-\n";

    // erase demo
    std::cout << "Erasing values at end-4, begin+2, begin... \n";
    v.erase(v.end() - 4);
    v.erase(v.begin() + 2);
    v.erase(v.begin());
    std::cout << "Erase done! \n-\n";

    std::cout << "Printing " << name << "... \n";
    printContainer<int>(v.cbegin(), v.cend());
    std::cout << "Printing done! \n-\n";

    std::cout << "max_size(): " << v.max_size() << "\n";
    std::cout << "size(): " << v.size() << "\n";
    std::cout << "empty(): " << v.empty() << "\n-\n";

    std::cout << "\nEnd of " << name << " test!\n";
    std::cout << "==================================\n";
}

void testClearGTUContainer(GTUContainer<int> &v, std::string name)
{
    std::cout << "Clearing " << name << "... \n";
    v.clear();
    std::cout << "Clear done! \n-\n";

    std::cout << "max_size(): " << v.max_size() << "\n";
    std::cout << "size(): " << v.size() << "\n";
    std::cout << "empty(): " << v.empty() << "\n-\n";

    std::cout << "Printing " << name << "... \n";
    printContainer<int>(v.cbegin(), v.cend());
    std::cout << "Printing done! \n-\n";
}

int main(int argc, char const *argv[])
{
    GTUVector<int> v;
    GTUSet<int> set;

    testGTUContainer(v, "vector");
    testGTUContainer(set, "set");

    std::cout << "==================================\n";
    std::cout << "find() tests for vector and set\n\n";
    std::cout << "Finding value 321 in vector...\n";
    std::cout << *(find(v.begin(), v.end(), 321)) << "\n";
    std::cout << "Finding done!\n\n";

    std::cout << "Finding what element is after value 321 in set...\n";
    std::cout << *(find(set.begin(), set.end(), 321) + 1) << "\n";
    std::cout << "Finding done!\n";
    std::cout << "\nfind() tests ended!\n";
    std::cout << "==================================\n";

    std::cout << "==================================\n";
    std::cout << "find_if() tests for vector and set\n\n";
    std::cout << "Finding value that is square root of 256 in vector...\n";
    std::cout << *(find_if(v.begin(), v.end(), [](int value) {
        return (value * value == 16 * 16);
    })) << "\n";
    std::cout << "Finding done!\n\n";

    std::cout << "Finding value that is greater than 60 in set...\n";
    std::cout << *(find_if(set.begin(), set.end(), [](int value) {
        return (value > 60);
    })) << "\n";
    std::cout << "Finding done!\n";
    std::cout << "\nfind_if() tests ended!\n";
    std::cout << "==================================\n";

    std::cout << "==================================\n";
    std::cout << "for_each() tests for vector and set\n\n";
    std::cout << "Print square of every number in vector...\n";
    for_each(v.begin(), v.end(), [](int value) {
        std::cout << value * value << " ";
    });
    std::cout << "\nPrinting done!\n\n";

    std::cout << "Print odd numbers in set...\n";
    for_each(set.begin(), set.end(), [](int value) {
        if (value % 2 != 0)
        {
            std::cout << value << " ";
        }
    });
    std::cout << "\nPrinting done!\n";
    std::cout << "\nfor_each() tests ended!\n";
    std::cout << "==================================\n";


    std::cout << "==================================\n";
    testClearGTUContainer(v, "vector");
    testClearGTUContainer(set, "set");
    std::cout << "==================================\n";

    std::cout << "\n\n\n ALL TESTS ENDED\n\n\n";

    return 0;
}