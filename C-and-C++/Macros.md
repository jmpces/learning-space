## Boost Predefined Macros

https://www.boost.org/doc/libs/1_82_0/libs/predef/doc/index.html#_using_the_predefs

## compiler macros
```c++
#if defined(__clang__)
// clang only code goes here
#elif defined(__GNUC__) || defined(__GNUG__)
// gnu-gcc only code goes here
#elif defined(_MSC_VER)
// microsoft compiler only code goes here
#endif
```

## assertion macro
```c++
#include <iostream>

#define ENABLE_ASSERT

#ifdef ENABLE_ASSERT
#define M_ASSERT(expr) \
      { \
         if(!(expr)){ \
            std::cerr << "ASSERTION FAILURE: \n"; \
            std::cerr << " => Condition: " << #expr << "\n"; \
            std::cerr << " =>  Function: " << __FUNCTION__ << "\n"; \
            std::cerr << __FILE__ << ":" << __LINE__ << ":" << "\n"; \
            std::terminate(); \
         } \
      }
#else
#define M_ASSERT(expr)
#endif
```

## debug macro

```c++
#if defined(DEBUG_MODE)
  #define disp(expr)  std::cerr << __FILE__ << ":" << __LINE__ << ":" \
      << " ; " <<  #expr << " = " << (expr)  <<  std::endl

  #define dbgloc(msg)  std::cerr << __FILE__ << ":" << __LINE__ << ":" << msg 
  #define dbgline __FILE__ << ":" << __LINE__ << ":" <<
  #define dbgtrace(msg) std::cerr << __FILE__ << ":" << __LINE__ << ": TRACING " << msg << "\n";
#else
  #define disp(expr) 
  #define dbgloc(msg)  
  #define dbgline 
  #define dbgtrace(msg) 
#endif 
```

## Type assertion
```c++
#define ASSERT_TYPE_EQUAL(type, expr) \
   static_assert(std::is_same<type, expr>::value, "Expected type equality")
```
 
 ## Predefined Macros
 
| Macro | Description | Compiler |
| --- | --- | --- |
| ```__LINE__``` | Contains current line number of the program. | all |
| ```__FILE__``` | Name of current file. | all |
| ```__DATE__``` | Date in the format month/day/year | all |
| ```__TIME__``` | Contains a string in the format hour:minute:second | all |
| ```__cplusplus``` | Contains C++ standard Version string | all |
| ```__FUNCTION__``` | Print name of current function or method (member function)	| all |
| ```__PRETTY_FUNCTION__```	| Print name of current function or method with type signature.	| GGC/G++, Mingw(GCC for Windows) and Clang |
| ```__FUNCSIG__``` | Print name of current function with type signature.	| MSVC(aka VC++) |

**Possible values of ```__cplusplus``` macro**

- 199711L	C++98/C++03
- 201103L	C++11
- 201402L	C++14
- 201703L	C++17
- N/A	C++20


## Macros for detecting platform or operating system

| Operating System | OS Family | Macro | Description |
| --- | --- | --- | --- |
| Windows 32 and 64-bits | WinNT | ```_WIN32``` |	Defined when compiling on Windows with Msvc(Visual C++) or Gcc |
Windows 64 bits	| WinNT | ```_WIN64``` | Windows 64 bits. |
Windows CE | WinCE | ```_WIN32_WCE``` | Windows CE Kernel for embedded systems. |
| MSDOS | | ```MSDOS``` or ```__MSDOS__``` | |	 
| OS2 | | ```OS2``` or ```_OS2``` or ```__OS2__``` | IBM's old OS2 Operating System. | 	 	 	 
| Unix-like | Unix | ```__unix__``` | Check whether OS is unix-like (Linux, BSD-variant), Mac OSX) |
| Linux | Unix | ```__linux__``` | Defined when compiling on Linux with Gcc or Clang |
| Android | Unix | ```__ANDROID__``` | Android NDK. |
| MacOSX and IOS (Darwin Kernel) | Unix | ```__apple__```, ```__APPLE__```, ```__MACH__```	| |
| BSD | Unix | ```__bsd__``` | |
| Free BDS | Unix | ```__FreeBSD__``` |	 
| Net BSD | Unix | ```__NetBSD__``` | |	 
| QNX | Unix | ```__QNX__``` | |	 
| VxWorks | | ```__VXWORKS__``` or ```__vxworks``` | |	 
| Minix | Unix | ```__minix``` | |	 
| NaCL | | ```__native_client__``` | 
| AsmJS | | ```__asmjs__``` | |	 
       
