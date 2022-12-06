
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


//Другой вариант кода
/*#include <vector>
#include<iostream>

using namespace std;

// Function to find the waiting time for all 
// processes

void findWaitingTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& wt)
{

    // waiting time for first process is 0

    wt[0] = 0;


    // calculating waiting time

    for (int i = 1; i < n; i++)

        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time

void findTurnAroundTime(vector <int>& processes, const int& n, vector <int>& bt, vector <int>& wt, vector <int>& tat)
{

    // calculating turnaround time by adding

    // bt[i] + wt[i]

    for (int i = 0; i < n; i++)

        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time

void findavgTime(vector <int>& processes, const int& n, vector <int>& bt)
{
    vector <int> wt, tat;
    wt.resize(n);
    tat.resize(n);

    int total_wt = 0, total_tat = 0;


    //Function to find waiting time of all processes

    findWaitingTime(processes, n, bt, wt);


    //Function to find turn around time for all processes

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
        cout << processes[i] << " ";

    }
    

    cout <<endl<< "Average waiting time = "

        << (float)total_wt / (float)n;

    cout << "\nAverage turn around time = "

        << (float)total_tat / (float)n;
}

// Driver code

int main()
{

    //process id's
    vector <int> processes = { 1, 2, 3, 4, 5 };
    //int processes[] = { 1, 2, 3 };

    //int n = sizeof processes / sizeof processes[0];
    const int n = processes.size();

    //Burst time of all processes

    vector <int> burst_time = { 10, 5, 8, 6, 7 };


    findavgTime(processes, n, burst_time);

    return 0;
}*/
