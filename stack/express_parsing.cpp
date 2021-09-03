// Pares a stirng of expression double and calculate its value
#include <bits/stdc++.h>

using namespace std;
map<char, int> priority = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}
};
template <typename T>
void print(stack<T> s){
    cout << "[ ";
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << " ]\n";
}
void calSub(stack<double>& coefficientNumbers, stack<char>& operators){
    char topOp = operators.top();
    operators.pop();
    if (coefficientNumbers.size()>=2) {
        double x2 = coefficientNumbers.top();
        coefficientNumbers.pop();
        double x1 = coefficientNumbers.top();
        coefficientNumbers.pop();
        double rs;
        switch (topOp)
        {
        case '+':
            rs = x1 + x2;
            break;
        case '-':
            rs = x1 - x2;
            break;
        case '*':
            rs = x1 * x2;
            break;
        case '/':
            rs = x1/x2;
            break;
        case '^':
            rs = pow(x1, x2);
            break;
        default:
            break;
        }
        coefficientNumbers.push(rs);
    }
}

double parse(string exp, int* index){
    stack<double> coefficientNumbers;
    stack<char> operators;
    string coefficient = "";
    while (*index < exp.length() && exp[*index] != ')'){ // End of term
        char c = exp[*index];
        // printf("---------------------\n");
        // print(coefficientNumbers);
        // printf("Current char %c \n", c);
        if (c==' '){
            *index = *index + 1;
            continue;
        } else if (isdigit(c)|| c=='.'){
            coefficient.push_back(c);
            *index = *index + 1;
            continue;
        } else if (priority.count(c)) {
            if (coefficient !=""){
                double coef = stod(coefficient);
                coefficient = "";
                coefficientNumbers.push(coef);
            }
            while (!operators.empty() && priority[operators.top()] >= priority[c]) {
                calSub(coefficientNumbers, operators);
            }
            operators.push(c);
            *index = *index + 1;
        } else if (c =='('){
            *index = *index + 1;
            double val = parse(exp, index);
            coefficientNumbers.push(val);
            continue;
        } else {
            throw "Invalid express";
        }
    }
    if (coefficient !=""){
        double coef = stod(coefficient);
        coefficient = "";
        coefficientNumbers.push(coef);
    }

    while (coefficientNumbers.size() > 1) {
        // print(coefficientNumbers);
        calSub(coefficientNumbers, operators);
    }
    double ret = coefficientNumbers.top();
    coefficientNumbers.pop();
    if (!coefficientNumbers.empty()) {
        throw "Not valid expression";
    }
    if (exp[*index] == ')') {
        *index = *index + 1;
    }
    return ret;
}
double cal(string exp){
    int i = 0;
    return parse(exp, &i);
}
int main(){
    string exp = "(1+2)*(3+4) - 1- 2 -3*2";
    cout << cal(exp) << endl;
    return 0; 
}