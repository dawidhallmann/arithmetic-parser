#include <iostream>
#include <string>

#include <validation.h>
#include <basic.h>

/* codeblocks
#include "validation.h" 
#include "basic.h"
*/

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