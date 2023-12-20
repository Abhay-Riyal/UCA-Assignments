#include <stdio.h>
#include <assert.h>

int BitAnd(int x,int y){
    return ~(~x|~y);
}

int main(){
    assert(BitAnd(6,5)==4);
    assert(BitAnd(5,5)==5);
    return 0;
}