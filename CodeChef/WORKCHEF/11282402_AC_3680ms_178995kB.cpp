// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[20][(1<<9) + 5][2][504][2];
ll a , b , k , si;

vector<int>v;

int Set(int n, int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

void make(ll x)
{
    v.clear();

    while(x!=0){

        v.push_back(x%10);
        x/=10;
    }

    if(v.size()==0)v.push_back(0);

    reverse(v.begin() , v.end());
}

ll f(int i , int mask , int smaller , int mod , int last)
{
    if(i==si){

        int counter = 0;

        if(Check(mask , 0)==1)counter++;

        if(Check(mask , 1)==1){

            if(mod==0)counter++;
            else if(mod%2==0)counter++;
        }

        if(Check(mask, 2)==1){

            if(mod==0)counter++;
            else if(mod%3==0)counter++;
        }
        if(Check(mask, 3)==1){

            if(mod==0)counter++;
            else if(mod%4==0)counter++;
        }

        if(Check(mask, 4)==1){

            if(last==1)counter++;
        }

        if(Check(mask, 5)==1){

            if(mod==0)counter++;
            else if(mod%6==0)counter++;
        }

        if(Check(mask, 6)==1){

            if(mod==0)counter++;
            else if(mod%7==0)counter++;
        }

        if(Check(mask, 7)==1){

            if(mod==0)counter++;
            else if(mod%8==0)counter++;
        }

        if(Check(mask, 8)==1){

            if(mod==0)counter++;
            else if(mod%9==0)counter++;
        }
//cout << counter << " " << k << endl;
        if(counter>=k)return 1;
        return 0;
    }

    if(dp[i][mask][smaller][mod][last]!=-1)return dp[i][mask][smaller][mod][last];

    int lim = v[i];
    if(smaller==1)lim = 9;

    ll value = 0;

    for(int j=0;j<=lim;j++){

        int temp = mask;
        if(j!=0)temp = Set(temp , j-1);
        if(j<lim){

            if(j==5||j==0)value+=f(i+1 , temp , 1 , ((mod*10)+j)%504 , 1);
            else value+=f(i+1 , temp , 1 , ((mod*10)+j)%504 , 0);
        }
        else{

            if(j==5||j==0)value+=f(i+1 , temp , smaller , ((mod*10)+j)%504 , 1);
            else value+=f(i+1 , temp , smaller , ((mod*10)+j)%504 , 0);
        }
    }

    return dp[i][mask][smaller][mod][last] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        scanf("%lld %lld %lld",&a , &b , &k);

        make(a-1);

        si = v.size();
//cout << v[0] << v[1] << endl;
        memset(dp , -1 , sizeof(dp));

        ll ans1 = f(0 , 0 , 0 , 0 , 0);

        make(b);
//cout << v[0] << v[1] << endl;
        si = v.size();

        memset(dp , -1 , sizeof(dp));

        ll ans2 = f(0 , 0 , 0 , 0 , 0);
//cout << ans1 << " " << ans2 << endl;
        printf("%lld\n",ans2-ans1);
    }

    return 0;
}
