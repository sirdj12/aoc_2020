// Day 4 of Advent of Code
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
/*
This script should read in a file of "passports."  Each passport 
is a group of lines with key:value pairs.  Passports are separated by blank lines.
To be valid, each passwort must have the fields byr, iyr, eyr, hgt, hcl, ecl, pid, and cid.
But we shoudl tread cid as optional for now.  
We want to count how many passports in the file are valid.
*/

/*
Plan 1 - see if we can find which lines are blank
    yes! Using line.empty() to check if it's empty

Plan 2 - loop through file and count which lines are empty.
        - add these numbers into a *Vector*!! which is new to me
        - loop through the number of passports (length of vector)
            and then loop through each chunk, line by line
        - for each chunk, make a vector with 8 zeros - one place for 
            each field.
        - on each line, use "find" to see if it has each field.
            each time we find the field, aput a 1 in the proper place in the vector
        - at the end of the chunk, check if the vector has all 1s (except for 
            the cid field).
        - If the vector has all the fields, add 1 to a counter, counting how many
            passports pass
        - And we should be done!! :) at least with this plan.
*/

    ifstream input_file;
// writing a function to get a specific line from the file
// since aparently that isn't a thing in c++?
string get_line(int max_lines, int line_number){

    //a bit of error checking
    if (line_number > max_lines){
        cout << "Line number is past end of file." << endl;
    } else {

        // start at the beginning of the file
        input_file.clear();
        input_file.seekg(0);

        int n = 0; //
        string fun_line;

        // loop through the file
        while ( getline(input_file, fun_line)){
            ++n;

            // stop once we get to the line number we want
            if (n == line_number){

                // go to the beginning of the file again (to be safe)
                input_file.clear();
                input_file.seekg(0);

                // return the line we want
                return fun_line;
            }
        }
    }
}




int main() {
    //opening the input file


    //input_file.open("test_input.txt");
    input_file.open("test_input.txt");

    //find how to tell if a line is blank
    string line;
    int num = 0;
    vector<int> blanks_idxs; // declaring our vector

    while ( getline (input_file,line) ) {
        ++num;

        if (line.empty()){
            cout << num << endl;
            blanks_idxs.emplace_back(num);
        }
    }
    cout << endl;

    // find how many passports there are
    int num_passports = blanks_idxs.size() + 1;

    // Now we loop through the number of passports
    for (int i=0; i < num_passports; i++){

        // Make a vector with 8 zeros
        vector<int> have_fields (8);

        // Now we loop through the lines in each chunk
        // start at 1 and go to the line before the 1st blank line
        // so 1 to blanks_idxs[0]-1, 
        // and then blanks_idxs[0]+1 to blanks_idxs[1]-1
        // and then blanks_idxs[1]+1 to blanks_idxs[2]-1, etc....
        // so follow a partern and have special handling at the 

        int start_n;
        int end_n;
        if (i == 0){
            start_n = 1;
            end_n = blanks_idxs[0]-1;

        } else if (i == (num_passports-1)){
            start_n = blanks_idxs.back()+1;
            end_n = num;
        } else {
            start_n = blanks_idxs[i-1]+1;
            end_n = blanks_idxs[i]-1;
        }

        int n_lines_in_passport = 0;
        
        // now we loop through the passports
        for (int j=start_n; j<= end_n; j++){
            ++n_lines_in_passport;
            string passport_line = get_line(num, j);
        }
        cout << n_lines_in_passport << endl;



        // int line_we_at = 0;
        // input_file.clear();
        // input_file.seekg(0);
        // int placeholder_n = 0;
        // while(getline(input_file, line)){
        //     ++line_we_at;
        //     //special handling for beginning
        //     if (i==0){
        //         if (line_we_at <= (blanks_idxs[0]-1)){
        //             //Now we *finally* check the lines in the passports to see
        //             // if they have the fields
        //             ++placeholder_n;
        //             //placeholder for now
        //         }
        //         //special handling for the last one
        //     } else if (i == (num_passports-1)){
        //         if (line_we_at > blanks_idxs.back()){
        //             // behavior at the end
        //             ++placeholder_n;
        //         }
        //     } else {
        //         //behavior if we're in the middle
        //         if 
        //     }

        //}



    }
    
    cout << endl;
    for(int i=0; i<blanks_idxs.size();i++){
        cout << blanks_idxs.at(i) << ' ';
    }
    cout << endl;
    //closing the file, now that we are done
    input_file.close();
    return 0;
}