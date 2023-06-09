#include<stdio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
int bjp=0, congress=0, aap=0, bsp=0,sp=0;
#define CANDIDATE1 "BJP"
#define CANDIDATE2 "CONGRESS"
#define CANDIDATE3 "AAP"
#define CANDIDATE4 "BSP"
#include <stdio.h>
void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
SetConsoleTextAttribute(hStdOut,wColor);

}
}
void electionResult()
{
    int wonByVote;
    if (bjp > congress && bjp > aap && bjp > bsp)
    {
        setcolor(7);
        printf("\n****************************\n");
        printf("\n***BJP won the election***\n\n");
        printf("****************************\n\n");
        setcolor(11);
        printf("Total vote of BJP : %d\n",bjp);
        wonByVote=bjp-congress;
        printf("BJP won by %d votes to Congress\n",wonByVote);
        wonByVote=bjp-aap;
        printf("BJP won by %d votes to AAP\n",wonByVote);
        wonByVote=bjp-bsp;
        printf("BJP won by %d votes to BSP\n",wonByVote);
    }
    else if (congress > aap && congress > bsp)
    {
        setcolor(9);
        printf("\n*********************************\n");
        printf("\n***Congress won the election***\n\n");
        printf("*********************************\n\n");
        setcolor(11);
        printf("Total vote of Congress : %d\n",congress);
        wonByVote=congress-bjp;
        printf("Congress won by %d votes to BJP\n",wonByVote);
        wonByVote=congress-aap;
        printf("Congress won by %d votes to AAP\n",wonByVote);
        wonByVote=congress-bsp;
        printf("Congress won by %d votes to BSP\n",wonByVote);
    }
    else if (aap > bsp)
    {
        setcolor(19);
        printf("\n****************************\n");
        printf("\n***AAP won the election***\n\n");
        printf("****************************\n\n");
        setcolor(11);
        printf("Total vote of AAP : %d\n",aap);
        wonByVote=aap-congress;
        printf("AAP won by %d votes to Congress\n",wonByVote);
        wonByVote=aap-bjp;
        printf("AAP won by %d votes to BJP\n",wonByVote);
        wonByVote=aap-bsp;
        printf("AAP won by %d votes to BSP\n",wonByVote);
    }
    else if(bjp == congress && bjp == aap && bjp == bsp)
    {
        printf("\nNo one won the election\n\n");
        printf("            BJP---Congress---AAP---BSP\n");
        printf("Total Vote   %d       %d        %d     %d\n",bjp,congress,aap,bsp);
    }
    else
    {
        setcolor(2);
        printf("\n****************************\n");
        printf("\n***BSP won the election***\n\n");
        printf("****************************\n\n");
        setcolor(11);
        printf("Total vote of BSP : %d\n",bsp);
        wonByVote=bsp-congress;
        printf("BSP won by %d votes to Congress\n",wonByVote);
        wonByVote=bsp-aap;
        printf("BSP won by %d votes to AAP\n",wonByVote);
        wonByVote=bsp-bjp;
        printf("BSP won by %d votes to BJP\n",wonByVote);
    }
}
void votesCount(){
printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, bjp);
printf("\n %s - %d ", CANDIDATE2, congress);
printf("\n %s - %d ", CANDIDATE3, aap);
printf("\n %s - %d ", CANDIDATE4, bsp);
printf("\n %s - %d ", "Spoiled Votes", sp);
}
void getLeadingCandidate(){
    printf("\n\n  #### Leading Candiate ####\n\n");
    if(bjp>congress && bjp>aap && bjp >bsp)
    printf("[%s]",CANDIDATE1);
    else if (congress>aap && congress>bsp && congress >bjp)
    printf("[%s]",CANDIDATE2);
    else if(aap>bsp && aap>congress && aap >bjp)
    printf("[%s]",CANDIDATE3);
    else if(bsp>bjp && bsp>congress && bsp >aap)
    printf("[%s]",CANDIDATE4);
    else
    printf("----- Warning !!! No-win situation----");



}

void calculateVote(int vote)
{
    switch (vote)
    {
    case 1:
        bjp+=1;
        break;
    case 2:
        congress+=1;
        break;
    case 3:
        aap+=1;
        break;
    case 4:
        bsp+=1;
        break;
    case 5:
        sp+=1;
        break;
    }
}
void main()
{
int i;
int choice;
setcolor(11);
 printf("\n\n ###### Welcome to Election/Voting 2023 #####");
     int vote_age;
  printf("\n Input the age of the candidate : ");
  scanf("%d",&vote_age);
  if (vote_age>18)
  {
       printf("Congratulation! You are eligible for casting your vote.\n");
  }
  else
  {
      printf("Sorry, You are not eligible to caste your vote.\n");
       printf("You would be able to caste your vote after %d year.\n",18-vote_age);
       return 0;
  }
do{
printf("\n\n 1. Cast the Vote");
printf("\n 2. Find Vote Count");
printf("\n 3. Find leading Candidate");
printf("\n 4. End voting and announce the winner");
printf("\n 0. Exit");
printf("\n\n Please enter your choice : ");
scanf("%d", &choice);
int choose;
switch(choice)
{
 case 1:
    printf("\n*********Welcome to the voting system project*********\n\n");
    do
    {
        printf("Press 1 to vote BJP\n");
        printf("Press 2 to vote Congress\n");
        printf("Press 3 to vote APP\n");
        printf("Press 4 to vote BSP\n");
        printf("Press 5 for NOTA\n");
        printf("Press 6 to stop\n");
        printf("Please choose : ");
        scanf("%d", &choose);
        if (choose==6)
        {
            break;
        }
        else
        {
            calculateVote(choose);
        }
        printf("\n");
    } while (choose != 6);
    break;
case 2:
    votesCount();
    break;
case 3:
    getLeadingCandidate();
    break;
case 4:
    electionResult();
    break;
default: printf("\n Error: Invalid Choice");
}
}while(choice!=0);
return 0;
}
