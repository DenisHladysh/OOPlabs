#ifndef LAB4_H
#define LAB4_H

#include <string>

class MailItem {
private:
    int id_;
    double base_weight_;
    std::string internal_code_;
    bool is_scanned_;
    int warehouse_zone_;

protected:
    double base_price_;
    std::string status_;
    std::string origin_city_;

public:
    std::string sender;
    std::string receiver;
    std::string date;

    MailItem();
    MailItem(int id, double bw, double bp, std::string st, std::string org, std::string snd, std::string rcv, std::string dt);
    MailItem(const MailItem& other);
    ~MailItem();

    void PrintBaseInfo();
    double GetPrice();
    void SetStatus(std::string s);
};

class Parcel4 : public MailItem {
private:
    bool is_fragile_;
    double extra_fee_;
    int volume_;
    std::string packing_type_;
    static int total_parcels_;

public:
    std::string courier_name;
    int delivery_days;
    bool signature_required;

    Parcel4();
    Parcel4(int id, double bw, double bp, std::string st, std::string org, std::string snd, std::string rcv, std::string dt, bool frag, double fee);
    ~Parcel4();

    void PrintInfo();
    using MailItem::GetPrice;
    void CheckBaseAccess();
    static int GetTotal();

    friend void InspectMail(Parcel4& p);
    friend class Customs;
};

class SecretDocument : private MailItem {
private:
    int clearance_level_;
    std::string encryption_key_;
    bool is_shredded_;
    int agent_id_;
    std::string safe_code_;

public:
    std::string department;
    int priority;
    bool requires_biometrics;

    SecretDocument();
    ~SecretDocument();
    void RevealSecret();
};

class InsuredItem {
protected:
    double insurance_amount_;
    std::string insurance_company_;
    int policy_number_;
    bool is_active_;
    double coverage_limit_;

public:
    std::string policy_type;
    std::string expiry_date;
    bool full_coverage;

    InsuredItem();
    ~InsuredItem();
};

class ExpressItem {
protected:
    int speed_multiplier_;
    bool use_air_plane_;
    std::string priority_lane_;
    int max_delay_hours_;
    double express_tax_;

public:
    std::string plane_number;
    bool skip_customs;
    std::string assigned_pilot;

    ExpressItem();
    ~ExpressItem();
};

class PremiumParcel : public Parcel4, public InsuredItem, public ExpressItem {
private:
    std::string vip_manager_;
    int bonus_points_;
    bool gift_wrap_;
    std::string promo_code_;
    double discount_;

public:
    std::string membership_level;
    bool free_tracking;
    int lounge_access;

    PremiumParcel();
    ~PremiumParcel();
    void ShowAllPowers();
};

class Customs {
public:
    void Confiscate(Parcel4& p);
};

void InspectMail(Parcel4& p);
void OutsideFunctionLab4(Parcel4 p);
void OutsideFunctionLab4(Parcel4* p);

void RunLab4();

#endif