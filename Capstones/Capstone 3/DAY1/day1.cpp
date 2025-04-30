/*System Monitor Tool
Objective: Create a system monitor tool in C++ that displays real-time information about system processes, memory usage, and CPU load, similar to the 'top' command.
Day-wise Tasks:
Day 1: Design UI layout and gather system data using system calls.
Day 2: Display process list with CPU and memory usage.
Day 3: Implement process sorting by CPU and memory usage.
Day 4: Add functionality to kill processes.
Day 5: Implement real-time update feature to refresh data every few seconds.
*/

#include<iostream>
#include<sys/sysinfo.h>
using namespace std;

void displayMemoryInfo()
{
	struct sysinfo info;
	if(sysinfo(&info)==0)
	{
		cout<<"TOtal RAM:"<<info.totalram/(1024*1024)<<"MB\n";
		cout<<"TOtal RAM:"<<info.totalram/(1024*1024*1024)<<"GB\n";
		cout<<"TOtal RAM:"<<info.freeram/(1024*1024)<<"MB\n";
		cout<<"TOtal RAM:"<<info.freeram/(1024*1024)<<"GB\n";
	}
}
int main()
{
	displayMemoryInfo();
	return 0;
}

