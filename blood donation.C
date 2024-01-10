#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void insert();
void search();
void display();
void delete();
void update_record();

int count=0;
int c=0;
int size=100;


struct info
{
char donor_name[50];
char blood_group[10];
int number;
int bag_quantity;
};


struct info s[100];


void main()
{
int ch;


while(ch!=0)
{


printf("\n\t***********************************************\n");
printf("\t	WELCOME TO PLASMA DONATION CAMP\n");
printf("\t***********************************************\n\n\n");



printf("\t\t 1: Add new donor\n");
printf("\t\t 2: Display donor record\n");
printf("\t\t 3: Search donor record\n");
printf("\t\t 4: Edit donor record\n");
printf("\t\t 5: Delete donor record\n");
printf("\t\t 0: Exit\n");
printf("\t\tEnter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert(); break;
case 2:
display(); break;

case 3:
search(); break;

case 5:
delete();
break;

case 4:
update_record();
break;
case 0:exit(1);
default:
printf("\n\t\tWrong choice Entered");
}
printf("\n\t\tPress any key to continue "); getch();
}
}


void insert()
{
printf("\n\n\t**** ENTER NEW DONOR DEATAILS ****\n\n"); printf("\n\t\tEnter Donor Name: ");
scanf("%s",s[c].donor_name); printf("\n\t\tEnter Donor Blood Group: "); scanf("%s",s[c].blood_group); printf("\n\t\tEnter Donor Number: "); scanf("\t%d",&s[c].number);
printf("\n\t\tEnter number of Bag (in mL) donated: "); scanf("\t%d",&s[c].bag_quantity);
printf("\n\n\t !!! Donor Record Inserted Sucessfully\n"); count++;
c++;
}


void display()
{

int i=0; int j;
printf("\n\n\t **** Donor Details Are As Follows ****\n");
printf("\nName of Donor\t\tBlood Group\t\tNumber\t\tBag Qty(in mL)\n\n"); for(j=0;j<size;j++)
{
while(i<c)
{

printf("%s\t\t\t%s\t\t\t%d\t\t\t%d\n",s[i].donor_name,s[i].blood_group,s[i].number,s[i]
.bag_quantity);
i++;
}
}
}




void search()
{
int ph_no,flag=0; int i;
printf("\n\n\tEnter Donor Phone Number Which You Want To Search: "); scanf("%d",&ph_no);
while(sizeof(s)>0 && flag==0)
{
for(i=0;i<100;i++)
{
if(s[i].number==ph_no)
{
flag=1;
printf("\n\n\tSearch Sucessfull And Donor Records are as Follows: \n\n");

printf("\nName of Donor\t\tBlood Group\t\tNumber\t\tBag Qty(in ml)\n\n");

printf("%s\t\t%s\t\t%d\t\t%d\n",s[i].donor_name,s[i].blood_group,s[i].number,s[i].bag_quantity);
}
}
}
if(flag==0)
{
printf("\n\n\t\tNo Such Record Found !!!!!\n");
}
}


void delete()
{
char s_id[15];
int i,j;
printf("\n\tEnter Donor Name to Delete: "); fflush(stdin);
scanf("%s",s_id);
for (i = 0; i < size; i++)
{
if(strcmp(s_id,s[i].donor_name)==0)
{
for(j=i-1;j<size-1;j++)
{
strcpy(s[i].donor_name,s[i+1].donor_name); strcpy(s[i].blood_group,s[i+1].blood_group); s[i].number=s[i+1].number; s[i].bag_quantity=s[i+1].bag_quantity;
}
size=size-1;

}
}
printf("\n\tThe record is successfully deleted");
}
void update_record()
{
int tnum,tbag,op;
int i;
char tname[10],tblood_grp[10];
printf("Enter the number of the record to edit: "); scanf("%d",&tnum);
for(i=0;i<size;i++)

{
if(tnum==s[i].number)
{
printf("Choose option to edit\n1. Name\n2. Blood group\n3. Number of bags donated\n");
scanf("%d",&op); switch (op)
{
case 1: printf("Enter new name: "); scanf("%s",tname); strcpy(s[i].donor_name,tname); break;

case 2: printf("Enter new blood type: "); scanf("%s",tblood_grp); strcpy(s[i].blood_group,tblood_grp); break;
case 3: printf("Enter the number of bags donated: "); scanf("%d",&tbag);
s[i].bag_quantity=tbag;

break;
default: printf("Invalid option"); break;
}
}
}
}
