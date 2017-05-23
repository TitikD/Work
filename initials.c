#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = GetString();
    if(s[0] != ' '){
        printf("%c",toupper(s[0])); 
    }
    for(int i = 0, n = strlen(s); n > i; i++){
        if(s[i] == ' ' && s[i+1] != ' ' && s[i+1] != '\0'){
            printf("%c",toupper(s[i+1]));
        }
    }
    printf("\n");
}