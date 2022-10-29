/*
 * custom_allocator.c
 *
 *  Created on: Oct 29, 2022
 *      Author: abhinav
 */

#include "custom_allocator.h"

unsigned int custom_memory[MEM_SIZE];
unsigned int size_table[MEM_SIZE];
unsigned int* address_table[MEM_SIZE];
unsigned int memory_size;
unsigned int pointer_pos;

/*
 * @brief : Initialise the memory with 0
 * 		    updates memory size and pointer to 0
 * @param : None
 * @retval: None
 */
void init_custom_memory(void)
{
	memset(custom_memory, 0, sizeof(custom_memory));
	memory_size = MEM_SIZE-1;
	pointer_pos = 0;
}

/*
 * @brief : Returns the address from the memory array, after checking
 * 			the if the required number of memory units are available or not
 * @param : Number of memory units or size needed
 * @retval: Returns address if available else returns NULL
 */
unsigned int* custom_malloc(unsigned int memory_units)
{
	if((memory_units > memory_size) || (pointer_pos > memory_size))
	{
		return (unsigned int*)NULL;
	}

	for(int i = pointer_pos; i < (pointer_pos + memory_units); i++)
	{
		if(custom_memory[i] != 0)
		{
			return (unsigned int*)NULL;
		}
	}

	unsigned int *retval = &custom_memory[pointer_pos];
	size_table[pointer_pos] = memory_units;
	address_table[pointer_pos] = retval;

	for(int i = 0; i < memory_units; i++)
	{
		pointer_pos++;
	}

	return retval;

}

/*
 * @brief : Frees the memory of the given address and
 * 			initialises that memory block to 0
 * @param : Memory address to be freed
 * @retval: None
 */
void custom_free(unsigned int *ptr)
{
	unsigned int index      = 0;
	unsigned int reset_size = 0;

	for(index = 0; index < memory_size; index++)
	{
		if(address_table[index] == ptr)
		{
			break;
		}
	}

	pointer_pos = index;
	reset_size  = size_table[index];

	for(int i = pointer_pos; i < (pointer_pos + reset_size); i++)
	{
		custom_memory[i] = 0;
	}
}
