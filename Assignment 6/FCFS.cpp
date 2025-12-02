#include <iostream>
using namespace std;

class process {
   public:
    int burst, pid, arrival;
};

bool compTasks(process a, process b){
    if (a.arrival == b.arrival) return a.pid < b.pid;
    return a.arrival < b.arrival;
}

void fcfs(process arr[], int n){
    vector<int> gantt;
    sort(arr, arr+n, compTasks);
    
    int currtime = 0;
    int delay = 0;
    int WTPerProcess[n];
    float avgWT = 0;
    int TAT[n];
    float avgTAT = 0;

    for(int i = 0; i < n; i++){
        if (currtime <= arr[i].arrival) {
            delay = arr[i].arrival - currtime;
            currtime += arr[i].burst + delay;
            WTPerProcess[i] = 0;
            gantt.push_back(arr[i].pid);
        }
        else {
            WTPerProcess[i] = currtime - arr[i].arrival;
            currtime += arr[i].burst;
            gantt.push_back(arr[i].pid);
        }
    }

    for(int i = 0; i < n; i++){
        avgWT += WTPerProcess[i];
        TAT[i] = WTPerProcess[i] + arr[i].burst;
        avgTAT += TAT[i];
    }

    avgWT /= n;
    avgTAT /= n;
}

int main(){
    
 
    return 0;
}