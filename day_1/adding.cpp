// Day 1 of Advent of Code!! :D
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*
This script should read in a list of integers from a 
file, find which 2 numbers sum up to 2020, multiply those
2 numbers together, and return the result.
*/

int main() {
    //opening the input file
    ifstream input_file;
    //input_file.open("test_input.txt");
    input_file.open("input.txt");

    //counting how many lines are in the input file
    string line;
    int num;
    int number_of_lines = 0;
    while ( getline (input_file,line) ) {
        ++number_of_lines;
    }
    cout << "The Number of lines in the file is: " << number_of_lines << endl;

    // creating an array to store the values in the file
    int nums[number_of_lines] = {};

    //Now we go back to the beginning of the file
    input_file.clear();
    input_file.seekg(0);

    //now we loop through the file again
    // to store the values in our array
    int counter = 0;
    while (getline(input_file,line)) {
        //converting line to an integer
        stringstream(line) >> num;
        //cout << num << endl;
        nums[counter] = num;
        ++counter;
    }

    // now we print the array, to check it
    //for (int j = 0; j < number_of_lines; j++){
    //   cout << nums[j] << endl;
    //}

    // Declaring the indexes of the numbers we're looking for, the total
    // and a flag to signal when we're done searching for the numbers
    int index1;
    int index2;
    int total;
    bool flag = true;
    // Now we loop through the numbers to see which ones add up to 2020
    // We use a nested for loop to mulitply each number by every other number after it
    for (int i = 0; ((i < number_of_lines) && flag); i++){
        for (int j = i; (j < number_of_lines) && flag; j++){
            total = nums[i] + nums[j];
            //cout << total << endl;
            if (total == 2020){
                index1 = i;
                index2 = j;
                flag = false;
            }
        }
    }

    // Now we print our result
    cout << "The numbers are " << nums[index1] << " and " << nums[index2] << ", and their product is " << nums[index1]*nums[index2] << endl;

    //closing the file, now that we are done
    input_file.close();
    return 0;
}