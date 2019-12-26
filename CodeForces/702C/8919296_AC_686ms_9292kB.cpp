// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;
int n , m , in;


struct myStruct{

    ll value , d;
};

vector<myStruct>v;
vector<myStruct>v_temp;

bool cmp(myStruct A , myStruct B)
{
    return A.value < B.value;
}

bool is_possible(ll r)
{

    ll d = v_temp[0].d;
    ll last = v_temp[0].value + r;

    for(int i=1;i<n+m;i++){

        if(v_temp[i].value>last){

            d--;
            last = v_temp[i].value + r;

            if(d<0)return false;
        }

        if(v_temp[i].d==1){

            d = 1;
            last = v_temp[i].value + r;
        }
    }

    if(d==0)return false;

    return true;
}

int main(void)
{
    cin >> n >> m;
    myStruct temp;

    for(int i=0;i<n;i++){cin >> temp.value;temp.d = 0; v.push_back(temp);}
    for(int i=0;i<m;i++){cin >> temp.value;temp.d = 1 ;v.push_back(temp);}

    sort(v.begin() , v.end() , cmp);

    v_temp = v;

    ll hi = 1e12 , low = 0 , mid , t = 200 , ans;

    while(t--){

        mid = (hi+low)/2;

        if(is_possible(mid)==true){

            ans = mid;
            hi = mid-1;
        }

        else low = mid+1;
    }

    cout << ans << endl;


    return 0;
}
