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

const unsigned short START_ADDRESS = 0x200;
const unsigned short STACK_START_ADDRESS = 0xEA0;

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

void init_cpu(void)
{
    // Point counter to beginning of program address range
    pc = START_ADDRESS;

    sp = STACK_START_ADDRESS;

    // Load font into memory 
    // Since interpreter isn't using 0x000-0x1FF, store font there
    memcpy(memory, fontset, sizeof(fontset));   
}

int load_rom(char* filename)
{


    return 0;
}

/*
    TODO
    - Pretty print memory better
    - ensure SP is marked correctly
*/
void display_memory(void)
{
    // Main memory
    for (int i = 0; i < 4096; i++)
    {
        // print pointers
        if (pc == i)
        {
            // Print the address and value
            printf("0x%03X: 0x%02X<-PC\t", i, memory[i]);
        }
        else if (sp + 0xEA0 == i)  // Adjusted for stack memory offset
        {
            // Print the address and value
            printf("0x%03X: 0x%02X<-SP\t", i, memory[i]);
        }
        else
        {
            // Print the address and value
            printf("0x%03X: 0x%02X\t", i, memory[i]);
        }
        
        // Print a new line after every 16 addresses
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
}

void execute_cycle()
{
    draw_flag = 0;
    sound_flag = 0;

    // Fetch opcode (2 bytes long, must merge 2 addresses)
    unsigned short op = memory[pc] << 8 | memory[pc + 1];

    // decode
    switch (op & 0xF000)    // checks first byte of opcode
    {
        // operations that start with 0
        case 0x0000:
            switch (op & 0x00FF)
            {
                // 00E0 Clear display
                case 0x00E0:
                    printf("OK: Clearing display...");
                    for (int i = 0; i < 64 * 32; i++) { display[i] = 0; }
                    pc += 2;
                    break; 
                // 00EE Return from subroutine
                case 0x00EE:
                    sp--;                    // Decrement stack pointer
                    pc = memory[sp] << 8;    // Retrieve the higher byte of the address
                    pc |= memory[sp + 1];    // Retrieve the lower byte of the address
                    pc += 2;                 // Increment PC by 2 to proceed to the next instruction
                    break;
                default:
                    printf("ERROR: Unknown opcode 0x%X\n", op);
                    break;
            }
        break;

        case 0x1000:
            // jump to address NNN (last 3 bytes)
            pc = op & 0x0FFF;
            break;
    }

    // execute

    // update
}
