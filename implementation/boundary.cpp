#include "boundary.h"
#include "control.h"

using namespace std;

// AddMemberUI 구현
// AddMemberUI 객체를 초기화한다.
AddMemberUI::AddMemberUI() : success(false) {}

// 회원가입 정보를 입력받고 컨트롤 객체를 통해 처리한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
// control: 회원가입 처리를 위한 컨트롤 객체
void AddMemberUI::inputData(ifstream& in_fp, ofstream& out_fp, AddMember* control) {
    out_fp << "1.1. 회원가입" << endl;

    in_fp >> id >> password >> phone;
    success = control->addNewMember(id, password, phone);
}

// 회원가입 결과를 출력 파일에 기록한다.
// 성공 시 사용자 정보를, 실패 시 실패 메시지를 출력한다.
// out_fp: 출력 파일 스트림
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
// LoginUI 객체를 초기화한다.
LoginUI::LoginUI() : success(false) {}

// 로그인 정보를 입력받고 컨트롤 객체를 통해 처리한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
// control: 로그인 처리를 위한 컨트롤 객체
void LoginUI::inputData(ifstream& in_fp, ofstream& out_fp, Login* control) {
    out_fp << "2.1. 로그인" << endl;

    in_fp >> id >> password;
    success = control->loginUser(id, password);
}

// 로그인 결과를 출력 파일에 기록한다.
// 성공 시 로그인 정보를, 실패 시 실패 메시지를 출력한다.
// out_fp: 출력 파일 스트림
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
// LogoutUI 객체를 초기화한다.
LogoutUI::LogoutUI() {}

// 로그아웃 결과를 출력 파일에 기록한다.
// out_fp: 출력 파일 스트림
// userId: 로그아웃한 사용자의 아이디
void LogoutUI::displayLogoutResult(ofstream& out_fp, const string& userId) {
    out_fp << "2.2. 로그아웃" << endl;
    out_fp << "> " << userId << endl;
    out_fp << endl;
}

// AddBikeUI 구현
// AddBikeUI 객체를 초기화한다.
AddBikeUI::AddBikeUI() : success(false) {}

// 자전거 정보를 입력받고 컨트롤 객체를 통해 처리한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
// control: 자전거 등록 처리를 위한 컨트롤 객체
void AddBikeUI::inputData(ifstream& in_fp, ofstream& out_fp, AddBike* control) {
    out_fp << "3.1. 자전거 등록" << endl;

    in_fp >> bikeId >> bikeName;
    success = control->addNewBike(bikeId, bikeName);
}

// 자전거 등록 결과를 출력 파일에 기록한다.
// 성공 시 자전거 정보를, 실패 시 실패 메시지를 출력한다.
// out_fp: 출력 파일 스트림
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
// RentBikeUI 객체를 초기화한다.
RentBikeUI::RentBikeUI() : success(false) {}

// 대여할 자전거 아이디를 입력받고 컨트롤 객체를 통해 처리한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
// control: 자전거 대여 처리를 위한 컨트롤 객체
void RentBikeUI::inputData(ifstream& in_fp, ofstream& out_fp, RentBike* control) {
    out_fp << "4.1. 자전거 대여" << endl;

    in_fp >> bikeId;
    bikeName = control->rentalBike(bikeId);
    success = !bikeName.empty();
}

// 자전거 대여 결과를 출력 파일에 기록한다.
// 성공 시 자전거 정보를, 실패 시 실패 메시지를 출력한다.
// out_fp: 출력 파일 스트림
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
// RentBikeListUI 객체를 초기화한다.
RentBikeListUI::RentBikeListUI() {}

// 현재 회원이 대여한 자전거 목록을 조회하여 출력 파일에 기록한다.
// 대여한 자전거가 없을 경우 해당 메시지를 출력한다.
// out_fp: 출력 파일 스트림
// control: 자전거 대여 리스트를 조회하기 위한 컨트롤 객체
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