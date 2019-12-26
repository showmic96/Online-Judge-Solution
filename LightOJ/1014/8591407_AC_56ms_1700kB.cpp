// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        ll p , l;

        scanf("%lld %lld",&p , &l);

        p-=l;

        ll lim = sqrt(p);

        vector<ll>data;

        for(int i=1;i<=lim;i++){

            if(p%i==0){

                if(i>l){

                    data.push_back(i);

                    if(i!=p/i&&p/i>l)data.push_back(p/i);
                }

                else if(p/i > l)data.push_back(p/i);

                else break;
            }
        }

        sort(data.begin() , data.end());

        int si = data.size();

        printf("Case %d: ",i+1);

        if(si==0)cout << "impossible" << endl;
        else{

            cout << data[0];

            for(int i=1;i<si;i++)cout << " " << data[i];

            cout << endl;
        }
    }
    return 0;
}
