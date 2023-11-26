#include "StaticStringRandom.hpp"

StaticStringRandom::StaticStringRandom(const std::string &strDefaultRandomString)
    : m_strDefaultString(strDefaultRandomString)
{
}

StaticStringRandom::~StaticStringRandom()
{
}

std::string StaticStringRandom::RandomString(uint8_t uLength)
{
    return m_strDefaultString;
}