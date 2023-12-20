#include <stdio.h>
#include <assert.h>

int conditional(int x,int y,int z){
    int mask=!!x;
    mask=~mask+1;
    return (y & mask) | (z & mask);
}

int main(){
    assert(conditional(4,5,6)==5);
    assert(conditional(0,5,6)==6);
    return 0;
}