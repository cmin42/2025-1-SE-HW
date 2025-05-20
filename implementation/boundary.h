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

// Boundary 클래스 정의
class AddMemberUI {
private:
    std::string id;
    std::string password;
    std::string phone;
    bool success;

public:
    AddMemberUI();
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, AddMember* control);
    void displaySignupResult(std::ofstream& out_fp);
};

class LoginUI {
private:
    std::string id;
    std::string password;
    bool success;

public:
    LoginUI();
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, Login* control);
    void displayLoginResult(std::ofstream& out_fp);
};

class LogoutUI {
public:
    LogoutUI();
    void displayLogoutResult(std::ofstream& out_fp, const std::string& userId);
};

class AddBikeUI {
private:
    std::string bikeId;
    std::string bikeName;
    bool success;

public:
    AddBikeUI();
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, AddBike* control);
    void displayAddBikeResult(std::ofstream& out_fp);
};

class RentBikeUI {
private:
    std::string bikeId;
    std::string bikeName;
    bool success;

public:
    RentBikeUI();
    void inputData(std::ifstream& in_fp, std::ofstream& out_fp, RentBike* control);
    void displayRentBikeResult(std::ofstream& out_fp);
};

class RentBikeListUI {
public:
    RentBikeListUI();
    void displayRentBikeList(std::ofstream& out_fp, RentBikeList* control);
};

#endif