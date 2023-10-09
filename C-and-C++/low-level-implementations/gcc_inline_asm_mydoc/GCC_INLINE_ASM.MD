## GCC inline assembly

## Structure

```c++
asm asm-qualifiers (
    "AssemblerTemplate"
    : OutputOperands 
    : InputOperands
    : Clobbers
)

asm asm-qualifiers (
    "AssemblerTemplate"
    : OutputOperands
    : InputOperands
    : Clobbers
    : GotoLabels
)
```

-----

## GCC Inline Assembly Syntax

[GCC Inline Assembly Syntax - reference](https://www.codeproject.com/Articles/15971/Using-Inline-Assembly-in-C-C)

Assembly language appears in two flavors: Intel Style & AT&T style. GNU C compiler i.e. GCC uses AT&T syntax and this is what we would use. Let us look at some of the major differences of this style as against the Intel Style.

1. **Register Naming**: Register names are prefixed with **```%```**, so that registers are **```%eax```**, **```%cl```** etc, instead of just **```eax```**, **```cl```**.
2. **Ordering of operands**: Unlike **Intel** convention (first operand is destination), the order of operands is source(s) first, and destination last. For example, Intel syntax **"```mov eax, edx```"** will look like **"```mov %edx, %eax```"** in **AT&T** assembly.
3. **Operand Size**: In AT&T syntax, the size of memory operands is determined from the last character of the op-code name. The suffix is **```b```** for **(8-bit)** byte, **```w```** for **(16-bit)** word, and **```l```** for **(32-bit)** long. For example, the correct syntax for the above instruction would have been **"```movl %edx, %eax```"**.
4. **Immediate Operand**: Immediate operands are marked with a **```$```** prefix, as in **"```addl $5, %eax```"**, which means add immediate long value 5 to register %eax.
5. **Memory Operands:** Missing operand prefix indicates it is a memory-address; hence **"```movl $bar, %ebx```"** puts the **address** of variable bar into register %ebx, but **"```movl bar, %ebx```"** puts the **contents/value** of variable bar into register %ebx.
6. **Indexing:** Indexing or indirection is done by enclosing the index register or indirection memory cell address in parentheses. For example, **"```movl 8(%ebx), %eax```"** (moves the contents at offset 8 bytes from the cell pointed to by %ebx into register %eax.

-----

## asm-qualifiers
- **volatile** - disables certain optimizations. See Volatile.
- **inline** - If you use the inline qualifier, then for inlining purposes the size of the asm statement is taken as the smallest size possible.
- **goto** - This qualifier informs the compiler that the asm statement may perform a jump to one of the labels listed in the GotoLabels.

## asm() parameters
- **AssemblerTemplate** - This is a literal string that is the template for the assembler code. The compiler replaces tokens in the template that refer to inputs, outputs, and goto labels, and then outputs the resulting string to the assembler. Below are special string formats you can use inside the assembler template.
    - **$immediate_value** - use to represent a number value in your assembler template.
    - **%zero_base_index** - are the operands to **represent/access** the **outputs** and **inputs** _inside an assembler template_. Say for example you have 2 outputs and 2 inputs in you inline assembly like the given code below, you can access them in the assembler template using format % followed by the index of the operand in your input or output
        ```c++
        asm volatile(
            "mov %2, %%eax\n\t"
            "mul %3\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t"
            : "=m"(msb), "=m"(lsb) // outputs %0, %1
            : "r"(a), "r"(b)       // inputs %2, %3
            : "rax", "rdx"
        );
        ```
    - **asmSymbolicName** instead of accessing inputs and outputs with zero base indexing you can also access them by using an asmSymbolicName, the format when creating an asm symbolic name in output and input parameter is this **```[asmSymbolicName]"constraint"(cvariablename)```**, then you can call the symbol in the assembler template using the format **```%[asmSymbolicName]```**
    - **%%register_name** - format when use a specific register inside the assembler template, for example you want to move the value of you first input from the previous example above into the ```rdx``` register, you would do it like this
        ```
        "mov %2, %%rdx\n\t"
        ```
    - **‘%%’** - Outputs a single ‘%’ into the assembler code.
    - **‘%=’** - Outputs a number that is unique to each instance of the asm statement in the entire compilation. This option is useful when creating local labels and referring to them multiple times in a single template that generates multiple assembler instructions.
        ```
        ‘%{’
        ‘%|’
        ‘%}’
        ```
        Outputs ‘{’, ‘|’, and ‘}’ characters (respectively) into the assembler code. When unescaped, these characters have special meaning to indicate multiple assembler dialects, as described below.

## The register constraints ("r")

When the **"```r```"** constraint is specified, gcc may keep the variable in **any** of the available General Purpose Registers.

We can also **specify** the register names directly by using specific register constraints instead of "r".

```
+---+--------------------+
| r |    Register(s)     |
+---+--------------------+
| a |   %eax, %ax, %al   |
| b |   %ebx, %bx, %bl   |
| c |   %ecx, %cx, %cl   |
| d |   %edx, %dx, %dl   |
| S |   %esi, %si        |
| D |   %edi, %di        |
+---+--------------------+
```

-----

[reference](https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)

## Memory operand constraint ("m")

When the operands are in the memory, any operations performed on them will occur directly in the memory location, as opposed to register constraints, which first store the value in a register to be modified and then write it back to the memory location. But register constraints are usually used only when they are absolutely necessary for an instruction or they significantly speed up the process. Memory constraints can be used most efficiently in cases where a C variable needs to be updated inside "asm" and you really don’t want to use a register to hold its value.

## Some other constraints used are:

- "m" : A memory operand is allowed, with any kind of address that the machine supports in general.
- "o" : A memory operand is allowed, but only if the address is offsettable. ie, adding a small offset to the address gives a valid address.
- "V" : A memory operand that is not offsettable. In other words, anything that would fit the `m’ constraint but not the `o’constraint.
- "i" : An immediate integer operand (one with constant value) is allowed. This includes symbolic constants whose values will be known only at assembly time.
- "n" : An immediate integer operand with a known numeric value is allowed. Many systems cannot support assembly-time constants for operands less than a word wide. Constraints for these operands should use ’n’ rather than ’i’.
- "g" : Any register, memory or immediate integer operand is allowed, except for registers that are not general registers.


## x86 specific constraints.

- "r" : Register operand constraint, look table given above.
- "q" : Registers a, b, c or d.
- "I" : Constant in range 0 to 31 (for 32-bit shifts).
- "J" : Constant in range 0 to 63 (for 64-bit shifts).
- "K" : 0xff.
- "L" : 0xffff.
- "M" : 0, 1, 2, or 3 (shifts for lea instruction).
- "N" : Constant in range 0 to 255 (for out instruction).
- "f" : Floating point register
- "t" : First (top of stack) floating point register
- "u" : Second floating point register
- "A" : Specifies the `a’ or `d’ registers. This is primarily useful for 64-bit integer values intended to be returned with the `d’ register holding the most significant bits and the `a’ register holding the least significant bits.

## Constraint Modifiers.

While using constraints, for more precise control over the effects of constraints, GCC provides us with constraint modifiers. Mostly used constraint modifiers are

- "+" : Both input and output operand, Operands using the ‘+’ constraint modifier count as two operands (that is, both as input and output) towards the total maximum of 30 operands per asm statement.
- "=" : Means that this operand is write-only for this instruction; the previous value is discarded and replaced by output data.
- "&" : Means that this operand is an earlyclobber operand, which is modified before the instruction is finished using the input operands. Therefore, this operand may not lie in a register that is used as an input operand or as part of any memory address. An input operand can be tied to an earlyclobber operand if its only use as an input occurs before the early result is written.

## Output constraints

output constraints must begin with either **```‘=’```** (a variable overwriting an existing value) or **```‘+’```** (when reading and writing).
- When using ‘=’, do not assume the location contains the existing value on entry to the asm, except when the operand is tied to an input.

## Adding More Constraints

After the prefix, there must be one or more additional constraints that describe where the value resides. Common constraints include ‘r’ for register and ‘m’ for memory. When you list more than one possible location (for example, "=rm") , the compiler chooses the most efficient one based on the current context. If you list as many alternates as the asm statement allows, you permit the optimizers to produce the best possible code. If you must use a specific register, but your Machine Constraints do not provide sufficient control to select the specific register you want, local register variables may provide a solution

Input constraint strings may not begin with either ‘=’ or ‘+’. When you list more than one possible location (for example, ‘"irm"’), the compiler chooses the most efficient one based on the current context.
