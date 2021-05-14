#include <iostream>

#include <fstream>

import validation;
import basic;

int main() {
    string expression;
    
    while (cin >> expression){
        if(validate(expression)){
            parse(expression);
        }
    }
    return 0;
}