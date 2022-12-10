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



void findWaitingTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& wt)
{
    // waiting time for first process is 0
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& wt, vector <int>& tat)
{
   
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
//Function to calculate average time
void findavgTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& arrival_time)
{
    vector <int> wt, tat;
    wt.resize(n);
    tat.resize(n);
    int total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
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
    sortProcess(processes, arrival_time);

    cout << endl << "Average waiting time = "

        << (float)total_wt / (float)n;

    cout << "\nAverage turn around time = "

        << (float)total_tat / (float)n;
}

// Driver code
