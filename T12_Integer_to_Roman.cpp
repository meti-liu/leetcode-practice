#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
1    I
4    IV
5    V
9    IX
10   X
40   XL
50   L
90   XC
100  C
400  CD
500  D
900  CM
1000 M
*/
bool in(int low,int high,int num)
{
    if(num<high&& num>=low) return true;
    else return false;
}

vector<int> a={1,4,5,9,10,40,50,90,100,400,500,900,1000};
unordered_map <int,string> map=
{
    {1,"I"},
    {4,"IV"},
    {5,"V"},
    {9,"IX"},
    {10,"X"},
    {40,"XL"},
    {50,"L"},
    {90,"XC"},
    {100,"C"},
    {400,"CD"},
    {500,"D"},
    {900,"CM"},
    {1000,"M"}
};
int main()
{
    int num;
    cin>>num;
    int i=0;
    string s;
    while(num>0)
    {
        while(num>=1000)
        {
            s+="M";
            num-=1000;
        }
        for(int i=a.size()-2;i>=0;i--)
        {
            while(in(a[i],a[i+1],num))
            {
                s+=map[a[i]];
                num-=a[i];
            }
        }

        // while(in(900,1000,num))
        // {
        //     s+="CM";
        //     num-=900;
        // }
        // while(in(500,900,num))
        // {
        //     s+="D";
        //     num-=500;
        // }
        // while(in(400,500,num))
        // {
        //     s+="CD";
        //     num-=400;
        // }
        // while(in(100,400,num))
        // {
        //     s+="C";
        //     num-=100;
        // }
        // while(in(90,100,num))
        // {
        //     s+="XC";
        //     num-=90;
        // }
        //  while(in(50,90,num))
        // {
        //     s+="L";
        //     num-=50;
        // }
        //  while(in(40,50,num))
        // {
        //     s+="XL";
        //     num-=40;
        // }
        // while(in(10,40,num))
        // {
        //     s+="X";
        //     num-=10;
        // }
        // while(in(9,10,num))
        // {
        //     s+="IX";
        //     num-=9;
        // }
        // while(in(5,9,num))
        // {
        //     s+="V";
        //     num-=5;
        // }
        // while(in(4,5,num))
        // {
        //     s+="IV";
        //     num-=4;
        // }
        // while(in(1,4,num))
        // {
        //     s+="I";
        //     num-=1;
        // }
    }
    cout<<s;
    return 0;
}