#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//declaration of functions
void Menu();
void PrimePalindroms();
int IfIsPrime(int num);
void CheckAndPrint();
void PrintNumbers(int number);
int  SumDigits(int number);
int IsNumberInRange(int low,int high,int number);
int FindPalindroms(int start);
int FindMinDigit(int);
void RemoveMinDigit();
void Game();
void PrintPattern();
//main function inly call to menu function
int main(){
Menu();
return 0;
}
//User will see several options that he can choose
void Menu(){
int SelectedOption;
while(SelectedOption!=6){
SelectedOption=0;
printf("\nChose an option from 1 to 6.\n");
printf("1-Check number\n");
printf("2-Prime Palindrome scavenger hunt\n");
printf("3-Remove all min digits\n");
printf("4-The guessing game\n");
printf("5-Print Pattern\n");
printf("6-Exit\n");
scanf("%d",&SelectedOption);
switch(SelectedOption)
{case 1:
	CheckAndPrint();
	break;
case 2:
	PrimePalindroms();
	break;
case 3:
	RemoveMinDigit();
	break;
case 4:
	Game();
	break;
case 5:
	PrintPattern();
	break;
case 6:
	printf("***Have a nice day!***\n");
	break;
default:
	printf("Something went wrong.Please choose an option from the menu.\n");
	break;
}
}
}
/*This function check if number in range*/

int IsNumberInRange(int low,int high,int number){
int x;
if(number>low&&number<high)
	x=1;
else
	x=0;
return x;
}

//This function will sum all digits from the number
int SumDigits(int number){
int SumNum=0;
if (number<0)
	number*=-1;
do{
SumNum+=number%10;
number/=10;
}while(number!=0);

return SumNum;
}
//This function will print numbers 100-999 that their sum same that users input
void PrintNumbers(int sun){
int i;
int a=SumDigits(sun);
for(i=100;i<999;i++){
int b=SumDigits(i);
	if(a==b){
		printf("%d\t",i);
}
}
}
//This function will ask from useer input an limits of range
void CheckAndPrint(){
int number,low,high;
printf("Enter a number:\n");
scanf("%d",&number);
printf("Enter lower limit:\n");
scanf("%d",&low);
printf("Enter higher limit:\n");
scanf("%d",&high);

if(IsNumberInRange(low,high,number)==0)
	printf("Something went wrong.Please enter another numbers.\n");
if(IsNumberInRange(low,high,number)==1)
	PrintNumbers(number);

}

//This function will print prime palindromes in given range from user
void PrimePalindroms(){
  int x,start,end,y;
  
  printf("Enter lower limit:\n");
  scanf("%d",&start);
  printf("Enter higher limit:\n");
  scanf("%d",&end);
  
  for(int a=start;a<end;a++){

    if(IfIsPrime(a)*FindPalindroms(a))
      printf("%d\t",a);
  }
    printf("\n");
}

int IfIsPrime(int num){

 for (int i = 2 ; i<num ; i++)
   {

      if (!(num% i))
        return 0;
  
  }
return 1;
}
int FindPalindroms(int start){
  int num,rem=0,reverse_num,temp,q;
	
		temp=start;
		reverse_num=0;
		while(temp){
			rem=temp%10;
			temp/=10;
			reverse_num=reverse_num*10+rem;
		}
		if(start==reverse_num)
			return 1;
    return 0;
			
}
  
  



	
	//This function will print patter according to number that iser input that consist a symbol also from users input


void PrintPattern(){
	int num,row,k,p,t,m,i;
	char sim;
	printf("Enter a number  then symbol:\n");
	scanf("%d %c",&num,&sim);

	for(i=num;i>=1;--i)
	{
		for(k=0;k<num-i;++k)
			printf("  ");
		for(p=i;p<=2*i-1;++p)
			printf("%c ",sim);
		for(p=0;p<i-1;++p)
			printf("%c ",sim);
		printf("\n");
	}
	
	{t=num;

	for(row=1;row<=num;row++)
	{
		printf("");
			for(m=1;m<t;m++)
				printf("  ");
			t--;

			for(m=1;m<=2*row-1;m++)
				printf("%c ",sim);

			printf("\n");
		}
		}
	}

//This function will find minimal digit in users input
int FindMinDigit(int some_number){

int temp,p,min=9;
while(some_number!=0){
	temp=some_number%10;
	if(temp==0){
		min=0;
		}
	if(temp<=min){
		min=temp;
		}
	some_number/=10;
	}
return min;
}
//This function will remove minimal digit from number after that it was found with help-function
void RemoveMinDigit(){
int p,output=0,power=1,q,some_number;

printf("Please enter your number:\n");
scanf("%d",&some_number);

q=FindMinDigit(some_number);


while(some_number!=0){
	p=some_number%10;
	some_number/=10;
	if(p!=q){
		output+=p*power;
			power*=10;}
	}
printf("The result is:%d\n",output);
}
//This function will do guessinf game
void Game(){
int low,high,number,counter,temp;
printf("Enter low limit:\n");
scanf("%d",&low);
printf("Enter high limiy:\n");
scanf("%d",&high);
do{
printf("Enter the number of guess you would like to make:\n");
scanf("%d",&number);
}while(IsNumberInRange(1,11,number)!=1);
srand(time(NULL));
int value=(rand()%(high-low+1)+low);
counter=number-1;
printf("Enter your guess(you have %d left):\n",number);
	
while(counter>=0){
	scanf("%d",&temp);
	if(IsNumberInRange(low-1,high+1,temp)!=1)
	printf("Invalid guess-not in the required range [%d-%d]",low,high);
	else
		if(temp==value){
			printf("You won!\n");
			counter=0;	
			}
		else{
			if(temp>value&&counter!=0)
				printf("Enter lower number(you jave %d guesses left):\n",counter);
			else if(temp<value&&counter!=0)	
				printf("Enter higher number(you have %d guesses left):\n",counter);
			
		}
	
	if(counter==0)
		printf("You lost\n");
	counter--;
}
}
