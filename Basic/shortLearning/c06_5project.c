#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 물고기 어항에 물주기 게임.
물고기 6마리가 사막에 있는 어항에 있는데, 사막이 너무 더워 물이 빨리 건조가 되기 때문에
물을 부지런히 어항에 줘서 물고기들을 살려줘야 해요.

*/
void initDate();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int level;
int arrayFish[6];
int *cursor;

int main(void)
{
    long startTime = 0;        //게임 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간
    long prevElapsedTime = 0;  //직전 경과 시간 (최근에 물을 준 시간 간격)

    int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력.
    initDate();

    cursor = arrayFish; // cursor[0] . . . cursor[1] . . .

    startTime = clock(); // 현재 시간을 millisecond (1/1000초) 단위로 반환.

    // enter 치면 게임 시작하기.
    printf("game start >> Enter!\n");
    getchar(); // 임시로 사용자 입력 대기
    while (1)
    {
        printFishes();
        // getchar(); // 임시로 사용자 입력 대기
        printf("\n=============== level %d ===============\n", level + 1);
        printf("Which fishbowl will you pour water? >> ");
        scanf("%d", &num);

        //입력값 체크
        if (num < 1 || num > 6)
        {
            printf("\n\n Wrong input number. Type again a number\n\n");
            continue; // 위로 다시 올라가서 입력 받기.
        }

        //총 경과시간 알아보기.
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // CLOCKS+PER_SEC 를 사용해서 milli second 단위를 1초 단위로 바꿔주기.
        printf("\n> Total elapsed time    : %ld second\n", totalElapsedTime);

        // 직전 물 준 시간(마지막으로 물을 준 시간) 이후로 흐른 시간 계산하기.
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("  Previous elapsed time : %ld second\n", prevElapsedTime);

        //어항의 물이 감소되어가는 증발 과정
        decreaseWater(prevElapsedTime);

        //사용자가 입ㄷ력한 어항에 물 주기.
        // 조건 1. 어항의 물이 0이라면 물을 주지 않는다. 이미 물고기가 죽었기 때문.
        if (cursor[num - 1] <= 0)
        {
            printf("\n> Fishbowl %d's fish was dead... You don't need to pour water on it.\n", num);
        }
        // 2. 어항의 물이 1~99 사이라면 물을 준다. 100을 넘는지 안 넘는지를 체크.
        else if (cursor[num - 1] + 1 <= 100)
        {
            //물을 준다.
            printf("\n> In fishbowl %d, pouring water.  \n", num);
            cursor[num - 1] += 1;
        }

        //레벨업을 할 건지 확인 (레벨업은 20초마다 수행된다.)
        if (totalElapsedTime / 20 > level - 1)
        {
            level++;
            printf(" ooooo level up! ooooo\n\n");

            // level 이 5이면 게임 끝내기.
            if (level == 5)
            {
                printf("\n\nooooo you win! ooooo\n\n");
                exit(0);
            }
        }

        // 물고기가 얼만큼 살았는지 체크하기.
        if (checkFishAlive() == 0)
        {
            // all dead
            printf("\n\n\nAll fish was dead... :(  \n\n");
            exit(0);
        }
        else
        {
            // at least one fish is alive.
            printf("Some fishes are still alive! :)\n\n");
        }

        /* 10초에 물을 주고 15초에 물을 주었다면 5초의 시간이 경과 되었으니
        prevElapsedTime 엔 15초가 들어가게 된다.
        그 후 25초에 물을 준다면 10초 경과 후 물을 준 셈인데
        이전시간에 대한 정보를 담기 위해 전체 흐른시간을 prevElapseTime 에 넣어주어야 한다.*/

        prevElapsedTime = totalElapsedTime;
    }

    return 0;
}

void initDate()
{
    level = 1; //게임 레벨 (1~5)
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; // 어항의 물 높이 (0~100)
    }
}

// 물이 얼만큼 들어있는지에 대한 어항 상태 알려주는 함수.
void printFishes()
{
    printf("%3dst %3dnd %3drd %3dth %3dth %3dth\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n\n");
}

void decreaseWater(long elapsedTime)
{
    // 6 개 어항 모두 물을 증발 시키기.
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] -= (level * 1.5 * (int)elapsedTime); // 3은 난이도 조절을 위한 값.
        //어항의 물이 마이너일 수는 없기 때문에 0보다 작은 수라고 한다면 그냥 0으로 퉁치기
        if (arrayFish[i] < 0)
        {
            arrayFish[i] = 0;
        }
    }
}

int checkFishAlive()
{
    for (int i = 0; i < 6; i++)
    {
        //어항에 물이 남아 있으면 물고기가 살아있다는 것을 알리기.
        if (arrayFish[i] > 0)
        {
            return 1; // 1은 참을 의미.
        }
    }
    return 0;
}