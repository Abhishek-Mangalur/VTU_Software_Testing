#include <stdio.h>

int check (int day, int month)
{
	if(( month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return 1;
	else 
		return 0;
}

int isleap (int year)
{
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else 
		return 0;
}

int main()
{
	int day,month,year,tday,tmonth,tyear;
	char flag;

	do
	{
		flag = 'y';
		printf("Enter the date:");	
		scanf("%d", &day);
		printf("Enter the month:");	
		scanf("%d", &month);
		printf("Enter the year:");	
		scanf("%d", &year);
		tmonth = month;
		tyear = year;

		if (day < 1 || day > 31)
		{
			printf("Day not in range of 1-31\n");
			flag = 'n';
		}
		if(month < 1 || month > 12)
		{
			printf("Month is not in range of 1-12\n");
			flag = 'n';
		}
		else if(check (day,month))
		{
			printf("Day not in the range of 1-31\n");
			flag = 'n';
		}
		if(year < 1812 || year > 2013)
		{
			printf("Year not in the range of 1811-2013\n");
			flag = 'n';
		}
		if(month == 2)
		{
			if(isleap(year) && day > 29)
			{
				printf("Invalid input for leap year\n");
				flag = 'n';
			}
			else if(!(isleap(year)) && day > 28)
			{
				printf("Invalid input for leap year\n");
				flag = 'n';
			}
		}
	}while(flag == 'n');

	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:if(day < 31)
					tday = day + 1;
				else{
					tday = 1;
					tmonth = month + 1;
				}
				break;
        
		case 4:
		case 6:
		case 9:
		case 11: if(day < 30)
					tday = day + 1;
				else{
					tday = 1;
					tmonth = month + 1;
				}
				break;

		case 12: if(day < 31)
					tday = day + 1;
				else{
					tday = 1;
					tmonth = 1;
					if(year == 2013){
						printf("The next day out of boundary year\n");
						tyear += 1;
					}
					else
						tyear += 1;
				}
				break;

		case 2: if(day < 28)
					tday = day + 1;
				else if(isleap(year) && day == 28)
					tday = day + 1;
				else if(day == 28 || day == 29)
				{
					tday = 1;
					tmonth = 3;
				}
				break;
	}
	printf("Next date is: %d/%d/%d\n", tday, tmonth, tyear);
	return 0;
}
