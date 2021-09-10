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
#define TOKEN_LENGTH 30
#define NUM_TOKENS 20

typedef struct token {
    int val;
} Token;

int printTokens(char tokens[NUM_TOKENS][TOKEN_LENGTH]){
    printf("tokens:\n");
    for(int i=1;i<NUM_TOKENS;++i){
        if(tokens[i])
            printf("%s\n", tokens[i]);
    }
    return 0;

}

int main(int argc, char *argv[]){
    // 2d array of chars to make array of token strings. 20 tokens max, 30 chars per token max
    char tokens[NUM_TOKENS][TOKEN_LENGTH];
    char str[BUFF_SIZE];
    int c, contFlag, tokenNum, tokenChar;
    FILE *fp;
    contFlag = 0;
    tokenNum = 0;
    tokenChar = 0;
    fp = fopen(argv[1], "r");
    // Walk through, one char at a time
    // when hitting char or digit, set flag for continue token
    // otherwise, hit turn off flag, iterate token #
    while(!feof(fp)){
        printf(" ");
        c = fgetc(fp);
        if(isalpha(c)){
            printf("char");
            if(contFlag == 0){
                tokenNum++;
                tokenChar = 0;
            }
            else{
                tokenChar++;
            }
            contFlag = 1;
            tokens[tokenNum][tokenChar] = c;
        }
        else if(isdigit(c)){    //something wrong with digit/alpha case
            printf("digit");
            if(contFlag == 0){
                tokenNum++;
                tokenChar = 0;
            }
            else{
                tokenChar++;
            }
            contFlag = 1;
            tokens[tokenNum][tokenChar] = c;
        }
        else if(c == '+'){
            printf("plus");
            contFlag = 0;
            tokenNum++;
            tokenChar = 0;
            tokens[tokenNum][tokenChar] = c;
        }
        else if(c == ' '){
            printf("space");
            contFlag = 0;
            tokenNum++;
        }
        else if(c == ';'){
            printf("semi");
            contFlag = 0;
            tokenNum++;
            tokenChar = 0;
            tokens[tokenNum][tokenChar] = c;
        }
        else if(c == '"')
            printf("quote");
        else if(c == '\n')
            printf("\n");
    }
    printf("\n");
    char test[][30] = {{'a','b','c'},{'d','e','f'},{'h','i','j'},{'h','i','j'},{'h','i','j'},{'h','i','j'}};
    printTokens(tokens);
    return 0;
}