-----

## Macros for detecting compiler

| Macro | Compiler |
| --- | --- |
| **```__GNUC__```** | GNU C/C++ Compiler. |
| **```__MINGW32__```** |	Mingw or GNU C/C++ Compiler ported for Windows NT. |
| **```__MINGW64__```** |	Mingw or GNU C/C++ Compiler ported for Windows NT - 64 bits only. |
| **```__GFORTRAN__```** |	Fortran / GNU Fortran Compiler |
| **```__clang__```** |	Clang / LLVM Compiler |
| **```_MSC_VER```** | Microsoft Visual Studio Compiler MSVC |
| **```_MANAGED```** or **```__cplusplus_cli```** | Compilation to C++/CLI .NET (CLR) bytecode |
| **```__INTEL_COMPILER```** |	Intel C/C++ Compiler |
| **```__PGI```** | or __PGIC__	Portland Group C/C++ Compiler |
| **```__BORLANDC__```** |	Borland C++ Compiler [DEPRECATED]
| **```__EMSCRIPTEN__```** | emscripten (asm.js - web assembly) |
| **```__asmjs__```** |	asm.js |
| **```__wasm__```** |	WebAssembly |
| **```__NVCC__```** |	NVCC |
| **```__CLING__```** |	CERN's ROOT Cling C++ Interactive Shell |
 	 
 	 
## C/C++-library Macros
| Macros | Library |
| --- | --- |
| **```__GLIBCXX__```** |	Libstdc++ |
| **```_LBCPP_VERSION```** | LibC++ |
| **```_MSC_VER```** | MSVC C++ Library (Runtime) |
| **```__GLIBC__```** |	GNU LibC runtime |
| **```__BIONIC__```** |	Bionic LibC runtime. (Android's C-library modified from BSD) |


Macros for detecting architecture

| Architecture | Macro |
| --- | --- |
| ***Intel x86*** | |
| x86 | **```_M_IX86```** ; ```__INTEL__``` ; **```__i386__```** |
| ***Intel or AMD X86-64 (64 bits)*** | |
| AMD64 (x86-64) | **```__amd__64__```** |
| AMD64 | **```__amd_64```** |
| AMD64 | **```__x86_64__```** |
| AMD64 | **```__x86_64```** |
| Intel Itanium 64 bits | **```__IA64__```** , **```__ia64__```** |
| ***ARM Core***	 | |
| ARM (general) | **```__arm__```** , **```_ARM```**, **```_M_ARM```**, **```M_ARMT```** |
| ARM thumb extension | **```__thumb__```** |
| ARM 2 CPU | **```__ARM_ARCH_2__```** |
| ARM 3 CPU | **```__ARM_ARCH_3__```** |
| ARM 4T CPU | **```__ARM_ARCH_4T__```** |
| ARM 5 CPU | **```__ARM_ARCH_5__```** |
| ARM 5T CPU | **```__ARM_ARCH_5T__```** |
| ARM 6 CPU | **```__ARM_ARCH_6__```** |
| ARM 7 CPU | **```__ARM_ARCH_7__```** |
| ARM 7 CPU | **```__ARM_ARCH_7A__```** |
| ARM 7 CPU | **```__ARM_ARCH_7R__```** |
| ARM 7 CPU | **```__ARM__ARCH_7M__```** |
| ARM 7 CPU | **```__ARM_ARCH_7S__```** |
| ARM64 (ARM 64 bits ) | **```__aarch64__```** |
| ***PowerPC*** | |	 
| PowerPC core | **```__powerpc```** ; **```__powerpc__```** ; **```__POWERPC__```** ; **```_M_PPC```** |
| PowerPC core | **```__powerpc64__```** |
| ***SuperH*** | |
| SuperH core | **```__sh__```** ; **```__sh1__```** ; **```__sh2__```** ; **```__sh3__```** |
| SuperH core | **```__SH3__```** ; **```__SH4__```** ; **```__SH5__```** |
