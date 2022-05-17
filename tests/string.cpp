#include <gtest/gtest.h>

#define ENABLE_COMPABILITY_W_STD_VECTOR
#define ENABLE_COMPABILITY_W_STD_STRING

#include "string.hpp"
#include <memory>
#include <string>

TEST(String, CStrConstrucorTest)
{
    struct TestStruct
    {
        mutable kor::String str;
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
    kor::String ch1;
    kor::String ch2 {};
    // fix this bug
    // kor::String ch3 {""};
    kor::String ch4 {"a"};

    ASSERT_TRUE(ch1.empty());
    ASSERT_TRUE(ch2.empty());
    // ASSERT_TRUE(ch3.empty());
    ASSERT_TRUE(!ch4.empty());
}

TEST(String, SizeControl)
{
    struct TestStruct
    {
        kor::String str;
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

TEST(String, ConvensionSTDString)
{
    kor::String str {"hi everyone"};
    std::string stdStr = str;

    ASSERT_EQ(stdStr.size(), str.size());
    ASSERT_EQ(stdStr.capacity(), str.capacity());
    ASSERT_STREQ(stdStr.c_str(), str.c_str());
}

// TEST(String, ConvensionSTDVector)
// {
//     kor::String str {"hi everyone"};
//     str += "hi everyone, hi everyone";

//     std::vector<char> strVec = str;

//     ASSERT_EQ(strVec.size(), str.size());

//     size_t index = 0;
//     for (size_t i = 0; i < strVec.size(); ++i) {
//         ASSERT_EQ(strVec[i], str[i]) << index;
//         ++index;
//     }
// }


TEST(String, OperatorPlusEq)
{
    kor::String str {"hi everyone"};

    ASSERT_EQ(str.size(), static_cast<size_t>(11));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(15));

    str += "0000";

    ASSERT_EQ(str.size(), static_cast<size_t>(15));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(15));

    str += "0";

    ASSERT_EQ(str.size(), static_cast<size_t>(16));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(30));

    str += "000";

    ASSERT_EQ(str.size(), static_cast<size_t>(19));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(30));

    str += '0';
    ASSERT_EQ(str.size(), static_cast<size_t>(20));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(30));

    str += "0000000000";

    ASSERT_EQ(str.size(), static_cast<size_t>(30));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(30));

    str += '0';

    ASSERT_EQ(str.size(), static_cast<size_t>(31));
    ASSERT_EQ(str.capacity(), static_cast<size_t>(31));

    std::string _str {"hi everyone"};

    for(int i = 0; i < 20; i++) {
        _str += '0';
    }

    ASSERT_EQ(str.size(), _str.size());

    size_t index = 0;
    for(size_t i = 0; i < str.size(); i++) {
        ASSERT_EQ(str[i], _str[i]) << index;
        ++index;
    }
}

TEST(String, IteratorTest) {
    kor::String kStr {"00000000000000000000000000000000000000000000000000000000000000000000000000000000000"};
    std::string stdStr {"00000000000000000000000000000000000000000000000000000000000000000000000000000000000"};

    ASSERT_EQ(kStr.size(), stdStr.size());

    auto val = kStr.begin(); 
    auto val2 = stdStr.begin();

    for (; val != kStr.end() && val2 != stdStr.end(); ++val, ++val2) {
        ASSERT_EQ(*val, *val2);
    }

    kor::String::const_iterator val3 = kStr.begin();
    std::string::const_iterator val4 = stdStr.begin();

    for (; val3 != kStr.end() && val4 != stdStr.end(); ++val3, ++val4) {
        ASSERT_EQ(*val3, *val4);
    }

    kor::String::reverse_iterator val5 = kStr.rbegin();
    std::string::reverse_iterator val6 = stdStr.rbegin();

    for (; val5 != kStr.rend() && val6 != stdStr.rend(); ++val5, ++val6) {
        ASSERT_EQ(*val5, *val6);
    }

    kor::String::const_reverse_iterator val7 = kStr.rbegin();
    std::string::const_reverse_iterator val8 = stdStr.rbegin();

    for (; val7 != kStr.rend() && val8 != stdStr.rend(); ++val7, ++val8) {
        ASSERT_EQ(*val7, *val8);
    }
}

TEST(String, OperatorLess) 
{
    kor::String str1 {"a"};
    kor::String str2 {"b"};

    std::string str3 {"a"};
    std::string str4 {"b"};

    ASSERT_TRUE(str1 < str2);
    ASSERT_TRUE(str3 < str4);

    str1 = "11111111111111111111111111111111111111111111111111111111111111111111111111110";
    str2 = "11111111111111111111111111111111111111111111111111111111111111111111111111111";

    str3 = "11111111111111111111111111111111111111111111111111111111111111111111111111110";
    str4 = "11111111111111111111111111111111111111111111111111111111111111111111111111111";

    ASSERT_TRUE(str1 < str2);
    ASSERT_TRUE(str3 < str4);

    str1 = "a0000000000000000000000000000000000000000000000000";
    str2 = "z0000000000000000000000000000000000000000000000000";

    ASSERT_TRUE(str1 < str2);
}

TEST(String, OperatorGreat) 
{
    kor::String str1 {"b"};
    kor::String str2 {"a"};

    ASSERT_TRUE(str1 > str2);

    str1 = "11111111111111111111111111111111111111111111111111111111111111111111111111111";
    str2 = "11111111111111111111111111111111111111111111111111111111111111111111111111110";

    ASSERT_TRUE(str1 > str2);

    str1 = "z0000000000000000000000000000000000000000000000000";
    str2 = "a0000000000000000000000000000000000000000000000000";
    
    ASSERT_TRUE(str1 > str2);
}

TEST(String, OperatorEq) 
{
    kor::String str1 {"a"};
    kor::String str2 {"a"};

    ASSERT_TRUE(str1 == str2);

    str1 = "11111111111111111111111111111111111111111111111111111111111111111111111111111";
    str2 = "11111111111111111111111111111111111111111111111111111111111111111111111111110";

    ASSERT_TRUE(!(str1 == str2));

    str1 = "z0000000000000000000000000000000000000000000000000";
    str2 = "a0000000000000000000000000000000000000000000000000";

    ASSERT_FALSE(str1 == str2);

    str1 = "a00b0x0h0000a0000000u00y00000b0000f000000z0000000000";
    str2 = "a00b0x0h0000a0000000u00y00000b0000f000000z0000000000";
    
    ASSERT_TRUE(str1 == str2);
}