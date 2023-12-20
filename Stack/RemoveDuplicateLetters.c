#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {
    char stack[10000];
    int top=-1;

    int lastOcurrence[26]={0};
    int seen[26]={0};

    for( int i=0;s[i];i++){
        lastOcurrence[s[i]-'a']=i;
    }

    for(int i=0;s[i];i++){
        int current=s[i]-'a';
        if(seen[current]==1) continue;
        while(top>-1 && s[i] < stack[top] && lastOcurrence[stack[top]-'a'] > i){
            seen[stack[top]-'a']=0;
            top--;
        }
        stack[++top]=s[i];
        seen[current]=1;
    }
    top++;
    char temp[top];
    for(int i=0;i<top;i++){
        temp[i]=stack[i];
    }

    char* ans=temp;
    return ans;  
}


int main(){
    char* input;
    char* ans;

    input="cbabc";
    ans=removeDuplicateLetters(input);
    printf("%s\n",ans);

    input="cbacdcbc";
    ans=removeDuplicateLetters(input);
    printf("%s\n",ans);

    input="ccacbaba";
    ans=removeDuplicateLetters(input);
    printf("%s\n",ans);

    return 0;
}