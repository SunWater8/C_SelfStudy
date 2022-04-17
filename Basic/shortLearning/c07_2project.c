#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 10마리의 서로 다른 동물 (각 카드 2장 씩)
사용자로부터 2개의 입력 값을 받아서 같은 동물을 찾으면 카드가 뒤집어짐.
모든 동물쌍을 찾으면 게임이 종료된다.
총 실패 횟수를 알려주기.*/

/* 결과 화면

***************** secret screen ******************

     camel  ostrich     cat     tiger    cat
    monkey      dog  giraff  elephant  hoppo
       dog    tiger     pig    giraff    pig
    monkey elephant ostrich     hippo  camel

***************************************************

<Question>
    1       2       3       4       5
    6       7       8       9       10
    11      12      13      14      15
    16      17      18      19      20  

Which two cards do you want to invert? >> 3 5 (사용자 입력)

> Bingo! cat was found.



***************** secret screen ******************

     camel  ostrich     cat     tiger    cat
    monkey      dog  giraff  elephant  hippo
       dog    tiger     pig    giraff    pig
    monkey elephant ostrich     hippo  camel

***************************************************

<Question>
    1       2     cat       4       cat
    6       7       8       9       10
    11      12      13      14      15
    16      17      18      19      20  

Which two cards do you want to invert? >> 4 10 (사용자 입력)

> Beep! Two cards are different or already checked.
  4 : tiger
  12: hippo

                        .
                        .
                        .
                        .
            (우여곡절 끝에 모든 카드를 맞춤)


<COMPLETE>
All animals were found and matched.
So far, 5 times mistakes.






*/

int main(void)
{






    return 0;
}