#pragma once
#include "IRandom.hpp"
#include "IPasswordManagement.hpp"

class PasswordManager : public IPasswordManagement
{
public:
    PasswordManager(std::shared_ptr<IRandom> random, const std::string &strUsername);
    ~PasswordManager();

    virtual std::string GeneratePassword() override;

private:
    std::shared_ptr<IRandom> m_iRandom;
    std::string m_strUsername;
};