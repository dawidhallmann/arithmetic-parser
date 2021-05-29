#ifndef validation
#define validation

#include <cctype>
#include <regex>

std::string charactersAllowed = "1234567890+-/*. "; // spaces allowed
std::string aritmeticOperationsCharacters = "+-/*";

bool validateNumbers(std::string ex){
    std::string str = ex;
    std::string const delims{aritmeticOperationsCharacters};
    size_t beg, pos = 0;
    while ((beg = str.find_first_not_of(delims, pos)) != std::string::npos){
        pos = str.find_first_of(delims, beg + 1);
        std::string number = str.substr(beg, pos - beg);
        std::regex reg1("-?[0-9]+.?[0-9]+");
        std::regex reg2("-?[0-9]+");
        if(!std::regex_match(number,reg1) && !std::regex_match(number,reg2)){
            std::cout << "Zla struktura liczby\n";
            return false;
        }
    }
    return true;
}

bool validateStructure(std::string ex){
    bool lastCharWasAOperationCharacter=false;
    for (int a = 0; a<ex.size(); a++){
        if (
            (aritmeticOperationsCharacters.find(ex[a]) != std::string::npos && (a == 0 || a == ex.size()-1)) ||
            (aritmeticOperationsCharacters.find(ex[a]) != std::string::npos && lastCharWasAOperationCharacter)
            ){// check if not allowed character is on 1 or last position and check if operation character is after other operation character
            std::cout << "Zla struktura wyrazenia arytmetycznego\n";
            return false;
        }
        lastCharWasAOperationCharacter = aritmeticOperationsCharacters.find(ex[a]) != std::string::npos;
    }

    for (int a = 0; a<ex.size(); a++)
        if (charactersAllowed.find(ex[a]) == std::string::npos){
            std::cout << "Zla struktura wyrazenia arytmetycznego\n";
            return false;
        }
    return true;
}

bool validate(std::string ex){
    if(!validateNumbers(ex))
        return false;
    if(!validateStructure(ex))
        return false;
    return true;
}
#endif
