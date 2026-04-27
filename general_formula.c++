#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;

    int completion;
    int waiting;
    int turnaround;
    int response_time;

    int priority;

    int start_time;
    bool completed;
};

struct Segment {
    int pid;
    int start;
    int end;
};

void addSegment(vector<Segment>& gantt, int pid, int start, int end) {
    Segment s;
    s.pid = pid;
    s.start = start;
    s.end = end;
    gantt.push_back(s);
}

vector<Process> readProcesses(const char* filename) {
    FILE *fp = fopen(filename, "r");

    vector<Process> processes;

    if (fp == NULL) {
        printf("File open failed\n");
        return processes;
    }

    Process p;

    while (fscanf(fp, "%d %d %d %d",
                  &p.pid,
                  &p.arrival,
                  &p.burst,
                  &p.priority) != EOF) {

        // Initialize extra fields
        p.remaining = p.burst;
        p.completion = 0;
        p.waiting = 0;
        p.turnaround = 0;
        p.start_time = -1;
        p.completed = false;

        processes.push_back(p);
    }

    fclose(fp);
    return processes;
}



