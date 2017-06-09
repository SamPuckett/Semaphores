//
//  foodpass.cpp
//  foodPass
//
//  Created by Samuel Ruiz on 5/1/17.
//  Copyright © 2017 Samuel Ruiz. All rights reserved.
//

#include <iostream>
#include <sched.h>
#include <time.h>
#include <pthread.h>
#include <string>
#include "sem.h"

using namespace std ;

/* ######################################## */
/*             Global Variables             */
/* ######################################## */

const int numTrivets = 3 ;
const int numDiners = numTrivets - 1 ;
const int maxDishNames = 13 ;
const int numDishNames = 5 ;

int trivet[numTrivets] ;

string dishName[maxDishNames];






//↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
//↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
//↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
//↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
//↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓

/* Notes
 --------------------------------------------------
 
 -----Empty---------------------------------------------------------------

 1) emptySem[numTrivets] - Description: This semaphore will be greater than 0 if the trivet is empty.
                         - if Value > 0
                            ~ The corresponding trivet currently has a dish
                         - if Value = 0
                            ~ The corresponding trivet is empty
                         - Name: emptySem

 -------------------------------------------------------------------------

 -----Full----------------------------------------------------------------

 2) fullSem[numTrivets] - Description: This semaphore will signal if the trivet currently has a dish.
                        - if Value > 0
                            ~ The corresponding trivet currently has a dish
                        - if Value = 0
                            ~ The corresponding trivet is empty
                        - Name: fServerSem

 -------------------------------------------------------------------------*/



/* Code
 -------------------------------------------------- */

sim_semaphore   emptySem[numTrivets];
sim_semaphore   fullSem[numTrivets];

// --------------------------------------------------

//↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
//↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
//↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
//↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
//↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑





pthread_t child_t[numTrivets] ;

/* ######################################## */
/*      "Special"   Global Variables        */
/* ######################################## */

int checking ;

pthread_mutex_t stdoutLock ;

struct threadIdType
{
    int id ;
};

/* ################################################## */
/*                         init                       */
/* ################################################## */

void init()
{
    int index ;

    srandom(time((time_t *) 0));
    checking = 0 ;

    if ( 0!=pthread_mutex_init(&stdoutLock, NULL) )
    {  cout << "MUTEX INITIALIZATION FAILURE!" << endl;
        exit(-1) ;}

    for (index=0; index<numTrivets; index++) trivet[index]=0;
    
    
    
    
    
    
    //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
    //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
    //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
    //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
    //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
    
    /* Notes
     --------------------------------------------------
     
     // Initializes the Diner semaphores with their respectice values using a for loop
     
     -----Empty---------------------------------------------------------------

     1) emptySem - Init Value: 1
                 - Quantity: Numbers of Diners + 1

     -----Full----------------------------------------------------------------

     1) fullSem - Init Value: 0
                - Quantity: Numbers of Diners + 1

     ------------------------------------------------------------------------- */

    
    
    /* Code
     -------------------------------------------------- */

    for (index=0; index<numTrivets; index++){
        fullSem[index] = create_sim_sem(0);
    }
    for (index=0; index<numTrivets; index++){
        emptySem[index] = create_sim_sem(1);
    }

    // --------------------------------------------------

    //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
    //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
    //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
    //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
    //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑

    
    
    
    
    dishName[0]="no dish";
    dishName[1]="pepperoni pizza" ;
    dishName[2]="cheese pizza" ;
    dishName[3]="hot wings" ;
    dishName[4]="bread sticks" ;
    dishName[5]="beer" ;
    dishName[6]="buffalo sauce" ;
    dishName[7]="ranch" ;
    dishName[8]="combination pizza" ;
    dishName[9]="grilled chicken pizza" ;
    dishName[10]="meat lovers pizza" ;
    dishName[11]="canadian bacon pizza" ;
    dishName[numDishNames-1]="check" ;

}

/* ################################################## */
/*                    DelayAsMuchAs                   */
/* ################################################## */
void delayAsMuchAs (int limit)
{
    int time, step;
    time=(int)random()%limit;
    for (step=0;step<time;step++) sched_yield() ;
}

/* ################################################## */
/*                       Server                       */
/* ################################################## */

void * Server(void * ignore)
{

    int i, delayLimit=100 ;

    for (i=1; i<numDishNames; i++)
    {

        delayAsMuchAs(delayLimit);

        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------

        wait(EMPTY semaphore[first trivet])

        -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */
        
        wait_sem(emptySem[0]);

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
        trivet[0]=i; // put dish #i onto trivet #0.
        pthread_mutex_lock(&stdoutLock) ;
        cout << "Server places " << dishName[trivet[0]]
        << " on trivet #0." << endl ;
        pthread_mutex_unlock(&stdoutLock);
        
        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------
         
         signal(FULL semaphore [first trivet])

         -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */

        signal_sem(fullSem[0]);

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
    }
    pthread_exit ((void *)0) ;
}

