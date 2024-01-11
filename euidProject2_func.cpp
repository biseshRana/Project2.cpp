#include "euidProject2_header.h"
#include <iostream>
#include <fstream>

void add_Student() {
    Student newStudent;
    std::cout << "Enter student name: ";
    std::cin.ignore(); // To handle the newline character
    std::getline(std::cin, newStudent.name);

    std::cout << "Enter student ID: ";
    std::cin >> newStudent.studentID;

    newStudent.numTestsTaken = NUM_TESTS;
    newStudent.testScores = new float[NUM_TESTS];
    for (int i = 0; i < NUM_TESTS; ++i) {
        std::cout << "Enter score for test " << i + 1 << ": ";
        std::cin >> newStudent.testScores[i];
    }

    // Calculate average score excluding the minimum score
    int minScore = findMinimum(newStudent.testScores, NUM_TESTS);
    float sum = 0;
    for (int i = 0; i < NUM_TESTS; ++i) {
        sum += newStudent.testScores[i];
    }
    newStudent.averageScore = (sum - minScore) / (NUM_TESTS - 1);

    // Write to file
    std::ofstream outFile("student.dat", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << newStudent.name << " "
            << newStudent.studentID << " "
            << newStudent.averageScore << std::endl;
    
    outFile.close();
    delete[] newStudent.testScores;
}
