// Day 5 of Advent of Code
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

/*
The Plan:
- Open the text file and loop through it, line by line
- On each line, break the first 7 characters and last 3 
  into seperate strings
- Convert each group into binary or numbers
- combine them into 1 number
- add the numbers to a vector
- find the highest number in the vector

Example input line: FBFBBFFRLR means 44
*/



int get_seat_number(string seat_string){
    //This function converts the text of string into
    // an integer.
    int length = seat_string.length();
    int sum = 0;

    if (length == 7){
        // length 7, FB string

        for (int i=0; i<7; i++){
            //looping through the string
            char letter = seat_string[i];

            if (letter == 'B'){
                double a = pow(2, (6-i));
                sum += (int)(a+0.5);
            } // else add zero, which is the same as doing nothing
        }
    } else {
        for (int j=0; j<3; j++){
            //looping through the string
            char letter = seat_string[j];

            if (letter == 'R'){
                double b = pow(2, (2-j));
                sum += (int)(b+0.5);
            }
        }
        // length 3, LR string
    }
    return sum;
}

int main() {
    // opening the file
    ifstream input_file;
    //input_file.open("test_input.txt");
    input_file.open("input.txt");

    // declaring our vector
    vector<int> seat_ids;

    string line;
    // now loop through the file
    while (getline (input_file, line)){
        // Now get the rows and columns
        string row_txt = line.substr(0,7);
        string col_txt = line.substr(7,3);

        // now convert the strings to text;
        int row_num = get_seat_number(row_txt);
        int col_num = get_seat_number(col_txt);
        
        int seat_num = row_num*8 + col_num;
        
        seat_ids.emplace_back(seat_num);

    }
        auto max_seat = max_element(begin(seat_ids), end(seat_ids));
    cout << "Highest seat  number is " << *max_seat << endl;

}