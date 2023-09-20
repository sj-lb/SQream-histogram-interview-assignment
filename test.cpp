#include <iostream>

void func1(char *str)
{
    *str = 'H';
}

void func1(const char *str)
{
    // do nothing
    static_cast<void>(str);
}

int main()
{
    char str1[6] = "hello";
    const char *str2 = "hello";

    func1(str1);
    func1(str2);

    std::cout << str1 << std::endl << str2 << std::endl;
}

// conclusion: functions in which the only difference is the constness
// of arguments can indeed be overloaded