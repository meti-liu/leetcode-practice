#include<string>
#include<algorithm>
using namespace std;


class Solution 
{
    //思路1，int转换成string，用一下string的工具
    //思路2，反转数字，和原数字比较
public:
    bool isPalindrome(int x) 
    {
        string s =to_string(x);
        string rev= s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};