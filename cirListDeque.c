#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
    TYPE value;/* value of the link */
    struct DLink * next;/* pointer to the next link */
    struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
    int size;/* number of links in the deque */
    struct DLink *Sentinel;    /* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
 Deque Functions
 ************************************************************************ */

/*
 create a new circular list deque
 
 pre:    none
 post:    returns pointer to allocated deque q, q->Sentinel is allocated and q->size equals zero
 
 */

struct cirListDeque *createCirListDeque()
{
    struct cirListDeque *q =  malloc(sizeof(struct cirListDeque));
    assert(q != 0);
    q->size = 0;
    q->Sentinel = (struct DLink *) malloc(sizeof(struct DLink));
    
    assert(q->Sentinel != 0);

    q->Sentinel->next = q->Sentinel;
    q->Sentinel->prev = q->Sentinel;
    return(q);
    /* FIXME: you must write this */
}


/* Create a link for a value.
 
 param:     val        the value to create a link for
 pre:    none
 post:    a link to store the value
 */

struct DLink * _createLink (TYPE val)
{
    /* FIXME: you must write this */
    struct DLink* tempLink = (struct DLink *) malloc(sizeof(struct DLink));
    assert(tempLink != 0);
    tempLink->value = val;
    /*temporary return value..you may need to change it*/
    return(tempLink);
    
}

//struct DLink * _createLink (TYPE val)
    /* FIXME: you must write this */
     //struct Dlink *temp = (struct Dlink*)malloc(sizeof(struct DLink));
    //assert(temp != 0);
    //temp->value = val;
    /*temporary return value..you may need to change it*/
    //return(temp);
    

/* Adds a link after another link
 
 param:     q        pointer to the deque
 param:     lnk        pointer to the existing link in the deque
 param:     v        value of the new link to be added after the existing link
 pre:    q is not null
 pre:     lnk is not null
 pre:    lnk is in the deque
 post:    the new link is added into the deque after the existing link
 */
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
    assert(q != 0);
    assert(lnk != 0);
    //Verify that lnk is in the deque
    assert(lnk->next != 0);
    assert(lnk->prev != 0);
    //Create a newLink
    struct DLink* tempLink = _createLink(v);
    //Add a new link with value v after lnk
    lnk->next->prev = tempLink;
    tempLink->next = lnk->next;
    lnk->next = tempLink;
    tempLink->prev = lnk;
    //Increment q->size
    q->size++;

    /* FIXME: you must write this */
    
}

/* Adds a link to the back of the deque
 
 param:     q        pointer to the deque
 param:     val        value for the link to be added
 pre:    q is not null
 post:    a link storing val is added to the back of the deque
 */
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
    assert(q != 0);
    _addLinkAfter(q, q->Sentinel->prev, val);
        
    }
    
    
    
    /* FIXME: you must write this */
    


/* Adds a link to the front of the deque
 
 param:     q        pointer to the deque
 param:     val        value for the link to be added
 pre:    q is not null
 post:    a link storing val is added to the front of the deque
 */
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
    assert(q != 0);
    _addLinkAfter(q, q->Sentinel, val);
    /* FIXME: you must write this */
}

/* Get the value of the front of the deque
 
 param:     q        pointer to the deque
 pre:    q is not null and q is not empty
 post:    none
 ret:     value of the front of the deque
 */
TYPE frontCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(q->size != 0);
    /*temporary return value..you may need to change it*/
    return(q->Sentinel->next->value);
    return(1);
}

/* Get the value of the back of the deque
 
 param:     q        pointer to the deque
 pre:    q is not null and q is not empty
 post:    none
 ret:     value of the back of the deque
 */
TYPE backCirListDeque(struct cirListDeque *q)
{
    
    assert(q != 0);
    assert(q->size != 0);
    /* FIXME: you must write this */
    /*temporary return value..you may need to change it*/
    return(q->Sentinel->prev->value);
    
}

/* Remove a link from the deque
 
 param:     q        pointer to the deque
 param:     lnk        pointer to the link to be removed
 pre:    q is not null and q is not empty
 post:    the link is removed from the deque
 */
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
    /* FIXME: you must write this */
    assert(q != 0);
    assert(q->size != 0);
    assert(lnk != 0);
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    free(lnk);
    //Decrement q->size;
    q->size--;
    
}

/* Remove the front of the deque
 
 param:     q        pointer to the deque
 pre:    q is not null and q is not empty
 post:    the front is removed from the deque
 */
void removeFrontCirListDeque (struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != 0);
    assert(q->size != 0);
    _removeLink(q, q->Sentinel->next);

}


/* Remove the back of the deque
 
 param:     q        pointer to the deque
 pre:    q is not null and q is not empty
 post:    the back is removed from the deque
 */
void removeBackCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(q->size != 0);
    _removeLink(q, q->Sentinel->prev);
    /* FIXME: you must write this */
}

/* De-allocate all links of the deque, and the deque itself
 
 param:     q        pointer to the deque
 pre:    none
 post:    All links (including Sentinel) are de-allocated
 */
void freeCirListDeque(struct cirListDeque *q)
{
    struct DLink* tempLink = q->Sentinel->next;
    //Free every front link until size is 0
    while(q->size != 0){
        printf("Deleting link with value of %g...\n", frontCirListDeque(q));
        removeFrontCirListDeque(q);
    }
    //Free Sentinel
    free(q->Sentinel);
    //Make Sentinel = 0 for good measure
    q->Sentinel = 0;
    /* FIXME: you must write this */
    
}

/* Check whether the deque is empty
 
 param:     q        pointer to the deque
 pre:    q is not null
 ret:     1 if the deque is empty. Otherwise, 0.
 */
int isEmptyCirListDeque(struct cirListDeque *q) {
    
    /* FIXME: you must write this */
    assert(q != 0);
    /*temporary return value..you may need to change it*/
    if(q->size == 0){
        return(1);
    }
    return(0);
    /* FIXME: you must write this */
    /*temporary return value..you may need to change it*/
    
}

/* Print the links in the deque from front to back
 
 param:     q        pointer to the deque
 pre:    q is not null and q is not empty
 post:     the links in the deque are printed from front to back
 */
void printCirListDeque(struct cirListDeque *q)
{
    printf("Size of deque is: %d\n", q->size);
    assert(q != 0);
    assert(q->size != 0);
    struct DLink* index = q->Sentinel->next;
    while(index != q->Sentinel){
        printf("%g\n", index->value);
        index = index->next;
    }
    
    /* FIXME: you must write this */
    
}

