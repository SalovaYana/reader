
#include "Parser.h" 

int main() 
{
    Parser fileReader; 
    std::cout << "Please, input the file name: ";
    std::string fileName;
    std::getline(std::cin, fileName); 

    const char comma = ','; 
    const char tab = '\t'; 
    int separatorChoice;
    bool validChoice = false;

    while (!validChoice) 
    {
        std::cout << "Please, select the separator of your file:" << std::endl
            << "0 - comma (,) separator" << std::endl
            << "1 - tab separator." << std::endl;
        std::cin >> separatorChoice;

        if (separatorChoice == 0) 
        {
            fileReader.parseFile(fileName, comma);
            validChoice = true;
        }
        else if (separatorChoice == 1) 
        {
            fileReader.parseFile(fileName, tab);
            validChoice = true; 
        }
        else 
        {
            std::cout << "You have entered an invalid choice." << std::endl;
        }
    }
    return 0;
}
