// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll k , a1, b1;
    cin >> k >> a1 >> b1;

    ll a[3][3] , b[3][3] , b2 = b1 , a2 = a1 , sa = 0 , sb = 0;

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            cin >> a[i][j];
        }
    }

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            cin >> b[i][j];
        }
    }

    ll counter = 0 , len;

    map<pair< ll , ll> , ll> mp;

    while(true){

        mp[make_pair(a1 , b1)] = counter;
        counter++;

        int t1 = a1-1 , t2 = b1-1;

        a1 = a[t1][t2];
        b1 = b[t1][t2];

        if(mp[make_pair(a1 ,b1)]!=0){

            len = counter - mp[make_pair(a1 , b1)];
            break;
        }
    }

    a1 = a2;
    b1 = b2;

    for(int i=0;i<counter-len;i++){

        if(a1!=b1){

            if(a1==1&&b1==2)sb++;
            if(a1==1&&b1==3)sa++;
            if(a1==2&&b1==3)sb++;
            if(a1==2&&b1==1)sa++;
            if(a1==3&&b1==1)sb++;
            if(a1==3&&b1==2)sa++;
        }

        int t1 = a1-1 , t2 = b1-1;

        a1 = a[t1][t2];
        b1 = b[t1][t2];
    }

    ll sat = 0 , sbt = 0;

    for(int i=0;i<len;i++){

        if(a1!=b1){

            if(a1==1&&b1==2)sbt++;
            if(a1==1&&b1==3)sat++;
            if(a1==2&&b1==3)sbt++;
            if(a1==2&&b1==1)sat++;
            if(a1==3&&b1==1)sbt++;
            if(a1==3&&b1==2)sat++;
        }
        int t1 = a1-1 , t2 = b1-1;
        a1 = a[t1][t2];
        b1 = b[t1][t2];
    }

    ll need = (k-(counter-len))/len;

    sa+=sat*need;
    sb+=sbt*need;

    int rem = k-(counter-len) - need*len;

    for(int i=0;i<rem;i++){

        if(a1!=b1){

            if(a1==1&&b1==2)sb++;
            if(a1==1&&b1==3)sa++;
            if(a1==2&&b1==3)sb++;
            if(a1==2&&b1==1)sa++;
            if(a1==3&&b1==1)sb++;
            if(a1==3&&b1==2)sa++;
        }

        int t1 = a1-1 , t2 = b1-1;

        a1 = a[t1][t2];
        b1 = b[t1][t2];
    }

    if(k>counter)cout << sa << " " << sb << endl;
    else{
        sa = 0 , sb =0;
        a1 = a2 , b1 = b2;
        for(int i=0;i<k;i++){

            if(a1!=b1){

                if(a1==1&&b1==2)sb++;
                if(a1==1&&b1==3)sa++;
                if(a1==2&&b1==3)sb++;
                if(a1==2&&b1==1)sa++;
                if(a1==3&&b1==1)sb++;
                if(a1==3&&b1==2)sa++;
            }

            int t1 = a1-1 , t2 = b1-1;

            a1 = a[t1][t2];
            b1 = b[t1][t2];
        }

        cout << sa << " " << sb << endl;
    }

    return 0;
}
