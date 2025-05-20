#include "control.h"
#include <algorithm>

using namespace std;

// Login 클래스 구현
Login::Login() {}

void Login::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displayLoginResult(out_fp);
}

bool Login::loginUser(const string& id, const string& password) {
    return Session::login(id, password);
}

// Logout 클래스 구현
Logout::Logout() {}

void Logout::start(ifstream& in_fp, ofstream& out_fp) {
    string userId = logoutUser();
    ui.displayLogoutResult(out_fp, userId);
}

string Logout::logoutUser() {
    User* currentUser = Session::getCurrentUser();
    string id = currentUser ? currentUser->getUserId() : "";
    Session::logout();
    return id;
}

// AddMember 클래스 구현
AddMember::AddMember() {}

void AddMember::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displaySignupResult(out_fp);
}

bool AddMember::addNewMember(const string& id, const string& password, const string& phone) {
    Member* newMember = new Member(id, password, phone);
    return UserCollection::addUser(newMember);
}

// AddBike 클래스 구현
AddBike::AddBike() {}

void AddBike::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displayAddBikeResult(out_fp);
}

bool AddBike::addNewBike(const string& bikeId, const string& bikeName) {
    if (!Session::isAdmin()) {
        return false;  // 관리자 접근이 아닐 경우 fail
    }

    Bike* newBike = new Bike(bikeId, bikeName);
    return BikeCollection::addBike(newBike);
}

// RentBike 클래스 구현
RentBike::RentBike() {}

void RentBike::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displayRentBikeResult(out_fp);
}

string RentBike::rentalBike(const string& bikeId) {
    Bike* bike = BikeCollection::getBike(bikeId);
    User* user = Session::getCurrentUser();
    Member* member = dynamic_cast<Member*>(user);

    if (bike && member) {
        bike->setRentMember(member);
        member->addRentalBike(bike);
        return bike->getBikeName();
    }
    return "";
}

// RentBikeList 클래스 구현
RentBikeList::RentBikeList() {}

void RentBikeList::start(ifstream& in_fp, ofstream& out_fp) {
    ui.displayRentBikeList(out_fp, this);
}

vector<Bike*> RentBikeList::listRentBike() {
    User* user = Session::getCurrentUser();
    Member* member = dynamic_cast<Member*>(user);
    if (member) {
        vector<Bike*> bikeList = member->getRentalBikeList();

        // bikeId를 기준으로 정렬
        sort(bikeList.begin(), bikeList.end(),
            [](const Bike* a, const Bike* b) {
                return a->getBikeId() < b->getBikeId();
            });

        return bikeList;
    }
    return vector<Bike*>();
}