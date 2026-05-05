// Joseph Valdez
// 5/4/2026
//  This is an updated version of the first program that takes daily quiz scores and displays the highest and lowest scores. 
// This program now contains a menu that allows the user to choose whether to look at the data currently saved, add new student name,
// search for students by name, delete a student's record and save new data added by the user.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

struct Student {      // Changed struct from Class to Student 
string name;       
int score;
};

// Function Prototypes
void displayData(Student students[], int count);
void findMinMax(Student students[], int count);
void addEntry(Student students[], int& count);
void searchEntry(Student students[], int count);
void saveData(Student students[], int count);
void deleteEntry(Student students[], int& count);

int main() {

  Student students[MAX_SIZE];
  int count = 0;
  int choice;

// Loads Output.txt into program

ifstream inFile("Output.txt");
if (inFile) {
    while (count < MAX_SIZE && inFile >> students[count].name >> students[count].score) {
        count++;
    }

    inFile.close();
    cout << "Loaded" << count << " records from class file.\n";
} else {
    cout << "No existing file found. Please try again.\n";
}
          // Revised menu loop
do {
    cout << "\n--- Daily Quiz Menu ---\n";
    cout << "1. View Data\n";
    cout << "2. Add Entry\n";
    cout << "3. Search Entry\n";
    cout << "4. Save Data\n";
    cout << "5. Delete Data\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            displayData(students, count);
            if (count > 0) findMinMax(students, count);
            break;
        case 2:
            addEntry(students, count);
            break;
        case 3:
            searchEntry(students, count);
            break;
        case 4:
            saveData(students, count);
            break;
        case 5:
            deleteEntry(students, count);
            break;
        case 6:
            cout << "Exiting program... See you tomorrow!\n";
            break;
        default:
            cout << "Invalid choice! Please try again!\n";
    }
  } while (choice != 6);

  return 0;
}

void displayData(Student students[], int count) {    // Function to display the current student names and daily quiz scores
  if (count == 0) {
      cout << "List is empty.\n";
      return;
  }
  cout << "\n" << left << setw(15) << "Name" << "Score" << endl;
  cout << "----------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << students[i].name << students[i].score << endl;
    }
}

void findMinMax(Student students[], int count) {      // Function to find the students with the highest and lowest daily quiz scores
  int maxIdx = 0, minIdx = 0;
  for (int i = 0; i < count; i++) {
      if (students[i].score > students[maxIdx].score)
        maxIdx = i;
      if (students[i].score < students[minIdx].score)
        minIdx = i;
   }
    cout << "\nTodays Highest Quiz Score: " << students[maxIdx].name << " (" << students[maxIdx].score << ")";
    cout << "\nTodays Lowest Quiz Score: " << students[minIdx].name << " (" << students[minIdx].score << ")";
}

void addEntry(Student students[], int& count) {      // Function allows user to add an entry
  if (count < MAX_SIZE) {
      cout << "Enter name: ";
      cin >> students[count].name;
      cout << "Enter score: ";
      cin >> students[count].score;
      count++;
      cout << "Student added successfully. \n";
  } else {
      cout << "Classroom Full!\n";
  }
}

void searchEntry(Student students[], int count) {    // Function to allow the user to search for an entry
  string query;
  cout << "Enter name to search: ";
  cin >> query;

  for (int i = 0; i < count; i++) {
      if (students[i].name == query) {
          cout << "Found " << students[i].name << " - Score: " << students[i].score << endl;

          return;
        }
    }
    cout << "Record not found.\n";
}

void saveData(Student students[], int count) {     // Function that allows the user to save the added data to the Output.txt data file
  ofstream outFile("Output.txt");
  for (int i = 0; i < count; i++) {
      outFile << students[i].name << " " << students[i].score << endl;
  }
  outFile.close();
  cout << "Data saved successfully to Output.txt";
}

void deleteEntry(Student students[], int& count) {      // Function that allows the user to delete any entry from the Output.txt data file
  string query;
  cout << "Enter name to delete: ";
  cin >> query;
  for (int i = 0; i < count; i++) {
      if (students[i].name == query) {
        for (int j = i; j < count - 1; j++) {
            students[j] = students[j + 1];
        }
        count--;
        cout << "Name successfully deleted.\n";
        return;
      }
  }
  cout << "Name not found.\n";
}
