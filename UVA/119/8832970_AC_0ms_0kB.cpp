#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    string name;
    int donate;
    int get;

}data[123456];

int main(void)
{
    int n;
    bool space = false;
    while(cin >> n){

        if(space)cout << endl;
        space = true;
        map<string , int>mp;

        for(int i=0;i<n;i++){
            string ar;
            cin >> ar;

            mp[ar] = i+1;
            data[i+1].name = ar;
            data[i+1].donate = 0;
            data[i+1].get = 0;
        }

        for(int i=0;i<n;i++){

            string name;
            cin >> name;
            int hm , amount;

            cin >> amount >> hm;

            int n = mp[name];
            //if(amount==0)continue;
            if(hm==0)continue;
            amount/=hm;
            amount*=hm;

            data[n].donate+=amount;

            for(int j=0;j<hm;j++){

                string temp;
                cin >> temp;
                if(amount==0)continue;
                data[mp[temp]].get+=(amount/hm);
            }
        }

        for(int i=1;i<=n;i++){

            cout << data[i].name << " " << -data[i].donate + data[i].get << endl;

        }


    }
    return 0;
}
