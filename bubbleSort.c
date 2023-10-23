#include<stdio.h>
#include<stdlib.h>

int main() {

int *x;
int size=0;
int m,e,f,g = 0;
printf("Please number of element to sort : ");
scanf("%d", &size);
x = (int *)malloc(sizeof(x)*size);
if(x==NULL) {
    printf("Unable to allocate memory");
    return 0;
}
m =size-1;
for (int i=0;i<size;i++){
    printf("Please Enter a number : ");
    scanf("%d", &x[i]);
}

while(m > 0 ){

e=0;
f=1;
while(e<m) {
    if(x[f]<x[e]) {
        g=x[f];
        x[f]=x[e];
        x[e]=g;
    }
    e++;
    f++;
} 

    m--;
}


printf("The sorted arr of size %d is : { ", size);
for(int j=0;j<size;j++){
    printf("%d", x[j]);
    if(j!=size-1) printf(",");
    else printf(" } \n");
} 

    return 0;
}