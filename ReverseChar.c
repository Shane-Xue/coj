#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char a[100],b[100];

void reverse(){
    int last,dummy;
    last=0;
    for(dummy=0;dummy<100;dummy++){
        if(a[dummy]==0) {
            last = dummy-1;
            break;
        }
    }
    b[last+1]='\0';
    for(dummy=0;dummy<=last;dummy++) b[last-dummy]=a[dummy];
}

int main(void){
    memset(a,0,100);
    memset(b,0,100);
    scanf("%s",a);
    reverse();
    puts(b);
    return 0;
}
