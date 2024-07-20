#include "cchip8.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>

/*
    Reference header file for architecture
*/
unsigned char memory[4096] = {0};

unsigned short pc = 0;
unsigned char sp = 0;

unsigned char V[16] = {0};
unsigned short I = 0;

unsigned char display[64 * 32] = {0};
unsigned char dt = 0;
unsigned char st = 0;
unsigned char draw_flag = 0;
unsigned char sound_flag = 0;

unsigned char fontset[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,  // 0
    0x20, 0x60, 0x20, 0x20, 0x70,  // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,  // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,  // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,  // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0,  // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0,  // 6
    0xF0, 0x10, 0x20, 0x40, 0x40,  // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0,  // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0,  // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90,  // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0,  // B
    0xF0, 0x80, 0x80, 0x80, 0xF0,  // C
    0xE0, 0x90, 0x90, 0x90, 0xE0,  // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0,  // E
    0xF0, 0x80, 0xF0, 0x80, 0x80   // F
};

// Function definitions

void init_cpu()
{
    // Point counter to beginning of program address range
    pc = 0x200;

    // Load font into memory 
    // Since interpreter isn't using 0x000-0x1FF, store font there
    memcpy(memory, fontset, sizeof(fontset));   
}

int load_rom(char* filename)
{


    return 0;
}

void display_memory()
{
    // Main memory
    for (int i = 0; i < 4096; i++)
    {
        // Print the address and value
        printf("0x%03X: 0x%02X\t", i, memory[i]);
        
        // Print a new line after every 16 addresses
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
}
