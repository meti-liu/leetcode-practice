/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
这是一个回溯递归类型题目，经典设计一个多参数的递归函数处理
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindrome(string s)
{
    string s1=s;
    reverse(s.begin(),s.end());
    return s1==s;
}


void backtrack(const string &s,int start,vector<string> &path,vector<vector<string>> &ans)
{
    if(start==s.size())
    {
        ans.push_back(path);
        return;
    }

    for(int end=start+1;end<=s.size();end++)
    {
        if(isPalindrome(s.substr(start,end-start)))
        {
            path.push_back(s.substr(start,end-start));
            backtrack(s,end,path,ans);

            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) 
{
    vector<string> path;
    vector<vector<string>> ans;
    backtrack(s,0,path,ans);
    return ans;  
}




int main() 
{
    string s;
    cin >> s;
    vector<vector<string>> res = partition(s);
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < res[i].size(); ++j) {
            cout << '"' << res[i][j] << '"';
            if (j + 1 < res[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < res.size()) cout << ",";
    }
    cout << "]\n";
    return 0;
}