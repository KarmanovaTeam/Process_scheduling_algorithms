#include<iostream> 
#include "syuzev_dz.cpp"
#include "SJN.cpp"
#include "fedotova_dz.cpp"
using namespace std;

int main()
{   
    //подключение русского языка
    setlocale(LC_ALL, "Russian");
    cout << "Методы планирование процессов в операционных системах" << endl;
    // id (номер) процессов
    vector <int> processes = { 1, 2, 3, 4, 5 };
    cout <<"Тестовые данные: "<< endl<< "Процессы(задачи) :" << endl;
    for (int i = 0; i < processes.size(); i++)
    {
        cout << processes[i]<< " ";
    }
    cout << endl;
    // время вызрыва для процессов
    vector <int> burst_time = { 10, 5, 8, 6, 7 };
    cout << "Время: " << endl;
    for (int i = 0; i < burst_time.size(); i++)
    {
        cout << burst_time[i] << " ";
    }
    cout << endl;
    //время кванта 
    const int quantum = 2;
    cout << "Квант времени: " << quantum << endl;
    const int n = processes.size();
    sortBT(burst_time, n, processes);
    findavgTime(processes, n, burst_time, quantum);
    SJN_avg_time(processes, n, burst_time);
    return 0;
}

