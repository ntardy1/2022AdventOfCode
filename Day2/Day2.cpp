
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    int rock = 1;
    int paper = 2;
    int scissors = 3;
    int win = 6;
    int draw = 3;
    int loss = 0;
    int score = 0;
    ifstream inFile;
    string opponent;
    string player;
    inFile.open("StrategyGuide.txt");
    while (inFile.eof() == false){
        getline(inFile, opponent, ' ');
        getline(inFile, player, '\n');
        if (opponent == "A"){
            if (player == "X"){
                score += scissors + loss;
            } else if (player == "Y"){
                score += rock + draw;
            } else if (player == "Z"){
                score += paper + win;
            }
        } else if (opponent == "B"){
            if (player == "X"){
                score += rock + loss;
            } else if (player == "Y"){
                score += paper + draw;
            } else if (player == "Z"){
                score += scissors + win;
            }
        } else if (opponent == "C"){
            if (player == "X"){
                score += paper + loss;
            } else if (player == "Y"){
                score += scissors + draw;
            } else if (player == "Z"){
                score += rock + win;
            }
        }
    }
    cout << "Score: " << score;
}