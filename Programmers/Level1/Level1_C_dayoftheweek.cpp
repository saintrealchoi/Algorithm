#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) {
    char* answer = (char*)malloc(3);
    int i = 0;
    switch (a) {
    case 1:
        break;
    case 2:
        i = 31;
        break;
    case 3:
        i = 60;
        break;
    case 4:
        i = 91;
        break;
    case 5:
        i = 121;
        break;
    case 6:
        i = 152;
        break;
    case 7:
        i = 182;
        break;
    case 8:
        i = 213;
        break;
    case 9:
        i = 244;
        break;
    case 10:
        i = 274;
        break;
    case 11:
        i = 305;
        break;
    case 12:
        i = 335;
        break;
    }
    i = i + b - 1;
    char* arr[7] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
    for (int j = 0; j < 7; j++)
    {
        if (j == (i % 7))
        {
            answer = arr[j];
            break;
        }
    }
    printf("%s", answer);
    return 0;
}
int main()
{
    solution(1, 19);
}