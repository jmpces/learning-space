# **JNI Basic Examples**

## **Matrix Transpose - example use case of JNI Arrays**
```c++
extern "C" JNIEXPORT jobjectArray JNICALL Java_com_example_myapp_MainActivity_transpose (
  JNIEnv *env,
  jobject,
  jobjectArray arr,
  jint row,
  jint column
) {
  // Create a vector that will hold the original jintArray rows
  std::vector<jintArray> original_rows;

  // Allocate an array of pointers that will contain the copy/reference of the rows
  jint **row_elements = new jint *[row];

  for (jsize i = 0; i < row; ++i) {
    // get the `jintArray` row at index `i` of the `jobjectArray arr`, push it to a vector
    original_rows.push_back((jintArray) env->GetObjectArrayElement(arr, i));

    // create a copy/reference buffer of the aquired `jintArray`
    row_elements[i] = env->GetIntArrayElements(original_rows.back(), nullptr);
  }

  // Allocate a new C 2D array for the transpose and apply the transpose
  jint **transposed_row_elements = new jint *[column];
  for (jsize i = 0; i < column; ++i) {
    transposed_row_elements[i] = new jint[row];
    for (jsize j = 0; j < row; ++j) {
      transposed_row_elements[i][j] = row_elements[j][i];
    }
  }

  // create a new jobjectArray that will contain the transpose 2D array values
  jclass jintArrayClass = env->FindClass("[I");
  jobjectArray transposed = env->NewObjectArray(column, jintArrayClass, nullptr);

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
    delete[] transposed_row_elements[i];
  }

  delete[] transposed_row_elements;
  delete[] row_elements;

  return transposed;
}
```

## **Things to remember when using JNI for multiple threads**
- Don't use the main `JNIEnv *env` from other threads, instead create a new `JNIEnv *pointer` for that thread:

  **On higher accessible scope**
  ```c++
  JavaVM* javaVM;
  env->GetJavaVM((_JavaVM**) &javaVM);
  ```
  
  **On the start of the thread**
  ```c++
  JNIEnv* threadEnv;
  javaVM->AttachCurrentThread((_JNIEnv**) &threadEnv, NULL);
  ```
  Now use the `threadEnv` for the current thread instead of the original `env`.
  
  **At the end of the thread, or whenever before the thread terminates**
  
  ```c++
  javaVM->DetachCurrentThread();
  ```

- Don't use `FindClass` in another thread.
- Create a `jobject` reference for `jobject` and `jclass` (_and probably other types_) that are accessed by a thread from outside of its code block using `NewGlobalRef`, and when all threads are done accessing it, deleted it using `DeleteGlobalRef`.
