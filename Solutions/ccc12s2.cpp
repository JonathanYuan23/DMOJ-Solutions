#include <bits/stdc++.h>
using namespace std;

class ARAR
{
private:
    string number;
    unordered_map<char, int> dict;

public:
    ARAR(string);
    int calc();
    int add(ARAR);
    int subtract(ARAR);
    int multiply(ARAR);
    int divide(ARAR);
    int modulo(ARAR);
};

int main()
{
    string s;
    cin >> s;
    ARAR aromatic(s);
    cout << aromatic.calc() << '\n';
}

ARAR::ARAR(string number)
    : number(number)
{
    dict['I'] = 1;
    dict['V'] = 5;
    dict['X'] = 10;
    dict['L'] = 50;
    dict['C'] = 100;
    dict['D'] = 500;
    dict['M'] = 1000;
}

int ARAR::calc()
{
    int value = 0;
    for (int i = 0; i < number.length() - 2; i += 2)
    {
        int A = number[i] - 48, R = dict[number[i + 1]], AP = number[i + 2] - 48, RP = dict[number[i + 3]];
        value += (RP > R) ? -(A * R) : (A * R);
    }
    value += (number[number.length() - 2] - 48) * dict[number[number.length() - 1]];
    return value;
}

int ARAR::add(ARAR b)
{
    return this->calc() + b.calc();
}

int ARAR::subtract(ARAR b)
{
    return this->calc() - b.calc();
}

int ARAR::multiply(ARAR b)
{
    return this->calc() * b.calc();
}

int ARAR::divide(ARAR b)
{
    return this->calc() / b.calc();
}

int ARAR::modulo(ARAR b)
{
    return this->calc() % b.calc();
}
