/* https://www.dotcpp.com/oj/problem1157.html */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct dataset{
    int num1,num2;
    } data;
    
typedef struct valarray{
    int* inptr;
    int datanum; /* Subscript ends at datanum-1 */
}valarray;

void data_init(data* dat,int init1,int init2){
    dat->num1 = init1;
    dat->num2 = init2;
}

data make_data(int a,int b){
    data datum;
    data_init(&datum,a,b);
    return datum;
}

int accum(int* ptr,int end,int begin){
    /* accummulate all integers in the array ptr in range [begin,end) */
    /* It is the client's responsibility to make sure the data does not go out of range. */
    int sum;
    sum = 0;
    for(;begin<end;begin++){
        sum += ptr[begin];
        }
    return sum;
}

valarray factors(int number){
    int max_fact,*factors,actual,factor;
    actual = 0;
    factor = 0;
    max_fact=log2(number);
    factors=(int*)calloc(max_fact,sizeof(int));
    while(number!=1){
        if(number%factor==0){
            factors[actual]=factor;
            actual++;
            number/=factor;
            }
        else factor++;
        }
    factors=(int*)realloc(factors,actual*sizeof(int));
    valarray array;
    array.inptr = factors;
    array.datanum = actual+1;
    return array;
}

bool is_friend(data dat){
    valarray one,two;
    int accum1,accum2;
    one = factors(dat.num1);
    two = factors(dat.num2);
    accum1=accum(one.inptr,one.datanum,0);
    accum2=accum(two.inptr,two.datanum,0);
    return accum1 == dat.num2 && accum2 == dat.num1;
}

int main(){
    int input,number;
    scanf("%d",&input);
    for(number=0;number<input;number++){
        int one,two;
        scanf("%d %d",&one,&two);
        if(is_friend(make_data(one,two))){
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}
