#include "Contact.hpp"

Contact::Contact() 
    : firstname_("")
    , lastname_("")
    , nickname_("")
    , phone_("")
    , secret_("") {}

Contact::~Contact() {}

void Contact::Set_FirstName(const std::string &firstname) { firstname_ = firstname; }
void Contact::Set_Secret(const std::string &secret) { secret_ = secret; }
void Contact::Set_Phone(const std::string &phone) { phone_ = phone; }
void Contact::Set_Nickname(const std::string &nickname) { nickname_ = nickname; }
void Contact::Set_LastName(const std::string &lastname) { lastname_ = lastname; }

const std::string& Contact::Get_FirstName() const { return firstname_; }
const std::string& Contact::Get_LastName() const { return lastname_; }
const std::string& Contact::Get_NickName() const { return nickname_; }
const std::string& Contact::Get_Phone() const { return phone_; }
const std::string& Contact::Get_Secret() const { return secret_; }
