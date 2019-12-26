// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ar[19];
ll n , k;
vector<ll>first;
vector<ll>second;

void f(int i , int lim , ll value)
{
    if(i==lim){

        first.push_back(value);
        //cout << "second : " << value << endl;
        return ;
    }

    f(i+1 , lim , value);
    f(i+1 , lim , value + ar[i]);
    //f(i+1 , lim , value + ar[i]+ar[i]);
}

void f2(int i , int lim , ll value )
{
    if(i==lim){

        second.push_back(value);
        //cout << "first : " << value << endl;
        return ;
    }

    f2(i+1 , lim , value);
    f2(i+1 , lim , value + ar[i]);
    //f2(i+1 , lim , value + ar[i] + ar[i]);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        first.clear();
        second.clear();

        scanf("%lld %lld",&n , &k);
        for(int j=0;j<n;j++){

            scanf("%lld",&ar[j]);
        }

        f(0 , n/2 , 0);
        f2(n/2 , n , 0);

        int si = first.size();
        sort(second.begin(),second.end());
        int counter = 0;
        for(int j=0;j<si;j++){

            vector<ll>::iterator it = lower_bound(second.begin() , second.end() ,k-first[j]);
            vector<ll>::iterator it2 = upper_bound(second.begin() , second.end() ,k-first[j]);
            //cout << "DEBUG : " << *it << " " << k - first[j] << endl;
            //if(binary_search(second.begin() , second.end() , k-first[j])==true)counter++;
            counter+= (it - second.begin());
            counter+= (it2 - it);
        }

        printf("Case %d: %d\n",i+1 , counter);
    }
    return 0;
}
