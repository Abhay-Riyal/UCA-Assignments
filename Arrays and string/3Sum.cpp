#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> ans;
    sort(begin(nums),end(nums));
    for(int i=0;i<n-2;i++){
        int start=i+1;
        int end=n-1;
        while(start<end){
            int current=nums[i]+nums[start]+nums[end];
            if(current==0){
                ans.push_back({nums[i],nums[start],nums[end]});
                int tempStart=nums[start];
                int tempEnd=nums[end];
                while(start < end && nums[start]==tempStart)start++;
                while(start < end && nums[end]==tempEnd)end--;
            }else if(current > 0){
                end--;
            }else{
                start++;
            }
        }
        while(i<n-1 && nums[i]==nums[i+1])i++;
    }
    return ans;
}

int main(){
    vector<int> input({-1,0,1,2,-1,-4});
    vector<vector<int>> ans=threeSum(input);
    for(auto& vec: ans){
        for(int& ele: vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}