#include <iostream>
#include <string>
#include <sstream>
#include "rpn/rpn.cpp"
#include "extensions/stringext.cpp"
using namespace std;

string history;

string numToString(double number)
{
    ostringstream toString;

    toString << number;

    return toString.str();
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "C++ RPN Console Calculator; Enter one expression part at a time." << endl;
        cout << "-----------------------------History----------------------------" << endl;
        cout << history;
        cout << "------------------------------Stack-----------------------------" << endl;
        cout << stackLines();
        cout << "----------------------------------------------------------------" << endl;

        string input;
        getline(cin, input);

        double inputNumber;
        bool isNumber = true;

        try
        {
            inputNumber = stod(input);
        }
        catch (...)
        {
            isNumber = false;
        }

        if (!isNumber)
        {
            for (auto &c : input)
                c = toupper(c);

            trim(input);

            bool shouldSaveHistory = true;

            if (input == "+")
            {
                add();
            }
            else if (input == "-")
            {
                subtract();
            }
            else if (input == "*")
            {
                multiply();
            }
            else if (input == "/")
            {
                divide();
            }
            else if (input == "^" || input == "**")
            {
                power();
            }
            else if (input == "SQRT")
            {
                root();
            }
            else if (input == "C")
            {
                stackClear();
            }
            else if (input == "AC")
            {
                stackClearAll();
                history = "";
                continue;
            }
            else
            {
                cout << "Valid inputs:" << endl;
                cout << "Operands: Add +, Subtract -, Multiply *, Divide /, Exponential ^ or **" << endl;
                cout << "Square Root: SQRT" << endl;
                cout << "Clear: C, All Clear: AC" << endl;
                cout << "Example valid expression:" << endl
                     << "5" << endl
                     << "6" << endl
                     << "+" << endl
                     << "[returns 11, removes 5 and 6, and places 11 bottom of the stack]" << endl;
                cout << "Press Enter to continue..." << endl;
                cin.get();
                continue;
            }

            history += input;
            history += "\n";
        }
        else
        {
            stackAdd(inputNumber);
            history += numToString(inputNumber);
            history += "\n";
        }
    }

    return 0;
}