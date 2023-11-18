#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

int main(int argc, char* argv[]){ // .\lab-06\frequency -i *** -o ***
    if(argc < 3 || argc > 5){
        std::cout<<"Proper usage ---> mean_std -i <input file name> [-o <output file name>]\n";
        return 1;
    }
    
    std::string line;
    std::vector<char> text;
    std::vector<int> freq(26, 0);
    int s = 0;


    std::ifstream input;
    std::string fileName = argv[2];
    fileName = ".\\lab-06\\" + fileName + ".txt";
    input.open(fileName);

    if(!input.good()){
        std::cout<< "Improper input file name\n";
        return 1; 
    }

    std::ofstream output;
    if(argc == 5){
        fileName = argv[4];
        fileName = ".\\lab-06\\" + fileName + ".txt";
        output.open(fileName, std::ios::out);
        std::cout.rdbuf(output.rdbuf());
    }

    while (std::getline(input, line)){
        tolower(line);
        for (char c : line) {
            if(std::isalpha(c)){
                text.push_back(c);
                s++;
            }
        }
    }

    for(int i = 0; i < s; i++){
        freq[text[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            double per = static_cast<double>(freq[text[i] - 'a']) / s * 100;
            std::cout<< text[i] << " => " << freq[text[i] - 'a'] << " => " << per <<"%\n"; 
            freq[text[i] - 'a'] = 0;
        }
    }

    return 0;
}