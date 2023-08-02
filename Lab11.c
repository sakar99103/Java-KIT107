// KIT107 Lab 11: Harness
/*
 * Program to illustrate implementation of cirque
 * Author Julian Dermoudy
 * Version 17/5/18
 */

#include <stdio.h>
#include "cirque.h"

char *makePrintable(void *t)
{
	return (char *)t;
}

int main(int argc, char *argv[])
{
	cirque p;
	char *animals[]={"cat","dog","horse","aardvark","cow","pig"};
	int i;
		
	printf("Building cirque...");
	init_cirque(&p);
		
	for (i=0;i<6; i++)
	{
		printf("adding %s...",animals[i]);
		add(p,animals[i]);
	}
	printf("done.\n");

	printf("Cirque is %s\n",toString(p,makePrintable));
	printf("First value is %s\n",makePrintable(nextOne(p)));

	printf("Before removal cirque is %s\n",toString(p,makePrintable));
	rear(p);
	printf("After removal cirque is %s\n",toString(p,makePrintable));

	printf("First thirteen items are...");
	for (i=1; i<=12; i++)
	{
		printf("%s, ",makePrintable(nextOne(p)));
	}
	printf("%s\n",makePrintable(nextOne(p)));
}
