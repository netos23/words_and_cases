#include "utils.h"

Utils::Utils(){}

void Utils::writeTextToFile(std::string fileName, std::string text)
{
    std::ofstream file;
    file.open(fileName);
    if (!file) {
        throw "file is not open";
    }
    file << text;
    file.close();
}

std::vector<std::string> Utils::readTextFromFile(std::string fileName)
{
    std::vector<std::string> strings;
    std::ifstream myFile;
    myFile.open(fileName);
    if (!myFile) {
        throw "file is not open";
    }
    std::string str;
    while(true) {
        if(myFile.eof()) break;
        str = "";
        myFile >> str;
        strings.push_back(str);
    }
    myFile.close();
    return strings;
}

std::string Utils::fromPairsToString(std::vector<std::pair<std::string, std::string>> pairs)
{
    std::string resString = "";
    for (std::pair<std::string, std::string> pair: pairs)
    {
        resString += pair.first + "(" + pair.second + ")\n";
    }
    return resString;
}

std::string Utils::fromVectorToString(std::vector<std::string> strings)
{
    std::string resString = "";
    for (std::string str: strings)
    {
        resString += str + "\n";
    }
    return resString;
}

std::vector<std::string> Utils::fromLabelStringToVector(std::string string)
{
    std::vector<std::string> strings;
    size_t start = 0;
    for (size_t i = 0; i < string.length(); ++i) {
        if (string[i] == '\n')
        {
            strings.push_back(string.substr(start, i + 1));
            start = i + 1;
        }
    }
    return strings;
}

std::vector<std::string> Utils::fromStringToVector(std::string string)
{
    std::vector<std::string> strings;
    size_t start = 0;
    for (size_t i = 0; i < string.length(); ++i) {
        if (string[i] == '\0')
        {
            strings.push_back(string.substr(start, i));
            start = i + 1;
        }
    }
    return strings;
}

void Utils::createAndWriteToFile(std::string fileName, std::string text)
{
    writeTextToFile(fileName, text);
}
