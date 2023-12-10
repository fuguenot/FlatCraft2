#include <functional>
#include <utility>

namespace pair_hash {
    struct pair_hash final {
        template<class TFirst, class TSecond>
        size_t operator()(const std::pair<TFirst, TSecond> &p) const noexcept {
            uintmax_t hash = std::hash<TFirst>{}(p.first);
            hash <<= sizeof(uintmax_t) * 4;
            hash ^= std::hash<TSecond>{}(p.second);
            return std::hash<uintmax_t>{}(hash);
        }
    };
}  // namespace pair_hash
