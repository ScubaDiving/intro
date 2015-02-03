#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef EX4_3_DAY
#define EX4_3_DAY

#define TASK_MAX_LENGTH 40
#define MAX_DAY 30

typedef struct{
    int  num;
    char **tasks;
    int  tasksLength;
} Day;

int addDay(int num, Day **days, int *daysLength);
int remDay(int num, Day **days, int *daysLength);
int isDayExist(int num, Day *pDay, int length);
int addTask(char *task, char ***tasks, int *tasksLength);
int remTask(char *task, char ***tasks, int *tasksLength);
int isTaskExist(char *task, char **tasks, int tasksLength);

#endif

/////////////////////////////////////////////////////////////////////

#ifndef EX4_3_MONTH
#define EX4_3_MONTH

#define MONTH_NAME_LENGTH 3
#define MAX_MONTH 12

typedef enum{
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec, NaM // Not a Month
} MonthName;

extern char *const MONTH_NAME[];

typedef struct{
    MonthName name;
    Day       *days;
    int       daysLength;
} Month;

int        addMonth(char *name, Month **months, int *monthLength);
int        remMonth(char *name, Month **months, int *monthLength);
int        printMonth(Month *months, int monthLength);
MonthName  toMonthName(char *name);
int        isMonthExist(MonthName name, Month *pMonth, int monthLength);

#endif


void _addMonth(Month **pMonths, int *pLength);
void _remMonth(Month **pMonths, int *pLength);
void _addTask(Month **pMonths, int *pLength);
void _remTask(Month **pMonths, int *pLength);
void _printTask(Month *months, int length);
void __exit(Month **pMonths, int *pLength);

int main(){
    Month *monthArr      = NULL;
    int   monthArrLength = 0, choice;
    while (1){
        scanf("%d", &choice);
        switch (choice){
            case 1:
                _addMonth(&monthArr, &monthArrLength);
                break;
            case 2:
                _remMonth(&monthArr, &monthArrLength);
                break;
            case 3:
                printMonth(monthArr, monthArrLength);
                break;
            case 4:
                _addTask(&monthArr, &monthArrLength);
                break;
            case 5:
                _remTask(&monthArr, &monthArrLength);
                break;
            case 6:
                _printTask(monthArr, monthArrLength);
                break;
            case 7:
                __exit(&monthArr, &monthArrLength);
                return 0; //not really necessary, just to remove the error...
            default:
                printf("Invalid option\n");
                break;
        }
    }
}

void _addMonth(Month **pMonths, int *pLength){
    char name[MONTH_NAME_LENGTH + 1];
    scanf("%s", name);

    addMonth(name, pMonths, pLength);
}

void _remMonth(Month **pMonths, int *pLength){
    char name[MONTH_NAME_LENGTH + 1];
    scanf("%s", name);

    remMonth(name, pMonths, pLength);
}

void _addTask(Month **pMonths, int *pLength){
    char monthName[MONTH_NAME_LENGTH + 1],
              taskBuff[TASK_MAX_LENGTH + 1],
              *task = NULL;
    int       dayNum, monthIndex, dayIndex;
    MonthName name;

    printf("Please enter a month:\n");
    scanf("%s", monthName);
    name = toMonthName(monthName);
    if (isMonthExist(name, *pMonths, *pLength) == -1 &&
        !addMonth(monthName, pMonths, pLength))
        return; //if month doesn't exist, create it. if it fails, return.
    monthIndex = isMonthExist(name, *pMonths, *pLength);

    printf("Please enter a day:\n");
    scanf("%d", &dayNum);
    if (isDayExist(dayNum, (*pMonths)[monthIndex].days, (*pMonths)[monthIndex].daysLength) == -1 &&
        !addDay(dayNum, &(*pMonths)[monthIndex].days, &(*pMonths)[monthIndex].daysLength))
        return; //if day doesn't exist, create it. if it fails, return.
    dayIndex = isDayExist(dayNum, (*pMonths)[monthIndex].days, (*pMonths)[monthIndex].daysLength);

    printf("Please enter a task:\n");
    gets(taskBuff);
    gets(taskBuff);
    task = (char *)calloc(strlen(taskBuff) + 1, sizeof(char));
    strcpy(task, taskBuff);

    addTask(task, &(*pMonths)[monthIndex].days[dayIndex].tasks, &(*pMonths)[monthIndex].days[dayIndex].tasksLength);
    free(task);
}

