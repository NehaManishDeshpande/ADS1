#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string infix) {
    string prefix = "";
    stack<char> stack;
    reverse(infix.begin(), infix.end());

    for (char &c : infix) {
        if (isalnum(c)) {
            prefix = c + prefix;
        } else if (c == ')') {
            stack.push(c);
        } else if (c == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix = stack.top() + prefix;
                stack.pop();
            }
            if (!stack.empty() && stack.top() == ')')
                stack.pop();
        } else {
            while (!stack.empty() && precedence(c) < precedence(stack.top())) {
                prefix = stack.top() + prefix;
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        prefix = stack.top() + prefix;
        stack.pop();
    }

    return prefix;
}

int main() {
    string infix_expression;
    cout << "Enter the infix expression: ";
    getline(cin, infix_expression);

    string prefix = infixToPrefix(infix_expression);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
