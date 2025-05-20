#ifndef CONTROL_H
#define CONTROL_H

#include "common.h"
#include "entity.h"
#include "boundary.h"

/* Control 클래스 정의 */

// 로그인 컨트롤 클래스
// 사용자 로그인을 처리한다.
// 예시:
//    Login control;
//    control.start(in_fp, out_fp);
//    control.loginUser("testId", "testPw");
class Login {
private:
    LoginUI ui;  // 로그인 UI 객체

public:
    // Login 객체를 생성한다.
    Login();

    // 로그인 기능을 시작한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    void start(std::ifstream& in_fp, std::ofstream& out_fp);

    // 사용자 로그인을 시도하고 결과를 반환한다.
    // id: 사용자 아이디
    // password: 사용자 비밀번호
    // 반환값: 로그인 성공 여부(true: 성공, false: 실패)
    bool loginUser(const std::string& id, const std::string& password);
};

// 로그아웃 컨트롤 클래스
// 사용자 로그아웃을 처리한다.
class Logout {
private:
    LogoutUI ui;  // 로그아웃 UI 객체

public:
    // Logout 객체를 생성한다.
    Logout();

    // 로그아웃 기능을 시작한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    void start(std::ifstream& in_fp, std::ofstream& out_fp);

    // 현재 로그인된 사용자를 로그아웃시키고 해당 사용자의 아이디를 반환한다.
    // 반환값: 로그아웃된 사용자의 아이디
    std::string logoutUser();
};

// 회원가입 컨트롤 클래스
// 새로운 회원 등록을 처리한다.
class AddMember {
private:
    AddMemberUI ui;  // 회원가입 UI 객체

public:
    // AddMember 객체를 생성한다.
    AddMember();

    // 회원가입 기능을 시작한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    void start(std::ifstream& in_fp, std::ofstream& out_fp);

    // 새로운 회원을 등록하고 결과를 반환한다.
    // id: 회원 아이디
    // password: 회원 비밀번호
    // phone: 회원 전화번호
    // 반환값: 회원 등록 성공 여부(true: 성공, false: 실패)
    bool addNewMember(const std::string& id, const std::string& password, const std::string& phone);
};

// 자전거 등록 컨트롤 클래스
// 새로운 자전거 등록을 처리한다.
class AddBike {
private:
    AddBikeUI ui;  // 자전거 등록 UI 객체

public:
    // AddBike 객체를 생성한다.
    AddBike();

    // 자전거 등록 기능을 시작한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    void start(std::ifstream& in_fp, std::ofstream& out_fp);

    // 새로운 자전거를 등록하고 결과를 반환한다.
    // bikeId: 자전거 아이디
    // bikeName: 자전거 이름
    // 반환값: 자전거 등록 성공 여부(true: 성공, false: 실패)
    bool addNewBike(const std::string& bikeId, const std::string& bikeName);
};

// 자전거 대여 컨트롤 클래스
// 자전거 대여 기능을 처리한다.
class RentBike {
private:
    RentBikeUI ui;  // 자전거 대여 UI 객체

public:
    // RentBike 객체를 생성한다.
    RentBike();

    // 자전거 대여 기능을 시작한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    void start(std::ifstream& in_fp, std::ofstream& out_fp);

    // 지정된 자전거를 현재 로그인한 회원에게 대여하고 자전거 이름을 반환한다.
    // bikeId: 대여할 자전거 아이디
    // 반환값: 대여한 자전거 이름(실패 시 빈 문자열)
    std::string rentalBike(const std::string& bikeId);
};

// 자전거 대여 리스트 컨트롤 클래스
// 현재 회원이 대여한 자전거 목록을 조회한다.
class RentBikeList {
private:
    RentBikeListUI ui;  // 자전거 대여 리스트 UI 객체

public:
    // RentBikeList 객체를 생성한다.
    RentBikeList();

    // 자전거 대여 리스트 조회 기능을 시작한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    void start(std::ifstream& in_fp, std::ofstream& out_fp);

    // 현재 로그인한 회원이 대여한 자전거 목록을 반환한다.
    // 반환값: 대여한 자전거 객체 포인터의 벡터
    std::vector<Bike*> listRentBike();
};

#endif