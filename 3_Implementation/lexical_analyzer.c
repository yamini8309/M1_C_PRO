#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 1000

int isKeyword(char *token){

    char *keywords[18] = {"if", "else", "do", "while", "break", "continue", "switch",
                    "case", "short", "int", "long", "double", "float", "char",
                    "return", "void", "NULL", "struct"};
    int flag = 0;

    for(int i = 0; i < 18; ++i){

        if(strcmp(keywords[i], token) == 0){
            flag = 1;
            break;
        }
    }

    return flag;

}

int isDelimeter(char *token){

    char *delimeters = " {}[]()";
    char tokenArray[50];
    int flag = 0;

    strcpy(tokenArray, token);

    for(int i = 0; tokenArray[i] != '\0'; ++i){

        for(int j = 0; j < 7; ++j){

            if(delimeters[j] == tokenArray[i]){
                return 1;

            }

        }

    }

    return 0;


}


int isOperator(char *token){

    char *operators[7] = {"+", "-", "*", "/", ">", "<", "="};

    int flag = 0;

    for(int i = 0; i < 7; ++i){

        if(strcmp(operators[i], token) == 0){

            flag = 1;
            break;
        }
    }

    return flag;

}

int isLetter(char *token){

    char *letters = "abcdefghijklmoprstuvyzxw";
    char tokenArray[50];

    strcpy(tokenArray, token);

    int flag = 0;

        for(int i = 0; i < 25; ++i){

            if (letters[i] == tokenArray[0]){

                flag = 1;
                break;

            }
        }

    return flag;
}

int isNumber(char *token){

    char *numbers = "0123456789";
    char *letters = "abcdefghijklmoprstuvyzxw";
    char tokenArray[50];
    int flag = 0;

    strcpy(tokenArray, token);

    for(int i = 0; token[i] != '\0'; ++i){

        for(int j = 0; j < 10; ++j){

            //real number
            if(tokenArray[i] == '.')
                    return 0;

            if(numbers[j] == tokenArray[i]){
                flag = 1;
            }

            if(flag == 1){

                for(int x = 0; x < 25; ++x){

                    //not a valid identifier
                    if(letters[x] == tokenArray[i]){
                        return 2;
                    }
                }
            }
        }
    }
    return flag;
}

int main(){

    FILE *inpPtr;
    char item[MAX_CHAR];
    int index = 0;
    int i;
    char *token;


    printf("***CENG2002 LEXICAL PARSER HOMEWORK FOR FINAL EXAM***\n");
    printf("***The String Is:\n");

    inpPtr = fopen("stringtoparse.txt", "r");

    if(NULL == inpPtr){
        printf("File couldn't be opened.");
    }

    while(!(feof(inpPtr)) && (index <= MAX_CHAR)){

        fscanf(inpPtr, "%c", &item[index++]);

    }

    for(i = 0; i < (index-1); i++){

        printf("%c", item[i]);

    }



    printf("\n\n***TOKENIZED VERSION IS***\n");


    token = strtok(item, " ");

    while(token != NULL){

        int i = 0;
        int identifier;


        identifier = isDelimeter(token);


        if(identifier == 1){

            int indexDelimeter;
            char tokenArray[50];
            strcpy(tokenArray, token);
            char *delimeters = " {}[]()";

            for(int i = 0; tokenArray[i] != '\0'; ++i){

                for(int j = 0; j < 7; ++j){

                    if(delimeters[j] == tokenArray[i]){
                        indexDelimeter = i;
                        break;
                    }

                }

            }
            printf("\n'%c' IS A DELIMETER", tokenArray[indexDelimeter]);

            if(indexDelimeter == 0){
                int i;
                for(i = 1; tokenArray[i] != '\0'; ++i){

                    tokenArray[i-1] = tokenArray[i];

                }

                tokenArray[i-1] = '\0';


            }else{

                tokenArray[indexDelimeter] = '\0';

            }
            token = (char *)malloc(strlen(tokenArray));
            strcpy(token, tokenArray);

        }

        identifier = isKeyword(token);

        while(token[i] != '\0'){

            if(token[i] == ';'){
                token[i] = '\0';
                break;
            }

            ++i;

        }

        switch(identifier){
        case 1:
            printf("'%s' IS A KEYWORD", token);
            break;

        case 0:

            identifier = isOperator(token);

            switch(identifier){
            case 1:

                printf("\n'%s' IS AN OPERATOR", token);
                break;

            case 0:

                identifier = isLetter(token);

                switch(identifier){
                case 1:
                    printf("\n'%s' IS A VALID IDENTIFIER", token);
                    break;

                case 0:

                    identifier = isNumber(token);

                    switch(identifier){
                    case 0:
                        printf("\n'%s' IS A REAL NUMBER", token);
                        break;

                    case 1:
                        printf("\n'%s' IS AN INTEGER", token);
                        break;

                    case 2:
                        printf("\n'%s' IS NOT A VALID IDENTIFIER", token);
                        break;
                    }
                }
            }
        }

        token = strtok(NULL, " ");
    }


    fclose(inpPtr);


    return 0;

}
