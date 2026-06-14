// This is the first iteration... not the best can be improved.

// Logic: We explore all the choices here.
// At any given step, I do what(plural: everything I can) i can then call the function recursively.

// Also let the function know what I did in the current step so that recursion can make choices in upcoming steps.

// So given a state we have some choices:

// 1. close_rem == open_rem : at this stage if value is 0, we have used up all the parennthesis. Just put in the vector and return.
//                            if value is not 0, then we can ONLY PLACE (: [Eg ()_ ()()_ ((()))_ ]
//                            In the dashes we can only place a opening

// 2. close_rem < open_rem : This means more closing than opening brackets; an invalid choice.
// 3. close_rem > open_rem : This is the ideal case. In this case see we have not checked if these "rem" values are >=0 or not.. otherwise recursion will go infinitely and we will keep on making combinations while open rem goes negative.

// So also add a case of checking if both >=0.
// Now in this case, we explore two possibility: placing a '(' and placing a ')' .


// We start of with a "(" from the main cuz it must happen.

class Solution {
public:
    void getParStr(int open_rem, int close_rem, vector<string>& st,
                   string str) {
        if (open_rem == close_rem) {
            if (open_rem == 0) {
                st.push_back(str);
                return;
            } else {
                str.push_back('(');
                getParStr(open_rem - 1, close_rem, st, str);
            }
        }

        else if (open_rem < close_rem && open_rem >= 0 && close_rem >= 0) {
            if (open_rem == 0) {
                str.push_back(')');
                return getParStr(open_rem, close_rem - 1, st, str);
            } else {
                string par = str;
                par.push_back(')');
                getParStr(open_rem, close_rem - 1, st, par);
                par = str;
                par.push_back('(');
                getParStr(open_rem - 1, close_rem, st, par);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "(";
        vector<string> parVec;
        getParStr(n - 1, n, parVec, s);

        return parVec;
    }
};

/*

The key insight of this problem is:

> At any point, a valid prefix can never have more `')'` than `'('`.

That's it. Everything follows from this one rule.

Instead of reasoning with many cases:

* `open_rem == close_rem`
* `open_rem < close_rem`
* `open_rem == 0`
* etc.

you can think in terms of **choices**:

### Choice 1: Add `'('`

You can do this whenever:

```cpp
open_rem > 0
```

### Choice 2: Add `')'`

You can do this whenever:

```cpp
close_rem > open_rem
```

because if `close_rem == open_rem`, it means you've used the same number of `'('` and `')'` so far, and adding another `')'` would immediately make the prefix invalid.

Then the recursion becomes almost mechanical:

```cpp
if (open_rem == 0 && close_rem == 0) {
    ans.push_back(str);
    return;
}

if (open_rem > 0) {
    // add '('
}

if (close_rem > open_rem) {
    // add ')'
}
```

---

The reason this problem feels difficult is that you're trying to derive the solution through **case analysis** ("if these counts are equal, then..."), whereas backtracking problems are usually easier when you think:

1. What state am I in?
2. What choices are legal from this state?
3. Make a choice, recurse, undo.

For this problem:

* **State:** `(open_rem, close_rem, current_string)`
* **Choices:** add `'('` or add `')'`
* **Constraint:** never let `')'` exceed `'('` in the prefix.

Once you train yourself to think in terms of **state + choices + constraints**, problems like:

* Generate Parentheses
* Letter Combinations of a Phone Number
* Permutations
* N-Queens
* Palindrome Partitioning

all start feeling very similar.

*/
