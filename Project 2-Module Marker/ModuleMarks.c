	
/***********************************************************************
* ModuleMarks.c
* Write a program that displays and handles assessment marks for 
* up to 75 students in a course module
* Christopher Greer
* 7th November 2017
* ********************************************************************/

//The following is a list of all of the libiaries that have been 
//imported to allow the function to run correctly
#include <stdio.h>
#include <stdlib.h>


//This is all of the functions in the code defined at the start
void start(int no, char name[30][no],int pin, int mark[3][no]);
void details(void);
int number(void);
int newPin(void);
void addStudent(int no, char name[30][no],int pin,int newNo);
char changeName(int no,char name[30][no]);
void changeMark(int no,char name[30][no],int pin,int marks[3][no]);
void changePin(int no,char name[30][no], int pin,int marks[3][no]);
int choose(int no,char name[30][no], int pin,int marks[3][no]);
void exitSupervisor(int no,char name[30][no],int pin,int marks[3][no]);
int mark1(int no,char name[30][no],int pin,int marks[3][no]);
int mark2(int no,char name[30][no],int pin,int marks[3][no]);
int mark3(int no, char name[30][no],int pin,int marks[3][no]);
void seeStudent(int no,char name[30][no],int pin,int marks[3][no]);
void options(int no,char name[30][no],int pin,int marks[3][no]);
void supervisorMode(int no,char name[30][no],int pin,int marks[3][no]);
void supervisorOptions(int no, char name[30][no],int pin
    ,int marks[3][no]);


//This is the function used to print all of the options of the
//main menu
void options(int no,char name[30][no],int pin,int marks[3][no])
{
	printf("------------------------------------------------------------");	
	printf("\n[                          Menu                           ]");
	printf("\n------------------------------------------------------------");
	printf("\n1.Enter marks for course work 1\n");
	printf("2.Enter marks for course work 2\n");
	printf("3.Enter marks for course work 3\n");
	printf("4.Display a particular student's marks\n");
	printf("5.Supervisor mode\n");
	printf("6.Exit program\n");
	printf("------------------------------------------------------------");
	choose(no,name,pin,marks);
}


//This function is used to take the users desired choice from
//the main menu and take them to that screen
int choose(int no, char name[30][no],int pin,int marks[3][no])
{
	int option;
	printf("\n\n\nI would like to select\n\n>>>");
	scanf("%d",&option);
	printf("\n\n\n");
	if (option==1)
	{
		if (marks[4][1]==1)
		{
			printf("------------------------------------------------------------");
			printf("\nThese values have already been entered\n");
			printf("To change these values go to supervisor menu\n");
			printf("------------------------------------------------------------");
			options(no,name,pin,marks);
		}
		else
		{
			mark1(no,name,pin,marks);
			options(no,name,pin,marks);
		}
	}
	else if (option==2)
	{
		if (marks[4][2]==1)
		{
			printf("------------------------------------------------------------");
			printf("\nThese values have already been entered\n");
			printf("To change these values go to supervisor menu\n");
			printf("------------------------------------------------------------");
			options(no,name,pin,marks);
		}
		else
		{
			mark2(no,name,pin,marks);
			options(no,name,pin,marks);
		}
	}
	else if (option==3)
	{
		if (marks[4][3]==1)
		{
			printf("------------------------------------------------------------");
			printf("\nThese values have already been entered\n");
			printf("To change these values go to supervisor menu\n");
			printf("------------------------------------------------------------");
			options(no,name,pin,marks);
		}
		else
		{
			mark3(no,name,pin,marks);
			options(no,name,pin,marks);
		}
	}
	else if (option==4)
	{
		seeStudent(no,name,pin,marks);
	}
	else if (option==5)
	{
		supervisorMode(no,name,pin,marks);
	}
	else if (option==6)
	{
		printf("------------------------------------------------------------");
		printf("\n\nExiting program.....\n");
		exit(0);
	}
	else if (option>6)
	{
		printf("\n\n\n\n Not a valid option");
		printf("Must be between 1-6");
		choose(no,name,pin,marks);
	}
	else if (option<1)
	{
		printf("\n\n\n\n Not a valid option");
		printf("Must be between 1-6");
		choose(no,name,pin,marks);
	}
	options(no,name,pin,marks);
}


