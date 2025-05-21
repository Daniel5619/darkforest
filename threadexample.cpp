#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

// how to run and compile: g++ -std=c++11 thread_example.cpp -pthread -o thread_example
// Mutex for synchronizing access to shared resources (cout in this case)
std::mutex print_mutex;

// A simple function to demonstrate basic thread execution
void print_numbers(int start, int end, const std::string& thread_name) {
    for (int i = start; i <= end; i++) {
        // Lock the mutex before printing to avoid mixed output from different threads
        std::lock_guard<std::mutex> guard(print_mutex);
        std::cout << thread_name << " printing: " << i << std::endl;
        
        // Simulate some work by sleeping for 100ms
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// A shared counter to demonstrate data race conditions and mutex usage
class SharedCounter {
private:
    int count;
    std::mutex counter_mutex;

public:
    SharedCounter() : count(0) {}

    // Thread-safe increment operation
    void increment() {
        std::lock_guard<std::mutex> guard(counter_mutex);
        count++;
    }

    // Thread-safe get operation
    int get_count() {
        std::lock_guard<std::mutex> guard(counter_mutex);
        return count;
    }
};

int main() {
    std::cout << "Multi-threading Example Program\n" << std::endl;

    // Example 1: Basic thread creation and execution
    std::cout << "Example 1: Creating two threads to print numbers" << std::endl;
    
    // Create two threads that will run concurrently
    std::thread thread1(print_numbers, 1, 5, "Thread 1");
    std::thread thread2(print_numbers, 6, 10, "Thread 2");

    // Wait for both threads to complete
    thread1.join();
    thread2.join();

    std::cout << "\nExample 2: Multiple threads incrementing a shared counter\n" << std::endl;

    // Create a shared counter
    SharedCounter counter;
    std::vector<std::thread> threads;

    // Create 5 threads that will increment the counter
    for (int i = 0; i < 5; i++) {
        threads.push_back(std::thread([&counter]() {
            for (int j = 0; j < 1000; j++) {
                counter.increment();
                std::this_thread::sleep_for(std::chrono::microseconds(10));
            }
        }));
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    // Print the final counter value
    std::cout << "Final counter value: " << counter.get_count() << std::endl;
    std::cout << "Expected counter value: " << (5 * 1000) << std::endl;

    return 0;
} 