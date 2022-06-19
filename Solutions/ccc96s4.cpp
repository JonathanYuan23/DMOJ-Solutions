#include <bits/stdc++.h>
using namespace std;

struct Solver
{
    // data members
    string numOne, numTwo;
    string symbols[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    int numOneVal, numTwoVal;
    int values[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    // members methods
    int toInt(string num);
    int symbolValue(string symbol, string next);
    int binarySearch(int num);

    string toString(int num);

    void extractNums(string expression);
    void output();
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int Q;
    cin >> Q;
    Solver solver;
    while (Q--)
    {
        string expression;
        cin >> expression;
        solver.extractNums(expression);
        solver.output();
    }

    return 0;
}

int Solver::toInt(string num)
{
    int sum = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (i == num.length() - 1)
            sum += symbolValue(num.substr(i, 1), "\0");
        else
            sum += symbolValue(num.substr(i, 1), num.substr(i + 1, 1));
    }
    return sum;
}

int Solver::symbolValue(string symbol, string next)
{
    int index = distance(symbols, find(symbols, symbols + 13, symbol));
    if ((symbol == "I" && (next == "V" || next == "X")) ||
        (symbol == "X" && (next == "L" || next == "C")) ||
        (symbol == "C" && (next == "D" || next == "M")))
        return -values[index];
    else
        return values[index];
}

int Solver::binarySearch(int num)
{
    int l = 0, r = 12, ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (values[m] <= num)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

string Solver::toString(int num)
{
    string ans = "";
    while (num)
    {
        // 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
        // I, IV, V, IX, X, XL, L, XC, C, CD, D, CM, M
        int index = binarySearch(num);
        num -= values[index];
        ans += symbols[index];
    }
    return ans;
}

void Solver::extractNums(string expression)
{
    expression.pop_back();
    size_t index = expression.find('+');
    numOne = expression.substr(0, index);
    numTwo = expression.substr(index + 1);
    numOneVal = toInt(numOne);
    numTwoVal = toInt(numTwo);
}

void Solver::output()
{
    int sum = numOneVal + numTwoVal;
    cout << numOne + '+' + numTwo + '=' << (sum > 1000 ? "CONCORDIA CUM VERITATE" : toString(sum)) << '\n';
}
