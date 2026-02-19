#include <vector>

#include <string>

#include <iostream>

using namespace std;

vector<string> findWords(vector<string>& words) {
    std::vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    std::vector<string> result = {};
    
    for (size_t i = 0; i < words.size(); i++) {
        std::string cword = words[i];
        
        for (size_t k = 0; k < rows.size(); k++) {
            bool found = true;

            for (size_t j = 0; j < cword.size(); j++) {
                if (rows[k].find((char)tolower(cword[j])) == std::string::npos) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                result.push_back(cword);
                break;
            }
        }
    }
    return result;
}

vector<string> words = {"Hello","Alaska","Dad","Peace"};

void printVector(vector<string> v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {

    std::vector<string> test = {"Hello","Alaska","Dad","Peace"};

    auto print = findWords(test);

    cout << "Original vector: ";
    printVector(test);
    cout << "Result: ";
    printVector(print);

    return 0;
}