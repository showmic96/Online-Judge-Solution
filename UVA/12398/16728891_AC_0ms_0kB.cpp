// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans[3][3];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c = 0;
    string ar;

    while(getline(cin , ar)){

        memset(ans , 0 , sizeof(ans));

        for(int i=0;i<ar.size();i++){

            if(ar[i]=='a'){

                ans[0][0]++;
                ans[0][1]++;
                ans[1][0]++;
            }
            else if(ar[i]=='b'){

                ans[0][1]++;
                ans[1][1]++;
                ans[0][0]++;
                ans[0][2]++;
            }
            else if(ar[i]=='c'){

                ans[0][2]++;
                ans[0][1]++;
                ans[1][2]++;
            }
            else if(ar[i]=='d'){

                ans[0][0]++;
                ans[1][0]++;
                ans[1][1]++;
                ans[2][0]++;
            }
            else if(ar[i]=='e'){

                ans[1][1]++;
                ans[1][0]++;
                ans[0][1]++;
                ans[1][2]++;
                ans[2][1]++;
            }
            else if(ar[i]=='f'){

                ans[1][2]++;
                ans[1][1]++;
                ans[2][2]++;
                ans[0][2]++;
            }
            else if(ar[i]=='g'){

                ans[2][0]++;
                ans[1][0]++;
                ans[2][1]++;
            }
            else if(ar[i]=='h'){

                ans[2][1]++;
                ans[2][0]++;
                ans[2][2]++;
                ans[1][1]++;
            }
            else{

                ans[2][1]++;
                ans[2][2]++;
                ans[1][2]++;
            }
        }
        cout << "Case #" << ++c << ":" << '\n';
        for(int i=0;i<3;i++){

            for(int j=0;j<3;j++){

                if(j>0)cout << " ";
                cout << ans[i][j]%10;
            }
            cout << endl;
        }
    }
    return 0;
}
