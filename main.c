#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mytimer.h"




void time_handler1(size_t timer_id, void * user_data)
{
    printf("Single shot timer expired.(%ld)\n", timer_id);
}

void time_handler2(size_t timer_id, void * user_data)
{
    printf("100 ms timer expired. (%ld)\n", timer_id);
}

void time_handler3(size_t timer_id, void * user_data)
{
    printf("2000 ms timer expired. (%ld)\n", timer_id);
}

int main(void)
{
    size_t timer1, timer2, timer3;

    initialize();

    timer1 = start_timer(200, time_handler1, TIMER_SINGLE_SHOT, NULL);
    timer2 = start_timer(100, time_handler2, TIMER_PERIODIC, NULL);
    timer3 = start_timer(2000, time_handler3, TIMER_PERIODIC, NULL);

    sleep(1);

    stop_timer(timer1);
    stop_timer(timer2);
    stop_timer(timer3);

    finalize();
    return 0;
}