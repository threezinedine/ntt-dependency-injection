#include <sstream>
#include "PasswordManager.hpp"

PasswordManager::PasswordManager(std::shared_ptr<IRandom> random, const std::string &strUsername)
    : m_iRandom(random), m_strUsername(strUsername)
{
}

PasswordManager::~PasswordManager()
{
}

std::string PasswordManager::GeneratePassword()
{
    std::stringstream ss;
    ss << m_strUsername << "_" << m_iRandom->RandomString(3);
    return ss.str();
}
