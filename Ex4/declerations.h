typedef struct{
    int day_num;

}day;

typedef struct {

    char monthName[3];
    day days;

}month;

int addMonth();
int rmMonth();
int printMonth();
int addTask();
int rmTask();
int printTask();