#include <iostream>
#include <string>

using namespace std;

//Statusi per Task
enum TaskStatus {
    PENDING,
    COMPLETED
};

//Struktura per Task
struct Task {
    string description;
    TaskStatus status;
};

//Nr maksimal per tasks
const int MAX_TASKS = 100;

int main() {

    Task tasks[MAX_TASKS];
    //nr i tasks
    int taskCount = 0;
    //zgjidhja ne menu
    int choice;

    return 0;
}
