# define LOCAL
# include<stdio.h>
# include<string.h>
# include<ctype.h>
double C=12.01;
double H=1.008;
double O=16.00;
double N=14.01;
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
        double prev_c = 0;
        int prev_n = 0;
        double ans = 0;
        for (int i=0; i<strlen(s); i++){
            if (isdigit(s[i])){
                prev_n *=10;
                prev_n += (int(s[i])-int('0'));
            }else{
                if (prev_n==0){
                    prev_n = 1;
                }
                ans += prev_c*prev_n;
                if (s[i]=='C'){
                    prev_c = C;
                }else if (s[i]=='H')
                {
                    prev_c = H;
                }else if(s[i]=='N'){
                    prev_c = N;
                }else{
                    prev_c = O;
                }
                prev_n = 0;
            }
        }
        if (prev_n==0){
            prev_n = 1;
        }
        ans += prev_c*prev_n;
        printf("%.3f\n", ans);
    }
    
    return 0;
}