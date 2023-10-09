# stlmanip

---------------------------------------------------------------

### stlvec - does operations on std::vector's

```c++
  #include <stlvec.hpp>
  
  typedef what_ever_type T;
  std::vector<T> combined  = vec::concat(vecT1,vecT2);
  std::vector<T> subvector = vec::subseq(vecT,index,length);
  bool exist = vec::has_member(vecT,T);
```
