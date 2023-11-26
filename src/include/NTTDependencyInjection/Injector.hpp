#pragma once
#include <functional>
#include <unordered_map>
#include <memory>

#include "DependencyBase.hpp"

namespace ntt::injector
{
    namespace internal
    {
        extern std::unordered_map<size_t, std::shared_ptr<DependencyBase>> _mInstanceMap;
    } // namespace internal

    template <typename Type, typename Ins, typename... Args>
    void Register(Args &&...args)
    {
        internal::_mInstanceMap[typeid(Type).hash_code()] = std::make_shared<Ins>(
            std::forward<Args>(args)...);
    }

    template <typename Type>
    std::shared_ptr<Type> Get()
    {
        size_t key = typeid(Type).hash_code();
        if (internal::_mInstanceMap.find(key) != internal::_mInstanceMap.end())
        {
            return std::dynamic_pointer_cast<Type>(internal::_mInstanceMap[key]);
        }
        else
        {
            return nullptr;
        }
    }
} // namespace ntt::injector
