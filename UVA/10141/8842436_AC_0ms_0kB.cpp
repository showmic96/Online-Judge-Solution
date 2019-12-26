// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    string name;
    int q;
    double value;

}data[123456];

bool cmp(struct myStruct A , struct myStruct B)
{

    if(A.q==B.q){

        return A.value < B.value;
    }

    return A.q > B.q;
}

int main(void)
{
    int c = 0;
    int n , m;
    while(cin >> n >> m){

        if(!n&&!m)break;
        //scanf("\n");
        if(c!=0)cout << endl;
        map<string , int>mp;
        map<string , int>mp2;
cin.ignore();
        for(int i=0;i<n;i++){
            //cin.ignore();
            string ar;
            getline(cin , ar);
            mp[ar] = 1;
        }

        for(int i=0;i<m;i++){

            string ar;
            getline(cin , ar);

            mp2[ar] = i+1;
            data[i+1].name = ar;

            int loop;

            cin >> data[i+1].value >> loop;
            data[i+1].q = loop;
            scanf("\n");
            for(int j=0;j<loop;j++){

                getline(cin , ar);

                //if(mp[ar]==1)data[i+1].q++;
            }

        }

        sort(data+1 , data+m+1 , cmp);
        printf("RFP #%d\n",++c);
        cout << data[1].name << endl;
    }
    return 0;
}
