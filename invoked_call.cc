#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "syscall_kernel.hpp"

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
