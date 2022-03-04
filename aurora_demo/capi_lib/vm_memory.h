#pragma once
#include <map>
#include <string>
#include <vector>

class vm_memory {
public:
    void read_memory(uint64_t offset, std::vector<uint8_t> & buffer) {
        std::printf("[vm_memory][read] : from: %lu - %lu  size: %zu \n", offset, offset + buffer.size(), buffer.size());
        char * begin_address = (char *)offset;
        for (std::size_t i = 0; i < buffer.size(); ++i) {
            buffer[i] = *begin_address;
            begin_address++;
        }
        printf("[debug][vm_memory][read] result:");
        for (auto _c : buffer) {
            printf("%c",_c);
        }
        printf("\n");

        // auto const & data = hash_memory.at(std::make_pair(offset, buffer.size()));
        // for (std::size_t i = 0; i < buffer.size(); ++i) {
        //     // buffer[i] = inner_memory[offset + i];
        //     buffer[i] = data[i];
        // }
    }

    void write_memory(uint64_t offset, std::vector<uint8_t> const & buffer) {
        std::printf("[vm_memory][write] : from: %lu - %lu  size: %zu  \n", offset, offset + buffer.size(), buffer.size());
        char * begin_address = (char *)offset;
        for (std::size_t i = 0; i < buffer.size(); ++i) {
            *begin_address = buffer[i];
            begin_address++;
        }

        // auto & data = hash_memory[std::make_pair(offset, buffer.size())];
        // data.resize(buffer.size());
        // for (std::size_t i = 0; i < buffer.size(); ++i) {
        //     // inner_memory[offset + i] = buffer[i];
        //     data[i] = buffer[i];
        // }
        // std::printf("[vm_memory][write] : from: %lu - %lu  size: %zu  \n", offset, offset + buffer.size(), buffer.size());
    }

private:
    // std::map<uint64_t, std::string> inner_memory;

    // std::vector<uint8_t> inner_memory{std::vector<uint8_t>(0xFFFFFF, 0)};

    // <(offset, len), data>
    // std::map<std::pair<uint64_t, uint64_t>, std::vector<uint8_t>> hash_memory;
};