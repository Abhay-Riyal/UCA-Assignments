#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int start=0;
    int end=height.size()-1;
    int maxWater=0;
    while(start < end){
        int current=(end-start)*min(height[end],height[start]);
        maxWater=max(maxWater,current);
        if(height[start] < height[end]){
            start++;
        }else{
            end--;
        }
    }
    return maxWater;
}


int main(){
    vector<int> input({1,8,6,2,5,4,8,3,7});
    assert(maxArea(input)==49);
    return 0;
}