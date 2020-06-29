	for(i=0;notToBe[i] !='\0'; ++i)
	{
		chr=notToBe[i];
		if(chr >='a'&& chr<='s')
		{
			chr=chr+key;
		}
		if(chr >='t'&& chr<='z')
		{
			chr=chr+68;
		}
		else if(chr>='A' && chr<='S')
		{
			chr=chr-key;
		}
		else if(chr>='T' && chr<='Z')
		{
			chr=chr-13;
		}
		else if(chr>='0' && chr<='2')
		{
			chr=chr-key;
		}
		else if(chr>='3' && chr<='9')
		{
			chr=chr-14;
		}
		notToBe[i]=chr;
	}
