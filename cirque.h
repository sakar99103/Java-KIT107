// KIT107 Lab 11: cirque
/*
 * Specification for the cirque ADT
 * Author Julian Dermoudy
 * Version 17/5/18
*/

#include <stdbool.h>

struct cirque_int;
typedef struct cirque_int *cirque;

void init_cirque(cirque *p);
bool isEmpty(cirque p);
void add(cirque p,void *o);
void *nextOne(cirque p);
void rear(cirque p);
char *toString(cirque p,char *(*makePrintable)(void *));