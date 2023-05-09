#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Data structure to store a Job
struct Job {
    int start, finish, profit;
};

int findLastNonConflictingJob(vector<Job> const &jobs, int n)
{
    // find the last job index whose finish time is less than or equal to the
    // given job's start time
    for (int i = n - 1; i >= 0; i--)
    {
        if (jobs[i].finish <= jobs[n].start) {
            return i;
        }
    }
 
    // return the negative index if no non-conflicting job is found
    return -1;
}
 
// Function to find the maximum profit of non-overlapping jobs using DP
int findMaxProfit(vector<Job> jobs)        // no-ref, no-const
{
    // sort jobs in increasing order of their finish times
    sort(jobs.begin(),
        jobs.end(),
        [](Job &x, Job &y) {
            return x.finish < y.finish;
        });
 
    // get the number of jobs
    int n = jobs.size();
 
    // construct a lookup table where the i'th index stores the maximum profit
    // for the first `i` jobs
    int maxProfit[n];
 
    // maximum profit gained by including the first job
    maxProfit[0] = jobs[0].profit;
 
    // fill the `maxProfit[]` table in a bottom-up manner from the second index
    for (int i = 1; i < n; i++)
    {
        // find the index of the last non-conflicting job with the current job
        int index = findLastNonConflictingJob(jobs, i);
 
        // include the current job with its non-conflicting jobs
        int incl = jobs[i].profit;
        if (index != -1) {
            incl += maxProfit[index];
        }

        maxProfit[i] = max(incl, maxProfit[i-1]);
    }

    return maxProfit[n-1];
}
int main()
{
    vector<Job> jobs {
        { 0, 6, 60 },
        { 1, 4, 30 },
        { 3, 5, 10 },
        { 5, 7, 30 },
        { 5, 9, 50 },
        { 7, 8, 10 }
    };
 
    cout << "The maximum profit is " << findMaxProfit(jobs);
    return 0;
}


