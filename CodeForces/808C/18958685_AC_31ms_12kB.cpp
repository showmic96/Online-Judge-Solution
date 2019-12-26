// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct {

    int value , ans , idx;

}data[123];

bool cmp(myStruct A , myStruct B)
{
    return A.value > B.value;
}

bool cmp2(myStruct A , myStruct B)
{
    return A.idx < B.idx;
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    int n , w;
    cin >> n >> w;

    for(int i=1;i<=n;i++){cin >> data[i].value;data[i].idx = i;}

    int mx = 0;

    sort(data+1 , data+n+1 , cmp);

    for(int i=n;i>=1;i--){

        if(data[i].value%2==1){

            int temp = data[i].value/2 + 1;

            temp = max(mx , temp);

            data[i].ans = temp;
            w-=temp;

            mx = max(temp , mx);
        }

        else{

            int temp = data[i].value/2;

            temp = max(mx , temp);

            data[i].ans = temp;
            w-=temp;

            mx = max(temp ,  mx);
        }

        if(w<0){cout << -1 << endl;return 0;}
    }

    for(int i=1;i<=n;i++){

        if(data[i].value<data[i].ans){cout << -1 << endl;return 0;}
    }

    for(int i=1;i<=n;i++){

        if(w==0)break;
        while(data[i].value>data[i].ans){data[i].ans++;w--;if(w==0)break;}
    }

    for(int i=1;i<=n-1;i++){

        if(data[i].ans<data[i+1].ans){cout << -1 << endl;return 0;}
    }

    mx = data[1].ans;

    for(int i=1;i<=n;i++){

        if(mx<data[i].ans){cout << -1 << endl;return 0;}
        mx = min(mx , data[i].ans);
    }

    if(w!=0){cout << -1 << endl;return 0;}

    sort(data+1 , data+n+1 , cmp2);

    for(int i=1;i<=n;i++)cout << data[i].ans << " ";
    cout << endl;

    return 0;
}