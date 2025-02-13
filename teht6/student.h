#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    // Konstruktori
    Student(std::string name, int age) : name(name), age(age) {}

    // Setterit
    void setName(std::string newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

    // Getterit
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Tulostusfunktio
    void printStudentInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

#endif
