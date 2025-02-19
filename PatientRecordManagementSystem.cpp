#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void MainMenu();
void DataEntry();
void DataDisp();
void DataSearch();
void DataEdit();
void DataDlt();

struct PRMS
{
	int PID;
	char Fname[60];
	int Age;
	char BloodGrp[4];
	char AppDoc[60];
} record[100];
int n, i, j;

int main()
{
	while(1)
	{
		system("cls");
		MainMenu();
		char c = getch();
		printf("%c", c);
		switch(c)
		{
			case '1':
				DataEntry();
			break;
			case '2':
				DataDisp();
			break;
			case '3':
				DataSearch();
			break;
			case '4':
				DataEdit();
			break;
			case '5':
				DataDlt();
			break;
			case '6':
				printf("\n\n  THANK YOU");
				return 0;
			break;
			default:
				printf("\nWrong Input!!!\nPress any key to try again!");
				getch();
			break;
		}
	}
}

void MainMenu()
{
	printf("\n\n\n");
	printf("             # XYZ Hospital #\n");
	printf("+----------------------------------------+\n");
	printf("+             Patient Records            +\n");
	printf("+----------------------------------------+\n");
	printf("+ 1. Enter Record                        +\n");
	printf("+ 2. Display Records                     +\n");
	printf("+ 3. Search Record                       +\n");
	printf("+ 4. Edit Record                         +\n");
	printf("+ 5. Delete Records                      +\n");
	printf("+ 6. Exit                                +\n");
	printf("+----------------------------------------+\n");
	printf("\n Enter your choice : ");
}

void DataEntry()
{
	system("cls");
	printf("\n\n\n");
	printf("             # XYZ Hospital #\n");
	printf("+----------------------------------------+\n");
	printf("+            Record Entry Menu           +\n");
	printf("+----------------------------------------+\n");
	printf("Enter no. of records : ");
	scanf("%d", &n);
	if(n>100){ 
		printf("Maximum amount of data entry at once is 100\nPress any key to try again...");
		return;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEntry no. %d",i+1);
		printf("\nPatient ID : ");
		scanf("%d", &record[i].PID);
		
		printf("Full Name : ");
    	fflush(stdin);
		gets(record[i].Fname);
		
		printf("Age : ");
		scanf("%d", &record[i].Age);
		
		printf("Blood Group : ");
		fflush(stdin);
		gets(record[i].BloodGrp);
		
		printf("Appointed Doctor : ");
		fflush(stdin);
		gets(record[i].AppDoc);
	}
	FILE *fp = fopen("records.txt", "a");
    if (fp != NULL)
    {
        for (i = 0; i < n; i++)
    {
      fprintf(fp, "%d,%s,%d,%s,%s\n", record[i].PID, record[i].Fname, record[i].Age, record[i].BloodGrp, record[i].AppDoc);
    }
    fclose(fp);
    }
    else
    {
      printf("Error: Unable to open file for writing.\n");
    }
}

void DataDisp()
{
	system("cls");
	printf("\n\n\n");
	printf("                                     # XYZ Hospital #\n");
	printf("+----------------------------------------------------------------------------------------------+\n");
	printf("| Patient ID | Name                         | Age | Blood Group | Appointed Doctor             |\n");
	printf("+------------+------------------------------+-----+-------------+------------------------------+\n");
	FILE *fp=fopen("records.txt","r");
	int PID,A;
	char FN[60],BG[4],AD[60];
	rewind(fp);
	if(fp==NULL)
	{
		printf("\n\n\n\t\t THE FILE DOESNT CONTAIN ANY DATA!\n\t\tPRESS ANY KEY TO CONTINUE!");
		getch();
		return;
	}
	else
	{
		while(fscanf(fp,"%d,%[^,],%d,%[^,],%[^\n]", &PID , FN , &A , BG , AD )!=EOF)
		{
			printf("| %-10d | %-28s | %-3d | %-11s | %-28s |\n", PID, FN, A, BG, AD);
		}
	}
	printf("+----------------------------------------------------------------------------------------------+\n");
	printf("\n\n\nEnter any key to continue!!!");
	getch();
	fclose(fp);
	return;
}

void DataSearch()
{
	int crit;
	system("cls");
	printf("\n\n\n");
	printf("                                     # XYZ Hospital #\n");
	printf("+----------------------------------------------------------------------------------------------+\n");
	printf("+                                   Search record Menu                                         +\n");	
	printf("+----------------------------------------------------------------------------------------------+\n");
	printf("1. Search by Patient ID\n2.Search by Name\n");
	printf("Enter search criteria : ");
	scanf("%d",&crit);
	switch(crit)
	{
		case '1':
			
	}
	getch();
}

void DataEdit() { printf("\nEdit Record Function\n"); getch(); }
void DataDlt() { printf("\nDelete Record Function\n"); getch(); }

