#include <iostream>

#ifdef _DEBUG
#include <CPPMemoryChecker/CPPMemoryChecker.hpp>
ntt::memory::MemoryChecker checker;
#endif

#include <NTTDependencyInjection/NTTDependencyInjection.hpp>
#include "IRandom.hpp"
#include "IPasswordManagement.hpp"
#include "StaticStringRandom.hpp"
#include "PasswordManager.hpp"

int main(void)
{
    ntt::injector::Register<IRandom, StaticStringRandom>("2349balsdf");
    ntt::injector::Register<IPasswordManagement, PasswordManager>(
        ntt::injector::Get<IRandom>(),
        "ThaoNguyenThe");
    std::cout << ntt::injector::Get<IPasswordManagement>()->GeneratePassword() << std::endl;
    return 0;
}