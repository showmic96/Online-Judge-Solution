// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n , m;
        cin >> n >> m;

        if(n%2==0&&m%2==1)cout << -1 << endl;
        else if(m>9*n)cout << -1 << endl;
        else if(m==1&&n>1)cout << -1 << endl;
        else{

            int ar[10] , counter = 0;
            memset(ar , 0 , sizeof(ar));
            for(int i=9;i>=1;i--){

                if(n-counter<2)break;
                ar[i]+=m/(2*i);
                m = m%(2*i);
                counter+=2*ar[i];
            }

            if(m>0){

                counter++;
            }
            ar[0] = (n-counter)/2;

            for(int i=9;i>=0;i--){

                for(int j=0;j<ar[i];j++)cout << i;
            }

            if(n%2==1)cout << m;
            for(int i=0;i<=9;i++){

                for(int j=0;j<ar[i];j++)cout << i;
            }

            cout << endl;
        }
    }
    return 0;
}
