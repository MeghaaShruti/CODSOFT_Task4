#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Task{
	string description;
	bool completed;
};

class ToDoList{
	private:
		vector<Task>tasks;
		
	public:
		void addTask(const string& description){
			tasks.push_back({description, false});
			cout<<"Task added successfully."<<endl;
	}
	
	    void viewTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }
	
	    void markTaskCompleted(size_t index){
	     	if (index >= 1 && index <= tasks.size()) {
			tasks[index-1].completed = true;
			cout<<"Task marked as completed."<<endl;
		}
		else{
			cout<<"Invalid task index."<<endl;
		}
	}
	
	void removeTask(size_t index){
		if (index >= 1 && index <= tasks.size()) {
			tasks.erase(tasks.begin() + index-1);
			cout<<"Task removed successfully"<<endl;
		}
		else{
			cout<<"invalid task index"<<endl;
		}
	}						
};


int main(){
	ToDoList todo;
	int choice;
	string task;
	
	while(true){
		
		cout << "\n1.Add Task\n2. View Task\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
		
		switch(choice){
			case 1:
				cout<<"Enter task description:";
				cin.ignore();
				getline(cin,task);
				todo.addTask(task);
				break;
			case 2:
				todo.viewTasks();
				break;
			case 3:
				size_t index;
				cout<<"Enter task index to mark as completed:";
				cin>>index;
				todo.markTaskCompleted(index);
				break;
			case 4:
				cout<<"Enter task index to remove: ";
				cin>>index;
				todo.removeTask(index);
				break;
			case 5:
				cout<<"To-Do-List ends!."<<endl;
				return 0;
				default:
					cout<<"invalid. try again"<<endl;
		}
	}
	return 0;
}
