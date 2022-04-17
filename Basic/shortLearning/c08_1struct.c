#include <stdio.h>

struct GameInfo
{
    char *name;
    int year;
    int price;
    char *company;

    struct GameInfo * friendGame; //연관 업체 게임
};


//typedef 를 이용하여 GameInfo를 GAME_INFO 라는 이름으로 구조체 명을 바꿔 쓰기.
//typedef struct GameInformation // typedef struct 까지만 써도 됨. ('GameInformation' 은 생략 가능)
typedef struct
{
    char *name;
    int year;
    int price;
    char *company;

    struct GameInfo * friendGame; 
} GAME_INFO; 
// { } 안에 있는 변수들을 GAME_INFO 라는 이름으로 쓰겠다는 의미.




int main(void)
{
    // 구조체 사용 (1)
    struct GameInfo gameInfo1;
    gameInfo1.name = "silGame";
    gameInfo1.year = 2017;
    gameInfo1.price = 50;
    gameInfo1.company = "silCompany";

    // 구조체 출력
    printf("======= 1st GameInfo instance =======\n");
    printf("Game name    : %s\n", gameInfo1.name);
    printf("Game year    : %d\n", gameInfo1.year);
    printf("Game price   : %d\n", gameInfo1.price);
    printf("Game company : %s\n", gameInfo1.company);

    

    // 구조체 사용 (2) 구조체를 배열처럼 초기화
    struct GameInfo gameInfo2 = {"golGame", 2019, 80, "golCom"};
    printf("\n\n======= 2nd GameInfo instance =======\n");
    printf("Game name    : %s\n", gameInfo2.name);
    printf("Game year    : %d\n", gameInfo2.year);
    printf("Game price   : %d\n", gameInfo2.price);
    printf("Game company : %s\n", gameInfo2.company);







    // 구조체 배열 - 한 회사가 두 개의 게임을 만드는 구조체 배열
    struct GameInfo gameArray[2] = {
        {"silGame", 2017, 50, "silCom"},
        {"golGame", 2019, 80, "golCom"}
    };
    







    // 구조체 포인터 - mission man 활용
    struct GameInfo * gamePtr; // *gamePtr 은 미션맨
    gamePtr = &gameInfo1;

    printf("\n\n==== game info of mission man using pointer ====\n");
    /*printf("Game name    : %s\n", (*gamePtr).name);
    printf("Game year    : %d\n", (*gamePtr).year);
    printf("Game price   : %d\n", (*gamePtr).price);
    printf("Game company : %s\n", (*gamePtr).company);*/

    // * 대신에 -> 사용하기.

    printf("Game name    : %s\n", gamePtr->name);
    printf("Game year    : %d\n", gamePtr->year);
    printf("Game price   : %d\n", gamePtr->price);
    printf("Game company : %s\n", gamePtr->company);







    // 연관 업체 게임 소개
    gameInfo1.friendGame = &gameInfo2;
    
    printf("\n\n==== Game info related (friend) game company using pointer ====\n");
    
    printf("Game name    : %s\n", gameInfo1.friendGame->name);
    printf("Game year    : %d\n", gameInfo1.friendGame->year);
    printf("Game price   : %d\n", gameInfo1.friendGame->price);
    printf("Game company : %s\n", gameInfo1.friendGame->company);







    // typedef : 자료형에 별명을 지정함.
    int i = 1; // 일반적인 정수형 변수 선언과 정의

    typedef int inting; // 이제 int 라는 자료형을 inting이라고 쓸 수 있다.
    inting intVariable = 3; // int intVariable = 3;

    typedef float floating;
    floating floatVariable = 2.32f; // float floatVariable = 2.32f;

    printf("\n\n===== changing datatype' name =====\n");
    // printf("intVar's data type is %s.\n", type(intVar));
    printf("intVariable : %d, floatVariable : %.2f\n\n", intVariable, floatVariable);




    //GameInfo 라는 구조체 이름을 'AboutGame' 로 바꾸기 - 구조체는 하나의 data type 이니까 typedef에 쓰일 수 있다.

    typedef struct GameInfo AboutGame;
    AboutGame game1;
    game1.name = "Korean game";
    game1.year = 2015;

    GAME_INFO game2;
    game1.name = "English game";
    game1.year = 2018;
    
    



    

    return 0;
}