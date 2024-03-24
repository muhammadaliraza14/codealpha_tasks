#include <iostream>
#include <cstring>
using namespace std;

struct Task {
    char description[100];
    bool completed;
};

class ToDoList {
private:
    Task tasks[100];
    int numTasks;

public:
    ToDoList() {
        numTasks = 0;
    }

    void addTask(const char* description) {
        if (numTasks < 100) {
            strcpy(tasks[numTasks].description, description);
            tasks[numTasks].completed = false;
            numTasks++;
            cout << "Task added successfully." << endl;
        } else {
            cout << "Cannot add more tasks. ToDo list is full." << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < numTasks) {
            tasks[index].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        if (numTasks == 0) {
            cout << "No tasks in the ToDo list." << endl;
        } else {
            cout << "Current tasks:" << endl;
            for (int i = 0; i < numTasks; ++i) {
                cout << (i + 1) << ". ";
                if (tasks[i].completed) {
                    cout << "[X] ";
                } else {
                    cout << "[ ] ";
                }
                cout << tasks[i].description << endl;
            }
        }
    }
};

int main() {
    ToDoList todo;

    int choice;
    do {
        cout << "\n===== ToDo List Menu =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task Completed" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();
                cout << "Enter task description: ";
                char description[100];
                cin.getline(description, sizeof(description));
                todo.addTask(description);
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                todo.markTaskCompleted(index - 1);
                break;
            }
            case 3: {
                todo.displayTasks();
                break;
            }
            case 4: {
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
