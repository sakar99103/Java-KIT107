// KIT107 Circular DNode
/*
* Implementation for DNode
* Author Julian Dermoudy
* Version 17/5/18
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dnode.h"


struct dnode_int {
	dnode prev;
	void *data;
	dnode next;
};

/*
* 'Constructor' for node
*/
void init_dnode(dnode *np,void *o)
{
	*np = (dnode)malloc(sizeof(struct dnode_int));
	(*np)->data = o;
	(*np)->next = *np;
	(*np)->prev = *np;
}

/*
* Getter for data
* Return data field
*/
void *getData(dnode n)
{
	return (n->data);
}

/*
* Getter for next
* Return next field
*/
dnode getNext(dnode n)
{
	return (n->next);
}

/*
* Getter for previous
* Return prev field
*/
dnode getPrev(dnode n)
{
	return (n->prev);
}

/*
* Setter for data
* Param o value to be placed into the node's data field
*/
void setData(dnode n,void *o)
{
	n->data = o;
}

/*
* Setter for next
* Param o value to be placed into the node's next field
*/
void setNext(dnode v, dnode n)
{
	v->next = n;
}

/*
* Setter for previous
* Param o value to be placed into the node's prev field
*/
void setPrev(dnode v, dnode n)
{
	v->prev = n;
}


