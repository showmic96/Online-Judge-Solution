// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n , m , ar[1234567];

bool is_possible(ll c)
{
    ll c_temp = c;
    ll m_temp = m;

    for(int i=0;i<=n;i++){

        if(ar[i]>c_temp){

            c_temp = c;
            m_temp--;
            i--;

            if(m_temp<0)return false;
        }

        else c_temp-=ar[i];
    }

    if(m_temp<0)return false;

    return true;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        scanf("%lld %lld",&n , &m);

        for(int j=0;j<=n;j++)scanf("%lld",&ar[j]);

        int q = 200;

        ll hi = 1e9 , low = 1 , mid , ans = 0;

        while(q--){

            mid = (hi+low)/2;

            if(is_possible(mid)==true){

                hi = mid-1;
                ans = mid;
            }

            else low = mid+1;
        }

        printf("Case %d: %lld\n",i+1 , ans);

        ll sum = 0;
        queue<ll>f;

        for(int j=0;j<=n;j++){

            f.push(ar[j]);
        }

        if(sum>0)f.push(sum);//printf("%lld\n",sum);
        int temp1 , temp2;
        vector<ll>fin;
        sum = 0;
        //cout << f.size() << " " << m << endl;
        while(f.size()<m+1)f.push(0);
        while(true){

            //cout << f.size() << " " << fin.size() << " " << m << endl;

            if(f.size()+fin.size()==m&&sum>0){

                fin.push_back(sum);
                break;
            }

            if(sum+f.front()>ans){

                fin.push_back(sum);
                if(f.size()+fin.size()==m+1)break;
                sum = 0;
            }

            else {sum+=f.front();f.pop();}
        }

        while(f.empty()==false){
//cout << f.front() << endl;
            fin.push_back(f.front());
            f.pop();
        }

        if(sum>0)fin.push_back(sum);

        for(int j=0;j<=m;j++)printf("%lld\n",fin[j]);
    }
    return 0;
}
