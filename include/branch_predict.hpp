class BranchPredict {
public:
    bool predict(uint32_t pc);
    void update(uint32_t pc, bool taken);
    
private:
    static constexpr size_t TABLE_SIZE = 4096;
    std::vector<uint8_t> prediction_table;
};

