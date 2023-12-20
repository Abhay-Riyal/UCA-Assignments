#include <stdio.h>
#include <assert.h>

int shift(int x,int n){
    return (x>>n) & (~(~0 << (32 + (~n + 1))));
}

int main(){
    assert(shift(0x87654321, 4)==0x8765432);
    assert(shift(-1,31)==1);
    return 0;
}