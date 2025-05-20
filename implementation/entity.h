#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"

/* Entity 클래스 정의 */

// 사용자 클래스
// 시스템에서 사용자를 나타내는 기본 클래스로, 관리자와 회원 클래스의 부모 클래스이다.
// 예시:
//    User* user = new Member("user01", "password", "010-1234-5678");
//    string id = user->getUserId();
class User {
protected:
	std::string userId;        // 사용자 아이디
	std::string userPassword;  // 사용자 비밀번호

public:
	// User 객체를 생성한다.
	// id: 사용자 아이디
	// password: 사용자 비밀번호
	User(std::string id, std::string password);

	// 가상 소멸자. 자식 클래스의 올바른 소멸을 보장한다.
	virtual ~User();

	// 사용자 아이디를 반환한다.
	// 반환값: 사용자 아이디
	std::string getUserId() const;

	// 사용자 비밀번호를 반환한다.
	// 반환값: 사용자 비밀번호
	std::string getPassword() const;

	// 관리자 여부를 확인한다.
	// 반환값: 관리자 여부(true: 관리자, false: 일반 사용자)
	virtual bool isAdmin() const;
};

// 관리자 클래스
// 시스템의 관리자를 나타내며, User 클래스를 상속받는다.
class Admin : public User {
public:
	// Admin 객체를 생성한다.
	// id: 관리자 아이디
	// password: 관리자 비밀번호
	Admin(std::string id, std::string password);

	// 관리자 여부를 확인한다. 항상 true를 반환한다.
	// 반환값: 항상 true(관리자)
	virtual bool isAdmin() const override;
};

// 회원 클래스
// 시스템의 일반 회원을 나타내며, User 클래스를 상속받는다.
class Member : public User {
private:
	std::string memberPhone;              // 회원 전화번호
	std::vector<Bike*> rentalBikeList;    // 회원이 대여한 자전거 목록

public:
	// Member 객체를 생성한다.
	// id: 회원 아이디
	// password: 회원 비밀번호
	// phone: 회원 전화번호
	Member(std::string id, std::string password, std::string phone);

	// 회원이 대여한 자전거 목록을 반환한다.
	// 반환값: 대여한 자전거 객체 포인터의 벡터
	const std::vector<Bike*>& getRentalBikeList() const;

	// 회원의 대여 목록에 자전거를 추가한다.
	// bike: 대여할 자전거 객체의 포인터
	void addRentalBike(Bike* bike);

	// 회원 전화번호를 반환한다.
	// 반환값: 회원 전화번호
	std::string getPhone() const;
};

// 자전거 클래스
// 시스템에서 자전거를 나타낸다.
class Bike {
private:
	std::string bikeId;      // 자전거 아이디
	std::string bikeName;    // 자전거 이름
	Member* rentMember;      // 자전거를 대여한 회원

public:
	// Bike 객체를 생성한다.
	// id: 자전거 아이디
	// name: 자전거 이름
	Bike(std::string id, std::string name);

	// 자전거 아이디를 반환한다.
	// 반환값: 자전거 아이디
	std::string getBikeId() const;

	// 자전거 이름을 반환한다.
	// 반환값: 자전거 이름
	std::string getBikeName() const;

	// 자전거를 대여한 회원을 반환한다.
	// 반환값: 자전거를 대여한 회원 객체의 포인터(대여되지 않은 경우 nullptr)
	Member* getRentMember() const;

	// 자전거를 대여한 회원을 설정한다.
	// member: 자전거를 대여한 회원 객체의 포인터
	void setRentMember(Member* member);
};

// 사용자 컬렉션 클래스
// 시스템에 등록된 모든 사용자를 관리한다.
class UserCollection {
private:
	static std::map<std::string, User*> users;  // 사용자 아이디를 키로 하는 사용자 맵

public:
	// UserCollection 객체를 생성한다.
	UserCollection();

	// UserCollection 객체를 소멸한다. 등록된 모든 사용자 객체를 해제한다.
	~UserCollection();

	// 아이디와 비밀번호로 사용자를 찾는다.
	// userId: 찾을 사용자의 아이디
	// password: 사용자 비밀번호
	// 반환값: 일치하는 사용자 객체 포인터(없는 경우 nullptr)
	static User* findUser(const std::string& userId, const std::string& password);

	// 새로운 사용자를 시스템에 추가한다.
	// user: 추가할 사용자 객체의 포인터
	// 반환값: 추가 성공 여부(true: 성공, false: 실패)
	static bool addUser(User* user);

	// 시스템을 초기화하고 기본 관리자 계정을 추가한다.
	static void initialize();
};

// 자전거 컬렉션 클래스
// 시스템에 등록된 모든 자전거를 관리한다.
class BikeCollection {
private:
	static std::map<std::string, Bike*> bikes;  // 자전거 아이디를 키로 하는 자전거 맵

public:
	// BikeCollection 객체를 생성한다.
	BikeCollection();

	// BikeCollection 객체를 소멸한다. 등록된 모든 자전거 객체를 해제한다.
	~BikeCollection();

	// 새로운 자전거를 시스템에 추가한다.
	// bike: 추가할 자전거 객체의 포인터
	// 반환값: 추가 성공 여부(true: 성공, false: 실패)
	static bool addBike(Bike* bike);

	// 아이디로 자전거를 찾는다.
	// bikeId: 찾을 자전거의 아이디
	// 반환값: 일치하는 자전거 객체 포인터(없는 경우 nullptr)
	static Bike* getBike(const std::string& bikeId);
};

// 세션 클래스
// 현재 로그인된 사용자 정보를 관리한다.
class Session {
private:
	static User* currentUser;  // 현재 로그인된 사용자

public:
	// 사용자 로그인을 시도한다.
	// id: 로그인할 사용자의 아이디
	// password: 사용자 비밀번호
	// 반환값: 로그인 성공 여부(true: 성공, false: 실패)
	static bool login(const std::string& id, const std::string& password);

	// 현재 로그인된 사용자를 로그아웃시킨다.
	static void logout();

	// 현재 로그인된 사용자를 반환한다.
	// 반환값: 현재 로그인된 사용자 객체의 포인터(로그인되지 않은 경우 nullptr)
	static User* getCurrentUser();

	// 현재 로그인된 사용자가 관리자인지 확인한다.
	// 반환값: 관리자 여부(true: 관리자, false: 일반 사용자 또는 로그인되지 않음)
	static bool isAdmin();
};

#endif