void _remTask(Month **pMonths, int *pLength){
    char monthName[MONTH_NAME_LENGTH + 1],
              taskBuffer[TASK_MAX_LENGTH + 1],
              *task;
    int       monthIndex,
              dayNum,
              dayIndex;
    MonthName name;

    printf("Please enter a month:\n");
    scanf("%s", monthName);
    name = toMonthName(monthName);
    if (isMonthExist(name, *pMonths, *pLength) == -1){
        printf("The month is not in the system\n");
        return;
    }
    monthIndex = isMonthExist(name, *pMonths, *pLength);

    printf("Please enter a day:\n");
    scanf("%d", &dayNum);
    if (isDayExist(dayNum, (*pMonths)[monthIndex].days, (*pMonths)[monthIndex].daysLength) == -1){
        printf("The day is not in the system\n");
        return;
    }
    dayIndex = isDayExist(dayNum, (*pMonths)[monthIndex].days, (*pMonths)[monthIndex].daysLength);

    printf("Please enter a task:\n");
    gets(taskBuffer);
    gets(taskBuffer);
    task = (char *)calloc(strlen(taskBuffer) + 1, sizeof(char));
    strcpy(task, taskBuffer);
    if (isTaskExist(task, (*pMonths)[monthIndex].days[dayIndex].tasks, (*pMonths)[monthIndex].days[dayIndex].tasksLength) ==
        -1){
        printf("The task is not in the system\n");
        return;
    }

    remTask(task, &(*pMonths)[monthIndex].days[dayIndex].tasks, &(*pMonths)[monthIndex].days[dayIndex].tasksLength);
    if ((*pMonths)[monthIndex].days[dayIndex].tasksLength != 0)
        return;
    remDay(dayNum, &(*pMonths)[monthIndex].days, &(*pMonths)[monthIndex].daysLength);
    if ((*pMonths)[monthIndex].daysLength != 0)
        return;
    remMonth(monthName, pMonths, pLength);

    free(task);
}

void _printTask(Month *months, int length){
    int i, j, k,
        monthIndex,
        dayIndex;
    for (i = 0; i < MAX_MONTH; i++){
        monthIndex = isMonthExist(toMonthName(MONTH_NAME[i]), months, length);
        if (monthIndex == -1)
            continue;

        for (j = 1; j <= MAX_DAY; j++){
            dayIndex = isDayExist(j, months[monthIndex].days, months[monthIndex].daysLength);
            if (dayIndex == -1)
                continue;

            printf("Month: %s; Day: %d; Tasks:\n", MONTH_NAME[i], j);

            for (k = 0; k < months[monthIndex].days[dayIndex].tasksLength; k++){
                puts(months[monthIndex].days[dayIndex].tasks[k]);
            }
        }
    }
}

void __exit(Month **pMonths, int *pLength){
    char monthName[MONTH_NAME_LENGTH + 1];

    while (*pLength){
        //freeing all months in *months. if there aren't any, skips this loop
        while ((*pMonths)[0].daysLength){
            //freeing all days in first month. if there aren't any, skips this loop
            while ((*pMonths)[0].days[0].tasksLength){
                //freeing all tasks in first day. if there aren't any, skips this loop
                remTask((*pMonths)[0].days[0].tasks[0], &(*pMonths)[0].days[0].tasks, &(*pMonths)[0].days[0].tasksLength);
            }

            remDay((*pMonths)[0].days[0].num, &(*pMonths)[0].days, &(*pMonths)[0].daysLength); //freeing first day (last one takes its place)
        }

        remMonth(MONTH_NAME[(int)(*pMonths)[0].name], pMonths, pLength); //removing first month (last one takes its place)
    }

    exit(0);
}


