#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    // random 숫자 맞추기 게임.
    /*출력 결과
    정답 숫자 : 63
    남은 기회 : 5번
    숫자를 맞혀보세요 <1~100> : 50
    up!

    남은 기회 : 4번
    숫자를 맞혀보세요 <1~100> : 63
    정답입니다!
    */
    srand(time(NULL));
    int num = rand() % 100 + 1;
    // printf("computer's choice number : %d\n", num);

    int count = 5;
    int guess;
    while (count > 0)
    {
        printf("count : %d\n", count--);
        printf("Guess the number <1~100>: ");
        scanf("%d", &guess);

        if (guess > 0 && guess <= 100)
        {
            if (count == 0)
            {
                printf("your chance's over");
                break;
            }
            
            if (guess > num)
            {
                printf("down!");
            }
            else if (guess < num)
            {
                printf("up!");
            }
            else if (guess == num)
            {
                printf("That's right!");
                break;
            }
        }
        else
        {
            printf("Error!!! you should input number from 1 to 100\n");
        }
        printf("\n");
    }





    return 0;
}