#include <stdio.h>
#include <assert.h>

int bang(int x){
    return ((x|(~x+1))>>31)+1;
}

int main(){
    assert(bang(0)==1);
    assert(bang(1)==0);
    return 0;
}