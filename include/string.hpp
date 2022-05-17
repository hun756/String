#ifndef STRING_HPP_wt709n
#define STRING_HPP_wt709n

#include <memory>
#include <cstring>
#include <stdexcept>

#define DEFAULT_CAP 15
#define CPP_2020_OR_HIGHER 202002L
#define CPP_2017_OR_HIGHER 201703L

#ifdef ENABLE_COMPABILITY_W_STD_STRING
#include <string>
#endif

#ifdef ENABLE_COMPABILITY_W_STD_VECTOR
#include <vector>
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
    typedef long int __li;            ///< long int
}

namespace kor
{
    template <typename charType>
    class ConstIterator
    {
    public:
        /**
         *  @brief
         *      Construct a new Const Iterator object
         *
         */
        ConstIterator();

        /**
         *  @brief
         *      Construct a new Const Iterator object
         *
         */
        ConstIterator(charType *);

        /**
         *  @brief
         *      Construct a new Const Iterator object
         *
         *  @return ConstIterator&
         *      Reference an object from class iterator.
         **/
        ConstIterator &operator++();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return
         *      Ref Object from class iterator
         **/
        ConstIterator &operator++(int);

        /**
         *  @brief
         *      Overloading operator ++ (prefix)
         *
         *  @return
         *      Object from class iterator
         **/
        ConstIterator &operator--();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return
         *      Object from class iterator
         **/
        ConstIterator &operator--(int);

        /**
         *  @brief
         *      Overloading operator *
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        const charType &operator*() const;

        /**
         *  @brief
         *      Overloading operator ->
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        charType *operator->() const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator!=(const ConstIterator &) const;

        /**
         * @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator==(const ConstIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator<(const ConstIterator &) const;

        /**
         *  Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator>(const ConstIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator<=(const ConstIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator>=(const ConstIterator &) const;

    private:
        const charType *current;
    };

    template <typename charType>
    ConstIterator<charType>::ConstIterator(charType *initLock)
    {
        current = initLock;
    }

    template <typename charType>
    ConstIterator<charType> &ConstIterator<charType>::operator++()
    {
        ++current;
        return *this;
    }

    template <typename charType>
    ConstIterator<charType> &ConstIterator<charType>::operator++(int)
    {
        ConstIterator iter = *this;
        ++(*this);
        return iter;
    }

    template <typename charType>
    const charType &ConstIterator<charType>::operator*() const
    {
        return *current;
    }

    template <typename charType>
    charType *ConstIterator<charType>::operator->() const
    {
        return current;
    }

    template <typename charType>
    bool ConstIterator<charType>::operator!=(const ConstIterator &rhs) const
    {
        return current != rhs.current;
    }

    template <typename charType>
    bool ConstIterator<charType>::operator==(const ConstIterator &rhs) const
    {
        return current == rhs.current;
    }

    template <typename charType>
    bool ConstIterator<charType>::operator<(const ConstIterator &rhs) const
    {
        return current < rhs.current;
    }

    template <typename charType>
    bool ConstIterator<charType>::operator>(const ConstIterator &rhs) const
    {
        return current > rhs.current;
    }

    template <typename charType>
    bool ConstIterator<charType>::operator<=(const ConstIterator &rhs) const
    {
        return !(current > rhs.current);
    }

    template <typename charType>
    bool ConstIterator<charType>::operator>=(const ConstIterator &rhs) const
    {
        return !(current < rhs.current);
    }

    template <typename charType>
    class Iterator : public ConstIterator<charType>
    {
        using Base = ConstIterator<charType>;

    public:
        /**
         *  @brief
         *      Construct a new Iterator object
         *
         */
        Iterator();

        /**
         * @brief
         *      Construct a new Iterator object
         *
         * @param[in] initLock
         */
        Iterator(charType *initLock);

        /**
         *  @brief
         *      Overloading operator ++ (prefix)
         *
         *  @return Iterator&
         */
        Iterator &operator++();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return Iterator&
         */
        Iterator &operator++(int);