//This fucntion takes the marks for the first coursework
//for all of the students
int mark1(int no, char name[30][no],int pin,int marks[3][no])
{
	int value, ID;
	ID=1;
	while (ID<(no+1))
	{
		printf("------------------------------------------------------------");
		printf("\n\nWhat is student number %d's mark for CW 1?",ID);
		printf("\n>>>");
		scanf("%d",&value);
		ID=ID+1;	
		printf("\n\n\n");
		if (value>100)
		{
			printf("Value has to be between 0-100\n");
			mark1(no,name,pin,marks);
		}
		else if (value<0)
		{
			printf("Value has to be between 0-100\n");
			mark1(no,name,pin,marks);
		}
		else
		{
			marks[4][1]=1;
			marks[1][ID]=value; 
		}
	}
	return marks[1][ID];
}


//This function takes the marks for the second coursework
//for all of the students
int mark2(int no,char name[30][no],int pin,int marks[3][no])
{
	int value, ID;
	ID=1;
	while (ID<(no+1))
	{
		printf("\nWhat is student number %d's mark for CW 2?",ID);
		printf("\n>>>");
		scanf("%d",&value);
		ID=ID+1;	
		printf("\n\n\n");
		if (value>100)
		{
			printf("Value has to be between 0-100\n");
			mark2(no,name,pin,marks);
		}
		else if (value<0)
		{
			printf("Value has to be between 0-100\n");
			mark2(no,name,pin,marks);
		}
		else
		{
			marks[4][2]=1;
			marks[2][ID]=value; 
		}
	}
	return marks[2][ID];
}


//This fucntion takes the marks for the third coursework
//for all of the students
int mark3(int no,char name[30][no],int pin,int marks[3][no])
{
	int value, ID;
	ID=1;
	while (ID<(no+1))
	{
		printf("\nWhat is student number %d's mark for CW 3?",ID);
		printf("\n>>>");
		scanf("%d",&value);
		ID=ID+1;	
		printf("\n\n\n");
		if (value>100)
		{
			printf("Value has to be between 0-100\n");
			mark3(no,name,pin,marks);
		}
		else if (value<0)
		{
			printf("Value has to be between 0-100\n");
			mark3(no,name,pin,marks);
		}
		else
		{
			marks[4][3]=1;
			marks[3][ID]=value; 
		}
	}
	return marks[3][ID];
}


//This function is used to look at a students name and marks
//and have them displayed in professional format
void seeStudent(int no,char name[30][no],int pin,int marks[3][no])
{
	int ID,z;
	printf("What is the ID of the Student you wish to view?");
	printf("\n>>>\n\n");
	scanf("%d",&ID);
	if (ID>no)
	{
		printf("There is a maximum of %d students\n",no);
		seeStudent(no,name,pin,marks);
	}
	else if (ID<0)
	{
		printf("The id is between 0-%d\n",no);
		seeStudent(no,name,pin,marks);
	}
	else
	{
		printf("------------------------------------------------------------");
		printf("\n                   Student's ID:%d",ID);
		printf("\n                   Student's Name:%s \n", &name[0][ID]);
		printf("------------------------------------------------------------");
		printf("\n                   CourseWork 1:%d",marks[1][ID]);
		printf("\n                   CourseWork 2:%d",marks[2][ID]);
		printf("\n                   CourseWork 3:%d\n",marks[3][ID]);
		printf("------------------------------------------------------------");
		printf("\n\n\n");
	}
	options(no,name,pin,marks);
}


