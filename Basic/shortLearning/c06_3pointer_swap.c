#include <stdio.h>

void swap(int a, int b);
void swap_pointer(int *a, int *b);

int main(void)
{
    int a = 10;
    int b = 20;

    //실제 값을 전달하여 swap 하기.
    printf("=== swap without using pointer === \n\n");
    printf("Before  -> a : %d, b : %d\n", a, b);
    swap(a, b);
    printf("After   -> a : %d, b : %d\n", a, b);

    // 실제 값이 아닌 주소값 전달하여 swap 하기.
    printf("\n\n=== swap with using pointer === \n\n");
    printf("Before  -> a : %d, b : %d\n", a, b);
    swap_pointer(&a, &b);
    printf("After   -> a : %d, b : %d\n", a, b);

    return 0;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("In func -> a : %d, b : %d\n", a, b);
}

void swap_pointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("In func -> a : %d, b : %d\n", *a, *b);
}