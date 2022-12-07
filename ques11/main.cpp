#include <iostream>

using namespace std;

class Car {
private:
    int year;
    string maker;
    string model;
    int speed;
public:
    Car(int year, string maker, string model) {
        this->year = year;
        this->maker = maker;
        this->model = model;
        this->speed = 0;
    }

    int getYear() const {
        return year;
    }

    const string &getMaker() const {
        return maker;
    }

    const string &getModel() const {
        return model;
    }

    int getSpeed() const {
        return speed;
    }

    void accelerate() {
        this->speed += 5;
    }

    void brake() {
        this->speed -= 5;
    }
};

int main() {
    Car mazda(2023, "Mazda", "Mazda3");
    Car audi(2023, "Audi", "A4");
    Car hyundai(2023, "Hyundai", "Elantra");

    cout << "Mazda call accelerate 4 times and brake 2 times:" << endl;
    for (int i = 0; i < 4; ++i) {
        mazda.accelerate();
        cout << mazda.getMaker() << "->accelerate() " << "speed: " << mazda.getSpeed() << endl;
    }
    for (int i = 0; i < 2; ++i) {
        mazda.brake();
        cout << mazda.getMaker() << "->brake() " << "speed: " << mazda.getSpeed() << endl;
    }
    cout << endl;

    cout << "Audi call accelerate 5 times:" << endl;
    for (int i = 0; i < 5; ++i) {
        audi.accelerate();
        cout << audi.getMaker() << "->accelerate() " << "speed: " << audi.getSpeed() << endl;
    }
    cout << endl;

    cout << "Mazda call accelerate last time:" << endl;
    mazda.accelerate();
    cout << mazda.getMaker() << "->accelerate() " << "speed: " << mazda.getSpeed() << endl;
    cout << endl;

    cout << "--> Audi call accelerate between 5 times of mazda, but not affect the speed of mazda" << endl;
    cout << endl;

    cout << "Hyundai call accelerate 5 times and brake 5 times:" << endl;
    cout << "--> However the other cars run before, Hyundai start with 0 speed" << endl;
    for (int i = 0; i < 5; ++i) {
        hyundai.accelerate();
        cout << hyundai.getMaker() << "->accelerate() " << "speed: " << hyundai.getSpeed() << endl;
    }
    for (int i = 0; i < 5; ++i) {
        hyundai.brake();
        cout << hyundai.getMaker() << "->brake() " << "speed: " << hyundai.getSpeed() << endl;
    }
    cout << endl;


    cout << "--> The data in each object stays in that object.";

    return 0;
}
/*
 * 1) The accelerate function is not flexible. It always increase the speed with 5 only.
 * I suggest that we should pass a speed value as param into that function to increase whatever we want.
 * Whenever call accelerate the speed will increase the value we gave.
 *
 * 2) We should check the year cannot be a negative number because it is not realistic.
 *
 * 3) We should have a max speed variable because the Int value has a limit.
 * If we call accelerate too many times the speed will be overflow.
 *
 * 4) The above code demonstrate that the data each object stays in that object.
 * when we call accelerate from another car between 2 times of a car,
 * the car speed still increase 5 everytime we call accelerate
 *
 * 5) If we call accelerate() from a car only, we cannot see the data stays in each object.
 * */