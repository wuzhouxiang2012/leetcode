# define LOCAL
# include<stdio.h>
# include<string.h>
# include<ctype.h>


const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

char r(char ch){
    if (isalpha(ch)) return rev[ch-'A'];
    return rev[ch - '0'+25];
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char s[5000];
    while (scanf("%s", s)==1){
        int len = strlen(s);
        bool palFlag = true, mirFlag = true;
        for (int i=0; i<(len+1)/2; i++){
            if (s[i] != s[len-1-i]) palFlag=false;
            if (r(s[i]) != s[len-1-i]) mirFlag=false;
        }
        if (!palFlag) {
            if (!mirFlag){
                printf("%s -- is %s.\n\n", s, msg[0]);
            }else{
                printf("%s -- is %s.\n\n", s, msg[2]);
            }
        }
        else
        {
            if (!mirFlag){
                printf("%s -- is %s.\n\n", s, msg[1]);
            }else{
                printf("%s -- is %s.\n\n", s, msg[3]);
            }
        }
        

    }
    return 0;
}