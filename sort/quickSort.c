#include<stdio.h>
#include<stdlib.h>

int findPartitionPoint(int *arr, int lb,int ub) {
     int e=lb+1;
     int f=ub;
     int g=0;
     while(1) {
        
        if(arr[e]<arr[lb] && e < ub){
              e++;
        }
        if(arr[f]>arr[lb]){
            f--;
        }
        // printf("e: %d f:%d\n", e,f);
        if(e<f){
            g=arr[f];
            arr[f]=arr[e];
            arr[e]=g;
        }
        else {
            g=arr[lb];
            arr[lb]=arr[f];
            arr[f]=g;
            return f;
        }
        
     }
 
}

int quickSort(int *arr,int lb,int ub,int size){
    int pp=0;
    if(size<=1) {
        return 0;
    }
    pp = findPartitionPoint(arr,lb,ub);
     printf("partition point %d", pp);
    quickSort(arr,lb,pp-1,pp-lb);
    quickSort(arr,pp+1,ub,ub-pp);
}

int main() {

int *x;
int size=0;
int m,pp = 0;
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

 quickSort(x,0,m,size);






printf("The sorted arr of size %d is : { ", size);
for(int j=0;j<size;j++){
    printf("%d", x[j]);
    if(j!=size-1) printf(",");
    else printf(" } \n");
} 

    return 0;
}