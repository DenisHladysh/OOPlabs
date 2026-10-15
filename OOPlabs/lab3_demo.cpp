#include "lab3.h"
#include <iostream>

using namespace std;
using namespace Lab3;

void RunLab3() {
    cout << "\n=== ЗАПУСК ЛАБОРАТОРНОЇ 3 ===\n";

    Parcel simple_parcel;
    Parcel explicit_parcel = Parcel(10.5, 50.0);
    Parcel implicit_parcel(2.0, 15.0);

    Parcel p1, p2, p3, p4, p5;
    Parcel* dp1 = new Parcel();
    Parcel* dp2 = new Parcel();
    Parcel* dp3 = new Parcel();
    Parcel* dp4 = new Parcel();
    Parcel* dp5 = new Parcel();

    Parcel arr[3] = { p1, p2, explicit_parcel };
    Parcel* ptr = &arr[1];
    ptr->SetPrice(100.0);

    cout << "\nВсього створено посилок: " << Parcel::GetTotalParcels() << "\n\n";

    CalculateTax(explicit_parcel);
    CalculateTax(&explicit_parcel);

    Parcel bonus = CreateBonusParcel();

    Client main_client(1, 500.0);
    main_client.name = "Denys";
    main_client.my_parcel.SetPrice(200.0);

    PostOffice my_office(10, "Khmelnytskyi");
    my_office.AssignClient(&main_client);

    DeliveryOperation operation;
    operation.Execute(main_client, explicit_parcel, my_office);

    cout << "\nОчищення динамічної пам'яті:\n";
    delete dp1; delete dp2; delete dp3; delete dp4; delete dp5;

    cout << "\nКінець програми (зараз спрацюють деструктори статичних об'єктів):\n";
}