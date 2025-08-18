/*
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
是一个动态规划DP问题
*/
#include<iostream>
#include<vector>
#include <string>
int a[30][30]={0};
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i][0]=1;
        a[0][i]=1;
    }
    for(int i=1;i<n;i++)
    for(int j=1;i+j<n;j++) a[i][j]=a[i-1][j]+a[i][j-1];
    

    string s;
    s+="[";
    for(int i=0;i<n;i++)
    {
        
        s+="[";
        for(int j=0;j<=i;j++)
        {
            s+=to_string(a[j][i-j]);
            if(j!=i) s+=",";
        }
        s+="]";
        if(i!=n-1) s+=",";
    }
    s+="]";
    cout<<s;
    return 0;
}