int addDay(int num, Day **pDays, int *daysLength){
    if (*daysLength >= MAX_DAY){
        printf("Array out of bound\n");
        return 0;
    }

    if (1 > num || num > MAX_DAY){
        printf("Invalid day\n");
        return 0;
    }

    if (isDayExist(num, *pDays, *daysLength) != -1){
        printf("Day already exist\n");
        return 0;
    }

    Day *temp = (Day *)realloc(*pDays, sizeof(Day) * (*daysLength + 1));
    if (temp == NULL){
        printf("Allocation error\n");
        return 0;
    }
    *pDays = temp;
    (*daysLength)++;
    (*pDays)[*daysLength - 1].num         = num;
    (*pDays)[*daysLength - 1].tasks       = NULL;
    (*pDays)[*daysLength - 1].tasksLength = 0;
    return 1;
}

int remDay(int num, Day **pDays, int *daysLength){
    if (*pDays == NULL){
        printf("No day given\n");
        return 0;
    }

    if (*daysLength <= 0){
        printf("Array empty\n");
        return 0;
    }

    if (1 > num || num > MAX_DAY){
        printf("Invalid day\n");
        return 0;
    }

    int index = isDayExist(num, *pDays, *daysLength);
    if (index == -1){
        printf("Day doesn't exist\n");
        return 0;
    }

    if (*daysLength == 1){
        free(*pDays);
        *pDays = NULL;
        (*daysLength)--;
        return 1;
    }

    (*pDays)[index] = (*pDays)[*daysLength - 1];
    Day *temp = (Day *)realloc(*pDays, sizeof(Day) * (*daysLength - 1));
    if (temp == NULL){
        printf("Allocation error\n");
        return 0;
    }
    *pDays = temp;
    (*daysLength)--;
    return 1;
}

/**
* checks if day exist in *pDay; if so returns it's index in *pDay.
*/
int isDayExist(int num, Day *pDay, int length){
    int i;
    for (i = 0; i < length; i++){
        if (pDay[i].num == num){
            return i;
        }
    }
    return -1;
}

int addTask(char *task, char ***pTasks, int *tasksLength){
    if (task == NULL){
        printf("No task entered\n");
        return 0;
    }

    if (isTaskExist(task, *pTasks, *tasksLength) != -1){
        printf("Task already entered\n");
        return 0;
    }

    char **temp = (char **)realloc(*pTasks, sizeof(char *) * (*tasksLength + 1));
    if (temp == NULL){
        printf("Allocation error\n");
        return 0;
    }
    *pTasks = temp;
    (*tasksLength)++;

    char *temp2 = (char *)calloc(strlen(task) + 1, sizeof(char));
    if (temp2 == NULL){
        printf("Allocation error\n");
        return 0;
    }
    (*pTasks)[*tasksLength - 1] = temp2;
    strcpy((*pTasks)[*tasksLength - 1], task);
    return 1;
}

int remTask(char *task, char ***pTasks, int *tasksLength){
    int i, index;
    if (*pTasks == NULL){
        printf("No task given\n");
        return 0;
    }

    index = isTaskExist(task, *pTasks, *tasksLength);
    if (index == -1){
        printf("The task is not in the system\n");
        return 0;
    }

    free((*pTasks)[index]);
    (*pTasks)[index] = NULL;

    if (*tasksLength == 1){
        free(*pTasks);
        *pTasks = NULL;
        (*tasksLength)--;
        return 1;
    }

    for (i = index; i < *tasksLength - 1; i++){
        (*pTasks)[i] = (*pTasks)[i + 1];
    }
    char **temp = (char **)realloc(*pTasks, sizeof(char *) * (*tasksLength - 1));
    if (temp == NULL){
        printf("Allocation error\n");
        return 0;
    }
    *pTasks = temp;
    (*tasksLength)--;
    return 1;
}

