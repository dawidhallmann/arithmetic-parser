#ifndef validation
#define validation

#include <cctype>

std::string charactersAllowed = "1234567890+-/*()[]. "; // spaces allowed
std::string aritmeticOperationsCharacters = "+-/*";

bool validateNumbers(std::string ex){
    for (int a = 0; a<ex.size(); a++)
        if (charactersAllowed.find(ex[a]) == std::string::npos){
            std::cout << "Wykryto zakazany symbol na pozycji " << (a+1) << "\n";
            return false;
        }
    return true;
}

bool validateStructure(std::string ex){
    bool lastCharWasAOperationCharacter=false;
    for (int a = 0; a<ex.size(); a++){
        if ((aritmeticOperationsCharacters.find(ex[a]) != std::string::npos && (a == 0 || a == ex.size()-1)) || (aritmeticOperationsCharacters.find(ex[a]) != std::string::npos && lastCharWasAOperationCharacter)){// check if not allowed character is on 1 or last position and check if operation character is after other operation character
            std::cout << "Zla struktura wyrazenia arytmetycznego\n";
            return false;
        }
        lastCharWasAOperationCharacter = aritmeticOperationsCharacters.find(ex[a]) != std::string::npos;
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
