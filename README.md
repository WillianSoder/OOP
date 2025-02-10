
# OOP

#### This repository contains my Object-Oriented Programming (OOP) studies, which I developed during my Computer Engineering course at UTFPR. The code samples here are various tests and exercises I created while learning about fundamental OOP concepts in C++. Below is a brief explanation of the key topics I studied:

 * ### Classes and Objects: classes define the blueprint for creating objects, encapsulating data (attributes) and behaviors (methods). An object is an instance of a class that can store unique values in its attributes and execute methods.
 Example in C++:
 ```bash
 class Car {
public:
    string brand;
    void honk() { cout << "Beep! Beep!" << endl; }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota";
    myCar.honk();
}
 ```


 * ### Encapsulation: restricts direct access to an object's internal data, allowing access only through controlled methods (getters and setters).
 Example in C++: 

```bash
class BankAccount {
private:
    double balance;
public:
    void setBalance(double b) { balance = b; }
    double getBalance() { return balance; }
};
```


* ### Inheritance: allows a child class to acquire attributes and methods from a parent class, promoting code reuse.
 Example in C++: 
```bash
class Animal {
public:
    void makeSound() { cout << "Some sound!" << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!" << endl; }
};
```


* ### Polymorphism: enables a method to have different behaviors depending on the object that calls it. It is implemented via method overriding (with virtual functions) or function overloading.
 Example in C++:
```bash
class Animal {
public:
    virtual void makeSound() { cout << "Animal sound" << endl; }
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Woof!" << endl; }
};
```


* ### Type Casting (Cast): casting converts one data type into another. In OOP, it's commonly used to cast between base and derived classes.
 Example in C++: 
```bash
class Base {};
class Derived : public Base {};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
}
```


* ### Dynamic Binding: dynamic binding allows method calls to be resolved at runtime instead of compile-time, enabling polymorphism. Achieved through virtual functions in C++.
 Example in C++: 
```bash
class Parent {
public:
    virtual void show() { cout << "Parent class" << endl; }
};

class Child : public Parent {
public:
    void show() override { cout << "Child class" << endl; }
};
```


* ### Abstract Classes: an abstract class is a class that cannot be instantiated and serves as a base for other classes. It contains at least one pure virtual function (= 0).
 Example in C++: 
```bash
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a Circle" << endl; }
};
```


* ### Interfaces: C++ does not have native interfaces, but they are simulated using abstract classes with only pure virtual functions.
 Example in C++:
```bash
class IShape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Rectangle : public IShape {
public:
    void draw() override { cout << "Drawing a Rectangle" << endl; }
};
```

#### This repository serves as a record of my learning journey in Object-Oriented Programming in C++, consolidating theoretical concepts with practical coding exercises. 🚀
 