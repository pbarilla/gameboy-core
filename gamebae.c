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
        // LD r1, r2 (page 66)
        // "hahaha fuck you" - GB Spec Writers
        case 0x7F: { // LD A,A
            cycles = 4;
            printf("LD A,A\n");
            programCounter++;
            break;
        }
        case 0x78: { // LD A,B
            cycles = 4;
            printf("LD A,B\n");
            programCounter++;
            break;
        }
        case 0x79: { // LD A,C
            cycles = 4;
            printf("LD A,C\n");
            programCounter++;
            break;
        }
        case 0x7A: { // LD A,D
            cycles = 4;
            printf("LD A,D\n");
            programCounter++;
            break;
        }
        case 0x7B: { // LD A,E
            cycles = 4;
            printf("LD A,E\n");
            programCounter++;
            break;
        }
        case 0x7C: { // LD A,H
            cycles = 4;
            printf("LD A,H\n");
            programCounter++;
            break;
        }
        case 0x7D: { // LD A,L
            cycles = 4;
            printf("LD A,L\n");
            programCounter++;
            break;
        }
        case 0x7E: { // LD A,(HL)
            cycles = 8;
            printf("LD A,(HL)\n");
            programCounter++;
            break;
        }
        case 0x40: { // LD B,B
            cycles = 4;
            printf("LD B,B\n");
            programCounter++;
            break;
        }
        case 0x41: { // LD B,C
            cycles = 4;
            printf("LD B,C\n");
            programCounter++;
            break;
        }
        case 0x42: { // LD B,D
            cycles = 4;
            printf("LD B,D\n");
            programCounter++;
            break;
        }
        case 0x43: { // LD B,E
            cycles = 4;
            printf("LD B,E\n");
            programCounter++;
            break;
        }
        case 0x44: { // LD B,H
            cycles = 4;
            printf("LD B,H\n");
            programCounter++;
            break;
        }
        case 0x45: { // LD B,L
            cycles = 4;
            printf("LD B,L\n");
            programCounter++;
            break;
        }
        case 0x46: { // LD B,(HL)
            cycles = 8;
            printf("LD B,(HL)\n");
            programCounter++;
            break;
        }

        case 0x48: { // LD C,B
            cycles = 4;
            printf("LD C,B\n");
            programCounter++;
            break;
        }
        case 0x49: { // LD C,C
            cycles = 4;
            printf("LD C,C\n");
            programCounter++;
            break;
        }
        case 0x4A: { // LD C,D
            cycles = 4;
            printf("LD C,D\n");
            programCounter++;
            break;
        }
        case 0x4B: { // LD C,E
            cycles = 4;
            printf("LD C,E\n");
            programCounter++;
            break;
        }
        case 0x4C: { // LD C,H
            cycles = 4;
            printf("LD C,H\n");
            programCounter++;
            break;
        }
        case 0x4D: { // LD C,L
            cycles = 4;
            printf("LD C,L\n");
            programCounter++;
            break;
        }
        case 0x4E: { // LD C,(HL)
            cycles = 8;
            printf("LD C,(HL)\n");
            programCounter++;
            break;
        }

        case 0x50: { // LD D,B
            cycles = 4;
            printf("LD D,B\n");
            programCounter++;
            break;
        }
        case 0x51: { // LD D,C
            cycles = 4;
            printf("LD D,C\n");
            programCounter++;
            break;
        }
        case 0x52: { // LD D,D
            cycles = 4;
            printf("LD D,D\n");
            programCounter++;
            break;
        }
        case 0x53: { // LD D,E
            cycles = 4;
            printf("LD D,E\n");
            programCounter++;
            break;
        }
        case 0x54: { // LD D,H
            cycles = 4;
            printf("LD D,H\n");
            programCounter++;
            break;
        }
        case 0x55: { // LD D,L
            cycles = 4;
            printf("LD D,L\n");
            programCounter++;
            break;
        }
        case 0x56: { // LD D,(HL)
            cycles = 8;
            printf("LD D,(HL)\n");
            programCounter++;
            break;
        }

        case 0x58: { // LD E,B
            cycles = 4;
            printf("LD E,B\n");
            programCounter++;
            break;
        }
        case 0x59: { // LD E,C
            cycles = 4;
            printf("LD E,C\n");
            programCounter++;
            break;
        }
        case 0x5A: { // LD E,D
            cycles = 4;
            printf("LD E,D\n");
            programCounter++;
            break;
        }
        case 0x5B: { // LD E,E
            cycles = 4;
            printf("LD E,E\n");
            programCounter++;
            break;
        }
        case 0x5C: { // LD E,H
            cycles = 4;
            printf("LD E,H\n");
            programCounter++;
            break;
        }
        case 0x5D: { // LD E,L
            cycles = 4;
            printf("LD E,L\n");
            programCounter++;
            break;
        }
        case 0x5E: { // LD E,(HL)
            cycles = 8;
            printf("LD E,(HL)\n");
            programCounter++;
            break;
        }

        case 0x60: { // LD H,B
            cycles = 4;
            printf("LD H,B\n");
            programCounter++;
            break;
        }
        case 0x61: { // LD H,C
            cycles = 4;
            printf("LD H,C\n");
            programCounter++;
            break;
        }
        case 0x62: { // LD H,D
            cycles = 4;
            printf("LD H,D\n");
            programCounter++;
            break;
        }
        case 0x63: { // LD H,E
            cycles = 4;
            printf("LD H,E\n");
            programCounter++;
            break;
        }
        case 0x64: { // LD H,H
            cycles = 4;
            printf("LD H,H\n");
            programCounter++;
            break;
        }
        case 0x65: { // LD H,L
            cycles = 4;
            printf("LD H,L\n");
            programCounter++;
            break;
        }
        case 0x66: { // LD H,(HL)
            cycles = 8;
            printf("LD H,(HL)\n");
            programCounter++;
            break;
        }

        case 0x68: { // LD L,B
            cycles = 4;
            printf("LD L,B\n");
            programCounter++;
            break;
        }
        case 0x69: { // LD L,C
            cycles = 4;
            printf("LD L,C\n");
            programCounter++;
            break;
        }
        case 0x6A: { // LD L,D
            cycles = 4;
            printf("LD L,D\n");
            programCounter++;
            break;
        }
        case 0x6B: { // LD L,E
            cycles = 4;
            printf("LD L,E\n");
            programCounter++;
            break;
        }
        case 0x6C: { // LD L,H
            cycles = 4;
            printf("LD L,H\n");
            programCounter++;
            break;
        }
        case 0x6D: { // LD L,L
            cycles = 4;
            printf("LD L,L\n");
            programCounter++;
            break;
        }
        case 0x6E: { // LD L,(HL)
            cycles = 8;
            printf("LD L,(HL)\n");
            programCounter++;
            break;
        }

        case 0x70: { // LD (HL),B
            cycles = 4;
            printf("LD (HL),B\n");
            programCounter++;
            break;
        }
        case 0x71: { // LD (HL),C
            cycles = 4;
            printf("LD (HL),C\n");
            programCounter++;
            break;
        }
        case 0x72: { // LD (HL),D
            cycles = 4;
            printf("LD (HL),D\n");
            programCounter++;
            break;
        }
        case 0x73: { // LD (HL),E
            cycles = 4;
            printf("LD (HL),E\n");
            programCounter++;
            break;
        }
        case 0x74: { // LD (HL),H
            cycles = 4;
            printf("LD (HL),H\n");
            programCounter++;
            break;
        }
        case 0x75: { // LD (HL),L
            cycles = 4;
            printf("LD (HL),L\n");
            programCounter++;
            break;
        }
        case 0x36: { // LD (HL),n
            cycles = 12;
            printf("LD (HL),n\n");
            programCounter++;
            break;
        }
        // 0A, 1A, FA, 3E
        // LD A, n
        case 0x0A: { // LD A,(BC)
            cycles = 8;
            printf("LD A,(BC)\n");
            programCounter++;
            break;
        }
        case 0x1A: { // LD A,(DE)
            cycles = 8;
            printf("LD A,(DE)\n");
            programCounter++;
            break;
        }
        case 0xFA: { // LD A,(nn) //nn = two byte immediate (LS byte first)
            cycles = 16;
            printf("LD A,(nn)\n");
            programCounter++;
            break;
        }
        case 0x3E: { // LD A,#
            cycles = 8;
            printf("LD A,#\n");
            programCounter++;
            break;
        }
        // up to LD n,A page 69
        case 0x47: { // LD B,A
            cycles = 4;
            printf("LD B,A\n");
            programCounter++;
            break;
        }
        case 0x4F: { // LD C,A
            cycles = 4;
            printf("LD C,A\n");
            programCounter++;
            break;
        }
        case 0x57: { // LD D,A
            cycles = 4;
            printf("LD D,A\n");
            programCounter++;
            break;
        }
        case 0x5F: { // LD E,A
            cycles = 4;
            printf("LD E,A\n");
            programCounter++;
            break;
        }
        case 0x67: { // LD H,A
            cycles = 4;
            printf("LD H,A\n");
            programCounter++;
            break;
        }
        case 0x6F: { // LD H,A
            cycles = 4;
            printf("LD L,A\n");
            programCounter++;
            break;
        }
        case 0x02: { // LD (BC),A
            cycles = 8;
            printf("LD (BC),A\n");
            programCounter++;
            break;
        }
        case 0x12: { // LD (DE),A
            cycles = 8;
            printf("LD (DE),A\n");
            programCounter++;
            break;
        }
        case 0x77: { // LD (HL),A
            cycles = 8;
            printf("LD (HL),A\n");
            programCounter++;
            break;
        }
        case 0xEA: { // LD (nn),A
            cycles = 16;
            printf("LD (nn),A\n");
            programCounter++;
            break;
        }
        // LD A, (C)
        // put value at address $FF00 + register C into A
        // same as : LD A, ($FF00+C)
        case 0xF2: { // LD A, ($FF00+C)
            cycles = 8;
            printf("LD A, ($FF00+C)\n");
            programCounter++;
            break;
        }
        // LD (C), A
        // Put A into address $FF00 + register C
        // (like the opposite of LD A, (C))
        case 0xE2: { // LD ($FF00+C), A
            cycles = 8;
            printf("LD ($FF00+C), A\n");
            programCounter++;
            break;
        }
        // LD A, (HLD)
        // LD A, (HL-)
        // LDD A, (HL)
        // put value at address HL into A. Decrement HL
        // those 3 instructions are identical
        case 0x3A: {
            cycles = 8;
            printf("LDD A, (HL)\n");
            programCounter++;
            break;
        }
        // LD (HLD), A
        // LD (HL-), A
        // LDD (HL), A
        // put A into memory address HL. Decrement HL.
        // those 3 are identical
        case 0x32: {
            cycles = 8;
            printf("LDD (HL), A\n");
            programCounter++;
            break;
        }
        // LD A, (HLI)
        // LD A, (HL+)
        // LDI A, (HL)
        // Put value at address HL into A. Increment HL.
        // all the same
        case 0x2A: {
            cycles = 8;
            printf("LDI A, (HL)\n");
            programCounter++;
            break;
        }
        // LD (HLI), A
        // LD (HL+), A
        // LDI (HL), A
        // Put A into memory address HL. Increment HL.
        case 0x22: {
            cycles = 8;
            printf("LDI (HLI), A\n");
            programCounter++;
            break;
        }
        // LDH (n), A
        // Put A into memory address $FF00+n
        // n = one byte immediate value
        case 0xE0: {
            cycles = 12;
            printf("LD ($FF00+n), A\n");
            programCounter++;
            break;
        }
        // LDH A, (n)
        // put memory address $FF00 into A
        // n = one byte immediate value
        case 0xF0: {
            cycles = 12;
            printf("LD A, ($FF00+n)\n");
            programCounter++;
            break;
        }

        // 16 bit loads

        // LD n, nn
        // put value nn into n
        // n = BC, DE, HL, SP
        // nn = 16 bit immediate value

        case 0x01: {
            cycles = 12;
            printf("LD BC, nn\n");
            programCounter++;
            break;
        }
        case 0x11: {
            cycles = 12;
            printf("LD DE, nn\n");
            programCounter++;
            break;
        }
        case 0x21: {
            cycles = 12;
            printf("LD HL, nn\n");
            programCounter++;
            break;
        }
        case 0x31: {
            cycles = 12;
            printf("LD SP, nn\n");
            programCounter++;
            break;
        }

        // LD SP, HL
        // put HL into SP
        case 0xF9: {
            cycles = 8;
            printf("LD SP, HL\n");
            programCounter++;
            break;
        }

        // LD HL, SP+n
        // LDHL SP,n
        // put SP + n effective address into HL
        // n = one byte SIGNED immediate value
        // flags affected
        // Z - RESET
        // N - RESET
        // H - set or reset based on result
        // C - set or reset based on result
        case 0xF8: {
            cycles = 12;
            printf("LDHL SP, n\n");
            programCounter++;
            break;
        }

        // LD (nn), SP
        // put SP at address nn
        // nn = two byte immediate value
        case 0x08: {
            cycles = 20;
            printf("LD (nn), SP\n");
            programCounter++;
            break;
        }

        // PUSH nn
        // push register pair nn onto stack
        // decrement SP twice
        // nn = AF, BC, DE, HL
        case 0xF5: {
            cycles = 16;
            printf("PUSH AF\n");
            programCounter++;
            break;
        }
        case 0xC5: {
            cycles = 16;
            printf("PUSH BC\n");
            programCounter++;
            break;
        }
        case 0xD5: {
            cycles = 16;
            printf("PUSH DE\n");
            programCounter++;
            break;
        }
        case 0xE5: {
            cycles = 16;
            printf("PUSH HL\n");
            programCounter++;
            break;
        }

        // POP nn
        // pop two bytes off the satck into register pair nn
        // increment SP twice

        case 0xF1: {
            cycles = 12;
            printf("POP AF\n");
            programCounter++;
            break;
        }
        case 0xC1: {
            cycles = 12;
            printf("POP BC\n");
            programCounter++;
            break;
        }
        case 0xD1: {
            cycles = 12;
            printf("POP DE\n");
            programCounter++;
            break;
        }
        case 0xE1: {
            cycles = 12;
            printf("POP HL\n");
            programCounter++;
            break;
        }

        // 8 bit ALU
        // ADD A, n
        // add n to A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N - reset
        // H - set if carry from bit 3
        // C - set if carry from bit 7
        case 0x87: {
            cycles = 4;
            printf("ADD A,A\n");
            programCounter++;
            break;
        }
        case 0x80: {
            cycles = 4;
            printf("ADD A,B\n");
            programCounter++;
            break;
        }
        case 0x81: {
            cycles = 4;
            printf("ADD A,C\n");
            programCounter++;
            break;
        }
        case 0x82: {
            cycles = 4;
            printf("ADD A,D\n");
            programCounter++;
            break;
        }
        case 0x83: {
            cycles = 4;
            printf("ADD A,E\n");
            programCounter++;
            break;
        }
        case 0x84: {
            cycles = 4;
            printf("ADD A,H\n");
            programCounter++;
            break;
        }
        case 0x85: {
            cycles = 4;
            printf("ADD A,L\n");
            programCounter++;
            break;
        }
        case 0x86: {
            cycles = 8;
            printf("ADD A,(HL)\n");
            programCounter++;
            break;
        }
        case 0xC6: {
            cycles = 8;
            printf("ADD A,#\n");
            programCounter++;
            break;
        }
        // ADC A,n
        // add n + carry flag to A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N - reset
        // H - set if carry from bit 3
        // C - set if carry from bit 7
        case 0x8F: {
            cycles = 4;
            printf("ADC A,A\n");
            programCounter++;
            break;
        }
        case 0x88: {
            cycles = 4;
            printf("ADC A,B\n");
            programCounter++;
            break;
        }
        case 0x89: {
            cycles = 4;
            printf("ADC A,C\n");
            programCounter++;
            break;
        }
        case 0x8A: {
            cycles = 4;
            printf("ADC A,D\n");
            programCounter++;
            break;
        }
        case 0x8B: {
            cycles = 4;
            printf("ADC A,E\n");
            programCounter++;
            break;
        }
        case 0x8C: {
            cycles = 4;
            printf("ADC A,H\n");
            programCounter++;
            break;
        }
        case 0x8D: {
            cycles = 4;
            printf("ADC A,L\n");
            programCounter++;
            break;
        }
        case 0x8E: {
            cycles = 8;
            printf("ADC A,(HL)\n");
            programCounter++;
            break;
        }
        case 0xCE: {
            cycles = 8;
            printf("ADC A,#\n");
            programCounter++;
            break;
        }

        // SUB n
        // subtract n from A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N - set
        // H - set if no borrow from bit 4
        // C - set if no borrow
        case 0x97: {
            cycles = 4;
            printf("SUB A\n");
            programCounter++;
            break;
        }
        case 0x90: {
            cycles = 4;
            printf("SUB B\n");
            programCounter++;
            break;
        }
        case 0x91: {
            cycles = 4;
            printf("SUB C\n");
            programCounter++;
            break;
        }
        case 0x92: {
            cycles = 4;
            printf("SUB D\n");
            programCounter++;
            break;
        }
        case 0x93: {
            cycles = 4;
            printf("SUB E\n");
            programCounter++;
            break;
        }
        case 0x94: {
            cycles = 4;
            printf("SUB H\n");
            programCounter++;
            break;
        }
        case 0x95: {
            cycles = 4;
            printf("SUB L\n");
            programCounter++;
            break;
        }
        case 0x96: {
            cycles = 8;
            printf("SUB (HL)\n");
            programCounter++;
            break;
        }
        case 0xD6: {
            cycles = 8;
            printf("SUB #\n");
            programCounter++;
            break;
        }
        // SBC A,n
        // subtract n + carry flag from A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N - set
        // H - set if no borrow from bit 4
        // C - set if no borrow
        case 0x9F: {
            cycles = 4;
            printf("SBC A,A\n");
            programCounter++;
            break;
        }
        case 0x98: {
            cycles = 4;
            printf("SBC A,B\n");
            programCounter++;
            break;
        }
        case 0x99: {
            cycles = 4;
            printf("SBC A,C\n");
            programCounter++;
            break;
        }
        case 0x9A: {
            cycles = 4;
            printf("SBC A,D\n");
            programCounter++;
            break;
        }
        case 0x9B: {
            cycles = 4;
            printf("SBC A,E\n");
            programCounter++;
            break;
        }
        case 0x9C: {
            cycles = 4;
            printf("SBC A,H\n");
            programCounter++;
            break;
        }
        case 0x9D: {
            cycles = 4;
            printf("SBC A,L\n");
            programCounter++;
            break;
        }
        case 0x9E: {
            cycles = 8;
            printf("SBC A,(HL)\n");
            programCounter++;
            break;
        }
        // MYSTERY! the op code is unknown lol
        // case 0x??: {
        //     cycles = ??;
        //     printf("SBC A,#\n");
        //     programCounter++;
        //     break;
        // }

        // AND n
        // Logically AND n with A, result in A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N - reset
        // H - set
        // C - reset
        case 0xA7: {
            cycles = 4;
            printf("AND A\n");
            programCounter++;
            break;
        }
        case 0xA0: {
            cycles = 4;
            printf("AND B\n");
            programCounter++;
            break;
        }
        case 0xA1: {
            cycles = 4;
            printf("AND C\n");
            programCounter++;
            break;
        }
        case 0xA2: {
            cycles = 4;
            printf("AND D\n");
            programCounter++;
            break;
        }
        case 0xA3: {
            cycles = 4;
            printf("AND E\n");
            programCounter++;
            break;
        }
        case 0xA4: {
            cycles = 4;
            printf("AND H\n");
            programCounter++;
            break;
        }
        case 0xA5: {
            cycles = 4;
            printf("AND L\n");
            programCounter++;
            break;
        }
        case 0xA6: {
            cycles = 8;
            printf("AND (HL)\n");
            programCounter++;
            break;
        }
        case 0xE6: {
            cycles = 8;
            printf("AND #\n");
            programCounter++;
            break;
        }

        // OR n
        // logical OR n with register A, result in A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N, H, C - reset

        case 0xB7: {
            cycles = 4;
            printf("OR A\n");
            programCounter++;
            break;
        }
        case 0xB0: {
            cycles = 4;
            printf("OR B\n");
            programCounter++;
            break;
        }
        case 0xB1: {
            cycles = 4;
            printf("OR C\n");
            programCounter++;
            break;
        }
        case 0xB2: {
            cycles = 4;
            printf("OR D\n");
            programCounter++;
            break;
        }
        case 0xB3: {
            cycles = 4;
            printf("OR E\n");
            programCounter++;
            break;
        }
        case 0xB4: {
            cycles = 4;
            printf("OR H\n");
            programCounter++;
            break;
        }
        case 0xB5: {
            cycles = 4;
            printf("OR L\n");
            programCounter++;
            break;
        }
        case 0xB6: {
            cycles = 8;
            printf("OR (HL)\n");
            programCounter++;
            break;
        }
        case 0xF6: {
            cycles = 8;
            printf("OR #\n");
            programCounter++;
            break;
        }

        // XOR n
        // logical exclusive OR n with register A, result in A
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0
        // N, H, C - reset

        case 0xAF: {
            cycles = 4;
            printf("XOR A\n");
            programCounter++;
            break;
        }
        case 0xA8: {
            cycles = 4;
            printf("XOR B\n");
            programCounter++;
            break;
        }
        case 0xA9: {
            cycles = 4;
            printf("XOR C\n");
            programCounter++;
            break;
        }
        case 0xAA: {
            cycles = 4;
            printf("XOR D\n");
            programCounter++;
            break;
        }
        case 0xAB: {
            cycles = 4;
            printf("XOR E\n");
            programCounter++;
            break;
        }
        case 0xAC: {
            cycles = 4;
            printf("XOR H\n");
            programCounter++;
            break;
        }
        case 0xAD: {
            cycles = 4;
            printf("XOR L\n");
            programCounter++;
            break;
        }
        case 0xAE: {
            cycles = 8;
            printf("XOR (HL)\n");
            programCounter++;
            break;
        }
        case 0xEE: {
            cycles = 8;
            printf("XOR #\n");
            programCounter++;
            break;
        }

        // CP n
        // compare A with n. this is A - n, but results are thrown away
        // n = A, B, C, D, E, H, L, (HL), #
        // flags
        // Z - set if result is 0. ie. if A = n
        // N - set
        // H - set if no borrow from bit 4
        // C - set if no borrow (A < n)







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
