#include <stdio.h>

int main(void) {
    //float
    float f = 34.27f;
    printf("%f\n",f); // 34.270000 -6�� �Ҽ��� �ڸ� ����
    printf("%.2f\n",f); // 34.27 -2° �ڸ� ������
    printf("%.1f\n",f); // 34.3  - �ݿø�

    //double (terminal ��� ����� float�� ����.)
    double d = 34.27;
    printf("%lf\n", d);
    printf("%.2lf\n", d);
    printf("%.1lf\n", d);

    //const (���)
    const int YEAR = 2000;
    

    printf("\n\n");
    
    //scanf

    // int input;
    // printf("input number:");
    // scanf("%d", &input);
    // printf("%d\n", input);


    // int one, two, three;
    // printf("input 3 numbers: ");
    // scanf("%d %d %d", &one, &two, &three);
    // printf("first num : %d\n", one);
    // printf("second num : %d\n", two);
    // printf("thrid num : %d\n", three);
    
    //character (char, string)
    char c = 'a';
    printf("%c\n", c);

    char str[256];
    scanf("%s", str, sizeof(str)); 
    printf("%s\n", str);

    printf("\n\n");


    
    
    return 0;
}
