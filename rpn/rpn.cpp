#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

vector<double> stack;

string stackLines()
{
    ostringstream stackLinesStream;

    if (stack.empty())
    {
        return stackLinesStream.str();
    }

    for (double dbl : stack)
    {
        stackLinesStream << dbl << endl;
    }

    return stackLinesStream.str();
}

void stackAdd(double number)
{
    stack.push_back(number);
}

void stackClear()
{
    if (!stack.empty())
        stack.pop_back();
}

void stackClearAll()
{
    stack.clear();
}

double add()
{
    double result;

    if (stack.size() > 1)
    {
        result = stack[stack.size() - 2] + stack[stack.size() - 1];
        stack.pop_back();
        stack[stack.size() - 1] = result;
    }
    else if (stack.size() == 1)
    {
        result = stack[0];
    }
    else
    {
        result = 0;
    }

    return result;
}

double subtract()
{
    double result;

    if (stack.size() > 1)
    {
        result = stack[stack.size() - 2] - stack[stack.size() - 1];
        stack.pop_back();
        stack[stack.size() - 1] = result;
    }
    else if (stack.size() == 1)
    {
        result = -stack[0];
    }
    else
    {
        result = 0;
    }

    return result;
}

double multiply()
{
    double result;

    if (stack.size() > 1)
    {
        result = stack[stack.size() - 2] * stack[stack.size() - 1];
        stack.pop_back();
        stack[stack.size() - 1] = result;
    }
    else
    {
        result = 0;
    }

    return result;
}

double divide()
{
    double result;

    if (stack.size() > 1)
    {
        result = stack[stack.size() - 2] / stack[stack.size() - 1];
        stack.pop_back();
        stack[stack.size() - 1] = result;
    }
    else
    {
        result = 0;
    }

    return result;
}

double power()
{
    double result;

    if (stack.size() > 1)
    {
        result = pow(stack[stack.size() - 2], stack[stack.size() - 1]);
        stack.pop_back();
        stack[stack.size() - 1] = result;
    }
    else
    {
        result = 0;
    }

    return result;
}

double root()
{
    double result;

    if (stack.size() > 0)
    {
        result = sqrt(stack[stack.size() - 1]);
        stack[stack.size() - 1] = result;
    }
    else
    {
        result = 0;
    }

    return result;
}

double mod()
{
    double result;

    if (stack.size() > 1)
    {
        result = fmod(stack[stack.size() - 2], stack[stack.size() - 1]);
        stack.pop_back();
        stack[stack.size() - 1] = result;
    }
    else
    {
        result = 0;
    }

    return result;
}