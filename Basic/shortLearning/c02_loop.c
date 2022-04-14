#include <stdio.h>

int main(void)
{

    // 10번 문장 출력하기. - for, while, do while

    // for (선언; 조건; 증감){ }
    printf("=== for ===\n\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("hello world with for(%d)\n", i);
    }

    printf("\n\n\n\n");

    // while (조건){ }
    printf("=== while ===\n\n");
    int j = 1;
    while (j <= 10)
    {
        printf("hello world with while(%d)\n", j++);
        // j++;
    }

    printf("\n\n\n\n");

    // do { } while (조건)
    printf("=== do while ===\n\n");
    int k = 1;
    do
    {
        printf("hello world with do while (%d)\n", k++);
    } while (k <= 10);

    printf("\n\n\n\n");

    // 2중 반복문
    printf("=== for and for ===\n\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\nThe first loop : %d\n", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("     The second loop : %d\n", j + 1);
        }
    }

    printf("\n\n\n\n");

    //구구단
    printf("=== for and for(2) ===\n\n");

    for (int i = 2; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }

    printf("\n\n\n\n");

    // *찍기
    printf("=== star(1) ===\n\n");
    /*
     *
     **
     ***
     ****
     *****
     */
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }


    printf("\n\n\n\n");

    // 오른쪽 정렬
    printf("=== star(2) ===\n\n");
    /*
        *
       **
      ***
     ****
    *****
    */
    for (int i = 5; i < 0; i--)
    {
        for(int j = 0; j > i ; j++){
            printf("*");
        }
        // for(int k=0; k <; k++){
        //     printf("*");
        // }
        printf("\n");
    }

    printf("my way\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 5; j > i; j--){
            printf(" ");
        }
        for (int k = 0; k < i+1; k++){
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n\n");

    printf("teacher's way\n");
    /* 공백을 s로 치환하여 생각하기.
    ssss*
    sss**
    ss***
    s****
    *****
    */
    for (int i =0; i < 5; i++ ){
        for (int j = i; j <5-1; j++){
            printf("s");
        }
        for (int k = 0; k <=i; k++){
            printf("*");
        }
        printf("\n");
    }


    printf("\n\n\n\n");



    // project - 피라미드를 쌓아라!
    printf("=== making star pramid ===\n\n");
    /*
        *
       ***
      *****
     *******
    *********
    */

    // 공백을 o으로 치환하여 만들기
    // oooo*
    // ooo***
    // oo*****
    // o*******
    // *********

    for (int i =0; i<5; i++){
        for (int j = i; j < 5-1; j++){
            printf("o");
        }
        for (int k = 0; k <= i*2; k++){
            printf("*");
        }
        printf("\n");
    }



    printf("\n[using scanf]\n");
    int a;
    while (a=1) {

        int floor;
        printf(" How many steps for pramid? : ");
        scanf("%d", &floor);
        printf("%d floors! \n\n", floor);

        for (int i =0; i < floor; i++){
            for (int j = i; j < floor-1; j++){
                printf(" ");
            }
            for (int k = 0; k < i*2+1; k++){
                printf("*");
            }
            printf("\n");
        }
    }









    return 0;
}