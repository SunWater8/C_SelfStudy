#include <stdio.h>

int main(void)
{
    //문자열
    char str[7] = "coding"; // 문자열 끝에는 ￦0 가 추가되므로 str의 사이즈는 7이여야 한다.
    char str2[] = "coding";
    char str3[7] = {'c', 'o', 'd', 'i', 'n', 'g', '\0'}; //결국엔 str, str2, str3 배열은 다 같다.

    printf("%s\n", str2);
    printf("%d\n\n", sizeof(str2));

    // 문자열을 반복문으로 출력하는 방법
    printf("== print with for ==\n");
    for (int i = 0; i < sizeof(str); i++)
    {
        printf("%c", str[i]);
    }

    printf("\n\n");

    // %c가 아닌 $d로 출력하게 되면 ascii code 로 결과가 나온다. 그리고 배열에서 남은 한 자리는 null 값인 0이 표시된다.
    printf("== print with for - ascii code ==\n");
    printf("ascii code");
    for (int i = 0; i < sizeof(str); i++)
    {
        printf("%d\n", str[i]);
    }

    printf("\n\n");

    printf("== print ascii code ==\n");
    // 1~128 아스키코드 출력해보기
    for (int i = 0; i < 128; i++)
    {
        printf("ASCII CODE %3d : %c\n", i, i);
    }
    printf("\n\n");







    return 0;
}