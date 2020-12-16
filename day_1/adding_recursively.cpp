// Day 1 of Advent of code, done with a recursive function
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*
This script should read in a list of integers from a 
file, find which 3 numbers sum up to 2020, multiply those
3 numbers together, and return the result.
*/

// setting max recursion depth.  This is how many numbers we want to find.
const int max_depth = 3;

// declaring an array to hold the indexes of our winning numbers
int idxs[max_depth] = {};

// Our flag.  If it's false, we halt our recursion and searching
bool flag = true;

// Initializing this here, so it's global
int number_of_lines = 0;

// Declaring this before main, since it needs to be in scope when main calls it.
// However, we wait to define it until *after* main, since it needs number_of_lines
// to be defined, I think.
int fun (int previous_depth, int idx, int*nums);

int main() {
    //opening the input file
    ifstream input_file;
    //input_file.open("test_input.txt");
    input_file.open("input.txt");

    //counting how many lines are in the input file
    string line;
    int num;
    while ( getline (input_file,line) ) {
        ++number_of_lines;
    }
    cout << "The number of lines in the file is: " << number_of_lines << endl;

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

    // Calling our recursive function.  I read that the array "nums" will decay
    // to a pointer once it is passed to the funciton
    fun(0,0, nums);

    //closing the file, now that we are done
    input_file.close();

    return 0;
}

// Defining our recursive function
int fun(int previous_depth, int idx, int* nums){

    // incrementing our current recursion depth
    int our_depth = previous_depth + 1;
    
    // looping through the indexes of the array of numbers.
    // we stop if flag is false
    for (int i=idx; ((i < number_of_lines) && flag); i++){

        // adding the current index into the array of our winning indexes
        idxs[our_depth-1] = i;

        // checking for end condition
        if (our_depth == max_depth){
            
            // initializing our total that should be 2020
            int total = 0;

            //  looping through the numbers in our array of indexes, to see if
            // they add up to 2020
            for (int j=0; j<max_depth; j++){
                total += nums[idxs[j]];
            }

            // checking if the total adds up to 2020, to see if we're done
            if (total == 2020){

                // setting the flag false.  Since this is a global 
                // variable, this will stop all our searching.
                flag = false;

                // initializing the product of our winning numbers
                long product = 1;
                cout << "The numbers are: ";

                // looping through our array of winning numbers, to find 
                // their product and print the result
                for (int k=0; k<max_depth; k++){
                    cout << nums[idxs[k]] << " and ";
                    product *= nums[idxs[k]];
                }
                cout << "their product is " << product << endl;
            }
        } else {
            // If we're not at max depth, we'll call the function again.
            fun(our_depth, i, nums);
        }
    }
}