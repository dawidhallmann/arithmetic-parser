#include <iostream>

#include <validation.h>
#include <basic.h>

int main() {
    std::string expression;
    
    while (std::cin >> expression){
        if(validate(expression)){
            parse(expression);
        }
    }
    return 0;
}