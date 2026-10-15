#ifndef POST_SYSTEM_H
#define POST_SYSTEM_H
#include <string>

// Пункт 15: Програма використовує три файли (це заголовний .h файл)
namespace Lab2 {

    // Пункт 1: Визначення користувацького класу (не менше 8 полів на клас)
    class Parcel {
    private:
        // Пункт 2: 5 приватних елементів. 
        // Пункт 14: Дотримання Google Code Style (нижнє підкреслення для приватних змінних)
        double weight_;
        double price_;
        std::string send_date_;
        std::string delivery_date_;
        bool is_delivered_;

    public:
        // Пункт 2: 3 загальні (публічні) елементи
        std::string sender_name;
        std::string receiver_name;
        int tracking_number;

        // Пункт 4: 6 методів (включаючи конструктори)
        Parcel();
        Parcel(int tracking, double weight, double price);

        // Пункт 4: Два перевантажені методи (однакова назва, різні параметри)
        void UpdateStatus(bool status);
        void UpdateStatus(std::string new_delivery_date);

        // Пункт 4: Метод, що приймає об'єкт класу як параметр
        void CopyFrom(Parcel other_parcel);

        // Пункт 4: Метод, що повертає об'єкт класу
        Parcel Duplicate() const;

        // Пункт 5: Методи для запису та читання з файлу
        void SaveToFile(std::string filename);
        void LoadFromFile(std::string filename);

        // Пункт 12: Додатковий метод (динамічна пам'ять та сортування з логікою)
        void SimulatePacking();

        double GetPrice();
    };

    // Пункт 1: Визначення другого користувацького класу
    class PostOffice {
    private:
        // Пункт 2: 5 приватних елементів
        int max_capacity_;
        int current_parcels_count_;
        double total_revenue_;
        bool is_open_;
        std::string manager_name_;

    public:
        // Пункт 2: 3 загальні (публічні) елементи
        std::string city;
        int office_number;

        // Пункт 3: Зв'язок двох об'єктів (розміщення об'єкта Parcel у PostOffice)
        Parcel active_parcel;

        // Пункт 4: 6 методів для опрацювання даних
        PostOffice();
        PostOffice(std::string city_name, int number);

        // Пункт 4: Перевантажені методи
        void ProcessParcel();
        void ProcessParcel(double extra_fee);

        // Пункт 4: Метод, що приймає об'єкт 
        void TransferFrom(PostOffice other_office);

        // Пункт 4: Метод, що повертає об'єкт
        PostOffice GetBranch();

        // Пункт 5: Запис та читання з файлу
        void SaveToFile(std::string filename);
        void LoadFromFile(std::string filename);

        // Пункт 12: Метод з динамічною пам'яттю
        void PlanTruckLoading();
    };
}
void RunLab2();
#endif