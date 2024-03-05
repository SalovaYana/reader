#include "Parser.h"

void Parser::parseFile(const std::string& filename, char delimiter) 
{
 
    if (filename.empty()) 
    {
        throw std::invalid_argument("Error: Empty filename provided.");
    }
    // Открываем файл для чтения
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        // Если файл не удалось открыть, выбрасываем исключение
        throw std::runtime_error("Error: Unable to open file.");
    }

    std::string line;
    // Считываем первую строку файла, содержащую заголовки столбцов
    std::getline(file, line);

    // Создаем вектор для хранения заголовков столбцов
    std::vector<std::string> columnNames;
    std::stringstream ss(line);
    std::string columnName;
    while (std::getline(ss, columnName, delimiter)) 
    {
        // Разбиваем строку на отдельные заголовки столбцов
        columnNames.push_back(columnName);
    }

    // Выводим заголовки столбцов
    for (const auto& name : columnNames) 
    {
        std::cout << name << delimiter;
    }
    std::cout << std::endl;



    // Создаем вектор для хранения данных из файла
    std::vector<std::vector<double>> data;
    // Считываем остальные строки файла
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::vector<double> row;
        std::string value;
        // Разбиваем строку на отдельные значения
        while (std::getline(ss, value, delimiter)) 
        {
            try 
            {
                // Преобразуем строковое значение в число
                double number = std::stod(value);
                row.push_back(number);
            }
            catch (const std::invalid_argument& e)
            {
                // В случае неверного формата данных выбрасываем исключение
                std::string errorMessage = "Error: Invalid data format. Invalid argument: ";
                errorMessage += e.what(); 
                throw std::runtime_error(errorMessage); 
            }

        }
        // Проверяем, что количество значений соответствует количеству столбцов
        if (row.size() != columnNames.size()) 
        {
            throw std::runtime_error("Error: Number of values does not match number of columns.");
        }
        // Добавляем строку в общий массив данных
        data.push_back(row);
    }

    // Закрываем файл
    file.close();

    // Выводим данные в консоль
    for (const auto& row : data) 
    {
        for (const auto& value : row) 
        {
            std::cout << value << delimiter;
        }
        std::cout << std::endl;
    }
}