        /**
         *  @brief
         *      Overloading operator ++ (prefix)
         *
         *  @return Iterator&
         */
        Iterator &operator--();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return Iterator&
         */
        Iterator &operator--(int);

        /**
         *  @brief
         *      Overloading operator *
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        charType &operator*();

        /**
         *  @brief
         *      Overloading operator ->
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        charType *operator->();
    };

    template <typename charType>
    Iterator<charType>::Iterator(charType *initLock) : Base(initLock)
    {
    }

    template <typename charType>
    Iterator<charType> &Iterator<charType>::operator++()
    {
        Base::operator++();
        return *this;
    }

    template <typename charType>
    Iterator<charType> &Iterator<charType>::operator++(int)
    {
        Iterator iter = *this;
        Base::operator++();
        return iter;
    }

    template <typename charType>
    Iterator<charType> &Iterator<charType>::operator--()
    {
        Base::operator--();
        return *this;
    }

    template <typename charType>
    Iterator<charType> &Iterator<charType>::operator--(int)
    {
        Iterator iter = *this;
        Base::operator--();
        return iter;
    }

    template <typename charType>
    charType &Iterator<charType>::operator*()
    {
        return const_cast<charType &>(Base::operator*());
    }

    template <typename charType>
    charType *Iterator<charType>::operator->()
    {
        return const_cast<charType *>(Base::operator->());
    }

    template <typename charType>
    class ConstReverseIterator
    {
    public:
        ConstReverseIterator();

        /**
         *  @brief
         *      Construct a new Const Reverse Iterator object.
         *
         * @param[in] initLock
         **/
        ConstReverseIterator(charType *);

        /**
         *  @brief
         *      Overloading operator ++ (prefix).
         *
         *  @return ConstReverseIterator&
         **/
        ConstReverseIterator &operator++();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return ConstReverseIterator&
         **/
        ConstReverseIterator &operator++(int);

        /**
         *  @brief
         *      Overloading operator ++ (prefix)
         *
         *  @return ConstReverseIterator&
         **/
        ConstReverseIterator &operator--();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return ConstReverseIterator&
         **/
        ConstReverseIterator &operator--(int);

        /**
         *  @brief
         *      Overloading operator *
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        const charType &operator*() const;

        /**
         *  @brief
         *      overloading operator ->
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        charType *operator->() const;

        /**
         *  @brief
         *
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator!=(const ConstReverseIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator==(const ConstReverseIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator<(const ConstReverseIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator>(const ConstReverseIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @retval
         *      !(current == rhs.current)
         **/
        bool operator<=(const ConstReverseIterator &) const;

        /**
         *  @brief
         *      Overloading operator !=
         *
         *  @param[in] rhs
         *
         *  @return
         *      !(current == rhs.current)
         **/
        bool operator>=(const ConstReverseIterator &) const;

    private:
        const charType *current;
    };

    // implementation from ConstReverseIterator
    template <typename charType>
    ConstReverseIterator<charType>::ConstReverseIterator() : current(nullptr)
    {
    }

    template <typename charType>
    ConstReverseIterator<charType>::ConstReverseIterator(charType *initLock)
    {
        current = initLock;
    }

    template <typename charType>
    ConstReverseIterator<charType> &ConstReverseIterator<charType>::operator++()
    {
        --current;
        return *this;
    }

    template <typename charType>
    ConstReverseIterator<charType> &ConstReverseIterator<charType>::operator++(int)
    {
        ConstReverseIterator iter = *this;
        --(*this);
        return iter;
    }

    template <typename charType>
    ConstReverseIterator<charType> &ConstReverseIterator<charType>::operator--()
    {
        ++current;
        return *this;
    }

    template <typename charType>
    ConstReverseIterator<charType> &ConstReverseIterator<charType>::operator--(int)
    {
        ConstReverseIterator iter = *this;
        ++(*this);
        return iter;
    }

    template <typename charType>
    const charType &ConstReverseIterator<charType>::operator*() const
    {
        return *current;
    }

    template <typename charType>
    charType *ConstReverseIterator<charType>::operator->() const
    {
        return current;
    }

