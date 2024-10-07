#include <stdio.h>
#include <string.h>

int main(){
    
    int choice,length;
    char cont;
    char str1[10],str2[10],str3[30];
    do{
        printf("1. String length\n");
        printf("2. String copy\n");
        printf("3. String compare\n");
        printf("4. String concatenate\n");
        printf("Enter the choice \n");
        scanf("%d",&choice);


        switch (choice)
        {
        case 1:
            printf("Enter the String \n");
            scanf("%s",str1);
            length =strlen(str1);
            printf("length of thering is %d\n",length);
            break;
        
        case 2:
            printf("Enter the Str \n");
            scanf("%s",str1);
            strcpy(str2,str1);
            printf("copied string %d\n",str2);
            break;

    
        case 3:
            printf("Enter the Str 1");
            scanf("%s",str1);
            printf("Enter the Str 2");
            scanf("%s",str2);
            int result = strcmp(str2,str1);
            if(result ==0)
                printf("strings are equal\n");
            else
                printf("strings are not equal\n");
            break;

        case 4:
            printf("Enter the Str 1");
            scanf("%s",str1);
            printf("Enter the Str 2");
            scanf("%s",str2);
            strcat(str2,str1);
            printf("concatenated string is is %s\n",str2);
            break;
        
        default:
            break;
        }

    }while (/* condition */)
    {
        /* code */
    }
    
}