#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void _err_exp()
{
    throw runtime_error("Illegal expression.");
	//cerr << "Illegal expression." << endl;
	//exit(-1);
}

double ConvertToCorrectDouble(const string& s)
{
	queue<char> myQueue;
	double Num=0.0;
	double decimalFactor = 0.1;
	bool foundDecimal = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			if (foundDecimal)
			{
                _err_exp();
			}
			else
				foundDecimal = true;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (foundDecimal)
			{
				Num = Num + (s[i] - '0') * decimalFactor;
				decimalFactor *= 0.1;
			}
			else
			{
				Num = Num * 10.0 + (s[i] - '0');
			}
		}
	}
	
	return Num;

}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


int getPrecedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0; // 默认优先级为0
}


queue<string> ConvertToPostfix(const string& infix) {
    stack<char> op;
    queue<string> exp;
    string currentNumeric;

    for (char c : infix) {
        if (c == '\n') {
            break;
        }

        if (c == '\t' || c == ' ') {
            continue;
        }

        if (isdigit(c) || (c == '.' && isdigit(currentNumeric.back())))
        {
            currentNumeric += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (!currentNumeric.empty())
            {
                exp.push(currentNumeric);
                currentNumeric.clear();
            }
            while (!op.empty() && isOperator(op.top()) && getPrecedence(op.top()) >= getPrecedence(c))
            {
                exp.push(string(1, op.top()));
                op.pop();
            }
            op.push(c);
        }
        else if (c == '(')
        {
            if (!currentNumeric.empty())
            {
                exp.push(currentNumeric);
                currentNumeric.clear();
            }
            op.push(c);
        }
        else if (c == ')')
        {
            if (!currentNumeric.empty())
            {
                exp.push(currentNumeric);
                currentNumeric.clear();
            }
            while (!op.empty() && op.top() != '(')
            {
                exp.push(string(1, op.top()));
                op.pop();
            }
            if (!op.empty() && op.top() == '(')
            {
                op.pop(); // 弹出左括号
            }
            else
                _err_exp(); // 没有匹配的左括号
        }
        //else
            //_err_exp();
    }

    if (!currentNumeric.empty())
    {
        exp.push(currentNumeric);
    }
    while (!op.empty())
    {
        if (op.top() == '(')
        {
            _err_exp(); // 没有匹配的右括号
        }
        exp.push(string(1, op.top()));
        op.pop();
    }

    return exp;
}

bool isOperator(const string& t)
{
    return (t == "+" || t == "-" || t == "*" || t == "/");
}

double calculatePostfix(queue<string>& postfix)
{
    stack<double> operandStack;

    while (!postfix.empty())
    {
        string t = postfix.front();
        //cout << t<<endl;
        postfix.pop();

        if (isdigit(t[0]) || t[0] == '-' && t.size() > 1)
        {
            double number = ConvertToCorrectDouble(t);
            operandStack.push(number);
        }
        else if (isOperator(t[0]))
        {
            if (operandStack.size() < 2)
            {
                cout << "Invalid postfix expression." << endl;
                _err_exp();
            }
            else
            {
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();

                if (t == "+")
                {
                    operandStack.push(operand1 + operand2);
                    //cout << operand1 << "+" << operand2 << "=" << operand1 + operand2 << endl;
                }
                else if (t == "-")
                {
                    operandStack.push(operand1 - operand2);
                    //cout << operand1 << "-" << operand2 << "=" << operand1 - operand2 << endl;
                }
                else if (t == "*")
                {
                    operandStack.push(operand1 * operand2);
                    //cout << operand1 << "*" << operand2 << "=" << operand1 * operand2 << endl;
                }
                else if (t == "/")
                {
                    if (operand2 == 0)
                    {
                        cout << "Division by zero." << endl;
                        _err_exp();
                    }
                    operandStack.push(operand1 / operand2);
                    //cout << operand1 << "/" << operand2 << "=" << operand1 / operand2 << endl;
                }

            }
        }
        //else
            //_err_exp();
    }
    if (operandStack.size() != 1)
    {
        cout << "Invalid postfix expression." << endl;
        _err_exp();
     }
    return operandStack.top();
}
