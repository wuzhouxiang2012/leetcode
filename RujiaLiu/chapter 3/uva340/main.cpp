# define LOCAL
# include<stdio.h>
# include<algorithm>
# define maxn 1010
using namespace std;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, a[maxn], b[maxn];
    int kase = 0;
    while (scanf("%d", &n)==1 && n){ //end with n=0
        kase+=1;
        printf("Game %d:\n", kase);
        // read the ground truth in list a
        for(int i=0; i<n; i+=1){
            scanf("%d", &a[i]);
        }
        while (true){
            for (int i=0; i<n; i+=1){
                scanf("%d", &b[i]);
            }
            if (b[0]==0) break;
            int cntA[10], cntB[10];
            for (int i=0; i<10; i+=1){
                cntA[i]=0;
                cntB[i]=0;
            }
            int A=0, B=0;
            for (int i=0; i<n; i+=1){
                if(a[i]==b[i]) A+=1;
                cntA[a[i]]+=1;
                cntB[b[i]]+=1;
            }
            for (int i=0; i<10; i+=1){
                B+=(std::min(cntA[i], cntB[i]));
            }
            printf("    (%d,%d)\n", A, B-A);
        }
    }
    return 0;
}