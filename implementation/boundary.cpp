#include "boundary.h"
#include "control.h"

using namespace std;

// AddMemberUI 구현
AddMemberUI::AddMemberUI() : success(false) {}

void AddMemberUI::inputData(ifstream& in_fp, ofstream& out_fp, AddMember* control) {
    out_fp << "1.1. 회원가입" << endl;

    in_fp >> id >> password >> phone;
    success = control->addNewMember(id, password, phone);
}

void AddMemberUI::displaySignupResult(ofstream& out_fp) {
    if (success) {
        out_fp << "> " << id << " " << password << " " << phone << endl;
    }
    else {
        out_fp << "> 회원가입 실패: 이미 존재하는 아이디입니다." << endl;
    }
    out_fp << endl;
}

// LoginUI 구현
LoginUI::LoginUI() : success(false) {}

void LoginUI::inputData(ifstream& in_fp, ofstream& out_fp, Login* control) {
    out_fp << "2.1. 로그인" << endl;

    in_fp >> id >> password;
    success = control->loginUser(id, password);
}

void LoginUI::displayLoginResult(ofstream& out_fp) {
    if (success) {
        out_fp << "> " << id << " " << password << endl;
    }
    else {
        out_fp << "> 로그인 실패: 아이디 또는 비밀번호가 일치하지 않습니다." << endl;
    }
    out_fp << endl;
}

// LogoutUI 구현
LogoutUI::LogoutUI() {}

void LogoutUI::displayLogoutResult(ofstream& out_fp, const string& userId) {
    out_fp << "2.2. 로그아웃" << endl;
    out_fp << "> " << userId << endl;
    out_fp << endl;
}

// AddBikeUI 구현
AddBikeUI::AddBikeUI() : success(false) {}

void AddBikeUI::inputData(ifstream& in_fp, ofstream& out_fp, AddBike* control) {
    out_fp << "3.1. 자전거 등록" << endl;

    in_fp >> bikeId >> bikeName;
    success = control->addNewBike(bikeId, bikeName);
}

void AddBikeUI::displayAddBikeResult(ofstream& out_fp) {
    if (success) {
        out_fp << "> " << bikeId << " " << bikeName << endl;
    }
    else {
        out_fp << "> 자전거 등록에 실패했습니다." << endl;
    }
    out_fp << endl;
}

// RentBikeUI 구현
RentBikeUI::RentBikeUI() : success(false) {}

void RentBikeUI::inputData(ifstream& in_fp, ofstream& out_fp, RentBike* control) {
    out_fp << "4.1. 자전거 대여" << endl;

    in_fp >> bikeId;
    bikeName = control->rentalBike(bikeId);
    success = !bikeName.empty();
}

void RentBikeUI::displayRentBikeResult(ofstream& out_fp) {
    if (success) {
        out_fp << "> " << bikeId << " " << bikeName << endl;
    }
    else {
        out_fp << "> 자전거 대여에 실패했습니다." << endl;
    }
    out_fp << endl;
}

// RentBikeListUI 구현
RentBikeListUI::RentBikeListUI() {}

void RentBikeListUI::displayRentBikeList(ofstream& out_fp, RentBikeList* control) {
    out_fp << "5.1. 자전거 대여 리스트" << endl;

    vector<Bike*> bikeList = control->listRentBike();

    if (bikeList.empty()) {
        out_fp << "> 대여한 자전거가 없습니다." << endl << endl;
        return;
    }

    for (Bike* bike : bikeList) {
        out_fp << "> " << bike->getBikeId() << " " << bike->getBikeName() << endl;
    }
    out_fp << endl;
}