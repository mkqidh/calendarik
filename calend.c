#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h> 
#include <stdbool.h>
#pragma warning(disable : 4996)

#define TIME_MAX_SIZE 6
#define DATE_MAX_SIZE 8

void Date(int date[])
{
    char ch;
    int k = 0;
    printf("Введите дату: ");
    for (int i = 0; i < 8; i++) {
        date[i] = -1;
    }
    while (1)
    {
        while (date[7] == -1) {
            ch = _getch();
            if (ch != 8) {
                if (ch == 46 || ch == 47) {
                    if (k == 1 || k == 3) {
                        date[k] = date[k - 1];
                        date[k - 1] = 0;
                        k++;
                        system("cls");
                        printf("Введите дату: ");
                        for (int i = 0; i < 8; i++) {
                            if (date[i] != -1) {
                                printf("%d", date[i]);
                                if (i == 1 || i == 3) {
                                    printf(".");
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                else {
                    if (isdigit(ch)) {
                        if (k < DATE_MAX_SIZE) {
                            sscanf_s(&ch, "%d", &date[k]);
                            k++;
                            system("cls");
                            printf("Введите дату: ");
                            for (int i = 0; i < 8; i++) {
                                if (date[i] != -1) {
                                    printf("%d", date[i]);
                                    if (i == 1 || i == 3) printf(".");
                                }
                                else break;
                            }
                        }
                    }
                }
            }
            else if (ch == 8) {
                if (k > 0) { date[k - 1] = -1; }
                else { date[0] = -1; }
                if (k > 0) { k--; }
                else { k = 0; }
                system("cls");
                printf("Введите дату: ");
                for (int i = 0; i < 8; i++) {
                    if (date[i] != -1) {
                        printf("%d", date[i]);
                        if (i == 1 || i == 3) {
                            printf(".");
                        }
                    }
                    else break;
                }
            }
        }
        return;
    }

}

void Time(int time[])
{
    char ch;
    int k = 0;
    printf("Введите время: ");
    for (int i = 0; i < 6; i++) {
        time[i] = -1;
    }
    while (1)
    {
        while (time[5] == -1) {
            ch = _getch();
            if (ch != 8) {
                if (ch == '58') {
                    if (k == 1 || k == 3) {
                        time[k] = time[k - 1];
                        time[k - 1] = 0;
                        k++;
                        system("cls");
                        printf("Введите время: ");
                        for (int i = 0; i < 6; i++) {
                            if (time[i] != -1) {
                                printf("%d", time[i]);
                                if (i == 1 || i == 3) {
                                    printf(":");
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                else if (ch == 13 && k == 5) {
                    time[5] = time[4];
                    time[4] = 0;
                }
                else {
                    if (isdigit(ch)) {
                        if (k < TIME_MAX_SIZE) {
                            sscanf_s(&ch, "%d", &time[k]);
                            k++;
                            system("cls");
                            printf("Введите время: ");
                            for (int i = 0; i < 6; i++) {
                                if (time[i] != -1) {
                                    printf("%d", time[i]);
                                    if (i == 1 || i == 3)
                                        printf(":");
                                }
                                else break;
                            }
                        }
                    }
                }
            }
            else if (ch == 8) {
                if (k > 0) { time[k - 1] = -1; }
                else { time[0] = -1; }
                if (k > 0) { k--; }
                else { k = 0; }
                system("cls");
                printf("Введите время: ");
                for (int i = 0; i < 6; i++) {
                    if (time[i] != -1) {
                        printf("%d", time[i]);
                        if (i == 1 || i == 3) {
                            printf(":");
                        }
                    }
                    else break;
                }
            }
        }
        return;
    }

}

bool leapYear(int year) {
    bool flag = false;
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    else {
        if (year % 4 == 0 && year % 100 != 0) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    return flag;
}

int daysInMonth(int day, int month, int year)
{
    day = 0;
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
        day = 31;
    }
    else {
        if (month == 2) {
            if (leapYear(year)) {
                day = 29;
            }
            else {
                day = 28;
            }
        }
        else {
            day = 30;
        }
    }
    return day;
}

int daysInData(int day, int month, int year) {
    int alldays = 0;
    alldays = day;
    while (year > 0 || (year == 0 && month > 1)) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        alldays += daysInMonth(0, month, year);
    }
    return alldays;
}

int secondsInTime(int hour, int minutes, int seconds) {
    int allseconds = 0;
    allseconds = hour * 3600 + minutes * 60 + seconds;
    return allseconds;
}

void TimeDifference(int d1, int d2, int m1, int m2, int y1, int y2, int h1, int h2, int min1, int min2, int s1, int s2, bool pr1, bool pr2, bool pr3, bool pr4)
{
    int dif_data;
    int dif_time;
    if (pr1 && pr2 && pr3 && pr4)
    {
        int did1 = daysInData(d1, m1, y1);
        int did2 = daysInData(d2, m2, y2);
        int sit1 = secondsInTime(h1, min1, s1);
        int sit2 = secondsInTime(h2, min2, s2);
        if (did1 >= did2) {
            dif_data = did1 - did2;
            if (sit1 > sit2) {
                dif_time = sit1 - sit2;
            }
            else if (sit1 == sit2) {
                dif_time = 0;
            }
            else if (sit1 < sit2) {
                dif_data = dif_data - 1;
                dif_time = sit1 + 24 * 3600 - sit2;
            }
        }
        else
        {
            dif_data = did2 - did1;
            if (sit2 > sit1) {
                dif_time = sit2 - sit1;
            }
            else if (sit1 == sit2) {
                dif_time = 0;
            }
            else if (sit2 < sit1) {
                dif_data = dif_data - 1;
                dif_time = sit2 + 24 * 3600 - sit1;
            }
        }
        int hoursDif = dif_time / 3600;
        dif_time = dif_time - hoursDif * 3600;
        int minutesDif = dif_time / 60;
        dif_time = dif_time - minutesDif * 60;
        int secondsDif = dif_time;
        printf("Разница между датами: дни: %d, часы: %02d, минуты: %02d, секунды: %02d", dif_data, hoursDif, minutesDif, secondsDif);
    }
    else {
        printf("Неверный формат входных данных");
    }
}

int readNumber()
{
    char input[20];
    int number;
    while (1)
    {
        printf("Введите число от -10000 до 10000: ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) {
            printf("Ошибка: ввод не может быть пустым.");
            _getch();
            system("cls");
            continue;
        }
        int valid = 1;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]) && !(i == 0 && (input[i] == '-')))
            {
                valid = 0;
                break;
            }
        }
        if (valid)
        {
            number = atoi(input);
            if (number >= -10000 && number <= 10000)
            {
                break;
            }
            else
            {
                printf("Ошибка: число должно быть от -10000 до 10000. ");
                _getch();
                system("cls");
            }
        }
        else
        {
            printf("Ошибка: это не число.");
            _getch();
            system("cls");
        }
    }
    return number;
}

void addDays(int day, int month, int year, int daysToAdd)
{
    const char* days[] = { "Суббота" , "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница" };
    int newDay;
    int newMonth;
    int newYear;
    int NewWeek;

    day += daysToAdd;

    while (day > daysInMonth(day, month, year)) {
        day -= daysInMonth(day, month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(day, month, year);
    }
    newDay = day;
    newMonth = month;
    newYear = year;

    if (newYear > 2030)
    {
        printf("Выход за пределы диапазона, введите другие значения");
    }
    else
    {
        if (day != 0 && daysToAdd != 0)
        {
            NewWeek = DayOfWeek(day, month, year);
            printf("Новая дата : %02d.%02d.%04d, %s \n", newDay, newMonth, newYear, days[NewWeek]);
        }
        else
        {
            printf("Неверный формат входных данных");
        }
    }

}

int DayOfWeek(int day, int month, int year)
{

    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;
    int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;

    return (dayOfWeek + 7) % 7;
}


int main()
{
    int days1 = 0, months1 = 0, years1 = 0;
    int days2 = 0, months2 = 0, years2 = 0;
    int hours1 = 0, minutes1 = 0, seconds1 = 0;
    int hours2 = 0, minutes2 = 0, seconds2 = 0;
    int daysAdd = 0;

    int week1 = 0, week2 = 0, week3 = 0;
    const char* days[] = { "Суббота" , "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница" };

    int date[DATE_MAX_SIZE];
    int time[TIME_MAX_SIZE];

    bool prevt1 = false;
    bool prevt2 = false;
    bool prevd1 = false;
    bool prevd2 = false;

    setlocale(LC_ALL, "Rus");
    int choice = 0;
    while (1)
    {
        system("cls");
        printf("Календарь\n\n");
        printf("%s %02d:%02d:%02d\n", (choice == 0) ? "1)Время 1: <== " : "1)Время 1:  ", hours1, minutes1, seconds1);
        if (days1 > 0) { printf("%s %02d.%02d.%04d, %s\n", (choice == 1) ? "2)Дата 1: <== " : "2)Дата 1:  ", days1, months1, years1, days[week1]); }
        else { printf("%s %02d.%02d.%04d\n", (choice == 1) ? "2)Дата 1: <== " : "2)Дата 1:  ", days1, months1, years1); }
        printf("%s %02d:%02d:%02d\n", (choice == 2) ? "3)Время 2: <== " : "3)Время 2: ", hours2, minutes2, seconds2);
        if (days2 > 0) { printf("%s %02d.%02d.%04d, %s\n", (choice == 3) ? "4)Дата 2: <== " : "4)Дата 2: ", days2, months2, years2, days[week2]); }
        else { printf("%s %02d.%02d.%04d\n", (choice == 3) ? "4)Дата 2: <== " : "4)Дата 2: ", days2, months2, years2); }
        printf("%s%s\n", (choice == 4) ? "5)Результат 1 <== " : "5)Результат 1 ", "");
        printf("%s %d\n", (choice == 5) ? "6)Количество дней: <== " : "6)Количество дней: ", daysAdd);
        printf("%s%s\n", (choice == 6) ? "7)Результат 2 <== " : "7)Результат 2 ", "");
        printf("%s%s\n", (choice == 7) ? "8)Выход  <== " : "8)Выход ", "");

        int arr = _getch();
        if (arr >= '1' && arr <= '7')
        {
            choice = arr - '1';
        }
        else if (arr == 224)
        {
            switch (_getch())
            {
            case 72:
                choice = (choice > 0) ? choice - 1 : 7;
                break;
            case 80:
                choice = (choice < 7) ? choice + 1 : 0;
                break;
            }
        }

        else if (arr == '\r')
        {
            switch (choice)
            {
            case 0:
                prevt1 = false;
                system("cls");
                Time(time);
                hours1 = time[0] * 10 + time[1];
                minutes1 = time[2] * 10 + time[3];
                seconds1 = time[4] * 10 + time[5];
                if (0 <= hours1 && hours1 <= 24 && 0 <= minutes1 && minutes1 <= 60 && 0 <= seconds1 && seconds1 <= 60)
                {
                    prevt1 = true;
                    printf("\nВведенное время 1: %02d:%02d:%02d", hours1, minutes1, seconds1);
                }
                else {
                    prevt1 = false;
                    printf("\nВведите другое время: ");
                    hours1 = 0;
                    minutes1 = 0;
                    seconds1 = 0;
                }
                _getch();
                break;
            case 1:
                prevd1 = false;
                system("cls");
                Date(date);

                days1 = date[0] * 10 + date[1];
                months1 = date[2] * 10 + date[3];
                years1 = date[4] * 1000 + date[5] * 100 + date[6] * 10 + date[7];
                week1 = DayOfWeek(days1, months1, years1);
                if (1 <= days1 && days1 <= 31 && 1 <= months1 && months1 <= 12 && 1930 <= years1 && years1 <= 2030 && days1 <= daysInMonth(days1, months1, years1))
                {
                    prevd1 = true;
                    printf("\nВведенная дата 1: %02d.%02d.%04d, %s", days1, months1, years1, days[week1]);
                }
                else {
                    prevd1 = false;
                    printf("\nВведите другую дату: ");
                    days1 = 0;
                    months1 = 0;
                    years1 = 0;
                }
                _getch();
                break;
            case 2:
                prevt2 = false;
                system("cls");
                Time(time);
                hours2 = time[0] * 10 + time[1];
                minutes2 = time[2] * 10 + time[3];
                seconds2 = time[4] * 10 + time[5];
                if (0 <= hours2 && hours2 <= 24 && 0 <= minutes2 && minutes2 <= 60 && 0 <= seconds2 && seconds2 <= 60)
                {
                    prevt2 = true;
                    printf("\nВведенное время 2: %02d:%02d:%02d", hours2, minutes2, seconds2);
                }
                else {
                    prevt2 = false;
                    printf("\nВведите другое время: ");
                    hours2 = 0;
                    minutes2 = 0;
                    seconds2 = 0;
                }
                _getch();
                break;
            case 3:
                prevd2 = false;
                system("cls");
                Date(date);
                days2 = date[0] * 10 + date[1];
                months2 = date[2] * 10 + date[3];
                years2 = date[4] * 1000 + date[5] * 100 + date[6] * 10 + date[7];
                week2 = DayOfWeek(days2, months2, years2);
                if (1 <= days2 && days2 <= 31 && 1 <= months2 && months2 <= 12 && 1930 <= years2 && years2 <= 2030 && days2 <= daysInMonth(days2, months2, years2))
                {
                    prevd2 = true;
                    printf("\nВведенная дата 2: %02d.%02d.%04d, %s", days2, months2, years2, days[week2]);
                }
                else {
                    prevd2 = false;
                    printf("\nВведите другую дату: ");
                    days2 = 0;
                    months2 = 0;
                    years2 = 0;
                }
                _getch();
                break;
            case 4:
                system("cls");
                TimeDifference(days1, days2, months1, months2, years1, years2, hours1, hours2, minutes1, minutes2, seconds1, seconds2, prevt1, prevt2, prevd1, prevd2);
                _getch();
                break;
            case 5:
                system("cls");
                daysAdd = readNumber();
                printf("Вы ввели: %d\n", daysAdd);
                _getch();
                break;
            case 6:
                system("cls");
                if (days1 != 0 && daysAdd != 0)
                {
                    addDays(days1, months1, years1, daysAdd);
                }
                else
                {
                    printf("Недостаточно данных");
                }
                _getch();
                break;
            case 7:
                exit(0);
                break;
            }
        }
    }
    return 0;
}