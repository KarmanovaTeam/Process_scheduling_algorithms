#include <vector>
#include <iostream>
#include "structures.h"
using namespace std;


bool notComplete(queues q[]) {
    bool a = false;
    int countInc = 0;
    for (int i = 0; i < 3; i++) {
        countInc = 0;
        for (int j = 0; j < q[i].length; j++) {
            if (q[i].p[j].burst_time != 0) {
                a = true;
            }
            else {
                countInc += 1;
            }
        }
        if (countInc == q[i].length) {

            q[i].executed = true;
        }
    }
    return a;
}


void sort_ps(queues q) {
    //Очередь q должна быть отсортированна по приоритету процессов
    for (int i = 1; i < q.length; i++) {
        for (int j = 0; j < q.length - 1; j++) {
            if (q.p[j].priority < q.p[j + 1].priority) {
                Process temp = q.p[j + 1];
                q.p[j + 1] = q.p[j];
                q.p[j] = temp;
            }
        }
    }
}


void checkCompleteTimer(queues q[]) {
    bool a = notComplete(q);
    for (int i = 0; i < 3; i++) {
        if (q[i].executed == false) {
            for (int j = 0; j < q[i].length; j++) {
                if (q[i].p[j].burst_time != 0) {
                    q[i].p[j].arriving_time += 1;
                }
            }
            q[i].total_time += 1;
        }
    }
}

void multilevel_queue(vector <Process> p1) {
    queues q[3];
    int n = p1.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++) {
            if (p1[i].priority == j+1) {
                q[j].length++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        int len = q[i].length;
        q[i].p = new Process[len];
    }

    int a = 0;
    int b = 0;
    int c = 0;

    for (int j = 0; j < n; j++) {
        if (p1[j].priority == 1) {
            q[0].p[a++] = p1[j];
        }
        else if (p1[j].priority == 2)
        {
            q[1].p[b++] = p1[j];
        }
        else {
            q[2].p[c++] = p1[j];
        }

    }

    a--; b--; c--;
    for (int i = 0; i < 3; i++) {
        std::cout << "Queue " << i + 1 << " : ";
        for (int j = 0; j < q[i].length; j++) {
            std::cout << q[i].p[j].Pid << "->";
        }
        std::cout << "NULL" << endl;
    }



    int timer = 0;
    int l = -1;
    int rr_timer = 4;
    int counter = 0;
    int counterps = 0;
    int counterfcfs = 0;
    while (notComplete(q)) {
        if (timer == 10) {
            timer = 0;
        }
        l += 1;
        if (l >= 3) {
            l = l % 3;
        }

        //Обрабатываем 1-ю очередь, если она ещё не выполнена 
        //Если выполнена меняем значение на 1
        if (q[l].executed == true) {
            l += 1;
            if (l >= 3) {
                l = l % 3;
            }
            continue;
        }

        //Итого мы имеем очередь, которая не полностью выполнена
        //Обработка незавершенных процессов

        if (l == 0) {
            //Round Robin алгоритм для q=4
            if (rr_timer == 0) {
                rr_timer = 4;
            }

            for (int i = 0; i < q[l].length; i++) {
                if (q[l].p[i].burst_time == 0) {
                    counter++;
                    continue;
                }
                if (counter == q[l].length) {
                    break;
                }
                while (rr_timer > 0 && q[l].p[i].burst_time != 0 && timer != 10) {
                    q[l].p[i].burst_time--;
                    checkCompleteTimer(q);
                    rr_timer--;
                    timer++;

                }
                if (timer == 10) {
                    break;
                }
                if (q[l].p[i].burst_time == 0 && rr_timer == 0) {
                    rr_timer = 4;
                    if (i == (q[i].length - 1)) {
                        i = -1;
                    }
                    continue;
                }
                if (q[l].p[i].burst_time == 0 && rr_timer > 0) {
                    if (i == (q[i].length - 1)) {
                        i = -1;
                    }
                    continue;
                }
                if (rr_timer <= 0) {
                    rr_timer = 4;
                    if (i == (q[i].length - 1)) {
                        i = -1;
                    }
                    continue;
                }

            }
        }


        else if (l == 1) {
            sort_ps(q[l]);
            //Приоритетное планирование
            for (int i = 0; i < q[l].length; i++) {
                if (q[l].p[i].burst_time == 0) {
                    counterps++;
                    continue;
                }
                if (counterps == q[l].length) {
                    break;
                }
                while (q[l].p[i].burst_time != 0 && timer != 10) {
                    q[l].p[i].burst_time--;
                    checkCompleteTimer(q);
                    timer++;

                }
                if (timer == 10) {
                    break;
                }
                if (q[l].p[i].burst_time == 0) {
                    continue;
                }

            }
        }
        else {
            //алгоритм первым пришел первым обслужен
            for (int i = 0; i < q[l].length; i++) {
                if (q[l].p[i].burst_time == 0) {
                    counterfcfs++;
                    continue;
                }
                if (counterfcfs == q[l].length) {
                    break;
                }
                while (q[l].p[i].burst_time != 0 && timer != 10) {
                    q[l].p[i].burst_time--;
                    checkCompleteTimer(q);

                    timer++;
                }
                if (timer == 10) {
                    break;
                }
                if (q[l].p[i].burst_time == 0) {
                    continue;
                }

            }

        }
    }

    /*for (int i = 0; i < 3; i++) {
        cout << "\nTime taken for queue " << i + 1 << " to execute: " << q[i].total_time << "\n";
        for (int j = 0; j < q[i].length; j++) {
            cout << "Process " << j + 1 << " of queue " << i + 1 << " took " << q[i].p[j].total_time << "\n";
        }
    }*/

    int sum_tt = 0;
    int sum_wt = 0;

    std::cout << "\n\nProcess     | Turn Around Time | Waiting Time\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "Queue " << i + 1 << "\n";
        for (int j = 0; j < q[i].length; j++) {
            std::cout << "Process P" << q[i].p[j].Pid << "\t" << q[i].p[j].burst_time+q[i].total_time << "\t\t    " << q[i].p[j].arriving_time - q[i].p[i].burst_time << "\n";
            sum_tt += q[i].p[j].arriving_time;
            sum_wt += q[i].p[j].arriving_time-q[i].p[j].burst_time;
        }
    }

    std::cout << "\n The average turnaround time is : " << sum_tt / n << endl;
    std::cout << "\n The average waiting time is : " << sum_wt / n << endl;

}

