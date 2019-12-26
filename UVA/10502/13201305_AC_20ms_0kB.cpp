// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

string ar[101];
int ans[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m;

    while(cin >> n){

        if(!n)break;
        cin >> m;
        memset(ans , 0 , sizeof(ans));

        for(int i=0;i<n;i++)cin >> ar[i];

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(ar[i-1][j-1]=='1'){

                    ans[i][j] = 1;
                }

                ans[i][j]+=(ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]);
            }
        }

        int counter = 0;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                for(int k=i;k<=n;k++){

                    for(int l=j;l<=m;l++){

                        int temp = ans[k][l]+ans[i-1][j-1]-ans[i-1][l]-ans[k][j-1];

                        if(temp==(k-i+1)*(l-j+1))counter++;
                    }
                }
            }
        }

        printf("%d\n",counter);
    }

    return 0;
}
