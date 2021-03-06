#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 2 /*1 for all, 2 for current development*/

enum operation {ERROR, UNDETERMINED, PLUS, SUBTRACT, MULTIPLY, DIVIDE};
int determine_sign(char *ptr)
{
    char *sign = "+-*/";
    int i;
    for(i = 0; i < 4; i++)
        if(ptr[0] == sign[i])
            return i + 2;
    return ERROR; /*This should never happen*/
}

void perform_add(int [], int [], int);
void perform_subtrack(int [], int [], int);
void perform_multiply(int [], int [], int);
void perform_divide(int [], int [], int);

int main()
{
    char input[500 * 2 + 10] = {'\0'};
    while(fgets(input, 1010, stdin) != NULL) {
        enum operation sign = UNDETERMINED;
        char *ptr, *temp_input_1, *temp_input_2;

        ptr = strtok(input, " ");
        temp_input_1 = malloc(sizeof(char) * (strlen(ptr) + 1));
        strcpy(temp_input_1, ptr);

        ptr = strtok(NULL, " ");
        sign = determine_sign(ptr);

        ptr = strtok(NULL, "\n");
        temp_input_2 = malloc(sizeof(char) * (strlen(ptr) + 1));
        strcpy(temp_input_2, ptr);

#if DEBUG == 1
        printf("Print all strtok results\n");
        printf("%s", temp_input_1);
        printf(" %d ", sign);
        printf("%s\n", temp_input_2);
#endif

        int i, input1[501] = {0}, input2[501] = {0};
        int len1 = strlen(temp_input_1), len2 = strlen(temp_input_2);
        int max = len1 > len2 ? len1: len2;

        for(i = 0; i < (int)strlen(temp_input_1); i++)
            input1[500 - (int)strlen(temp_input_1) + 1 + i] = temp_input_1[i] - '0';
        for(i = 0; i < (int)strlen(temp_input_2); i++)
            input2[500 - (int)strlen(temp_input_2) + 1 + i] = temp_input_2[i] - '0';

#if DEBUG == 1
        printf("Print all convert to number results\n");
        for(i = 0; i < 501; i++)
            printf("%d", input1[i]);
        printf("\n");
        for(i = 0; i < 501; i++)
            printf("%d", input2[i]);
        printf("\n");
#endif

        switch(sign) {
        case PLUS:
            perform_add(input1, input2, max);
            break;
        case SUBTRACT:
            perform_subtrack(input1, input2, max);
            break;
        case MULTIPLY:
            perform_multiply(input1, input2, max);
            break;
        case DIVIDE:
            perform_divide(input1, input2, max);
            break;
        default:
            printf("Error!\n");
            break;
        }
        free(temp_input_1);
        free(temp_input_2);
    }

    return 0;
}

void perform_add(int input1[], int input2[], int max)
{
    int i, carry = 0, answer[501] = {0};
    for(i = 500; i >= (500 - max); i--) {
        answer[i] = input1[i] + input2[i] + carry;
        if(answer[i] > 9) {
            carry = 1;
            answer[i] -= 10;
        } else {
            carry = 0;
        }
    }
#if DEBUG == 1
    printf("max %d\n", max);
    printf("Print all convert to number results\n");
    for(i = 0; i < 501; i++)
        printf("%d", input1[i]);
    printf("\n");
    for(i = 0; i < 501; i++)
        printf("%d", input2[i]);
    printf("\n");

    printf("Print plus result\n");
#endif

    if(answer[500 - max] == 0)
        max--;
    for(i = 500 - max; i < 501; i++)
        printf("%d", answer[i]);
    printf("\n");
}

void perform_subtrack(int input1[], int input2[], int max)
{
 
}

void perform_multiply(int input1[], int input2[], int max)
{


}

void perform_divide(int input1[], int input2[], int max)
{


}