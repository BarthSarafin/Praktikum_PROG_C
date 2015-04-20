//
// Created by BarthSarafin on 20.04.2015.
//

#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[100];
    int result;

    printf("Please enter a String:\n");
    gets(string);

    result = isPalindrome(string);

    if(result == 1){
        printf("\"%s\" is a palindrome string.\n", string);
    } else {
        printf("\"%s\" is not a palindrome string.\n", string);
    }
    return 0;
}

int isPalindrome(char *string){
    int check, length;
    char *reverse;

    length = stringLength(string);
    reverse = (char*)malloc((size_t) (length+1));

    copyString(reverse, string);
    reverseString(reverse);

    check = compareString(string, reverse);

    free(reverse);

    if(check == 0){
        return 1;
    } else {
        return 0;
    }
}

int stringLength(char *string){
    int length = 0;

    while(*string){
        length++;
        string++;
    }

    return length;
}

void copyString(char *target, char *source){
    while(*source){
        *target = *source;
        source++;
        target++;
    }

    *target = '\0';
}

void reverseString(char *string){
    int length, c;
    char *begin, *end, temp;

    length = stringLength(string);

    begin = string;
    end = string;

    for(c = 0; c < (length - 1); c++){
        end++;
    }

    for(c = 0; c < length/2; c++){
        temp = *end;
        *end = *begin;
        *begin = temp;

        begin++;
        end--;
    }
}

int compareString(char *first, char *second){
    while(*first == *second){
        if(*first == '\0' || *second == '\0'){
            break;
        }
        first++;
        second++;
    }
    if( *first == '\0' && *second == '\0'){
        return 0;
    } else {
        return -1;
    }
}