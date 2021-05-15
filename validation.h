#ifndef validation
#define validation

#include <cctype>

std::string charactersAllowed = "1234567890+-/*()[] "; // spaces allowed
bool validate(std::string ex){
    for (int a = 0; a<ex.size(); a++)
        if (charactersAllowed.find(ex[a]) == std::string::npos){
            std::cout << "Wykryto zakazany symbol\n" << "na pozycji " << (a+1) << "\n";
            return false;
        }
    return true;
}
#endif
