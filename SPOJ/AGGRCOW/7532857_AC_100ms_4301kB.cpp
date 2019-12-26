// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000+7;

ll ar[MAX] , n ,m;

bool is_possible(ll a)
{
    ll counter = 1 , temp , pre = ar[0];

    for(ll i=0;i<n;){

        temp = 0;

        while(temp<a){

            temp=ar[i] - pre;

            if(temp>=a){pre = ar[i];counter++;}
            i++;
            if(i>=n)break;
        }


    }

    //cout << "COUNTER " << counter << endl;

    if(counter>=m)return true;

    return false;
}

int b_search()
{
    ll hi = ar[n-1] , low = 0 , mid , ans=0;
    //cout << hi << endl;
    while(hi>=low){

        mid = (hi+low)/2;

        if(is_possible(mid)==false){

            //cout << "HI " << mid << endl;
            hi = mid-1;


        }

        else{

            //cout << "LOW" << endl;

            low = mid+1;
            ans = max(mid , ans);
        }
    }

    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;

        for(int i=0;i<n;i++)cin >> ar[i];
        sort(ar , ar+n);

        cout << b_search() << endl;
    }
    return 0;
}
