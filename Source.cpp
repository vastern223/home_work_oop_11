#include<iostream>
#include<string>
#include"Stack.h"
#include"Stack.cpp"
using namespace std;

void Correctness_check(string str);

int main()
{
    string code = "void main(){ Stack st(10); }";
    Correctness_check(code);
	system("pause");
	return 0;
}

void Correctness_check(string str)
{
    enum ScopeType
    {
        CIRCLE_IN = '(',
        CIRCLE_OUT = ')',
        SQUARE_IN = '[',
        SQUARE_OUT = ']'
    };
    string other;
    Stack<char>scopes;

    for (char s : str)
    {
        other += s;

        switch (s)
        {
        case CIRCLE_IN:
            scopes.Push(s);
            break;
        case  SQUARE_IN:
            scopes.Push(s);
            break;

        case CIRCLE_OUT:
            if (scopes.Peek() == CIRCLE_IN)
                scopes.Pop();
            else
            {
                cout << other << endl;
               cout << "Error at symbol: " << s << endl;
            }
            break;

        case SQUARE_OUT:

            if (scopes.Peek() == SQUARE_IN)
                scopes.Pop();
            else
                cout << other << endl;
                cout << "Error at symbol: " << s << endl;
            break;
        }
    }
    if (!scopes.IsEmpty())
    {
        cout << other << endl;
        cout << "Error!" << endl;
    }
    else
        cout << "Correct code!\n";
}