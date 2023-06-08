#ifndef CASETABLE_H
#define CASETABLE_H

#include <string>
#include <map>
#include <vector>
#include <QString>
#include <fstream>
#include <iostream>
#include <utils.h>


class CaseTable
{
public:
    CaseTable();
    CaseTable(std::string* word);
    ~CaseTable();

public:
    bool isEmpty();
    void fillTable(std::vector<std::string> text);
    std::vector<std::pair<std::string, std::string>> getFileCases(std::vector<std::string> fileName);

private:
    std::pair<std::string, std::string> checkWord(std::string word);

private:
    std::vector<std::vector<std::string>> table;
};

#endif // CASETABLE_H
