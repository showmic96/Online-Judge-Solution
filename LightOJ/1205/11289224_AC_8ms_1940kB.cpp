// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[20][20][20][2][2] , si;

vector<int>v;
bool zero;

void make(ll x)
{
    v.clear();
    ll x_temp = x , rev = 1;
    while(x!=0){

        if(x%10==0)zero = false;
        v.push_back(x%10);
        x/=10;
    }

    if(v.size()==0)v.push_back(0);

    reverse(v.begin() , v.end());
}

ll f(int i , int j , int l , int smaller , int issmaller)
{
    if(i>j){

        if(smaller==0&&issmaller==0)return 1;
        if(issmaller==1&&smaller==0)return 0;
        return 1;

    }

    if(dp[i][j][l][smaller][issmaller]!=-1)return dp[i][j][l][smaller][issmaller];

    int lim = v[i];

    if(smaller==1)lim = 9;

    ll value = 0;

    for(int k=0;k<=lim;k++){

        if(k==0&&l==0)continue;

        if(k<lim){

            if(k<v[j]){

                //cout << "debug value : " << value << endl;
                value+=f(i+1 , j-1 , l+1 , 1 , 0);
                //cout << value << endl;
            }
            else if(k==v[j])value+=f(i+1 , j-1 , l+1 , 1 , issmaller);
            else value+=f(i+1 , j-1 , l+1 , 1 , 1);
        }

        else{

            if(k<v[j]){
                //cout << "debug value: " << value << endl;
                value+=f(i+1 , j-1 , l+1 , smaller , 0);
                //cout << value << endl;
            }
            else if(k==v[j])value+=f(i+1 , j-1 , l+1 , smaller , issmaller);
            else value+=f(i+1 , j-1 , l+1 , smaller , 1);
        }
    }

    return dp[i][j][l][smaller][issmaller] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 ,sizeof(dp));
        ll a , b;
        scanf("%lld %lld",&a , &b);

        if(a>b)swap(a , b);
        zero = true;
        make(a-1);

        si = v.size();

        ll ans1 = 0;

        for(int i=si-1;i>=0;i--){

            if(i==si-1)ans1+=f(0 , i , 0 , 0 , 0);
            else ans1+=f(0 , i , 0 , 1 , 0);
        }

        //ans1+=zero;

        memset(dp , -1 , sizeof(dp));
        zero = true;
        make(b);

        si = v.size();

        ll ans2 = 0;

        for(int i=si-1;i>=0;i--){

            if(i==si-1)ans2+=f(0 , i , 0 , 0 , 0);
            else ans2+=f(0 , i , 0 , 1 , 0);
        }

        if(a==0)ans2++;

        printf("Case %d: %lld\n",++c , ans2-ans1);
    }
    return 0;
}
