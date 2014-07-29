#pragma once
#include <string>
#include<vector>
#include<memory>
class RailFenceCipher
{
private:
    std::string rail_one;
    std::string rail_two;
    std::string rail_three;
    std::string plain_text;
    std::vector<std::string> rails;
    void setupRails();
    int numRails;
public:
    void SetPlainText(const std::string& plain_text);
    void SetNumRails(int num){ numRails = num; }
    std::string GetCipherText();
};

