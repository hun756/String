#include <gtest/gtest.h>
#include "string.hpp"
#include <memory>
#include <string>

TEST(String, CStrConstrucorTest)
{
    struct TestStruct
    {
        mutable kor::String<char> str;
        size_t acutal_capacity;
        size_t actual_size;
        std::unique_ptr<char[]> _toActualArray;
        std::string _actual;

        TestStruct(const std::string _cStr, std::unique_ptr<char[]>& toActualArray, const size_t _acutal_capacity, const size_t _actual_size)
            : str{_cStr.c_str()}, _actual{_cStr}, _toActualArray{std::move(toActualArray)},
              acutal_capacity{_acutal_capacity}, actual_size{_actual_size}
        {
        }
    };

    std::unique_ptr<char[]> test01ch{ new char[7] { 'M', 'e', 'r', 'h', 'a', 'b', 'a' }};

    std::vector<TestStruct> testVecs{};
    testVecs.push_back(TestStruct{"Merhaba", test01ch, 15, 7});

    for(const auto& test : testVecs) {
        ASSERT_STREQ(test._actual.c_str(), test.str.c_str());
        ASSERT_EQ(test.acutal_capacity, test.str.capacity());
        ASSERT_EQ(test.actual_size, test.str.size());

        auto _val = test.str.toCharArray();
        for (size_t i = 0; i < test.actual_size; ++i) {
            ASSERT_EQ(test._toActualArray[i], _val[i]);
        }
    }
}


/**
 * @brief Construct a new TEST object
 *  @bug
 *      Pasing when "" 
 * @todo
 *  Fix it.
 */
TEST(String, CheckEmpty)
{
    kor::String<char> ch1;
    kor::String<char> ch2 {};
    // fix this bug
    // kor::String<char> ch3 {""};
    kor::String<char> ch4 {"a"};

    ASSERT_TRUE(ch1.empty());
    ASSERT_TRUE(ch2.empty());
    // ASSERT_TRUE(ch3.empty());
    ASSERT_TRUE(!ch4.empty());
}

TEST(String, SizeControl)
{
    struct TestStruct
    {
        kor::String<char> str;
        size_t actual_length;

        TestStruct(const std::string& s_name, const size_t _actual_l) : str(s_name.c_str()), actual_length(_actual_l) {}
    };

    std::vector<TestStruct> testVecs {
        {"a", 1},
        {"abc", 3},
        {"merhabadenemedeneme", 19},
        {"QnUgZm90b8SfcmFmxLFuIGnDp2VyaXNpbmRlIHNlbmkgZ2l6bGkgYmlyIG1lc2FqIGJla2xpeW9yLg==", 80},
    };

    size_t index = 0;
    for(const auto& val : testVecs) {
        ASSERT_EQ(val.str.size(), val.actual_length) << index;
        ASSERT_EQ(val.str.length(), val.actual_length) << index;
        ++index;
    }
}