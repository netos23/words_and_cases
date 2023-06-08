#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Utils
{
public:
    Utils();

public:
    static std::vector<std::string> readTextFromFile(std::string fileName);
    static void writeTextToFile(std::string fileName, std::string text);
    static std::string fromPairsToString(std::vector<std::pair<std::string, std::string>> pairs);
    static std::string fromVectorToString(std::vector<std::string> string);
    static std::vector<std::string> fromStringToVector(std::string string);
    static void createAndWriteToFile(std::string fileName, std::string text);
    static std::vector<std::string> fromLabelStringToVector(std::string string);
};

#endif // UTILS_H
