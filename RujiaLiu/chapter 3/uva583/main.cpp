# define LOCAL
# include<stdio.h>
# include<string.h>
# define maxn 100005

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int num_test;
    int ans[maxn];
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<maxn; i+=1){
        int x = i, y = i;
        while (x>0){
            y+=(x%10);
            x/=10;
        }
        if (y>=0 && y<maxn &&ans[y]==0){
            ans[y]=i;
        }
    }
    scanf("%d", &num_test);
    for(int i=0; i<num_test; i+=1){
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}