Here is the formatted content from the PDF. I have cleaned up the layout, fixed the code blocks that were split across pages, and organized the sections for better readability while ensuring all the key information, warnings, and best practices are included.

````markdown:introduction to std::string:introduction_std_string.md
# 5.7 — Introduction to std::string

In lesson 5.2 -- Literals, we introduced C-style string literals:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, world!"; // "Hello world!" is a C-style string literal.
    return 0;
}
````

While C-style string literals are fine to use, C-style string variables behave oddly, are hard to work with (e.g., you can't use assignment to assign a C-style string variable a new value), and are dangerous (e.g., if you copy a larger C-style string into the space allocated for a shorter C-style string, undefined behavior will result). In modern C++, C-style string variables are best avoided.

Fortunately, C++ has introduced two additional string types into the language that are much easier and safer to work with: `std::string` and `std::string_view` (C++17). Unlike the types we've introduced previously, `std::string` and `std::string_view` aren't fundamental types (they're class types, which we'll cover in the future). However, basic usage of each is straightforward and useful enough that we'll introduce them here.

## Introducing std::string

The easiest way to work with strings and string objects in C++ is via the `std::string` type, which lives in the `<string>` header.

We can create objects of type `std::string` just like other objects:

```cpp
#include <string> // allows use of std::string

int main()
{
    std::string name {}; // empty string
    return 0;
}
```

Just like normal variables, you can initialize or assign values to `std::string` objects as you would expect:

```cpp
#include <string>

int main()
{
    std::string name { "Alex" }; // initialize name with string literal "Alex"
    name = "John";               // change name to "John"

    return 0;
}
```

Note that strings can be composed of numeric characters as well:

```cpp
std::string myID{ "45" }; // "45" is not the same as integer 45!
```

In string form, numbers are treated as text, not as numbers, and thus they cannot be manipulated as numbers (e.g., you can't multiply them). C++ will not automatically convert strings to integer or floating-point values or vice-versa (though there are ways to do so that we'll cover in a future lesson).

## String output with std::cout

`std::string` objects can be output as expected using `std::cout`:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name { "Alex" };
    std::cout << "My name is: " << name << '\n';

    return 0;
}
```

**Output:**

```
My name is: Alex
```

Empty strings will print nothing:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string empty{ };
    std::cout << '[' << empty << ']';

    return 0;
}
```

**Output:**

```
[]
```

## std::string can handle strings of different lengths

One of the neatest things that `std::string` can do is store strings of different lengths:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name { "Alex" }; // initialize name with string literal "Alex"
    std::cout << name << '\n';

    name = "Jason"; // change name to a longer string
    std::cout << name << '\n';

    name = "Jay";   // change name to a shorter string
    std::cout << name << '\n';

    return 0;
}
```

**Output:**

```
Alex
Jason
Jay
```

In the above example, `name` is initialized with the string "Alex", which contains five characters (four explicit characters and a null-terminator). We then set `name` to a larger string, and then a smaller string. `std::string` has no problem handling this\! You can even store really long strings in a `std::string`. This is one of the reasons that `std::string` is so powerful.

> **Key insight**
>
> If `std::string` doesn't have enough memory to store a string, it will request additional memory (at runtime) using a form of memory allocation known as **dynamic memory allocation**. This ability to acquire additional memory is part of what makes `std::string` so flexible, but also comparatively slow.

## String input with std::cin

Using `std::string` with `std::cin` may yield some surprises\! Consider the following example:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::cin >> color;

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}
```

**Sample run:**

```
Enter your full name: John Doe
Enter your favorite color: Your name is John and your favorite color is Doe
```

**What happened?**
It turns out that when using `operator>>` to extract a string from `std::cin`, `operator>>` only returns characters **up to the first whitespace it encounters**. Any other characters are left inside `std::cin`, waiting for the next extraction.

So when we used `operator>>` to extract input into variable `name`, only "John" was extracted, leaving " Doe" inside `std::cin`. When we then used `operator>>` to extract input into variable `color`, it extracted "Doe" instead of waiting for us to input a color. Then the program ends.

## Use std::getline() to input text

To read a full line of input into a string, you're better off using the `std::getline()` function instead. `std::getline()` requires two arguments: the first is `std::cin`, and the second is your string variable.

Here's the same program as above using `std::getline()`:

```cpp
#include <iostream>
#include <string> // For std::string and std::getline

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}
```

**Output:**

```
Enter your full name: John Doe
Enter your favorite color: blue
Your name is John Doe and your favorite color is blue
```

### What the heck is std::ws?

C++ supports **input manipulators**, which alter the way that input is accepted. The `std::ws` input manipulator tells `std::cin` to **ignore any leading whitespace before extraction**. Leading whitespace is any whitespace character (spaces, tabs, newlines) that occur at the start of the string.

