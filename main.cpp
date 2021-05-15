#include <iostream>

#include <validation.h>
#include <basic.h>

int main() {
    char expression[100];
    
    while (std::cin >> expression){
        if(validate(expression)){
            parse(expression);
        }
    }
    return 0;
}