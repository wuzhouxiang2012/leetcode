# define LOCAL
# include<stdio.h>
# include<string.h>
char s[1000];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int num_test;
    scanf("%d", &num_test);
    while (num_test>0){
        num_test-=1;
        scanf("%s", s);
        int prev = 0;
        int ans = 0;
        for (int i=0; i<strlen(s); i++){
            if (s[i]=='O'){
                prev+=1;
            }else{
                prev = 0;
            }
            ans += prev;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}