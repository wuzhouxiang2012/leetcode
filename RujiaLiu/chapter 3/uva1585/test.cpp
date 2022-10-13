# define LOCAL
# include<stdio.h>
# include<string.h>
# define maxn 
char s[1000];
int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int num_test;
    scanf("%d", &num_test);
    printf("%d num case", num_test);
    while (num_test>0){
        num_test-=1;
        scanf("%s", s);
        for (int i=0; i<strlen(s); i++){
            printf("%c", s[i]);
        }
        printf("\n");
    }
    
    return 0;
}