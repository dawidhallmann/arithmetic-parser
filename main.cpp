#include <iostream>
#include <string>

#include <validation.h>
#include <basic.h>

int main() {
    std::string expression;
    while (std::getline(std::cin, expression)){
        if(validate(expression)){
            std::cout << parse(expression);
        }
    }
    return 0;
}
