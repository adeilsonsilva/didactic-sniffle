#include <stdio.h>

/**
 * "We made it char to illustrate a legitimate use of char for storing small
 * non-character integers".
 */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/**
 * @brief Set day of year from month and day
 *
 * @param year
 * @param month
 * @param day
 *
 * @return int Ordered number of the day inside year
 */
int day_of_year (int year, int month, int day)
{
    char *p;
    int i, leap;

    if (year < 1752 || month < 1 || month > 12 || day < 0 || day > 31) { return -1; }

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    /* Set a pointer to the correct row and col*/
    p = &daytab[leap][1];

    while ((p - daytab[leap]) < month)
        day += *p++;

    return day;
}

/**
 * @brief Set month and day based on day of year
 *
 * @param year
 * @param yearday
 * @param pmonth Place to save computed month
 * @param pday   Place to save computed day
 */
int month_day (int year, int yearday, int *pmonth, int *pday)
{
    char *p;
    int i, leap;

    if (year < 1752 || yearday < 1 || yearday > 366) {
        return -1;
    }

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if ((leap == 1 && yearday > 366) || (leap == 0 && yearday > 365))
        return -1;

    /* Set a pointer to the correct row and col*/
    p = &daytab[leap][1];
    while (yearday > *p && (p - daytab[leap]) < 13)
        yearday -= *p++;

    *pmonth = (p - daytab[leap]);
    *pday = yearday;

    return 1;
}

main ()
{
    int month = 0, day = 0;

    printf("[*] %d-%d-%d: %dth day.\n", 1925, 8, 14, day_of_year(1925, 8, 14));

    if (month_day(1967, 27, &month, &day) > 0) {
        printf("[*] The %dth day of %d is the day %d-%d-%d.\n", 27, 1967, 1967, month, day);
    }
}
