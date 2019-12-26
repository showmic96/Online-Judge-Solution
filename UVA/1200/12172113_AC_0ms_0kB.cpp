// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int convert(string ar , int si)
{
    if(ar=="x")return 1;
    int ans = 0;
    for(int i=0;i<=si;i++){

        ans*=10;
        ans+=ar[i]-'0';
    }

    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;

        string s1 = "" , s2 = "";
        int si = ar.size() , i = 0;
        for(i=0;i<si;i++){

            if(ar[i]=='='){

                s1+='+';
                i++;
                break;
            }

            s1+=ar[i];
        }

        for(;i<si;i++){

            s2+=ar[i];
        }

        s2+='+';

        si = s1.size();

        int la = 0 , lb = 0 , ra = 0 , rb = 0;

        string temp = "";
        char last = '+';
        if(s1[0]=='-')last = '-';
        for(i=0;i<si;i++){

            if(s1[i]=='+'||s1[i]=='-'){

                if(temp[temp.size()-1]=='x'){

                    if(last=='+')la+=convert(temp , temp.size()-2);
                    else la-=convert(temp , temp.size()-2);
                }

                else{

                    if(last=='+')lb+=convert(temp , temp.size()-1);
                    else lb-=convert(temp , temp.size()-1);
                }

                temp = "";
                last = s1[i];
            }

            else{

                temp+=s1[i];
            }
        }

        last = '+';
        if(s2[0]=='-')last = '-';
        si = s2.size();
        temp = "";

        for(i=0;i<si;i++){

            if(s2[i]=='+'||s2[i]=='-'){

                if(temp[temp.size()-1]=='x'){

                    if(last=='+')ra+=convert(temp , temp.size()-2);
                    else ra-=convert(temp , temp.size()-2);
                }

                else{

                    if(last=='+')rb+=convert(temp , temp.size()-1);
                    else rb-=convert(temp , temp.size()-1);
                }

                last = s2[i];

                temp = "";
            }

            else{

                temp+=s2[i];
            }
        }

        if(la==ra&&rb==lb)cout << "IDENTITY" << endl;
        else if(la==ra&&lb!=rb)cout << "IMPOSSIBLE" << endl;
        else cout << (int)floor((double)(lb-rb)/(ra-la)) << endl;
    }
    return 0;
}
