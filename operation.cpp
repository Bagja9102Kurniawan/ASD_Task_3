#include "list.h"
#include "operation.h"
#include "my_data.h"


void insertAndSort(List &L, infotype x) {
    /**
    * IS : List may be empty
    * PR : insert a new element into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID.
    *      procedure must also check if such ID is already exists (No Duplicate ID).
    *      If new data has duplicate ID, new data is rejected.
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    address Q,P;
    P = first(L);
    if (P == NULL || info(P).ID > x.ID ){
        insertFirst(L,allocate(x));
    }else if (findElm(L,x) == NULL) {
            while (P != NULL && info(P).ID < x.ID){
                Q = P;
                P = next(P);
            }
            insertAfter(L,Q,allocate(x));
    }
    //----------------------------------------
}


void deletebyID(List &L, int id_x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = id_x is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    P = first(L);
    if (P == first(L) && id_x == info(P).ID) {
        deleteFirst(L, P);
    } else {
        while (P != NULL) {
            if (id_x == info(P).ID && first(L) != last(L)) {
                Prec = prev(P);
                deleteAfter(L, Prec, P);
            }
        P = next(P);
        }
    }


    //----------------------------------------
}


void savePassedMember(List &L, List &L2){
    /**
    * IS : List L and L2 may be empty
    * FS : any element with score greater than 80 is moved to L2
    */
    address P;
    //-------------your code here-------------
    P = first(L);
    address Q = P;
    while (Q != NULL) {
        P = Q;
        if (info(P).Score > 80) {
            insertAndSort(L2, info(P));
            Q = next(Q);
            if (prev(P) == NULL) {
                deleteFirst(L, P);
            } else {
                deleteAfter(L, prev(P), P);
            }
        } else {
            Q = next(Q);
        }
    }


    //----------------------------------------
}
