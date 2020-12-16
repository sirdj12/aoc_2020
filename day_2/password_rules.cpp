// Day 1 of Advent of Code!! :D
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*
This script should read in a list of password rules and 
passwords, and check how many satisfy the rules.

Here's the plan
- loop through the file
- get min and max times the letter can appear
- get the letter
- get the password
- loop through the password to check
- count how many times the letter appears
- compare this number to the min and max allowed
- increment a counter if the password passes
- print the counter
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

        // now we loop through the string, and count how many times we find 
        // the letter we're looking for.  I think a slice of a string is a char?
        int n = 0;
        for (int i = 0; i < password.size(); i++){
            if (password[i] == letter[0]) n++;
        }
        
        //actually, we can use a funciton for this!
        //int n = count(password.begin(), password.end(), letter);
        // never mind - that gave us an error :/

        // Now we compare if n is within our bounds!
        // and increment our count if it passed
        if ((n >= min) && (n <= max)) num_passed++;

        //cout << n << endl;
    }
    //Now print the result and close the file! :)
    cout << num_passed << endl;
    input_file.close();
    return 0;
}