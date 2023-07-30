#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1005;
const int MAX_M = 1005;

bool backtrack(int worker, int n, int m, int* job_assignment, int** worker_jobs, bool* used_jobs) {
    if (worker == n + 1) {
        return true;
    }

    for (int i = 1; i <= worker_jobs[worker][0]; ++i) {
        int job = worker_jobs[worker][i];
        if (!used_jobs[job]) {
            job_assignment[worker] = job;
            used_jobs[job] = true;

            if (backtrack(worker + 1, n, m, job_assignment, worker_jobs, used_jobs)) {
                return true;
            }

            job_assignment[worker] = 0;
            used_jobs[job] = false;
        }
    }

    return false;
}

void assign_jobs_to_workers(int n, int m, int** worker_jobs, int* result) {
    int job_assignment[MAX_N];
    memset(job_assignment, 0, sizeof(job_assignment));

    bool used_jobs[MAX_M] = {false};

    if (backtrack(1, n, m, job_assignment, worker_jobs, used_jobs)) {
        for (int worker = 1; worker <= n; ++worker) {
            result[worker] = job_assignment[worker];
        }
    } else {
        for (int worker = 1; worker <= n; ++worker) {
            result[worker] = -1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int** worker_jobs = new int*[n + 1];
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        worker_jobs[i] = new int[k + 1];
        worker_jobs[i][0] = k;
        for (int j = 1; j <= k; ++j) {
            cin >> worker_jobs[i][j];
        }
    }

    int* result = new int[n + 1];
    assign_jobs_to_workers(n, m, worker_jobs, result);
    if(result[1]==-1) {
        cout<<-1;
        return 0;
    }
    for (int worker = 1; worker <= n; ++worker) {
        cout << worker << " " << result[worker] << endl;
    }

    for (int i = 1; i <= n; ++i) {
        delete[] worker_jobs[i];
    }
    delete[] worker_jobs;
    delete[] result;

    return 0;
}
