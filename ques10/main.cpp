#include <iostream>
#include <vector>

using namespace std;


int strcmp(const char *str1, const char *str2) {
    int i = 0, chk = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            chk = 1;
            break;
        } else if (str1[i] < str2[i]) {
            chk = -1;
            break;
        }
        i++;
    }
    return chk;
}

// Search the first greater than value
int linearSearch(vector<string> vec, const char *value) {
    for (int i = 0; i < vec.size(); ++i) {
        if (strcmp(vec[i].c_str(), value) > 0) {
            return i;
        }
    }
    return -1;
}

int main() {

    const int NUM_ELE = 20;

    string names[NUM_ELE] = {

            "Jack", "Jill", "Adam", "Mary", "Zack",

            "Jose", "George", "Sylvia", "Thien", "George",

            "Eric", "Miguel", "Luna", "Brandon", "Kathryn",

            "America", "Harvey", "Elliot", "Ashley", "Cynthia"

    };

    // Insert code here:
    vector<string> vec;

    //  show the vector when it is empty,
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }

    //  insert the names into the vector in order
    for (int i = 0; i < NUM_ELE; ++i) {
        // search index to insert
        int addIndex = linearSearch(vec, names[i].c_str());

        // addIndex < 0 means it is the greatest so push back
        if (addIndex < 0) {
            vec.push_back(names[i]);
        } else {
            vec.insert(vec.begin() + addIndex, names[i]);
        }

        // show the vector
        cout << "vector has ";
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[j] << " ";
        }
        cout << endl;
    }
}

/* Question 1:
 * I used a linear search to determine index I should insert next value
 * In this way, I can find the first value greater than the next value, so that I inserted the next value into that point
 * */

/* Question 2:
 * The differences between vectors and arrays:
 *                  Arrays          Vectors
 * Size             fixed           dynamic
 * Speed            faster          ...
 * Safety           ...             more safe
 * Flexibility      ...             more flexible
 * Performance      better          ...
 * Code style       harder          easier
 * */