//This is the function that allows the user to choose options from the
//supervisor menu hence why it has a similar name to the choosing function
// of the main menu
void supervisorChoose(int no, char name[30][no],int pin,int marks[3][no])
{
	int option,newNo;
	printf("\nI would like to select\n\n>>>");
	scanf("%d",&option);
	printf("\n\n\n");
	if (option==1)
	{
		pin=newPin();
		start(no,name,pin,marks);
	}
	else if (option==2)
	{
		changeMark(no,name,pin,marks);
		start(no,name,pin,marks);
	}
	else if (option==3)
	{
		newNo=newNumber(no,name,pin);
		addStudent(no,name,pin,newNo);
		no=newNo;
		start(no,name,pin,marks);
	}
	else if (option==4)
	{
		changeName(no,name);
	    start(no,name,pin,marks);	
	}
	else if (option==5)
	{
		start(no,name,pin,marks);
	}
	else if (option>5)
	{
		printf("\n\n\n\n Not a valid option");
		printf("Must be between 1-5");
		supervisorChoose(no,name,pin,marks);
	}
	else if (option<1)
	{
		printf("\n\n\n\n Not a valid option");
		printf("Must be between 1-5");
		supervisorChoose(no,name,pin,marks);
	};
}


//This function allows the user to change their previously
//entered pin to something different
void changePin(int no, char name[30][no],int pin,int marks[3][no])
{
	options(no,name,pin,marks);
}


//This function allows the user to change the marks of students
//This can't be done in the previous functions because once
//entered this is the only place they can be chnanged from
void changeMark(int no,char name[30][no],int pin,int marks[3][no])
{
	int option;
	printf("What mark are you changing?(1-3)");
	scanf("%d",&option);
	if (option==1)
	{
		mark1(no,name,pin,marks);
	}
	else if (option==2)
	{
		mark2(no,name,pin,marks);
	}
	else if (option==3)
	{
		mark3(no,name,pin,marks);
	}
	else
	{
		printf("Selection must be between 1 and 3");
		changeMark(no,name,pin,marks);
	}
}


//This function allows the changing of a students name 
char changeName(int no, char name[30][no])
{
	int ID,z;
	printf("------------------------------------------------------------");
	printf("\nWhat is the ID of the student?(max 75)\n");
	scanf("%d",&ID);
	printf("------------------------------------------------------------");
	printf("\nWhat is the name of student number %d?",ID);
	printf("\n>>>");
	for(z=0; z<no; z++)
	{
		scanf("%s",&name[z][ID]);
		getchar();	
	}
}


//This function is required in the adding of a new student
//This is as it is used to get the new tital number of
//students located in the array
int newNumber(int no,char name[30][no],int pin)
{
	int newNo,in;
	printf("\nHow many Students do you wish to add?\n");
	printf(">>>");
	scanf("%d",&in);
	if ((in+no)>75)
	{
		printf("Maximum of 75 students allowed\n");
		printf("Entering %d will give you %d students\n",in,(in+no));
		newNumber(no,name, pin);
	}
	else if(in<0)
	{
		printf("You can't remove students'\n");
		newNumber(no,name, pin);	
	}
	else
	{
		newNo=no+in;
		return newNo;
	}
}


//This fucntion uses the output of the last function to add the required
//number of new students to the array
void addStudent(int no,char name[30][no],int pin,int newNo)
{
	int i,z;
	printf("------------------------------------------------------------");
	i=no+1;
	z=0;
	printf("\nStudents names are allowed a max of 22 characters\n");
	printf("------------------------------------------------------------");
	while (i<((newNo)+1))
	{
		printf("\nWhat is the name of student number %d?",i);
		printf("\n>>>");
		for(z=0; z<no; z++)
			scanf("%[^\n]",&name[z][i]);
			getchar();
		i=i+1;	
	}
	no=newNo;
}


//This function exits the user from the supervisor menu and back 
//to the main menu
void exitSupervisor(int no,char name[30][no],int pin,int marks[3][no])
{
	options(no,name,pin,marks);
}