    template <typename charType>
    bool ConstReverseIterator<charType>::operator!=(const ConstReverseIterator &rhs) const
    {
        return current != rhs.current;
    }

    template <typename charType>
    bool ConstReverseIterator<charType>::operator==(const ConstReverseIterator &rhs) const
    {
        return current == rhs.current;
    }

    template <typename charType>
    bool ConstReverseIterator<charType>::operator<(const ConstReverseIterator &rhs) const
    {
        return current < rhs.current;
    }

    template <typename charType>
    bool ConstReverseIterator<charType>::operator>(const ConstReverseIterator &rhs) const
    {
        return current > rhs.current;
    }

    template <typename charType>
    bool ConstReverseIterator<charType>::operator<=(const ConstReverseIterator &rhs) const
    {
        return !(current > rhs.current);
    }

    template <typename charType>
    bool ConstReverseIterator<charType>::operator>=(const ConstReverseIterator &rhs) const
    {
        return !(current < rhs.current);
    }

    // implementation end : ConstReverseIterator

    template <typename charType>
    class ReverseIterator : public ConstReverseIterator<charType>
    {
    public:
        using Base = ConstReverseIterator<charType>;

    public:
        /**
         *  @brief
         *      Construct a new Reverse Iterator object
         *
         **/
        ReverseIterator();

        /**
         *  @brief
         *      Construct a new Reverse Iterator object
         *
         *  @param[in]  T*
         **/
        ReverseIterator(charType *);

        /**
         *  @brief
         *      Overloading operator ++ (prefix)
         *
         *  @return ReverseIterator&
         **/
        ReverseIterator &operator++();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return ReverseIterator&
         **/
        ReverseIterator &operator++(int);

        /**
         *  @brief
         *      Overloading operator ++ (prefix)
         *
         *  @return ReverseIterator&
         **/
        ReverseIterator &operator--();

        /**
         *  @brief
         *      Overloading operator ++ (postfix)
         *
         *  @return ReverseIterator&
         **/
        ReverseIterator &operator--(int);

        /**
         *  @brief
         *      Overloading operator *
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        charType &operator*();

        /**
         * @brief
         *      Overloading operator *
         *
         *  @return T&
         *      Adress of template value. Return this value of adress.
         **/
        charType *operator->();
    };

    // implementation from ReverseIterator

    template <typename charType>
    ReverseIterator<charType>::ReverseIterator(charType *initLock) : Base(initLock)
    {
    }

    template <typename charType>
    ReverseIterator<charType> &ReverseIterator<charType>::operator++()
    {
        Base::operator++();
        return *this;
    }

    template <typename charType>
    ReverseIterator<charType> &ReverseIterator<charType>::operator++(int)
    {
        ReverseIterator iter = *this;
        Base::operator++();
        return iter;
    }

    template <typename charType>
    ReverseIterator<charType> &ReverseIterator<charType>::operator--()
    {
        Base::operator--();
        return *this;
    }

    template <typename charType>
    ReverseIterator<charType> &ReverseIterator<charType>::operator--(int)
    {
        ReverseIterator iter = *this;
        Base::operator--();
        return iter;
    }

    template <typename charType>
    charType &ReverseIterator<charType>::operator*()
    {
        return const_cast<charType &>(Base::operator*());
    }

    template <typename charType>
    charType *ReverseIterator<charType>::operator->()
    {
        return const_cast<charType *>(Base::operator->());
    }

}

namespace kor
{
    template <typename charType>
    class StringBase
    {
    public:
        static_assert(kor::is_char<charType>, "String class works only with char");

        using reference = charType &;
        using pointer_type = charType *;
        using iterator = kor::Iterator<charType>;
        using const_iterator = kor::ConstIterator<charType>;
        using reverse_iterator = kor::ReverseIterator<charType>;
        using const_reverse_iterator = kor::ConstReverseIterator<charType>;
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

