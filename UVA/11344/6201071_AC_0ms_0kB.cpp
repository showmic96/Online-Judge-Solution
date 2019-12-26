#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool devide_two(char ar[],int si)
{
    if(ar[si-1]=='0'||ar[si-1]=='2'||ar[si-1]=='4'||ar[si-1]=='6'||ar[si-1]=='8')return true;
    return false;
}

bool devide_three(char ar[],int si)
{
    ll a=0;
    for(int b=0;b<si;b++){

        if(ar[b]=='0')a+=0;
        if(ar[b]=='1')a+=1;
        if(ar[b]=='2')a+=2;
        if(ar[b]=='3')a+=3;
        if(ar[b]=='4')a+=4;
        if(ar[b]=='5')a+=5;
        if(ar[b]=='6')a+=6;
        if(ar[b]=='7')a+=7;
        if(ar[b]=='8')a+=8;
        if(ar[b]=='9')a+=9;
    }
    if(a%3==0)return true;
    else return false;
}

bool devide_four(char ar[],int si)
{
    char fr[3];
    if(si-2>=0)fr[0]=ar[si-2];
    else fr[0]='0';
    if(si-1>=0)fr[1]=ar[si-1];
    else fr[1]='0';
    fr[2]='\0';
    int a = atoi(fr);
    if(a%4==0)return true;
    else return false;

}

bool devide_five(char ar[],int si)
{
    if(ar[si-1]=='5'||ar[si-1]=='0')return true;
    return false;
}


bool devide_six(char ar[],int si)

{
    if(devide_two(ar,si)==true&&devide_three(ar,si)==true)return true;
    return false;
}
bool devide_seven(char ar[],int si)
{

    int a = si;
    int temp;
    long long j=0;
    for(int b=0;b<a;b+=6){

        if(b<a){
            if(ar[b]=='0')temp=0;
            if(ar[b]=='1')temp=1;
            if(ar[b]=='2')temp=2;
            if(ar[b]=='3')temp=3;
            if(ar[b]=='4')temp=4;
            if(ar[b]=='5')temp=5;
            if(ar[b]=='6')temp=6;
            if(ar[b]=='7')temp=7;
            if(ar[b]=='8')temp=8;
            if(ar[b]=='9')temp=9;
            j-=(temp*2);
        }
        if(b+1<a){
            if(ar[b+1]=='0')temp=0;
            if(ar[b+1]=='1')temp=1;
            if(ar[b+1]=='2')temp=2;
            if(ar[b+1]=='3')temp=3;
            if(ar[b+1]=='4')temp=4;
            if(ar[b+1]=='5')temp=5;
            if(ar[b+1]=='6')temp=6;
            if(ar[b+1]=='7')temp=7;
            if(ar[b+1]=='8')temp=8;
            if(ar[b+1]=='9')temp=9;
            j-=(temp*3);
        }
        if(b+2<a){
            if(ar[b+2]=='0')temp=0;
            if(ar[b+2]=='1')temp=1;
            if(ar[b+2]=='2')temp=2;
            if(ar[b+2]=='3')temp=3;
            if(ar[b+2]=='4')temp=4;
            if(ar[b+2]=='5')temp=5;
            if(ar[b+2]=='6')temp=6;
            if(ar[b+2]=='7')temp=7;
            if(ar[b+2]=='8')temp=8;
            if(ar[b+2]=='9')temp=9;
            j-=(temp);
        }
        if(b+3<a){
            if(ar[b+3]=='0')temp=0;
            if(ar[b+3]=='1')temp=1;
            if(ar[b+3]=='2')temp=2;
            if(ar[b+3]=='3')temp=3;
            if(ar[b+3]=='4')temp=4;
            if(ar[b+3]=='5')temp=5;
            if(ar[b+3]=='6')temp=6;
            if(ar[b+3]=='7')temp=7;
            if(ar[b+3]=='8')temp=8;
            if(ar[b+3]=='9')temp=9;
            j+=(temp*2);
        }
        if(b+4<a){
            if(ar[b+4]=='0')temp=0;
            if(ar[b+4]=='1')temp=1;
            if(ar[b+4]=='2')temp=2;
            if(ar[b+4]=='3')temp=3;
            if(ar[b+4]=='4')temp=4;
            if(ar[b+4]=='5')temp=5;
            if(ar[b+4]=='6')temp=6;
            if(ar[b+4]=='7')temp=7;
            if(ar[b+4]=='8')temp=8;
            if(ar[b+4]=='9')temp=9;
            j+=(temp*3);
        }
        if(b+5<a){
            if(ar[b+5]=='0')temp=0;
            if(ar[b+5]=='1')temp=1;
            if(ar[b+5]=='2')temp=2;
            if(ar[b+5]=='3')temp=3;
            if(ar[b+5]=='4')temp=4;
            if(ar[b+5]=='5')temp=5;
            if(ar[b+5]=='6')temp=6;
            if(ar[b+5]=='7')temp=7;
            if(ar[b+5]=='8')temp=8;
            if(ar[b+5]=='9')temp=9;
            j+=(temp);
        }
    }
    if(j%7==0)return true;
    else return false;
}

