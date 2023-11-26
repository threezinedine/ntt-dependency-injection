#pragma once
#include <string>
#include <NTTDependencyInjection/NTTDependencyInjection.hpp>

class IPasswordManagement : public ntt::injector::DependencyBase
{
public:
    virtual std::string GeneratePassword() = 0;
};