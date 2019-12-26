// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    int counter;
    int fre;
}ans[10010];

bool is_alpha(char x)
{
    if(x>='A'&&x<='Z')return true;
    if(x>='a'&&x<='z')return true;

    return false;
}

bool cmp(myStruct A , myStruct B)
{
    if(A.fre==B.fre){

        return A.counter>B.counter;
    }

    return A.fre < B.fre;
}

void print(string ar)
{
    //cout << ar << endl;
    int si = ar.size();
    map<int,int>maping;

    string br="";

    int d = 1;

    for(int i=0;i<si;i++){

        if(ar[i]==' '||ar[i]==','||ar[i]=='?'||ar[i]=='!'||ar[i]=='.'){

            int s = br.size();
            if(s>0)if(maping[s]==0){

              maping[br.size()] = d;
              ans[d].fre = br.size();
              ans[d].counter = 0;
              d++;

            }

            ans[maping[br.size()]].counter++;

            br="";
        }

        else if(is_alpha(ar[i])==true)br+=ar[i];
        //hecout << br << endl;
    }

    sort(ans+1 , ans+d , cmp);

    for(int i=1;i<d;i++)cout << ans[i].fre << " " << ans[i].counter << endl;
    cout << endl;
}

int main(void)
{
    string ar , br="";
    bool check = false;
    while(getline(cin , ar)){

        if(ar[0]=='#'){print(br);br="";}
        br+=ar;
        if(ar[ar.size()-1]!='-')br+=" ";
    }

    return 0;
}
