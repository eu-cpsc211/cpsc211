#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void FuncRecursive()
{
    FuncRecursive();
}

void Func4()
{
    cout << "Func 4" << endl;
}

void Func3()
{
    cout << "Func 3" << endl;
    Func4();
}

void Func2()
{
    cout << "Func 2" << endl;
    Func3();
    Func4();
}

void Func1()
{
    cout << "Func 1" << endl;
    Func2();
}

/**
Main entry point for the program.
*/
int main()
{
    cout << "Main" << endl;

    Func1();

    // FuncRecursive();

    return 0;
}
