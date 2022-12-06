// Lecture08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

// Read file until EOF, for each line save number into arrayNumber
bool readNumberFromFile(string fileName, int *arrayNumber, int *arrayLength, int limit) {
    string line;
    ifstream file;
    *arrayLength = 0;

    file.open(fileName);
    // Read number and save into array if not reached the limit
    if (file.is_open()) {
        while (getline(file, line) && *arrayLength < limit) {
            arrayNumber[*arrayLength] = stoi(line);
            (*arrayLength)++;
        }
        return true;
    }

    return false;
}

// Calculate the lowest number and save into currentValue
void saveLowestNumber(int *currentValue, int newValue) {
    if (newValue < *currentValue) {
        *currentValue = newValue;
    }
}

// Calculate the highest number and save into currentValue
void saveHighestNumber(int *currentValue, int newValue) {
    if (newValue > *currentValue) {
        *currentValue = newValue;
    }
}

// Calculate the total number of numbers in array and save into currentValue
void saveTotalNumber(int *currentValue, int newValue) {
    *currentValue += newValue;
}

int main() {
    // Constants
    const int MAX_NUMBER_ELEMENTS = 100; // limit number of elements in the file

    // Variables
    string fileName;
    int arrayNumber[10] = {};
    int arrayNumberLength;
    int lowestNumber = INT_MAX, highestNumber = INT_MIN, total = 0;
    double average;

    // Ask user to enter file name
    cout << "Enter file name:";
    cin >> fileName;

    try {
        if (!readNumberFromFile(fileName, arrayNumber, &arrayNumberLength, MAX_NUMBER_ELEMENTS)) {
            cout << "File not found or cannot open file";
            return 0;
        }
    } catch (exception) {
        cout << "File contains non-numeric characters";
        return 0;
    }

    // Check if file is empty
    if (arrayNumberLength == 0) {
        cout << "File is empty";
        return 0;
    }

    // Loop array number and calculate result
    for (int i = 0; i < arrayNumberLength; i++) {
        saveLowestNumber(&lowestNumber, arrayNumber[i]);
        saveHighestNumber(&highestNumber, arrayNumber[i]);
        saveTotalNumber(&total, arrayNumber[i]);
        average = (double) total / arrayNumberLength;
    }

    cout << "The lowest number in the array: " << lowestNumber << endl;
    cout << "The highest number in the array: " << highestNumber << endl;
    cout << "The total number of numbers in the array: " << total << endl;
    cout << "The average of the number in the array: " << average << endl;
}

// Test case 1:
// =============================================
// file test.txt
// 1
// 2
// 3
// 4
// =============================================
// Enter file name:test.txt
// The lowest number in the array: 1
// The highest number in the array: 4
// The total number of numbers in the array: 10
// The average of the number in the array: 2.5

// Test case 2:
// =============================================
// file test.txt
// a
// b
// 3
// 4
// =============================================
// Enter file name:test.txt
// File contains non-numeric characters

// Test case 3:
// =============================================
// file test.txt
// a
// b
// 3
// 4
// =============================================
// Enter file name:test.bat
// File not found or cannot open file

// Test case 4:
// =============================================
// file test.txt
// =============================================
// Enter file name:test.txt
// File is empty