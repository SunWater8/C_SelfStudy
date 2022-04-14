#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 구구단 5문제 맞추기 게임
// level 1 ~ 5 까지 문제가 출제된다. 레벨이 높아질 수록 7배수의 숫자 범위가 늘어난다.
// ex) lever 1 은 1~7의 숫자 가운데 곱하기를 수행. level 2 은 1~14 사이의 숫자가 랜덤으로 곱하기 수행.

/* 출력 결과

############## Q 1 ##############

            7 x 5 = ?

#################################

Answer the question (exit:-1) >> 35 (입력값)

>> Good! That's right.


############## Q 2 ##############

            9 x 2 = ?

#################################

Answer the question (exit:-1) >> 17

>> Beep! That's wrong.

                .
                .  (총 5번 질문 하기.)
                .

############## Q 5 ##############

            19 x 56 = ?

#################################

Answer the question (exit:-1) >> 456

>> Beep! That's wrong.

This game is over. Your score is 3 of 5.

*/

void showQuestion();
int get_random_number();

int main(void)
{
    srand(time(NULL));
    int count = 1;
    for (int level = 1; level <= 5; level++)
    {
        
        int num1 = get_random_number(level);
        int num2 = get_random_number(level);

        showQuestion(level, num1, num2);

        printf("Answer the question (exit:-1) >> ");
        
        int guess_num;
        scanf("%d", &guess_num);

        int answer_num = num1 * num2;
        if (guess_num == -1) 
        {
            printf("This program will be finished.");
            break;
        }
        else if (answer_num == guess_num)
        {
            //success();
            printf("\n>> Good! That's right.\n\n");
            count++;
        }
        else 
        {
            //fail();
            printf("\n>> Beep! That's wrong.\n\n");
        }
        if (level == 5)
        {
            printf("\nThis game is over. Your score is %d of %d.\n", count, level);
        }
    }
    return 0;
}

int get_random_number(int level)
{
    return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
    printf("############## Q %d ##############\n", level);
    printf("this level is %d\n\n", level);
    printf("            %d x %d = ?\n\n", num1, num2);
    printf("#################################\n\n");
}
