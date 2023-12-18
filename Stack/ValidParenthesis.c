#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isValid(char* p) {
    char stack[10000];
    int top=-1;

    while(*p){
        if(*p=='[' || *p=='{' || *p=='('){
            stack[++top]=*p;
        }else if(*p==']'){
            if(top==-1 || stack[top]!='['){
                return false;
            }else{
                top--;
            }
        }else if(*p=='}'){
            if(top==-1 || stack[top]!='{'){
                return false;
            }else{
                top--;
            }
        }else if(*p==')'){
            if(top==-1 || stack[top]!='('){
                return false;
            }else{
                top--;
            }
        }
        p++;
    }    
    return (top==-1) ? true : false;
}

int main(){
    // testcase 1 "()"
    char testcase1[]={'(',')'};
    assert(isValid(testcase1)==true);

    // testcase 2 "()[]{}"
    char testcase2[]={'(',')','[',']','{','}'};
    assert(isValid(testcase2)==true);

    //testcase 3 "(]"
    char testcase3[]={'(',']'};
    assert(isValid(testcase3)==false);

    return 0;
}