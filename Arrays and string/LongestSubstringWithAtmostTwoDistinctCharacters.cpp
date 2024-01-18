#include<bits/stdc++.h>
using namespace std;

int TwoDistinctChars(string &str)
{
    unordered_map<int,int> mpp;
    int start=0;
    int end=0;
    int ans=0;
    while(end < str.size()){
        mpp[str[end]]++;
        while(mpp.size()>2){
            mpp[str[start]]--;
            if(mpp[str[start]]==0) mpp.erase(str[start]);
            start++;
        }
        ans=max(ans,end-start+1);
        end++;
    }
    return ans;
}


int main(){
    string input="abbbbbbc";
    assert(TwoDistinctChars(input)==7);
    input="abcddefg";
    assert(TwoDistinctChars(input)==3);
    input="aaaaaaaa";
    assert(TwoDistinctChars(input)==8);
    return 0;
}