/***********************************************************************  
* print.c  
* Estimates the cost of a job for an interior decorator    
* Christopher Greer  
* October 2017  
* ********************************************************************/ 

#include <stdio.h>

int main(void)
{
	printf("_______________________________________________________________\n");
	printf("]                        Cost Estimator                        [\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                         Room Dimensions                    ][\n");
	printf("][Height][Length][Width][Ceiling Area][Wall Area 1][Wall Area1][\n");
	printf("][ 2.4 m][ 2.4 m][2.4 m][   2.4 m^2  ][   2.4m^2  ][  2.4m^2  ][\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                            Choices                         ][\n");
	printf("][  PaintType ][    Hours   ][  Plastering  ][    UnderCoat   ][\n");
	printf("][     l      ][      y     ][      y       ][        y       ][\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                         Costs                       ][\n");
	printf("][   Paint   ][   Labour    ][   Plastering ][    UnderCoat   ][\n");
	printf("][     l     ][      y      ][       y      ][        y       ][\n");
	printf("]--------------------------------------------------------------[\n");
	printf("][                      Total Costs                    ][\n");
	printf("]            Total:            ][       Total with VAT:       ][\n");
	printf("][             110             ][             110             ][\n");
	printf("_______________________________________________________________\n");
	return 0;
}

