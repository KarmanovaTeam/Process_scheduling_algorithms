#pragma once
enum PRIORITY
{
    LOW = 3,
    NORMAL = 2,
    HIGH = 1
};

struct Process {
    int Pid; //íîìåð ïðîöåññà(çàäà÷è), 
    int burst_time;// íà÷àëüíîå âðåìÿ
    int arriving_time;// âðåìÿ ïðèáûòèÿ
    PRIORITY priority = NORMAL;//Çà îñíîâó âçÿòà ñðåäíÿÿ ïðèîðèòåòíîñòü, ò.å. ãäå ïðèîðèòåòíîñòü íå óêàçàíà - îíà íîðìàëüíàÿ(ò.å. ðàâíà 2) 
    int total_time = 0;
    int tt_time = burst_time;
}; 

struct queues {
    int total_time = 0;
    int length = 0;
    Process* p;
    bool executed = false;
};


