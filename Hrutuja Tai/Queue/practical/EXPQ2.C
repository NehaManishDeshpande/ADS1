// An operating system assigns job to print queues based on the number of
// pages to be printed (1 to 50 pages). You may assume that the system
// printers are able to print 10 page per minute. Smaller print jobs are
// printed before larger print jobs and print jobs are processed from a
// single print queue implemented as a priority queue). The system
// administrators would like to compare the time required to process a set
// of print jobs using 1, 2, or 3 system printers. Write a program which
// simulates processing 100 print jobs of varying lengths using either 1, 2,
// or 3 printers. Assume that a print request is made every minute and that
// the number of pages to print varies from 1 to 50 pages. To be fair, you
// will need to process the same set of print jobs each time you add a
// printer.The output from your program should indicate the order in which
// the jobs were received, the order in which they were printed, and the
// time required to process the set of print jobs. If more than one printer is
// being used, indicate which printer each job was printed on.


#include <stdio.h>
