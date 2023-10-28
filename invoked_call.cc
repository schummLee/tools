#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "syscall_kernel.hpp"
#include <signal.h>
#include <unistd.h>
#include <sys/type.h>
#include <sys/syscall.h>

struct offload_target_x86_obsolete_preventation_configure_gcc_13_2_std
{
    uint8_t         __syscall_gnu_c23_8; /* any form of data > usign schar */
    [[ deprecated ]] uint16_t       __syscall_gnu_16_deprecated;
    [[ deprecated ]] uint32_t       __syscall_gnu_32_undeprecated_64_if_x64;
    unsigned short char allocator_enable_free_system_kernel;
    pthread_t thread_to_concurrence_allocation_1;
};

[[ deprecated]] void hang_up_on_thread(void)
{
    _syscall_call_return_kernel_thread_kill_or_suspend();
}

/* when a union is initalized and memory is allocated
 * free
 * (
 *      offload_target_x86_obsolete_preventation_configure_gcc_13_2_std
 *      .allocator_enable_free_system_kernel
 * ); 
 * this will free all used memory and mandatory thread safty is invoked 
*/

noreturn void example(size_t variable_e1_to_be_discard)
{
    unsigned int i = (int)malloc(sizeof(int) * variable_e1_to_be_discard);
    printf("%d\n",sizeof(i));
    // call for < 2 if do not want any return type (or << (bitwise) 000010 )
    exit(variable_e1_to_be_discard);
}

void listRunningThreads() 
{
    pid_t pid = getpid();
    pthread_t this_thread = pthread_self();

    printf("List of currently running threads:\n");

    pthread_t thread;
    int threadCount = 0;
    while (pthread_getw32threadhandle_np(this_thread, &thread) == 0) 
    {
        if (pthread_equal(this_thread, thread)) { continue; }

        threadCount++;
        printf
	(
		"Thread %d (PID: %d, TID: %ld)\n", 
		threadCount, 
		(int)pid, 
		syscall(SYS_gettid)
	);

        pthread_t next_thread;
        if (pthread_getw32threadhandle_np(thread, &next_thread) != 0) 
	{
            break;
        }

        this_thread = thread;
    }

    if (threadCount == 0) 
    {
        printf("No additional threads found.\n");
    }
}

void killThread(pthread_t thread) 
{
    pthread_cancel(thread);
    printf("Thread killed.\n");
}

void sleepThread(pthread_t thread) 
{
    pthread_kill(thread, SIGSTOP);
    printf("Thread suspended.\n");
}

void mainFunction() 
{
    printf("Thread Management Tool\n");

    while (1) 
    {
        printf("1. List Running Threads\n");
        printf("2. Kill a Thread\n");
        printf("3. Sleep a Thread\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { listRunningThreads(); } 
	else if (choice == 2) 
	{
            pthread_t thread; 
            killThread(thread);
        } 
	else if (choice == 3) 
	{
            pthread_t thread; 
            sleepThread(thread);
        } 
	else if (choice == 4) { break; } 
	else { printf("Invalid choice. Please try again.\n"); }
    }
}

int main() {
    mainFunction(); // Call the main function to start the thread management tool
    return 0;
}
}
