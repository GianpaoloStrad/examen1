#include <iostream>
#include <sstream>
#include <cctype>
#include <fstream>

using namespace std;

bool isVowel(char c) {
    c =tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isConsonant(char c) {
    c =tolower(c);
    return c >='a' && c <='z' && !isVowel(c);
}

int main() {
    ifstream inFile("dataExamen2.csv");
    ofstream outFile("noNumbers.csv"), vowelsFile("vowels.csv"), consonantsFile("consonants.csv");
    string line, word;

    while (getline(inFile, line)) {
        istringstream iss(line);
        while (iss>>word) {
            if (!isdigit(word[0])) {
                outFile<<word<< " ";
                if (isVowel(word[0])) {
                    vowelsFile<<word<< " ";
                } else if (isConsonant(word[0])) {
                    consonantsFile<<word<< " ";
                }
            }
        }
        outFile<<"\n";
        vowelsFile<<"\n";
        consonantsFile<<"\n";
    }

    inFile.close();
    outFile.close();
    vowelsFile.close();
    consonantsFile.close();

    return 0;
}