#include<iostream>
#include<string>
#include<sstream> // For using sstream
#include<vector>
using namespace std;

// New Concept: Stringstream
/*
hink of std::stringstream as a temporary, invisible console window that lives inside your program's memory.

Just like you use std::cin >> to read words or numbers that a user types on their keyboard, you use stringstream >> to read words or numbers out of a string you already have. It completely removes the headache of manually writing loops to check for spaces, commas, or specific data types.
Think of `std::stringstream` as a temporary, invisible console window that lives inside your program's memory.

Just like you use `std::cin >>` to read words or numbers that a user types on their keyboard, you use `stringstream >>` to read words or numbers out of a string you already have. It completely removes the headache of manually writing loops to check for spaces, commas, or specific data types.

Here is exactly how to use it to solve your specific problem, followed by the rules for using it effectively in algorithmic problems.

### 1. Splitting a String into a Vector of Words

This is the most common use case for `stringstream`. The extraction operator (`>>`) automatically skips all leading spaces, reads the characters until it hits the next space, and stops. It handles multiple consecutive spaces perfectly without creating empty strings.

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string sentence = "  This   has  way too   many   spaces.  ";
    
    // 1. Initialize the stringstream with your string
    std::stringstream ss(sentence);
    
    std::vector<std::string> words;
    std::string current_word;
    
    // 2. Extract words one by one until the stream is empty
    while (ss >> current_word) {
        words.push_back(current_word);
    }
    
    // 3. Verify the output
    for (const std::string& w : words) {
        std::cout << "[" << w << "]\n";
    }
    
    return 0;
}

```

**Output:**

```text
[This]
[has]
[way]
[too]
[many]
[spaces.]

```

### 2. Extracting Mixed Data Types

If a problem gives you a string that contains both text and numbers (e.g., `"Alice 85 92 78"`), `stringstream` automatically converts the text into the correct C++ types as it reads.

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "Alice 85 92 78";
    std::stringstream ss(data);
    
    std::string name;
    int score1, score2, score3;
    
    // Extracts and converts simultaneously
    ss >> name >> score1 >> score2 >> score3;
    
    std::cout << "Name: " << name << ", Total: " << (score1 + score2 + score3) << "\n";
    
    return 0;
}

```

### 3. Splitting by a Custom Delimiter (e.g., Commas)

If the words are separated by something other than spaces (like a comma in a CSV file), you pair `stringstream` with the `std::getline()` function.

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string csv_data = "apple,banana,orange,grape";
    std::stringstream ss(csv_data);
    
    std::vector<std::string> fruits;
    std::string fruit;
    
    // getline(stream, target_string, delimiter_character)
    while (std::getline(ss, fruit, ',')) {
        fruits.push_back(fruit);
    }
    
    return 0;
}

```

### The Critical Trap: Reusing a Stringstream

When tackling multiple test cases in a row (a very common scenario when submitting solutions), you might want to declare your `stringstream` once outside a loop and reuse it to save memory.

**If you reuse a `stringstream`, you MUST reset it properly.** When a stream reaches the end of a string, it sets an internal "End of File" (EOF) error flag. If you give it a new string without clearing that flag, it will refuse to read anything.

```cpp
std::stringstream ss;
std::string text1 = "first test case";
std::string text2 = "second test case";

// Process first string
ss.str(text1);
// ... extract data ...

// RESET REQUIRED before the second string:
ss.clear();        // 1. Clears the EOF and error flags
ss.str(text2);     // 2. Loads the new string

// ... extract data ...

```

### Summary of When to Use It

* **Use it when:** You need to break a sentence into words, parse a string containing integers/floats, or split data by a specific character like a comma.
* **Don't use it when:** You just need to find a specific substring (use `s.find()`), check if a string is a palindrome (use `std::reverse`), or count characters. Stream operations are slightly heavier than basic string indexing, so reserve them for tokenizing and type conversion.

 */

class solution{
public:
    string reverseWords(string& s){
        stringstream ss(s); 
        // HERE s acts as input space. In cin, WE ACT AS INPUT SPACE.
        // Continuous use of cin reads inputs multiple times from us.
        // Continuous use of stringstream will read strings from s MULTIPLE TIMES. Cuz ss only knows s.
        // At the end, returns EOF flag.
        string str;
        vector<string> st;
        while(ss >> str){
            st.push_back(str);
        }
        // " I am a man   "
        //  [I,am,a,man]
        int i = 0, j = st.size()-1;
        while(i<j){
            swap(st[i], st[j]);
            i++;
            j--;
        }

        s = "";
        for(i=0; i<st.size()-1; i++){
            s.append(st[i]);
            s.append(" ");
        }
        s.append(st[i]);

        return s;
    }
};

int main(){
    solution s;
    string str = "   I am a man ";
    cout<<s.reverseWords(str);
    return 0;
}