#include <iostream>
#include <string>

using namespace std;

/*
Abstract class --> 
1. Act as an interface for the outside world to operate the car. 
2. This abstract class tells 'WHAT' all it can do rather then 'HOW' it does that , achieved using pure virtual functions.
3. Since this is an abstract class we cannot directly create Objects of this class. 
4. We need to Inherit it first and then that child class will have the responsibility to 
provide implementation details of all the abstract (virtual) methods in the class.

5. In our real world example of Car, imagine you sitting in the car and able to operate
the car (startEngine, accelerate, brake, turn) just by pressing or moving some
pedals/buttons/ steer the wheel etc. You dont need to know how these things work, and
also they are hidden under the hood.
6. This Class 'Car' denotes that (pedals/buttons/steering wheel etc). 



Conclusion:
An abstract class in C++ is a class that cannot be instantiated (you can’t create objects of it).
It is mainly used as a base class to provide a common interface for derived classes.

- A class becomes abstract when it contains at least one pure virtual function.
- A pure virtual function is declared by assigning = 0 in its declaration.
- Derived classes must override all pure virtual functions, otherwise the derived class also becomes abstract.


#When we declare a function as virtual:
If a derived class overrides it, then calling via base pointer/reference will execute the derived version (runtime polymorphism).
If not overridden, the base version is used.
virtual enables polymorphism, but overriding is optional.


#Pure Virtual Function (= 0):
every derived class must override it, otherwise the derived class itself becomes abstract.
No default implementation is provided in base
The class becomes abstract → you cannot create objects of it.
*/


class Car {
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

/*
1. This is a Concrete class (A class that provide implementation details of an abstract class).
Now anyone can make an Object of 'SportsCar' and can assign it to 'Car' (Parent class) pointer 
(See main method for this)

2. In our real world example of Car, as you cannot have a real car by just having its body only
(all these buttons or steering wheel). You need to have the actual implementation of 'What' happens
when we press these buttons. 'SportsCar' class denotes that actual implementation. 

3. Therefore, to denote a real world car in programming we created 2 classes.
One to denote all the user-interface like pedals, buttons, steering wheels etc ('Car' class).And,
Another one to denote the actual car with all the implementations of these buttons (SportsCar' class).
 
*/

class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }



    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

// Main Method
int main() {

    Car* myCar = new SportsCar("Ford", "Mustang");  // parent class pointer pointing to child class object // aisa hi krna hota hai

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;    

    return 0;
}




/*
Q) why abstract classes (base classes with pure virtual functions) are needed when we can just put methods in child classes??
If you only write methods in child classes (e.g., Circle, Square), then:
- You have no common interface for different shapes.
- You cannot store different objects in a single container.
- You cannot use polymorphism (deciding behavior at runtime).



Example ❌ (no abstract class):
class Circle {
public:
    void draw() { cout << "Drawing Circle\n"; }
};

class Square {
public:
    void draw() { cout << "Drawing Square\n"; }
};

int main() {
    Circle c;
    Square s;

    // You must call individually, no common type
    c.draw();
    s.draw();
}

Here, if you want to handle multiple shapes together, you can’t — you must know their exact type.


*/