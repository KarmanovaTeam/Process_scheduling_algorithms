#include<iostream> 
#include<vector>
#include "structures.h"
using namespace std;

//Функция для нахождения времени ожидания для всех
void findWaitingTime(vector <Process>& processes, const int& n, vector <int>& wt, const int& quantum)
{
    vector <int> rem_bt;
    rem_bt.resize(n);
    for (int i = 0; i < n; i++)
        rem_bt[i] = processes[i].burst_time;
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - processes[i].burst_time;
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}
//Функция для расчета времени оборота
void findTurnAroundTime(vector <Process>& processes, const int& n, vector <int>& wt, vector <int>& tat)
{
    for (int i = 0; i < n; i++)
        tat[i] = processes[i].burst_time + wt[i];
}
// функция расчета среднего времени
void findavgTime(vector <Process>& processes, const int& quantum)
{
    cout << "round-robbin\n";
    const int n = processes.size();
    vector <int> wt, tat;
    wt.resize(n);
    tat.resize(n);
    int total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, wt, quantum);
    findTurnAroundTime(processes, n, wt, tat);
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout  << processes[i].Pid << " ";
    }
    cout<<fixed;
    cout.precision(2);
    cout <<endl<< "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}
