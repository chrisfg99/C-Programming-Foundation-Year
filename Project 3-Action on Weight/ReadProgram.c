/***********************************************************************
* ReadProgram.c
* Allows theconsultant to read the computer file generated
* by the previous program
* Christopher Greer
* 28th November 2017
/**********************************************************************/
#include <stdio.h>

#include <stdlib.h>

FILE* fp;

void fileName(void);
void patientView(char fN[20]);
char encrypt(char toBe[100]);
char decrypt(char notToBe[1000]);
void cont(void);
void comment(char fN[20]);
void addComment(char fN[20]);
void exitFunc(void);

//Takes the patients surname and date of birth and uses them
//to get the file name for that patient
void fileName(void)
{
	char surname,fN[20],dob[20];

	printf("=========================================================");
	printf("\n What is the surname of the patient you wish to view?");
	printf("\n>>>");
	scanf("%s",&surname);
	printf("--------------------------------------------------------");
	printf("\n What is the D.O.B of the patient you wish to view?");
	printf("\n         Enter in format ddmmyy (030299)");
	printf("\n>>>");
	scanf("%s",&dob);
	sprintf(fN,"%s%s.aow",&surname, &dob);
	printf("=========================================================");
	patientView(fN);
}

//This function takes the filename and opens the file with that
//name and displays it to the user
void patientView(char fN[20])
{
	char chr[10000];
	fp=fopen(fN,"r");
	if (!fp)
	{
		printf("\n                    !FILE NOT FOUND!\n");
		printf("---------------------------------------------------------");
		printf("\nPlease check input for capitalisation of surname\n");
		printf("or the input of incorrect information\n");
		printf("=========================================================");
		printf("\nDo you wish to try again?");
		printf("\nPlease use Y or N");
		cont();
	}
	else
	{
		printf("\n                      File found\n");
		printf("---------------------------------------------------------");
		printf("\n");
		while (fgets(chr,10000,fp)!=NULL)
		{
			decrypt(chr);
			puts(chr);
		}
		printf("\n");
		printf("=========================================================");
		comment(fN);		
	}
}

//This function decrypts anything given to it
char decrypt(char notToBe[1000])
{
	char chr;
	int i, key;
	key=7;
	for(i=0;notToBe[i] !='\0'; ++i)
	{
		chr=notToBe[i];
		if(chr >='a'&& chr<='g')
		{
			chr=chr-13;
		}
		else if(chr >='h'&& chr<='z')
		{
			chr=chr-key;
		}
		else if(chr>='A' && chr<='G')
		{
			chr=chr-14;
		}
		else if(chr>='H' && chr<='Z')
		{
			chr=chr-key;
		}
		else if(chr>='0' && chr<='6')
		{
			chr=chr+68;
		}
		else if(chr>='7' && chr<='9')
		{
			chr=chr-key;
		}
		else if(chr >='!'&& chr<=')')
		{
			chr=chr+76;
		}
		notToBe[i]=chr;
	}
}

//This function encrypts what ever is given to it
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

//This function asks the user if they wish to continue, if they don't
//they shall then exit the program
void cont(void)
{
	fp;
	char opt[0];
	printf("\n>>>");
	scanf("%s",opt);
	fclose(fp);
	if (opt[0]=='y')
	{
		printf("=========================================================");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		fileName();
	}
	else if (opt[0]=='n')
	{
		printf("=========================================================");
		printf("\n                Exiting Program..............\n");
		printf("=========================================================");
		exitFunc();
	}
	else if (opt[0]=='Y')
	{
		printf("=========================================================");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		fileName();
	}
	else if (opt[0]=='N')
	{
		printf("=========================================================");
		printf("\n                Exiting Program..............\n");
		printf("=========================================================");
		exitFunc();
	}
	else
	{		
		printf("Incorrect input try again");
		cont();
	}
}

//This function asks the user if they wish to comment
//if they do not then they rturn to the first function
void comment(char fN[20])
{
	char opt[1];
	printf("\nDo you wish to add comments?");
	printf("\nPlease use Y or N");
	printf("\n>>>");
	scanf("%s",opt);
	getchar();
		if (opt[0]=='y')
	{
		addComment(fN);
	}
	else if (opt[0]=='n')
	{
		printf("=========================================================");
		printf("\nDo you wish to view another patient?");
		printf("\nPlease use Y or N");
		cont();
	}
	else if (opt[0]=='Y')
	{
		addComment(fN);
	}
	else if (opt[0]=='N')
	{
		printf("=========================================================");
		printf("\nDo you wish to view another patient?");
		printf("\nPlease use Y or N");
		cont();
	}
	else
	{		
		printf("Incorrect input try again");
		comment(fN);
	}
}

//This function is used to add a comment to 
void addComment(char fN[20])
{
	char comt[1000];
	printf("=========================================================");
	printf("\n         What comment would you wish to add?\n");
	fp=fopen(fN,"a+");
	printf(">>>");
	scanf("%[^\n]",&comt);
	getchar();
	encrypt(comt);
	fprintf(fp,"\n%s",comt);
	printf("=========================================================");
	printf("\nDo you wish to view another patient?");
	printf("\nPlease use Y or N");
	cont();
}

//This functions purpose is simply to exit the program
void exitFunc(void)
{
	exit(0);
}

//This is the main fucntion of the program where the whole program 
//starts by printing a welcome banner then calling filename()
int main(void)
{
	char fN;
	printf("=========================================================");
	printf("\n               Welcome to Patient View\n");
	fileName();	
	return 0;
}
