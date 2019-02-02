//
//  Memory420.c
//  Lab02
//
//  Created by Aaron David Block on 1/28/19.
//  Copyright © 2019 Aaron David Block. All rights reserved.
//

#include "ACMemory.h"
#include <assert.h>

#include <stdio.h>

const size_t sizet_size = sizeof(size_t);
const size_t overhead_size = sizeof(void*) + sizet_size;
const size_t base_allocation_size = 4096;
const size_t max_threads_per_process = 7;
const size_t process_heap_size = base_allocation_size;
const size_t thread_stack_size = base_allocation_size;
const size_t process_size = thread_stack_size * max_threads_per_process + base_allocation_size;


#define element_size_heap(X) *(size_t*)(X - sizet_size)
#define next_element_heap(X) *(void**)(X - overhead_size)


