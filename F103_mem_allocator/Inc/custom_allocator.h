/*
 * custom_allocator.h
 *
 *  Created on: Oct 29, 2022
 *      Author: abhinav
 */

#ifndef CUSTOM_ALLOCATOR_H_
#define CUSTOM_ALLOCATOR_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 10 						  	// fixed memory size for memory array

/* < Variables for managing the memory array > */
extern unsigned int custom_memory[MEM_SIZE];  	// memory array to be used in allocation
extern unsigned int size_table[MEM_SIZE];	  	// it will store the number of units that will be allocated with corresponding address
extern unsigned int* address_table[MEM_SIZE]; 	// it will store the return address of the corresponding allocated units
extern unsigned int memory_size; 			  	// it will store the size of memory used for indexing memory array
extern unsigned int pointer_pos; 			  	// it will store the current updated index for memory array

void init_custom_memory(void);
unsigned int* custom_malloc(unsigned int);
void custom_free(unsigned int*);


#endif /* CUSTOM_ALLOCATOR_H_ */
