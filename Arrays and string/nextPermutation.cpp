#include<bits/stdc++.h>
using namespace std;

 void nextPermutation(vector<int>& nums) {
    int indx=-1,n=nums.size();
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            indx=i;
            break;
        }
    }
    if(indx==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i]>nums[indx]){
            swap(nums[i],nums[indx]);
            break;
        }
    }

    reverse(nums.begin()+indx+1,nums.end());

}

int main(){
    vector<int> input({1,2,3,2,4,3,1,0,0});
    nextPermutation(input);
    for(int& ele: input)cout<<ele<<" ";

    return 0;
}