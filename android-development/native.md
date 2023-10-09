# **Native C++ Development in Android Studio**

## **Adding C++ to an Existing Project**

1. In Project tab > **Android** > **app > Gradle Scripts > android.defaultConfig** block, add the property:

    ```gradle
    externalNativeBuild {
        cmake {
            cppFlags '-std=c++14'
        }
    }
    ```

2. In **app > Gradle Scripts > android** block, add the property:

    ```gradle
    externalNativeBuild {
        cmake {
            path file('src/main/cpp/CMakeLists.txt')
            version '3.22.1'
        }
    }
    ```

3. In Project tab > **Project > app > src > main > Right-Click >
New > Directory :** `cpp`

4. **cpp > Right-Click > New > File :** CMakeList.txt

    ```cmake
    cmake_minimum_required(VERSION 3.22.1)

    project("LIBRARY_NAME")

    add_library(
        LIBRARY_NAME
        SHARED
        native-lib.cpp
    )

    find_library(
        log-lib
        log
    )

    target_link_libraries(
        LIBRARY_NAME
        ${log-lib}
    )
    ```

5. **cpp > Right-Click > New > File :** native-lib.cpp

    ```c++
    #include <jni.h>
    #include <string>
    ```

6. In your activity java class add:

    ```java
    static {
        System.loadLibrary("LIBRARY_NAME");
    }
    ```

## **Implement a native method**

1. Define a native function in your activity java class.

    ```java
    private native ReturnType FunctionName(ArgType ArgName);
    ```
    
2. To declare the C++ functions you have two ways.

    - You can select the defined function name and press
    `Alt + Enter > "Create JNI function ..."` and let the
    android studio to automatically declare the C++ function
    signature for you.

    - Or you can define it manually following this format:

        Format :
        
        ```c++
        extern "C" JNIEXPORT jreturn_type JNICALL
        Java_PackageName_ClassName_MethodName(
            JNIEnv* env,
            jobject thiz,
            jarg_type_if_there_is_one arg
        ) {
            
        }
        ```

    - **PackageName** was the directory where the Activity Class is
    located, usually this is `com.example.APP_NAME` so in this case
    the package name would be `_com_example_APP_NAME`

    - **ClassName** is the Activity Class where you defined the
    native function definition, usually this is `MainActivity`.

    - **MethodName** is the name of the defined native function
    name in the Activity Class.

## **JNI Primitive Types**

| Java       | C++ JNI        | C++ Equivalent | Signatures |
| ---------- | -------------- | -------------- | ---------- |
| `boolean`  | `jboolean`     | `uint8_t`      | Z          |
| `byte`     | `jbyte`        | `int8_t`       | B          |
| `char`     | `jchar`        | `uint16_t`     | C          |
| `short`    | `jshort`       | `int16_t`      | S          |
| `int`      | `jint`         | `int32_t`      | I          |
| `long`     | `jlong`        | `int64_t`      | J          |
| `float`    | `jfloat`       | `float`        | F          |
| `double`   | `jdouble`      | `double`       | D          |
| `void`     | `void`         | `void`         | V          |

Signature of objects - `Ljava_lang_ClassName_2`

## **Overloading native methods**

- Signatures - **Only used** in native declaration of methods
**when overloading** methods in order for the JNI to see the overloaded
methods properly.

    In functions that are overloaded just add `__Signature` for one
    argument function, add `__SignatureSignature` for two argument
    function, and so on and so forth.

    An example of a method that was overloaded but with 2 arguments:

    Format: `Java_PackageName_ClassName_MethodName__MethodParamType1MethodParamType2...MethodParamTypeN`

    ```c++
    extern "C" JNIEXPORT jreturn_type JNICALL
    Java_com_example_MainActivity_MethodName__ID(
        JNIEnv* env,
        jobject thiz,
        jarg_type_if_there_is_one arg,
        jint a, jdouble
    ) {
        // Function Code
    }
    ```

## **Returning Primitive Types**

There is **no problem** when you **return the corresponding C++ types**
to their JNI counterpart, but this is **only true for primitive types**.

**For arrays** its quiet different, we need to **use the `JNIEnv* env`**
to **convert or set our arrays** into an array that the java can process.


# **Primitive Type Arrays**

C++ JNI primitive type arrays are defined in the format:

- j**PrimitiveType**Array

## **GetArrayLength**

```c++
jsize GetArrayLength(JNIEnv *env, jarray array);
```

Returns the number of elements in the array.

<br>

## **NewObjectArray**

```c++
jobjectArray NewObjectArray(
    JNIEnv *env,
    jsize length,
    jclass elementClass,
    jobject initialElement
);
```

Constructs a new array holding objects in class elementClass. All elements are initially set to initialElement.

<br>

## **GetObjectArrayElement**

```c++
jobject GetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index);
```

