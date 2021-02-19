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
        case INDEXED_INDIRECT:  // INDIRECT X
            return 2;
        case INDIRECT_INDEXED:  // INDIRECT Y
            return 2;
    }

    // panic("Invalid addressing mode.");
    return -1;
}

void add_opcode(byte opcode, instruction instr) {
    opcode_table[opcode] = instr;
}

void init_opcodes() {
    add_opcode(0xea, (instruction){IMPLIED, instruction_nop});

    add_opcode(0x29, (instruction){IMMEDIATE, instruction_and});
    add_opcode(0x25, (instruction){ZERO_PAGE, instruction_and});
    add_opcode(0x35, (instruction){ZERO_PAGE_X, instruction_and});
    add_opcode(0x2d, (instruction){ABSOLUTE, instruction_and});
    add_opcode(0x3d, (instruction){INDEXED_ABSOLUTE_X, instruction_and});
    add_opcode(0x39, (instruction){INDEXED_ABSOLUTE_Y, instruction_and});
    add_opcode(0x21, (instruction){INDEXED_INDIRECT, instruction_and});
    add_opcode(0x31, (instruction){INDIRECT_INDEXED, instruction_and});

    add_opcode(0x49, (instruction){IMMEDIATE, instruction_eor});
    add_opcode(0x45, (instruction){ZERO_PAGE, instruction_eor});
    add_opcode(0x55, (instruction){ZERO_PAGE_X, instruction_eor});
    add_opcode(0x4d, (instruction){ABSOLUTE, instruction_eor});
    add_opcode(0x5d, (instruction){INDEXED_ABSOLUTE_X, instruction_eor});
    add_opcode(0x59, (instruction){INDEXED_ABSOLUTE_Y, instruction_eor});
    add_opcode(0x41, (instruction){INDEXED_INDIRECT, instruction_eor});
    add_opcode(0x51, (instruction){INDIRECT_INDEXED, instruction_eor});

    add_opcode(0x09, (instruction){IMMEDIATE, instruction_ora});
    add_opcode(0x05, (instruction){ZERO_PAGE, instruction_ora});
    add_opcode(0x15, (instruction){ZERO_PAGE_X, instruction_ora});
    add_opcode(0x0d, (instruction){ABSOLUTE, instruction_ora});
    add_opcode(0x1d, (instruction){INDEXED_ABSOLUTE_X, instruction_ora});
    add_opcode(0x19, (instruction){INDEXED_ABSOLUTE_Y, instruction_ora});
    add_opcode(0x01, (instruction){INDEXED_INDIRECT, instruction_ora});
    add_opcode(0x11, (instruction){INDIRECT_INDEXED, instruction_ora});

    add_opcode(0x4a, (instruction){ACCUMULATOR, instruction_lsr});
    add_opcode(0x46, (instruction){ZERO_PAGE, instruction_lsr});
    add_opcode(0x56, (instruction){ZERO_PAGE_X, instruction_lsr});
    add_opcode(0x4e, (instruction){ABSOLUTE, instruction_lsr});
    add_opcode(0x5e,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_lsr});

    add_opcode(0xca, (instruction){IMPLIED, instruction_dex});

    add_opcode(0x88, (instruction){IMPLIED, instruction_dey});

    add_opcode(0xc6, (instruction){ZERO_PAGE, instruction_dec});
    add_opcode(0xd6, (instruction){ZERO_PAGE_X, instruction_dec});
    add_opcode(0xce, (instruction){ABSOLUTE, instruction_dec});
    add_opcode(0xde,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_dec});

    add_opcode(0xe8, (instruction){IMPLIED, instruction_inx});

    add_opcode(0xc8, (instruction){IMPLIED, instruction_iny});

    add_opcode(0xe6, (instruction){ZERO_PAGE, instruction_inc});
    add_opcode(0xf6, (instruction){ZERO_PAGE_X, instruction_inc});
    add_opcode(0xee, (instruction){ABSOLUTE, instruction_inc});
    add_opcode(0xfe,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_inc});

    add_opcode(0x78, (instruction){IMPLIED, instruction_sei});
    add_opcode(0x38, (instruction){IMPLIED, instruction_sec});
    add_opcode(0xf8, (instruction){IMPLIED, instruction_sed});
    add_opcode(0x18, (instruction){IMPLIED, instruction_clc});
    add_opcode(0xd8, (instruction){IMPLIED, instruction_cld});
    add_opcode(0x58, (instruction){IMPLIED, instruction_cli});
    add_opcode(0xb8, (instruction){IMPLIED, instruction_clv});

    add_opcode(0x4c, (instruction){ABSOLUTE, instruction_jmp});
    add_opcode(0x6c, (instruction){INDIRECT, instruction_jmp});

    add_opcode(0xa9, (instruction){IMMEDIATE, instruction_lda});
    add_opcode(0xa5, (instruction){ZERO_PAGE, instruction_lda});
    add_opcode(0xb5, (instruction){ZERO_PAGE_X, instruction_lda});
    add_opcode(0xad, (instruction){ABSOLUTE, instruction_lda});
    add_opcode(0xbd, (instruction){INDEXED_ABSOLUTE_X, instruction_lda});
    add_opcode(0xb9, (instruction){INDEXED_ABSOLUTE_Y, instruction_lda});
    add_opcode(0xa1, (instruction){INDEXED_INDIRECT, instruction_lda});
    add_opcode(0xb1, (instruction){INDIRECT_INDEXED, instruction_lda});

    add_opcode(0xa2, (instruction){IMMEDIATE, instruction_ldx});
    add_opcode(0xa6, (instruction){ZERO_PAGE, instruction_ldx});
    add_opcode(0xb6, (instruction){ZERO_PAGE_Y, instruction_ldx});
    add_opcode(0xae, (instruction){ABSOLUTE, instruction_ldx});
    add_opcode(0xbe, (instruction){INDEXED_ABSOLUTE_Y, instruction_ldx});

    add_opcode(0xa0, (instruction){IMMEDIATE, instruction_ldy});
    add_opcode(0xa4, (instruction){ZERO_PAGE, instruction_ldy});
    add_opcode(0xb4, (instruction){ZERO_PAGE_X, instruction_ldy});
    add_opcode(0xac, (instruction){ABSOLUTE, instruction_ldy});
    add_opcode(0xbc, (instruction){INDEXED_ABSOLUTE_X, instruction_ldy});

    add_opcode(0x85, (instruction){ZERO_PAGE, instruction_sta});
    add_opcode(0x95, (instruction){ZERO_PAGE_X, instruction_sta});
    add_opcode(0x8d, (instruction){ABSOLUTE, instruction_sta});
    add_opcode(0x9d,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_sta});
    add_opcode(0x99,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_Y, instruction_sta});
    add_opcode(0x81, (instruction){INDEXED_INDIRECT, instruction_sta});
    add_opcode(0x91, (instruction){SPECIAL_INDIRECT_INDEXED, instruction_sta});

    add_opcode(0x86, (instruction){ZERO_PAGE, instruction_stx});
    add_opcode(0x96, (instruction){ZERO_PAGE_Y, instruction_stx});
    add_opcode(0x8e, (instruction){ABSOLUTE, instruction_stx});

    add_opcode(0x84, (instruction){ZERO_PAGE, instruction_sty});
    add_opcode(0x94, (instruction){ZERO_PAGE_X, instruction_sty});
    add_opcode(0x8c, (instruction){ABSOLUTE, instruction_sty});

    add_opcode(0xaa, (instruction){IMPLIED, instruction_tax});
    add_opcode(0xa8, (instruction){IMPLIED, instruction_tay});
    add_opcode(0xba, (instruction){IMPLIED, instruction_tsx});
    add_opcode(0x8a, (instruction){IMPLIED, instruction_txa});
    add_opcode(0x9a, (instruction){IMPLIED, instruction_txs});
    add_opcode(0x98, (instruction){IMPLIED, instruction_txs});

    add_opcode(0x24, (instruction){ZERO_PAGE, instruction_bit});
    add_opcode(0x2c, (instruction){ABSOLUTE, instruction_bit});

    add_opcode(0x2a, (instruction){ACCUMULATOR, instruction_rol});
    add_opcode(0x26, (instruction){ZERO_PAGE, instruction_rol});
    add_opcode(0x36, (instruction){ZERO_PAGE_X, instruction_rol});
    add_opcode(0x2e, (instruction){ABSOLUTE, instruction_rol});
    add_opcode(0x3e,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_rol});

    add_opcode(0x6a, (instruction){ACCUMULATOR, instruction_ror});
    add_opcode(0x66, (instruction){ZERO_PAGE, instruction_ror});
    add_opcode(0x76, (instruction){ZERO_PAGE_X, instruction_ror});
    add_opcode(0x6e, (instruction){ABSOLUTE, instruction_ror});
    add_opcode(0x7e,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_ror});

    add_opcode(0x0a, (instruction){ACCUMULATOR, instruction_asl});
    add_opcode(0x06, (instruction){ZERO_PAGE, instruction_asl});
    add_opcode(0x16, (instruction){ZERO_PAGE_X, instruction_asl});
    add_opcode(0x0e, (instruction){ABSOLUTE, instruction_asl});
    add_opcode(0x1e,
               (instruction){SPECIAL_INDEXED_ABSOLUTE_X, instruction_asl});

    add_opcode(0x90, (instruction){RELATIVE, instruction_bcc});
    add_opcode(0xb0, (instruction){RELATIVE, instruction_bcs});
    add_opcode(0xf0, (instruction){RELATIVE, instruction_beq});
    add_opcode(0x30, (instruction){RELATIVE, instruction_bmi});
    add_opcode(0xd0, (instruction){RELATIVE, instruction_bne});
    add_opcode(0x10, (instruction){RELATIVE, instruction_bpl});
    add_opcode(0x50, (instruction){RELATIVE, instruction_bvc});
    add_opcode(0x70, (instruction){RELATIVE, instruction_bvs});

    add_opcode(0x48, (instruction){IMPLIED, instruction_pha});
    add_opcode(0x08, (instruction){IMPLIED, instruction_php});
    add_opcode(0x68, (instruction){IMPLIED, instruction_pla});
    add_opcode(0x28, (instruction){IMPLIED, instruction_plp});

    add_opcode(0x20, (instruction){ABSOLUTE, instruction_jsr});
    add_opcode(0x60, (instruction){IMPLIED, instruction_rts});

    add_opcode(0x69, (instruction){IMMEDIATE, instruction_adc});
    add_opcode(0x65, (instruction){ZERO_PAGE, instruction_adc});
    add_opcode(0x75, (instruction){ZERO_PAGE_X, instruction_adc});
    add_opcode(0x6d, (instruction){ABSOLUTE, instruction_adc});
    add_opcode(0x7d, (instruction){INDEXED_ABSOLUTE_X, instruction_adc});
    add_opcode(0x79, (instruction){INDEXED_ABSOLUTE_Y, instruction_adc});
    add_opcode(0x61, (instruction){INDEXED_INDIRECT, instruction_adc});
    add_opcode(0x71, (instruction){INDIRECT_INDEXED, instruction_adc});

    add_opcode(0xe9, (instruction){IMMEDIATE, instruction_sbc});
    add_opcode(0xe5, (instruction){ZERO_PAGE, instruction_sbc});
    add_opcode(0xf5, (instruction){ZERO_PAGE_X, instruction_sbc});
    add_opcode(0xed, (instruction){ABSOLUTE, instruction_sbc});
    add_opcode(0xfd, (instruction){INDEXED_ABSOLUTE_X, instruction_sbc});
    add_opcode(0xf9, (instruction){INDEXED_ABSOLUTE_Y, instruction_sbc});
    add_opcode(0xe1, (instruction){INDEXED_INDIRECT, instruction_sbc});
    add_opcode(0xf1, (instruction){INDIRECT_INDEXED, instruction_sbc});

    add_opcode(0xc9, (instruction){IMMEDIATE, instruction_cmp});
    add_opcode(0xc5, (instruction){ZERO_PAGE, instruction_cmp});
    add_opcode(0xd5, (instruction){ZERO_PAGE_X, instruction_cmp});
    add_opcode(0xcd, (instruction){ABSOLUTE, instruction_cmp});
    add_opcode(0xdd, (instruction){INDEXED_ABSOLUTE_X, instruction_cmp});
    add_opcode(0xd9, (instruction){INDEXED_ABSOLUTE_Y, instruction_cmp});
    add_opcode(0xc1, (instruction){INDEXED_INDIRECT, instruction_cmp});
    add_opcode(0xd1, (instruction){INDIRECT_INDEXED, instruction_cmp});

    add_opcode(0xe0, (instruction){IMMEDIATE, instruction_cpx});
    add_opcode(0xe4, (instruction){ZERO_PAGE, instruction_cpx});
    add_opcode(0xec, (instruction){ABSOLUTE, instruction_cpx});

    add_opcode(0xc0, (instruction){IMMEDIATE, instruction_cpy});
    add_opcode(0xc4, (instruction){ZERO_PAGE, instruction_cpy});
    add_opcode(0xcc, (instruction){ABSOLUTE, instruction_cpy});

    // add_opcode(0x00, (instruction) {IMPLIED,            instruction_brk});
    add_opcode(0x40, (instruction){IMPLIED, instruction_rti});
}
