#include <stdio.h>
#include "main.h"

/**
 * calculate_day_of_year - Calculate the nth day of the year.
 * @month: month of the year.
 * @day: day of the month.
 * @is_leap: whether the year is a leap year.
 * Return: day of the year.
 */
int calculate_day_of_year(int month, int day, int is_leap)
{
	int total_days = day;

	if (is_leap && month > 2)
	{
		total_days++;
	}

	if (month > 1)
		total_days += 31;
	if (month > 2)
		total_days += is_leap ? 29 : 28;
	if (month > 3)
		total_days += 31;
	if (month > 4)
		total_days += 30;
	if (month > 5)
		total_days += 31;
	if (month > 6)
		total_days += 30;
	if (month > 7)
		total_days += 31;
	if (month > 8)
		total_days += 31;
	if (month > 9)
		total_days += 30;
	if (month > 10)
		total_days += 31;
	if (month > 11)
		total_days += 30;

	return (total_days);
}

/**
 * print_remaining_days - Print the remaining days of the year.
 * @month: month of the year.
 * @day: day of the month.
 * @year: the current year.
 * Return: void.
 */
void print_remaining_days(int month, int day, int year)
{
	int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int total_days = calculate_day_of_year(month, day, is_leap);

	if (is_leap)
	{
		printf("Day of the year: %d\n", total_days);
		printf("Remaining days: %d\n", 366 - total_days);
	}
	else
	{
		if (month == 2 && day == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		}
		else
		{
			printf("Day of the year: %d\n", total_days);
			printf("Remaining days: %d\n", 365 - total_days);
		}
	}
}
