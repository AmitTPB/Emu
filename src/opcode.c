#include "opcode.h"

int get_instr_length(addresing_mode mode) {
	switch (mode) {
		case ZERO_PAGE:
			return 2;
		case ZERO_PAGE_X:
			return 2;
		case ZERO_PAGE_Y:
			return 2;
		case ABSOLUTE:
			return 3;
		case INDEXED_ABSOLUTE_X:
			return 3;
		case INDEXED_ABSOLUTE_Y:
			return 3;
		case INDIRECT:
			return 3;
		case IMPLIED:
			return 1;
		case ACCUMULATOR:
			return 1;
		case IMMEDIATE:
			return 2;
		case RELATIVE:
			return 2;
		case INDEXED_INDIRECT: // INDIRECT X
			return 2;
		case INDIRECT_INDEXED: // INDIRECT Y
			return 2;
	}

	// panic("Invalid addressing mode.");
	return -1;
}

void add_opcode(byte opcode, instruction instr) {
	opcode_table[opcode] = instr;
}

void init_opcodes() {
	add_opcode(0xea, (instruction) {IMPLIED,            instruction_nop});

	add_opcode(0x29, (instruction) {IMMEDIATE,          instruction_and});
	add_opcode(0x25, (instruction) {ZERO_PAGE,          instruction_and});
	add_opcode(0x35, (instruction) {ZERO_PAGE_X,        instruction_and});
	add_opcode(0x2d, (instruction) {ABSOLUTE,           instruction_and});
	add_opcode(0x3d, (instruction) {INDEXED_ABSOLUTE_X, instruction_and});
	add_opcode(0x39, (instruction) {INDEXED_ABSOLUTE_Y, instruction_and});
	add_opcode(0x21, (instruction) {INDEXED_INDIRECT,   instruction_and});
	add_opcode(0x31, (instruction) {INDIRECT_INDEXED,   instruction_and});

	add_opcode(0x49, (instruction) {IMMEDIATE,          instruction_eor});
	add_opcode(0x45, (instruction) {ZERO_PAGE,          instruction_eor});
	add_opcode(0x55, (instruction) {ZERO_PAGE_X,        instruction_eor});
	add_opcode(0x4d, (instruction) {ABSOLUTE,           instruction_eor});
	add_opcode(0x5d, (instruction) {INDEXED_ABSOLUTE_X, instruction_eor});
	add_opcode(0x59, (instruction) {INDEXED_ABSOLUTE_Y, instruction_eor});
	add_opcode(0x41, (instruction) {INDEXED_INDIRECT,   instruction_eor});
	add_opcode(0x51, (instruction) {INDIRECT_INDEXED,   instruction_eor});

	add_opcode(0x09, (instruction) {IMMEDIATE,          instruction_ora});
	add_opcode(0x05, (instruction) {ZERO_PAGE,          instruction_ora});
	add_opcode(0x15, (instruction) {ZERO_PAGE_X,        instruction_ora});
	add_opcode(0x0d, (instruction) {ABSOLUTE,           instruction_ora});
	add_opcode(0x1d, (instruction) {INDEXED_ABSOLUTE_X, instruction_ora});
	add_opcode(0x19, (instruction) {INDEXED_ABSOLUTE_Y, instruction_ora});
	add_opcode(0x01, (instruction) {INDEXED_INDIRECT,   instruction_ora});
	add_opcode(0x11, (instruction) {INDIRECT_INDEXED,   instruction_ora});

	add_opcode(0x4a, (instruction) {ACCUMULATOR,        instruction_lsr});
	add_opcode(0x46, (instruction) {ZERO_PAGE,          instruction_lsr});
	add_opcode(0x56, (instruction) {ZERO_PAGE_X,        instruction_lsr});
	add_opcode(0x4e, (instruction) {ABSOLUTE,           instruction_lsr});
	add_opcode(0x5e, (instruction) {INDEXED_ABSOLUTE_X, instruction_lsr});

	add_opcode(0xca, (instruction) {IMPLIED,            instruction_dex});

	add_opcode(0x88, (instruction) {IMPLIED,            instruction_dey});

	add_opcode(0xc6, (instruction) {ZERO_PAGE,          instruction_dec});
	add_opcode(0xd6, (instruction) {ZERO_PAGE_X,        instruction_dec});
	add_opcode(0xce, (instruction) {ABSOLUTE,           instruction_dec});
	add_opcode(0xde, (instruction) {INDEXED_ABSOLUTE_X, instruction_dec});

	add_opcode(0xe8, (instruction) {IMPLIED,            instruction_inx});

	add_opcode(0xc8, (instruction) {IMPLIED,            instruction_iny});

	add_opcode(0xe6, (instruction) {ZERO_PAGE,          instruction_inc});
	add_opcode(0xf6, (instruction) {ZERO_PAGE_X,        instruction_inc});
	add_opcode(0xee, (instruction) {ABSOLUTE,           instruction_inc});
	add_opcode(0xfe, (instruction) {INDEXED_ABSOLUTE_X, instruction_inc});

	add_opcode(0x78, (instruction) {IMPLIED,            instruction_sei});
	add_opcode(0x38, (instruction) {IMPLIED,            instruction_sec});
	add_opcode(0xf8, (instruction) {IMPLIED,            instruction_sed});
	add_opcode(0x18, (instruction) {IMPLIED,            instruction_clc});
	add_opcode(0xd8, (instruction) {IMPLIED,            instruction_cld});
	add_opcode(0x58, (instruction) {IMPLIED,            instruction_cli});
	add_opcode(0xb8, (instruction) {IMPLIED,            instruction_clv});

	add_opcode(0x4c, (instruction) {ABSOLUTE,            instruction_jmp});
	add_opcode(0x6c, (instruction) {INDIRECT,            instruction_jmp});

	add_opcode(0xa9, (instruction) {IMMEDIATE,          instruction_lda});
	add_opcode(0xa5, (instruction) {ZERO_PAGE,          instruction_lda});
	add_opcode(0xb5, (instruction) {ZERO_PAGE_X,        instruction_lda});
	add_opcode(0xad, (instruction) {ABSOLUTE,           instruction_lda});
	add_opcode(0xbd, (instruction) {INDEXED_ABSOLUTE_X, instruction_lda});
	add_opcode(0xb9, (instruction) {INDEXED_ABSOLUTE_Y, instruction_lda});
	add_opcode(0xa1, (instruction) {INDEXED_INDIRECT,   instruction_lda});
	add_opcode(0xb1, (instruction) {INDIRECT_INDEXED,   instruction_lda});

	add_opcode(0xa2, (instruction) {IMMEDIATE,          instruction_ldx});
	add_opcode(0xa6, (instruction) {ZERO_PAGE,          instruction_ldx});
	add_opcode(0xb6, (instruction) {ZERO_PAGE_Y,        instruction_ldx});
	add_opcode(0xae, (instruction) {ABSOLUTE,           instruction_ldx});
	add_opcode(0xbe, (instruction) {INDEXED_ABSOLUTE_Y, instruction_ldx});

	add_opcode(0xa0, (instruction) {IMMEDIATE,          instruction_ldy});
	add_opcode(0xa4, (instruction) {ZERO_PAGE,          instruction_ldy});
	add_opcode(0xb4, (instruction) {ZERO_PAGE_X,        instruction_ldy});
	add_opcode(0xac, (instruction) {ABSOLUTE,           instruction_ldy});
	add_opcode(0xbc, (instruction) {INDEXED_ABSOLUTE_X, instruction_ldy});


	add_opcode(0x85, (instruction) {ZERO_PAGE,          instruction_sta});
	add_opcode(0x95, (instruction) {ZERO_PAGE_X,        instruction_sta});
	add_opcode(0x8d, (instruction) {ABSOLUTE,           instruction_sta});
	add_opcode(0x9d, (instruction) {INDEXED_ABSOLUTE_X, instruction_sta});
	add_opcode(0x99, (instruction) {INDEXED_ABSOLUTE_Y, instruction_sta});
	add_opcode(0x81, (instruction) {INDEXED_INDIRECT,   instruction_sta});
	add_opcode(0x91, (instruction) {INDIRECT_INDEXED,   instruction_sta});

	add_opcode(0x86, (instruction) {ZERO_PAGE,          instruction_stx});
	add_opcode(0x96, (instruction) {ZERO_PAGE_Y,        instruction_stx});
	add_opcode(0x8e, (instruction) {ABSOLUTE,           instruction_stx});

	add_opcode(0x84, (instruction) {ZERO_PAGE,          instruction_sty});
	add_opcode(0x94, (instruction) {ZERO_PAGE_X,        instruction_sty});
	add_opcode(0x8c, (instruction) {ABSOLUTE,           instruction_sty});

	add_opcode(0xaa, (instruction) {IMPLIED,         	instruction_tax});
	add_opcode(0xa8, (instruction) {IMPLIED,            instruction_tay});
	add_opcode(0xba, (instruction) {IMPLIED,            instruction_tsx});
	add_opcode(0x8a, (instruction) {IMPLIED,            instruction_txa});
	add_opcode(0x9a, (instruction) {IMPLIED,            instruction_txs});
	add_opcode(0x98, (instruction) {IMPLIED,            instruction_txs});

}