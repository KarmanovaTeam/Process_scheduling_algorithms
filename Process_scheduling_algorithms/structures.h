#pragma once
enum PRIORITY
{
    LOW = 3,
    NORMAL = 2,
    HIGH = 1
};

struct Process {
    int Pid; //����� ��������(������), 
    int burst_time;// ��������� �����
    int arriving_time;// ����� ��������
    PRIORITY priority = NORMAL;//�� ������ ����� ������� ��������������, �.�. ��� �������������� �� ������� - ��� ����������(�.�. ����� 2) 
}; 

struct queues {
    int total_time = 0;
    int length = 0;
    Process* p;
    bool executed = false;
};


