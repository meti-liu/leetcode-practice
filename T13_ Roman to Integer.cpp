#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

/*需要考虑的点在于IV=4而不是1+5
实际上我们就从左往右扫描并且判断你右边那个数是否比你大
我们可以构造一个map吧试一试
*/

class Solution {
public:
    int romanToInt(string s) 
    {

        int ans=0;
        unordered_map<char,int> map=
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        if(s.size()==1) ans+=map[s[0]] ;
               //如果只有一个字符
        else
        {
            for(int i=0;i<s.size()-1;i++)
            {
                //char是key，int是value
                if(map[s[i]]<map[s[i+1]])
                {
                    ans+=map[s[i+1]]-map[s[i]];
                    i++;
                }
                else ans+=map[s[i]];
            }

            if(map[s[s.size()-1]]<=map[s[s.size()-2]]) ans+=map[s[s.size()-1]];
        }



        return ans;
    }
};

int main()
{
    Solution s;
    std::cout<<s.romanToInt("D");
    return 0;
}