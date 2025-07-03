//candy problem
#include <stdio.h>

int main() {
    int n;
    printf("enter the no of elements in rating array\n");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("enter rating %d\n",i+1);
        scanf("%d",&(arr[i]));
        
    }
    int arr2[n];
    for(i=0;i<n;i++){
        arr2[i]=1;
    }
    //exectuion begins front comparisions
    for(i=1;i<n;i++){
        
        if(arr[i]>arr[i-1]){
            arr2[i]=arr2[i-1]+1;
            
        }
        
    }
    // Step 3: Right to left
    for(i = n - 2; i >= 0; i--) {
        if(arr[i] > arr[i + 1]) {
            // Take max of existing and what the rule suggests
            if(arr2[i] < arr2[i + 1] + 1){
                arr2[i] = arr2[i + 1] + 1;
            }
        }
    }
        
    
    int sum=0;
    printf("\ncandies are \n");
    for(i=0;i<n;i++){
        printf("%d ",arr2[i]);
        sum+=arr2[i];
    }
    printf("\nsum of candies are %d",sum);
    
    

    return 0;
}