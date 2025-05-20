#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"

/* Entity 클래스 정의 */
class User {
protected:
	std::string userId;
	std::string userPassword;

public:
	User(std::string id, std::string password);
	virtual ~User();

	std::string getUserId() const;
	std::string getPassword() const;
	virtual bool isAdmin() const;
};

class Admin : public User {
public:
	Admin(std::string id, std::string password);
	virtual bool isAdmin() const override;
};

class Member : public User {
private:
	std::string memberPhone;
	std::vector<Bike*> rentalBikeList;

public:
	Member(std::string id, std::string password, std::string phone);

	const std::vector<Bike*>& getRentalBikeList() const;
	void addRentalBike(Bike* bike);
	std::string getPhone() const;
};

class Bike {
private:
	std::string bikeId;
	std::string bikeName;
	Member* rentMember;

public:
	Bike(std::string id, std::string name);

	std::string getBikeId() const;
	std::string getBikeName() const;
	Member* getRentMember() const;
	void setRentMember(Member* member);
};

class UserCollection {
private:
	static std::map<std::string, User*> users;

public:
	UserCollection();
	~UserCollection();

	static User* findUser(const std::string& userId, const std::string& password);
	static bool addUser(User* user);
	static void initialize();
};

class BikeCollection {
private:
	static std::map<std::string, Bike*> bikes;

public:
	BikeCollection();
	~BikeCollection();

	static bool addBike(Bike* bike);
	static Bike* getBike(const std::string& bikeId);
};

class Session {
private:
	static User* currentUser;

public:
	static bool login(const std::string& id, const std::string& password);
	static void logout();
	static User* getCurrentUser();
	static bool isAdmin();
};

#endif