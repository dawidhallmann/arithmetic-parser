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
    std::vector<arithmeticOperation> arithmeticExpression;
    std::string currNumber;
    char currOperation='+';
    for( const auto &c : expresion ) {
        if(c=='+' || c=='-' || c=='*' || c=='/'){
//          currNumber could be one of ["2.5.2", ".56", "23.", "."]
//          although it may be good idea to allow ".14" format and just remove dot from "65." format
//          create function to validate it here or validate it in validate()
//          i think that validating here would be easier but its up to you
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