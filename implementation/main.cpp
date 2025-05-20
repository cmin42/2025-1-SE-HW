#include "common.h"
#include "entity.h"
#include "boundary.h"
#include "control.h"
#include <Windows.h>

using namespace std;

// 함수 선언
void doTask(ifstream& in_fp, ofstream& out_fp);

// 메인 함수
// 파일 입출력을 초기화하고 기본 사용자를 설정한 후 작업을 수행한다.
// 반환값: 프로그램 종료 코드(0: 정상 종료)
int main()
{
    // 파일 입출력을 위한 초기화
    // INPUT_FILE_NAME과 OUTPUT_FILE_NAME은 common.h에 정의되어 있다.
    ifstream in_fp(INPUT_FILE_NAME);
    ofstream out_fp(OUTPUT_FILE_NAME);

    // 기본 관리자 계정 생성
    UserCollection::initialize();

    // 메뉴 처리 및 작업 수행
    doTask(in_fp, out_fp);

    // 파일 스트림 닫기
    out_fp.close();
    in_fp.close();

    return 0;
}

// 메뉴에 따라 적절한 기능을 수행하는 함수
// 입력 파일에서 메뉴 레벨을 읽고, 해당 메뉴에 맞는 컨트롤러를 실행한다.
// in_fp: 입력 파일 스트림
// out_fp: 출력 파일 스트림
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

    // 프로그램 종료 전까지 메뉴 처리를 반복한다.
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