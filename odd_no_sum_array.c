
#include <stdio.h>

int main() {
    int n;
    printf("enter the no of elements\n");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("enter element %d\n",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\narray element are\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    int sum=0;
    for(i=0;i<n;i++){
        if(arr[i]%2 != 0){
            sum=sum+arr[i];
        }
    }
    printf("\nsum is %d",sum);

    return 0;
}