        operator const char *() const noexcept
        {
            return this->_data.get();
        }

#ifdef ENABLE_COMPABILITY_W_STD_STRING
        operator std::string() const
        {
            return std::string(_data.get());
        }
#endif

#ifdef ENABLE_COMPABILITY_W_STD_VECTOR
        template <typename U>
        operator std::vector<U>() const noexcept
        {
            static_assert(kor::is_char<U>, "Vector convension works only with char");
            return std::vector<U>(&_data.get()[0], &_data.get()[_size]);
        }
#endif
        /**
         * @brief
         *
         * @return std::unique_ptr<charType[]>
         */
        std::unique_ptr<charType[]> toCharArray()
        {
            std::unique_ptr<charType[]> _newCh = std::make_unique<charType[]>(_size + 1);

            for (size_t i = 0; i < _size; ++i)
            {
                _newCh[i] = _data[i];
            }

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

        /**
         *  @brief
         *      This method  a pointer that returns the starting point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::iterator begin()
        {
            return iterator(&_data.get()[0]);
        }

        /**
         *  @brief
         *      This method a pointer that returns the ending point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::iterator end()
        {
            return iterator(&_data.get()[_size]);
        }

        /**
         *  @brief
         *      This method a const pointer that returns the ending
         *      point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::const_iterator begin() const
        {
            return const_iterator(&_data.get()[0]);
        }

        /**
         *  @brief
         *      This method a const pointer that returns the ending
         *      point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::const_iterator end() const
        {
            return const_iterator(&_data.get()[_size]);
        }

        /**
         *  @brief
         *      This method  a pointer that returns the ending point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::reverse_iterator rbegin()
        {
            return reverse_iterator(&_data.get()[_size - 1]);
        }

        /**
         *  @brief
         *      This method a pointer that returns the starting point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::reverse_iterator rend()
        {
            return reverse_iterator(&_data.get()[0 - 1]);
        }

        /**
         *  @brief
         *      This method a const pointer that returns the ending
         *      point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(&_data.get()[_size - 1]);
        }

        /**
         *  @brief
         *      This method a const pointer that returns the starting
         *      point of the string.
         *
         *  @return
         *      object from class Iterator
         **/
        template <typename U = charType>
        typename StringBase<U>::const_reverse_iterator rend() const
        {
            return const_reverse_iterator(&_data.get()[0 - 1]);
        }

        /**
         *  @brief
         *      This method takes the desired array element as a parameter.
         *
         *  @param[in]
         *      It is the index of the directory to be accessed.
         *
         *  @return
         *      T&  reference from template
         **/
        charType &at(std::size_t index)
        {
            return (*this)[index];
        }

        const charType &at(std::size_t index) const
        {
            return (*this)[index];
        }

        /**
         * @brief
         *  Appends the given string to this string.
         *
         * @param rhs
         *  The value to add to the string.
         *
         * @return StringBase&
         *  Returns the class's own reference.
         */
        StringBase &append(const StringBase &rhs)
        {
            (*this) += rhs;
            return *this;
        }

        StringBase &append(const char *rhs)
        {
            if (rhs)
                (*this) += rhs;

            return *this;
        }

        StringBase &append(char ch)
        {
            (*this) += ch;
            return *this;
        }

        /**
         * @brief
         *  Assigns a new value to the string, replacing its current contents.
         *
         * @param rhs
         *  Another string object, whose value is either copied or moved.
         *
         * @return StringBase&
         */
        StringBase &assign(const StringBase &rhs)
        {
            (*this) = rhs;
            return *this;
        }

        StringBase &assign(const char *rhs)
        {
            if (rhs)
                (*this) = rhs;

            return *this;
        }

        StringBase &assign(StringBase &&rhs) noexcept
        {
            (*this) = std::move(rhs);
            return *this;
        }

        void swap(StringBase &str)
        {
            std::swap(_capacity, str._capacity);
            std::swap(_size, str._size);
            std::swap(_data, str._data);
        }

        ///< Overloading operators ...!

        StringBase &operator=(const StringBase &rhs);
        StringBase &operator=(StringBase &&rhs) noexcept;
        StringBase &operator=(const charType *rhs);
        StringBase &operator=(charType rhs);
        StringBase &operator+=(const StringBase &rhs);
        StringBase &operator+=(const charType *rhs);
        StringBase &operator+=(charType rhs);
        charType &operator[](std::size_t idx);
        const charType &operator[](std::size_t idx) const;

        template <charType>
        friend std::ostream &operator<<(std::ostream &os, const StringBase &str);

        template <charType>
        friend StringBase operator+(const StringBase &lhs, const StringBase &rhs);

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend StringBase operator+(const StringBase &lhs, const charType *rhs);

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend StringBase operator+(const charType *lhs, const StringBase &rhs);
        template <charType>
        friend StringBase operator+(const StringBase &lhs, charType rhs);
        template <charType>
        friend StringBase operator+(charType lhs, const StringBase &rhs);
        template <charType>
        friend bool operator==(const StringBase &lhs, const StringBase &rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator==(const StringBase &lhs, const charType *rhs) noexcept;
        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator==(const charType *lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator==(const StringBase &lhs, charType rhs) noexcept;
        template <charType>
        friend bool operator==(charType lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator!=(const StringBase &lhs, const StringBase &rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator!=(const StringBase &lhs, const charType *rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator!=(const charType *lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator!=(const StringBase &lhs, charType rhs) noexcept;
        template <charType>
        friend bool operator!=(charType lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator<(const StringBase &lhs, const StringBase &rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator<(const StringBase &lhs, const charType *rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator<(const charType *lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator<(const StringBase &lhs, charType rhs) noexcept;
        template <charType>
        friend bool operator<(charType lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator>(const StringBase &lhs, const StringBase &rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator>(const StringBase &lhs, const charType *rhs) noexcept;

        /**
         * @todo
         *  Fix it : Undefined behavior if lhs is nullptr.
         */
        template <charType>
        friend bool operator>(const charType *lhs, const StringBase &rhs) noexcept;
        template <charType>
        friend bool operator>(const StringBase &lhs, charType rhs) noexcept;
        template <charType>
        friend bool operator>(charType lhs, const StringBase &rhs) noexcept;

    private:
        void reAlloc()
        {
            std::unique_ptr<char[]> temp = std::make_unique<char[]>(_capacity + 1);
            std::memcpy(temp.get(), _data.get(), _size);
            _data = std::move(temp);
        }

        void _h_allocate_len_control()
        {
            if (_size <= DEFAULT_CAP)
                _capacity = DEFAULT_CAP;
            else if (_size <= DEFAULT_CAP * 2)
                _capacity = DEFAULT_CAP * 2;
            else
                _capacity = _size;
        }

    private:
        std::unique_ptr<charType[]> _data;
        size_t _capacity;
        size_t _size;
    };

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator=(const StringBase<charType> &rhs)
    {
        if (this != &rhs)
        {
            if (_capacity < rhs._size)
            {
                _capacity = rhs._capacity;
                _data = std::make_unique<char[]>(_capacity + 1);
            }

            _size = rhs._size;
            std::memcpy(_data.get(), rhs.c_str(), rhs._size + 1);
        }

        return *this;
    }

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator=(StringBase<charType> &&rhs) noexcept
    {
        _capacity = rhs._capacity;
        _size = rhs._size;
        _data = std::move(rhs._data);
        return *this;
    }

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator=(const charType *rhs)
    {
        _size = std::strlen(rhs);

        _h_allocate_len_control();

        _data = std::make_unique<char[]>(_capacity + 1);
        std::memcpy(_data.get(), rhs, _size + 1);
        return *this;
    }

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator=(charType rhs)
    {
        _size = 1;
        _capacity = DEFAULT_CAP;
        _data = std::make_unique<char[]>(_capacity + 1);
        _data.get()[0] = rhs;
        _data.get()[1] = 0x00;
        return *this;
    }

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator+=(const StringBase<charType> &rhs)
    {
        auto tempSize = _size;
        _size += rhs._size;

        _h_allocate_len_control();

        if (_size < DEFAULT_CAP * 2)
            reAlloc();

        std::memcpy(_data.get() + tempSize, rhs.c_str(), rhs._size + 1);
        return *this;
    }

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator+=(const charType *rhs)
    {

        auto tempSize = _size;
        auto rhsSize = std::strlen(rhs);
        _size += rhsSize;

        _h_allocate_len_control();

        if (_size < DEFAULT_CAP * 2)
            reAlloc();

        std::memcpy(_data.get() + tempSize, rhs, rhsSize + 1);
        return *this;
    }

    template <typename charType>
    StringBase<charType> &StringBase<charType>::operator+=(charType rhs)
    {
        auto tempSize = _size;
        _size += 1;

        _h_allocate_len_control();

        if (_size < DEFAULT_CAP * 2)
            reAlloc();

        _data.get()[tempSize] = rhs;
        _data.get()[_size] = 0x00;

        return *this;
    }

    template <typename charType>
    charType &StringBase<charType>::operator[](std::size_t index)
    {
        if (static_cast<__li>(index) < 0 || index >= _size)
            throw std::out_of_range{"Error..! The index you want to reach is exceed the bounds of the array."};

        return _data.get()[index];
    }

    template <typename charType>
    const charType &StringBase<charType>::operator[](std::size_t index) const
    {
        if (static_cast<__li>(index) < 0 || index >= _size)
            throw std::out_of_range{"Error..! The index you want to reach is exceed the bounds of the array."};

        return _data.get()[index];
    }

    template <typename charType>
    std::ostream &operator<<(std::ostream &os, const StringBase<charType> &str)
    {
        if (str.size() > 0)
        {
#if __cplusplus < CPP_2017_OR_HIGHER
            os.write(str.c_str(), static_cast<typename kor::StringBase<charType>::difference_type>(str.size()));
#else
            os << str.c_str();
#endif
        }
        return os;
    }

    template <typename charType>
    StringBase<charType> operator+(const StringBase<charType> &lhs, const StringBase<charType> &rhs)
    {
        StringBase temp{lhs};
        temp += rhs;
        return temp;
    }

    template <typename charType>
    StringBase<charType> operator+(const StringBase<charType> &lhs, const charType *rhs)
    {
        StringBase temp{lhs};
        temp += rhs;
        return temp;
    }

    template <typename charType>
    StringBase<charType> operator+(const charType *lhs, const StringBase<charType> &rhs)
    {
        StringBase temp{lhs};
        temp += rhs;
        return temp;
    }

    template <typename charType>
    StringBase<charType> operator+(const StringBase<charType> &lhs, charType rhs)
    {
        StringBase temp{lhs};
        temp += rhs;
        return temp;
    }

    template <typename charType>
    StringBase<charType> operator+(charType lhs, const StringBase<charType> &rhs)
    {
        StringBase temp{lhs};
        temp += rhs;
        return temp;
    }

    template <typename charType>
    bool operator==(const StringBase<charType> &lhs, const StringBase<charType> &rhs) noexcept
    {
        ///< first check length equality..!
        if (lhs._size != rhs._size)
        {
            return false;
        }

        ///< Compare string
        const char *lhsStr = lhs.c_str();
        const char *rhsStr = rhs.c_str();

        return strcmp(lhsStr, rhsStr) == 0;
    }

    template <typename charType>
    bool operator==(const StringBase<charType> &lhs, const charType *rhs) noexcept
    {
        ///< first check length equality..!
        const std::size_t rhsSize = std::strlen(rhs);
        if (lhs._size != rhsSize)
        {
            return false;
        }

        ///< Compare string
        const char *lhsStr = lhs.c_str();

        return strcmp(lhsStr, rhs) == 0;
    }

    template <typename charType>
    bool operator==(const charType *lhs, const StringBase<charType> &rhs) noexcept
    {
        ///< first check length equality..!
        const std::size_t lhsSize = std::strlen(lhs);
        if (lhsSize != rhs._size)
        {
            return false;
        }

        ///< Compare string
        const char *rhsStr = rhs.c_str();

        return strcmp(rhsStr, lhs) == 0;
    }

    template <typename charType>
    bool operator==(const StringBase<charType> &lhs, charType rhs) noexcept
    {
        return lhs._size == 1 && lhs.c_str()[0] == rhs;
    }

    template <typename charType>
    bool operator==(charType lhs, const StringBase<charType> &rhs) noexcept
    {
        return rhs._size == 1 && lhs == rhs.c_str()[0];
    }

    template <typename charType>
    bool operator!=(const StringBase<charType> &lhs, const StringBase<charType> &rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename charType>
    bool operator!=(const StringBase<charType> &lhs, const charType *rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename charType>
    bool operator!=(const charType *lhs, const StringBase<charType> &rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename charType>
    bool operator!=(const StringBase<charType> &lhs, charType rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename charType>
    bool operator!=(charType lhs, const StringBase<charType> &rhs) noexcept
    {
        return !(lhs == rhs);
    }

    template <typename charType>
    bool operator<(const StringBase<charType> &lhs, const StringBase<charType> &rhs) noexcept
    {
        const size_t loopRange = (lhs._size < rhs._size) ? lhs._size : rhs._size;

        const char *lhsStr = lhs.c_str();
        const char *rhsStr = rhs.c_str();

        for (size_t i{0}; i < loopRange; ++i)
        {
            if (lhsStr[i] < rhsStr[i])
                return true;
            else if (lhsStr[i] > rhsStr[i])
                return false;
        }

        if (lhs._size >= rhs._size)
            return false;

        return true;
    }

    template <typename charType>
    bool operator<(const StringBase<charType> &lhs, const charType *rhs) noexcept
    {
        const size_t rhsSize = std::strlen(rhs);
        const size_t loopRange = (lhs._size < rhsSize) ? lhs._size : rhsSize;
        const char *lhsStr = lhs.c_str();

        for (std::size_t i{0}; i < loopRange; ++i)
        {
            if (lhsStr[i] < rhs[i])
                return true;
            else if (lhsStr[i] > rhs[i])
                return false;
        }

        if (lhs._size >= rhsSize)
            return false;

        return true;
    }

    template <typename charType>
    bool operator<(const charType *lhs, const StringBase<charType> &rhs) noexcept
    {
        const std::size_t lhsSize = std::strlen(lhs);
        const std::size_t loopRange = (lhsSize < rhs._size) ? lhsSize : rhs._size;
        const char *rhsStr = rhs.c_str();

        for (std::size_t i{0}; i < loopRange; ++i)
        {
            if (lhs[i] < rhsStr[i])
                return true;
            else if (lhs[i] > rhsStr[i])
                return false;
        }

        if (lhsSize >= rhs._size)
            return false;

        return true;
    }

    template <typename charType>
    bool operator<(const StringBase<charType> &lhs, charType rhs) noexcept
    {
        if ((lhs._size == 0) || (lhs.c_str()[0] < rhs))
            return true;

        return false;
    }

    template <typename charType>
    bool operator<(charType lhs, const StringBase<charType> &rhs) noexcept
    {
        if ((rhs._size > 0) && (lhs < rhs.c_str()[0]))
            return true;

        return false;
    }

    template <typename charType>
    bool operator>(const StringBase<charType> &lhs, const StringBase<charType> &rhs) noexcept
    {
        return lhs != rhs && !(lhs < rhs);
    }

    template <typename charType>
    bool operator>(const StringBase<charType> &lhs, const charType *rhs) noexcept
    {
        return lhs != rhs && !(lhs < rhs);
    }

    template <typename charType>
    bool operator>(const charType *lhs, const StringBase<charType> &rhs) noexcept
    {
        return lhs != rhs && !(lhs < rhs);
    }

    template <typename charType>
    bool operator>(const StringBase<charType> &lhs, charType rhs) noexcept
    {
        return lhs != rhs && !(lhs < rhs);
    }

    template <typename charType>
    bool operator>(charType lhs, const StringBase<charType> &rhs) noexcept
    {
        return lhs != rhs && !(lhs < rhs);
    }

    using String = StringBase<char>;
    using WString = StringBase<wchar_t>;
}

#endif /** End of include guard : STRING_HPP_wt709n */