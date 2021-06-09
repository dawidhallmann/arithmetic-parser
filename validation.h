#ifndef validation
#define validation

#include <cctype>
#include <regex>

std::string charactersAllowed = "1234567890+-/*.()[] "; // spaces allowed
std::string aritmeticOperationsCharacters = "+-/*";

bool validateBrackets(std::string ex){
    /*
        open -> '(['
        close -> ')]'
    */
    std::string brackets = "((]]";
    std::string bracketsType1Open = "(";
    std::string bracketsType2Open = "[";
    std::string bracketsType1Close = ")";
    std::string bracketsType2Close = "]";

    int bracketsType1OpenCount = 0;
    int bracketsType2OpenCount = 0;
    int bracketsType1CloseCount = 0;
    int bracketsType2CloseCount = 0;

    bool lastCharWasAOperationCharacter=false;
    bool lastWasBracket=false;

    for (char a : ex){

        if (bracketsType1Open.find(a) != std::string::npos){
            bracketsType1OpenCount++;

            if(lastWasBracket && aritmeticOperationsCharacters.find(a) != std::string::npos){
                std::cout << "Blad: znak arytmetyczny za nawiasem\n";
                return false;
            }
        }
        if (bracketsType2Open.find(a) != std::string::npos){
            bracketsType2OpenCount++;

            if(lastWasBracket && aritmeticOperationsCharacters.find(a) != std::string::npos){
                std::cout << "Blad: znak arytmetyczny za nawiasem\n";
                return false;
            }
        }
        if (bracketsType1Close.find(a) != std::string::npos){
            bracketsType1CloseCount++;

            if(bracketsType1OpenCount < bracketsType1CloseCount){
                std::cout << "Blad: nazwias zamykajacy przed otwierajacym\n";
                return false;
            }

            if(lastCharWasAOperationCharacter){
                std::cout << "Blad: nazwias zamykajacy przed znakiem dzialania\n";
                return false;
            }
        }
        if (bracketsType2Close.find(a) != std::string::npos){
            bracketsType2CloseCount++;

            if(bracketsType2OpenCount < bracketsType2CloseCount){
                std::cout << "Blad: nazwias zamykajacy przed otwierajacym\n";
                return false;
            }

            if(lastCharWasAOperationCharacter){
                std::cout << "Blad: nazwias zamykajacy przed znakiem dzialania\n";
                return false;
            }
        }

        lastCharWasAOperationCharacter = aritmeticOperationsCharacters.find(a) != std::string::npos;
        lastWasBracket = brackets.find(a) != std::string::npos;

    }

    if(bracketsType1OpenCount != bracketsType1CloseCount || bracketsType2OpenCount != bracketsType2CloseCount){
        std::cout << "Zla ilosc nawiasow\n";
        return false;
    }

    return true;
}

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

    for (char a : ex)
        if (charactersAllowed.find(a) == std::string::npos){
            std::cout << "Zla struktura wyrazenia arytmetycznego\n";
            return false;
        }
    return true;
}

bool validate(const std::string& ex){
    if(!validateBrackets(ex))
        return false;
    if(!validateNumbers(ex))
        return false;
    if(!validateStructure(ex))
        return false;
    return true;
}
#endif