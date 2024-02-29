#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct bank
{
	int no, bal, pin;
	char name[15], type[15], add[15];
};
struct bank B[10];
int i,n;
void input()
{
	printf("\n Enter Size of Data : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\n Enter account no. : ");
		scanf("%d",&B[i].no);
		printf("\n Acount name : ");
		fflush(stdin);
		gets(B[i].name);
		printf("\n Enter Acount type : ");
		fflush(stdin);
		gets(B[i].type);
		printf(" \n Enter address of acount holder : ");
		fflush(stdin);
		gets(B[i].add);
		printf("\n Enter acount pin : ");
		scanf("%d",&B[i].pin);
		printf("\n Enter Acount balance : ");
		scanf("%d",&B[i].bal);
	}
}
void display()
{
	//for(i=0;i<n;i++)
	//{
		printf("\n\n Acount no.	 	: %d",B[i].no);
		printf("\n Acount name 		: %s",B[i].name);
		printf("\n Acount type		: %s",B[i].type);
		printf("\n Acount holde address : %s",B[i].add);
		printf("\n Acount Balance	: %d",B[i].bal);
		//delay(500);
	//}
}
int j;
void delet()
{
	int de,D=3, dpin;
	do
	{
		printf("\n Enter acount no. to delete :");
		scanf("%d",&de);
		for(i=0;i<n;i++)
		{
			if(de==B[i].no)
			{
				do
				{
				printf("\n Enter Pin : ");
				scanf("%d",&dpin);
				if(dpin==B[i].pin)
				{
					n--;
					for(j=i;j<n;j++)
					{
						B[j].no=B[j+1].no;
						B[j].bal=B[j+1].bal;
						B[j].pin=B[j+1].pin;
						strcpy(B[j].name,B[j+1].name);
						strcpy(B[j].type,B[j+1].type);
						strcpy(B[j].add,B[j+1].add);
					}
					D=0;
				}
				else if(dpin!=B[i].pin && D==1)
				{
					printf("\n You have entered wrong pin three times. \n So you can not delete the acount");
					D--;
				}
				else
				{
					printf("\n You have entered a wrong pin \n Please try again.");
					D--;
				}
				}while(D>0);
			}
		}
		if(D==3)
		printf("\n\n Invalid Acount no.\n\n  Try Again");
	}
	while(D>0);
}
void banking()    //to search the acount no. before
{			//withdraw and deposite
	int no, b=1;
	do
	{
		printf("\n Enter your acount no. to continue : ");
		scanf("%d",&no);
		for(i=0;i<n;i++)
		{
			if(no==B[i].no)
			{
				b=0;
				break;
			}
		}
		if(b==1)
		printf("\n Invalide acount number");
	}while(b>0);
}

