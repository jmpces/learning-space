#### > copy an array

```c
  memcpy(DESTINATION_ARRAY,SOURCE_ARRAY,sizeof(DATA_TYPE)*NUM_ELEMENTS); // add std:: in front for C++
```

#### > printing hex format in printf()

```c++
print("%08x",num);
```

- the **08** means that the hex value will be padded to meet the display length of 4 total bytes (8 hex char)
- a lowercase **x** will display small hex letters from a-f, and an uppercase **X** will display capital characters of A-F
