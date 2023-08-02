// KIT107 Slide 186: DNode
/*
 * Specification for the DNode ADT
 * Author Julian Dermoudy
 * Version 17/5/18
*/

#include <stdbool.h>

struct dnode_int;
typedef struct dnode_int *dnode;

void init_dnode(dnode *v, void *o);
void setData(dnode v, void *o);
void setNext(dnode v, dnode n);
void setPrev(dnode v, dnode p);
void *getData(dnode v);
dnode getNext(dnode v);
dnode getPrev(dnode v);
