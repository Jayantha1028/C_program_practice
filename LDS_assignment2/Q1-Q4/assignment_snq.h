#ifndef _assignment_snq_h_
#define _assignment_snq_h_
#include<stdint.h>
#include "../Stack_n_Queue/stack.h"
#include "../Stack_n_Queue/queue.h"
#include <assert.h>
#include<stdlib.h>

uint8_t ispalindrome(const int32_t size,char str[]);
int32_t *reverse_k_ele(int32_t arr[],const uint32_t len, uint32_t k);
int32_t *reverse_array(int32_t arr[],const uint32_t len);
int32_t *even_odd_sorting(int32_t arr[],uint32_t len);

#endif