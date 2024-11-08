#include <stdbool.h>
#include <stddef.h>  // for NULL (if you need it)
#include <stdint.h>

#define INT_ENABLE ((uint32_t*) 0x40000000)
#define INT_PENDING ((uint32_t*) 0x40000004)

#define MTIME_LOW ((uint32_t*) 0x40000008)
#define MTIME_HIGH ((uint32_t*) 0x4000000C)
#define MTIMECMP_LOW ((uint32_t*) 0x40000010)
#define MTIMECMP_HIGH ((uint32_t*) 0x40000014)

#define CONTROLLER ((uint32_t*) 0x40000018)
#define LEFT 0x1
#define UP 0x2
#define DOWN 0x4
#define RIGHT 0x8

#define VIDEO_MEMORY ((char*) 0x500FE800)
#define VIDEO_NUM_ROWS 36
#define VIDEO_NUM_COLS 64

void game(void)
{

    // You'll probably want to use this line at some point.
    // *INT_ENABLE = 0x4;
    


    // You'll probably want to use this line at some point.
    // *INT_ENABLE = 0x0;


}

void c_interrupt_handler(void)
{


    // You'll probably want to use this line at some point.
    // *INT_PENDING = 0x4;


}
