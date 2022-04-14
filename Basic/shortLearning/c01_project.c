#include <stdio.h>

int main(void) {
    //경찰관이 범죄자의 정보를 입수 (조서 작성)
    // 이름, 나이, 몸무게, 키, 범죄명

    char name[256];
    printf("what is your name? : ");
    scanf("%s", name, sizeof(name));

    int age;
    printf("How old are you? : ");
    scanf("%d", &age);


    float weight;
    printf("How kg are you? : ");
    scanf("%f",&weight);

    double height;
    printf("How tall are you? : ");
    scanf("%lf", &height);

    char name_of_crime[256];
    printf("What is your crime name? : ");
    scanf("%s", name_of_crime, sizeof(name_of_crime));


    // 조서 내용 출력
    printf("=== Result of collection ===\n");
    printf("Name is %s\n", name);
    printf("He is %d years old.\n", age);
    printf("He is %.1f kg.\n", weight);
    printf("His height is %.1lf.\n", height);
    printf("He was captured by %s\n", name_of_crime);


    return 0;
}