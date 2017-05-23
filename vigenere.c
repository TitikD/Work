#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Error argc\n ./vigenere key");
        return 1;
    }
    string k = argv[1];
    for(int i = 0, n = strlen(k); n > i; i++){
        if(!isalpha(k[i])){
            printf("Error lang");
            return 1;
        }
    }
    string s = GetString();
    int j = 0;
    int low;
    for(int i = 0, n = strlen(s); n > i; i++){
        if(islower(k[j])){
            low = 97;
        }
        if(isupper(k[j])){
            low = 65;
        }
        if(j == strlen(k)){
            j = 0;
        }
        if(isalpha(s[i])){
            if(isupper(s[i])){
                int u = (s[i]-65+k[j]-low)%26;
                printf("%c",u+65);
            }
            if(islower(s[i])){
                int l = (s[i]-97+k[j]-low)%26;
                printf("%c",l+97);
            }
        }else{
            printf("%c", s[i]);
            j--;
        }
        j++;
    }
    printf("\n");
    return 0;
}