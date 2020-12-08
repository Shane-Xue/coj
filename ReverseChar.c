#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[100],b[100];

void reverse(){
    int last,dummy;
    for(dummy=0;dummy<100;dummy++){
        if(a[dummy]=='\0') last = dummy-1;
    }
    b[last+1]='\0';
    for(dummy=0;dummy<last/2;dummy++) b[last-dummy]=a[dummy];
}

int main(void){
    scanf("%100s",a);
    reverse();
    printf("%s",b);
    return 0;
}
