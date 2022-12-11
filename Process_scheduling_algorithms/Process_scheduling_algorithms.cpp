#include<iostream> 
#include<vector> 
#include"SJN.cpp"
#include"syuzev_dz.cpp"
#include"fedotova_dz.cpp"
#include"Gromova.cpp"
#include "Kozyrev.cpp"
using namespace std;

//Приоритетность выполнения
enum PRIORITY
{
    LOW = 1,
    NORMAL = 2,
    HIGH = 3
};

/*struct queues {
    int total_time = 0;
    int length = 0;
    Process* p;
    bool executed = false;
};*/

struct Process {
    int Pid; //номер процесса(задачи), 
    int burst_time;// начальное время
    int arriving_time;// время прибытия
    PRIORITY priority = NORMAL;//За основу взята средняя приоритетность, т.е. где приоритетность не указана - она нормальная(т.е. равна 2) 
};

void test1() {
    cout << "Тест 1" << endl;
    const int quantum = 2; //квант времения
    vector<Process> processes = { {1, 10, 3}, {2, 4, 1}, {3, 18,2, HIGH}, {4, 99,4, LOW}, {5, 2,5}, {6, 55,10}, {7, 1000,6},{8, 23,8, LOW},{9, 10,9},{10, 100000,11, HIGH} };
    findavgTime(processes, quantum);
    SJN_avg_time(processes);
    findavTime(processes);
    cout << endl;
}

void test2() {
    cout << "Тест 2" << endl;
    const int quantum = 1000000; //квант времения
    vector<Process> processes = { {1, 10000000,2},{2, 100000,2}, {3, 500000,0, HIGH}, {4, 2000000,19, HIGH}, {5, 100000000,25, HIGH}};
    findavgTime(processes, quantum);
    SJN_avg_time(processes);
    cout << endl;
}

void test3() {
    cout << "Тест 3" << endl;
    const int quantum = 5;
    vector<Process> processes = { {1, 2,82,HIGH}, {2, 26, 90}, {3, 11,72, LOW}, {4, 1,113}, {5, 7,51}, {6, 21,112,HIGH}, {7, 18,77,LOW},{8, 20,7, LOW},{9, 29,7},{10, 18,95, HIGH},
    {11, 42, 119,LOW}, {12, 5, 29,HIGH}, {13, 36,71, HIGH}, {14, 31,64, LOW}, {15, 8,119,HIGH}, {16, 15,82}, {17, 30,80},{18, 20,81, LOW},{19, 11,117,HIGH},{20, 11,57, HIGH} ,
    { 21, 43, 14,LOW }, { 22, 32, 118,LOW }, { 23, 39,6, HIGH }, { 24, 15,1, LOW }, { 25, 38,1 }, { 26, 28,1 }, { 27, 14,79 }, { 28, 15,33, LOW }, { 29, 26,39,HIGH }, { 30, 2,118},
    {31, 22, 100,HIGH}, { 32, 45, 118 }, { 33, 18,23, HIGH }, { 34, 7,44, LOW }, { 35, 21,28 }, { 36, 17,10,LOW }, { 37, 42,6 }, { 38, 30,88, LOW }, { 39, 27,19,HIGH }, { 40, 34,11, LOW },
    { 41, 38, 31, LOW}, { 42, 4, 5,LOW }, { 43, 6,2, HIGH }, { 44, 29,4, LOW }, { 45, 8,57 }, { 46, 9,102,HIGH }, { 47, 9,6 }, { 48, 6,81, LOW }, { 49, 20,92 }, { 50, 4,111, LOW }};
    findavgTime(processes, quantum);
    SJN_avg_time(processes);
}

int main() {
    setlocale(LC_ALL, "Russian");
    test1();
    test2();
    test3();
}
    



