/*Bai toan nguoi du lich */
#include<bits/stdc++.h>

using namespace std;

#define MAX 20 //n max
#define MAXCOST 10000 

int n, m;
int c[MAX][MAX]; //mang 2 chieu bieu dien gia tri de bai
int x[MAX + 1]; //thu cac kha nang
int t[MAX + 1];//chi phi khi den thanh pho thu i
int bestW[MAX + 1]; //mang dap an 
int minCost = MAXCOST;//config
bool a[MAX + 1]; //danh dau tp da di qua chua

void printResult() {
    for (int i = 1; i <=n ;++i) {
        cout << bestW[i] << "->";
    }
    cout << "1\nMin Cost: "<<minCost<<"\n";
}

void trySolve(int i) {
    for (int j = 2; j <= n;++j) {
        if(a[j]) { //tp chua di qua
            x[i] = j;
            t[i] = t[i - 1] + c[x[i - 1]][j]; //cost luc nay
            if(t[i] < minCost) { //hi vong tim dc config tot hon
                if(i < n) {
                    a[j] = false;
                    trySolve(i + 1);
                    a[j] = true;
                }
                else {
                    if(t[n]+c[x[n]][1] < minCost) {
                        for (int k = 1; k <= n;++k)
                            bestW[k] = x[k];            //cap nhat best way
                        minCost = t[n] + c[x[n]][1]; //cap nhat best config
                    }
                    
                }
            }
        }
        
    }
}
int main() {

    cin >> n >> m;

    for (int i = 1; i <= n;++i) 
        for (int j = 1; j <= n;++j) {
            if(i == j)
                c[i][j] = 0;
            else 
                c[i][j] = MAXCOST;
        }
            

    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        c[x][y] = c[y][x] = z;
    }
    
    for (int i = 1; i <= MAX+1;++i) {
        a[i] = true;
    }
    x[1] = 1;
    t[1] = 0;
    a[1] = false;
    trySolve(2);
    printResult();
    system("pause");
    return 0;
}