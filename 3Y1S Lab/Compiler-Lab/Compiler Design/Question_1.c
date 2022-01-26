#include <stdio.h>
#include <string.h>


int isValidDelimiter(char ch){
    if (ch == ' ' || ch == '+'  || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}'){
        return 1;
    }
    return 0;
}

int isValidLetter(char ch){
    if( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
        return 1;
    }
    return 0;
}

int isValidDigit(char ch){
    if(ch >= 48 && ch <= 57 ){
        return 1;
    }
    return 0;
}

int isVowel(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        ch = ch - 'A' + 'a';
    }
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return 1;
    }
    return 0;
}


void aNo(char str[]){
    printf("A\n");
    int len = strlen(str);
    int i, j, words, letters = 0, digits = 0, others = 0;
    words = 1;

    for(int i = 0;i < len; i++){
        if(str[i] == ' ' && str[i+1] != ' '){
            words++;
        }
        if(isValidLetter(str[i])){
           letters++;
        }
        else if(isValidDigit(str[i])){
            digits++;
        }else{
            others++;
        }
    }
    printf("Number of Words = %d, Letters = %d, Disits = %d, Others = %d", words, letters, digits, others);
}

void bNo(char str[]){
    printf("\nB\n");

    int len = strlen(str);
    int i, l=0, d=0, o=0;
    char letter[50], digit[50], others[50];

    for(int i = 0; i < len; i++){
        if(isValidLetter(str[i])){
           letter[l++] = str[i];
        }else if(isValidDigit(str[i])){
            digit[d++] = str[i];
        }else if(str[i] != ' '){
            others[o++] = str[i];
        }
    }

    letter[l] = digit[d] = others[o] = '\0';
    printf("Letters: %s\nDigits: %s\nOthers: %s\n",letter,digit,others);
}

void cNo(char str[]){
    printf("\nC\nCount how many vowels and consonants are there?\n");

    int vowels = 0, con = 0, i;
    int len = strlen(str);
    for(i = 0; i < len; i++){
        if(isValidLetter(str[i])){
            if(isVowel(str[i])){
                vowels++;
            }else{
                con++;
            }
        }
    }

    printf("Number of Vowels: %d and Consonants: %d\n",vowels,con);

}

int mark[30];

void dNo(char str[]){
    printf("D\n");

    int len = strlen(str);
    int i,j = 0, k = 0;
    char vowel[50], consonant[50],ch;

    for(i = 0; i < len; i++){
        if(isValidLetter(str[i])){
            ch = str[i];
            if(ch>= 'A' && ch <= 'Z'){
                ch = ch - 'A' + 'a';
            }
            if(isVowel(ch) && mark[ch-'a'] == 0){
                vowel[j++] = str[i];
                mark[ch-'a'] = 1;
            }else if(mark[ch-'a'] == 0){
                consonant[k++] = str[i];
                mark[ch-'a'] = 1;
            }
        }
    }

    vowel[j] = consonant[k] = '\0';
    printf("Vowel: %s and Consonant: %s\n",vowel,consonant);
}

void eNo(char str[]){
    printf("\nE\n");

    int len = strlen(str);
    int i, j = 0, k = 1, v[50], vw = 0, cs = 0;
    v[0] = 0;
    char vowel[50], consonant[50];
    for(i = 1; i < len; i++){
        if(str[i] == ' ' && i + 1 < len){
            v[k++] = i + 1;
            printf("value of i %d\n", i);
        }
    }

    printf("\nValue of k = %d\n", k);


    for(i = 0; i < k; i++){
        if(isVowel(str[v[i]])){
            vowel[vw++] = str[v[i]];
            j = v[i] + 1;
            while(j < len && str[j] != ' '){
                vowel[vw++] = str[j++];
            }
        }
    }
    vowel[vw] = '\0';

    for(i = 0; i < k; i++){
        if(!isVowel(str[v[i]]) && !isValidDigit(str[v[i]])){
            consonant[cs++] = str[v[i]];
            j = v[i] + 1;

            while(j < len && !isValidDelimiter(str[j])){
                consonant[cs++] = str[j++];
            }
            consonant[cs++] = ' ';

        }
    }

    consonant[cs] = '\0';
    puts("Starting with vowel");
    puts(vowel);
    puts("Starting with consonant");
    puts(consonant);


}


int main()
{
    char str[100] = "Md. Tareq Zaman, Part-3, 2011";

    aNo(str);
    bNo(str);
    cNo(str);
    dNo(str);
    eNo(str);

    return 0;
}


