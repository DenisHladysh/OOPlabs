#ifndef LAB3_H
#define LAB3_H

#include <string>
namespace Lab3 {
    class Parcel {
    private:
        double weight_;
        double price_;
        int tracking_id_;
        bool is_fragile_;
        static int total_parcels_;

    public:
        std::string sender;
        std::string receiver;
        std::string date;

        Parcel();
        Parcel(double weight, double price);
        Parcel(const Parcel& other);
        ~Parcel();

        void SetPrice(double p);
        void SetPrice(double p, double discount);
        Parcel Duplicate();
        void CopyData(Parcel p);
        void SaveToFile(std::string filename);
        void LoadFromFile(std::string filename);

        double GetWeight();
        static int GetTotalParcels();
    };

    class Client {
    private:
        int client_id_;
        double money_;
        int age_;
        int discount_;
        std::string phone_;

    public:
        std::string name;
        std::string surname;
        Parcel my_parcel;

        Client();
        Client(int id, double money);
        Client(const Client& other);
        ~Client();

        void SpendMoney(double amount);
        void SpendMoney(double amount, double fee);
        Client Clone();
        void UpdateFrom(Client c);
        void SaveToFile(std::string filename);
        void LoadFromFile(std::string filename);
    };

    class PostOffice {
    private:
        int office_id_;
        int max_parcels_;
        double cash_register_;
        std::string manager_;
        Client* active_client_;

    public:
        std::string location;
        bool is_open;
        int rating;

        PostOffice();
        PostOffice(int id, std::string loc);
        PostOffice(const PostOffice& other);
        ~PostOffice();

        void AddCash(double amount);
        void AddCash(double amount, double bonus);
        PostOffice GetBranch();
        void AssignClient(Client* c);
        void SaveToFile(std::string filename);
        void LoadFromFile(std::string filename);
    };

    class DeliveryOperation {
    public:
        void Execute(Client& c, Parcel& p, PostOffice& o);
    };

    void CalculateTax(Parcel p);
    void CalculateTax(Parcel* p);
    Parcel CreateBonusParcel();
}
void RunLab3();

#endif
