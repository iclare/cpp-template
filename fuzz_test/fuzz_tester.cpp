#include <fmt/format.h>

#include <iterator>
#include <utility>

[[nodiscard]] auto sumValues(const uint8_t *data, size_t size) {
    constexpr auto scale = 1000;

    int value = 0;
    for (std::size_t offset = 0; offset < size; ++offset) {
        // NOLINTNEXTLINE(google-runtime-int)
        value += static_cast<int>(*std::next(data, static_cast<long>(offset))) * scale;
    }
    return value;
}

// Fuzzer that attempts to invoke undefined behavior for signed integer overflow
// cppcheck-suppress unusedFunction symbolName=LLVMFuzzerTestOneInput
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    fmt::print("Value sum: {}, len{}\n", sumValues(data, size), size);
    return 0;
}
