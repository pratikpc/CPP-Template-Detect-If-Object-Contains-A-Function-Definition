# Code Required

```cpp
    auto const contains_test = requires(T t)
    {
        { t.Test(1, 2) } -> std::same_as<void>;
    };
```

# In C++17

```cpp
    static constexpr auto const contains_test = static_cast<bool>(boost::hana::is_valid(
        [](auto &&obj) -> decltype(obj.Test(1, 2)) {

        })(t));
```
