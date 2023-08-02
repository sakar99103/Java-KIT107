// KIT107 Lab 11: cirque
/*
 * Implementation for cirque using doubly-linked list
 * Author Julian Dermoudy
 * Version 17/5/18
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dnode.h"
#include "cirque.h"

struct cirque_int {
	dnode cursor;
};

/*
 * 'Constructor' for cirque
 */
void init_cirque(cirque *p)
{
	*p=(cirque)malloc(sizeof(struct cirque_int));
	(*p)->cursor=NULL;
}

/*
 * Check for emptiness
 * Return true if cirque is empty, false otherwise
*/
bool isEmpty(cirque p)
{
	return (p->cursor == NULL);
}

/*
 * Find current item in cirque, advancing cursor to next
 * Return value under cursor when function is called
*/
void *nextOne(cirque p)
{
	if (isEmpty(p))
	{
		fprintf(stderr,"cirque is empty.");
		exit(1);
	}
	
	p->cursor=getNext(p->cursor);
	return getData(getPrev(p->cursor));
}

/*
 * Remove current item from cirque
*/
void rear(cirque p)
{
	if (isEmpty(p))
	{
		fprintf(stderr,"cirque is empty.");
		exit(1);
	}
	else
	{
		if (p->cursor == getNext(p->cursor))
		{
			p->cursor=NULL;
		}
		else
		{
			setNext(getPrev(p->cursor),getNext(p->cursor));
			setPrev(getNext(p->cursor),getPrev(p->cursor));
			p->cursor=getNext(p->cursor);
		}
	}
}

/*
 * Add item to cirque in front of cursor
 * Param o value to be added to cirque
*/
void add(cirque p,void *o)
{
	dnode n;

	init_dnode(&n,o);

	if (isEmpty(p))
	{
		p->cursor=n;
	}
	else
	{
		setNext(n,p->cursor);
		setPrev(n,getPrev(p->cursor));
		setNext(getPrev(p->cursor),n);
		setPrev(p->cursor,n);
	}
}

/*
 * Find printable form of cirque
 * Return string form of cirque for printing etc.
*/
char *toString(cirque p,char *(*makePrintable)(void *))
{
	dnode c;
	bool done;
	char *s=(char *)malloc(1000*sizeof(char));
	
	if (isEmpty(p))
		sprintf(s,"<>");
	else
	{
		done=false;
		sprintf(s,"<");
		c=p->cursor;
		while ((c != p->cursor) || (! done))
		{
			if (c == p->cursor)
			{
				sprintf(s,"%s[%s]",s,(*makePrintable)(getData(c)));
				done=true;
			}
			else
			{
				sprintf(s,"%s%s",s,(*makePrintable)(getData(c)));
			}
			if (c != getPrev(p->cursor))
			{
				s=strcat(s,", ");
			}
			c=getNext(c);
		}
		s=strcat(s,">");
	}
	return s;
}


