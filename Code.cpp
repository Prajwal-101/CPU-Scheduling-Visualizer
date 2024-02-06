#include <bits/stdc++.h>
using namespace std;

int menu()
{
    int choice;

    system("cls");
    cout << ("\n\n                              CPU SCHEDULER");
    cout << ("\n-------------------------------------------------------------------------------");
    cout << ("\n     Choose the algorithm you want to use to simulate the scheduler. \n");
    cout << ("\n                  < 1 > Firts-Come, First-Serve (FCFS)");
    cout << ("\n                  < 2 > Shortest-Job-First- (SRTF) ");
    cout << ("\n                  < 3 > Priority scheduler ");
    cout << ("\n                  < 4 > Round Robin (RR) ");
    cout << ("\n                  < 5 > Exit \n");
    cout << ("\n     Your choice: ");
    cin >> choice;

    return choice;
}

int painel()
{
    int choice;
    system("cls");
    cout << ("\n\n                              CPU SCHEDULER");
    cout << ("\n-------------------------------------------------------------------------------\n\n");
    cout << ("                           Process definition.\n\n");
    cout << ("\n                  < 1 > Use processes established by the program.");
    cout << ("\n                  < 2 > Introduce new processes.");
    cout << ("\n\n    Your choice: ");
    cin >> (choice);
    if (choice > 2)
        painel();
    else
        return choice;
}

void top()
{
    system("cls");
    cout << ("\n\n                              CPU SCHEDULER");
    cout << ("\n-------------------------------------------------------------------------------\n\n");
}

struct processes
{
    int id;
    int dur;
    int prio;
    int execu;
    int esp;
    processes *next;
    /*
        id - process identification
        dur - process duration time
        exe - process runtime
        esp - process waiting time
    */
};

processes *process_input(int id, int dur, int prio)
{
    processes *loc = new processes;
    // loc = ( processes*)malloc(sizeof( processes));
    if (loc == NULL)
    {
        cout << ("Allocation error.\nEnd of execution\n");
        exit(1);
    }
    loc->id = id;
    loc->dur = dur;
    loc->prio = prio;
    loc->execu = 0;
    loc->esp = 0;
    loc->next = NULL;
    return (loc);
}

void list_processes(processes *loc)
{
    processes *tmp = loc;
    cout << ("\n\n\t\t\tList of processes\n\n");
    while (tmp != NULL)
    {
        cout << "\tProcess: " << tmp->id << "\tPriority: " << tmp->prio << "\tDuration: " << tmp->dur << endl;
        tmp = tmp->next;
    }
    cout << ("\n");
}

void fcfs(processes *loc, int process_number)
{
    int time = 0, start, end, waiting_time = 0, turnaround_time = 0;
    int p[process_number], i = 0;
    processes *tmp = loc;
    cout << ("\n\t\tFirts-Come, First-Serve (FCFS) Scheduling\n\n");
    while (tmp != NULL)
    {
        start = time;
        time += tmp->dur;
        p[i] = time;
        end = time;
        cout << "\tProcess: " << tmp->id << "\t Duration: " << tmp->dur << "\tWaiting time: " << start << "\tFinish: " << end << endl;
        waiting_time += start;
        tmp = tmp->next;
        i++;
    }
    i = 0;
    cout << "\n\t\tAverage Waiting Time= " << waiting_time * 1.0 / process_number;
    cout << ("\t    Visually simulating scaling.");
    cout << ("\n\n\t\t    ");
    for (i = 0; i < process_number; i++)
    {
        cout << "| P" << i + 1 << " ";
    }
    cout << ("|");
    cout << ("\n\t\t    0  ");
    for (i = 0; i < process_number; i++)
        cout << "  " << p[i] << " ";
}

