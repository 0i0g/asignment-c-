// Lecture08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

// Ask user to enter all answers
void askUserEnterAnswers(char *userAnswers, int amount) {
    const string ACCEPT_ANSWER = "ABCD";

    cout << "Enter your answers (A, B, C, D)" << endl;
    for (int i = 0; i < amount; ++i) {
        cout << "Answer " << i + 1 << ":";
        bool a = true;
        // Loop until accept answer
        while (a) {
            char answer;
            cin >> answer;

            // Check if answer is accepted
            if (ACCEPT_ANSWER.find(answer) != string::npos) {
                // Save user answer
                userAnswers[i] = answer;
                a = false;
            } else {
                cout << "Only accept the letters A, B, C or D as answers" << endl;;
            }
        }
    }
}

void validateUserAnswers(char *userAnswers,
                         char *correctAnswers,
                         int *incorrectlyAnswered,
                         int amount,
                         int *totalIncorrect) {
    for (int i = 0; i < amount; ++i) {
        if (userAnswers[i] != correctAnswers[i]) {
            incorrectlyAnswered[*totalIncorrect] = i + 1;
            (*totalIncorrect)++;
        }
    }
}

// Concat int array to a string
string joinInts(int array[], int length, string separator) {
    ostringstream stream;
    string result;
    for (int i = 0; i < length; ++i) {
        stream << array[i] << separator;
    }
    result = stream.str();
    // Remove last separator
    result = result.substr(0, result.length() - separator.length());

    return result;
}

int main() {
    // Constants
    const int NUMBER_OF_QUESTIONS = 20;
    const string ANSWERS = "ADBBCBABCDACDBDCCADB";
    const int TOTAL_CORRECT_TO_PASS = 15;

    // Variables
    char correctAnswers[NUMBER_OF_QUESTIONS] = {};
    char userAnswers[NUMBER_OF_QUESTIONS] = {};
    int incorrectlyAnswered[NUMBER_OF_QUESTIONS] = {};
    int totalIncorrect = 0;
    int totalCorrect = 0;
    string incorrectAnswerNumberToString;

    // ANSWER string to char array
    strcpy(correctAnswers, ANSWERS.c_str());

    askUserEnterAnswers(userAnswers, NUMBER_OF_QUESTIONS);

    validateUserAnswers(userAnswers, correctAnswers, incorrectlyAnswered, NUMBER_OF_QUESTIONS, &totalIncorrect);

    // Check if user pass the exam
    totalCorrect = NUMBER_OF_QUESTIONS - totalIncorrect;
    if (totalCorrect >= TOTAL_CORRECT_TO_PASS) {
        // passed
        cout << "Passed the exam" << endl;
    } else {
        // failed
        cout << "Failed the exam" << endl;
    }
    cout << "Total correct: " << totalCorrect << endl;
    cout << "Total incorrect: " << totalIncorrect << endl;

    if(totalIncorrect > 0){
    cout << "Incorrectly answered: " << joinInts(incorrectlyAnswered, totalIncorrect, ", ");
    }
}
