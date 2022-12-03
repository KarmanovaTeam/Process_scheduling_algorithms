#include<iostream> 
#include<vector>
using namespace std;

//Функция для нахождения времени ожидания для всех
void findWaitingTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& wt, const int& quantum)
{
    vector <int> rem_bt;
    rem_bt.resize(n);
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
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
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}
//Функция для расчета времени оборота
void findTurnAroundTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& wt, vector <int>& tat)
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
// функция расчета среднего времени
void findavgTime(vector <int>& processes, const int& n, vector <int>& bt, const int& quantum)
{
    vector <int> wt, tat;
    wt.resize(n);
    tat.resize(n);
    int total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);
    cout << "Round Robin"<< endl;
    //cout << "PN-номер процесса\n";
    //cout << "BT-время взрыва\n";
    //cout << "WT-время ожидания \n";
    //cout << "TAT-время оборота\n";
    //cout << "PN\t " << " \tBT "<< " \tWT " << " \tTAT=BT+wt\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << processes[i] << " ";
           // << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << endl;
    cout << "Среднее время ожидания = "
        << (float)total_wt / (float)n;
    cout << "\nСреднее время обслуживания = "
        << (float)total_tat / (float)n;
}
//сортировка BT
void sortBT(vector <int>& bt, int n, vector <int>& processes)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int par = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = par;
                par = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = par;
            }
        }
    }
}