void sjf(processes *loc, int process_number)
{
    int execution_time, shortest, start, end, waiting_time, duration;
    processes *copy, *src_tmp, *tmp, *before_shortest;
    cout << ("\n\t\tShortest-Job-First- (SRTF)\n\n ");
    src_tmp = loc;
    copy = tmp = NULL;
    while (src_tmp != NULL)
    { /*making copies of the processes*/
        if (copy == NULL)
        {
            copy = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = copy;
        }
        else
        {
            tmp->next = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = tmp->next;
        }
        src_tmp = src_tmp->next;
    }
    execution_time = 0;
    while (copy != NULL)
    { /*new process search*/
        before_shortest = NULL;
        shortest = copy->dur;
        tmp = copy->next;
        src_tmp = copy;
        while (tmp != NULL)
        {
            if (tmp->dur < shortest)
            {
                shortest = tmp->dur;
                before_shortest = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if (before_shortest == NULL)
        { /*process is executed and copy is killed and allocates the 1st process s is less*/
            start = execution_time;
            execution_time += copy->dur;
            duration = copy->dur;
            end = execution_time;
            cout << "\tProcess: " << copy->id << "\t Duration: " << duration << "\tWaiting time: " << start << "\tFinish: " << end << endl;
            waiting_time += end;
            src_tmp = copy;
            copy = copy->next;
            free(src_tmp);
        }
        else
        { /*allocates the 1st process if there is no smaller one*/
            tmp = before_shortest->next;
            start = execution_time;
            execution_time += tmp->dur;
            duration = tmp->dur;
            end = execution_time;
            cout << "\tProcess: " << tmp->id << "\t Duration: " << tmp->dur << "\tWaiting time: " << start << "\tFinish: " << end << endl;
            before_shortest->next = tmp->next;
            free(tmp);
        }
    }
    double h = waiting_time * 1.0 / process_number;
    cout << "\n\t\tAverage Waiting Time= " << h << endl;
}

void sjf_simulator(processes *loc, int process_number)
{
    int execution_time, shortest, start, end, duration, i = 0, p[process_number];
    processes *copy, *src_tmp, *tmp, *before_shortest;
    cout << ("\n\t    Visually simulating scaling\n\n ");
    src_tmp = loc;
    copy = tmp = NULL;
    while (src_tmp != NULL)
    { /*copying the processes*/
        if (copy == NULL)
        {
            copy = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = copy;
        }
        else
        {
            tmp->next = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = tmp->next;
        }
        src_tmp = src_tmp->next;
    }
    execution_time = 0;
    cout << ("\t\t  ");
    while (copy != NULL)
    { /*new process search*/
        before_shortest = NULL;
        shortest = copy->dur;
        tmp = copy->next;
        src_tmp = copy;
        while (tmp != NULL)
        {
            if (tmp->dur < shortest)
            {
                shortest = tmp->dur;
                before_shortest = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if (before_shortest == NULL)
        { /*process is executed and copy is killed and allocates the 1st process s is less*/
            start = execution_time;
            execution_time += copy->dur;
            duration = copy->dur;
            end = execution_time;
            p[i] = execution_time;
            cout << "| P" << copy->id << " ";
            src_tmp = copy;
            copy = copy->next;
            free(src_tmp);
        }
        else
        { /*allocates the 1st process if there is no smaller one*/
            tmp = before_shortest->next;
            start = execution_time;
            execution_time += tmp->dur;
            duration = tmp->dur;
            p[i] = execution_time;
            end = execution_time;
            cout << "| P" << tmp->id << " ";
            before_shortest->next = tmp->next;
            free(tmp);
        }
        i++;
    }
    cout << ("|");
    cout << ("\n\t\t  0  ");
    for (i = 0; i < process_number; i++)
        cout << "  " << p[i] << " ";
}

void priority_scheduler(processes *loc, int process_number)
{
    int execution_time, start, maior, end, waiting_time, duration;
    processes *copy, *src_tmp, *tmp, *maior_prio;
    cout << ("\n\t\tPriority scheduler \n\n");
    src_tmp = loc;
    copy = tmp = NULL;
    while (src_tmp != NULL)
    { /*copying the processes*/
        if (copy == NULL)
        {
            copy = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = copy;
        }
        else
        {
            tmp->next = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = tmp->next;
        }
        src_tmp = src_tmp->next;
    }
    execution_time = 0;
    while (copy != NULL)
    { /*check next process*/
        maior_prio = NULL;
        maior = copy->prio;
        tmp = copy->next;
        src_tmp = copy;
        while (tmp != NULL)
        {
            if (tmp->prio < maior)
            {
                maior = tmp->prio;
                maior_prio = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if (maior_prio == NULL)
        { /*ver se 1º tem prioridade maior*/
            start = execution_time;
            execution_time += copy->dur;
            duration = copy->dur;
            end = execution_time;
            cout << "\tProcess: " << copy->id << "\t Duration: " << duration << "\tWaiting time: " << start << "\tFinish: " << end << endl;
            waiting_time += end;
            src_tmp = copy->next;
            free(copy);
            copy = src_tmp;
        }
        else
        { /*if 1st does not have higher priority*/
            tmp = maior_prio->next;
            start = execution_time;
            execution_time += tmp->dur;
            duration = tmp->dur;
            end = execution_time;
            cout << "\tProcess: " << tmp->id << "\t Duration: " << duration << "\tWaiting time: " << start << "\tFinish: " << end << endl;
            maior_prio->next = tmp->next;
            free(tmp);
        }
    }
    cout << "\n\t\tAverage Waiting Time= " << waiting_time * 1.0 / process_number << endl;
}

void priority_scheduler_simulator(processes *loc, int process_number)
{
    int execution_time, start, maior, end, duration, i = 0, p[process_number];
    processes *copy, *src_tmp, *tmp, *maior_prio;
    cout << ("\n\t    Visually simulating scaling\n\n ");
    src_tmp = loc;
    copy = tmp = NULL;
    while (src_tmp != NULL)
    { /*copying the processes*/
        if (copy == NULL)
        {
            copy = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = copy;
        }
        else
        {
            tmp->next = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = tmp->next;
        }
        src_tmp = src_tmp->next;
    }
    execution_time = 0;
    cout << ("\t\t  ");
    while (copy != NULL)
    { /*check next process*/
        maior_prio = NULL;
        maior = copy->prio;
        tmp = copy->next;
        src_tmp = copy;
        while (tmp != NULL)
        {
            if (tmp->prio < maior)
            {
                maior = tmp->prio;
                maior_prio = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if (maior_prio == NULL)
        { /*see if 1st has higher priority*/
            start = execution_time;
            execution_time += copy->dur;
            p[i] = execution_time;
            duration = copy->dur;
            end = execution_time;
            cout << "| P" << copy->id << " ";
            src_tmp = copy->next;
            free(copy);
            copy = src_tmp;
        }
        else
        { /* if 1st does not have higher priority*/
            tmp = maior_prio->next;
            start = execution_time;
            execution_time += tmp->dur;
            p[i] = execution_time;
            duration = tmp->dur;
            end = execution_time;
            cout << "| P" << tmp->id << " ";
            maior_prio->next = tmp->next;
            free(tmp);
        }
        i++;
    }
    cout << ("|");
    cout << ("\n\t\t  0  ");
    for (i = 0; i < process_number; i++)
        cout << "  " << p[i] << " ";
}

void robbin_round(processes *loc, int quantum, int process_number)
{
    int count, j, time, remain, flag = 0;
    int waiting_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    remain = process_number;
    processes *copy, *src_tmp, *tmp, *slot;
    cout << ("\n\t\tRound Robin (RR) - Quantum: %d\n", quantum);
    src_tmp = loc;

    for (count = 0; count < process_number; count++)
    {
        bt[count] = src_tmp->dur;
        rt[count] = bt[count];
        src_tmp = src_tmp->next;
    }
    for (time = 0, count = 0; remain != 0;)
    {
        at[count] = time;
        if (rt[count] <= quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= quantum;
            time += quantum;
        }

        if (rt[count] == 0 && flag == 1)
        {
            remain--;
            cout << "\tProcess: " << count + 1 << "\tWaiting time: " << time - bt[count] << " \tFinish: " << time << endl;
            waiting_time += time - bt[count];
            turnaround_time += time;
            flag = 0;
        }
        if (count == process_number - 1)
            count = 0;
        else if (at[count] <= time)
            count++;
        else
            count = 0;
    }
    cout << "\n\t\tAverage Waiting Time= " << waiting_time * 1.0 / process_number << endl;
    cout << "\t   Avgerage Turnaround Time = " << turnaround_time * 1.0 / process_number;
    free(src_tmp);
}

int main()
{
    int choice, es_proc, process_number, i, id, dur, prio, position = 0;
    do
    {
        if (position == 0)
        {
            es_proc = painel();
        }
        else
            choice = menu();

        processes *list_proc, *tmp_proc;

        if (es_proc == 1)
        {
            process_number = 4;
            list_proc = process_input(1, 12, 2);
            list_proc->next = process_input(2, 2, 1);
            tmp_proc = list_proc->next;
            tmp_proc->next = process_input(3, 8, 4);
            tmp_proc = tmp_proc->next;
            tmp_proc->next = process_input(4, 10, 3);
            choice = menu();
        }
        else if (es_proc == 2)
        {
            top();
            cout << ("\n\n  NOTE: Choose preferably for more than 3 processes.");
            cout << ("\n\n   Enter the number of processes: ");
            cin >> process_number;
            for (i = 0; i < process_number; i++)
            {
                system("cls");
                top();
                cout << "\n             Process" << i + 1 << " ";
                cout << "\n\nEnter your duration time (Burst time) P[" << i + 1 << "]: ";
                cin >> dur;
                cout << "Enter your execution priority P[" << i + 1 << "]: ";
                cin >> prio;
                if (i == 0)
                    list_proc = process_input(i + 1, dur, prio);
                else if (i == 1)
                {
                    list_proc->next = process_input(i + 1, dur, prio);
                    tmp_proc = list_proc->next;
                }
                else if (i == process_number - 1)
                {
                    tmp_proc->next = process_input(i + 1, dur, prio);
                }
                else
                {
                    tmp_proc->next = process_input(i + 1, dur, prio);
                    tmp_proc = tmp_proc->next;
                }
            }
            position = 1;
            choice = menu();
        }

        if (choice == 1)
        {
            system("cls");
            list_processes(list_proc);
            fcfs(list_proc, process_number);
            cout << ("\n\n\t< 1 > To go back\nChoose: ");
            int i;
            cin >> i;
        }
        else if (choice == 2)
        {
            system("cls");
            list_processes(list_proc);
            sjf(list_proc, process_number);
            sjf_simulator(list_proc, process_number);
            cout << ("\n\n\t< 1 > To go back\nChoose: ");
            int i;
            cin >> i;
        }
        else if (choice == 3)
        {
            system("cls");
            list_processes(list_proc);
            priority_scheduler(list_proc, process_number);
            priority_scheduler_simulator(list_proc, process_number);
            cout << ("\n\n\t< 1 > To go back\nChoose: ");
            int i;
            cin >> i;
        }
        else if (choice == 4)
        {
            system("cls");
            int quantum;
            list_processes(list_proc);
            cout << ("\nEnter the desired time quantum: ");
            cin >> quantum;
            robbin_round(list_proc, quantum, process_number);
            cout << ("\n\n\t< 1 > To go back\nChoose: ");
            int i;
            cin >> i;
        }
        else if (choice == 5)
        {
            cout << ("\n\nEnd of program.\n\n");
            exit(2);
        }

    } while (choice <= 6);

    return 0;
}
