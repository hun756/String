#ifndef STRING_HPP
#define STRING_HPP

#include <type_traits>
#include <memory>
#include <cstring>

#define DEFAULT_CAP 15

#ifdef ENABLE_COMPABILITY_W_STD_STRING
#include <string>
#endif

template <class T>
struct tag_t
{
};
template <typename T>
constexpr tag_t<T> tag{};
namespace kor
{
    template <typename T, typename... Ts>
    constexpr bool _is_char_(tag_t<T>, Ts &&...) { return false; }
    constexpr bool _is_char_(tag_t<char>) { return true; }

#if __cplusplus >= 202002L
    constexpr bool _is_char_(tag_t<char_8t>)
    {
        return true;
    }
#endif

    constexpr bool _is_char_(tag_t<char16_t>)
    {
        return true;
    }
    constexpr bool _is_char_(tag_t<char32_t>) { return true; }
    constexpr bool _is_char_(tag_t<wchar_t>) { return true; }

    template <typename T>
    constexpr bool is_char = _is_char_(tag<T>);
}

namespace kor
{
    template <typename charType>
    class String
    {
        static_assert(kor::is_char<charType>, "String class works only with char");

    public:
        static constexpr size_t npos = -1;

        ///< Life Time Management

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
        /**
         * @brief Construct a new String object
         *
         */
        String() : _capacity(DEFAULT_CAP), _size{0}
        {
            _data = std::make_unique<charType[]>(_capacity + 1);
            _data[0] = '\0';
        }

        /**
         * @brief Construct a new String object
         *  Fix undefined behaviour to pass nullptr_t to char*
         *
         * @param nptr
         */
        String(std::nullptr_t n)
        {
        }

        /**
         * @brief Construct a new String object
         *
         * @param cStr
         */
        String(const char *cStr)
            :  _size(std::strlen(cStr))
               
        {
            _capacity = _size <= 15 ? DEFAULT_CAP : _size;
            _data= std::make_unique<charType[]>(_capacity + 1);
            std::memcpy(_data.get(), cStr, _size + 1);
        }

        /**
         * @brief Construct a new String object
         * 
         * @param other 
         */
        String(const String &other)
        {
            _capacity = other._capacity;
            _size = other._size;
            _data = std::make_unique<char[]>(_capacity + 1);
            std::memcpy(_data.get(), other._data.get(), other._size + 1); 
        }

        /**
         * @brief Construct a new String object
         * 
         * @param other 
         */
        String(String &&other) noexcept
            :  _capacity{other._capacity}, _size{other._size}
        {
           _data = std::move(other._data);
        }

#pragma GCC diagnostic pop

        /**
         * @brief
         *
         * @return std::unique_ptr<charType[]>
         */
        std::unique_ptr<charType[]> toCharArray()
        {
            std::unique_ptr<charType[]> _newCh = std::move(_data);
            return _newCh;
        }

        /**
         * @brief
         *
         * @return charType*
         */
        charType *c_str() const { return _data.get(); }

        /**
         * @brief 
         * 
         * @return size_t 
         */
        size_t capacity() const { return _capacity; }

        /**
         * @brief 
         * 
         * @return size_t 
         */
        size_t size() const { return _size; }

        /**
         * @brief 
         * 
         * @return size_t 
         */
        size_t length() const { return _size; }

        /**
         * @brief 
         * 
         * @return size_t 
         */
        size_t empty() const { return _size == 0; }

    private:
    private:
        std::unique_ptr<charType[]> _data;
        size_t _capacity;
        size_t _size;
    };
}

#endif