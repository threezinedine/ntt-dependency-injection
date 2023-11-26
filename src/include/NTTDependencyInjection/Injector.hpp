#pragma once
#include <functional>
#include <unordered_map>
#include <memory>

#include "DependencyBase.hpp"

namespace ntt::injector
{
    namespace internal
    {
        std::unordered_map<size_t, std::shared_ptr<DependencyBase>> &_GetMap();
    } // namespace internal

    template <typename Type, typename Ins, typename... Args>
    void Register(Args &&...args)
    {
        internal::_GetMap()[typeid(Type).hash_code()] = std::make_shared<Ins>(
            std::forward<Args>(args)...);
    }

    template <typename Type>
    std::shared_ptr<Type> Get()
    {
        size_t key = typeid(Type).hash_code();
        if (internal::_GetMap().find(key) != internal::_GetMap().end())
        {
            return std::dynamic_pointer_cast<Type>(internal::_GetMap()[key]);
        }
        else
        {
            return nullptr;
        }
    }
} // namespace ntt::injector
