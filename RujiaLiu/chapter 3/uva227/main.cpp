# define LOCAL
#include <string>
#include <iostream>
using namespace std;

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    char c;
    string input;
    char board[5][5];
    int x, y;
    int kase = 0;
    while (getline(cin, input)){
        if (input=="Z") break;
        if(kase>0){
            cout << endl;
        }
        kase +=1;

        for (int i=0; i<5; i+=1){
            board[0][i]=input[i];
        }
        for (int i=1; i<5; i+=1){
            getline(cin, input);
            for (int j=0; j<5; j+=1){
                board[i][j]=input[j];
            }
        }
        for (int i=0; i<5; i+=1){
            for (int j=0; j<5; j+=1){
                if (board[i][j]==' '){
                    x = i;
                    y = j;
                }
            }
        }
        bool illegal = false;
        while (cin>>c){
            if (c=='0') break;
            if (illegal) continue;
            if (c=='A'){
                int new_x = x-1;
                int new_y = y;
                if (new_x>=0){
                    board[x][y]=board[new_x][new_y];
                    board[new_x][new_y] = ' ';
                    x = new_x;
                    y = new_y;
                }else{
                    illegal=true;
                }                          
            }else if(c=='B'){
                int new_x = x+1;
                int new_y = y;
                if (new_x<5){
                    board[x][y]=board[new_x][new_y];
                    board[new_x][new_y] = ' ';
                    x = new_x;
                    y = new_y;
                }else{
                    illegal=true;
                }                 
            }else if(c=='L'){
                int new_x = x;
                int new_y = y-1;
                if (new_y>=0){
                    board[x][y]=board[new_x][new_y];
                    board[new_x][new_y] = ' ';
                    x = new_x;
                    y = new_y;
                }else{
                    illegal=true;
                }      
            }else if(c=='R'){
                int new_x = x;
                int new_y = y+1;
                if (new_y<5){
                    board[x][y]=board[new_x][new_y];
                    board[new_x][new_y] = ' ';
                    x = new_x;
                    y = new_y;
                }else{
                    illegal=true;
                }      
            }else{
                illegal=true;
            }
        }
        cin.ignore(100, '\n');
        cout << "Puzzle #" << kase << ":" << endl;
        if (illegal) {
            cout << "This puzzle has no final configuration." << endl;
            continue;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << board[i][j];
                if (j!=4) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}