/* ################################################## */
/*                         Diner                      */
/* ################################################## */

void * Diner(void * postnPtr)
{
    int position = ((threadIdType *) (postnPtr))->id ;
    int i, delayLimit=100 ;
    for (i=0; i<numDishNames; i++)
    {
        delayAsMuchAs(delayLimit);
        
        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------
         
         wait(FULL semaphore[trivet to the left of current diner]);

         position - 1 = trivet to the left of current diner;

         -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */

        wait_sem(fullSem[position]);
    

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
        pthread_mutex_lock(&stdoutLock) ;
        cout << "Diner number "<< position ;
        if (i<numDishNames-2) cout << " enjoys ";
        else if (position<numDiners-1) cout << " examines " ;
        else cout << " examines and pays " ;

        cout << dishName[trivet[position]] << endl ;
        pthread_mutex_unlock(&stdoutLock);

        delayAsMuchAs(delayLimit);
        
        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------
         
        wait(EMPTY semaphore[trivet to the right of current diner]);

        position = trivet to the right of current diner;

        -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */

        wait_sem(emptySem[position + 1]);

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
        pthread_mutex_lock(&stdoutLock) ;
        cout << "Diner number "<< position << " moves "
        << dishName[trivet[position]] << " from trivet #"
        << position << " to trivet #" << position+1 << endl;
        pthread_mutex_unlock(&stdoutLock);
        /* transfer the dish on my left to trivet on my right */
        trivet[position+1]=trivet[position] ;
        /* mark trivet on my left as empty */
        trivet[position]=0;
        
        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------
         
        signal(EMPTY semaphore[trivet to the left of the current diner]);

        position - 1 = trivet to the left of the current diner;

        signal(FULL semaphore[trivet to the right of the current diner]);

        position = trivet to the right of the current diner;

        -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */

        signal_sem(emptySem[position]);

        signal_sem(fullSem[position + 1]);

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
    }
    pthread_exit ((void *)0) ;
}

/* ################################################## */
/*                       Busser                       */
/* ################################################## */

void * Busser (void * ignore)
{

    int i, delayLimit=100 ;

    for (i=0; i<numDishNames; i++)
    {
        delayAsMuchAs(delayLimit);
        
        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------
         
         wait(FULL semaphore[number of trivets - 1);

         -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */
        
        if(i == numDishNames - 1){
            return (void *) 0 ;
        }

        wait_sem(fullSem[numTrivets - 1]);

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
        pthread_mutex_lock(&stdoutLock) ;
        cout << "Busser removes "
        << dishName[trivet[numTrivets-1]] << " from trivet #"
        << numTrivets-1<< "." << endl ;
        pthread_mutex_unlock(&stdoutLock);
        trivet[numTrivets-1]=0; // remove the dish.
        
        
        
        
        
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        //↓↓↓↓↓↓↓↓↓↓ MY CODE ↓↓↓↓↓↓↓↓↓↓
        
        /* Notes
         --------------------------------------------------

         signal(EMPTY semaphore[number of trivets - 1);

         -------------------------------------------------- */

        /* Code
         -------------------------------------------------- */

        signal_sem(emptySem[numTrivets - 1]);

        // --------------------------------------------------
        
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        //↑↑↑↑↑↑↑↑↑↑ MY CODE ↑↑↑↑↑↑↑↑↑↑
        
        
        
        
        
    }
    return (void *) 0 ;
}

/* ################################################## */
/*                         Main                       */
/* ################################################## */

int main()
{
    init();

    cout << endl << endl;
    cout << "Welcome to Sam's pizzeria!" << endl ;
    cout << numDiners << " will be dining." << endl ;
    cout << "The meal will consist of " << numDishNames-2
    << " dishes." << endl;
    cout << "Bon appetit!" << endl ;
    cout << endl << endl;

    int i;

    threadIdType * idPtr ;

    for (i=0; i<numDiners; i++)
    {

        idPtr = new threadIdType ;
        idPtr->id = i ;

        if (0!=pthread_create(&child_t[i], NULL, Diner, (void *) idPtr))
        {cout << "THREAD CREATION FAILURE!" << endl; exit(-1) ;}

        if (0!=pthread_detach(child_t[i]))
        {cout << "THREAD DETACHMENT FAILURE!" << endl ; exit(-1) ;}
    }

    if (0!=pthread_create(&child_t[numDiners], NULL, Server, (void *) 0))
    {cout << "THREAD CREATION FAILURE!" << endl; exit(-1) ;}

    if (0!=pthread_detach(child_t[numDiners]))
    {cout << "THREAD DETACHMENT FAILURE!" << endl ; exit(-1) ;}

    Busser((void *)0) ;

    cout << endl << endl;
    cout << "Thank you for coming!" << endl ;
    cout << endl << endl;

    return 0 ;

}
