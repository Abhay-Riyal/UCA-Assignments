#include <stdio.h>
#include <assert.h>

int sign(int x){
    return ((x >> 31) & ~0) | (!!x);
}

int main(){
    assert(sign(4)==1);
    assert(sign(-20)==-1);
    return 0;
}