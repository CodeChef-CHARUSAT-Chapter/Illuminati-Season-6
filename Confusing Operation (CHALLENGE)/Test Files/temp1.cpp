#include<iostream>
#include<stdio.h>
int main(){
    char s[3];
    scanf("%s",&s);
    printf("%s\n","MANN");
    if(s[0]=='R' && s[1]=='O' && s[2]=='W'){
        std::cout<<"YES"<<std::endl;
    }
    else{
        std::cout<<"NO"<<std::endl;
    }
}
