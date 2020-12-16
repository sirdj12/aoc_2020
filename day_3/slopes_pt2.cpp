// Day 1 of Advent of Code!! :D
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*
This script should read in a block of hashtags and 
periods (trees and open spaces) and count how many 
trees we would hit if we started in the top left corner 
and jumped/slid right 3 characters and down 1 character,
assuming the pattern repeats to the right.

Here's the plan
- start a variable to keep track of what position,
  laterally, we are in. So it starts at 1, then 1+3, then 1+3+3, etc.
- loop through the file, line by line
- increment our counter.
- if it is beyond the width of the file, do a mod operation
  or something like that to loop back to where it should be
- pick the character we are at
- increment our tree counter if it is a hashtag
- print our tree counter once we are through the file
*/

//Maing our tree-counting function
int tree_checker(int lateral_jump, int vertical_jump){
    ifstream input_file;
    //input_file.open("test_input.txt");
    input_file.open("input.txt");
    
    int tree_counter = 0;
    int lateral_pos = 0 - lateral_jump;

    string line;
    int vertical_counter = -1;
    while (getline(input_file, line)){

        vertical_counter++;
        if ((vertical_counter % vertical_jump) == 0){
            lateral_pos += lateral_jump;

            int width = line.size();

            if (lateral_pos >= width){
                lateral_pos -= width;
            }

            char letter = line[lateral_pos];

            if (letter == '#') tree_counter++;
        } else {
            continue;
        }
    }
    input_file.close();
    return tree_counter;
}

int main() {

    int lateral_jumps[5] = {1, 3, 5, 7, 1};
    int vertical_jumps[5] = {1, 1, 1, 1, 2};
    long tree_product = 1;
    for (int i=0; i<5; i++){
        int n_trees = tree_checker(lateral_jumps[i], vertical_jumps[i]);
        cout << n_trees << ' ';
        tree_product *= n_trees;
    }
    cout << endl << tree_product << endl;
    return 0;
}