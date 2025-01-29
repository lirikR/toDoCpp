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

    } while (promptReturnToMenu());

    return 0;
}


//Pyesim user a deshiron te vazhdoj ne menu
bool promptReturnToMenu() {
    char choice;
    cout << "\nReturn to menu? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}