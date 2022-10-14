# define LOCAL
# include<stdio.h>
# include<string.h>
# define maxn 80
char s[maxn+5];
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
        for (int i=1; i<=strlen(s); i+=1){
            if (strlen(s)%i==0){
                bool flag = true;
                for(int j=i; j<strlen(s); j+=1){
                    if(s[j]!=s[j%i]){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    printf("%d\n", i);
                    break;
                }
            }
        }
        if (num_test!=0){
            printf("\n");
        }
    }
    return 0;
}