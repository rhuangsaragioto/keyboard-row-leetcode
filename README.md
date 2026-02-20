# LeetCode - 500. Keyboard Row

My solution to Leetcode's 500th problem: Keyboard Row.

## Description

Given an array of strings `words`, return *the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.*

**Note** that the strings are **case-insensitive**, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the **American keyboard**:

- the first row consists of the characters `"qwertyuiop"`,
- the second row consists of the characters `"asdfghjkl"`, and
- the third row consists of the characters `"zxcvbnm"`.

![US Layout Keyboard](https://assets.leetcode.com/uploads/2018/10/12/keyboard.png)

**Example 1:**

> **Input:** `words = ["Hello","Alaska","Dad","Peace"]`
>
> **Output:** `["Alaska","Dad"]`
>
> **Explanation**:
>
> Both `"a"` and `"A"` are in the 2nd row of the American keyboard due to case insensitivity.

**Example 2:**

> **Input:** `words = ["omk"]`
>
> **Output:** []

**Example 3**:

> **Input:** words = ["adsdf","sfd"]
>
> **Output:** ["adsdf","sfd"]

**Constraints:**

`1 <= words.length <= 20`
`1 <= words[i].length <= 100`
`words[i]` consists of English letters (both lowercase and uppercase).

## Solution

I used three nested `for` loops. The outermost loop

```c++
for (size_t i = 0; i < words.size(); i++)
```

iterates through the words fed by the word list (i.e., `words = ["Hello", "Alaska", "Dad", "Peace"]`).

The middle loop

```c++
for (size_t j = 0; j < rows.size(); j++)
```

iterates through every "row" of characters from the keyboard defined in `rows`. It also sets `found` to `1` which is just equivalent to `true`. This sets up the logic for the next loop nicely.

The inner most loop

```c++
for (size_t k = 0; k < cword.size(); k++)
```

does most of the heavy lifting, it iterates through every character of the current word to check if it belongs to the current row which is being iterated through. So long as the character is found (meaning, all characters so far are present in the current row), it keeps iterating until we run out of characters in the current word. Otherwise, if the character is not found in the current row being checked,

```c++
if (rows[i].find((char)tolower(cword[j])) == std::string::npos)
```

then `found` is set to 0 and the program immediately breaks out of the `j` loop. To expand more on the if statement that basically is the bulk of the solution, the current character of the word being iterated through `cword[j]` is parsed as its lower-case self into the `find()` function from `std::string`, and if that character is not found, then `find()` returns `npos`, which is what the result of the function is being compared against.

Finally, when the inner most loop ends, either because it was broken out of, or because it actually ended, the word is appended if `found = 1` or not appended if `found = 0`. The process continues until every word is visited.

**Note** that explicitly converting the result of `tolower()` to a `char` is not necessary at all. I did it because gcc would not stop screaming at me for having an implicit conversion which could lose accuracy. That is the same reason as to why I have my iterators declared to `size_t` rather than int. *Thanks*, gcc.

## Thought Process

Approaching this problem, my idea was that I knew I was going to need at least two `for` loops (since you need to iterate through the words, and you also need to iterate through the words' characters), so that's where I started. I wrote a loop that iterated through the words that needed to be checked, and then I wrote a loop that iterated through every character of the current word, which I initially called `word`, but after a while it got kind of confusing for me to have `word` and `words` so close together in the code, so I settled with the name `cword` for the current word which stands for "current word."

I hit my first roadblock when it came down to checking what row the current character was in. To solve that, I created a local variable which was a `vector<string>` of the characters present in each row of the keyboard (`qwertyuiop`, `asdfghjkl`, and `zxcvbnm`). Then, because I had three different rows to check, I created a loop inside my other two loops (so: words > characters > rows).

If you're familiar with this problem or are just in general proficient in algorithms, you already realize the major problem with what I did at first. I had the row loop inside all of the other loops, so for **every** character, I was checking all three rows.

Thankfully, I was able to realize that and I flipped the middle loop and the inner most loop so that for each row, it was checking every character. The actual checking was also another part that got me stumped, mainly because I have a real hard time remembering the member functions of every STL data structure (such as the vector) and also of data types (such as the string), so I spent unnecessarily long researching to remind myself how I could check for a substring present within a string.

Since the problem specified case-insensitivity, I thought that I should parse every character as its lower-case self to avoid false positives. I knew that I wanted to keep the loop going until I found a mismatch, since one **mismatch** is all it took for the word candidate to be invalidated. Therefore, I kept a boolean variable `found` around that served to break me out of the character loop (because there's no point to keep checking once you found a mismatch), and so if not found i broke out of the loop.

I also made a vector called `result` since LeetCode formatted its expected output as a list. Finally, I appended the word to the `result` vector if `found` was 1, and then I break out of the loop on the same condition to avoid checking the other rows for an already found word.

## Authors

Rhuan Saragioto
My LeetCode profile: [@rhuangsaragioto](https://leetcode.com/u/rhuangsaragioto/)
My GitHub profile: [@rhuangsaragioto](https://github.com/rhuangsaragioto)

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
