// Šuráb, Denis 1DAE13
#include <iostream>
#include <string>

int g_Count{};

void AddString(std::string& text);
int& GetSmallest(int& a, int& b);

int CalcSum(int number);

int main()
{
    //std::cout << "Hello World!\n";

    std::string name{"Fen"};
    AddString(name);
    std::cout << name << "\n";

    int a{ 2 }, b{ 7 };

    int& result = GetSmallest(a, b);
    result *= 2;
    std::cout << a << ' ' << b << '\n';

    int sum{CalcSum(4757)};
    std::cout << sum;
}

void AddString(std::string& text)
{
    text += " Ming";
}

int& GetSmallest(int& a, int& b)
{
    if (a < b) return a;
    return b;
}

int CalcSum(int number)
{
    ++g_Count;
    std::cout << g_Count << '\n';

    if (number == 1) return 1;
    return number + CalcSum(number - 1);
}