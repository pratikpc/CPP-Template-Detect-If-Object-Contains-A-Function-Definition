#include <iostream>

struct ContainsFunction
{
    void Test(int x, int y)
    {

    }
};

struct ContainsFunctionWithDifferentParameters
{
    void Test(int x)
    {

    }
};

struct DoesNotContainTestFunction
{
    void DifferentFunction(int x)
    {
        
    }
};



int main()
{
    std::cout << "Executing code" << std::endl;
}