Returns an element of an Object array.


<br>

## **SetObjectArrayElement**

```c++
void SetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index, jobject value);
```

Sets an element of an Object array.

<br>

## **New\<PrimitiveType\>Array Routines**

```c++
ArrayType New<PrimitiveType>Array(JNIEnv *env, jsize length);
```

| PrimitiveType | ArrayType       |
| ------------- | --------------- |
| `Boolean`     | `jbooleanArray` |
| `Byte`        | `jbyteArray`    |
| `Char`        | `jcharArray`    |
| `Short`       | `jshortArray`   |
| `Int`         | `jintArray`     |
| `Long`        | `jlongArray`    |
| `Float`       | `jfloatArray`   |
| `Double`      | `jdoubleArray`  |

A family of operations used to construct a new primitive array object.
The following table describes the specific primitive array constructors.

You should replace `New<PrimitiveType>Array` with one of the actual
primitive array constructor routine names from the table above, and replace
`ArrayType` with the corresponding array type for that routine.

<br>

## **Get\<PrimitiveType\>ArrayElements Routines**

```c++
NativeType *Get<PrimitiveType>ArrayElements(JNIEnv *env, ArrayType array, jboolean *isCopy);
```

| PrimitiveType | ArrayType       | NativeType |
| ------------- | --------------- | ---------- |
| `Boolean`     | `jbooleanArray` | `jboolean` |
| `Byte`        | `jbyteArray`    | `jbyte`    |
| `Char`        | `jcharArray`    | `jchar`    |
| `Short`       | `jshortArray`   | `jshort`   |
| `Int`         | `jintArray`     | `jint`     |
| `Long`        | `jlongArray`    | `jlong`    |
| `Float`       | `jfloatArray`   | `jfloat`   |
| `Double`      | `jdoubleArray`  | `jdouble`  |

**Creating a C/C++ pointer of a JNI type array**

A family of functions that returns the body of the primitive array.
The result is valid until the corresponding 
`Release<PrimitiveType>ArrayElements()` function is called.

**Since the returned array may be a copy of the Java array,
changes made to the returned array will not necessarily be
reflected in the original array until
`Release<PrimitiveType>ArrayElements()` is called**.

The `isCopy` parameter is a `jboolean` reference, it will **contain the
output** to know **if** the operation returns a **copy or not**:

- `*isCopy` is set to `JNI_TRUE` if a copy is made
- `*isCopy` is set to `JNI_FALSE` if no copy is made

The following table describes the specific primitive array element accessors. You should make the following substitutions:

- Replace `PrimitiveType` with one of the actual primitive element accessor 
routine names from the following table.
- Replace `ArrayType` with the corresponding array type.
- Replace `NativeType` with the corresponding native type for that routine.

**Note :** Regardless of how boolean arrays are represented in the Java VM,
`GetBooleanArrayElements()` always returns a pointer to `jbooleans`,
with each byte denoting an element (the unpacked representation).

All arrays of other types are guaranteed to be contiguous in memory.

<br>

## **Release\<PrimitiveType\>ArrayElements Routines**

```c++
void Release<PrimitiveType>ArrayElements(JNIEnv *env, ArrayType array, NativeType *elems, jint mode);
```

A family of functions that informs the VM that the native code no
longer needs access to `elems`.

The `elems` argument is a pointer derived from `array` using the 
corresponding `Get<PrimitiveType>ArrayElements()` function.

**If necessary**, this function **copies** back **all changes** made
to **`elems` to the original `array`**.

The `mode` argument provides information on how the `array` buffer should be released.

**`mode` has no effect if `elems` is not a copy of the elements in `array`.**

Otherwise, `mode` has the following impact, as shown in the following table:

| Mode         | Actions                                                   |
| ------------ | --------------------------------------------------------- |
| `0`          | copy back the content and free the `elems` buffer         |
| `JNI_COMMIT` | copy back the content but do not free the `elems` buffer  |
| `JNI_ABORT`  | free the buffer without copying back the possible changes |

<br>

## **Get\<PrimitiveType\>ArrayRegion**
```c++
void Get<PrimitiveType>ArrayRegion(JNIEnv *env, ArrayType array, jsize start, jsize len, NativeType *buf);
```

| PrimitiveType | ArrayType       | NativeType |
| ------------- | --------------- | ---------- |
| `Boolean`     | `jbooleanArray` | `jboolean` |
| `Byte`        | `jbyteArray`    | `jbyte`    |
| `Char`        | `jcharArray`    | `jchar`    |
| `Short`       | `jshortArray`   | `jhort`    |
| `Int`         | `jintArray`     | `jint`     |
| `Long`        | `jlongArray`    | `jlong`    |
| `Float`       | `jfloatArray`   | `jloat`    |
| `Double`      | `jdoubleArray`  | `jdouble`  |

