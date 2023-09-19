#include <iostream>
#include <type_traits>

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

template<typename T>
void TemplatedTestCaller(T t)
{
#if __cpp_concepts
    /// @brief Thanks to C++20's Requires expressions,
    /// this can be done very easily
    /// The requires expression is able to check if the given code
    /// with the given arguements will work or not
    static constexpr auto const contains_test = requires(T t)
    {
        { t.Test(1, 2) } -> std::same_as<void>;
    };
#endif

    /// @note The type of contains_test will be a boolean
    static_assert(
        std::is_same_v<
            std::remove_cvref_t<decltype(contains_test)>,
            bool
        >
    );

    /// Take a decision at compile time whether we wish to call Test or do something else
    /// contains_test will be true only for functions where Test function with 2 integers is present
    if constexpr(contains_test)
    {
        t.Test(1, 2);
        std::cout << "Contains Test function with the correct parameters" << std::endl;
    }
    else
    {
        std::cout << "Does not contain Test function with Correct Parameters" << std::endl;
    }
}

int main()
{
    {
        ContainsFunction c;
        TemplatedTestCaller(c);
    }
    {
        ContainsFunctionWithDifferentParameters c;
        TemplatedTestCaller(c);
    }
    {
        DoesNotContainTestFunction c;
        TemplatedTestCaller(c);
    }
}