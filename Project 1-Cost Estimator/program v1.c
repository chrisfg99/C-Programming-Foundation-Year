/***********************************************************************  
* test.c  
* Estimates the cost of a job for an interior decorator    
* Christopher Greer, candidate number:184521  
* October 2017  
* ********************************************************************/ 

#include <stdio.h>

#include <stdlib.h>

float getLength(void);
float getHeight(void);
float getWidth(void);
char getPaint(void);
char getPlastering(void);
char getUndercoat(void);
float getHours(void);
float ceilingArea(float width,float length);
float wall1Area(float length,float height);
float wall2Area(float width,float height);
float plasteringFunc(float ceilingArea,float Area1,float Area2, char plastering);
float paintCost(char paintType);
float paintingCost(float cArea,float Area1,float Area2, float paint, float width, float length, float height);
float hoursCost(float hoursNeeded);
float undercoatCost(char underCoat,float cArea,float Area1,float Area2,float width, float length,float height);
float Total(float hCost,float pCost,float plasteringCost,float uCost);
float totalFinal(float t);
int printInfo();

int main(void)
{
	

	
	//This is where all welcome infomation is displayed//
	printf("Welcome to the Cost Estimator\n");
	printf("The idea of this program is to work out the cost of decorating the given room.\n\n\n");
	printf("Here is a guide on how best to use this program:\n");
	printf("1. When answering a yes or no statement enter y or n instead of yes or no\n");
	printf("2. Width and Length must be within parameters of 1.8m-7.5m\n");
	printf("3. Height must be within parameters of 2.1m-4.25m\n\n");
	
	printInfo();


	return 0;
}

//Below is the function to get the height//
float getHeight(void)
{
	float height;
	printf("\nWhat is the height of your room?");
	scanf("%f",&height);
	
	if(height>4.25)
		{printf("Not within parameters of 2.1m-4.25m\a\n");
		exit(0);
	}
	if(height<2.1)
		{printf("Not within parameters of 2.1m-4.25m\a\n");
		exit(0);
	}
	return height;
}

//Below is the function to get the length//
float getLength(void)
{
	float length;
	printf("\nWhat is the length of you room?");
	scanf("%f",&length);
	if(length<1.8)
		{printf("Not within parameters of 1.8m-7.5m\a\n");
		exit(0);
	}
	if(length>7.5)
		{printf("Not within parameters of 1.8m-7.5m\a\n");
		exit(0);
	}
	return length;
}

//Below is the function to get the width//
float getWidth(void)
{
	float width;
	printf("\nWhat is the width of you room?");
	scanf("%f",&width);
	if(width<1.8)
		{printf("Not within parameters of 1.8m-7.5m\a\n");
		exit(0);
		}
	if(width>7.5)
		{printf("Not within parameters of 1.8m-7.5m\a\n");
		exit(0);
		}
	return width;
}

//Below is the function to get the type of paint//
char getPaint(void)
{
	char l[0], paintType;
	printf("\nWhat type of paint would like used?");
	printf("\nLuxury(l), Standard (s) or Economy (e)");
	scanf("%s",&l);
	
	paintType=l[0];
	paintCost(paintType);
	return paintType;

	}

//Below is the function to see whether plastering is needed//
char getPlastering(void)
{
	char p[0],plastering; 
	printf("\nIs plastering needed?");
	printf("\nYes=y No=n");
	scanf(" %s", &p);
		if (p[0]=='y')
	{
		return 'y';
	}
	else if (p[0]=='n')
	{
		return 'n';	
	}
	else
	{
		printf("Wrong input for Plastering");
		getPlastering();
	}
	
	
	plastering=p[0];
	return plastering;
}

//Below is the function to see whether an Undercoat is needed//
char getUndercoat(void)
{
	char uc[0],underCoat; 
	printf("\nIs undercoating needed?");
	printf("\nYes=y No=n");
	scanf(" %c", &uc);
	if (uc[0]=='y')
	{
		return 'y';
	}
	else if (uc[0]=='n')
	{
		return 'n';	
	}
	else
	{
		printf("Wrong input for underCoat");
		getUndercoat();
	}
	
	underCoat=uc[0];
	printf("%c",underCoat);
	return underCoat;
}

//Below is the function to see how many hours are needed//
float getHours(void)
{
	float hoursNeeded,h;
	printf("\nHow long will it take?\n In hours?");
	scanf("%f",&h);
	hoursNeeded=h;
	return hoursNeeded;
}

//This function calculates the area of the ceiling//
float ceilingArea(float width,float length)
{
	float cArea;
	cArea=width*length;
	return cArea;
}

//This function calculates the area of a wall//
float wall1Area(float length,float height)
{
	float Area1;
	Area1=(length*height)*2;
	return Area1;
}

//This function calculates the area of the other wall//
float wall2Area(float width,float height)
{
	float Area2;
	Area2=(width*height)*2;
	return Area2;
}

//This function calculates the cost of the plastering//
float plasteringFunc(float cArea,float Area1,float Area2, char plastering)
{
	float plasteringCost,P1,P2,P3;
	char p;
	p=plastering;
	if (p=='y')
	{
		plasteringCost=(cArea*31)+(Area1*22.55)+(Area2*22.55);
		return plasteringCost;
	}
	else if (p=='n')
	{
		return 0;
	}
	else
	{
		printf("Wrong input for plastering");
		getPlastering();
	}
	return p;	
}

