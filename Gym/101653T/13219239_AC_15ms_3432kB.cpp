// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool taken[10];

bool ck(ll x1 , ll x2 , ll x3 , char x)
{
    if(x=='+')return (x1+x2==x3);
    if(x=='-')return (x1-x2==x3);
    if(x=='*')return (x1*x2==x3);
}

ll f(string ar)
{
    ll temp = 0;

    for(int i=0;i<ar.size();i++){

        temp*=10;
        temp+=ar[i]-'0';
    }

    return temp;
}

void print_ans(string t1 , string t2 , string t3 , char x)
{
    for(int i=0;i<=9;i++){

        if(taken[i]==true)continue;

        bool check = true;

        string s1 = "" , s2 = "" , s3 = "";

        bool c = false;

        for(int j=0;j<t1.size();j++){

            if(t1[j]=='-')continue;

            if(t1[j]=='?'){

                if(i==0&&c==false){

                    if(t1.size()==1)s1+='0';
                    else check = false;
                }
                else s1+=i+'0';
            }

            else s1+=t1[j];
            c = true;
        }

        c = false;

        for(int j=0;j<t2.size();j++){

            if(t2[j]=='-')continue;

            if(t2[j]=='?'){

                if(i==0&&c==false){

                    if(t2.size()==1)s2+='0';
                    else check = false;
                }
                else s2+=i+'0';
            }

            else s2+=t2[j];
            c = true;
        }

        c = false;

        for(int j=0;j<t3.size();j++){

            if(t3[j]=='-')continue;

            if(t3[j]=='?'){

                if(i==0&&c==false){

                    if(t3.size()==1)s3+='0';
                    else check = false;
                }
                else s3+=i+'0';
            }

            else s3+=t3[j];
            c = true;
        }

        if(check==false)continue;

        ll x1 = f(s1);
        if(t1[0]=='-')x1*=-1;
        ll x2 = f(s2);
        if(t2[0]=='-')x2*=-1;
        ll x3 = f(s3);
        if(t3[0]=='-')x3*=-1;

        if(ck(x1 , x2 , x3 , x)){

            cout << i << endl;
            return ;
        }
    }

    cout << -1 << endl;
    return ;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string ar;
        cin >> ar;

        int i=0;

        string t1 = "" , t2 = "" , t3 = "";
        char x;

        t1+=ar[i];

        for(i++;i<ar.size();i++){

            if(ar[i]=='*'||ar[i]=='-'||ar[i]=='+'){

                x = ar[i];
                i++;
                break;
            }

            t1+=ar[i];
        }

        t2+=ar[i];

        for(i++;i<ar.size();i++){

            if(ar[i]=='='){

                i++;
                break;
            }

            t2+=ar[i];
        }

        for(;i<ar.size();i++){

            t3+=ar[i];
        }

        memset(taken , false , sizeof(taken));

        for(int j=0;j<t1.size();j++){

            if(t1[j]>='0'&&t1[j]<='9'){

                taken[t1[j]-'0'] = true;
            }
        }

        for(int j=0;j<t2.size();j++){

            if(t2[j]>='0'&&t2[j]<='9'){

                taken[t2[j]-'0'] = true;
            }
        }

        for(int j=0;j<t3.size();j++){

            if(t3[j]>='0'&&t3[j]<='9'){

                taken[t3[j]-'0'] = true;
            }
        }

        print_ans(t1 , t2 , t3 , x);
    }

    return 0;
}
