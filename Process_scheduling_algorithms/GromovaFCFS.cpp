
#include <vector>
#include<iostream>
using namespace std;

void sortProcess(vector <int>& n, vector <int>& at)
{
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 4;j++)
        {
         
            if (at[i] < at[j])
            {
                int Na,T;
                Na = n[i];
                n[i] = n[j];
                n[j] = Na;

                T = at[i];
                at[i] = at[j];
                at[j] = T;
            
            }
        }
    }
    for (int i = 0;i < 5;i++)
    {
        cout << n[i] << "\t";
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    vector <int> n = { 1, 2, 3, 4, 5 };
    vector <int> at = { 4, 8, 5, 1, 7 };
    vector <int> bt = { 10, 5, 8, 6, 7 };
    int wt[5], tat[5], i, j;
    float  avwt = 0, avtat = 0;

    wt[0] = 0;    //waiting time for first process is 0
    //calculating waiting time
    for (i = 1;i < 5;i++)
    {
        wt[i] = 0;
        for (j = 0;j < i;j++)
            wt[i] += bt[j];
    }
   // cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    //calculating turnaround time
    for (i = 0;i < 5;i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
    //   cout << "\nP[" << i + 1 << "]" << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    avwt /= i;
    avtat /= i;
    cout << "\nFirst Come First Serve(FCFS)" << endl;
    sortProcess(n, at);
    cout << "\nсреднее время ожидания (wt)=" << avwt;
    cout << "\nсреднее время обслуживания (tat)=" << avtat;

    return 0;
}