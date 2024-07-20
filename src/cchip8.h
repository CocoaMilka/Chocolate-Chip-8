#ifndef CCHIP8_H
#define CCHIP8_H

/*
    MEMORY MAP

    4k memory locations 
    each 8 bit
    
    0x000 - 0x1FF   Chip-8 Interpreter
    0x200 - 0xE9F   Program Space
        .
        .
        .
    0xEA0 - 0xEFF   Call Stack
    0xF00 - 0xFFF   Reserved for Display Refresh 
*/

// Memory
extern unsigned char memory[4096];

/*
    Pseudo Registers
    PC  Program Counter 16 Bits
    SP  Stack Pointer   8 Bits

    I wonder if I can use pointers instead? That would be so cool :3
*/

extern unsigned short pc;
extern unsigned char sp;

/*
    REGISTERS

    16 8-bit Registers V0 - VF
    a char is 8 bits :3

    1 16-bit Register I - Address Register
    Originally 12 bits wide but fuck that, no native 12 bit structure in C
    (I think)
    a short is 16 bits :3
*/

extern unsigned char V[16];
extern unsigned short I;

/*
    DISPLAY
    64x32 monochrome display
*/

extern unsigned char display[64 * 32];

// Extra stuffs weh

// Delay Timer
extern unsigned char dt;

// Sound Timer
extern unsigned char st;

// Update display flag
extern unsigned char draw_flag;

// Play a sound flag
extern unsigned char sound_flag;

// Font set
extern unsigned char fontset[80];

// Function declarations
void init_cpu();
int load_rom(char* filename);

#endif // CCHIP8_H