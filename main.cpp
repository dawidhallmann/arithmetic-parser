#include <iostream>
#include <string>

#include <validation.h>
#include <basic.h>

/* codeblocks
#include "validation.h" 
#include "basic.h"
*/

int defaultCharPosition=0;
double parse(const std::string& expression, int &charPosition=defaultCharPosition){
    std::string nestedExpression;
    for (; charPosition<expression.size(); charPosition++){
        if(expression[charPosition] == '('){
            charPosition++;
            nestedExpression += std::to_string(parse(expression, charPosition));
        }
        else if(expression[charPosition] == ')') return basicParse(nestedExpression);
        else nestedExpression += expression[charPosition];
    }
    charPosition=0;
    return basicParse(nestedExpression);
}

int main() {
    std::string expression;

    std::cout << "Wpisz dzialanie\n";

    while (std::getline(std::cin, expression)){
        if(validate(expression)){
            std::cout << parse(expression) << "\n";
        }
    }
    return 0;
}