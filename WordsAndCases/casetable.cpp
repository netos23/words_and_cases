#include "casetable.h"


CaseTable::CaseTable(){}

CaseTable::~CaseTable(){}

bool CaseTable::isEmpty()
{
    return table.size() == 0;
}

void CaseTable::fillTable(std::vector<std::string> strings) {
    for(std::string string: strings)
    {
        table.push_back(std::vector<std::string>());
        std::vector<std::string> row = table[table.size() - 1];
        std::string word;
        size_t start = 0;
        for (size_t i = 0; i < string.size(); ++i) {
            if(string[i] == ',' || string[i] == '\n') {
                table[table.size() - 1].push_back(string.substr(start, i - start));
                start = i + 1;
            }
        }
    }
}

std::vector<std::pair<std::string, std::string>> CaseTable::getFileCases(std::vector<std::string> strings)
{
    if (table.size() == 0)
    {
        throw "case table is empty";
    }
    std::vector<std::pair<std::string, std::string>> pairs;
    for (std::string str: strings)
    {
        pairs.push_back(checkWord(str.substr(0, str.length() - 1)));
    }
    return pairs;
}

std::pair<std::string, std::string> CaseTable::checkWord(std::string word) {
    for (size_t i = 0; i < table.size(); ++i) {
        std::pair<std::string, std::string> res;
        if(word == table[i][0]) {
            res = std::make_pair(table[i][0], "Nominative case");
            return res;
        } else if (word == table[i][1]) {
            res = std::make_pair(table[i][0], "Genitive case");
            return res;
        } else if (word == table[i][2]) {
            res = std::make_pair(table[i][0], "Dative case");
            return res;
        } else if (word == table[i][3]) {
            res = std::make_pair(table[i][0], "Accusative case");
            return res;
        } else if (word == table[i][4]) {
            res = std::make_pair(table[i][0], "Ablative case");
            return res;
        } else if (word == table[i][5]) {
            res = std::make_pair(table[i][0], "Prepositional case");
            return res;
        }
    }
    std::pair<std::string, std::string> res;
    res.first = "";
    res.second = "";
    return res;
}

//std::string CaseTable::nominativeCase() {
//    return table[0];
//}

//std::string CaseTable::genitiveCase() {
//    return table[1];
//}

//std::string CaseTable::dativeCase() {
//    return table[2];
//}

//std::string CaseTable::accusativeCase() {
//    return table[3];
//}

//std::string CaseTable::ablativeCase() {
//    return table[4];
//}

//std::string CaseTable::prepositionalCase() {
//    return table[5];
//}


