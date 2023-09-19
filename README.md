# Code Required

```cpp
    auto const contains_test = requires(T t)
    {
        { t.Test(1, 2) } -> std::same_as<void>;
    };
```