#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor  queue
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == size - 1;
    }

    // Function to add an element to the queue (push)
    void push(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }

    // Function to remove a specific element from the queue (pop)
    void pop(int index) {
        if (isEmpty() || index < front || index > rear) {
            cout << "Invalid index or empty queue!" << endl;
            return;
        }

        // If we're removing the last element
        if (index == rear) {
            --rear;
        } else {
            // Remove the element at the specified index
            int valueToRemove = arr[index];
            cout << "Popped value: " << valueToRemove << endl;

            // Shift all elements after the index to the left to fill the gap
            for (int i = index; i < rear; ++i) {
                arr[i] = arr[i + 1];
            }

            --rear;
        }

        // If the queue becomes empty, reset the front and rear
        if (rear == -1) {
            front = -1;
        }
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, value, index;

    // Get number of elements in the queue from the user
    cout << "Enter number of elements in the queue: ";
    cin >> n;

    // Create a queue of size n
    Queue q(n);

    // Input values for the queue (one at a time)
    cout << "Enter " << n << " values for the queue:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        q.push(value);
    }

    // Display the original queue
    cout << "Original Queue: ";
    q.display();

    // Ask user to select the index of the element to pop
    cout << "Enter the index (0 to " << n - 1 << ") of the element to pop: ";
    cin >> index;

    // Perform pop operation at the chosen index
    q.pop(index);

    // Display the modified queue
    cout << "Queue after pop operation: ";
    q.display();

    return 0;
}
