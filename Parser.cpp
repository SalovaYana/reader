#include "Parser.h"

void Parser::parseFile(const std::string& filename, char delimiter) 
{
 
    if (filename.empty()) 
    {
        throw std::invalid_argument("Error: Empty filename provided.");
    }
  
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        
        throw std::runtime_error("Error: Unable to open file.");
    }

    std::string line;
    std::getline(file, line);


    std::vector<std::string> columnNames;
    std::stringstream ss(line);
    std::string columnName;
    while (std::getline(ss, columnName, delimiter)) 
    {
        columnNames.push_back(columnName);
    }

    for (const auto& name : columnNames) 
    {
        std::cout << name << delimiter;
    }
    std::cout << std::endl;

    std::vector<std::vector<double>> data;
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::vector<double> row;
        std::string value;

        while (std::getline(ss, value, delimiter))
        {
            if (value.empty() || value == "Na")
            {
                row.push_back(std::nan(""));
            }
            else 
            {
                try 
                {  
                    double number = std::stod(value);
                    row.push_back(number);
                }
                catch (const std::invalid_argument& e) 
                {
                    std::string errorMessage = "Error: Invalid data format. Invalid argument: ";
                    errorMessage += e.what();
                    throw std::runtime_error(errorMessage);
                }
            }
        }

        if (row.size() != columnNames.size()) 
        {
            throw std::runtime_error("Error: Number of values does not match number of columns.");
        }
        data.push_back(row);
    }

    file.close();

    for (const auto& row : data)
    {
        for (const auto& value : row)
        {
            if (std::isnan(value)) 
            { 
                std::cout << "Na" << delimiter;
            }
            else 
            {
                std::cout << value << delimiter;
            }
        }
        std::cout << std::endl;
    }

}
