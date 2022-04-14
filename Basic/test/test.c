#include <stdio.h>

main(){
    int i =10, j = 10, k = 30;
    i /= j; //i 에 i/j 값을 넣어라. i=1
    j -= i; // j에 j-i 값을 넣어라. j = 9
    k %= j; // k 에 k%j를 넣어라. 30/9의 나머지는 3. k=3
    printf("%d %d %d\n", i, j, k); // 1 9 3
}