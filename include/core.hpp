#pragma once
#include <vector>
#include <cstdint>
#include <memory>

class BranchPredictor;
class Cache;

class RISCVCore {
public:
    RISCVCore();
    void tick();
    void reset();
    
private:
    // Pipeline stages
    void fetch();
    void decode();
    void execute();
    void memory();
    void writeback();
    
    // Pipeline registers
    struct PipelineReg {
        uint32_t pc;
        uint32_t instruction;
        bool valid;
    };
    
    struct PipelineState {
        PipelineReg fetch_decode;
        PipelineReg decode_execute;
        PipelineReg execute_memory;
        PipelineReg memory_writeback;
    } pipeline;
    
    // Components
    std::unique_ptr<BranchPredictor> branch_predictor;
    std::unique_ptr<Cache> icache;
    std::unique_ptr<Cache> dcache;
    
    // Register file
    std::array<uint32_t, 32> registers;
    
    // Performance counters
    struct Metrics {
        uint64_t total_instructions;
        uint64_t cycles;
        uint64_t branch_mispredictions;
        uint64_t cache_misses;
    } metrics;
};