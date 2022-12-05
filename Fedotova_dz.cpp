#include <iostream> 
using namespace std;


struct Process {
	int pid; // Идентификатор процесса
	int bt; // Время взрыва
	int art; // Время прибытия 
};


///Функция для определения времени ожидания для всех процессов
void findWaitingTime(Process proc[], int n,
	int wt[])
{
	int* rt = new int[n];

	///Копия времени взрыва в rt[] 
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].bt;
	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;
	
	///Обрабатываtncz до тех пор, пока все процессы не будут завершены
	while (complete != n) {

		///Найти процесс с минимальным оставшимся временем среди процессов, которые поступают до текущего времени
		for (int j = 0; j < n; j++) {
			if ((proc[j].art <= t) &&
				(rt[j] < minm) && rt[j] > 0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		///Сократить оставшееся время на один
		rt[shortest]--;

		///Обновить минимум
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

		// Если процесс будет полностью выполнен
		if (rt[shortest] == 0) {

			///Инкремент завершен
			complete++;
			check = false;

			///Найти время завершения текущего процесса
			finish_time = t + 1;

			///Рассчитать время ожидания
			wt[shortest] = finish_time -
				proc[shortest].bt -
				proc[shortest].art;
			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++;

	}
}


///Функция для расчета времени обхода
void findTurnAroundTime(Process proc[], int n,
	int wt[], int tat[])
{
	///Расчет времени выполнения работ путем добавления bt[i] + wt[i] 
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];
}



///Функция для вычисления среднего времени
void findavgTime(Process proc[], int n)
{

	int total_wt = 0,
		total_tat = 0;
	int* wt = new int[n];
	int* tat = new int[n];


	///Функция для определения времени ожидания всех процессов
	findWaitingTime(proc, n, wt);
 
	///Функция для определения времени обхода для всех процессов
	findTurnAroundTime(proc, n, wt, tat);

	///Отображение процессов вместе со всеми подробностями
	cout << " P\t\t"
		<< "BT\t\t"
		<< "WT\t\t"
		<< "TAT\t\t\n";
	//cout << "P-номер процесса\n";
	//cout << "BT-время взрыва\n";
	//cout << "WT-время ожидания \n";
	//cout << "TAT-время оборота\n";


	///Рассчитать общее время ожидания и общее время выполнения работ
	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t\t " << wt[i]
			<< "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}


///Код драйвера
int main()
{
	Process proc[] = { { 1, 6, 2 }, { 2, 2, 5 },
					{ 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
	int n = sizeof(proc) / sizeof(proc[0]);
	findavgTime(proc, n);
	return 0;
}


