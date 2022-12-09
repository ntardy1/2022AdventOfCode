
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string elf1Bound1;
    int elf1Bound1Int;
    string elf1Bound2;
    int elf1Bound2Int;
    string elf2Bound1;
    int elf2Bound1Int;
    string elf2Bound2;
    int elf2Bound2Int;
    int contained = 0;
    ifstream inFile;
    inFile.open("Assignments.txt");
    while (inFile.eof() == false){
        getline(inFile, elf1Bound1, '-');
        elf1Bound1Int = stoi(elf1Bound1);
        getline(inFile, elf1Bound2, ',');
        elf1Bound2Int = stoi(elf1Bound2);
        getline(inFile, elf2Bound1, '-');
        elf2Bound1Int = stoi(elf2Bound1);
        getline(inFile, elf2Bound2, '\n');
        elf2Bound2Int = stoi(elf2Bound2);
        if (elf2Bound1Int > elf1Bound1Int && elf2Bound1Int > elf1Bound2Int && elf2Bound2Int > elf1Bound1Int && elf2Bound2Int > elf1Bound2Int){
            NULL;
        } else if (elf2Bound1Int < elf1Bound1Int && elf2Bound1Int < elf1Bound2Int && elf2Bound2Int < elf1Bound1Int && elf2Bound2Int < elf1Bound2Int){
            NULL;
        } else {
            contained++;
        }
        /*
        if (elf1Bound1Int >= elf2Bound1Int && elf1Bound1Int <= elf2Bound2Int && elf1Bound2Int >= elf2Bound1Int && elf1Bound2Int <= elf2Bound2Int){
            contained++;
        } else if (elf2Bound1Int >= elf1Bound1Int && elf2Bound1Int <= elf1Bound2Int && elf2Bound2Int >= elf1Bound1Int && elf2Bound2Int <= elf1Bound2Int){
            contained++;
        }
        */
    }
    // 952 too high
    cout << "Contained: " << contained;
}