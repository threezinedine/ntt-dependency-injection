#pragma once
#include <string>
#include "IRandom.hpp"

class StaticStringRandom : public IRandom
{
public:
    StaticStringRandom(const std::string &strDefaultRandomString);
    ~StaticStringRandom();

    std::string RandomString(uint8_t uLength) override;

private:
    std::string m_strDefaultString;
};