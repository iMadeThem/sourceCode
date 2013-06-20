#include <iostream>
#include <string>

void scanDigits(char** string)
{
    while(**string != '\0' && **string >= '0' && **string <='9')
        ++(*string);
}

bool isExponential(char** string)
{
    if(**string != 'e' && **string != 'E')
        return false;

    ++(*string);

    if(**string == '+' || **string == '-')
        ++(*string);

    if(**string == '\0')
        return false;

    scanDigits(string);
    return (**string == '\0') ? true : false;
}

bool isNumeric(char* string)
{
    if(string == NULL)
        return false;

    if(*string == '+' || *string == '-')
        ++string;
    if(*string == '\0')
        return false;

    bool numeric = true;

    scanDigits(&string);
    if(*string != '\0') {
        // for floats
        if(*string == '.') {
            ++string;
            scanDigits(&string);

            if(*string == 'e' || *string == 'E')
                numeric = isExponential(&string);
        }
        // for integers
        else if(*string == 'e' || *string == 'E')
            numeric = isExponential(&string);
        else
            numeric = false;
    }

    return numeric && *string == '\0';
}

int main(int argc, char* argv[])
{
    if(argc == 1){
        std::cout << "Usage: " << argv[0] << " NUMERIC_STRING" << std::endl;
        exit(0);
    }
    std::cout << "The string \"" << argv[1] << "\"";
    std::string output = (isNumeric(argv[1])==true) ? " is numeric." : " is not numeric.";
    std::cout << output << std::endl;

    return 0;
}
