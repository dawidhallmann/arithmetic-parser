export module validation;

export module bool validate(string ex){
    
    ex.erase(remove(ex.begin(), ex.end(), ' '), ex.end()); // no spaces
    
    // for po stringu i sprawdzanie czy są tylko dozwolone znaki
    
    string dozwolone_znaki = "1234567890+-/*()[]";
    
    for (int a = 0; a<ex.size(); a++)
    if (dozwolone_znaki.find(ex[a]) == std::string::npos){
        cout << "Wykryto zakazane znaki lub symbole\n";
        return false;
    }
    
    return true;
}