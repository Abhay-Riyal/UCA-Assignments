#include <stdio.h>
#include <assert.h>

int getByte(int x,int n){
    return (x >> (n<<3))&255;
}

int main(){
    assert(getByte(0x12345678, 1)==0x56);
    assert(getByte(65535,1)==255);
    return 0;
}