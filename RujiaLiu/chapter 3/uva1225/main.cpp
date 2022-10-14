# define LOCAL
# include<stdio.h>
# include<string.h>
# include<ctype.h>
# define maxn 10001
char s[6];

int ans[maxn][10];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    memset(ans[0], 0, sizeof(ans[0]));
    for (int i=1; i<maxn; i+=1){
        int cur = i;
        memcpy(ans[i], ans[i-1], sizeof(ans[i]));
        while (cur>0){
            int digit = cur%10;
            cur = cur/10;
            ans[i][digit] +=1;
        }
    }
    int num_test;
    scanf("%d", &num_test);
    while (num_test>0){
        num_test-=1;
        int num;
        scanf("%d", &num);
        for (int i=0; i<9; i+=1){
            printf("%d ", ans[num][i]);
        }
        printf("%d\n", ans[num][9]);
    }
    
    return 0;
}