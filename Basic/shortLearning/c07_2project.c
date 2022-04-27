#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 10마리의 서로 다른 동물 (각 카드 2장 씩)
사용자로부터 2개의 입력 값을 받아서 같은 동물을 찾으면 카드가 뒤집어짐.
모든 동물쌍을 찾으면 게임이 종료된다.
게임이 종료되면 총 실패 횟수를 알려주기.*/

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
So far, 5 times mistakes you had.

*/
int arrayAnimal[4][5]; // 카드 지도 (20장의 카드)
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인
char *strAnimal[10];   // 동물 이름

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();

int conv_pos_x(int x);
int conv_pos_y(int y);

void printAnimals();
void printQuestion();

int main(void)
{
    srand(time(NULL));

    initAnimalArray(); // 동물 배열을 만드는 함수.
    initAnimalName();  // 동물 이름

    shuffleAnimal(); //동물 지도에 동물들 넣어서 섞기

    int failCount = 0; // 실패 횟수

    while (1)
    {
        int select1 = 0; // 사용자가 선택한 처음 수
        int select2 = 0; // 사용자가 선택한 두번째 수

        printAnimals();  // 동물 위치 출력
        printQuestion(); // 문제 출력 (카드 지도)

        printf("\nWhich two cards do you want to invert? >> ");
        scanf("%d %d", &select1, &select2);

        //같은 카드 선택 시 무효 처리
        if (select1 == select2)
        {
            continue;
        }
        // if()
        // {
        //     printf("\n> Bingo! cat was found.\n");
        // }
        // else
        // {

        //     printf("\n> Beep! Two cards are different or already checked.\n");
        //     printf("%d : %s\n", select1, ); // 4 : tiger
        //     printf("%d : %s\n", select2, ); // 12: hippo
        //     failCount++;
        // }
    }

    /*

    <COMPLETE>
    All animals were found and matched.
    So far, 5 times mistakes you had.
    */

    return 0;
}

void initAnimalArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1; // 빈 공간을 나타내기 위해 일괄적으로 -1로 통일.
        }
    }
}

void initAnimalName()
{
    strAnimal[0] = "Cat";
    strAnimal[1] = "Hippo";
    strAnimal[2] = "Dog";
    strAnimal[3] = "Camel";
    strAnimal[4] = "Ostrich";
    strAnimal[5] = "Giraff";
    strAnimal[6] = "Pig";
    strAnimal[7] = "Monkey";
    strAnimal[8] = "Elephant";
    strAnimal[9] = "Tiger";
}

void shuffleAnimal()
{
    //빈 공간에 동물 이름 2개씩 넣기.
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition(); //비어있는 위치를 반환하여 pos(position) 변수에 넣기.
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{
    //ㅁㅁㅁㅁㅁ  0  1  2  3  4
    //ㅁㅁㅁㅁㅁ  5  6  7  8  9
    //ㅁㅁㅁㅁㅁ 10 11 12 13 14
    //ㅁㅁㅁㅁㅁ 15 16 17 18 19

    while (1)
    {
        int randPos = ran() % 20; // 0~19 사이의 숫자 반환

        // 19 -> [3, 4]
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if (arrayAnimal[x][y] == -1)
        {
            return randPos;
        }
    }
    return 0;
}

/* 가로로 된 숫자들을 각각 5로 나누면 정수형 값으로 0,1,2,3 이렇게 나온다.

ㅁㅁㅁㅁㅁ  0  1  2  3  4  →  0 0 0 0 0
ㅁㅁㅁㅁㅁ  5  6  7  8  9  →  1 1 1 1 1
ㅁㅁㅁㅁㅁ 10 11 12 13 14  →  2 2 2 2 2
ㅁㅁㅁㅁㅁ 15 16 17 18 19  →  3 3 3 3 3
*/

int conv_pos_x(int x)
{
    return x / 5;
}

/* 세로로 된 숫자들을 각각 5로 나누면 나머지가 0, 1, 2, 3, 4 이렇게 나온다.

ㅁㅁㅁㅁㅁ  0  1  2  3  4  →  0 1 2 3 4
ㅁㅁㅁㅁㅁ  5  6  7  8  9  →  0 1 2 3 4
ㅁㅁㅁㅁㅁ 10 11 12 13 14  →  0 1 2 3 4
ㅁㅁㅁㅁㅁ 15 16 17 18 19  →  0 1 2 3 4

*/
int conv_pos_y(int y)
{
    return y % 5;
}

void printAnimals()
{
    printf("\n\n***************** secret screen ******************\n\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }

    printf("\n\n***************************************************\n\n");
}

void printQuestion()
{

    printf("<Question>\n");
    int seq = 0; // sequence 연속된 숫자

    /*                                    seq                            checkAnimal (동물 맞춘 곳은 1, 아직 맞추지 못한 동물엔 0으로 check하기.)

    ㅁㅁㅁㅁㅁ  0  1  2  3  4     0     1     2     3     4                0 0 0 0 0
    ㅁㅁㅁㅁㅁ  5  6  7  8  9    hippo  6     7     8     9                1 0 0 0 0
    ㅁㅁㅁㅁㅁ 10 11 12 13 14    10    11    12   hippo   14               0 0 0 1 0
    ㅁㅁㅁㅁㅁ 15 16 17 18 19    15    16     17    18    19               0 0 0 0 0
    */
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //카드를 뒤집어서 정답을 맞혔으면 -> 동물 이름
            if (checkAnimal[i][j] != 0)
            {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            // 아직 뒤집지 못했으면 (정답을 못맞췄으면) -> 뒷면 (위치를 나타내는 숫자)
            else
            {
                printf("%8d", seq);
            }
        }
        printf("\n");
    }
}