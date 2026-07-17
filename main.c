#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int add(int a, int b);
int sub(int a,int b);
int mult(int a,int b);
float division(float a,float b);
int factorial(int a);
int isPrime(int a);
int gcd(int a, int b);
void saveHistory(char operation[]);
void viewHistory();
void clearHistory();
int main(){
    int ch;
    int n1;
    int n2;
    float x;
    float y;
    char expression[100];
    int result;
    float result1;
    do{
        printf("\n========== Smart Calculator ==========\n");
        printf("1.Addition\n ");
        printf("2.Subtraction\n ");
        printf("3.Multiplication\n ");
        printf("4.Division\n ");
        printf("5.Factorial\n ");
        printf("6.Power\n ");
        printf("7.Prime Check\n ");
        printf("8.GCD\n ");
        printf("9.View History\n ");
        printf("10.Clear History\n ");
        printf("0.Exit\n ");
        printf("\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter Your first number: ");
                scanf("%d",&n1);
                printf("Enter Your first number: ");
                scanf("%d", &n2);
                result = add(n1,n2);
                printf("%d + %d = %d",n1,n2, result);
                sprintf(expression,"%d + %d = %d",n1,n2,result);
                saveHistory(expression);
                printf("\n");
                break;
            case 2:
                printf("Enter Your first number: ");
                scanf("%d",&n1);
                printf("Enter Your first number: ");
                scanf("%d", &n2);
                result= sub(n1,n2);
                printf("%d - %d = %d",n1,n2, result);
                sprintf(expression, "%d - %d = %d",n1,n2,result);
                saveHistory(expression);
                printf("\n");
                break;
            case 3:
                printf("Enter Your first number: ");
                scanf("%d",&n1);
                printf("Enter Your first number: ");
                scanf("%d", &n2);
                result = mult(n1,n2);
                printf("%d x %d = %d",n1,n2, result);
                sprintf(expression, "%d * %d = %d",n1,n2,result);
                saveHistory(expression);
                printf("\n");
                break;
            case 4:
                printf("Enter Your first number: ");
                scanf("%f",&x);
                printf("Enter Your first number(it should not be 0): ");
                scanf("%f", &y);
                result1 = division(x,y);
                if(result1==0){
                    break;
                }
                printf("%f / %f = %f",x,y,result1);
                sprintf(expression, "%f / %f = %f",x,y,result1);
                saveHistory(expression);
                printf("\n");
                break;
            case 5:
                printf("Enter number: ");
                scanf("%d",&n1);
                result = factorial(n1);
                printf("%d! = %d",n1,result);
                sprintf(expression,"%d! = %d",n1,result);
                saveHistory(expression);
                printf("\n");
                break;
            case 6:
                printf("Enter your number: ");
                scanf("%f",&x);
                printf("Enter power: ");
                scanf("%f",&y);
                result1 = pow(x,y);
                printf("%.2f ^ %.2f = %.2f", x,y,result1);
                sprintf(expression,"%.2f ^ %.2f = %.2f", x,y,result1);
                saveHistory(expression);
                break;
            case 7:
                printf("Enter your number: ");
                scanf("%d",&n1);
                result = isPrime(n1);
                if(result){
                    printf("Prime");
                    sprintf(expression,"%d is Prime",n1);
                }else{
                    printf("Not a Prime");
                    sprintf(expression,"%d is not a Prime",n1);
                }saveHistory(expression);
                break;
            case 8:
                printf("Enter your first number: ");
                scanf("%d",&n1);
                printf("Enter your second number: ");
                scanf("%d",&n2);
                result = gcd(n1,n2);
                printf("GCD of %d and %d is: %d\n", n1, n2, result);
                sprintf(expression,"GCD of %d and %d is: %d\n", n1, n2, result);
                saveHistory(expression);
                break;
            case 9:
                viewHistory();
                break;
            case 10:
                clearHistory();
                break;
                
            default:
                printf("Invalid Input");

        }

    }while (ch !=0);
    
    return 0;
}
int add(int a,int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mult(int a,int b){
    return a*b;
}
float division(float a,float b){
    if (b==0){
        printf("Invalid input! Second number can't be 0");
        return 0;
    }
    return a/b;
}
int factorial(int a){
    int fact= 1;
    for (int i=1;i<a+1 ;i++){
        fact*=i;
    }
    return fact;
}
int isPrime(int a){
    if(a<=1){
        return 0;
    }
    int flag=0;
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            flag++;
            break;
        }
    }
    if(flag==1)
        return 0;
    else
        return 1;
}
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }return a;
}
void saveHistory(char operation[]){
    FILE *fptr= fopen("history.txt","a");
    if (fptr==NULL){
        printf("Unable to print history\n");
        return;
    }
    fprintf(fptr,"%s\n",operation);
    fclose(fptr);
}
void viewHistory()
{
    FILE *fptr = fopen("history.txt", "r");
    char line[100];
    printf("History:\n");
    if (fptr == NULL){
        printf("No history available.\n");
        return;
    }
    while (fgets(line, sizeof(line), fptr) != NULL){
        printf("%s", line);
    }
    fclose(fptr);
}
void clearHistory(){
    FILE *fptr=fopen("history.txt","w");
    if(fptr==NULL){
        printf("Unable to clear History.\n");
        return;
    }
    fclose(fptr);
    printf("History deleted successfully.\n");

}