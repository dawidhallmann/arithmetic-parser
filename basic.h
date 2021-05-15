#ifndef basic  
#define basic

#include <vector>

class arithmeticOperation {
public:
  double number;
  char operation;
  arithmeticOperation(double number, char operation){
      this->number=number;
      this->operation=operation;
  }
};

double parse(const std::string& expresion){
    double result=0;

    std::vector<arithmeticOperation> arithmeticExpression;
    std::string currNumber;
    char currOperation='+';
    for( const auto &c : expresion ) {
        if(c=='+' || c=='-' || c=='*' || c=='/'){
            arithmeticExpression.emplace_back(std::stod(currNumber), currOperation);
            currNumber = "";
            currOperation = c;
        } else {
            currNumber += c;
        }
    }
    arithmeticExpression.emplace_back(std::stod(currNumber), currOperation);

    for (const auto el: arithmeticExpression){
        switch (el.operation) {
            case '+':
                result += el.number;
                break;
            case '-':
                result -= el.number;
                break;
            case '*':
                result *= el.number;
                break;
            case '/':
                result /= el.number;
                break;
        }
    }
    return result;
}

#endif