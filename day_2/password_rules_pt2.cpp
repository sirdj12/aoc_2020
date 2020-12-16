// Day 1 of Advent of Code!! :D
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*
This script should read in a list of password rules and 
passwords, and check how many satisfy the rules.

This is part 2!!!

Here's the plan:
Just like part 1, but we just slice the string to get the characters in the min
and max positions, compare those to the password, and use a XOR (!=) to see if
it passes.

*/

int main() {
    //opening the input file
    ifstream input_file;
    //input_file.open("test_input.txt");
    input_file.open("input.txt");

    int num_passed = 0;

    //looping 
    string line;
    while (getline(input_file, line)){
        // first, find the first number. We'll find the - and 
        // get all the characters before that

        // find the index of the -
        int dash_idx = line.find("-");

        // get a string of the number before the -
        string num1 = line.substr(0,dash_idx);

        //convert it to an integer - I found this function online
        int min = stoi(num1);

        //now find the colon and step backwards from that? to find the 2nd number
        int colon_idx = line.find(":");

        // Now step backwards to find the max number
        int num2_length = colon_idx - dash_idx - 3;
        string num2 = line.substr(dash_idx+1, num2_length);

        //convert it to an integer
        int max = stoi(num2);

        //now we get the letter.  It could be a char, but I'll try
        // getting it as a string anyway?
        string letter = line.substr(colon_idx-1,1);

        // now get the password - I think the -1 gets until the end of the string
        string password = line.substr(colon_idx+2,-1);

        // So far so good! :D

        // Now since this is pt2, we check if the letter at position min or position
        // max (indexing from 1) is the letter we're looking for.  If either is
        // (but not both), then it passes.
        
        bool cond1 = (password[min-1] == letter[0]);
        bool cond2 = (password[max-1] == letter[0]);

        // != is the c++ XOR
        if (cond1 != cond2) num_passed++;

        //cout << n << endl;
    }
    //Now print the result and close the file! :)
    cout << num_passed << endl;
    input_file.close();
    return 0;
}