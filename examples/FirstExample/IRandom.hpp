#pragma once
#include <string>
#include <NTTDependencyInjection/NTTDependencyInjection.hpp>

class IRandom : public ntt::injector::DependencyBase
{
public:
    virtual std::string RandomString(uint8_t u8Length) = 0;
};