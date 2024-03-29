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

double basicParse(const std::string& expresion){
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

    std::vector<arithmeticOperation> reducedMultiply;
    for (const auto el: arithmeticExpression){
        switch (el.operation) {
            case '*':
                reducedMultiply.back().number *= el.number;
                break;
            case '/':
                reducedMultiply.back().number /= el.number;
                break;
            default:
                reducedMultiply.emplace_back(el);
                break;
        }
    }

    double result=0;
    for (const auto el: reducedMultiply){
        switch (el.operation) {
            case '+':
                result += el.number;
                break;
            case '-':
                result -= el.number;
                break;
        }
    }
    return result;
}

#endif