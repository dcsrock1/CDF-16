#pragma once

class Operations {
public:

    enum opcodes {
        NOP = 0x00, // No Operation
        // All instructions for loading data into CPU registers are listed here
        LDAC_IM = 0x01,
        LDAC_AB = 0x02,
        LDAC_ABAI = 0x03,
        LDAC_ABCI = 0x04,
        LDA_IM = 0x05,
        LDA_AB = 0x06,
        LDA_ABAI = 0x07,
        LDA_ABCI = 0x08,        
    };
};
