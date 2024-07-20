#include "cchip8.h"

int main()
{
    init_cpu();

    // SIMPLE DEBUG PROGRAM
    // jmp to program start address (0x200)
    memory[0x200] = 0x12;
    memory[0x201] = 0x02;

    // return from jump
    memory[0x202] = 0x00;
    memory[0x203] = 0xEE;

    // emu code :3


    while (1)
    {
        execute_cycle();

        display_memory();
    }

    return 0;
}
