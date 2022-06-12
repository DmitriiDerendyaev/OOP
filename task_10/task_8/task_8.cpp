#include <iostream>
#include "string"

using namespace std;

enum class TokenType {
    Number,
    Operator,
};

class IToken {
public:
    virtual string getValue() = 0;
};

class Number : public IToken {
private:
    string value;
public:
    Number() = default;

    Number(string current_value) {
        value = current_value;
    }

    string getValue() override {
        return value;
    }
};

class Operator : public IToken {
private:
    string curr_operator;
public:
    Operator(const string& op) {
        curr_operator = op;
    }

    Operator(char c) {
        curr_operator = c;
    }

    string getValue() override {
        return curr_operator;
    }
};

const int LEN = 80; 
const int MAX = 40;
///////////////////////////////////////////////////////////
class Stack
{
private:
    IToken* st[MAX]; 
    int top;
public:
    Stack() 
    {
        top = 0;
    }
    void push(IToken* var)
    {
        st[++top] = var;
    }
    IToken* pop()
    {
        return st[top--];
    }
    int gettop() 
    {
        return top;
    }
};
///////////////////////////////////////////////////////////
class processing
{
private:
    Stack s; 
    char* ptrStr;
    int len;
public:
    processing(char* ptr)
    {
        ptrStr = ptr; 
        len = strlen(ptrStr); 
    }
    void parsing_expr(); 
    double solve_expr();
};
///////////////////////////////////////////////////////////
void processing::parsing_expr()
{
    char ch; 
    IToken* lastval;
    IToken* lastop;
    string current_value;
    for (int j = 0; j < len; j++)
    {
        ch = ptrStr[j];
        if ((ch >= '0' && ch <= '9') || ch == '.')
            current_value.push_back(ch);
        else
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                s.push(new Number(current_value));
                current_value = "";
                if (s.gettop() == 1)
                    s.push(new Operator(ch)); 
                else 
                {
                    lastval = s.pop(); 
                    lastop = s.pop(); 
                    if ((ch == '*' || ch == '/') && (lastop->getValue() == "+" || lastop->getValue() == "-"))
                    {
                        s.push(lastop); 
                        s.push(lastval);
                    }
                    else
                    {
                        string symb = lastop->getValue();
                        if (symb == "+") {
                            auto ans = stod(s.pop()->getValue()) + stod(lastval->getValue());
                            s.push(new Number(to_string(ans)));
                        }
                        else if (symb == "-") {
                            auto ans = stod(s.pop()->getValue()) - stod(lastval->getValue());
                            s.push(new Number(to_string(ans)));
                        }
                        else if (symb == "*") {
                            auto ans = stod(s.pop()->getValue()) * stod(lastval->getValue());
                            s.push(new Number(to_string(ans)));
                        }
                        else if (symb == "/") {
                            auto ans = stod(s.pop()->getValue()) / stod(lastval->getValue());
                            s.push(new Number(to_string(ans)));
                        }
                        else throw - 1;
                    }
                    s.push(new Operator(ch)); 
                }
            }

            else 
            {
                cout << "\nНеизвестный символ";
                exit(1);
            }
    }
    s.push(new Number(current_value));
}

///////////////////////////////////////////////////////////
double processing::solve_expr() 
{
    IToken* lastval; 
    while (s.gettop() > 1)
    {
        lastval = s.pop(); 
        string symb = s.pop()->getValue();
        if (symb == "+") 
        {
            auto ans = stod(s.pop()->getValue()) + stod(lastval->getValue());
            s.push(new Number(to_string(ans)));
        }
        else if (symb == "-") 
        {
            auto ans = stod(s.pop()->getValue()) - stod(lastval->getValue());
            s.push(new Number(to_string(ans)));
        }
        else if (symb == "*") 
        {
            auto ans = stod(s.pop()->getValue()) * stod(lastval->getValue());
            s.push(new Number(to_string(ans)));
        }
        else if (symb == "/") 
        {
            auto ans = stod(s.pop()->getValue()) / stod(lastval->getValue());
            s.push(new Number(to_string(ans)));
        }
        else throw - 1;
        
    }
    return stod(s.pop()->getValue()); //stod - строка в плавуюущую запятую
}


int main()
{

    setlocale(LC_ALL, "russian");

    char ans; 
    char string[LEN]; 
    do
    {
        cout << "\nExpression: ";
        cin >> string;
        processing* expression_ptr = new processing(string); 
        expression_ptr->parsing_expr();
        cout << "Answer: "
            << expression_ptr->solve_expr();
        delete expression_ptr; 
        cout << "\nAnother one(y/n)? ";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}