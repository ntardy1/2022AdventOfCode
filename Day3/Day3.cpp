
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    ifstream inFile;
    string line;
    string firstHalf;
    string secondHalf;
    char inCommon;
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRTSUVWXYZ";
    int prioritySum = 0;
    int iterations = 0;
    inFile.open("Items.txt");
    while (inFile.eof() == false){
        iterations++;
        firstHalf = "";
        secondHalf = "";
        getline(inFile, line, '\n');
        for (int i = 0; i < line.size(); i++){
            if (i < line.size()/2){
                firstHalf.push_back(line[i]);
            } else {
                secondHalf.push_back(line[i]);
            }
        }
        cout << firstHalf << "-" << secondHalf;
        for (int i = 0; i < firstHalf.size(); i++){
            for (int j = 0; j < secondHalf.size(); j++){
                if (firstHalf[i] == secondHalf[j]){
                    inCommon = firstHalf[i];
                    goto addPriority;
                }
            }
        }
        addPriority:
        cout << ", " << inCommon;
        for (int k = 0; k < lowercase.size(); k++){
            if (inCommon == lowercase[k]){
                prioritySum += 1 + k;
                cout << ", " << k + 1 << endl;
                break;
            } else if (inCommon == uppercase[k]){
                prioritySum += 27 + k;
                cout << ", " << k + 27 << endl;
                break;
            }
        }
    }
    inFile.close();
    // 7599 too high
    cout << "Priority Sum: " << prioritySum << ", Rucksacks: " << iterations;
}