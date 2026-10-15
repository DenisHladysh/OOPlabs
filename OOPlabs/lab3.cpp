#include "lab3.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace Lab3 {
    int Parcel::total_parcels_ = 0;

    Parcel::Parcel() {
        weight_ = 0.0; price_ = 0.0; tracking_id_ = 0; is_fragile_ = false;
        sender = "N/A"; receiver = "N/A"; date = "01.01.26";
        total_parcels_++;
        cout << "[Створення] Порожня посилка\n";
    }

    Parcel::Parcel(double weight, double price) : weight_(weight), price_(price), tracking_id_(1), is_fragile_(false) {
        sender = "A"; receiver = "B"; date = "02.01.26";
        total_parcels_++;
        cout << "[Створення] Посилка з параметрами\n";
    }

    Parcel::Parcel(const Parcel& other) {
        weight_ = other.weight_; price_ = other.price_; tracking_id_ = other.tracking_id_;
        is_fragile_ = other.is_fragile_; sender = other.sender; receiver = other.receiver; date = other.date;
        total_parcels_++;
        cout << "[Створення] Копія посилки\n";
    }

    Parcel::~Parcel() {
        cout << "[Знищення] Посилка видаляється з пам'яті\n";
    }

    void Parcel::SetPrice(double p) { price_ = p; }
    void Parcel::SetPrice(double p, double discount) { price_ = p - discount; }
    Parcel Parcel::Duplicate() { return *this; }
    void Parcel::CopyData(Parcel p) { weight_ = p.weight_; }
    void Parcel::SaveToFile(string filename) { ofstream f(filename); f << price_; f.close(); }
    void Parcel::LoadFromFile(string filename) { ifstream f(filename); f >> price_; f.close(); }
    double Parcel::GetWeight() { return weight_; }
    int Parcel::GetTotalParcels() { return total_parcels_; }

    Client::Client() { client_id_ = 0; money_ = 100; age_ = 18; discount_ = 0; phone_ = "000"; name = "N/A"; surname = "N/A"; }
    Client::Client(int id, double money) : client_id_(id), money_(money), age_(20), discount_(5), phone_("111") { name = "X"; surname = "Y"; }
    Client::Client(const Client& other) { client_id_ = other.client_id_; money_ = other.money_; }
    Client::~Client() { cout << "[Знищення] Клієнт видаляється\n"; }

    void Client::SpendMoney(double amount) { money_ -= amount; }
    void Client::SpendMoney(double amount, double fee) { money_ -= (amount + fee); }
    Client Client::Clone() { return *this; }
    void Client::UpdateFrom(Client c) { money_ = c.money_; }
    void Client::SaveToFile(string filename) { ofstream f(filename); f << money_; f.close(); }
    void Client::LoadFromFile(string filename) { ifstream f(filename); f >> money_; f.close(); }

    PostOffice::PostOffice() { office_id_ = 1; max_parcels_ = 10; cash_register_ = 0; manager_ = "Admin"; active_client_ = nullptr; location = "Center"; is_open = true; rating = 5; }
    PostOffice::PostOffice(int id, string loc) : office_id_(id), max_parcels_(20), cash_register_(100), manager_("Bob"), active_client_(nullptr) { location = loc; is_open = true; rating = 4; }
    PostOffice::PostOffice(const PostOffice& other) { office_id_ = other.office_id_; cash_register_ = other.cash_register_; }
    PostOffice::~PostOffice() { cout << "[Знищення] Відділення зачиняється\n"; }

    void PostOffice::AddCash(double amount) { cash_register_ += amount; }
    void PostOffice::AddCash(double amount, double bonus) { cash_register_ += amount + bonus; }
    PostOffice PostOffice::GetBranch() { return *this; }
    void PostOffice::AssignClient(Client* c) { active_client_ = c; }
    void PostOffice::SaveToFile(string filename) { ofstream f(filename); f << cash_register_; f.close(); }
    void PostOffice::LoadFromFile(string filename) { ifstream f(filename); f >> cash_register_; f.close(); }

    void DeliveryOperation::Execute(Client& c, Parcel& p, PostOffice& o) {
        cout << "Асоціація: Клієнт " << c.name << " відправив посилку у відділення " << o.location << "\n";
    }

    void CalculateTax(Parcel p) {
        cout << "Податок (копія): " << p.GetWeight() * 0.2 << "\n";
    }
    void CalculateTax(Parcel* p) {
        cout << "Податок (покажчик): " << p->GetWeight() * 0.2 << "\n";
    }

    Parcel CreateBonusParcel() {
        Parcel p;
        p.SetPrice(0.0);
        return p;
    }
}