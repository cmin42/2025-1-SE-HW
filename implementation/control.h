#ifndef CONTROL_H
#define CONTROL_H

#include "common.h"
#include "entity.h"
#include "boundary.h"

// Control 클래스 정의
class Login {
private:
    LoginUI ui;
public:
    Login();
    void start(std::ifstream& in_fp, std::ofstream& out_fp);
    bool loginUser(const std::string& id, const std::string& password);
};

class Logout {
private:
    LogoutUI ui;
public:
    Logout();
    void start(std::ifstream& in_fp, std::ofstream& out_fp);
    std::string logoutUser();
};

class AddMember {
private:
    AddMemberUI ui;
public:
    AddMember();
    void start(std::ifstream& in_fp, std::ofstream& out_fp);
    bool addNewMember(const std::string& id, const std::string& password, const std::string& phone);
};

class AddBike {
private:
    AddBikeUI ui;
public:
    AddBike();
    void start(std::ifstream& in_fp, std::ofstream& out_fp);
    bool addNewBike(const std::string& bikeId, const std::string& bikeName);
};

class RentBike {
private:
    RentBikeUI ui;
public:
    RentBike();
    void start(std::ifstream& in_fp, std::ofstream& out_fp);
    std::string rentalBike(const std::string& bikeId);
};

class RentBikeList {
private:
    RentBikeListUI ui;
public:
    RentBikeList();
    void start(std::ifstream& in_fp, std::ofstream& out_fp);
    std::vector<Bike*> listRentBike();
};

#endif // CONTROL_H