#include <stdio.h>

int main(void)
{
    //버스를 탄다고 가정
    int age = 15;
    if (age > 20)
        printf("you are adult\n");
    else
        printf("you are student\n");

    printf("\n\n\n");

    // if/ break  | continue
    // 1~30번 까지 있는 반에서 1~5번 까지만 조별 발표를 합니다.
    for (int i = 0; i < 30; i++)
    {
        if (i > 6)
        {
            printf("Rest of you would go home\n");
            break;
        }
        printf("%d student must do a presentation today.\n", i);
    }
    printf("\n\n\n");

    // 1~30번 까지 있는 반에서 7번 학생은 아파서 결석
    // 7번을 제외하고 6~10번까지 조별 발표를 합니다.
    for (int i = 1; i <= 30; i++)
    {
        if (i >= 6 && i <= 10)
        {

            if (i == 7)
            {
                printf("%d student is absent\n", i);
                
                continue;
            }
            printf("%d student presentaion\n", i);
        }
    }
    printf("\n\n\n");


    //and or









    

    return 0;
}