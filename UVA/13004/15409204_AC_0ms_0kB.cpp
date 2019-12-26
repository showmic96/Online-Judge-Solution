// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll x;
    while(scanf("%lld",&x)==1){

        vector<int>v;

        ll x_temp = x;

        while(x_temp!=0){

            v.push_back(x_temp%10);
            x_temp/=10;
        }

        reverse(v.begin() ,v.end());

        int ar[10];
        memset(ar , 0 , sizeof(ar));

        int si = v.size();

        int idx = -1;

        for(int i=0;i<si;i++){

            ar[v[i]]++;

            if(ar[v[i]]>2){

                idx = i;
                break;
            }
        }

        if(idx==-1){

            printf("%lld\n",x);
        }

        else{

            int f = -1;

            for(int i=idx;i>=0;i--){
                int temp = v[i];
                while(v[i]!=0){
                    v[i]--;

                    if(ar[v[i]]<2){

                       f = i;
                       ar[v[i]]++;
                       //v[i]--;
                       break;
                    }
                }

                if(f==-1)v[i] = temp;
                if(f!=-1)break;
                ar[v[i]]--;

            }

            memset(ar , 0 , sizeof(ar));

            for(int i=0;i<=f;i++){
                    if(i==0){

                        if(v[0]==0)continue;
                    }
                    cout << v[i];
                    ar[v[i]]++;
            }

            for(int i=f+1;i<v.size();i++){

                for(int j=9;j>=0;j--){

                    if(ar[j]<2){

                        cout << j;
                        ar[j]++;
                        break;
                    }
                }
            }

            cout << endl;
        }
    }
    return 0;
}