void supervisorOptions(int no,char name[30][no],int pin,int marks[3][no])
{
	printf("\n\n");
	printf("------------------------------------------------------------\n");
	printf("[                      Supervisor Menu                     ]\n");
	printf("------------------------------------------------------------\n");
	printf("!!!                       Warning                        !!!\n");
	printf("!!!     Once you finish your selected option you will    !!!\n");
	printf("!!!             return to the previous menu              !!!\n");
	printf("------------------------------------------------------------\n");
	printf("1.Change your Pin\n");
	printf("2.Change a Students Marks\n");
	printf("3.Add a Student\n");
	printf("4.Change a students name\n");
	printf("5.Return to Previous Menu\n");
	printf("------------------------------------------------------------\n");
	supervisorChoose(no,name,pin,marks);
}


//This function is used to take in a pin and if correct shall
//take them to the supervisor menu, if it is not it shall ask
//ask them if they wish to retry if not they'll be returned
//to the main menu
void supervisorMode(int no,char name[30][no],int pin,int marks[3][no])
{
	int enteredPin,z;
	printf("------------------------------------------------------------");
	printf("\nPlease enter your secure 4-digit pin");
	printf("\n>>>");
	scanf("%d",&enteredPin);
	if (enteredPin==pin)
	{
		supervisorOptions(no,name,pin,marks);
	}
	else
	{
		char o[0];
		printf("\nYou have entered the wrong pin");
		printf("\nDo you wish to try again?");
		printf("\ny or n");
		printf("\n>>>");
		scanf("%s",&o[0]);
		getchar();
		if (o[0]=='y')
		{
			supervisorMode(no, name, pin,marks);
		}
		else
		{
			options(no,name,pin,marks);
		}
	}	
}


//This fucntion is used towards the start of the program to get the total
//number of students that will be in the array
int number(void)
{
	int no,i;
	
	i=1;
	printf("\n[         Welcome to the Coursework Module Marker         ]\n");
	printf("------------------------------------------------------------");		
	printf("\n[         How many students will you be entering?         ]");
	printf("\n[        There is a maximum of 75 at any one time         ]");
	printf("\n>>>");
	scanf("%d",&no);
	getchar();
	printf("------------------------------------------------------------");
	if (no>75)
	{
		printf("\nNumber of students is 75 max\n");
		printf("------------------------------------------------------------");
		number();
	}
	else if (no<1)
	{
		printf("\nNumber of students is between 1-75\n");
			printf("------------------------------------------------------------");
		number();
	}
	return no;
}


//This fucntion is used to get the pin from the user
//This shall be used to gain access to the supervisor menu
int newPin(void)
{
	int pin;
	printf("------------------------------------------------------------");
	printf("\nYou are required set up a secure 4-digit pin\n");
	printf("Please enter this now\n");
	printf("\n>>>");
	scanf("%d",&pin);
	if (pin>9999)
	{
		printf("Must be a 4 digit pin\n");
		newPin();
	}
	return pin;
}


//This function is used to collect the details of the students
void details(void)
{
	int no,i,z,pin,marks[3][no];
	char name[30][no];
	no=number();
	i=1;
	z=0;
	printf("\nStudents names are allowed a max of 30 characters\n");
	printf("------------------------------------------------------------");
	while (i<(no+1))
	{
		printf("\nWhat is the name of student number %d?",i);
		printf("\n>>>");
		for(z=0; z<no; z++)
			scanf("%[^\n]",&name[z][i]);
			getchar();
		i=i+1;	
	}
	pin=newPin();
	printf("------------------------------------------------------------");
	start(no,name,pin,marks);
}

//This function is used to welcome the user to the main menu
//and give them appropriate information on how to use it
void start(int no, char name[30][no],int pin,int marks[3][no])
{
	printf("\n\n\n\n");
	printf("------------------------------------------------------------");	
	printf("\n[             Welcome to the CMM's Main Menu             ]\n");
	printf("------------------------------------------------------------");	
	printf("\nThe following is the list of options available\n");
	printf("To select an option please enter the associated number");
	printf("\nfor that option (1-6)\n");
	options(no,name,pin,marks);	
}


//This is the main function of the program which is used to 
//run the details function and start the program
int main(void)
{
	details();	
	return 0;
}









