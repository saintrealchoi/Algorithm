#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int i = 0;
    int count = 0;
    int num = strlen(s);
    char* temp = (char*)malloc(1);
    char* answer = (char*)malloc(num);
    strcpy(answer, s);
    printf("%c\n", answer[0]);
    printf("%c\n", answer[1]);
    printf("%c\n", answer[2]);
    printf("%c\n", answer[3]);
    printf("%c\n", answer[4]);
    printf("%c\n", answer[5]);
    while (1)
    {
        count = 0;
        i = 0;
        for (; i < num - 1; i++)
        {
            if (answer[i] < answer[i + 1])
            {
                temp[0] = answer[i + 1];
                answer[i + 1] = answer[i];
                answer[i] = temp[0];
                count++;
            }
        }
        if (count == 0)
        {
            break;
        }
    }

    return answer;

}