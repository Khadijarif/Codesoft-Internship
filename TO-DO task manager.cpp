#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

const int total_task = 100;

struct task {
    string headline;
    bool completed;
};

task list[total_task];
int count = 0;

void add_task(string& name) {
    if (count < total_task) {
        list[count].headline = name;
        list[count].completed = false;
        count++;
        cout << "Task '" << name << "' has been added successfully" << endl;
    }
    else {
        cout << "No more space" << endl;
    }
}

void task_view() {
    if (count == 0) {
        cout << "NO TASK AVAILABLE" << endl;
    }
    else {
        cout << "LIST : " << endl;
        for (int a = 0; a < count; a++) {
            string status = list[a].completed ? "(Complete)" : "(Pending)";
            cout << a + 1 << " : " << list[a].headline << "-" << status << endl;
        }
    }
}

void mark(int task_no) {
    if (task_no >= 1 && task_no <= count) {
        list[task_no - 1].completed = true;
        cout << "Task '" << list[task_no - 1].headline << "' marked as completed!" << endl;
    }
    else {
        cout << "Invalid task index." << endl;
    }
}

void remove(int task_no) {
    if (task_no >= 1 && task_no <= count) {
        task removedTask = list[task_no - 1];
        for (int i = task_no - 1; i < count - 1; ++i) {
            list[i] = list[i + 1];
        }
        --count;
        cout << "Task '" << removedTask.headline << "' removed successfully!" << endl;
    }
    else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    string name;
    int task_no;
    int removeIndex;

    while (true) {
    	cout<<"WELCOME!"<<endl;
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "SELECT : ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cin.ignore();
                    cout << "Enter the task description: ";
                    getline(cin, name);
                    add_task(name);
                }
                break;
            case 2:
                task_view();
                break;
            case 3:
                task_view();
                cout << "Enter the index of the task to mark as completed: ";
                cin >> task_no;
                mark(task_no);
                break;
            case 4:
                task_view();
                cout << "Enter the index of the task to remove: ";
                cin >> removeIndex;
                remove(removeIndex);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

