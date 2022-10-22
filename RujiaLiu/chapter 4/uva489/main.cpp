# define LOCAL
# include<stdio.h>
# include<string.h>
# define maxn 1000
int left, chance;
char s[maxn], s2[maxn];
int win, loss;
void guess(char ch){
    int bad =1;
    for (int i=0; i<strlen(s); i++){
        if (s[i]==ch){
            bad = 0;
            s[i] = ' ';
            left -=1;
        }
    }
    if (bad){
        chance-=1;
    }
    if (!chance) loss=1;
    if (!left) win=1;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int rnd;
    while(scanf("%d%s%s", &rnd, s, s2)==3 && rnd != -1){
        win = loss = 0;
        printf("Round %d\n", rnd);
        left = strlen(s);
        chance = 7;
        for (int i=0; i<strlen(s2); i++){
            guess(s2[i]);
            if (win||loss){
                break;
            }
        }
        if (win) printf("You win.\n");
        else if(loss) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}