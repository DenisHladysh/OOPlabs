#include "post_system.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Пункт 15: Срр-файл із реалізацією класу
namespace Lab2 {

    // --- Реалізація методів класу Parcel ---
    Parcel::Parcel() {
        weight_ = 0.0;
        price_ = 0.0;
        send_date_ = "01.01.2026";
        delivery_date_ = "01.01.2026";
        is_delivered_ = false;
        sender_name = "Unknown";
        receiver_name = "Unknown";
        tracking_number = 0;
    }

    Parcel::Parcel(int tracking, double weight, double price) {
        weight_ = weight;
        price_ = price;
        send_date_ = "14.10.2026";
        delivery_date_ = "20.10.2026";
        is_delivered_ = false;
        sender_name = "Client";
        receiver_name = "Receiver";
        tracking_number = tracking;
    }

    // Пункт 4: Перевантажений метод (варіант 1 - статус)
    void Parcel::UpdateStatus(bool status) {
        is_delivered_ = status;
    }

    // Пункт 4: Перевантажений метод (варіант 2 - дата)
    void Parcel::UpdateStatus(string new_delivery_date) {
        delivery_date_ = new_delivery_date;
    }

    // Пункт 4: Метод приймає об'єкт
    void Parcel::CopyFrom(Parcel other_parcel) {
        weight_ = other_parcel.weight_;
        price_ = other_parcel.price_;
        tracking_number = other_parcel.tracking_number;
    }

    // Пункт 4: Метод повертає об'єкт
    Parcel Parcel::Duplicate() const {
        Parcel p;
        p.tracking_number = tracking_number + 1;
        p.price_ = price_;
        return p;
    }

    // Пункт 5: Читання/запис файлів
    void Parcel::SaveToFile(string filename) {
        ofstream file(filename);
        file << tracking_number << "\n" << price_ << "\n" << is_delivered_ << "\n";
        file.close();
    }

    void Parcel::LoadFromFile(string filename) {
        ifstream file(filename);
        file >> tracking_number >> price_ >> is_delivered_;
        file.close();
    }

    // Пункт 12: Динамічна пам'ять + сортування (Бізнес-логіка: Симуляція пакування)
    void Parcel::SimulatePacking() {
        int items_count = rand() % 10 + 5;
        int* items_weights = new int[items_count]; // Виділення динамічної пам'яті
        double total_simulated_weight = 0;

        for (int i = 0; i < items_count; i++) {
            items_weights[i] = rand() % 10 + 1;
            total_simulated_weight += items_weights[i];
        }

        sort(items_weights, items_weights + items_count); // Сортування

        cout << "Речі в посилці відсортовані для пакування (від легких до важких): ";
        for (int i = 0; i < items_count; i++) {
            cout << items_weights[i] << " ";
        }

        weight_ = total_simulated_weight; // Взаємодія з приватними полями
        price_ = total_simulated_weight * 15.5;

        cout << "\nЗагальна вага посилки оновлена: " << weight_ << " кг. Нова ціна: " << price_ << " грн.\n";

        delete[] items_weights; // Звільнення динамічної пам'яті
    }

    double Parcel::GetPrice() {
        return price_;
    }

    // --- Реалізація методів класу PostOffice ---
    PostOffice::PostOffice() {
        max_capacity_ = 100;
        current_parcels_count_ = 0;
        total_revenue_ = 0.0;
        is_open_ = true;
        manager_name_ = "Admin";
        city = "Khmelnytskyi";
        office_number = 1;
    }

    PostOffice::PostOffice(string city_name, int number) {
        max_capacity_ = 200;
        current_parcels_count_ = 0;
        total_revenue_ = 0.0;
        is_open_ = true;
        manager_name_ = "Admin";
        city = city_name;
        office_number = number;
    }

    void PostOffice::ProcessParcel() {
        total_revenue_ += active_parcel.GetPrice();
        current_parcels_count_++;
    }

    void PostOffice::ProcessParcel(double extra_fee) {
        total_revenue_ += active_parcel.GetPrice() + extra_fee;
        current_parcels_count_++;
    }

    void PostOffice::TransferFrom(PostOffice other_office) {
        total_revenue_ += other_office.total_revenue_;
    }

    PostOffice PostOffice::GetBranch() {
        PostOffice branch(city, office_number + 1);
        return branch;
    }

    void PostOffice::SaveToFile(string filename) {
        ofstream file(filename);
        file << city << "\n" << office_number << "\n" << total_revenue_ << "\n";
        file.close();
    }

    void PostOffice::LoadFromFile(string filename) {
        ifstream file(filename);
        file >> city >> office_number >> total_revenue_;
        file.close();
    }

    // Пункт 12: Динамічна пам'ять (Бізнес-логіка: Планування фури)
    void PostOffice::PlanTruckLoading() {
        int incoming_count = rand() % 20 + 10;
        int* incoming_weights = new int[incoming_count];

        for (int i = 0; i < incoming_count; i++) {
            incoming_weights[i] = rand() % 50 + 1;
        }

        sort(incoming_weights, incoming_weights + incoming_count);

        cout << "План завантаження вантажівки складено (вага посилок): ";
        for (int i = 0; i < incoming_count; i++) {
            cout << incoming_weights[i] << " ";
        }
        cout << "\nФура готова до відправки!\n";

        delete[] incoming_weights;
    }
}