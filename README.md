# Interval_Map Class

## Overview

The `Interval_Map` class provided in the code is a C++ template class designed to represent an interval map, where each interval is associated with a value. This class allows you to assign values to intervals defined by keys and retrieve the value associated with a specific key.

## How to Use

1. **Include the Header Files:**

    ```cpp
    #include <iostream>
    #include <map>
    #include <limits>
    #include <string>
    ```

2. **Define `Interval_Map` Objects:**

    ```cpp
    // Example with TestKeyType as keys and TestValueType as values
    Interval_Map<TestKeyType, TestValueType> map{'A'};
    ```

3. **Assign Values to Intervals:**

    ```cpp
    map.assign(keyBegin, keyEnd, value);
    ```
   
   - `keyBegin` and `keyEnd` define the interval.
   - `value` is the value associated with the specified interval.

4. **Retrieve Values for a Key:**

    ```cpp
    char value = map[key];
    ```
    - Returns the value associated with the specified key.

5. **Print Interval Map:**

    ```cpp
    print_interval_map(map);
    ```
    - Displays the intervals and their associated values in the map.

6. **Example Usage:**

    ```cpp
    Interval_Map<int, char> map{'A'};
    map.assign(4, 10, 'b');
    map.assign(10, 50, 'C');
    map.assign(4, 10, 'C');
    print_interval_map(map);
    ```

## Additional Information

- The `print_interval_map` function prints the intervals and their associated values in the map.

- The code includes examples using custom key types (`TestKeyType` and `TestFloatKeyType`), demonstrating how to use different data types with the `Interval_Map` class.

- The `numeric_limits` specialization is used to handle the case where the key type does not have a well-defined "lowest" value.

## Example Output

```plaintext
4 -> b
10 -> C
---------------------------
```

## Notes

- The `Interval_Map` class utilizes `std::map` internally to store and manage the intervals and their associated values.

- Ensure that the key type used supports the comparison operators (`<`) for the proper functioning of the `Interval_Map` class.

- The code includes examples using custom key types (`TestKeyType` and `TestFloatKeyType`), demonstrating how to use different data types with the `Interval_Map` class.

- The `numeric_limits` specialization is used to handle cases where the key type does not have a well-defined "lowest" value.

- It is recommended to thoroughly test the code with different inputs to ensure correctness and suitability for your specific use case.

