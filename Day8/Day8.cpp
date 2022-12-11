
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Returns false if any element in the vector is greater than or equal to the target
// Returns true otherwise
bool isTreeVisible(vector<int> vector, int target){
    for (int i = 0; i < vector.size(); i++){
        if (vector[i] >= target){
            return false;
        }
    }
    return true;
}

// Returns the maximum value in a vector of integers
int vectorMax(vector<int> vector){
    int max = vector[0];
    for (int i = 0; i < vector.size(); i++){
        if (vector[i] > max){
            max = vector[i];
        }
    }
    return max;
}

int main(){
    ifstream inFile;
    vector<vector<int>> grid;
    vector<int> temp;
    string line;
    int row = 0;
    int visible = 0;
    bool isVisible;
    inFile.open("Trees.txt");
    while (inFile.eof() == false){
        getline(inFile, line, '\n');
        grid.push_back({});
        for (int i = 0; i < line.size(); i++){
            grid[row].push_back(static_cast<int>(line[i]) - 48);
        }
        row++;
    }
    // Adding all the edge trees
    visible += 2 * grid[0].size();
    visible += (2 * grid.size()) - 4;
    
    // Checking the inner trees from all sides
    for (int i = 1; i < grid.size() - 1; i++){
        isVisible = false;
        for (int j = 1; j < grid[0].size() - 1; j++){
            // Test left side
            for (int k = 0; k < j; k++){
                temp.push_back(grid[i][k]);
            }
            isVisible = isTreeVisible(temp, grid[i][j]);
            temp.clear();
            if (isVisible){
                visible++;
                if (j == grid[0].size() - 2){
                    goto nextRow;
                } else {
                goto nextColumn;
                }
            }
            // Test top
            for (int k = 0; k < i; k++){
                temp.push_back(grid[k][j]);
            }
            isVisible = isTreeVisible(temp, grid[i][j]);
            temp.clear();
            if (isVisible){
                visible++;
                if (j == grid[0].size() - 2){
                    goto nextRow;
                } else {
                goto nextColumn;
                }
            }
            right:
            // Test right side
            for (int k = grid[i].size() - 1; k > j; k--){
                temp.push_back(grid[i][k]);
            } 
            isVisible = isTreeVisible(temp, grid[i][j]);
            temp.clear();
            if (isVisible){
                visible++;
                if (j == grid[0].size() - 2){
                    goto nextRow;
                } else {
                goto nextColumn;
                }
            }
            bottom:
            // Test bottom
            for (int k = grid.size() - 1; k > i; k--){
                temp.push_back(grid[k][j]);
            }
            isVisible = isTreeVisible(temp, grid[i][j]);
            temp.clear();
            if (isVisible){
                visible++;
                if (j == grid[0].size() - 2){
                    goto nextRow;
                } else {
                goto nextColumn;
                }
            }
            nextColumn:
            NULL;
        }
        nextRow:
        NULL;
    }
    std::cout << "Trees Visible: " << visible << endl;

    // Start code for Part 2
    int scenicScore = 0;
    int leftDirection = 0, topDirection = 0, rightDirection = 0, bottomDirection = 0;
    vector<int> scenicScores;
    // Finding the scenic score of each tree
    for (int i = 1; i < grid.size() - 1; i++){
        for (int j = 1; j < grid[0].size() - 1; j++){
            // Left viewing direction
            for (int k = j - 1; k >= 0; k--){
                if (grid[i][k] >= grid[i][j] || k == 0){
                    leftDirection = j - k;
                    break;
                }
            }
            // Top viewing direction
            for (int k = i - 1; k >= 0; k--){
                if (grid[k][j] >= grid[i][j] || k == 0){
                    topDirection = i - k;
                    break;
                }
            }
            // Right viewing direction
            for (int k = j + 1; k < grid[i].size(); k++){
                if (grid[i][k] >= grid[i][j] || k == grid[i].size() - 1){
                    rightDirection = k - j;
                    break;
                }
            }
            // Bottom viewing direction
            for (int k = i + 1; k < grid.size(); k++){
                if (grid[k][j] >= grid[i][j] || k == grid.size() - 1){
                    bottomDirection = k - i;
                    break;
                }
            }
            scenicScore = leftDirection * topDirection * rightDirection * bottomDirection;
            scenicScores.push_back(scenicScore);
            scenicScore = 0;
            leftDirection = 0;
            topDirection = 0;
            rightDirection = 0;
            bottomDirection = 0;
        }
    }
    cout << "Highest Scenic Score: " << vectorMax(scenicScores) << endl;
}
