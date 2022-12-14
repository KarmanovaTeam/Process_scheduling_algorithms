#pragma once
#include <stdio.h>
#include <vector>
#include <locale.h>
#include "structures.h"

using namespace std;
void SJN_avg_time(vector <Process>& processes)
{
	printf("\nSJN\n");
	vector <int> p, bt, wt, tat;

	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;

	n = processes.size();

	for (i = 0; i < n; i++) {

		bt.push_back(processes[i].burst_time); // Записываем в матрицу B_T_

		p.push_back(processes[i].Pid);		 // Записываем номер процесса

	}

	// Сортировка по burst_time

	for (i = 0; i < n; i++) {

		index = i;

		for (j = i + 1; j < n; j++)
		{
			if (bt[j] < bt[index])
				index = j;
		}

		temp = bt[i];

		bt[i] = bt[index];

		bt[index] = temp;


		temp = p[i];

		p[i] = p[index];

		p[index] = temp;

	}

	wt.push_back(0);

	// Вычисление времени ожидания (W_T_)

	for (i = 1; i < n; i++) {

		wt.push_back(0);

		for (j = 0; j < i; j++)
			wt[i] += bt[j];
		total += wt[i];

	}

	avg_wt = (float)total / n;

	total = 0;

	//printf("P - номер процесса\n");
	//printf("BT - burst time, время отработки процесса\n");
	//printf("WT - waiting time, время ожидания начала выполнения процесса\n");
	//printf("TAT - turn around time, время от вызова процесса, до его завершения. TAT = WT + BT при одновременном вызове процессов\n");
	
	//printf("P     BT     WT     TAT\n");

	// Вычисление T_A_T_ и печать


	for (i = 0; i < n; i++) {
		
		printf("%d ", p[i]);

		tat.push_back(bt[i] + wt[i]);

		total += tat[i];

		//printf("P%d     %d     %d      %d\n", p[i], bt[i], wt[i], tat[i]);
		
		// !!!	ПЕЧАТЬ ИДЁТ ПО СОРТИРОВАННОМУ ВЕКТОРУ ПРОЦЕССОВ ДЛЯ ВИДИМОСТИ ПОРЯДКА ВЫПОЛНЕНИЯ

	}
	printf("\n");

	avg_tat = (float)total / n;

	printf("Average waiting time= %.2f", avg_wt);
	printf("\nAverage turn around time = %.2f", avg_tat);
}

