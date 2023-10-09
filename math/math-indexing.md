# **The Math Of Indexing Arrays**

The matrices here are assumed to be in the **Row Major Order**.

- $A$ = array.
- $M$ = matrix.
- $h$ = height of matrix.
- $w$ = width of matrix.
- **i** = row number.
- **j** = column number.

### **Creating 1D array as 2D array**

$M[h,w] = A[h \cdot w]$

To create a 1D array matrix representation, we just set the
total elements of the 1D array into `height * width` of the 2D array
or matrix.

## *NOTE: the example below obeys the following constraints:*

- $0 \leq i < h$
- $0 \leq j < w$
- $n + i < h$ **or** $n + j < w$
- $n - i \leq 0$ **or** $n - j \leq 0$

### **Indexing 1D arrays as a 2D array / Matrix**

$M_{i,j} = A_{(i \cdot w + j)}$

### **Downward Traversal**

- **by 1 cell**

    $M_{i+1,j} = A_{((i+1) \cdot w + j)} = A_{(i \cdot w + j) + w} =  A_{index + w}$

- **by n cell**

    $M_{i+n,j} = A_{((i+n) \cdot w + j)} = A_{(i \cdot w + j) + (n \cdot w)} =  A_{index + (n \cdot w)}$

### **Upward Traversal**

- **by 1 cell**

    $M_{i-1,j} = A_{((i-1) \cdot w + j)} = A_{(i \cdot w + j) - w} =  A_{index - w}$

- **by n cell**

    $M_{i-n,j} = A_{((i-n) \cdot w + j)} = A_{(i \cdot w + j) - (n \cdot w)} =  A_{index - (n \cdot w)}$

### **Leftward Traversal**

- **by 1 cell**

    $M_{i,j-1} = A_{(i \cdot w + j - 1)} = A_{(i \cdot w + j) - 1} = A_{index-1}$

- **by n cell**

    $M_{i,j-1} = A_{(i \cdot w + j - n)} = A_{(i \cdot w + j) - n} = A_{index-n}$

### **Rightward Traversal**

- **by 1 cell**

    $M_{i,j+1} = A_{(i \cdot w + j + 1)} = A_{(i \cdot w + j) + 1} = A_{index+1}$

- **by n cell**

    $M_{i,j+1} = A_{(i \cdot w + j + n)} = A_{(i \cdot w + j) + n} = A_{index+n}$

### **Down-Left Traversal**

- **by 1 cell**

    $M_{i+1, j-1} = A_{((i+1) \cdot w+j-1)} = A_{(i \cdot w+j) + w-1} =  A_{index+w-1}$

- **by n cell**

    $M_{i+n,j-n} = A_{((i+n) \cdot w+j-n)} = A_{(i \cdot w+j)+(n \cdot w)-n} =  A_{index+(n \cdot w)-n}$

### **Up-Left Traversal**

- **by 1 cell**

    $M_{i-1, j-1} = A_{((i-1) \cdot w+j-1)} = A_{(i \cdot w+j) - w-1} =  A_{index-w-1}$

- **by n cell**

    $M_{i-n,j-n} = A_{((i-n) \cdot w+j-n)} = A_{(i \cdot w+j)-(n \cdot w)-n} =  A_{index-(n \cdot w)-n}$

### **Down-Right Traversal**

- **by 1 cell**

    $M_{i+1,j+1} = A_{((i+1) \cdot w+j+1)} = A_{(i \cdot w+j) + w+1} =  A_{index+w+1}$

- **by n cell**

    $M_{i+n,j+n} = A_{((i+n) \cdot w+j+n)} = A_{(i \cdot w+j)+(n \cdot w)+n} =  A_{index+(n \cdot w)+n}$

### **Up-Right Traversal**

- **by 1 cell**

    $M_{i-1,j+1} = A_{((i-1) \cdot w+j+1)} = A_{(i \cdot w+j) - w+1} =  A_{index-w+1}$

- **by n cell**

    $M_{i-n,j+n} = A_{((i-n) \cdot w+j+n)} = A_{(i \cdot w+j)-(n \cdot w)+n} =  A_{index-(n \cdot w)+n}$