#include <stdio.h>

int main(void)
{
    // 포인터와 배열
    int arr[3] = {1, 5, 7};
    int *ptr = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("Value of arr[%d] : %d\n", i, arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Value of ptr[%d] : %d\n", i, ptr[i]);
    }

    // 포인터 배열의 값으로 원래 가리키는 배열의 값을 바꿀 수 있다.
    printf("\n\n=== changing values of ptr ===\n\n");
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

    for (int i = 0; i < 3; i++)
    {
        // printf("Value of arr[%d] : %d\n", i, arr[i]);   아래 문장과 동일한 의미
        printf("Value of arr[%d] : %d\n", i, *(arr + 1));
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        // printf("Value of ptr[%d] : %d\n", i, ptr[i]);   아래 문장과 동일한 의미
        printf("Value of ptr[%d] : %d\n", i, *(ptr + 1));
    }

    // *(arr + i) == arr[i] 똑같은 표현
    // arr은 arr 배열의 첫 번째 값의 주소와 동일. arr == &arr[0]
    printf("\n\n=== arr and arr[0] ===\n\n");

    printf("arr         (value of arr)          : %d\n", arr);      // 6422012      arr : arr 자체의 값
    printf("&arr[0]     (address of arr[0])     : %d\n", &arr[0]);  // 6422012      arr[0] : arr[0]의 주소
    //&arr 의 값은 &arr[0] 와 같다.
    printf("&arr        (address of arr)        : %d\n", &arr);     // 6422012      
    printf("*&arr       (value of arr's address): %d\n", *&arr);    // 6422012         
    //*arr은 *(arr + 0)와 같다.
    printf("*arr        (address value of arr)  : %d\n", *arr);      // 100         *arr : arr 자체의 값이 가지는 주소의 실제 값
    
    // *&는 아무것도 없는 것과 같다. &는 주소이며, *는 그 주소의 값이기 때문에 *&는 서로 상쇄된다.  
    printf("*&arr[0]    (value of arr[0])       : %d\n", *&arr[0]);  // 100         arr[0]의 실제 값. 
    printf("arr[0]      (value of arr)          : %d\n", arr[0]);    // 100


    printf("\n\nptr\n\n");
    printf("ptr[0] (value of ptr[0] : %d\n", ptr[0]);
    printf("&ptr[0] (address of ptr) : %d\n", &ptr[0]);

    return 0;
}