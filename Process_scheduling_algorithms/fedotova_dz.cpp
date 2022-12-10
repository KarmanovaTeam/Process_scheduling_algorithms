#include <iostream> 
#include<vector>
using namespace std;


struct Process {
	int Pid; // Идентификатор процесса
	int burst_time; // Время взрыва
	int arriving_time; // Время прибытия 
};


///Функция для определения времени ожидания для всех процессов
template <typename T>
void findWaitingTime(vector <T>& proc, const int& n,
	vector <int>& wt)
{
	vector<int> rt;
	rt.resize(n);

	///Копия времени взрыва в rt[] 
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].burst_time;
	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	///Обрабатываtncz до тех пор, пока все процессы не будут завершены
	while (complete != n) {

		///Найти процесс с минимальным оставшимся временем среди процессов, которые поступают до текущего времени
		for (int j = 0; j < n; j++) {
			if ((proc[j].arriving_time <= t) &&
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
				proc[shortest].burst_time -
				proc[shortest].arriving_time;
			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++;

	}
}


///Функция для расчета времени обхода
void findTurnAroundTime(vector <Process>& proc, const int& n,
	vector <int>& wt, vector <int>& tat)
{
	///Расчет времени выполнения работ путем добавления bt[i] + wt[i] 
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].burst_time + wt[i];
}



///Функция для вычисления среднего времени
void findavgTime(vector <Process>& proc, const int& n)
{

	int total_wt = 0,
		total_tat = 0;
	vector <int> wt;
	wt.resize(n);
	vector <int> tat;
	tat.resize(n);


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
		cout << " " << proc[i].Pid << "\t\t"
			<< proc[i].burst_time << "\t\t " << wt[i]
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
	vector <Process> proc = { { 1, 6, 2 }, { 2, 2, 5 },
					{ 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
	const int n = proc.size();
	findavgTime(proc, n);
	return 0;
}
