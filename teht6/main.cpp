#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

int main() {
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cout << "Exit = 5" << endl;
        cout << "Enter selection: ";

        // Tarkistetaan käyttäjän syöte
        if (!(cin >> selection)) {
            cout << "Invalid input. Exiting..." << endl;
            break; // Poistutaan ohjelmasta, jos syöte ei ole numero
        }

        switch (selection) {
        case 0: {
            string name;
            int age;
            cin.ignore();  // Tyhjennetään edellinen rivinvaihto
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student age: ";
            while (!(cin >> age)) {  // Tarkistetaan, että ikä on numero
                cout << "Invalid input. Enter a number for age: ";
                cin.clear();
            }
            studentList.push_back(Student(name, age));
            break;
        }
        case 1:
            cout << "Student List:" << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 2:
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getName() < b.getName();
                 });
            cout << "Sorted by Name:" << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 3:
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getAge() < b.getAge();
                 });
            cout << "Sorted by Age:" << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 4: {
            string searchName;
            cin.ignore();  // Poistetaan edellinen rivinvaihto
            cout << "Enter student name to search: ";
            getline(cin, searchName);
            auto it = find_if(studentList.begin(), studentList.end(),
                              [&searchName](const Student& s) {
                                  return s.getName() == searchName;
                              });
            if (it != studentList.end()) {
                cout << "Student found:" << endl;
                it->printStudentInfo();
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            return 0; // Lopetetaan ohjelma
        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }
    } while (true);  // Lopetus tapahtuu `case 5` -kohdassa

    return 0;
}
