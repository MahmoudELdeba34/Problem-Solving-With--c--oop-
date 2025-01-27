#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor to initialize the queue
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to add an element to the queue (push)
    void push(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) {  // First element being added
            front = 0;
        }

        rear = (rear + 1) % size;  // Move rear to next position in circular manner
        arr[rear] = value;
    }

    // Function to remove a specific element from the queue (pop)
    void pop(int value) {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // Find the index of the element to be removed
        int index = -1;
        for (int i = front; i != rear; i = (i + 1) % size) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }
        if (arr[rear] == value) {  // Special case for rear element
            index = rear;
        }

        if (index == -1) {
            cout << "Value not found in the queue!" << endl;
            return;
        }

        cout << "Popped value: " << arr[index] << endl;

        // Shift all elements after the index to the left to fill the gap
        for (int i = index; i != rear; i = (i + 1) % size) {
            arr[i] = arr[(i + 1) % size];
        }

        // Special case when the element to be removed is the rear
        if (index == rear) {
            rear = (rear - 1 + size) % size;
        } else {
            rear = (rear - 1 + size) % size;
        }

        // If the queue becomes empty, reset the front and rear
        if (front == (rear + 1) % size) {
            front = rear = -1;
        }
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;  // Circular traversal
        }
        cout << arr[rear] << endl;  // Print the rear element
    }
};

int main() {
    int n, value;

    // Get number of elements in the queue from the user
    cout << "Enter number of elements in the queue: ";
    cin >> n;

    // Create a queue of size n
    CircularQueue q(n);

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

    // Ask user to select the value to pop
    cout << "Enter the value you want to pop: ";
    cin >> value;

    // Perform pop operation on the selected value
    q.pop(value);

    // Display the queue after pop operation
    cout << "Queue after pop operation: ";
    q.display();

    return 0;
}
