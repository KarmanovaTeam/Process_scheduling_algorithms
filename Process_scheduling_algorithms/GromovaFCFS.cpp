#include <vector>
#include<iostream>
using namespace std;

template <typename T>
void sortProcess(vector <T>& processes, const int& n)
{
    vector <int> at;
    vector <int> num;
    rem_bt.resize(n);
    for (int i = 0; i < n; i++)
    {
        at[i] = processes[i].arriving_time;
        num[i] = processes[i].Pid;
    }

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n-1;j++)
        {
         
            if (at[i] < at[j])
            {
                int Na,T;
                Na = num[i];
                num[i] = num[j];
                num[j] = Na;

                T = at[i];
                at[i] = at[j];
                at[j] = T;
            
            }
        }
    }
    for (int i = 0;i < 5;i++)
    {
        cout << num[i] << "\t";
    }
}



template <typename T>
void findWaitingTime(vector <T>& processes, const int& n, vector <int>& wt)
{
    // waiting time for first process is 0
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = processes[i - 1].burst_time + wt[i - 1];
}
template <typename T>
void findTurnAroundTime(vector <T>& processes, const int& n, vector <int>& wt, vector <int>& tat)
{
   
    for (int i = 0; i < n; i++)
        tat[i] = processes[i].burst_time + wt[i];
}
//Function to calculate average time
template <typename T>
void findavgTime(vector <T>& processes)
{
    const int n = processes.size();
    vector <int> wt, tat;
    wt.resize(n);
    tat.resize(n);
    int total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, wt);
    findTurnAroundTime(processes, n, wt, tat);
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

    cout << "First Come First Serve(FCFS)" << endl;
    sortProcess(processes, n);

    cout << endl << "Average waiting time = "

        << (float)total_wt / (float)n;

    cout << "\nAverage turn around time = "

        << (float)total_tat / (float)n;
}

// Driver code
