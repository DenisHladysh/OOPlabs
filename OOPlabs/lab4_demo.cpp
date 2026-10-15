#include "lab4.h"
#include <iostream>

using namespace std;

void RunLab4() {
    cout << "\n=== ЗАПУСК ЛАБОРАТОРНОЇ 4 ===\n";

    cout << "\n--- Тест 1: Конструктори та передача 5+ параметрів ---\n";
    Parcel4 p_params(99, 10.5, 200.0, "В дорозі", "Київ", "Денис", "Олег", "14.10", true, 50.0);

    cout << "\n--- Тест 2: Доступ (public, private, protected) та :: ---\n";
    p_params.CheckBaseAccess();
    cout << "Ціна через using: " << p_params.GetPrice() << "\n";

    cout << "\n--- Тест 3: Закрите успадкування (Task 9) ---\n";
    SecretDocument secret;
    secret.RevealSecret();

    cout << "\n--- Тест 4: Множинне успадкування (Task 10) ---\n";
    PremiumParcel premium;

    cout << "\n--- Тест 5: Дружні класи та функції (Task 16, 17) ---\n";
    InspectMail(p_params);
    Customs my_customs;
    my_customs.Confiscate(p_params);

    cout << "\n--- Тест 6: 5 статичних і 5 динамічних об'єктів ---\n";
    Parcel4 s1, s2, s3, s4, s5;
    Parcel4* d1 = new Parcel4();
    Parcel4* d2 = new Parcel4();
    Parcel4* d3 = new Parcel4();
    Parcel4* d4 = new Parcel4();
    Parcel4* d5 = new Parcel4();

    OutsideFunctionLab4(s1);
    OutsideFunctionLab4(d1);

    cout << "\nОчищення пам'яті:\n";
    delete d1; delete d2; delete d3; delete d4; delete d5;

    cout << "\nЗараз спрацює ланцюжок деструкторів:\n";
}