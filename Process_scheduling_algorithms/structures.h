#pragma once
enum PRIORITY
{
    LOW = 3,
    NORMAL = 2,
    HIGH = 1
};

struct Process {
    int Pid; //номер процесса(задачи), 
    int burst_time;// начальное время
    int arriving_time;// время прибытия
    PRIORITY priority = NORMAL;//За основу взята средняя приоритетность, т.е. где приоритетность не указана - она нормальная(т.е. равна 2) 
}; 

struct queues {
    int total_time = 0;
    int length = 0;
    Process* p;
    bool executed = false;
};


