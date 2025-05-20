#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "common.h"

// 전방 선언
class Login;
class Logout;
class AddMember;
class AddBike;
class RentBike;
class RentBikeList;

/* Boundary 클래스 정의 */

// 회원가입 UI 클래스
// 사용자로부터 회원가입 정보를 입력받고 결과를 출력한다.
// 예시:
//    AddMemberUI ui;
//    ui.inputData(in_fp, out_fp, control);
//    ui.displaySignupResult(out_fp);
class AddMemberUI {
private:
    std::string id;           // 사용자 아이디
    std::string password;     // 사용자 비밀번호
    std::string phone;        // 사용자 전화번호
    bool success;             // 회원가입 성공 여부

public:
    // AddMemberUI 객체를 생성한다.
    AddMemberUI();

    // 파일로부터 회원가입 정보를 입력받고, AddMember 컨트롤을 통해 처리한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    // control: 회원가입 처리를 위한 컨트롤 객체
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, AddMember* control);

    // 회원가입 결과를 출력 파일에 기록한다.
    // out_fp: 출력 파일 스트림
    void displaySignupResult(std::ofstream& out_fp);
};

// 로그인 UI 클래스
// 사용자로부터 로그인 정보를 입력받고 결과를 출력한다.
class LoginUI {
private:
    std::string id;           // 사용자 아이디
    std::string password;     // 사용자 비밀번호
    bool success;             // 로그인 성공 여부

public:
    // LoginUI 객체를 생성한다.
    LoginUI();

    // 파일로부터 로그인 정보를 입력받고, Login 컨트롤을 통해 처리한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    // control: 로그인 처리를 위한 컨트롤 객체
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, Login* control);

    // 로그인 결과를 출력 파일에 기록한다.
    // out_fp: 출력 파일 스트림
    void displayLoginResult(std::ofstream& out_fp);
};

// 로그아웃 UI 클래스
// 로그아웃 결과를 출력한다.
class LogoutUI {
public:
    // LogoutUI 객체를 생성한다.
    LogoutUI();

    // 로그아웃 결과를 출력 파일에 기록한다.
    // out_fp: 출력 파일 스트림
    // userId: 로그아웃한 사용자의 아이디
    void displayLogoutResult(std::ofstream& out_fp, const std::string& userId);
};

// 자전거 등록 UI 클래스
// 관리자로부터 자전거 정보를 입력받고 결과를 출력한다.
class AddBikeUI {
private:
    std::string bikeId;       // 자전거 아이디
    std::string bikeName;     // 자전거 이름
    bool success;             // 등록 성공 여부

public:
    // AddBikeUI 객체를 생성한다.
    AddBikeUI();

    // 파일로부터 자전거 정보를 입력받고, AddBike 컨트롤을 통해 처리한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    // control: 자전거 등록 처리를 위한 컨트롤 객체
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, AddBike* control);

    // 자전거 등록 결과를 출력 파일에 기록한다.
    // out_fp: 출력 파일 스트림
    void displayAddBikeResult(std::ofstream& out_fp);
};

// 자전거 대여 UI 클래스
// 회원으로부터 대여할 자전거 아이디를 입력받고 결과를 출력한다.
class RentBikeUI {
private:
    std::string bikeId;       // 자전거 아이디
    std::string bikeName;     // 자전거 이름
    bool success;             // 대여 성공 여부

public:
    // RentBikeUI 객체를 생성한다.
    RentBikeUI();

    // 파일로부터 대여할 자전거 아이디를 입력받고, RentBike 컨트롤을 통해 처리한다.
    // in_fp: 입력 파일 스트림
    // out_fp: 출력 파일 스트림
    // control: 자전거 대여 처리를 위한 컨트롤 객체
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, RentBike* control);

    // 자전거 대여 결과를 출력 파일에 기록한다.
    // out_fp: 출력 파일 스트림
    void displayRentBikeResult(std::ofstream& out_fp);
};

// 자전거 대여 리스트 UI 클래스
// 현재 회원이 대여한 자전거 목록을 출력한다.
class RentBikeListUI {
public:
    // RentBikeListUI 객체를 생성한다.
    RentBikeListUI();

    // 현재 회원이 대여한 자전거 목록을 출력 파일에 기록한다.
    // out_fp: 출력 파일 스트림
    // control: 자전거 대여 리스트를 조회하기 위한 컨트롤 객체
    void displayRentBikeList(std::ofstream& out_fp, RentBikeList* control);
};

#endif