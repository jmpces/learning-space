# Bash Scripting

### Create Bash Scripts

To create a bash script we add this comment to the very top
of our bash script

```bash
#! /bin/bash
```

> ![NOTE]  
> All of this bash commands will also work in the terminal
> we don't necessarily need to create a bash script, most
> of the time we only do this to avoid repetition of
> multiple commands

### Variables

```bash
STRING="str"
some_variable="noting to see here"
```

### Printing

```bash
echo this is just an ordinary line
echo variable value : $some_variable
```

### Arguments

File: script.sh

```bash
#! /bin/bash
echo $1 $2 $3 $4
```

Usage:

```bash
bash script.sh arg1 arg2 arg3
```

Output:

```bash
arg1 arg2 arg3
```

### Reading Input

You will be promted to enter a value for this variable

```bash
read just_a_variable
```

### Command Substitution

Substitute the output of another command

```bash
echo Files : $(ls)
```

### Conditionals

Checks if the variable has a value

```bash
#! /bin/bash
echo "who are you? "
read name
if [[ $name ]]; then
    echo "hello \"$name\" welcome to bash scripting"
else
    echo "I dont know you"
fi
```

Logical `&&`, `||`, `!` are also supported, Relational operations `==` and `!=` is also available and more.

```bash
#! /bin/bash

echo "why are you here? "
read reason
if [[ $reason == "to learn" || $reason == "learn" || $reason == "learning" ]]; then
    echo "good for you"
else
    echo "wut?"
fi

echo "how old are you? "
read age
if [ $age ]; then
    if   (( $age <= 18 ));  then echo "too young"
    elif (( $age <= 30 ));  then echo "mid age"
    elif (( $age <= 70 ));  then echo "too old"
    elif (( $age <= 100 )); then echo "ancient"
    else echo "what?"
    fi
else
    echo I need inputs
fi

echo "Pick a color"
read color
if [[ $color == "red" ]]; then
    echo "wild"
elif [[ $color == "blue" ]]; then
    echo "cool"
elif [[ $green == "green" ]]; then
    echo "calm"
else
    echo "not in the choice"
fi
```

### Types of Conditionals

In Bash, there are several ways to evaluate conditions and perform tests. The primary constructs for conditionals are `[[ ]]`, `[ ]`, `(( ))`, and `()`.

1. `[[ ]]` (Double Square Brackets):
   - `[[ ]]` is used for advanced conditional testing and is recommended for most situations.
   - It supports logical operators (`&&` for AND, `||` for OR) and various string and numeric comparisons.
   - It allows for pattern matching with `==`, `!=`, `=~`, and more.
   - It handles empty variables safely; an empty variable within `[[ ]]` is treated as false.
   - It doesn't require quoting variables within the brackets (e.g., you can use `[[ $var == "string" ]]` without double quotes around `$var`).

    Example:
    ```bash
    if [[ $age -ge 18 && $age -le 100 ]]; then
        echo "You are an adult."
    fi
    ```

> [NOTE]  
> the `=~` operator is used within double square brackets ([[ ]]) for pattern matching using regular expressions. It allows you to compare a string against a regular expression pattern and determine if the string matches the pattern. Regular expressions are a powerful tool for string manipulation and matching complex patterns.

