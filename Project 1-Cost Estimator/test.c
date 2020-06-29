/***********************************************************************  
* test.c  
* Estimates the cost of a job for an interior decorator    
* Christopher Greer  
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
float plasteringFunc(float ceilingArea,float Area1,float Area2, char plastering[0]);
float paintCost(char paintType[0]);
float paintingCost(float cArea,float Area1,float Area2, float paint);
float hoursCost(float hoursNeeded);
float undercoatCost(char underCoat[0],float cArea,float Area1,float Area2);
float Total(float hCost,float pCost,float plasteringCost,float uCost);
int printInfo(float width,float length,float height,float plasteringCost,float paint,float hoursNeeded,float hCost,float uCost,float Area1,float Area2,float cArea,float pCost,char plastering[0],char paintType[0],char underCoat[0]);

int main(void)
{
	float width,length,height,plasteringCost,paint,hoursNeeded,hCost,uCost,Area1,Area2,cArea,pCost;
	char plastering[0],paintType[0],underCoat[0];
	getLength();
	getHeight();
	getWidth();
	getPaint();
	getPlastering();
	getUndercoat();
	getHours();
	ceilingArea(width,length);
	wall1Area(length,height);
	wall2Area(width,height);
	plasteringFunc(cArea,Area1,Area2,plastering);
	paintCost(paintType);
	paintingCost(cArea,Area1,Area2,paint);
	hoursCost(hoursNeeded);
	undercoatCost(underCoat,cArea,Area1,Area2);
	Total(hCost,pCost,plasteringCost,uCost);
	printInfo(width,length,height,plasteringCost,paint,hoursNeeded,hCost,uCost,Area1,Area2,cArea,pCost,plastering,paintType,underCoat);


	return 0;
}

float getHeight(void)
{
	float height;
	printf("What is the height of your room?");
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
	
float getLength(void)
{
	float length;
	printf("What is the length of you room?");
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

float getWidth(void)
{
	float width;
	printf("What is the width of you room?");
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

char getPaint(void)
{
	char paintType[0];
	printf("What type of paint would like used?");
	printf("Luxury(l), Standard (s) or Economy (e)");
	scanf("%s",&paintType[0]);
	printf("%s", paintType[0]);
	return paintType[0];
}
char getPlastering(void)
{
	float plastering; 
	printf("Is plastering needed?");
	printf("Yes=y No=n");
	scanf(" %s", &plastering);
	return plastering;
}
char getUndercoat(void)
{
	float underCoat;
	printf("Is undercoat paint needed?");
	printf("Yes=y No=n");
	scanf("%s",&underCoat);
	return underCoat;
}
float getHours(void)
{
	float hoursNeeded;
	printf("How long will it take?");
	scanf("%f",&hoursNeeded);
	return hoursNeeded;
}

float ceilingArea(float width,float length)
{
	printf("%f",width);
	float cArea;
	cArea=width*length;
	return cArea;
}

float wall1Area(float length,float height)
{
	float w1,Area1;
	w1=length*height;
	Area1=w1*2;
	return w1,Area1;
}

float wall2Area(float width,float height)
{
	float w2,Area2;
	w2=width*height;
	Area2=w2*2;
	return w2,Area2;
}

float plasteringFunc(float cArea,float Area1,float Area2, char plastering[0])
{
	float plasteringCost,P1,P2,P3;
	if (plastering="n")
	{
		return 0;
	}
	else
	{
		P1=cArea*31;
		P2=Area1*22.55;
		P3=Area2*22.55;
		plasteringCost=P1+P2+P3;
	}
	return plasteringCost;
}

float paintCost(char paintType[0])
{
	float paint;
	if (paintType="l")
	{
		paint=3;
	}
	if (paintType="s")
	{
		paint=1.45;
	}
	if (paintType="e")
	{
		paint=0.75;
	}
	return paint;
}



float paintingCost(float cArea,float Area1,float Area2,float paint)
{
	float c1,c2,c3,pCost;
	char paintType[0];
	c1=cArea*paint;
	c1=Area1*paint;
	c1=Area2*paint;
	pCost=c1+c2+c3;
	return pCost;
}

float hoursCost(float hoursNeeded)
{
	float hCost;
	hCost=hoursNeeded*17.5;
	if (hCost<120)
	{
		hCost=120;
	}
	return hCost;
}

float undercoatCost(char underCoat[0],float cArea,float Area1,float Area2)
{
	float uCost,tArea;
	if (underCoat="n")
	{
		return 0;
	}
	else
	{
		tArea=cArea+Area1+Area2;
		uCost=tArea*0.5;
		return uCost;
	}
	
}

float Total(float hCost,float pCost,float plasteringCost,float uCost)
{
	float totalF,t;
	t=hCost+pCost+plasteringCost+uCost;
	totalF=t*1.2;
	return totalF,t;
}

int printInfo(float width,float length,float height,float plasteringCost,float paint,float hoursNeeded,float hCost,float uCost,float Area1,float Area2,float cArea,float pCost,char plastering[0],char paintType[0],char underCoat[0])
{
	printf("_______________________________________________________________\n");
	printf("]                        Cost Estimator                        [\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                         Room Dimensions                    ][\n");
	printf("][Height][Length][Width][Ceiling Area][Wall Area 1][Wall Area1][\n");
	printf("][ %f m][ %f m][%f  m][   %f  m^2  ][   %f m^2  ][  %f m^2  ][\n",
	height,length,width,cArea,Area1,Area2);
	printf("]--------------------------------------------------------------[\n");
	printf("][                            Choices                         ][\n");
	printf("][  PaintType ][    Hours   ][  Plastering  ][    UnderCoat   ][\n");
	printf("][     %s      ][      %f     ][      %s       ][        %s       ][\n",
	paintType,hoursNeeded,plastering,underCoat);
	printf("]--------------------------------------------------------------[\n");
	printf("][                         Costs                       ][\n");
	printf("][   Paint   ][   Labour    ][   Plastering ][    UnderCoat   ][\n");
	printf("][    £%f    ][     £%f     ][      £%f     ][       £%f      ][\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                      Total Costs                    ][\n");
	printf("]            Total:            ][       Total with VAT:       ][\n");
	printf("][            £%f              ][             £%f             ][\n");
	printf("_______________________________________________________________\n");
	return 0;
}



