#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <NTTDependencyInjection/NTTDependencyInjection.hpp>

#include "TestClass.hpp"

class InjectorTest : public testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(InjectorTest, GivenAnObjectIsRegistered_WhenGetThatObject_ThenThatObjectIsObtained)
{
    ntt::injector::Register<TestClass, TestClass>(3);

    std::shared_ptr<TestClass> obj = ntt::injector::Get<TestClass>();

    EXPECT_THAT(obj->GetId(), testing::Eq(3));
}

TEST_F(InjectorTest, WhenGetTheObjectWhichHasNotBeenRegistered_ThenReturnsNull)
{
    ntt::injector::Register<TestClass, TestClass>(3);

    std::shared_ptr<NeededDependencyClass> obj = ntt::injector::Get<NeededDependencyClass>();

    EXPECT_THAT(obj, testing::IsNull());
}

TEST_F(InjectorTest, WhenRegisterObjectWithDendency_ThenCanGetThatObject)
{
    ntt::injector::Register<TestClass, TestClass>(3);
    ntt::injector::Register<NeededDependencyClass, NeededDependencyClass>(ntt::injector::Get<TestClass>(), 2);

    std::shared_ptr<NeededDependencyClass> obj = ntt::injector::Get<NeededDependencyClass>();

    EXPECT_THAT(obj->GetTestClass()->GetId(), testing::Eq(3));
}