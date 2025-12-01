# Static Code Analysis

## What It Is  
Static code analysis is the automatic checking of source code **without running it**.  
It detects defects early by scanning the code for patterns linked to bugs, safety issues, or rule violations.

---

## Why It Matters  
- C language is unsafe by default (pointers, casts, overflow).  
- Humans miss subtle bugs.  
- Safety standards (IEC 62304, ISO 26262) require it.  
- Greatly reduces testing cost later in development.

---

## What It Finds  
- Uninitialized variables  
- Dead code  
- Buffer overflow risks  
- Dangerous casts  
- MISRA-C violations  
- Unreachable states  
- Concurrency issues (if applicable)

---

## Examples of Tools  
- **Free:** cppcheck, clang-tidy, clang static analyzer  
- **Industry:** PC-lint, QA-C, Coverity, Polyspace, Klocwork

https://cppcheck.sourceforge.io
https://www.mathworks.com/help/bugfinder/misra-c-2023-reference.html
https://www.kernel.org/doc/html/v6.4/process/coding-style.html
---

## Simple Example  
```c
int read_value(void)
{
    int x;
    return x;   // static tool: "x may be uninitialized"
}
```