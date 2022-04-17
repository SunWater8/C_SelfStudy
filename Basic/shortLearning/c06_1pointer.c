#include <stdio.h>

int main(void)
{
    // 포인터

    // [Jake] : 101호 -> 메모리 공간의 주소
    // [Emil] : 201호
    // [Hope] : 301호

    // 각 문 앞에 '암호'가 걸려 있음
    int Jake = 1; // 암호
    int Emil = 2;
    int Hope = 3;

    printf("Jake's address : %d, password : %d\n", &Jake, Jake);
    printf("Emil's address : %d, password : %d\n", &Emil, Emil);
    printf("Hope's address : %d, password : %d\n", &Hope, Hope);


    printf("\n\n\n");



    // 미션맨으로 비유하기.
    printf("=== mission man ===\n\n");
    //미션맨의 첫 번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호를 확인하라.
    printf("mission (1)\n");
    int * missionMan; // 포인터 변수
    missionMan = &Jake;
    printf("The address that the missionMan visited : %d, password : %d\n", missionMan, *missionMan);

    missionMan = &Emil;
    printf("The address that the missionMan visited : %d, password : %d\n", missionMan, *missionMan);

    missionMan = &Hope;
    printf("The address that the missionMan visited : %d, password : %d\n", missionMan, *missionMan);

    printf("\n");


    //미션맨의 두 번째 미션 : 미션맨이 방문한 집의 암호에 3을 곱하라.
    printf("mission (2)\n");
    
    missionMan = &Jake;
    *missionMan = *missionMan * 3;
    printf("The address that the missionMan visited : %d, changed password : %d\n", missionMan, *missionMan);

    missionMan = &Emil;
    *missionMan = *missionMan * 3;
    printf("The address that the missionMan visited : %d, changed password : %d\n", missionMan, *missionMan);

    missionMan = &Hope;
    *missionMan = *missionMan * 3;
    printf("The address that the missionMan visited : %d, changed password : %d\n", missionMan, *missionMan);

    
    printf("\n");



    // 스파이 등장!
    // 스파이를 이용해 미션맨이 바꾼 암호에서 2를 빼라.
    int * spy = missionMan; // spy 변수 선언.
    printf("... spy is carrying out the mission.... \n");
    
    spy = &Jake;
    *spy = *spy - 2; //Jake = Jake - 2 
    printf("The address that the spy visited : %d, changed password : %d\n", spy, *spy);

    spy = &Emil;
    *spy = *spy - 2;
    printf("The address that the spy visited : %d, changed password : %d\n", spy, *spy);

    spy = &Hope;
    *spy = *spy - 2;
    printf("The address that the spy visited : %d, changed password : %d\n", spy, *spy);

    
    
    printf("\n\n");


    
    printf("... Jake, Emil and Hope were embarrassed, after noticing their changed password ... \n\n");

    printf("Jake's address : %d, password : %d\n", &Jake, Jake);
    printf("Emil's address : %d, password : %d\n", &Emil, Emil);
    printf("Hope's address : %d, password : %d\n", &Hope, Hope);
    
    
    
    printf("\n\n");



    // 미션맨과 스파이가 사는 주소
    printf("... Adress of mission man and spy ...\n\n");
    printf("mission man's address : %d\n", &missionMan);
    printf("spy's address : %d", &spy);
    
    

    return 0;
}