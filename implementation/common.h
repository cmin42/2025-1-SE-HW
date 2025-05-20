#ifndef COMMON_H
#define COMMON_H

// 상수 선언  
#define MAX_STRING 32  
#define INPUT_FILE_NAME "input.txt"  
#define OUTPUT_FILE_NAME "output.txt"

// 전방 선언
class User;            // 사용자 클래스
class Admin;           // 관리자 클래스 
class Member;          // 회원 클래스
class Bike;            // 자전거 클래스
class BikeCollection;  // 자전거 컬렉션 클래스
class UserCollection;  // 사용자 컬렉션 클래스
class Session;         // 세션 클래스

// 표준 라이브러리
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#endif