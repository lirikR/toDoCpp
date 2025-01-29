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

// Printojme titullin per menu te gjeneruar me ASCII Generator
void printTitle() {
    cout << R"(
___________              ________                .____    .__          __   
\__    ___/___           \______ \   ____        |    |   |__| _______/  |_ 
  |    | /  _ \   ______  |    |  \ /  _ \       |    |   |  |/  ___/\   __\
  |    |(  <_> ) /_____/  |    `   (  <_> )      |    |___|  |\___ \  |  |  
  |____| \____/          /________/\____/        |________\__/____  > |__|  
    )" << "\n";
}

//Deklarimi inicial per perdorimin e funksioneve
void addTask(Task tasks[], int& taskCount);
void markTaskCompleted(Task tasks[], int taskCount);
void deleteTask(Task tasks[], int& taskCount);
void displayTasks(const Task tasks[], int taskCount);
bool promptReturnToMenu();

//Nr maksimal per tasks
const int MAX_TASKS = 100;

int main() {

    Task tasks[MAX_TASKS];
    //nr i tasks
    int taskCount = 0;
    //zgjidhja ne menu
    int choice;

    do {
        printTitle(); //Printojme titullin ASCII
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Delete Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                markTaskCompleted(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, taskCount);
                break;
            case 4:
                displayTasks(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (promptReturnToMenu());

    return 0;
}

// Funksioni per te shtuar taks
void addTask(Task tasks[], int& taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full. Cannot add more tasks.\n";
        return;
    }

    cout << "Enter the task description: ";
    string description;
    getline(cin, description);

    tasks[taskCount].description = description;
    tasks[taskCount].status = PENDING;
    taskCount++;

    cout << "Task added successfully!\n";
}


//Statusi per taskun
void markTaskCompleted(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }

    displayTasks(tasks, taskCount);

    int taskIndex;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> taskIndex;
    

    if (taskIndex >= 0 && taskIndex < taskCount) {
        tasks[taskIndex].status = COMPLETED;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

// funksioni per fshirjen e nje tasku
void deleteTask(Task tasks[], int& taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available to delete.\n";
        return;
    }

    displayTasks(tasks, taskCount);

    int taskIndex;
    cout << "Enter the index of the task to delete: ";
    cin >> taskIndex;

    if (taskIndex >= 0 && taskIndex < taskCount) {
        for (int i = taskIndex; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

// funksioni i paraqitjes se tasks
void displayTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n--- Tasks ---\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i << ". " << tasks[i].description << " - "
             << (tasks[i].status == PENDING ? "Pending" : "Completed") << "\n";
    }
}

//Pyesim user a deshiron te vazhdoj ne menu
bool promptReturnToMenu() {
    char choice;
    cout << "\nReturn to menu? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
