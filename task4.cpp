// TO-DO LIST
// Build a simple console-based to-do list
// manager that allows users to add, view, and
// delete tasks
// Task Input: Allow users to input tasks they want to add to the list.
// Add Task: Implement a function to add tasks to the list.
// View Tasks: Display the list of tasks with their status (completed or
// pending).
// Mark Task as Completed: Allow users to mark tasks as completed.
// Remove Task: Provide an option to remove tasks from the list

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - ";
            cout << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\n=== TO-DO LIST MANAGER ===" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t index;
                cout << "Enter index of task to mark as completed: ";
                cin >> index;
                todoList.markAsCompleted(index);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter index of task to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
