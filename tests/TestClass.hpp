#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <NTTDependencyInjection/NTTDependencyInjection.hpp>

class TestClass : public ntt::injector::DependencyBase
{
public:
    TestClass(int id);
    ~TestClass();
    inline int GetId() const { return m_sId; }

private:
    int m_sId;
};

class NeededDependencyClass : public ntt::injector::DependencyBase
{
public:
    NeededDependencyClass(std::shared_ptr<TestClass> obj, int sValue);
    ~NeededDependencyClass();

    inline int GetValue() const { return m_sValue; }
    inline std::shared_ptr<TestClass> GetTestClass() const { return m_tcObj; }

private:
    std::shared_ptr<TestClass> m_tcObj;
    int m_sValue;
};