2. `[ ]` (Single Square Brackets):
   - `[ ]`, also known as the test command, is a basic conditional construct.
   - It's less versatile compared to `[[ ]]` and should be used when only simple conditions are needed.
   - It requires quoting variables and operators inside the brackets (e.g., `[ "$var" = "string" ]`).
   - It uses single brackets (`[ ]`) and often requires a closing semicolon `;` after the condition.

    Example:
    ```bash
    if [ "$var" = "string" ]; then
        echo "The variable is equal to 'string'."
    fi
    ```

    In Bash, you can use various conditional operators and flags with the `test` command or `[ ]` (single square brackets) for performing different types of tests. These operators are commonly used in conditional statements like `if` to evaluate various conditions. Here are some of the commonly used ones:

    1. `-eq`: Equal to
        - Checks if two values are equal.
        
        Example:
        ```bash
        if [ $x -eq $y ]; then
            echo "$x is equal to $y"
        fi
        ```

    2. `-lt`: Less than
        - Checks if one value is less than another.
        
        Example:
        ```bash
        if [ $x -lt $y ]; then
            echo "$x is less than $y"
        fi
        ```

    3. `-gt`: Greater than
        - Checks if one value is greater than another.
        
        Example:
        ```bash
        if [ $x -gt $y ]; then
            echo "$x is greater than $y"
        fi
        ```

    4. `-d`: Directory Exists
        - Checks if a directory with the specified name exists.
        
        Example:
        ```bash
        if [ -d "/path/to/directory" ]; then
            echo "Directory exists"
        fi
        ```

    5. `-e`: File or Directory Exists
        - Checks if a file or directory with the specified name exists.
        
        Example:
        ```bash
        if [ -e "/path/to/file_or_directory" ]; then
            echo "File or directory exists"
        fi
        ```

    6. `-f`: File Exists and is a Regular File
        - Checks if a file with the specified name exists and is a regular file (not a directory or special file).
        
        Example:
        ```bash
        if [ -f "/path/to/file" ]; then
            echo "File exists and is a regular file"
        fi
        ```

    7. `-w`: Writable
        - Checks if a file or directory is writable by the current user.
        
        Example:
        ```bash
        if [ -w "/path/to/file_or_directory" ]; then
            echo "File or directory is writable"
        fi
        ```

    8. `-x`: Executable
        - Checks if a file is executable by the current user.
        
        Example:
        ```bash
        if [ -x "/path/to/executable_file" ]; then
            echo "File is executable"
        fi
        ```

    These operators are commonly used in conditional statements like `if` to make decisions based on the results of these tests. You can combine these operators and use them in more complex conditions as needed in your Bash scripts.

3. `(( ))` (Double Parentheses):
   - `(( ))` is used for arithmetic operations and comparisons.
   - It's primarily used for numeric comparisons, calculations, and incrementing/decrementing variables.
   - It doesn't require quoting variables.
   - It evaluates to 0 for false and 1 for true.

    Example:
    ```bash
    if (( age >= 18 && age <= 100 )); then
        echo "You are an adult."
    fi
    ```

4. `()` (Parentheses):
   - `()` is used for subshells and command grouping, not for conditionals.
   - It runs commands in a subshell environment and doesn't affect the main shell's variables or state.
   - It's not used for writing conditional statements.

In summary, `[[ ]]` is the most flexible and commonly used construct for conditional testing in Bash, suitable for string and numeric comparisons, pattern matching, and handling empty variables. `[ ]` is a simpler alternative for basic conditional tests but requires more careful handling of quotes. `(( ))` is used exclusively for numeric comparisons and calculations. Parentheses `()` are used for creating subshells and command grouping, not for conditionals.

### Pipe, Grep and Awk

**Pipe** - the `|` character in bash is called a **pipe** where its job is to
pass output of one command to the argument of another command.

**grep** - is a useful command to search for matching patterns in a file. grep is short for "global regular expression print".

**awk** - is a powerful tool for manipulating and processing text files in Unix/Linux environments. It can be used to perform tasks such as pattern matching, filtering, sorting, and manipulating data. awk is mainly used to process and manipulate data in a structured manner.

_**Show only the line that has a matching pattern**_

```bash
lscpu | grep "Flags:"
```

The example above filter the output of `lscpu` and only show the Flags line output. The way this work is by passing the original output of the `lscpu` command to arguments of grep then grep will find the `Flags:` pattern in a line and output the line if it has a match.

_**Print a specific column number**_


Column are just words in a output, by default they are separated by spaces.

The command below will only print the first column of the lscpu command

```bash
lscpu | awk '{print $1}'
```