#include <stdio.h>
#include <string.h>


int main() {

        int num_names, i=0;

        char strmat[60][12], temp[12];
        printf("How many names do you wish to input (max is 20): ");
        scanf("%d", &num_names); 
        //This tells us how many rows our table will have
        for(i=0; i<num_names*3; i++){ 
            //We need to do this 3 times the number of names since our matrix 
            //will seperate the names into different rows every time there is a
            //space
            if (i%3==0)
                printf("Enter Last name, First Name, and age: ");
            
            scanf(“%s”,strmat[i]);
            printf("\n");
        }
        
        printf("Original List:\n--------------------------\n");
        
        for(i=0; i<num_names*3;i=i+3){
            printf("%8s%8s%8s\n", strmat[i],strmat[i+1],strmat[i+2]);
        }
        
        printf("\n\n Sorted List:\n--------------------------\n");
        for(i=0; i<num_names*3;i=i+3){
            for(int j=i+3; j<num_names*3;j=j+3){
                if(strcmp(strmat[i], strmat[j])>0){
                    strcpy(temp, strmat[i]);
                    strcpy(strmat[i], strmat[j]);
                    strcpy(strmat[j],temp);
                }
            }
        }
        for(i=0; i<num_names*3;i=i+3){
            printf("%8s %8s %8s\n", strmat[i],strmat[i+1],strmat[i+2]);
        }

    return 0;
}