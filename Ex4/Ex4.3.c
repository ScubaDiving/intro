int main(){

    do{
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                addMonth();
                break;
            case 2:
                rmMonth();
                break;
            case 3:
                printMonths();
                break;
            case 4:
                addTask();
                break;
            case 5:
                rmTask();
                break;
            case 6:
                printTasks();
                break;
        }
    }while(n!=7);

}