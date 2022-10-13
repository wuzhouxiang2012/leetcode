# define LOCAL
# include<stdio.h>
# include<string.h>
# define maxn 105

int less(const char * s, int p, int q){
    int n = strlen(s);
    for (int i=0; i<n; i+=1){
        if (s[(p+i)%n] != s[(q+i)%n]){
            return s[(p+i)%n]<s[(q+i)%n];
        }
    }
    return 0;
}
int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int test_num;
    scanf("%d", &test_num);
    for (int i=0; i<test_num; i+=1){
        char s[maxn];
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for (int i=1; i<n; i+=1){
            if (less(s, i, ans)){
                ans = i;
            }
        }
        for (int i=0; i<n; i+=1){
            putchar(s[(i+ans)%n]);
        }
        putchar('\n');
    }
    return 0;
}