// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    //freopen("input.txt" , "r" , stdin);
    int t;
    //cin >> t;
    map<int , int>mp1;
    map<int , int>mp2;
    set<int>input;
    set<int>::iterator it;
    scanf("%d",&t);
    while(t--){

        mp1.clear();
        mp2.clear();
        input.clear();
        int n1 , n2 , in;
        //cin >> n;
        scanf("%d %d",&n1,&n2);
        for(int i = 0 ;i<n1;i++){

            scanf("%d",&in);//cin >> in;
            mp1[in]++;
            input.insert(in);
        }

        for(int i=0;i<n2;i++){

            scanf("%d",&in);//cin >> in;
            mp2[in]++;
            input.insert(in);

        }

        int counter = 0;

        for(it = input.begin();it!=input.end();it++){

            if(mp1[*it]!=mp2[*it])counter+=abs(mp1[*it] - mp2[*it]);
        }

        //cout << counter << endl;
        printf("%d\n",counter);
    }

    return 0;
}
