#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - Print the remaining days of the year.
 * @month: month of the year.
 * @day: day of the year.
 * @year: the current year.
 * Return: void.
 */
void print_remaining_days(int month, int day, int year)
{
	int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (is_leap && month > 2)
		day++;

	if (is_leap)
	{
		printf("Day of the year: %d\n", day);
		printf("Remaining days: %d\n", 366 - day);
	}
	else
	{
		if (month == 2 && day == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		}
		else
		{
			printf("Day of the year: %d\n", day);
			printf("Remaining days: %d\n", 365 - day);
		}
	}
}