int isTaskExist(char *task, char **tasks, int length){
    if (tasks == NULL)
        return -1;

    int i;
    for (i = 0; i < length; i++){
        if (!strcmp(task, tasks[i])){
            return i;
        }
    }
    return -1;
}


char *const MONTH_NAME[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

/**
* adds a new month to array months, and increasing monthLength accordingly
* returns succession - 0 for fail, 1 for success
*/
int addMonth(char *name, Month **pMonths, int *monthLength){
    //checking monthLength
    if (*monthLength >= MAX_MONTH){
        printf("Array out of bound\n");
        return 0;
    }
    //checking name (and casting it to compatible type)
    MonthName monthName = toMonthName(name);
    if (monthName == NaM){
        printf("Invalid month\n");
        return 0;
    }

    //checking if month already in *pMonths
    if (isMonthExist(monthName, *pMonths, *monthLength) != -1){
        printf("The month is already in the system\n");
        return 0;
    }

    Month *temp = (Month *)realloc(*pMonths, sizeof(Month) * (*monthLength + 1));
    if (temp == NULL){ //there are other arrays besides month, so it'll be irresponsible to free and exit.
        printf("Allocation error\n");
        return 0;
    }
    *pMonths = temp;
    (*monthLength)++;
    (*pMonths)[*monthLength - 1].name       = monthName;
    (*pMonths)[*monthLength - 1].days       = NULL;
    (*pMonths)[*monthLength - 1].daysLength = 0;

    return 1;
}

int remMonth(char *name, Month **pMonths, int *monthLength){
    if (*pMonths == NULL){
        printf("No Month Given\n");
        return 0;
    }

    //checking monthLength
    if (*monthLength <= 0){
        printf("Array empty\n");
        return 0;
    }
    //checking name (and casting)
    MonthName monthName = toMonthName(name);
    if (monthName == NaM){
        printf("Invalid month\n");
        return 0;
    }

    int index = isMonthExist(monthName, *pMonths, *monthLength);
    if (index == -1){
        printf("The month is not in the system\n");
        return 0;
    }

    //if this is the last month, free array containing it. (and set it to NULL)
    if (*monthLength == 1){
        free(*pMonths);
        *pMonths = NULL;
        (*monthLength)--;
        return 1;
    }

    (*pMonths)[index] = (*pMonths)[*monthLength - 1];
    Month *temp = (Month *)realloc(*pMonths, sizeof(Month) * (*monthLength - 1));
    if (temp == NULL){
        printf("Allocation error\n");
        return 0;
    }
    *pMonths = temp;
    (*monthLength)--;
    return 1;
}

int printMonth(Month *months, int monthLength){
    if (months == NULL){
        printf("No month given\n");
        return 0;
    }

    int arr[MAX_MONTH] = {0}, i, last;
    for (i = 0; i < monthLength; i++){
        arr[(int)months[i].name] = 1;
    }
    for (last = MAX_MONTH - 1; last >= 0 && !arr[last]; last--); //last is index of last month to print
    for (i = 0; i < last; i++)
        printf(arr[i]? "%s, " : "", MONTH_NAME[i]);
    printf("%s\n", MONTH_NAME[last]);

    return 1;
}

/**
* cast string name to enum MonthName type
* returns according MonthName or NULL
*/
MonthName toMonthName(char *name){
    if (strlen(name) != MONTH_NAME_LENGTH)
        return NaM;

    int i;
    for (i = 0; i < MAX_MONTH; i++){
        if (!strcmp(MONTH_NAME[i], name))
            return (MonthName)i;
    }

    return NaM;
}

/**
* checks is month with said name is found in array pMonth of length monthLength
* if so, returns its place, else returns -1
*/
int isMonthExist(MonthName name, Month *pMonth, int monthLength){
    if (pMonth == NULL)
        return -1;

    int i;
    for (i = 0; i < monthLength; i++){
        if (pMonth[i].name == name)
            return i;
    }
    return -1;
}
