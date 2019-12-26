#include<bits/stdc++.h>
using namespace std;

map<string,int>isThere;
map<string,int>input;
int n , m;

string pure_string(string ar)
{
    int d = 0;
    string br="";
    int si = ar.size();
    for(int i=0;i<si;i++){

        if(ar[i]>='a'&&ar[i]<='z')br+=ar[i];
        else if(ar[i]>='A'&&ar[i]<='Z')br+=ar[i]+32;
        else{
            d = i;
            br+=' ';
            while(d<si){

                if(ar[d]>='a'&&ar[d]<='z'){d--;i=d;break;}
                if(ar[d]>='A'&&ar[d]<='Z'){d--;i=d;break;}
                d++;
            }
        }
    }

    return br;
}


int main(void)
{
    int counter = 0;

    while(cin >> n >> m){

        isThere.clear();
        input.clear();

        string ar , br[m+1];

        while(n--){

            cin >> ar;

            isThere[ar] = 1;
        }

        ar="";
        int hi = 0;
        //scanf("\n");
        for(int i=0;i<m;i++){

            scanf("\n");
            getline(cin , br[i]);

            ar = pure_string(br[i]);

            //cout << endl << ar << endl;

            stringstream ss(ar);

            while(ss >> ar){

                if(isThere[ar]==1){input[br[i]]++;if(input[br[i]]>hi)hi = input[br[i]];}
            }
        }

        printf("Excuse Set #%d\n",++counter);

        for(int i=0;i<m;i++){

            if(input[br[i]]==hi)cout << br[i] << endl;
        }
        cout << endl;
    }

    return 0;
}
