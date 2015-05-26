#include "gamebae.h"

// Cartridge Memory. The largest cart will have a max size of 0x200000
BYTE cartMemory[0x200000];

// ROM Memory. I know, the M in ROM stands for Memory rofl
BYTE romMemory[0x10000];

// Registers Definition. Each register pair represents 2 registers, lo and hi.
union Register {
    WORD reg;
    struct {
        BYTE lo;
        BYTE hi;
    };
};

// Registers
union Register registerAF;
union Register registerBC;
union Register registerDE;
union Register registerHL;

// Program Counter and Stack Pointer
WORD programCounter;
union Register stackPointer;

int main(int argc, char *argv[]) {
    /*
        Accepted Arguments:
        gamebae -rom romename.gb
        gamebae -help
        gamebae -test
        gamebae -dis romename.gb filename.txt
    */
    if (argc < 2) {
		printf("Nope! Usage is: %s -rom romname.gb\n", argv[0]);
	} else {
        // lets figure out what argument it is
        int isRom = stringMatches("-rom", argv[1]);
        int isHelp = stringMatches("-help", argv[1]);
        int isTest = stringMatches("-test", argv[1]);
        int isDis = stringMatches("-dis", argv[1]);

        if (isRom == 1)  {
            loadCartridgeWithFilename(argv[2]);
            initializeMemory();
            updateEmulator();
        } else if (isHelp == 1) {
            printf("TODO: make help page lol\n");
        } else if (isTest == 1) {
            printf("This mode will prove all opcodes are implimented.\n");
        } else if (isDis == 1) {
            printf("This mode just spits out disassembly");
        } else {
            printf("Unknown Argument\n");
        }
	}
    return 0;
}


// This should be called for every frame, so 60 times a second.
// the currentCycles < MAXCYCLES will make sure the emulator doesnt run too fast
int updateEmulator() {
    const int MAXCYCLES = 65535;
    int currentCycles = 0;

    while (currentCycles < MAXCYCLES) {
        // fetch, decode, execute
        int cycles = fetchDecodeExecute();
        currentCycles += cycles;

        // update timing
        // update graphics
        // check for interrupts
    }
    // render screen
    return 0;
}

int fetchDecodeExecute() {
    BYTE opcode = cartMemory[programCounter];
    int cycles = 0;
    switch (opcode) {
        case 0x00: { // NOP
            cycles = 4;
            printf("NOP\n");
            programCounter++;
            break;
        }
        // 8-bit loads
        // LD nn,n
        case 0x06: { // LD B,n
            cycles = 8;
            printf("LD B,n\n");
            programCounter++;
            break;
        }
        case 0x0E: { // LD C,n
            cycles = 8;
            printf("LD C,n\n");
            programCounter++;
            break;
        }
        case 0x16: { // LD D,n
            cycles = 8;
            printf("LD D,n\n");
            programCounter++;
            break;
        }
        case 0x1E: { // LD E,n
            cycles = 8;
            printf("LD E,n\n");
            programCounter++;
            break;
        }
        case 0x26: { // LD H,n
            cycles = 8;
            printf("LD H,n\n");
            programCounter++;
            break;
        }
        case 0x2E: { // LD L,n
            cycles = 8;
            printf("LD L,n\n");
            programCounter++;
            break;
        }
        default: { // Not implimented yet
            cycles = 4;
            printf("?\n");
            programCounter++;

            break;
        }
    }

    return cycles;
}


int loadCartridgeWithFilename(char *filename) {
    memset (cartMemory, 0, sizeof(cartMemory));

    FILE *fileopener;
    const char *filenameConst = filename;

    fileopener = fopen(filenameConst, "rb");
    fread(cartMemory, 1, 0x200000, fileopener);
    fclose(fileopener);

    return 0;
}

int initializeMemory() {
    programCounter = 0x100;
    stackPointer.reg = 0xFFFE;
    registerAF.reg = 0x01B0;
    registerBC.reg = 0x0013;
    registerDE.reg = 0x00D8;
    registerHL.reg = 0x014D;
    romMemory[0xFF05] = 0x00;
    romMemory[0xFF06] = 0x00;
    romMemory[0xFF07] = 0x00;
    romMemory[0xFF10] = 0x80;
    romMemory[0xFF11] = 0xBF;
    romMemory[0xFF12] = 0xF3;
    romMemory[0xFF14] = 0xBF;
    romMemory[0xFF16] = 0x3F;
    romMemory[0xFF17] = 0x00;
    romMemory[0xFF19] = 0xBF;
    romMemory[0xFF1A] = 0x7F;
    romMemory[0xFF1B] = 0xFF;
    romMemory[0xFF1C] = 0x9F;
    romMemory[0xFF1E] = 0xBF;
    romMemory[0xFF20] = 0xFF;
    romMemory[0xFF21] = 0x00;
    romMemory[0xFF22] = 0x00;
    romMemory[0xFF23] = 0xBF;
    romMemory[0xFF24] = 0x77;
    romMemory[0xFF25] = 0xF3;
    romMemory[0xFF26] = 0xF1;
    romMemory[0xFF40] = 0x91;
    romMemory[0xFF42] = 0x00;
    romMemory[0xFF43] = 0x00;
    romMemory[0xFF45] = 0x00;
    romMemory[0xFF47] = 0xFC;
    romMemory[0xFF48] = 0xFF;
    romMemory[0xFF49] = 0xFF;
    romMemory[0xFF4A] = 0x00;
    romMemory[0xFF4B] = 0x00;
    romMemory[0xFFFF] = 0x00;

    return 0;
}
