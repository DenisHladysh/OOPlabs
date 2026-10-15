#include "lab1.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    char name[50];
    char gender[10];
    int course;
    char group[20];
};

void RW(const vector<Student>& students, const string& filename) {
    ofstream file(filename, ios::binary);
    for (const auto& s : students) {
        file.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    }
    file.close();
}

void RD(vector<Student>& students, const string& filename) {
    ifstream file(filename, ios::binary);
    Student s;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        students.push_back(s);
    }
    file.close();
}

void RW(const string& textInfo, const string& filename) {
    ofstream file(filename);
    file << textInfo;
    file.close();
}

void RD(string& textInfo, const string& filename) {
    ifstream file(filename);
    string line;
    textInfo = "";
    while (getline(file, line)) {
        textInfo += line + "\n";
    }
    file.close();
}

void RunLab1() {
    vector<Student> myStudents = {
        { "Denys Hladysh", "Male", 2, "IST-25-1" },
        { "Anna Petrenko", "Female", 2, "IST-25-1" },
        { "Oleg Sydorov", "Male", 3, "PZ-24-1" },
        { "Ivan Ivanchuk", "Male", 2, "IST-25-1" }
    };

    RW(myStudents, "INFO.DAT");

    vector<Student> readStudents;
    RD(readStudents, "INFO.DAT");

    string resultText = "Знайдені студенти:\n";
    int searchCourse = 2;
    string searchGroup = "IST-25-1";

    cout << "Всі студенти з файлу INFO.DAT:\n";
    for (const auto& s : readStudents) {
        cout << s.name << " | " << s.gender << " | " << s.course << " | " << s.group << "\n";

        string sGender = s.gender;
        string sGroup = s.group;

        if (sGender == "Male" && s.course == searchCourse && sGroup == searchGroup) {
            resultText += string(s.name) + "\n";
        }
    }

    RW(resultText, "INFO.TXT");

    string textFromFile;
    RD(textFromFile, "INFO.TXT");

    cout << "\nВміст текстового файлу INFO.TXT (результат пошуку):\n";
    cout << textFromFile;

}