//This function works out what paint type was given//
float paintCost(char paintType)
{
	float paint;
	if (paintType=='l')
	{
		return 3;
	}
	else if (paintType=='s')
	{
		return 1.45;
	}
	else if (paintType=='e')
	{
		return 0.75;
	}
	else
	{
		printf("Wrong input for paint type");
		getPaint();
	}
}

//This function calculates the cost of the painting//
float paintingCost(float cArea,float Area1,float Area2,float paint,float width, float length, float height)
{
	float c1,c2,c3,pCost,p;
	cArea=ceilingArea(width,length);
	Area1=wall1Area(length,height);
	Area2=wall2Area(width,height);
	p=Area1+Area2+cArea;
	pCost=p*paint;
	return pCost;
}

//This function calculates the cost of labour//
float hoursCost(float hoursNeeded)
{
	float hCost;
	char q;
	hCost=hoursNeeded*17.5;
	if (hCost<120)
	{
		hCost=120;
	}
	else if (hoursNeeded>99)
	{
		printf("This exceeds the maximum amount of hours.\n");
		printf("Are you sure you want to do this?");
		scanf("%s",&q);
		if (q=='y')
		{
			hCost=hoursNeeded*17.5;
			return hCost;
		}
		else
		{
			hoursNeeded=getHours();
		}
	}
	return hCost;
}

//This function calculates the cost of the undercoat//
float undercoatCost(char underCoat,float cArea,float Area1,float Area2,float width, float length,float height)
{
	float uCost,tArea;
	char uc;
	cArea=ceilingArea(width,length);
	Area1=wall1Area(length,height);
	Area2=wall2Area(width,height);
	uc=underCoat;
	if (uc=='y')
	{
		tArea=cArea+Area1+Area2;
		uCost=tArea*0.5;
		return uCost;
	}
	else if (uc='n')
	{
		return 0;
	}
	else
	{
		printf("Wrong input for underCoat");
		getUndercoat();
	}	
}

//This function adds up all of the costs to give a total//
float Total(float hCost,float pCost,float plasteringCost,float uCost)
{

	float t;
	t=hCost+pCost+plasteringCost+uCost;
	return t;
}

//This function takes the total and adds the VAT//
float totalFinal(float t)
{
	float totalF;
	totalF=t*1.2;
	return totalF;
}

//This function displays all of the information in a format that can be easily read//
int printInfo()
{
	char pound=156 ;
	//This is where the main Variables are defined//
	float width, length, height, plasteringCost, paint, hoursNeeded, hCost, uCost, Area1, Area2, cArea,
	 pCost, totalF,  t;
	 char plastering, paintType, underCoat;	
	 
	//Here is where all of the seperate funcions are called and variables assigned//
	paintType=getPaint();
	paint=paintCost(paintType);
	plastering=getPlastering();
	underCoat=getUndercoat();
	hoursNeeded=getHours();
	hCost=hoursCost(hoursNeeded);
	length=getLength();
	height=getHeight();
	width=getWidth();
	uCost=undercoatCost(underCoat,cArea,Area1,Area2,width,length,height);
	cArea=ceilingArea(width,length);
	Area1=wall1Area(length,height);
	Area2=wall2Area(width,height);
	plasteringCost=plasteringFunc(cArea,Area1,Area2,plastering);
	pCost=paintingCost(cArea,Area1,Area2,paint,width,length,height);
	t=Total(hCost,pCost,plasteringCost,uCost);
	totalF=totalFinal(t);
	printf("_______________________________________________________________\n");
	printf("]                        Cost Estimator                        [\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                       Room Dimensions                      ][\n");
	printf("][Height][Length][Width][Ceiling  Area][Wall Area1][Wall Area2][\n");
	printf("][ %.2fm][%.2f m][%.2fm][ %.2f  m^2 ][ %.2f m^2 ][ %.2f m^2 ][\n",
	height,length,width,cArea,Area1/2,Area2/2);
	printf("]--------------------------------------------------------------[\n");
	printf("][                          Choices                           ][\n");
	printf("][  PaintType ][    Hours   ][  Plastering  ][    UnderCoat   ][\n");
	printf("][     %c      ][    %.1f     ][      %c       ][        %c       ][\n",
	paintType,hoursNeeded,plastering,underCoat);
	printf("]--------------------------------------------------------------[\n");
	printf("][                           Costs                            ][\n");
	printf("][   Paint   ][   Labour    ][   Plastering ][    UnderCoat   ][\n");
	printf("][   %c%.2f  ][   %c%.2f   ][    %c%.2f  ][      %c%.2f    ][\n",
	pound,pCost,pound,hoursCost(hoursNeeded),pound,plasteringCost,pound,uCost);
	printf("]--------------------------------------------------------------[\n");
	printf("][                        Total Costs                         ][\n");
	printf("][            Total:             ][       Total with VAT:     ][\n");
	printf("][            %c%.2f           ][           %c%.2f        ][\n",
	pound,t,pound,totalF);
	printf("_______________________________________________________________\n");
	return 0;
}





