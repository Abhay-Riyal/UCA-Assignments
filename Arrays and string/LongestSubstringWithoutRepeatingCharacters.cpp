#include <bits/stdc++.h>
#include<assert.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<int,int> mpp;
    int start=0;
    int end=0;
    int ans=0;
    while(end < s.size()){
        mpp[s[end]]++;
        if(mpp[s[end]]>1){
            while(mpp[s[end]]>1){
                mpp[s[start]]--;
                start++;
            }
        }
        ans=max(ans,end-start+1);
        end++;
    }
    return ans;
}

int main(){
    string input="abcabcbb";
    assert(lengthOfLongestSubstring(input)==3);
    input="bbbbb";
    assert(lengthOfLongestSubstring(input)==1);
    input="pwwkew";
    assert(lengthOfLongestSubstring(input)==3);
    return 0;
}
