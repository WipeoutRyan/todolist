#include <iostream>
#include <vector>
#include <string>

class TodoList {
private:
    struct Task {
        std::string description;
        bool completed;

        Task(const std::string& desc) : description(desc), completed(false) {}
    };

    std::vector<Task> tasks;

public:
    // Add a new task to the list
    void add(const std::string& description) {
        tasks.push_back(Task(description));
    }

    // Mark a task as complete by its index
    void complete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        }
    }

    // Show all items in the list (both complete and incomplete)
    void all() const {
        std::cout << "All tasks:\n";
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            std::cout << (it - tasks.begin() + 1) << ". " << it->description;
            if (it->completed) {
                std::cout << " - Completed";
            }
            std::cout << std::endl;
        }
    }

    // Show any completed items in the list
    void completed() const {
        std::cout << "Completed tasks:\n";
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->completed) {
                std::cout << (it - tasks.begin() + 1) << ". " << it->description << std::endl;
            }
        }
    }

    // Show any incomplete items in the list
    void incomplete() const {
        std::cout << "Incomplete tasks:\n";
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (!it->completed) {
                std::cout << (it - tasks.begin() + 1) << ". " << it->description << std::endl;
            }
        }
    }

    // Clear the todo list
    void clear() {
        tasks.clear();
    }
};

int main() {
    TodoList todo;

    todo.add("Complete assignment");
    todo.add("Go for a run");
    todo.add("Buy groceries");

    todo.all();

    todo.complete(0);
    todo.complete(2);

    todo.completed();
    todo.incomplete();

    todo.clear();

    todo.all();

    return 0;
}
