# Lambda Func and Custom Sort

To understand how custom sorting works in C++, we need to look at two powerful tools: **`std::sort`** (the engine) and the **lambda function** (the steering wheel).

Here is a breakdown of how they work individually and how they team up to sort data exactly how you want.

---

## 1. What is `std::sort`?

`std::sort` is a highly optimized built-in function from the C++ Standard Library (`<algorithm>`).

Under the hood, it doesn't just use a single sorting algorithm. It uses a hybrid algorithm called **Introsort**. Introsort is a "best of all worlds" approach that keeps your code running at maximum speed ($O(N \log N)$ time complexity):

1. It starts with **Quicksort** because it is incredibly fast in practice.

2. If the recursion depth goes too deep (meaning Quicksort hit a worst-case scenario), it automatically switches to **Heapsort** to guarantee performance.

3. For very small sub-arrays, it switches to **Insertion Sort** because it has very low overhead for a handful of elements.

By default, if you just give `std::sort` a starting point and an ending point, it will sort elements in **ascending order** using the standard `<` (less-than) operator.

```cpp
std::vector<int> numbers = {5, 1, 4, 2};
std::sort(numbers.begin(), numbers.end()); 
// Result: {1, 2, 4, 5}

```

---

## 2. What is a Custom Lambda Function?

A lambda function is simply an **anonymous function** (a function without a name) that you can write directly inside your code, right where you need it.

Instead of writing a completely separate function somewhere else in your file, you can pass a lambda directly as an argument to `std::sort`.

Here is the anatomy of a C++ lambda function:

```text
       [capture clause] (parameters) -> return_type { body }
              │               │             │          │
    Allows lambda to see    What it      Optional     The actual
    variables outside it    receives     return type     code

```

### Breakdown of the Syntax:

* **Capture Clause `[]**`: This tells the lambda what variables from the surrounding code it is allowed to "see" and use inside its body.
* `[&weights]` means "let this lambda access the `weights` array by reference."
* `[=]` means "make a copy of all local variables for the lambda to use."


* **Parameters `(...)**`: Just like a normal function, this defines the inputs. For sorting, it will always take two elements of the array to compare against each other (e.g., `char a, char b` or `int a, int b`).
* **Body `{...}**`: The logic that returns `true` or `false`.

---

## 3. How they work together: The Comparator

When you pass a lambda to `std::sort`, you are defining a **Strict Weak Ordering** rule. Think of `std::sort` as a supervisor asking your lambda a series of yes-or-no questions about elements in the array.

`std::sort` will pick two elements from your string/array, let's call them element `a` and element `b`, and pass them to your lambda.

> **The Golden Rule of `std::sort`:** > Your lambda must return `true` if element `a` should come **BEFORE** element `b` in the final sorted result. Otherwise, it must return `false`.

### Step-by-Step Visualization

Imagine we want to sort the string `"ba"` using a custom mapping where `b` has a weight of `3` and `a` has a weight of `2` (meaning `a` should come first because it has a smaller weight).

```cpp
std::sort(str.begin(), str.end(), [&weights](char a, char b) {
    return weights[a] < weights[b]; 
});

```

1. `std::sort` grabs two characters from the string: `a = 'b'` and `b = 'a'`.
2. It plugs them into your lambda.
3. The lambda looks up their weights:
* `weights['b']` is `3`
* `weights['a']` is `2`


4. The lambda evaluates the return statement: `return 3 < 2;` which is **`false`**.
5. Because it returned `false`, `std::sort` realizes that `'b'` does *not* belong before `'a'`.
6. `std::sort` swaps them, placing `'a'` before `'b'`.