void withdraw()
{
	int wa, pinw, w=3;
	system("cls");
	banking();
	do
	{
		printf("\n To Continue Enter Your Pin : ");
		scanf("%d",&pinw);
		if(pinw==B[i].pin)
		{
			printf("\n Enter withdraw amount : ");
			scanf("%d",&wa);
			B[i].bal-=wa;
			w=0;
		}
		else if(pinw!=B[i].pin && w==1)
		{
			printf("\n Sorry You Have Entered a Wrong Pin 3 Times");
			w--;
		}
		else
		{
			printf("\n Invalid pin please try again");
			w--;
		}
	}while(w>0);
	printf("\n\n Your Account Info : \n\n");
	display();
	getch();
}
void deposit()
{
	int de;
	system("cls");
	banking();
	printf("\n Enter deposit amount : ");
	scanf("%d",&de);
	B[i].bal+=de;
	printf("\n\n Your Account Info : \n\n");
	display();
	getch();
}
int f=0;
void search()
{
	int ac;
	printf("\n Enter Acount number to search : ");
	scanf("%d",&ac);
	for(i=0;i<n;i++)
	{
		if(ac==B[i].no)
		{
			//printf("\n\n Acount number	: %d",B[i].no);
			//printf("\n Acount name		: %s",B[i].name);
			//printf("\n Acount type 		: %s",B[i].type);
			//printf("\n Acount address	: %s",B[i].add);
			//printf("\n Acount balance	: %d",B[i].bal);
			display();
			f=1;
			break;
		}
	}
	if(f==0)
	printf("\n\n Invalide Acount number");
}
void update()
{
	int uac,upin, U=3;
	do
	{
		printf("\n Enter acount number to Update :");
		scanf("%d",&uac);
		for(i=0;i<n;i++)
		{
			if(uac==B[i].no)
			{
			do
			{
				printf("\n Enter pin : ");
				scanf("%d",&upin);
				if(upin==B[i].pin)
				{
					printf("\n\n Update name : ");
					fflush(stdin);
					gets(B[i].name);
					printf("\n Update address : ");
					gets(B[i].add);
					printf("\n Update acount type : ");
					gets(B[i].type);
					printf("\n Update acount password :");
					scanf("%d",&B[i].pin);
					U=0;
					break;
				}
				else if(upin!=B[i].pin && U==1)
				{
					printf("\n You have entered a wrong pin Three times\n So you can not update the acount ");
					U--;
				}
				else
				{
					printf("\n Wrong pin please try again");
					U--;
				}
			}while(U>0);
			}
		}
		if(U==1)
		printf("\n\n Invalid Acount no. Try Again");

	}
	while(U>0);
	system("cls");
	display();
	getch();
}
void sort()
{
	int sbal, sac, pins;
	char sname[15],stype[15],sadd[15];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(B[j].no>B[j+1].no)
			{
				sac=B[j].no;
				sbal=B[j].bal;
				pins=B[j].pin;
				strcpy(sname,B[j].name);
				strcpy(stype,B[j].type);
				strcpy(sadd,B[j].add);

				B[j].no=B[j+1].no;
				B[j].bal=B[j+1].bal;
				B[j].pin=B[j+1].pin;
				strcpy(B[j].name,B[j+1].name);
				strcpy(B[j].type,B[j+1].type);
				strcpy(B[j].add,B[j+1].add);

				B[j+1].no=sac;
				B[j+1].bal=sbal;
				B[j+1].pin=pins;
				strcpy(B[j+1].name,sname);
				strcpy(B[j+1].type,stype);
				strcpy(B[j+1].add,sadd);
			}
		}
	}
}
void insert()
{
	int pos;
	printf("\n Enter the position : ");
	scanf("%d",&pos);
	n++;
	for(j=n-1;j>pos-1;j--)
	{
		B[j].no=B[j-1].no;
		B[j].bal=B[j-1].bal;
		B[j].pin=B[j-1].pin;
		strcpy(B[j].name,B[j-1].name);
		strcpy(B[j].type,B[j-1].type);
		strcpy(B[j].add,B[j-1].add);
	}
	printf("\n\n Enter account no. : ");
	scanf("%d",&B[j].no);
	printf("\n Acount name : ");
	fflush(stdin);
	gets(B[j].name);
	printf("\n Enter Acount type : ");
	fflush(stdin);
	gets(B[j].type);
	printf(" \n Enter address of acount holder : ");
	fflush(stdin);
	gets(B[j].add);
	printf("\n Enter acount password : ");
	scanf("%d",&B[j].pin);
	printf("\n Enter Acount balance : ");
	scanf("%d",&B[j].bal);
}


main()
{
	char ch;
	system("cls");
	input();
	do
	{
		system("cls");
		printf("\n\n\n For Info Press 1");
		printf("\n For Withdraw Press 2");
		printf("\n For Deposite Press 3");
		printf("\n For Searching Press 4");
		printf("\n For Update Press 5");
		printf("\n For Deletion Press 6");
		printf("\n For Sorting Press 7");
		printf("\n For Insertion Press 8");
		printf("\n For Exit Press 0");
		printf("\n Enter a Valid Key : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1 :system("cls");
				for(i=0;i<n;i++)
				{
					display();
//					delay(500);
					Sleep(1);
				}
				getch();
				break;
			case 2 :withdraw();
				break;
			case 3 :deposit();
				break;
			case 4 :search();
				getch();
				break;
			case 5 :update();
				break;
			case 6 :delet();
				break;
			case 7 :sort();
				break;
			case 8 :insert();
				break;
			case 0 :exit(1);
				break;
			default  :printf("\n\n Invalide Choise\n\n Try Again\n\n");
		}
       }while(1);
}
