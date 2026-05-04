// Joseph Valdez
// 5/1/2026
//  This is an updated version of the first program that takes daily quiz scores and displays the highest and lowest scores. 
// This program now contains a menu that allows the user to choose whether to look at the data currently saved, add new student name,
// search for students by name, delete a student's record and save new data added by the user.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

struct Student {
string name;
int score;
};







