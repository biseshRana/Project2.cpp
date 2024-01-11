#ifndef EUIDPROJECT2_HEADER_H
#define EUIDPROJECT2_HEADER_H

#include <string>

const int NUM_TESTS = 5;

enum MenuOption { Add = 1, Remove, Display, Search, Results, Quit };

struct Student {
    std::string name;
    int studentID;
    int numTestsTaken;
    float* testScores;
    float averageScore;
};

// Function prototypes
void add_Student();
void remove_Student(int studentID);
void display();
void search(int studentID);
void exportResults();
int findMinimum(int* arr, int size);

#endif //EUIDPROJECT2_HEADER_H
