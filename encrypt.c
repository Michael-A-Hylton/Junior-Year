
#include <stdio.h>
#include <string.h>

char encrypt(char *enc, int N)
{
    char temp; //declare a temporary variable to hold characters
    if (N<=2){
        return(*enc); //set up the break
    }
    else{
        int k = N/2; //since it is an int, it will delete anything after a decimal
        //int l=k+1; //create an int to start the secnond string.
        for(int i=0; i<k/2;i++){
            temp=*(enc+i); //set the temp variable to the i-th location
            *(enc+i)=*(enc+k-i);//set the i-th variable to the (k-i)th location
            *(enc+k-i)=temp; //use the temp variable to set the (k-i)th location to the original ith value
        }
        char enc2[8192/2];// create a string to store half the string temporarily
        for(int j=0;j<(N-k);j++){
            enc2[j]=*(enc+j+k);// copy the old string to the new string
        }
        for(int i=0; i<(N-k)/2;i++){
            temp=*(enc2+i); //set the temp variable to the i-th location
            *(enc2+i)=*(enc2+k-i);//set the i-th variable to the (k-i)th location
            *(enc2+k-i)=temp; //use the temp variable to set the (k-i)th location to the original ith value
        }
        
        *enc2=encrypt(enc2,(N-k));
        *enc=encrypt(enc,k)+*enc2;//pass them both to get new string.
        //printf("Pass\n");
        
    }
}

int main()
{
    int length;
    char enc[8192];
    printf("Input string you want encrypted: ");
    scanf("%s", enc);//Have the user input a string
    length=strlen(enc);//find the strings length
    //printf("Original String: %s\n",enc);//print out original string.
    *enc=encrypt(enc,length); //call the encrypt function passing the string and the length.
    printf("Output:\n%d\n %s\n",length, enc);
    
    
}






