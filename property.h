#pragma once

#include <functional>

template<typename T>
class Property {
public:
    inline Property(std::function<T()> getter, std::function<void(T)> setter) : getter(getter), setter(setter) {}
    inline Property& operator=(T value) { setter(value); return *this; }
    template<typename OT>
    inline operator OT() { return getter(); }
    inline T operator()() { return getter(); }
private:
    std::function<T()> getter;
    std::function<void(T)> setter;
};

template<typename T>
class Indexer {
public:
    inline Indexer(std::function<T(int)> getter, std::function<void(int, T)> setter) : getter(getter), setter(setter) {}
    inline Property<T> operator[](int index) { return Property<T>([=]() { return getter(index); }, [=](auto value) { setter(index, value); }); }
private:
    std::function<T(int)> getter;
    std::function<void(int, T)> setter;
};
