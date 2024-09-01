#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> taskList;

void addTask(const std::string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    taskList.push_back(task);
}

void viewTasks() {
    std::cout << "Task List:" << std::endl;
    for (int i = 0; i < taskList.size(); i++) {
        std::cout << "[" << i + 1 << "] " << taskList[i].description << " - ";
        if (taskList[i].completed) {
            std::cout << "Completed" << std::endl;
        } else {
            std::cout << "Pending" << std::endl;
        }
    }
}

void markTaskAsCompleted(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].completed = true;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void removeTask(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList.erase(taskList.begin() + taskIndex);
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "Task Management System" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(description);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3: {
                std::cout << "Enter task index to mark as completed: ";
                int taskIndex;
                std::cin >> taskIndex;
                markTaskAsCompleted(taskIndex - 1);
                break;
            }
            case 4: {
                std::cout << "Enter task index to remove: ";
                int taskIndex;
                std::cin >> taskIndex;
                removeTask(taskIndex - 1);
                break;
            }
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}