A family of functions that copies a region of a primitive array into a buffer.

The following table describes the specific primitive array element accessors. You should do the following substitutions:

- Replace `PrimitiveType` with one of the actual primitive element accessor routine names from the following table.
- Replace `ArrayType` with the corresponding array type.
- Replace `NativeType` with the corresponding native type for that routine.

<br>

## **Set\<PrimitiveType\>ArrayRegion**

```c++
void Set<PrimitiveType>ArrayRegion(JNIEnv *env, ArrayType array, jsize start, jsize len, const NativeType *buf);
```
| PrimitiveType | ArrayType       | NativeType |
| ------------- | --------------- | ---------- |
| `Boolean`     | `jbooleanArray` | `jboolean` |
| `Byte`        | `jbyteArray`    | `jbyte`    |
| `Char`        | `jcharArray`    | `jchar`    |
| `Short`       | `jshortArray`   | `jshort`   |
| `Int`         | `jintArray`     | `jint`     |
| `Long`        | `jlongArray`    | `jlong`    |
| `Float`       | `jfloatArray`   | `jfloat`   |
| `Double`      | `jdoubleArray`  | `jdouble`  |

A family of functions that copies back a region of a primitive array from a buffer.

The following table describes the specific primitive array element accessors. You should make the following replacements:

- Replace `PrimitiveType` with one of the actual primitive element accessor routine names from the following table.
- Replace `ArrayType` with the corresponding array type.
- Replace `NativeType` with the corresponding native type for that routine.

<br>

-----

## **Transpose Matrix JNI Example**

**Java**:

```java
private native int[][] transpose(int[][] array2D, int row, int column);
```

**C++**

```c++
extern "C" JNIEXPORT jobjectArray JNICALL Java_com_example_nativeapp_MainActivity_transpose(
        JNIEnv *env,
        jobject,
        jobjectArray arr,
        jint row,
        jint column)
{
    // Create a vector that will hold the original jintArray rows
    std::vector<jintArray> original_rows;

    // Allocate an array of pointers that will contain the copy/reference of the rows
    jint **row_elements = new jint*[row];

    for (jsize i = 0; i < row; ++i) {
        // get the `jintArray` row at index `i` of the `jobjectArray arr`, push it to a vector
        original_rows.push_back((jintArray) env->GetObjectArrayElement(arr, i));

        // create a copy/reference buffer of the aquired `jintArray`
        row_elements[i] = env->GetIntArrayElements(original_rows.back(), nullptr);
    }

    // Allocate a new C 2D array for the transpose and apply the transpose
    jint **transposed_row_elements = new jint*[column];
    for (jsize i = 0; i < column; ++i) {
        transposed_row_elements[i] = new jint[row];
        for (jsize j = 0; j < row; ++j) {
            transposed_row_elements[i][j] = row_elements[j][i];
        }
    }

    // create a new jobjectArray that will contain the transpose 2D array values
    jclass jintArrayClass = env->FindClass("[I");
    jobjectArray transposed = env->NewObjectArray(column, jintArrayClass , nullptr);

    for (jsize i = 0; i < column; ++i) {
        // create a new jintArray
        jintArray curr_row = env->NewIntArray(row);

        // set the values of the new jintArray using the values of the transposed matrix
        env->SetIntArrayRegion(curr_row, 0, row, transposed_row_elements[i]);

        // add the row jintArray to the main jobjectArray transpose matrix
        env->SetObjectArrayElement(transposed, i, curr_row);
    }

    // release the copy/reference buffers of the original rows that we got from the first loop
    for (jsize i = 0; i < row; ++i) {
        env->ReleaseIntArrayElements(original_rows[i], row_elements[i], 0);
    }

    // deallocate all of the C++ array that we allocated using C++ convention
    for (jsize i = 0; i < column; ++i) {
        delete [] transposed_row_elements[i];
    }

    delete [] transposed_row_elements;
    delete [] row_elements;

    return transposed;
}
```

## **Reverse Array JNI Example**

**Java**

```java
private native int[] reverse(int[] array, int size);
```

**C++**

```c++
extern "C" JNIEXPORT jintArray JNICALL Java_com_example_nativeapp_MainActivity_reverse(
        JNIEnv *env,
        jobject,
        jintArray arr,
        jint size)
{
    // A C array that could be a copy or a direct pointer to `arr`
    jint *reverse_array = env->GetIntArrayElements(arr, nullptr);

    // reverse the array
    for (jsize i = 0; i < size / 2; ++i) {
        jint temp = reverse_array[i];
        reverse_array[i] = reverse_array[size - 1 - i];
        reverse_array[size - 1 - i] = temp;
    }

    // free the C array and apply the changes back to the `arr`
    env->ReleaseIntArrayElements(arr, reverse_array, 0);

    return arr;
}
```