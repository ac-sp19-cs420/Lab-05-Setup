//
//  Memory420.h
//  Lab02
//
//  Created by Aaron David Block on 1/28/19.
//  Copyright © 2019 Aaron David Block. All rights reserved.
//

#ifndef ACMemory_h
#define ACMemory_h
//Chars and bytes are interchangable in C, but this will make our code read easier



#include <stdlib.h>

#define byte char

/* To declare a global variable you need to declare it in the header using extern
 * then in the implementation file you need to include it's acutal declearation
 */
extern const size_t sizet_size; //Defined to be sizeof(size_t) in implementation file
extern const size_t overhead_size; //Defined to be sizeof(void*) + sizet_size in implementation file
extern const size_t base_allocation_size; //We make the size of all heaps and thread stacks 4096 for simplicity
extern const size_t max_threads_per_process; //We only allow a limited number of threads for simplicity.
extern const size_t process_heap_size; //For simplicity all process heaps will be allocated this amount of space
extern const size_t thread_stack_size; //For simplicity all threads will receive stacks of a uniform size;
extern const size_t process_size; //For simplicity all processes will be allocated this amount of space

struct Process;
//Don't touch this
typedef struct OS_Memory {
    void* data;
    unsigned long max_number_of_processes;
    size_t size_of_data;
    struct Process* processes;
    unsigned long next_pid;
} OS_Memory;

struct Thread;
struct Process{
    OS_Memory* os;
    unsigned long pid;
    unsigned long next_tid;
    
    size_t size_of_heap;
    void* start_of_heap;
    void* start_of_free_list;
    
    struct Thread* threads;
    
};
typedef struct Process Process;


typedef struct Thread{
    Process* pr;
    unsigned long tid; //Internall only to Process
    
    size_t size_of_stack;
    void* stack_pointer;
    void* start_of_stack;
} Thread;

// Return 0 if failure 1 if success.
OS_Memory* initialize_memory(unsigned long max_num_processes);

/* frees the memory allocated. Will Dealocate memory as well */
void free_memory(OS_Memory* memory);

Process* create_process(OS_Memory* memory);
void kill_process(Process* process);

Thread* create_thread(Process* process);
void kill_thread(Thread* thread);




/* Pushes the data in bytes onto the stack and returns a pointer to the data's location
 * returns 0 if there is a failure.
 */
void* push_bytes(Thread* thread, void* data, size_t size);



/* Returns a pointer to the top element on the stack, 0 if there is a failure */

void* get_bytes(Thread* thread);


/* Pops off top value from stack.
 * Returns pointer to the popped element, 0 if there is an error.
 * While Pointer is *removed* from the stack, it still lives in memory for a short time. Therefore, if you want to use this data you should immediatly copy it to a more persistant data location since the next push will destroy the data.
 */
void* pop_bytes(Thread* thread);



/* Similar to malloc(), but all in user space */
void* memory_alloc(Process* memory, size_t size);

/* conviencen method that calls memory_alloc internally but called by thread */
void* tm_alloc(Thread* memory, size_t size);


/* Similar to free(), but all in user space */
void memory_dealloc(Process* memory, void* ptr);

/* conviencen method that calls memory_dealloc internally but called by thread */
void tm_dealloc(Thread* memory, void* ptr);



#endif /* Memory420_h */
