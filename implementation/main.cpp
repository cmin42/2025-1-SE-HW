#include "common.h"
#include "entity.h"
#include "boundary.h"
#include "control.h"
#include <Windows.h>

using namespace std;

// 함수 선언
void doTask(ifstream& in_fp, ofstream& out_fp);

int main()
{
    // 파일 입출력을 위한 초기화
    ifstream in_fp(INPUT_FILE_NAME);
    ofstream out_fp(OUTPUT_FILE_NAME);

    // 초기 사용자 설정
    UserCollection::initialize();

    doTask(in_fp, out_fp);

    out_fp.close();
    in_fp.close();

    return 0;
}

void doTask(ifstream& in_fp, ofstream& out_fp)
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    // Control 클래스 인스턴스 생성
    AddMember addMemberControl;
    Login loginControl;
    Logout logoutControl;
    AddBike addBikeControl;
    RentBike rentBikeControl;
    RentBikeList rentBikeListControl;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        in_fp >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // 1.1. 회원가입
            {
                addMemberControl.start(in_fp, out_fp);
                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:   // 2.1. 로그인
            {
                loginControl.start(in_fp, out_fp);
                break;
            }
            case 2:   // 2.2. 로그아웃
            {
                logoutControl.start(in_fp, out_fp);
                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1:   // 3.1. 자전거 등록
            {
                addBikeControl.start(in_fp, out_fp);
                break;
            }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2)
            {
            case 1:   // 4.1. 자전거 대여
            {
                rentBikeControl.start(in_fp, out_fp);
                break;
            }
            }
            break;
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1:   // 5.1. 자전거 대여 리스트
            {
                rentBikeListControl.start(in_fp, out_fp);
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // 6.1. 종료
            {
                is_program_exit = 1;
                out_fp << "6.1. 종료" << endl;
                break;
            }
            }
            break;
        }
        }
    }
}