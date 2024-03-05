
#include "Parser.h" 

int main() 
{
    Parser fileReader; // Создаем объект класса reader
    std::cout << "Please, input the file name: ";
    std::string fileName;
    std::getline(std::cin, fileName); // Получаем имя файла от пользователя

    const char comma = ','; // Задаем разделитель - запятая
    const char tab = '\t'; // Задаем разделитель - табуляция
    int separatorChoice;
    bool validChoice = false;

    while (!validChoice) 
    {
        // Запрашиваем у пользователя выбор разделителя
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