Let's explore why this is useful. Consider the following program **without** `std::ws`:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin, name); // note: no std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}
```

**Output:**

```
Pick 1 or 2: 2
Now enter your name: Hello, , you picked 2
```

**The Issue:**
When you enter a value using `operator>>`, `std::cin` captures the value but **leaves the newline character ('\\n')** from the enter key in the buffer. So when `std::getline()` goes to extract text to `name`, it sees `\n` is already waiting in `std::cin`, and figures we must have previously entered an empty string\!

By adding `std::ws`, we tell `std::getline()` to ignore any leading whitespace (including that leftover newline).

```cpp
std::getline(std::cin >> std::ws, name); // note: added std::ws here
```

> **Best practice**
>
> If using `std::getline()` to read strings, use `std::cin >> std::ws` input manipulator to ignore leading whitespace. This needs to be done for each `std::getline()` call, as `std::ws` is not preserved across calls.

> **Key insight**
>
>   - When extracting to a variable, the extraction operator (`>>`) ignores leading whitespace and stops extracting when encountering non-leading whitespace.
>   - `std::getline()` does **not** ignore leading whitespace by default. If you want it to ignore leading whitespace, pass `std::cin >> std::ws` as the first argument. It stops extracting when encountering a newline.

## The length of a std::string

If we want to know how many characters are in a `std::string`, we can ask the object for its length.

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    std::cout << name << " has " << name.length() << " characters\n";

    return 0;
}
```

**Output:**

```
Alex has 4 characters
```

Note that `name.length()` is a **member function**, so it is called as `object.function()`.

Also note that `std::string::length()` returns an unsigned integral value (most likely of type `size_t`). If you want to assign the length to an `int` variable, you should `static_cast` it to avoid compiler warnings about signed/unsigned conversions:

```cpp
int length { static_cast<int>(name.length()) };
```

### For advanced readers (C++20)

In C++20, you can use the `std::ssize()` function to get the length of a `std::string` as a large signed integral type (usually `std::ptrdiff_t`):

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    std::cout << name << " has " << std::ssize(name) << " characters\n";
    return 0;
}
```

## Initializing a std::string is expensive

Whenever a `std::string` is initialized, a copy of the string used to initialize it is made. Making copies of strings is expensive, so care should be taken to minimize the number of copies made.

### Do not pass std::string by value

When a `std::string` is passed to a function by value, the `std::string` function parameter must be instantiated and initialized with the argument. This results in an expensive copy.

> **Best practice**
>
> Do not pass `std::string` by value, as it makes an expensive copy.
>
> **Tip:** In most cases, use a `std::string_view` parameter instead (covered in lesson 5.8).

## Returning a std::string

However, as a rule of thumb, it is okay to return a `std::string` by value when the expression of the return statement resolves to any of the following:

  * A local variable of type `std::string`.
  * A `std::string` that has been returned by value from another function call or operator.
  * A `std::string` temporary that is created as part of the return statement.

In most other cases, prefer to avoid returning a `std::string` by value.

## Literals for std::string

Double-quoted string literals (like `"Hello, world!"`) are C-style strings by default. We can create string literals with type `std::string` by using an `s` suffix after the double-quoted string literal. The `s` must be lower case.

```cpp
#include <iostream>
#include <string> // for std::string

int main()
{
    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";    // no suffix is a C-style string literal
    std::cout << "goo\n"s;   // s suffix is a std::string literal

    return 0;
}
```

> **Tip**
>
> The "s" suffix lives in the namespace `std::literals::string_literals`.
> We recommend using `using namespace std::string_literals;` which imports only the literals for `std::string`.

## Constexpr strings

If you try to define a `constexpr std::string`, your compiler will probably generate an error. `constexpr std::string` isn't supported at all in C++17 or earlier, and only works in very limited cases in C++20/23. If you need constexpr strings, use `std::string_view` instead.

## Quiz time

**Question \#1**

Write a program that asks the user to enter their full name and their age. As output, tell the user the sum of their age and the number of characters in their name (use the `std::string::length()` member function to get the length of the string). For simplicity, count any spaces in the name as a character.

**Sample output:**

```
Enter your full name: John Doe
Enter your age: 32
Your age + length of name is: 40
```

*Reminder: `std::string::length()` returns an unsigned value. If you're C++20 capable, use `std::ssize()` to get the length as a signed value. Otherwise, `static_cast` the return value of `std::string::length()` to an `int`.*

I've extracted the full content of the lesson, formatted code blocks, emphasized key insights/best practices, and fixed the fragmented sentences caused by the PDF page breaks. You can now use the "Open in Canvas" button to view, edit, or save the clean version.
