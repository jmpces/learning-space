# NUMBERS

---------------------------------------------------------------

### RANDOMIZER - header file that provides wrapper function for cpp stl's random library

```c++
  #include <randomizer.hpp>
  
  int   num1 = randomizer::integer<int,std::mt19937_64>(); // generate random number of integer int type
  long  num2 = randomizer::integer<long,std::default_random_engine>(-5,100); // example with range
  float num3 = randomizer::real<float,std::mt19937>(0,1);
  // you can use any random engine that you want in the second template argument
```

<details>
<summary><b>some of stl's random engine generator</b></summary>
<br>
  
  :
  
  - std::default_random_engine
  
  - std::minstd_rand
  
  - std::minstd_rand0
  
  - std::mt19937
  
  - std::mt19937_64
  
  - std::ranlux24_base
  
*see the C++ documentation for more information about random engine generators*
  
 </details>
