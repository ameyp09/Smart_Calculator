#include <stdio.h>
#include <math.h>
int add(int a, int b);
int sub(int a,int b);
int mult(int a,int b);
void div(int a,int b);
int factorial(int a);
int main(){
    int ch;
    int n1;
    int n2;
    float x;
    float y;
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
        printf("9.LCM ");
        printf("10.View History\n ");
        printf("11.Clear History\n ");
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
                printf("%d + %d = %d",n1,n2, add(n1,n2));
                printf("\n");
                break;
            case 2:
                printf("Enter Your first number: ");
                scanf("%d",&n1);
                printf("Enter Your first number: ");
                scanf("%d", &n2);
                printf("%d - %d = %d",n1,n2, sub(n1,n2));
                printf("\n");
                break;
            case 3:
                printf("Enter Your first number: ");
                scanf("%d",&n1);
                printf("Enter Your first number: ");
                scanf("%d", &n2);
                printf("%d x %d = %d",n1,n2, mult(n1,n2));
                printf("\n");
                break;
            case 4:
                printf("Enter Your first number: ");
                scanf("%d",&n1);
                printf("Enter Your first number(it should not be 0): ");
                scanf("%d", &n2);
                div(n1,n2);
                printf("\n");
                break;
            case 5:
                printf("Enter number: ");
                scanf("%d",&n1);
                printf("%d! = %d",n1,factorial(n1));
                printf("\n");
            case 6:
                printf("Enter your number: ");
                scanf("%f",&x);
                printf("Enter power: ");
                scanf("%f",&y);
                printf("%f ^ %f = %f", x,y,pow(x,y));
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
void div(int a,int b){
    if (b!=0){
        printf("%d / %d = %d",a,b,a/b);
    }else{
        printf("Invalid input! Second number can't be 0");
    }
}
int factorial(int a){
    int fact= 1;
    for (int i=1;i<a+1 ;i++){
        fact*=i;
    }
    return fact;
}
