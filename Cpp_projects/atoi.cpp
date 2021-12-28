#include<bits/stdc++.h>

double my_atoi(char * str, bool * status = NULL)
{
	if(status)
		*status = true;
	if(!str || str[0]=='\0'){
		if(status)
			*status = false;
		return 0;
	}
	bool isnegative = false;
	int i = 0;
	if(str[0]=='-'){
		isnegative = true;
		i++;
	}
	int len = 0;
	int n = i;
	while(str[n]!='\0')
	{
		if(str[n]=='.')
			break;
		len++;
		n++;
	}
	double multiplier;
	double my_num = 0;
	
	multiplier =  pow(10, len-1);

	while(str[i])
	{
		if((str[i]>='0' && str[i]<='9') || str[i]=='.')
		{
			if(str[i]=='.'){
				i++;
				continue;
			}
			if(isnegative)
			{
				my_num -= (str[i] - '0') * multiplier;
			}
			else
			{
				my_num += (str[i] - '0') * multiplier;
			}
			multiplier /= 10;
		}
		else
		{
			if(status)
				*status = false;
			return 0;
		}
		i++;
	}
	return my_num;
}
	

int main()
{
	char str[100];
	scanf("%s", str);
	bool status = true;
	double num = my_atoi(str);
	if(status)
	{
		printf("%f", num);
	}
}
