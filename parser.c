//This will parse basic arithmetic 
// input will be single lines of things like 3+55-10*2;
//walk through each char of input. 
// * if int, flag 'reading int'
// * if space, end token
// * if plus yada yada
// * if semicolon end tree, list tokens



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define BUFF_SIZE 100


typedef struct token {
    int val;
} Token;


int main(int argc, char *argv[]){
    // 2d array of chars to make array of token strings. 20 tokens max, 30 chars per token max
    char tokens[20][30];
    char str[BUFF_SIZE];
    int c;
    FILE *fp;
    fp = fopen(argv[1], "r");
    //now read each line and tokenize everything
    //walk through line by char
    // OR use strtok on +, -, *, /. Then 
    while(!feof(fp)){
        c = fgetc(fp);
        if(isalpha(c))
            printf("char");
        else if(isdigit(c))
            printf("digit");
        else if(c == '+')
            printf("its a plus");
        else if(c == ' ')
            printf("its a space");
        else if(c == ';')
            printf("its a semi");
        else if(c == '"')
            printf("quote");
        puts(" ");
    }
    printf("\n");
    return 0;
}
