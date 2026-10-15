#include "post_system.h"
#include <iostream>

using namespace std;
using namespace Lab2;

// Пункт 15: Срр-файл демонстраційної програми
void RunLab2() {

    // Пункт 6: Побудувати 5 об'єктів у статичній пам'яті
    Parcel p1, p2, p3, p4, p5(105, 2.5, 50.0);
    PostOffice o1, o2, o3, o4, o5("Khmelnytskyi", 2);

    // Пункт 6: Побудувати 5 об'єктів у динамічній пам'яті (через оператор new)
    Parcel* dyn_p1 = new Parcel();
    Parcel* dyn_p2 = new Parcel();
    Parcel* dyn_p3 = new Parcel();
    Parcel* dyn_p4 = new Parcel();
    Parcel* dyn_p5 = new Parcel(205, 5.0, 120.0);

    PostOffice* dyn_o1 = new PostOffice();
    PostOffice* dyn_o2 = new PostOffice();
    PostOffice* dyn_o3 = new PostOffice();
    PostOffice* dyn_o4 = new PostOffice();
    PostOffice* dyn_o5 = new PostOffice("Kyiv", 10);

    // Пункт 7: Визначити 2 масиви об'єктів
    Parcel parcel_array[2] = { p1, p5 };
    PostOffice office_array[2] = { o1, o5 };

    // Пункт 8: Продемонструвати роботу з об'єктами, розміщеними в масиві
    cout << "Елемент масиву (номер трекінгу): " << parcel_array[1].tracking_number << "\n";

    // Пункт 9: Продемонструвати роботу усіх методів, описаних в класах
    p5.UpdateStatus(true);
    p5.UpdateStatus("15.10.2026"); // Демонстрація перевантаження

    Parcel p6 = p5.Duplicate(); // Повернення об'єкта
    p1.CopyFrom(p5);            // Передача об'єкта

    p5.SaveToFile("parcel.txt");
    p4.LoadFromFile("parcel.txt");

    // Пункт 10: Сценарій взаємодії двох об'єктів (відділення бере в роботу посилку)
    o5.active_parcel = p5;

    o5.ProcessParcel();
    o5.ProcessParcel(15.5); // Виклик перевантаженого методу

    o1.TransferFrom(o5);
    PostOffice o6 = o5.GetBranch();

    o5.SaveToFile("office.txt");
    o4.LoadFromFile("office.txt");

    // Пункт 11: Використання покажчика на екземпляр класу (доступ через ->)
    PostOffice* ptr_office = &o5;
    cout << "Доступ через покажчик: Місто = " << ptr_office->city << "\n";

    // Пункт 12: Демонстрація роботи додаткового методу з динамічною пам'яттю
    cout << "\n--- Симуляція пакування посилки ---\n";
    p5.SimulatePacking();

    cout << "\n--- Планування логістики відділення ---\n";
    o5.PlanTruckLoading();

    // Обов'язкове звільнення об'єктів з динамічної пам'яті (до Пункту 6)
    delete dyn_p1; delete dyn_p2; delete dyn_p3; delete dyn_p4; delete dyn_p5;
    delete dyn_o1; delete dyn_o2; delete dyn_o3; delete dyn_o4; delete dyn_o5;
}   