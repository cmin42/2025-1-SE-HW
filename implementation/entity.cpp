#include "entity.h"

using namespace std;

// User 클래스 구현
User::User(string id, string password) : userId(id), userPassword(password) {}
User::~User() {}

string User::getUserId() const { return userId; }
string User::getPassword() const { return userPassword; }
bool User::isAdmin() const { return false; }


// Admin 클래스 구현
Admin::Admin(string id, string password) : User(id, password) {}
bool Admin::isAdmin() const { return true; }


// Bike 클래스 구현
Bike::Bike(string id, string name) : bikeId(id), bikeName(name), rentMember(nullptr) {}

string Bike::getBikeId() const { return bikeId; }
string Bike::getBikeName() const { return bikeName; }
Member* Bike::getRentMember() const { return rentMember; }

void Bike::setRentMember(Member* member) {
    rentMember = member;
}


// Member 클래스 구현
Member::Member(string id, string password, string phone)
    : User(id, password), memberPhone(phone) {
}

const vector<Bike*>& Member::getRentalBikeList() const {
    return rentalBikeList;
}

void Member::addRentalBike(Bike* bike) {
    if (bike) {
        rentalBikeList.push_back(bike);
    }
}

string Member::getPhone() const {
    return memberPhone;
}


// UserCollection 클래스 구현
map<string, User*> UserCollection::users;

UserCollection::UserCollection() {}
UserCollection::~UserCollection() {
    for (auto& pair : users) {
        delete pair.second;
    }
    users.clear();
}

User* UserCollection::findUser(const string& userId, const string& password) {
    auto it = users.find(userId);
    if (it != users.end() && it->second->getPassword() == password) {
        return it->second;
    }
    return nullptr;
}

bool UserCollection::addUser(User* user) {
    if (!user) return false;

    string userId = user->getUserId();
    if (users.find(userId) != users.end()) {
        return false; // 이미 존재하는 유저
    }

    users[userId] = user;
    return true;
}

void UserCollection::initialize() {
    // 기본 Admin 계정 추가
    if (users.find("admin") == users.end()) {
        User* user = new Admin("admin", "admin");
        users["admin"] = user;
    }
}


// BikeCollection 클래스 구현
map<string, Bike*> BikeCollection::bikes;

BikeCollection::BikeCollection() {}
BikeCollection::~BikeCollection() {
    for (auto& pair : bikes) {
        delete pair.second;
    }
    bikes.clear();
}

bool BikeCollection::addBike(Bike* bike) {
    if (!bike) return false;

    string bikeId = bike->getBikeId();
    if (bikes.find(bikeId) != bikes.end()) {
        return false; // 이미 존재하는 자전거일 경우 fail
    }

    bikes[bikeId] = bike;
    return true;
}

Bike* BikeCollection::getBike(const string& bikeId) {
    auto it = bikes.find(bikeId);
    if (it != bikes.end()) {
        return it->second;
    }
    return nullptr;
}


// Session 클래스 구현
User* Session::currentUser = nullptr;

bool Session::login(const string& id, const string& password) {
    currentUser = UserCollection::findUser(id, password);
    return (currentUser != nullptr);
}

void Session::logout() {
    currentUser = nullptr;
}

User* Session::getCurrentUser() {
    return currentUser;
}

bool Session::isAdmin() {
    return currentUser && currentUser->isAdmin();
}