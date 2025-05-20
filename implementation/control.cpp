#include "control.h"
#include <algorithm>

using namespace std;

/* Control 클래스 함수 구현 */

// Login 클래스 구현
// Login 객체를 초기화한다.
Login::Login() {}

// 로그인 기능을 시작한다.
// UI를 통해 로그인 정보를 입력받고 결과를 출력한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
void Login::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displayLoginResult(out_fp);
}

// 사용자 로그인을 시도하고 결과를 반환한다.
// Session 클래스를 사용하여 실제 로그인 처리를 수행한다.
// id: 사용자 아이디
// password: 사용자 비밀번호
// 반환값: 로그인 성공 여부(true: 성공, false: 실패)
bool Login::loginUser(const string& id, const string& password) {
    return Session::login(id, password);
}

// Logout 클래스 구현
// Logout 객체를 초기화한다.
Logout::Logout() {}

// 로그아웃 기능을 시작한다.
// 로그아웃을 수행하고 결과를 UI를 통해 출력한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
void Logout::start(ifstream& in_fp, ofstream& out_fp) {
    string userId = logoutUser();
    ui.displayLogoutResult(out_fp, userId);
}

// 현재 로그인된 사용자를 로그아웃시키고 해당 사용자의 아이디를 반환한다.
// 반환값: 로그아웃된 사용자의 아이디
string Logout::logoutUser() {
    User* currentUser = Session::getCurrentUser();
    string id = currentUser ? currentUser->getUserId() : "";
    Session::logout();
    return id;
}

// AddMember 클래스 구현
// AddMember 객체를 초기화한다.
AddMember::AddMember() {}

// 회원가입 기능을 시작한다.
// UI를 통해 회원가입 정보를 입력받고 결과를 출력한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
void AddMember::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displaySignupResult(out_fp);
}

// 새로운 회원을 등록하고 결과를 반환한다.
// Member 객체를 생성하고 UserCollection에 추가한다.
// id: 회원 아이디
// password: 회원 비밀번호
// phone: 회원 전화번호
// 반환값: 회원 등록 성공 여부(true: 성공, false: 실패)
bool AddMember::addNewMember(const string& id, const string& password, const string& phone) {
    Member* newMember = new Member(id, password, phone);
    return UserCollection::addUser(newMember);
}

// AddBike 클래스 구현
// AddBike 객체를 초기화한다.
AddBike::AddBike() {}

// 자전거 등록 기능을 시작한다.
// UI를 통해 자전거 정보를 입력받고 결과를 출력한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
void AddBike::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displayAddBikeResult(out_fp);
}

// 새로운 자전거를 등록하고 결과를 반환한다.
// 관리자만 자전거를 등록할 수 있으며, Bike 객체를 생성하여 BikeCollection에 추가한다.
// bikeId: 자전거 아이디
// bikeName: 자전거 이름
// 반환값: 자전거 등록 성공 여부(true: 성공, false: 실패)
bool AddBike::addNewBike(const string& bikeId, const string& bikeName) {
    if (!Session::isAdmin()) {
        return false;  // 관리자 접근이 아닐 경우 fail
    }

    Bike* newBike = new Bike(bikeId, bikeName);
    return BikeCollection::addBike(newBike);
}

// RentBike 클래스 구현
// RentBike 객체를 초기화한다.
RentBike::RentBike() {}

// 자전거 대여 기능을 시작한다.
// UI를 통해 대여할 자전거 아이디를 입력받고 결과를 출력한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
void RentBike::start(ifstream& in_fp, ofstream& out_fp) {
    ui.inputData(in_fp, out_fp, this);
    ui.displayRentBikeResult(out_fp);
}

// 지정된 자전거를 현재 로그인한 회원에게 대여하고 자전거 이름을 반환한다.
// bikeId: 대여할 자전거 아이디
// 반환값: 대여한 자전거 이름(실패 시 빈 문자열)
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
// RentBikeList 객체를 초기화한다.
RentBikeList::RentBikeList() {}

// 자전거 대여 리스트 조회 기능을 시작한다.
// UI를 통해 현재 회원이 대여한 자전거 목록을 출력한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
void RentBikeList::start(ifstream& in_fp, ofstream& out_fp) {
    ui.displayRentBikeList(out_fp, this);
}

// 현재 로그인한 회원이 대여한 자전거 목록을 반환한다.
// 자전거 목록을 자전거 아이디 기준으로 정렬하여 반환한다.
// 반환값: 대여한 자전거 객체 포인터의 벡터
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