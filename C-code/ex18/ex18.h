#ifndef EX18
#define EX18

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die (const char *message);

typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmp);

void test_sorting(int *numbers, int count, compare_cb cmp);

int sorted_order (int a, int b);
int reverse_order (int a, int b);
int strange_order(int a, int b);


#endif

