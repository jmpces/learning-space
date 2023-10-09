# STRINGS

---------------------------------------------------------------

### WRITE METHODS - write strings to an existing text file

```c++
  #include <writer.hpp>
  
  write::create("new_file.txt");
  write::append("filename.txt","text to append");
  write::overwrite("filename.txt","text to overwrite existing text");
```

### READ METHODS - read text from an existing text file

```c++
  #include <reader.hpp>

  std::string     wholetext = read::all("filename.txt");
  std::vector<string> lines = read::lines("filename.txt");
  std::vector<string> words = read::words("filename.txt");
```

---------------------------------------------------------------

### MODIFIERS - transforms strings to a different form

```c++
  #include <transform.hpp>
  
  std::string str_lowercase = transform::tolower(str_uppercase);
  std::string str_uppercase = transform::toupper(str_lowercase);
  
  std::string newstr = transform::replace_all(old_str,old_substr,new_substr);
  ```
  
---------------------------------------------------------------
  
### SEARCH - finds pattern on strings

```c++
  #include <search.hpp>
  
  bool exist_s = search::pattern_s("to find", "string where to find");
  bool exist_i = search::pattern_i("tO FiNd", "sTriNg wHere tO fInD");
```

---------------------------------------------------------------

### COMBINATIONS & PERMUTATIONS

```c++
#include <iostream>
#include <possibilities.hpp>

int main()
{
    std::string char_set = "abc";
    // by default, if you do not initialize with an argument, the possibilities::default_char_set will be used instead 
    possibilities::collection demo(char_set);
    for(size_t i=0; i<30; ++i)
    {
        std::cout<<demo.value()<<std::endl;
        demo.next();
    }
    std::cin.get();
    return 0;
}
```

<details>
<summary><b>output</b></summary>
<br>
  
```
a
b
c
aa
ba
ca
ab
bb
cb
ac
bc
cc
aaa
baa
caa
aba
bba
cba
aca
bca
cca
aab
bab
cab
abb
bbb
cbb
acb
bcb
ccb
```

</details>
