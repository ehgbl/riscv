
class Cache {
public:
    Cache(size_t size, size_t line_size, size_t associativity);
    bool access(uint32_t address, bool is_write);
    
private:
    struct CacheLine {
        uint32_t tag;
        bool valid;
        bool dirty;
        std::vector<uint8_t> data;
    };
    
    std::vector<std::vector<CacheLine>> sets;
    size_t set_bits;
    size_t line_size;
};