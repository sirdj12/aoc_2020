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

int main() {
    //opening the input file
    ifstream input_file;
    //input_file.open("test_input.txt");
    input_file.open("input.txt");

    //initializing our tree counter 
    int tree_counter = 0;

    // initializing our lateral position counter to -3, so that
    // after we add 3, it'll be 0
    int lateral_pos = -3;

    string line;
    while (getline(input_file, line)){

        //increment our lateral position
        lateral_pos += 3;

        //get number of characters in the line
        int width = line.size();

        //now we check if we need to wrap around

        //less than or equal to, since position 9 is really the 10th character,
        //so if we were at pos 9, and the width was 9, we would be asking for
        // the 10th character, and would have to loop around
        if (lateral_pos >= width){
            lateral_pos -= (width);
        }

        // picking the character we're at
        char letter = line[lateral_pos];

        // incrementing our tree counter if we're at a tree
        if (letter == '#') tree_counter++;

        //and now I think we're done???
        //cout << line << ' ' << letter << lateral_pos << ' ' << width << endl;

    }

    //Now print the result and close the file! :)
    cout << tree_counter << endl;
    input_file.close();
    return 0;
}
