#include <iostream>
#include <string>

void check(std::string text);
void transformation(std::string text);

int main()
{
    std::cout<<"Enter text: ";
    std::string text;
    std::getline(std::cin, text);
    check(text);
    transformation(text);
    return 0;
}

void check(std::string text) {
    int upper=0, lower=0, digit=0, space=0;
    for (size_t i = 0; i < text.length(); i++) 
    {
        if (std::isupper(text[i])) upper++;
        if (std::islower(text[i])) lower++;
        if (std::isdigit(text[i])) digit++;
        if (std::isspace(text[i])) space++;
    }
    std::cout << "Uppercase: " << upper << "; Lowercase: " << lower << "; Digits: " << digit << "; Spaces: " << space << "." << std::endl;
}

void transformation(std::string text) {
    std::cout << "String before transformation: " << text << std::endl;
    size_t i = 0;
    while (i<text.length()) {
        if (std::isspace(text[i])) text.erase(i,1);
        else i++;
    }
    
    size_t pos = 0;
    while ((pos = text.find("hello")) != std::string::npos) {
        text.replace(pos, 5, "hi");
        pos+=2;
    }

    for (size_t i = 0; i < text.length(); i++) 
    {
        char c = text[i];
        if (std::isupper(c)) text[i]=std::tolower(c);
        if (std::islower(c)) text[i]=std::toupper(c);
    }
    std::cout << "String after transformation: " << text << std::endl;
}