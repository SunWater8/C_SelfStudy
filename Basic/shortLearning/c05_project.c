#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 아빠는 대머리 게임

/* 출력 결과

========== Dad's bald hair game ==========

> 1 try : 2 3  put on his hair.

    >> Fair! His hair hasn't grown.. :(

.. Press any key if you want to continue ..
===========================================

> 2 try : 2 3 4 put on his hair.

    >> Hooray! His hair has grown!!

.. Press any key if you want to continue ..
===========================================

> 3 try : 1 2 put on his hair.

    >> Hooray! His hair has grown!!

    >> Fair! His hair hasn't grown.. :(

.. Press any key if you want to continue ..
===========================================

Which number is the hair-solution  >>> 4 (scanf 로 직접 입력한 값)

>> Perfect! That's wright.
(>> Beep! That's wrong. The answer is 4.)


*/

int main(void)
{

    // int hair_solution[] = {1, 2, 3, 4};

    printf("========== Dad's bald hair game ==========\n\n");

    // computer 가 뽑은 정답 random 한 수
    srand(time(NULL));
    int answer;                 // 사용자 입력값
    int treatment = rand() % 4; // 발모제 선택 (0~3)
    int cntShowBottle = 0;      // 이번 게임에 보여줄 병 갯수
    int prevCntShowBottle = 0;  //서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 다음엔 3개. 이런 식으로)

    // 3번의 발모제 투여 시도
    for (int i = 0; i < 3; i++)
    {
        int bottle[4] = {0, 0, 0, 0}; // 4개의 병

        //보여 줄 병 갯수 몇개로 할 지 뽑기 (2~3개)
        do
        {
            cntShowBottle = rand() % 2 + 2;           // 보여줄 병 갯수 (0~1, +2 -> 2, 3)
        } while (cntShowBottle == prevCntShowBottle); // 앞에 나온 병 갯수와 이번 게임에서의 병 갯수가 다를 때 까지 반복해서 병 갯수 뽑기
        prevCntShowBottle = cntShowBottle; // 원래 선언한 값으로 돌려놓기. ??
        
        int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부

        printf("> try %d : ", i + 1);

        //보여줄 병 종류 선택하기.
        for (int j = 0; j < cntShowBottle; j++)
        {
            int randBottle = rand() % 4;

            //아직 선택되지 않은 병이면, 선택 처리하기.
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;

                //선택된 병이 발모제가 포함되었다면 포함여부를 1로 표시.
                if (randBottle == treatment)
                {
                    isIncluded = 1;
                }
            }
            //이미 선택된 병이면, 중복이므로 다시 선택하기.
            else
            {
                j--;
            }
        }

        //사용자에게 문제 표시
        for (int k = 0; k < 4; k++)
        {
            if (bottle[k] == 1)
                printf("%d ", k + 1);
        }
        printf("Put on his hair.\n\n");

        if (isIncluded == 1)
        {
            printf("    >> Hooray! His hair has grown!! :)\n\n");
        }
        else
        {

            printf("    >> Fair! His hair hasn't grown.. :(\n\n");
        }
        printf(".. Press any key if you want to continue ..\n===========================================\n\n");
        getchar(); // 사용자가 아무키나 누르면 다음으로 넘어감
    }

    printf("Which number is the hair-solution  >>> ");
    scanf("%d", &answer);
    printf("\n");

    if (answer == treatment + 1)
    {
        printf(">> Perfect! That's right.\n\n");
    }
    else
    {
        printf(">> Beep! That's wrong. The answer is %d\n\n", treatment + 1);
    }

    return 0;
}