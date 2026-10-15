#include <iostream>
#include <Windows.h>
#include "lab1.h"        
#include "post_system.h" 
#include "lab3.h"
#include "lab4.h"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);  
   
    int choice;

    while (true) {
        cout << "\n=== МОЇ ЛАБОРАТОРНІ З ООП ===" << endl;
        cout << "1. Запустити Лабораторну 1 (Студенти)" << endl;
        cout << "2. Запустити Лабораторну 2 (Пошта)" << endl;
        cout << "3. Запустити Лабораторну 3 (25 пунктів)" << endl;
        cout << "4. Запустити Лабораторну 4 (Спадкування)" << endl;
        cout << "0. Вийти" << endl;
        cout << "Виберіть номер: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- ЛАБОРАТОРНА 1 ---\n";
            RunLab1();
        }
        else if (choice == 2) {
            cout << "\n--- ЛАБОРАТОРНА 2 ---\n";
            RunLab2();
        }
        else if (choice == 3) {
            cout << "\n--- ЛАБОРАТОРНА 3 ---\n";
            RunLab3();
        }
        else if (choice == 4) {
            cout << "\n--- ЛАБОРАТОРНА 4 ---\n";
            RunLab4();
        }
        else if (choice == 0) {
            break;
        }

        else {
            cout << "Такої лаби ще немає!" << endl;
        }
    }

    return 0;
}