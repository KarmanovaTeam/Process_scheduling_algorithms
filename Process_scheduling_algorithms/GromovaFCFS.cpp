#include <vector>
#include<iostream>
#include "structures.h"
using namespace std;

void sortProcess(vector <Process>& processes, const int& n)
{
    vector <int> at;
    vector <int> num;
    at.resize(n);
    num.resize(n);
    for (int i = 0; i < n; i++)
    {
        at[i] = processes[i].arriving_time;
        num[i] = processes[i].Pid;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            if (at[i] < at[j])
            {
                int Na, A;
                Na = num[i];
                num[i] = num[j];
                num[j] = Na;

                A = at[i];
                at[i] = at[j];
                at[j] = A;

            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << "\t";
    }
}

/*template <typename T>
void findTurnAroundTime(vector <T>& processes, const int& n, vector <int>& wt, vector <int>& tat)
{

   for (int i = 0; i < n; i++)
       tat[i] = processes[i].burst_time + wt[i];
}*/


void findWaiting(vector <Process>& processes, const int& n, vector <int>& wt, vector <int>& tat)
{
    // waiting time for first process is 0
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = processes[i - 1].burst_time + wt[i - 1];
    for (int i = 0; i < n; i++)
        tat[i] = processes[i].burst_time + wt[i];
}

//Function to calculate average time

void findavTime(vector <Process>& processes)
{
    const int n = processes.size();
    vector <int> wt, tat;
    wt.resize(n);
    tat.resize(n);

    findWaiting(processes, n, wt, tat);

    int total_wt = 0, total_tat = 0;
    //findTurnAroundTime(processes, n, wt,tat);
    //Display processes along with all details
    //cout << "Processes  " << " Burst time  "
        //<< " Waiting time  " << " Turn around time\n";
    // Calculate total waiting time and total turn 
    // around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        /*cout << "   " << i + 1 << "\t\t" << bt[i] << "\t    "
            << wt[i] << "\t\t  " << tat[i] << endl;*/
            // cout << processes[i] << " ";

    }
    cout<< endl;
    cout << "First Come First Serve(FCFS)" << endl;
    sortProcess(processes, n);

    cout << endl << "Average waiting time = "

        << (float)total_wt / (float)n;

    cout << "\nAverage turn around time = "

        << (float)total_tat / (float)n;
}
