#include<iostream> 
#include <stdio.h>
using namespace std; 
  
// Function to find the waiting time for all  
// processes 
void findWaitingTime(int processes[], int n,  
                          int bt[], int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime( int processes[], int n,  
                  int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime( int processes[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all processes 
    findWaitingTime(processes, n, bt, wt); 
  
    //Function to find turn around time for all processes 
    findTurnAroundTime(processes, n, bt, wt, tat); 
  
    //Display processes along with all details 
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn  
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = " 
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " 
         << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main() 
{ 
    int processCount;
    printf("Process Count : ");
    scanf("%d", &processCount);

    //process id's 
    int processes[processCount]; 
    int  burst_time[processCount] ;
    for(int i = 0 ; i < processCount; i++){
        printf("Process %d Arrival Time : ",i+1);
        scanf("%d", &processes[i]);
        printf("Burst Time %d : ",i+1);
        scanf("%d", &burst_time[i]);
    }
  
    
    findavgTime(processes, processCount,  burst_time); 
    return 0; 
} 