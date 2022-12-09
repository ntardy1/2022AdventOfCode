
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    system("cls");
    fstream file;
    int temp;
    string stringNumber;
    int calorieCount;
    vector<int> calories;
    vector<int> calorieTotals;
    vector<int> maxes;
    file.open("Calories.txt");
    while (file.eof() == false){
        getline(file, stringNumber, '\n');
        if (stringNumber != ""){
            calorieCount = stoi(stringNumber);
            calories.push_back(calorieCount);
        } else if (stringNumber == ""){
            calories.push_back(0);
        }
    }
    int j = 0;
    while (true){
        calorieTotals.push_back(0);
        for (int i = 0; i < calories.size(); i++){
            if (calories[i] != 0){
                calorieTotals[j] += calories[i];
            } else if (calories[i] == 0){
                j++;
                calorieTotals.push_back(0);
            }
        }
        break;
    }
    for (int i = 0; i < 3; i++){
        maxes.push_back(0);
    }
    for (int i = 0; i < calorieTotals.size(); i++){
        for (int j = 0; j < maxes.size(); j++){
            if (calorieTotals[i] > maxes[j]){
                temp = maxes[j];
                maxes[j] = calorieTotals[i];
                if (j == 0){
                    maxes[j + 2] = maxes[j + 1];
                    maxes[j + 1] = temp;
                } else if (j == 1){
                    maxes[j + 1] = temp;
                }
                break;
            }
        }
    }
    int totalCalories = 0;
    for (int i = 0; i < maxes.size(); i++){
        totalCalories += maxes[i];
    }
    cout << totalCalories;
}