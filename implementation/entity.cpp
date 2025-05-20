#include "entity.h"

using namespace std;

/* Entity 클래스 함수 구현 */

// User 클래스 구현
// User 객체를 생성한다.
// id: 사용자 아이디
// password: 사용자 비밀번호
User::User(string id, string password) : userId(id), userPassword(password) {}

// 가상 소멸자
User::~User() {}

// 사용자 아이디를 반환한다.
// 반환값: 사용자 아이디
string User::getUserId() const { return userId; }

// 사용자 비밀번호를 반환한다.
// 반환값: 사용자 비밀번호
string User::getPassword() const { return userPassword; }

// 관리자 여부를 확인한다.
// 반환값: 관리자 여부(false: 일반 사용자)
bool User::isAdmin() const { return false; }


// Admin 클래스 구현
// Admin 객체를 생성한다.
// id: 관리자 아이디
// password: 관리자 비밀번호
Admin::Admin(string id, string password) : User(id, password) {}

// 관리자 여부를 확인한다. Admin은 항상 true를 반환한다.
// 반환값: 항상 true(관리자)
bool Admin::isAdmin() const { return true; }


// Bike 클래스 구현
// Bike 객체를 생성한다. 생성 시 대여자는 없다(nullptr).
// id: 자전거 아이디
// name: 자전거 이름
Bike::Bike(string id, string name) : bikeId(id), bikeName(name), rentMember(nullptr) {}

// 자전거 아이디를 반환한다.
// 반환값: 자전거 아이디
string Bike::getBikeId() const { return bikeId; }

// 자전거 이름을 반환한다.
// 반환값: 자전거 이름
string Bike::getBikeName() const { return bikeName; }

// 자전거를 대여한 회원을 반환한다.
// 반환값: 자전거를 대여한 회원 객체의 포인터(대여되지 않은 경우 nullptr)
Member* Bike::getRentMember() const { return rentMember; }

// 자전거를 대여한 회원을 설정한다.
// member: 자전거를 대여한 회원 객체의 포인터
void Bike::setRentMember(Member* member) {
    rentMember = member;
}


// Member 클래스 구현
// Member 객체를 생성한다.
// id: 회원 아이디
// password: 회원 비밀번호
// phone: 회원 전화번호
Member::Member(string id, string password, string phone)
    : User(id, password), memberPhone(phone) {
}

// 회원이 대여한 자전거 목록을 반환한다.
// 반환값: 대여한 자전거 객체 포인터의 벡터
const vector<Bike*>& Member::getRentalBikeList() const {
    return rentalBikeList;
}

// 회원의 대여 목록에 자전거를 추가한다.
// bike: 대여할 자전거 객체의 포인터
void Member::addRentalBike(Bike* bike) {
    if (bike) {
        rentalBikeList.push_back(bike);
    }
}

// 회원 전화번호를 반환한다.
// 반환값: 회원 전화번호
string Member::getPhone() const {
    return memberPhone;
}


// UserCollection 클래스 구현
// 모든 사용자를 저장하는 맵을 정적 멤버 변수로 선언한다.
map<string, User*> UserCollection::users;

// UserCollection 객체를 생성한다.
UserCollection::UserCollection() {}

// UserCollection 객체를 소멸한다. 등록된 모든 사용자 객체를 해제한다.
UserCollection::~UserCollection() {
    for (auto& pair : users) {
        delete pair.second;
    }
    users.clear();
}

// 아이디와 비밀번호로 사용자를 찾는다.
// userId: 찾을 사용자의 아이디
// password: 사용자 비밀번호
// 반환값: 일치하는 사용자 객체 포인터(없는 경우 nullptr)
User* UserCollection::findUser(const string& userId, const string& password) {
    auto it = users.find(userId);
    if (it != users.end() && it->second->getPassword() == password) {
        return it->second;
    }
    return nullptr;
}

// 새로운 사용자를 시스템에 추가한다.
// 이미 존재하는 아이디인 경우 추가하지 않는다.
// user: 추가할 사용자 객체의 포인터
// 반환값: 추가 성공 여부(true: 성공, false: 실패)
bool UserCollection::addUser(User* user) {
    if (!user) return false;

    string userId = user->getUserId();
    if (users.find(userId) != users.end()) {
        return false; // 이미 존재하는 유저
    }

    users[userId] = user;
    return true;
}

// 시스템을 초기화하고 기본 관리자 계정을 추가한다.
// 관리자 계정이 이미 존재하지 않는 경우에만 추가한다.
void UserCollection::initialize() {
    // 기본 Admin 계정 추가
    if (users.find("admin") == users.end()) {
        User* user = new Admin("admin", "admin");
        users["admin"] = user;
    }
}


// BikeCollection 클래스 구현
// 모든 자전거를 저장하는 맵을 정적 멤버 변수로 선언한다.
map<string, Bike*> BikeCollection::bikes;

// BikeCollection 객체를 생성한다.
BikeCollection::BikeCollection() {}

// BikeCollection 객체를 소멸한다. 등록된 모든 자전거 객체를 해제한다.
BikeCollection::~BikeCollection() {
    for (auto& pair : bikes) {
        delete pair.second;
    }
    bikes.clear();
}

// 새로운 자전거를 시스템에 추가한다.
// 이미 존재하는 자전거 아이디인 경우 추가하지 않는다.
// bike: 추가할 자전거 객체의 포인터
// 반환값: 추가 성공 여부(true: 성공, false: 실패)
bool BikeCollection::addBike(Bike* bike) {
    if (!bike) return false;

    string bikeId = bike->getBikeId();
    if (bikes.find(bikeId) != bikes.end()) {
        return false; // 이미 존재하는 자전거일 경우 fail
    }

    bikes[bikeId] = bike;
    return true;
}

// 아이디로 자전거를 찾는다.
// bikeId: 찾을 자전거의 아이디
// 반환값: 일치하는 자전거 객체 포인터(없는 경우 nullptr)
Bike* BikeCollection::getBike(const string& bikeId) {
    auto it = bikes.find(bikeId);
    if (it != bikes.end()) {
        return it->second;
    }
    return nullptr;
}


// Session 클래스 구현
// 현재 로그인된 사용자를 정적 멤버 변수로 선언한다.
User* Session::currentUser = nullptr;

// 사용자 로그인을 시도한다.
// id와 password로 사용자를 찾아 로그인 처리한다.
// id: 로그인할 사용자의 아이디
// password: 사용자 비밀번호
// 반환값: 로그인 성공 여부(true: 성공, false: 실패)
bool Session::login(const string& id, const string& password) {
    currentUser = UserCollection::findUser(id, password);
    return (currentUser != nullptr);
}

// 현재 로그인된 사용자를 로그아웃시킨다.
// 현재 사용자를 nullptr로 설정한다.
void Session::logout() {
    currentUser = nullptr;
}

// 현재 로그인된 사용자를 반환한다.
// 반환값: 현재 로그인된 사용자 객체의 포인터(로그인되지 않은 경우 nullptr)
User* Session::getCurrentUser() {
    return currentUser;
}

// 현재 로그인된 사용자가 관리자인지 확인한다.
// 반환값: 관리자 여부(true: 관리자, false: 일반 사용자 또는 로그인되지 않음)
bool Session::isAdmin() {
    return currentUser && currentUser->isAdmin();
}