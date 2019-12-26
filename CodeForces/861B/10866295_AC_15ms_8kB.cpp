#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m;
    cin >> n >> m;

    int ar[110];
    memset(ar , 0 , sizeof(ar));

    vector<int>store;

    for(int i=0;i<m;i++){

        int in1 , in2;
        cin >> in1 >> in2;

        ar[in1] = in2;
    }

    int ans = 0 , counter = 0;

    for(int i=1;i<=100;i++){

        bool check = true;

        for(int j=1;j<=100;j++){

            if(ar[j]==0)continue;
            int t = (double)(1.00*ceil(1.00*j/i*1.00));

            if(ar[j]!=t){

                check = false;
                break;
            }
        }


        if(check==true){

            store.push_back(i);
            ans = i;
            counter++;
        }
    }

    ans = (int)ceil(1.00*n/store[0]);

    for(int i=1;i<store.size();i++){

        int temp = (int)ceil(1.00*n/store[i]);

        if(temp!=ans){

            ans = -1;
            break;

        }
    }

    if(counter==0)cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
