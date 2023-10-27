#include <iostream>
#include <vector>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

// Function to list all running threads
void listRunningThreads() 
{
    pid_t pid = getpid();
    pthread_t this_thread = pthread_self();

    std::cout << "List of currently running threads:" << std::endl;

    // Find and print information about each thread
    pthread_t thread;
    int threadCount = 0;
    while (pthread_getw32threadhandle_np(this_thread, &thread) == 0) 
    {
        if (pthread_equal(this_thread, thread)) 
	{
            // Skip the main thread
            continue;
        }

        threadCount++;
        std::cout << "Thread " << \
	threadCount << " (PID: " << \
	pid << ", TID: " << \
	syscall(SYS_gettid) << \
	 ")" << std::endl;

        // Print more thread information here if needed
        // For example, you can retrieve the thread's name or other details.

        // Move to the next thread
        pthread_t next_thread;
        if (pthread_getw32threadhandle_np(thread, &next_thread) != 0) 
	{
            break;
        }

        this_thread = thread;
    }

    if (threadCount == 0) 
{
        std::cout << "No additional threads found." << std::endl;
    }
}

void killThread(pthread_t thread) 
{
    pthread_cancel(thread);
    std::cout << "Thread killed." << std::endl;
}

void sleepThread(pthread_t thread) 
{
    pthread_kill(thread, SIGSTOP);
    std::cout << "Thread suspended." << std::endl;
}

void mainFunction() 
{
    std::cout << "Thread Management Tool" << std::endl;

    while (true) 
    {
        std::cout << "1. List Running Threads" << std::endl;
        std::cout << "2. Kill a Thread" << std::endl;
        std::cout << "3. Sleep a Thread" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) { listRunningThreads(); } 
	else if (choice == 2) { pthread_t thread; killThread(thread); } 
	else if (choice == 3) { pthread_t thread;  sleepThread(thread); } 
	else if (choice == 4) { break; } 
	else { std::cout << "Invalid choice. Please try again." << std::endl; }
    }
}

auto main() -> int  
{
    mainFunction(); // Call the main function to start the thread management tool
    return 0;
}


