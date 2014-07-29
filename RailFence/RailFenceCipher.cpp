#include "stdafx.h"
#include "RailFenceCipher.h"
#include <algorithm>
using namespace std;

void RailFenceCipher::SetPlainText(const std::string& message){
    plain_text = message;
}

void RailFenceCipher::setupRails(){
    for (int i = 0; i < numRails; i++){
        rails.push_back(string());
    }
}
string RailFenceCipher::GetCipherText(){
    setupRails();
    plain_text.erase(remove_if(plain_text.begin(), plain_text.end(), ::isspace), plain_text.end());
    bool forward = true;
    int vectorPos = 0;
    for (string::size_type i = 0; i < plain_text.length(); i++)
    {

        char* position = &plain_text[i];
        *position = toupper(plain_text[i]);

        rails[vectorPos] += *position;
        if (vectorPos == rails.size() - 1){
            forward = false;
        }
        if (vectorPos == 0){
            forward = true;
        }
        if (forward){
            vectorPos += 1;
        }
        else{
            vectorPos -= 1;
        }
    }
    string finalMessage;
    for_each(rails.begin(), rails.end(),
        [&finalMessage](string rail){
        finalMessage += rail;
    });
    return finalMessage;
}

