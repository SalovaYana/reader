#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>

class Parser 
{
public:
    static void parseFile(const std::string& filename, char delimiter);
};