bool devide_eight(char ar[],int si)

{
    char fr[4];
    if(si-3>=0)fr[0]=ar[si-3];
    else fr[0]='0';
    if(si-2>=0)fr[1]=ar[si-2];
    else fr[1]='0';
    if(si-1>=0)fr[2]=ar[si-1];
    //fr[2]='\0';
    fr[3]='\0';
    int a = atoi(fr);
    if(a%8==0)return true;
    else return false;

}
bool devide_nine(char ar[],int si)
{
    ll a=0;
    for(int b=0;b<si;b++){

        if(ar[b]=='0')a+=0;
        if(ar[b]=='1')a+=1;
        if(ar[b]=='2')a+=2;
        if(ar[b]=='3')a+=3;
        if(ar[b]=='4')a+=4;
        if(ar[b]=='5')a+=5;
        if(ar[b]=='6')a+=6;
        if(ar[b]=='7')a+=7;
        if(ar[b]=='8')a+=8;
        if(ar[b]=='9')a+=9;
    }
    if(a%9==0)return true;
    else return false;

}
bool devide_ten(char ar[],int si)
{
    if(ar[si-1]=='0')return true;
    else return false;
}
bool devide_eleven(char ar[],int si)
{

    ll a=0 , k =0;
    for(int b=0;b<si;b++){

        if(ar[b]=='0')a=0;
        if(ar[b]=='1')a=1;
        if(ar[b]=='2')a=2;
        if(ar[b]=='3')a=3;
        if(ar[b]=='4')a=4;
        if(ar[b]=='5')a=5;
        if(ar[b]=='6')a=6;
        if(ar[b]=='7')a=7;
        if(ar[b]=='8')a=8;
        if(ar[b]=='9')a=9;
        if((b+1)%2!=0)k+=a;
        else k-=a;
    }
    if(k%11==0)return true;
    else return false;

}
bool devide_twelve(char ar[],int si)
{
    if(devide_three(ar,si)==true&&devide_four(ar,si)==true)return true;
    else return false;
}

int main(void)
{
    /*char ar[1000];
    while(gets(ar)){

        int si = strlen(ar);
        if(devide_two(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_three(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_four(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_five(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_six(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_seven(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_eight(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_nine(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_ten(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_eleven(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
        if(devide_twelve(ar,si)==true)cout << "YES" << endl;
        else cout << "NO" << endl;
    }*/

    int a;
    cin >> a;
    char ar[1000];
    while(a--){
        scanf("\n");

        gets(ar);
        int j , in;
        int x = strlen(ar);
        scanf("\n");
        cin >> j;
        int k =0;
        for(int i=0;i<j;i++){
             cin >> in;
            if(in==1){k++;continue;}
            else if(in==2){
                if(devide_two(ar,x)==true)k++;
                continue;
            }
            else if(in==3){
                if(devide_three(ar,x)==true)k++;
                continue;
            }
            else if(in==4){
                if(devide_four(ar,x)==true)k++;
                continue;
            }
            else if(in==5){
                if(devide_five(ar,x)==true)k++;
                continue;
            }
            else if(in==6){
                if(devide_six(ar,x)==true)k++;
                continue;
            }
            else if(in==7){
                if(devide_seven(ar,x)==true)k++;
                continue;
            }
            else if(in==8){
                if(devide_eight(ar,x)==true)k++;
                continue;
            }
            else if(in==9){
                if(devide_nine(ar,x)==true)k++;
                continue;
            }
            else if(in==10){
                if(devide_ten(ar,x)==true)k++;
                continue;
            }
            else if(in==11){
                if(devide_eleven(ar,x)==true)k++;
                continue;
            }
            else if(in==12){
                if(devide_twelve(ar,x)==true)k++;
                continue;
            }
        }
        //cout << j << " " << k << endl;
        if(j==k)cout << ar << " - " << "Wonderful." << endl;
        else cout << ar << " - " << "Simple." << endl;
    }

    return 0;
}
