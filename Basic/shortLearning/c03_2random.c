#include <time.h>
#include <stdlib.h>
#include <stdio.h>
 
// random 함수 쓸 수 있는 lib 들 -> <time.h>  <stdlib.h>  <stdio.h>

int main(void)
{
    // srand(time(NULL)); // 난수 초기화 - 난수 초기화를 하여야 다시 실행할 때 다른 난수가 출력된다.
    // int num = rand() % 3; // 0~2 중에 하나가 난수로 채택됨. 
                             // int num = rand() % 3+1; // 1~3 중에 하나가 난수로 채택됨. 
    // printf("%d\n", num);


    //난수 초기화 이전
    printf("before initialization\n");
    for (int i=0;i<10;i++){
        printf("%d", rand()%10);
    }

    printf("\n\n");

    //난수 초기화 이후
    printf("after initialization\n");
    srand(time(NULL));
    for (int i =0; i<10; i++){
        printf("%d", rand()%10);
    }

    printf("\n\n\n");

    //switch를 이용한 random 함수 활용

    //가위 0 , 바위 1, 보 2
    srand(time(NULL));
    int s = rand() % 3; 
    printf("number : %d\n", s);

    switch (s)
    {
        case 0 :
            printf("cissors\n");
            break;
        case 1 :
            printf("rock\n");
            break;
        case 2 :
            printf("paper\n");
            break;
        default :
            printf("i don't know.\n");
    }

    printf("\n\n\n");

    // break 문이 올 때까지 샐행되는 특성을 살린 switch 문
    int age = 8;
    switch (age)
    {
        case 8: 
        case 9:
        case 10:
        case 11:
        case 12:
        case 13: printf("elementary school student"); break;
        case 14:
        case 15:
        case 16: printf("middle school student"); break;
        case 17:
        case 18:
        case 19: printf("high school student"); break;
        case 20: printf("college student"); break;
    }


    printf("\n\n\n");


    




    return 0;
}