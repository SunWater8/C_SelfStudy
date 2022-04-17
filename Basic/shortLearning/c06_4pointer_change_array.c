#include <stdio.h>

void changeValue(int *ptr);

int main(void)
{

    //마지막 요소의 값을 50으로 바꾸기.
    int arr[3] = {10, 20, 30};
    // 바꾸기 전 값 확인.
    printf(" === Before change === \n\n");
    for (int i = 0; i < 3; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\n\n\n === After change === \n\n");

    // changeValue(arr);
    changeValue(&arr[0]); // 주소를 던져도 결과는 같다.

    // 바꾼 후 값 확인.
    for (int i = 0; i < 3; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}

void changeValue(int *ptr)
{
    ptr[2] = 50;
}