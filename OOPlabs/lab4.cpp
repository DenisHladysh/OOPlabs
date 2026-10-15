#include "lab4.h"
#include <iostream>

using namespace std;

MailItem::MailItem() : id_(0), base_weight_(0), internal_code_("000"), is_scanned_(false), warehouse_zone_(1), base_price_(0), status_("None"), origin_city_("None") {
    sender = "N/A"; receiver = "N/A"; date = "01.01.26";
    cout << "[Базовий] MailItem створено (без параметрів)\n";
}

MailItem::MailItem(int id, double bw, double bp, string st, string org, string snd, string rcv, string dt)
    : id_(id), base_weight_(bw), internal_code_("XYZ"), is_scanned_(true), warehouse_zone_(2), base_price_(bp), status_(st), origin_city_(org) {
    sender = snd; receiver = rcv; date = dt;
    cout << "[Базовий] MailItem створено (з параметрами)\n";
}

MailItem::MailItem(const MailItem& other) {
    id_ = other.id_; base_weight_ = other.base_weight_; base_price_ = other.base_price_;
    cout << "[Базовий] MailItem копія\n";
}

MailItem::~MailItem() {
    cout << "[Базовий] MailItem знищено\n";
}

void MailItem::PrintBaseInfo() { cout << "Відправник: " << sender << "\n"; }
double MailItem::GetPrice() { return base_price_; }
void MailItem::SetStatus(string s) { status_ = s; }

int Parcel4::total_parcels_ = 0;

Parcel4::Parcel4() : MailItem(), is_fragile_(false), extra_fee_(0.0), volume_(10), packing_type_("Box") {
    courier_name = "Ivan"; delivery_days = 3; signature_required = false;
    total_parcels_++;
    cout << "[Похідний] Parcel4 створено\n";
}

Parcel4::Parcel4(int id, double bw, double bp, string st, string org, string snd, string rcv, string dt, bool frag, double fee)
    : MailItem(id, bw, bp, st, org, snd, rcv, dt), is_fragile_(frag), extra_fee_(fee), volume_(20), packing_type_("Wood") {
    courier_name = "Oleg"; delivery_days = 1; signature_required = true;
    total_parcels_++;
    cout << "[Похідний] Parcel4 створено (з передачею параметрів базі)\n";
}

Parcel4::~Parcel4() {
    cout << "[Похідний] Parcel4 знищено\n";
}

void Parcel4::PrintInfo() {
    PrintBaseInfo();
}

void Parcel4::CheckBaseAccess() {
    cout << "Доступ через :: -> Статус: " << MailItem::status_ << "\n";
}

int Parcel4::GetTotal() { return total_parcels_; }

SecretDocument::SecretDocument() : MailItem(), clearance_level_(5), encryption_key_("123"), is_shredded_(false), agent_id_(7), safe_code_("000") {
    department = "X"; priority = 1; requires_biometrics = true;
    cout << "[Секретний] Документ створено (закрите успадкування)\n";
}

SecretDocument::~SecretDocument() { cout << "[Секретний] Документ спалено\n"; }
void SecretDocument::RevealSecret() { cout << "Секретний статус: " << status_ << "\n"; }

InsuredItem::InsuredItem() : insurance_amount_(1000), insurance_company_("AXA"), policy_number_(1), is_active_(true), coverage_limit_(5000) {
    policy_type = "Basic"; expiry_date = "2027"; full_coverage = false;
    cout << "[Множинне-1] Страховка оформлена\n";
}
InsuredItem::~InsuredItem() { cout << "[Множинне-1] Страховка закінчилась\n"; }

ExpressItem::ExpressItem() : speed_multiplier_(2), use_air_plane_(true), priority_lane_("A1"), max_delay_hours_(2), express_tax_(50) {
    plane_number = "Boeing"; skip_customs = false; assigned_pilot = "Max";
    cout << "[Множинне-2] Експрес-доставка активована\n";
}
ExpressItem::~ExpressItem() { cout << "[Множинне-2] Експрес завершено\n"; }

PremiumParcel::PremiumParcel() : Parcel4(), InsuredItem(), ExpressItem(), vip_manager_("Anna"), bonus_points_(100), gift_wrap_(true), promo_code_("VIP"), discount_(10) {
    membership_level = "Gold"; free_tracking = true; lounge_access = 1;
    cout << "[Супер-Клас] Преміум посилка зібрана (Множинне успадкування)\n";
}

PremiumParcel::~PremiumParcel() { cout << "[Супер-Клас] Преміум посилка доставлена\n"; }
void PremiumParcel::ShowAllPowers() { cout << "Преміум менеджер: " << vip_manager_ << "\n"; }

void InspectMail(Parcel4& p) {
    cout << "[Дружня Функція] Митниця перевіряє приватний збір: " << p.extra_fee_ << "\n";
}

void Customs::Confiscate(Parcel4& p) {
    cout << "[Дружній Клас] Митниця змінює приватне пакування: " << p.packing_type_ << " на 'Відкрито'\n";
    p.packing_type_ = "Opened";
}

void OutsideFunctionLab4(Parcel4 p) { cout << "Зовнішня функція (копія)\n"; }
void OutsideFunctionLab4(Parcel4* p) { cout << "Зовнішня функція (покажчик)\n"; }