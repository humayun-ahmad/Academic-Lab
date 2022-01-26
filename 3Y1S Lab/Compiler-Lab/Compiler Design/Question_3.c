/***
Write a program to recognize C which converts a word of C program to its equivalent token
i) keyword  ii) Identifier iii) Operator iv) Constant
***/
#include <stdio.h>
#include <string.h>


int isValidArithmeticOperator(char *str){
    if(!strcmp(str,"+") || !strcmp(str,"-") || !strcmp(str,"*") || !strcmp(str, "/") || !strcmp(str,"%")|| !strcmp(str,"^") || !strcmp(str,"=") ){
        return 1;
    }
    return 0;
}

int isValidRelationalOperator(char *str){
    if(strcmp(str,"<") == 0 || strcmp(str,">") == 0 || strcmp(str,"!=") == 0||
        strcmp(str,"==") == 0 || strcmp(str,"<=") == 0 || strcmp(str,">=") == 0)
        return 1;

    return 0;
}

int isValidIdentifier(char ch){

    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;

    return 0;
}

int isFloat(char *str){

    int i, cnt = 0, len = strlen(str), j;

    for(i = 0; i < len; i++){
        if(str[i] == '.'){
            for(int j = 0; j < len; j++){
                if(j != i && (str[j]<'0' || str[j]>'9')){
                    return 0;
                }
            }
            if(str[0] == '0' && str[1] != '.'){
                return 0;
            }

            return len-i-1;
        }
    }
    return 0;

}

int isInteger(char *str){

    int i, len = strlen(str);

    for(i = 0; i < len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            continue;
        }
        return 0;
    }

    return 1;
}


int isValidKeyword(char* str){
    if (!strcmp(str, "auto") || !strcmp(str, "break") || !strcmp(str, "case") || !strcmp(str, "char") ||    !strcmp(str, "const") || !strcmp(str, "continue") || !strcmp(str, "default")
    || !strcmp(str, "do") || !strcmp(str, "double") || !strcmp(str, "else") || !strcmp(str,    "enum") || !strcmp(str, "extern") || !strcmp(str, "float")
    || !strcmp(str, "for") || !strcmp(str, "goto") || !strcmp(str, "if") || !strcmp(str, "int") || !strcmp(str, "long") || !strcmp(str, "register")
    || !strcmp(str, "return") || !strcmp(str, "short") || !strcmp(str, "signed") || !strcmp(str, "sizeof")|| !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "switch") || !strcmp(str, "typedef")
    || !strcmp(str, "union") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "volatile")|| !strcmp(str, "while")){
        return 1;
    }
    return 0;
}





int main(){
    char str[100];
    //char ch[10] = "Bangla";

    //printf("%d\n", strcmp(ch,"bangladesh"));
    int len,a;
    while(scanf("%s", str) != EOF ){
        len = strlen(str);

        if(isValidArithmeticOperator(str))
            printf("Arithmetic Operator\n");
        else if(isValidRelationalOperator(str))
            printf("Relational Operator\n");
        else if(isValidKeyword(str))
            printf("Keyword\n");
        else if(isValidIdentifier(str[0]))
            printf("Identifier\n");
        else if(isFloat(str))
            printf("Float\n");
        else if(isInteger(str))
            printf("Integer\n");
        else
            printf("Unknown\n");
    }



    return 0;
}
