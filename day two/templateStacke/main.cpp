#include <iostream>
#include <vector>
using namespace std;

// Template stack class
template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    // Push a value onto the stack
    void push(T value) {
        elements.push_back(value);
        cout << "Pushed into Template Stack: " << value << endl; // Display pushed value
    }

    // Pop a value from the stack
    void pop() {
        if (!elements.empty()) {
            T removedValue = elements.back();
            elements.pop_back();
            cout << "Popped from Template Stack: " << removedValue << endl; // Display popped value
        } else {
            cout << "Template Stack is empty!" << endl;
        }
    }

    // Display the top value
    T top() const {
        if (!elements.empty()) {
            return elements.back();
        }
        throw out_of_range("Template Stack is empty!");
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Display all stack elements
    void display() const {
        if (elements.empty()) {
            cout << "Template Stack is empty!" << endl;
        } else {
            cout << "Elements in the Template Stack: ";
            for (int i = elements.size() - 1; i >= 0; i--) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "This is a Template Stack Program\n";

    Stack<int> stack;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display top\n4. Display all elements\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                try {
                    cout << "Top element in Template Stack is: " << stack.top() << endl;
                } catch (const out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting Template Stack Program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
