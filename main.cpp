//
//  main.cpp
//  340Project2
//
//  Created by James on 3/9/20.
//  Copyright © 2020 James. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* runner(void* param);
void* runner2(void* param);
/* Declare the array that we will randomly assign numbers to as global */
int randnums[10000];
/* The first 100 minimum numbers from the 20 threads each of the initial 5 threads creates */
int first100[100];
/* The minimum returned from each of the 20 threads to the main 5 threads */
int min5[5];
/* The lowest number from the 5 threads */
int globalMin = 0;
int main(int argc, const char * argv[]) {
     /* Random array integer set up */
    time_t t;
    //int n = 10000;
    /* Initialize the min and max values, can get the min and max while generating
     integers, so you don't have to run through another for loop again. */
    int min = 0, max = 0;
    //int randnums[n];
    /* Prep step to set up and seed random number generator */
    srand((unsigned)time(&t));
    /* Generate the random numbers */
    for (int i = 0; i < 10000; i++){
        randnums[i] = rand();
        if (min == 0) {
            /* Since min is initialized to 0 it will never find a smaller number,
             so assign its first value to be a number in the set, that way if its the
             smallest value that's fine, and if it's not there's a comparison it can make
             to swap. */
            min = randnums[i];
        }
        if (randnums[i] > max) {
            max = randnums[i];
        }
        else if (randnums[i] < min) {
            min = randnums[i];
        }
    }
    std::cout << "The min is : " << min << std::endl
              << "The max is : " << max << std::endl;
    /* Threading Part */
    /* Need the main thread to create 5 threads, each of those 5 threads will create
     20 threads
     Thread 1-5 will be assigned array index
     1 : 0-1999, 2 : 2000-3999, 3 : 4000-5999, 4 : 6000-7999, 5 : 8000-9999.
     Each of those threads will create 20 threads that will handle 100 numbers each
     and return the minimum to the original 5, and then those original 5 will return
     the minimum to the main program. */
    int thd1 = 0, thd2 = 2000, thd3 = 4000, thd4 = 6000, thd5 = 8000;
    pthread_t tid1, tid2, tid3, tid4, tid5;
    pthread_attr_t attr1, attr2, attr3, attr4, attr5;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);
    pthread_attr_init(&attr4);
    pthread_attr_init(&attr5);
    pthread_create(&tid1, &attr1, runner, (void *) &thd1);
    pthread_create(&tid2, &attr2, runner, (void *) &thd2);
    pthread_create(&tid3, &attr3, runner, (void *) &thd3);
    pthread_create(&tid4, &attr4, runner, (void *) &thd4);
    pthread_create(&tid5, &attr5, runner, (void *) &thd5);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);
    
    std::cout << "Testing the 100 values array." << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout<< "Index " << i << " has a value of " << first100[i] << std::endl;
    }
    std::cout << "Testing the 5 values array." << std::endl;
    globalMin = min5[0];
    for (int i = 0; i < 5; i++) {
        if (globalMin > min5[i]) {
            globalMin = min5[i];
        }
        std::cout<< "Index " << i << " has a value of " << min5[i] << std::endl;
    }
    std::cout << "The lowest number from the initial 5 threads is : " << globalMin << std::endl;

    return 0;
}
void* runner(void* param) {
    int lowerNum = *((int *) param);
    int numArr[20];
    /* We have the original lowest number we need to operate on, so assign that to the index. */
    numArr[0] = lowerNum;
    /* Now assign each array index up to 20 the range of numbers its gonna be in by 200, that way
     we can operate / check on that range of values from the X00 - X99 range. */
    for (int i = 0; i < 20; i++) {
        if ( i != 0 ) {
        lowerNum += 100;
        numArr[i] = lowerNum;
        }
        else {
            numArr[0] = lowerNum;
        }
    }
    /* Create the 20 threads, and pass in the integer value from numArr so that we can read it in as a param through the runner2 function, and use that parameter to instruct which numbers to make the thread run upon */
     pthread_t tid1, tid2, tid3, tid4, tid5, tid6, tid7, tid8, tid9, tid10, tid11, tid12, tid13, tid14, tid15, tid16, tid17,tid18, tid19, tid20;
     pthread_attr_t attr1, attr2, attr3, attr4, attr5, attr6, attr7, attr8, attr9, attr10, attr11, attr12, attr13, attr14, attr15, attr16, attr17, attr18, attr19, attr20;
     pthread_attr_init(&attr1);
     pthread_attr_init(&attr2);
     pthread_attr_init(&attr3);
     pthread_attr_init(&attr4);
     pthread_attr_init(&attr5);
     pthread_attr_init(&attr6);
     pthread_attr_init(&attr7);
     pthread_attr_init(&attr8);
     pthread_attr_init(&attr9);
     pthread_attr_init(&attr10);
     pthread_attr_init(&attr11);
     pthread_attr_init(&attr12);
     pthread_attr_init(&attr13);
     pthread_attr_init(&attr14);
     pthread_attr_init(&attr15);
     pthread_attr_init(&attr16);
     pthread_attr_init(&attr17);
     pthread_attr_init(&attr18);
     pthread_attr_init(&attr19);
     pthread_attr_init(&attr20);
     pthread_create(&tid1, &attr1, runner2, (void *) &numArr[0]);
     pthread_create(&tid2, &attr2, runner2, (void *) &numArr[1]);
     pthread_create(&tid3, &attr3, runner2, (void *) &numArr[2]);
     pthread_create(&tid4, &attr4, runner2, (void *) &numArr[3]);
     pthread_create(&tid5, &attr5, runner2, (void *) &numArr[4]);
     pthread_create(&tid6, &attr6, runner2, (void *) &numArr[5]);
     pthread_create(&tid7, &attr7, runner2, (void *) &numArr[6]);
     pthread_create(&tid8, &attr8, runner2, (void *) &numArr[7]);
     pthread_create(&tid9, &attr9, runner2, (void *) &numArr[8]);
     pthread_create(&tid10, &attr10, runner2, (void *) &numArr[9]);
     pthread_create(&tid11, &attr11, runner2, (void *) &numArr[10]);
     pthread_create(&tid12, &attr12, runner2, (void *) &numArr[11]);
     pthread_create(&tid13, &attr13, runner2, (void *) &numArr[12]);
     pthread_create(&tid14, &attr14, runner2, (void *) &numArr[13]);
     pthread_create(&tid15, &attr15, runner2, (void *) &numArr[14]);
     pthread_create(&tid16, &attr16, runner2, (void *) &numArr[15]);
     pthread_create(&tid17, &attr17, runner2, (void *) &numArr[16]);
     pthread_create(&tid18, &attr18, runner2, (void *) &numArr[17]);
     pthread_create(&tid19, &attr19, runner2, (void *) &numArr[18]);
     pthread_create(&tid20, &attr20, runner2, (void *) &numArr[19]);
     pthread_join(tid1, NULL);
     pthread_join(tid2, NULL);
     pthread_join(tid3, NULL);
     pthread_join(tid4, NULL);
     pthread_join(tid5, NULL);
     pthread_join(tid6, NULL);
     pthread_join(tid7, NULL);
     pthread_join(tid8, NULL);
     pthread_join(tid9, NULL);
     pthread_join(tid10, NULL);
     pthread_join(tid11, NULL);
     pthread_join(tid12, NULL);
     pthread_join(tid13, NULL);
     pthread_join(tid14, NULL);
     pthread_join(tid15, NULL);
     pthread_join(tid16, NULL);
     pthread_join(tid17, NULL);
     pthread_join(tid18, NULL);
     pthread_join(tid19, NULL);
     pthread_join(tid20, NULL);
    /* The parameter passed in will be assigned to the lower range variable, that way we have a location
     to start form, and the upper range +19 so that is exactly 20 numbers, from index 0 to 20.
     Then we divide that number by 100, the reason why is because every param passed in is a multiple of
     100, so 0 / 100 = 0, and 2000, 4000, 6000 and 8000 / 100 puts he numbers in the sub 100 range in their target range, 0 -> 0-19, 2000 -> 20-39, 4000 -> 40-59, 6000 -> 60-79, 8000 -> 80-99 */
    int lowerRange = *((int *) param) / 100;
    int upperRange = lowerRange + 19;
    /* This is the minimum that this thread will return, we will assign the first number in this threads
     range as the minimum, that way we have something to check against the other numbers.. */
    int thdMin = first100[lowerRange];
    for (int i = lowerRange; i < upperRange; i++) {
        if (thdMin > first100[i]) {
                   thdMin = first100[i];
               }
      }
    /* To get the indices we need, we divide the passed in parameter. We divide it by 2000, because 0, 2000, 4000, 6000, 8000 when divided by 2000 are indices 0-4 */
    min5[*((int *) param) / 2000] = thdMin;
    pthread_exit(0);
    
}
void* runner2(void* param) {
    /* The parameter passed in will be assigned to the lower range variable, that way we have a location
     to start form, and the upper range +99 so that is exactly 100 numbers, from index 0 to 99*/
    int lowerRange = *((int *) param);
    int upperRange = lowerRange + 99;
    /* This is the minimum that this thread will return, we will assign the first number in this threads
     range as the minimum, that way we have something to check against the other numbers.. */
    int thdMin = randnums[lowerRange];
    //std:: cout << "The lower range is : " << lowerRange << std::endl;
    for (int i = lowerRange; i < upperRange; i++) {
        if(randnums[i] < thdMin) {
            thdMin = randnums[i];
        }
    }
    /* I had a hard time figuring out how to get the number back from this thread, so I thought of a type of formula, to store it into a global array. Since there's only going to be 100 spots in the array, if you divide each number by 100, you'll get an index from 0-100. For example : 5000 / 100 = 50, index 50. Each will be unique, and the array should be completely filled. */
    int arrIndex = *((int*) param) / 100;
    first100[arrIndex] = thdMin;
    pthread_exit(0);
}
