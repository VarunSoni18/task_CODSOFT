#include <iostream>
#include <string>
using namespace std;

class Task
{
private:
    struct TaskItem {
        string description;
        bool completed;
    };

    TaskItem tasks[20];
    int task_count = 0;

public:
    int option = -1;

    void tasklist_menu()
    {
        while (option != 0)
        {
            cout << "-----------------This is the to-do list-----------" << endl;
            cout << "ENTER 0 to terminate the list" << endl;
            cout << "ENTER 1 to add a new task" << endl;
            cout << "ENTER 2 to view tasks" << endl;
            cout << "ENTER 3 to delete a task from the list" << endl;
            cout << "ENTER 4 to mark a task as completed" << endl;
            
            cin >> option;
            cin.ignore(); // Ignore newline left in buffer

            inputs();
        }
    }

    void print_tasks()
    {
        cout << "THE tasks to do:" << endl;
        for (int i = 0; i < task_count; i++)
        {
            cout << "TASK " << i << ": " << tasks[i].description;
            if (tasks[i].completed)
            {
                cout << " [COMPLETED]";
            }
            cout << endl;
        }
    }

    void inputs()
    {
        switch (option)
        {
        case 1:
            if (task_count >= 20)
            {
                cout << "TASK list is full" << endl;
            }
            else
            {
                cout << "ENTER a new task description:" << endl;
                getline(cin, tasks[task_count].description);
                tasks[task_count].completed = false; // New task is initially not completed
                task_count++;
            }
            break;

        case 2:
            print_tasks();
            break;

        case 3:
            {
                int del_task;
                cout << "ENTER the index of the task to delete:" << endl;
                cin >> del_task;
                if (del_task < 0 || del_task >= task_count)
                {
                    cout << "INVALID task index" << endl;
                }
                else
                {
                    for (int i = del_task; i < task_count - 1; i++)
                    {
                        tasks[i] = tasks[i + 1];
                    }
                    task_count--;
                }
            }
            break;

        case 4:
            {
                int mark_task;
                cout << "ENTER the index of the task to mark as completed:" << endl;
                cin >> mark_task;
                if (mark_task < 0 || mark_task >= task_count)
                {
                    cout << "INVALID task index" << endl;
                }
                else
                {
                    tasks[mark_task].completed = true;
                    cout << "THE chosen task is marked as completed" << endl;
                }
            }
            break;

        default:
            cout << "INVALID option" << endl;
            break;
        }
    }
};

int main()
{
    Task t;
    t.tasklist_menu();
    return 0;
}