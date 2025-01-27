#include <iostream>
using namespace std;

class Stack {
private:
    int* elements;  // Pointer to dynamic array (stack elements)
    int topIndex;    // Index to track the top of the stack
    static int counter; // Static counter to track the number of pushed elements

public:
    Stack(int size) : topIndex(-1) {
        elements = new int[size];  // Allocate memory for the stack
    }

    ~Stack() {
        delete[] elements;  // Free the allocated memory
    }

    // Push a value onto the stack
    void push(int value) {
        elements[++topIndex] = value;
        counter++;
        cout << "Pushed: " << value << endl;
    }

    // Pop a value from the stack
    void pop() {
        if (topIndex >= 0) {
            cout << "Popped: " << elements[topIndex--] << endl;
            counter--;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    // Friend function to display static count and elements in the stack
    friend void displayStack(const Stack& stack, bool isFirstTime);
};

// Initialize the static counter
int Stack::counter = 0;

// Friend function to display stack elements and the static counter
void displayStack(const Stack& stack, bool isFirstTime) {
    if (isFirstTime) {
        cout << "\n--- Stack Elements ---\n";

        if (stack.topIndex < 0) {
            cout << "Stack is empty!" << endl;
        } else {
            for (int i = stack.topIndex; i >= 0; i--) {
                cout << stack.elements[i] << " ";
            }
            cout << endl;
        }

        // Display the static counter (number of elements)
        cout << "Total elements pushed: " << Stack::counter << endl;
    } else {
        cout << "rabash\n";  // Print rabash in the second time
    }
}

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;  // Get the size of the array

    Stack stack(size);  // Create a stack with the given size
    int value;
    bool isFirstTime = true;  // Flag to check if it's the first time displaying stack

    // First output: ask the user to input values
    cout << "Please enter " << size << " values to push onto the stack:\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << i + 1 << ": ";  // Display prompt for each value
        cin >> value;
        stack.push(value);
    }

    // Display the stack and count (first time)
    displayStack(stack, isFirstTime);

    // After displaying, set the flag to false
    isFirstTime = false;

    // Second output: Display "rabash"
    displayStack(stack, isFirstTime);

    return 0;
}
