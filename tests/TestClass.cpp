#include "TestClass.hpp"

TestClass::TestClass(int id)
    : m_sId(id)
{
}

TestClass::~TestClass()
{
}

NeededDependencyClass::NeededDependencyClass(std::shared_ptr<TestClass> obj, int sValue)
    : m_tcObj(obj), m_sValue(sValue)
{
}

NeededDependencyClass::~NeededDependencyClass()
{
}