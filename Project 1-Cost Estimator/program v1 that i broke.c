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
float plasteringFunc(float ceilingArea,float Area1,float Area2, char plastering);
float paintCost(char paintType);
float paintingCost(float cArea,float Area1,float Area2, float paint);
float hoursCost();
float undercoatCost(float cArea,float Area1,float Area2);
float Total(float hCost,float pCost,float plasteringCost,float uCost);
float totalFinal(float t);
int printInfo(float width,float length,float height,float plasteringCost,float paint,
float hoursNeeded,float hCost,float uCost,float Area1,float Area2,float cArea,
float pCost,char plastering,char paintType,char underCoat,float totalF, float t);

int main(void)
{
	//This is where the main Variables are defined//
	
	float width,length,height,plasteringCost,paint,hoursNeeded,hCost,uCost,Area1,Area2,cArea,pCost,totalF, t;
	char plastering,paintType,underCoat;
	
	//This is where all welcome infomation is displayed//
	printf("Welcome to the Cost Estimator\n");
	printf("The idea of this program is to work out the cost of decorating the given room.\n\n\n");
	printf("Here is a guide on how best to use this program:\n");
	printf("1. When answering a yes or no statement enter y or n instead of yes or no\n");
	printf("2. Width and Length must be within parameters of 1.8m-7.5m\n");
	printf("3. Height must be within parameters of 2.1m-4.25m\n\n");
	
	//Here is where all of the seperate funcions are called and variables assigned//
	paintType=getPaint();
	paint=paintCost(paintType);
	hCost=hoursCost(hoursNeeded);
	length=getLength();
	height=getHeight();
	width=getWidth();
	cArea=width*length;
	Area1=(length*height)*2;
	Area2=(width*height)*2;
	uCost=undercoatCost(cArea,Area1,Area2);
	plasteringCost=plasteringFunc(cArea,Area1,Area2,plastering);
	pCost=paintingCost(cArea,Area1,Area2,paint);
	
	//This function adds up all of the costs to give a total//
	t=hCost+pCost+plasteringCost+uCost;
	//This line takes the total and adds the VAT//
	totalF=t*1.2;
	printInfo(width,length,height,plasteringCost,paint,hoursNeeded,hCost,uCost,Area1,
	 Area2,cArea,pCost,plastering,paintType,underCoat,totalF,t);
	return 0;
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

//This function calculates the cost of the painting//
float paintingCost(float cArea,float Area1,float Area2,float paint)
{
	float c1,c2,c3,pCost;
	char paintType[0];
	printf("%f",cArea);
	c1=cArea*paint;
	c1=Area1*paint;
	c1=Area2*paint;
	pCost=c1+c2+c3;
	return pCost;
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
	else if(length>7.5)
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



//Below is the function to see whether plastering is needed//
char getPlastering(void)
{
	char l[0],plastering; 
	printf("\nIs plastering needed?");
	printf("Yes=y No=n");
	scanf(" %s", &l);
	
	plastering=l[0];
	return plastering;
}

//Below is the function to see whether an Undercoat is needed//
char getUndercoat(void)
{
	char l[0],underCoat; 
	printf("\nIs undercoat needed?");
	printf("Yes=y No=n");
	scanf(" %s", &l);
	
	underCoat=l[0];
	return underCoat;
}

//Below is the function to see how many hours are needed//
float getHours(void)
{
	float hoursNeeded;
	printf("\nHow long will it take?");
	scanf("%f",&hoursNeeded);
	return hoursNeeded;
}

//This function calculates the area of the ceiling//
float ceilingArea(float width,float length)
{
	float cArea;
	
	return cArea;
}

//This function calculates the area of a wall//
float wall1Area(float length,float height)
{
	float w1,Area1;
	
	return Area1;
}

//This function calculates the area of the other wall//
float wall2Area(float width,float height)
{
	float w2,Area2;
	w2=width*height;
	Area2=w2*2;
	return Area2;
}

//This function calculates the cost of the plastering//
float plasteringFunc(float cArea,float Area1,float Area2, char plastering)
{
	float plasteringCost,P1,P2,P3;
	plastering=getPlastering();
	if (plastering='y')
	{
		P1=cArea*31;
		P2=Area1*22.55;
		P3=Area2*22.55;
		plasteringCost=P1+P2+P3;
		return plasteringCost;
	}
	else if (plastering='n')
	{
		plasteringCost=0;
		return plasteringCost;
	}
	else
	{
		printf("Wrong input for plastering");
		getPlastering();
	}
}

//This function works out what paint type was given//
float paintCost(char paintType)
{
	float paint;
	if (paintType=='l')
	{
		paint=3;
		return paint;
	}
	else if (paintType=='s')
	{
		paint=1.45;
		return paint;
	}
	else if (paintType=='e')
	{
		paint=0.75;
		return paint;
	}
	else
	{
		printf("Wrong input for paint type");
		getPaint();
	}
}



//This function calculates the cost of labour//
float hoursCost()
{
	char hoursNeeded;
	hoursNeeded=getHours();
	float hCost;
	hCost=hoursNeeded*17.5;
	if (hCost<120)
	{
		hCost=120;
	}
	return hCost;
}

//This function calculates the cost of the undercoat//
float undercoatCost(float cArea,float Area1,float Area2)
{
	float uCost,tArea;
	char underCoat;
	underCoat=getUndercoat();
	if (underCoat=='n')
	{
		return 0;
	}
	else if (underCoat=='y')
	{
		tArea=cArea+Area1+Area2;
		uCost=tArea*0.5;
		return uCost;
	}
	else
	{
		printf("Wrong input for underCoat");
		getUndercoat();
	}
	
}





//This function displays all of the information in a format that can be easily read//
int printInfo(float width,float length,float height,float plasteringCost,float paint,
 float hoursNeeded,float hCost,float uCost,float Area1,float Area2,float cArea,float pCost,
 char plastering,char paintType,char underCoat,float totalF, float t)
{
	char pound=156 ;
	printf("_______________________________________________________________\n");
	printf("]                        Cost Estimator                        [\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                       Room Dimensions                      ][\n");
	printf("][Height][Length][Width][Ceiling  Area][Wall Area1][Wall Area2][\n");
	printf("][ %.2fm][%.2f m][%.2fm][ %.2f  m^2 ][ %.2f m^2][ %.2f m^2][\n",
	height,length,width,cArea,Area1/2,Area1/2);
	printf("]--------------------------------------------------------------[\n");
	printf("][                          Choices                           ][\n");
	printf("][  PaintType ][    Hours   ][  Plastering  ][    UnderCoat   ][\n");
	printf("][     %c      ][    %.1f     ][      %c       ][        %c       ][\n",
	paintType,hoursNeeded,plastering,underCoat);
	printf("]--------------------------------------------------------------[\n");
	printf("][                           Costs                            ][\n");
	printf("][   Paint   ][   Labour    ][   Plastering ][    UnderCoat   ][\n");
	printf("][   %c%.2f  ][   %c%.2f   ][     %c%.2f    ][      %c%.2f     ][\n",
	pound,pCost,pound,hCost,pound,plasteringCost,pound,uCost);
	printf("]--------------------------------------------------------------[\n");
	printf("][                        Total Costs                         ][\n");
	printf("][            Total:             ][       Total with VAT:     ][\n");
	printf("][            %c%.2f            ][           %c%.2f         ][\n",
	pound,t,pound,totalF);
	printf("_______________________________________________________________\n");
	return 0;
}



