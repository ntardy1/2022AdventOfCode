
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Checks to see if all elements of a character vector are unique
// Returns false if there are duplicate elements, true otherwise
bool checkForDuplicate(vector<char> vector){
    char temp;
    for (int i = 0; i < vector.size(); i++){
        temp = vector[i];
        for (int j = 0; j < vector.size(); j++){
            if (vector[j] == temp && i != j){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ifstream inFile;
    string line;
    vector<char> markers;
    inFile.open("Buffer.txt");
    while (inFile.eof() == false){
        getline(inFile, line, '\n');
        for (int i = 0; i < line.size(); i++){
            markers.clear();
            if (i < line.size() - 13){
                for (int j = 0; j < 14; j++){
                    markers.push_back(line[i + j]);
                }
                if (checkForDuplicate(markers)){
                    cout << i + 14 << endl;
                    return 0;
                }
            }
        }
    }
}
