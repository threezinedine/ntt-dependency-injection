#include "NTTDependencyInjection/Injector.hpp"

namespace ntt::injector
{
    namespace internal
    {
        std::unordered_map<size_t, std::shared_ptr<DependencyBase>> &_GetMap()
        {
            static std::unordered_map<size_t, std::shared_ptr<DependencyBase>> _mInstanceMap = {};
            return _mInstanceMap;
        }
    } // namespace internal
} // namespace ntt::injector
