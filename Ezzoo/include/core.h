#ifndef CORE_H
#define CORE_H

#define BIT(x) (1 << x)

#define EZZOO_ASSERT(x, ...)                 \
    {                                        \
        if (!(x))                            \
        {                                    \
            EZZOO_CLIENT_ERROR(__VA_ARGS__); \
            __debugbreak();                  \
        }                                    \
    }
template <typename T>
using Ref = std::shared_ptr<T>;

template <typename T, typename... ARGS>
Ref<T> createRef(ARGS &&...args)
{

    return std::make_shared<T>(std::forward<ARGS>(args)...);
}

#endif