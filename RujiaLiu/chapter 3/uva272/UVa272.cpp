# define LOCAL
# include<stdio.h>
int main(){
    #ifdef LOCAL
    freopen("UVa272input.txt", "r", stdin);
    freopen("UVa272output.txt", "w", stdout);
    #endif
        int c;
        int flag = 1;
        while ((c=getchar())!=EOF) {
            if (c=='"') {
                if (flag){
                    printf("%s", "``");
                    flag = 0;
                }else{
                    printf("%s", "''");
                    flag = 1;
                }
            }else{
                printf("%c", c);
            }
        }
        return 0;
}