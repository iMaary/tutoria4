#include <stdio.h>
#include "process.h"
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Integer variables declared
    int qnt_process = 0, quantum = 0, process = 0, validate = 0, validate2 = 0, 
        response = 0, finish_time = 0, response_time = 0, wait_time = 0;

    scanf("%d %d", &qnt_process, &quantum);
    struct Process main_process[qnt_process + 1];
    int real_time[qnt_process + 1];

    for (int i = 0; i < qnt_process; i++) {
        scanf("%d %d", &main_process[i].arrival_time, &main_process[i].duration_time);
        real_time[i] = main_process[i].duration_time;
    }
    process = qnt_process;

    int index = 0, total_time = 0;
    while (process != 0) {

        if (real_time[index] <= quantum && real_time[index] > 0)
        {
            total_time = total_time + real_time[index];
            real_time[index] = 0;
            validate2 = 1;
        } else if (real_time[index] > 0) {
            real_time[index] = real_time[index] - quantum;
            total_time = total_time + quantum;
            if (validate == 1) {
                response++;
                validate = 0;
            }
        }

        if (real_time[index] == 0 && validate2 == 1) {
            process--;
            int wait = total_time - main_process[index].arrival_time - main_process[index].duration_time;
            int arrived_time = total_time - main_process[index].arrival_time;
            wait_time = wait_time + wait;
            finish_time = finish_time + arrived_time;
            validate2 = 0;
        }
        
        if (index == qnt_process - 1) {
            index = 0;
            validate = 1;
        }
        else if (main_process[index + 1].arrival_time <= total_time) {
            index++;
        } else {
            index = 0;
        }
    }
    // Averages floating variables declared and replaced
    float av_finish_time = (finish_time * 1.0 / qnt_process) + 1;
    float av_response_time = response * 1.0 / qnt_process;
    float av_wait_time = (wait_time * 1.0 / qnt_process) + 1;
    cout << "RR: " << av_finish_time << " " << av_response_time << " " << av_wait_time << endl;
    return 0;
}
