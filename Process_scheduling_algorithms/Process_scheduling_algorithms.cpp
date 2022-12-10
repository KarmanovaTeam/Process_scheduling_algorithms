#include<iostream> 
#include<vector> 
#include"SJN.cpp" 
using namespace std;


//Приоритетность выполнения
enum PRIORITY
{
    LOW = 1,
    NORMAL=2,
    HIGH=3
};

struct Process {
    int Pid; //номер процесса(задачи), 
    int burst_time;// начальное время
    PRIORITY priority = NORMAL;//За основу взята средняя приоритетность, т.е. где приоритетность не указана - она нормальная(т.е. равна 2) 
};

int main() {
    //Тест 1
    //ПОЯСНЕНИЕ : {3, 18, HIGH} 3-номер процесса, 18 - burst_time, HIGH - приоритетность, если приоритетность не стоит - значит, она по умолчанию NORMAL
    const int quantum = 2; //квант времения
    vector<Process> processes = { {1, 10},{2, 4}, {3, 18, HIGH}, {4, 99, LOW}, {5, 2}, {6, 55}, {7, 1000},{8, 23, LOW},{9, 10},{10, 100000, HIGH} };
    SJN_avg_time(processes);
    //Тест 2
    /*const int quantum = 10; //квант времения
    vector<Process> processes = { {1, 100000},{2, 1000}, {3, 5000, HIGH}, {4, 2000, HIGH}, {5, 100000, HIGH}};*/
}



