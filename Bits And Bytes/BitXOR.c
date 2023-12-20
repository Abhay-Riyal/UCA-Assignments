#include <stdio.h>
#include <assert.h>

int BitXOR(int x,int y){
    return ((x&(~y))|(y&(~x)));
}

int main(){
    assert(BitXOR(4,5)==1);
    assert(BitXOR(5,5)==0);
    return 0;
}