
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void printCRT(vector<char> CRT){
    for (int j = 1; j < 241; j++){
        if (j % 40 == 0){
            cout << CRT[j - 1] << endl;
        } else {
            cout << CRT[j - 1];
        }
    }
    cout << endl;
}

int main(){
    ifstream inFile;
    string temp;
    string word = "";
    int X = 1;
    string addTo;
    int signalStrengths = 0;
    int addToX = 0;
    int cycle = 0;
    int index = 0;
    vector<char> CRT;
    // Intializing the screen of the CRT to be totally blank
    for (int i = 0; i < 240; i++){
        CRT.push_back('.');
    }
    inFile.open("Cycles.txt");
    while (inFile.eof() == false){
        // Resetting the value of word
        word = "";
        for (int i = 0; i < 4; i++){
            word += inFile.get();
        }
        if (word == "noop"){
            // Getting the new line character out of the way
            inFile.get();
            cycle += 1;
            // Part 2
            // Note: Need to include the modulus with the index since X only 
            // determines the horizontal position of the sprite
            if (index % 40 >= X - 1 && index % 40 <= X + 1){
                CRT[index] = '#';
            }
            index++;
            // Part 1
            if ((cycle - 20) % 40 == 0){
                signalStrengths += (cycle * X);
            }
        } else if (word == "addx"){
            // Getting the space character out of the way
            inFile.get();
            cycle += 1;
            // Part 2
            // Note: Need to include the modulus with the index since X only 
            // determines the horizontal position of the sprite
            if (index % 40 >= X - 1 && index % 40 <= X + 1){
                CRT[index] = '#';
            }
            index++;
            // Adding to the sum of the signal strengths
            if ((cycle - 20) % 40 == 0){
                signalStrengths += (cycle * X);
            }
            cycle += 1;
            // Part 2
            // Note: Need to include the modulus with the index since X only 
            // determines the horizontal position of the sprite
            if (index % 40 >= X - 1 && index % 40 <= X + 1){
                CRT[index] = '#';
            }
            index++;
            // Adding to the sum of the signal strengths
            if ((cycle - 20) % 40 == 0){
                signalStrengths += (cycle * X);
            }
            getline(inFile, addTo, '\n');
            X += stoi(addTo);
        }
    }
    cout << "Sum of signal strengths: " << signalStrengths << endl;
    printCRT(CRT);
}
