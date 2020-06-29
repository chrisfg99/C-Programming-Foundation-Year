/***********************************************************************
* WriteProgram.c
* Allows one of the nurses to enter patient details 
* into a computer file
* Christopher Greer
* 28th November 2017
/***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE*fp;

void enterName(void);
void enterPassword(char filename[30]);
void Options(void);
void Add(char surname[8],char dob[8],char fN[20]);
void fileName(void);
char encrypt(char toBe[100]);
void exitFunc();

//This function takes the first name of the nurse and creates
//their file name and uses it to check if they exist
void enterName(void)
{
	char name[30],opt[1],filename[30];
	printf("=========================================================");
	printf("\nWhat is your first name?\n");
	printf(">>>");
	scanf("%s[^' ']",&name);
	printf("---------------------------------------------------------");
	sprintf(filename, "%s.aow", name);
	fp=fopen(filename,"r");
	if (fp != NULL)
	{
		enterPassword(filename);
	}
	else 
	{	
		printf("\nWrong Username, Please Try Again\n");
		enterName();	
		}
}

//This file takes the users password and checks it in their file
void enterPassword(char filename[30])
{
	char password[8],chr,fPassword[8],toBe[8];
	printf("\nWhat is your password?\n");
	printf(">>>");
	scanf("%s",&password);
	fp=fopen(filename,"r");
	encrypt(password);
	fgets(fPassword,9,fp)!=NULL;
	if (strcmp(fPassword,password)==0)
	{
		fclose(fp);
		Options();
	}
	else
	{
		fclose(fp);
		printf("=========================================================");
		printf("\n              !Password is Incorrect!\n");
		enterName();
	}
}

//This fuction is the main menu of the program
void Options(void)
{
	int option;
	printf("=========================================================");
	printf("\n                        Main Menu\n");
	printf("---------------------------------------------------------");
	printf("\nWhat function do you wish to use?\n");
	printf("Option 1:Add\n");
	printf("Option 2:Exit\n");
	printf("---------------------------------------------------------");
	printf("\n>>>");
	scanf("%d",&option);
	printf("=========================================================");
	switch(option)
	{
	case 1:
		fileName();
		break;
	case 2:
		exitFunc();
		break;
	default:
	printf("\n                    !Incorrect Option!\n");	
	Options();
	}
}

//This function encrypts anything that is given to it
char encrypt(char toBe[100])
{
	char chr;
	int i, key;
	key=7;
	for(i=0;toBe[i] !='\0'; ++i)
	{
		chr=toBe[i];
		if(chr >='a'&& chr<='l')
		{
			chr=chr+key;
		}
		else if(chr >='m'&& chr<='s')
		{
			chr=chr-76;
		}
		if(chr >='t'&& chr<='z')
		{
			chr=chr-68;
		}
		else if(chr>='A' && chr<='S')
		{
			chr=chr+key;
		}
		else if(chr>='T' && chr<='Z')
		{
			chr=chr+13;
		}
		else if(chr>='0' && chr<='2')
		{
			chr=chr+key;
		}
		else if(chr>='3' && chr<='9')
		{
			chr=chr+14;
		}
		toBe[i]=chr;
	}
}

//This function takes the users entries and adds them to
//a patient's file
void Add(char surname[8],char dob[8],char fN[20])
{
	char name[50],height[50],waist[50],weight[50],comment[1000]
		, surnamef[50],commentf[250],dobf[50], heightf[50],
		waistf[50],weightf[50];
	fp=fopen(fN,"w");
	
	
	printf("\nWhat is the first name of the patient?");
	printf("\n>>>");
	scanf("%s",&name);
	encrypt(name);
	fprintf(fp,"%s ",name);
	
	encrypt(surname);
	fprintf(fp, "%s", surname);
	sprintf(dobf, "\n Date of Birth: %s", dob);	
	encrypt(dobf);
	fprintf(fp,"%s", dobf);
	
	printf("\nWhat is the Height of the patient in metres?");
	printf("\n>>>");
	scanf("%s",&height);
	getchar();
	sprintf(heightf,"\nHeight: %sm",height);
	encrypt(heightf);
	fprintf(fp,"%s",heightf);
	
	
	printf("\nWhat is the Waist Measurement of the patient");
	printf("in Inches?");
	printf("\n>>>");
	scanf("%[^\n]",&waist);
	getchar();
	sprintf(waistf,"\nWaist Measurement:%s Inches",waist);
	encrypt(waistf);
	fprintf(fp,"%s",waistf);

	printf("\nWhat is the Weight of the patient in Kg?");
	printf("\n>>>");
	scanf("%[^\n]",&weight);
	getchar();
	sprintf(weightf,"\n Weight:%skg",weight);
	encrypt(weightf);
	fprintf(fp,"%s",weightf);

	printf("\nAre there any comments for the patient?");
	printf("\nIf not type N/A");
	printf("\n>>>");
	scanf("%[^\n]",&comment);
	getchar();
	sprintf(commentf,"\nComments:%s",&comment);
	encrypt(commentf);
	fprintf(fp,"%s",commentf);
	fclose(fp);
	Options();
}

//This function creates the file name for the patient file
void fileName(void)
{
	char fN[20],surname[8], dob[8];
	printf("\nWhat is the surname of the patient?");
	printf("\n>>>");
	scanf("%s",&surname);
	getchar();
	
	printf("\nWhat is the Date of Birth of the patient?");
	printf("\n>>>");
	scanf("%s",&dob);
	getchar();
	sprintf(fN,"%s%s.aow",surname, dob);

	Add(surname,dob,fN);
}

//This function is called when the prgram needs to be exited
void exitFunc(void)
{
	exit(0);
}

//This is the main function of the program and is the first to be called
int main(void)
{
	printf("=========================================================");
	printf("\n               Welcome to Patient Entry\n");
	enterName();
	return 0;
}
