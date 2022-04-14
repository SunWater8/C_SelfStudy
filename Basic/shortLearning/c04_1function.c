#include <stdio.h>

//함수 선언하기.
void p(int num);
int add(int num);
void function_without_return();
void function_without_params();
void function_with_params(int a, int b, int c);
int apple(int total, int ate);

int main(void)
{
    // 계산기
    printf("=== function basic ===\n");
    int num = 2;

    num += 1;
    p(num);

    num -= 3;
    p(num);

    num += 4;
    num *= 2;
    p(num);

    num /= 2;
    p(num);

    printf("\n\n");
    // 반환형 함수 출력
    printf("=== function with return ===\n");
    num = add(3);
    p(num);

    printf("\n\n");
    // 반환값이 없는 함수.
    printf("=== function without return ===\n");
    function_without_return();

    printf("\n\n");
    // 전달값이 없는 함수
    printf("=== function without parameter ===\n");
    function_without_params();

    printf("\n\n");
    // 전달값이 있는 함수
    printf("=== function with parameter ===\n");
    function_with_params(12, 35, 48);

    printf("\n\n");
    // 전달값과 반환값이 있는 함수.
    printf("=== function with parameters and return ===\n");
    // 5개의 사과 중에 2개를 먹고 남은 개수를 반환하기.
    int ret = apple(5, 2);
    printf("%d apples are left.\n", ret);




    return 0;
}

//함수 정의하기.
void p(int num)
{
    printf("num is %d\n", num);
}

int add(int num)
{
    return num + 4;
}

void function_without_return()
{
    printf("function without return.\n");
};

void function_without_params()
{
    printf("function without parameters.\n");
};

void function_with_params(int a, int b, int c)
{
    printf("function with parameters. parameters are %d, %d, %d.\n", a, b, c);
}

int apple(int total, int ate)
{
    printf("function with parameters and return\n");
    return total - ate;
}