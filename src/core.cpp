#include <iostream>
void RISCVCore::tick() {
    // Pipeline execution in reverse order to prevent data loss
    writeback();
    memory();
    execute();
    decode();
    fetch();
    
    metrics.cycles++;
}

void RISCVCore::fetch() {
    if (pipeline.fetch_decode.valid) {
        return; // Stall if next stage is busy
    }
    
    uint32_t pc = pipeline.fetch_decode.pc;
    bool hit = icache->access(pc, false);
    
    if (!hit) {
        metrics.cache_misses++;
        return; // Stall on cache miss
    }
    
    // Predict next PC
    bool predicted_taken = branch_predictor->predict(pc);
    pipeline.fetch_decode = {
        .pc = predicted_taken ? predicted_target : pc + 4,
        .instruction = memory[pc],
        .valid = true
    };
}