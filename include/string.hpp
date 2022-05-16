#ifndef STRING_HPP_wt709n
#define STRING_HPP_wt709n

#include <memory>
#include <cstring>

#define DEFAULT_CAP 15
#define CPP_2020_OR_HIGHER 202002L
#define CPP_2017_OR_HIGHER 201703L

#ifdef ENABLE_COMPABILITY_W_STD_STRING
#include <string>
#endif

namespace kor
{
    template <class T>
    struct tag_t
    {
    };

    template <typename T>
    constexpr tag_t<T> tag{};

    template <typename T, typename... Ts>
    constexpr bool _is_char_(tag_t<T>, Ts &&...) { return false; }
    constexpr bool _is_char_(tag_t<char>) { return true; }

#if __cplusplus >= CPP_2020_OR_HIGHER
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
    typedef unsigned __u;             ///< unsigned (int)
    typedef unsigned short __us;      ///< unsigned (int16_t)
    typedef unsigned long __ul;       ///< unsigned long
    typedef unsigned long long __ull; ///< unsigned long long
    typedef long long __ll;           ///< long long
    typedef long double __ld;         ///< long double
}

namespace kor
{
    template <typename charType>
    class ConstIterator
    {
    };

    template <typename charType>
    class Iterator : public ConstIterator<charType>
    {
    };
}

namespace kor
{
    template <typename charType>
    class StringBase
    {
        static_assert(kor::is_char<charType>, "String class works only with char");

        using reference = charType &;
        using pointer_type = charType *;
        using iterator = kor::Iterator<charType>;
        using const_iterator = kor::ConstIterator<charType>;
        using difference_type = ptrdiff_t;

    public:
        static constexpr size_t npos = -1;

        ///< Life Time Management

#if __GNUC__ || __MINGW32__ || __MINGW64__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
#endif
        /**
         * @brief Construct a new String object
         *
         */
        StringBase() : _capacity(DEFAULT_CAP), _size{0}
        {
            _data = std::make_unique<charType[]>(_capacity + 1);
            _data[0] = 0x00;
        }

        /**
         * @brief Construct a new String object
         *  Fix undefined behaviour to pass null_datat to char*
         *
         * @param nptr
         */
        StringBase(std::nullptr_t n)
        {
        }

        /**
         * @brief Construct a new String object
         *
         * @param _cap
         */
        StringBase(__u _cap)
            : _size(0), _capacity(_cap)
        {
            _data = std::make_unique<charType[]>(_capacity + 1);
            _data[0] = 0x00;
        }

        /**
         * @brief Construct a new String object
         *
         * @param cStr
         */
        StringBase(const charType *cStr)
            : _size(std::strlen(cStr))

        {
            _capacity = _size <= 15 ? DEFAULT_CAP : _size;
            _data = std::make_unique<charType[]>(_capacity + 1);
            std::memcpy(_data.get(), cStr, _size + 1);
        }

        /**
         * @brief Construct a new String object
         *
         * @param other
         */
        StringBase(const StringBase &other)
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
        StringBase(StringBase &&other) noexcept
            : _capacity{other._capacity}, _size{other._size}
        {
            _data = std::move(other._data);
        }

#if __GNUC__ || __MINGW32__ || __MINGW64__
#pragma GCC diagnostic pop
#endif
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
        std::unique_ptr<charType[]> _data;
        size_t _capacity;
        size_t _size;
    };

    using String = StringBase<char>;
    using WString = StringBase<wchar_t>;
}

#endif /** End of include guard : STRING_HPP_wt709n */