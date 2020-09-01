## Array and String

### Array
```c++
#include <iostream>

int main() {
    // 1. Initialize
    int a0[5];
    int a1[5] = {1, 2, 3};  // other element will be set as the default value
    // 2. Get Length
    int size = sizeof(a1) / sizeof(*a1);
    cout << "The size of a1 is: " << size << endl;
    // 3. Access Element
    cout << "The first element is: " << a1[0] << endl;
    // 4. Iterate all Elements
    cout << "[Version 1] The contents of a1 are:";
    for (int i = 0; i < size; ++i) {
        cout << " " << a1[i];
    }
    cout << endl;
    cout << "[Version 2] The contents of a1 are:";
    for (int& item: a1) {
        cout << " " << item;
    }
    cout << endl;
    // 5. Modify Element
    a1[0] = 4;
    // 6. Sort
    sort(a1, a1 + size);
}
```


```java
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        // 1. Initialize
        int[] a0 = new int[5];
        int[] a1 = {1, 2, 3};
        // 2. Get Length
        System.out.println("The size of a1 is: " + a1.length);
        // 3. Access Element
        System.out.println("The first element is: " + a1[0]);
        // 4. Iterate all Elements
        System.out.print("[Version 1] The contents of a1 are:");
        for (int i = 0; i < a1.length; ++i) {
            System.out.print(" " + a1[i]);
        }
        System.out.println();
        System.out.print("[Version 2] The contents of a1 are:");
        for (int item: a1) {
            System.out.print(" " + item);
        }
        System.out.println();
        // 5. Modify Element
        a1[0] = 4;
        // 6. Sort
        Arrays.sort(a1);
    }
}
```

### Dynamic Array
```c++
#include <iostream>

int main() {
    // 1. initialize
    vector<int> v0;
    vector<int> v1(5, 0);
    // 2. make a copy
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);
    // 2. cast an array to a vector
    int a[5] = {0, 1, 2, 3, 4};
    vector<int> v4(a, *(&a + 1));
    // 3. get length
    cout << "The size of v4 is: " << v4.size() << endl;
    // 4. access element
    cout << "The first element in v4 is: " << v4[0] << endl;
    // 5. iterate the vector
    cout << "[Version 1] The contents of v4 are:";
    for (int i = 0; i < v4.size(); ++i) {
        cout << " " << v4[i];
    }
    cout << endl;
    cout << "[Version 2] The contents of v4 are:";
    for (int& item : v4) {
        cout << " " << item;
    }
    cout << endl;
    cout << "[Version 3] The contents of v4 are:";
    for (auto item = v4.begin(); item != v4.end(); ++item) {
        cout << " " << *item;
    }
    cout << endl;
    // 6. modify element
    v4[0] = 5;
    // 7. sort
    sort(v4.begin(), v4.end());
    // 8. add new element at the end of the vector
    v4.push_back(-1);
    // 9. delete the last element
    v4.pop_back();
}
```

```java
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        // 1. initialize
        List<Integer> v0 = new ArrayList<>();
        List<Integer> v1;                           // v1 == null
        // 2. cast an array to a vector
        Integer[] a = {0, 1, 2, 3, 4};
        v1 = new ArrayList<>(Arrays.asList(a));
        // 3. make a copy
        List<Integer> v2 = v1;                      // another reference to v1
        List<Integer> v3 = new ArrayList<>(v1);     // make an actual copy of v1
        // 3. get length
        System.out.println("The size of v1 is: " + v1.size());
        // 4. access element
        System.out.println("The first element in v1 is: " + v1.get(0));
        // 5. iterate the vector
        System.out.print("[Version 1] The contents of v1 are:");
        for (int i = 0; i < v1.size(); ++i) {
            System.out.print(" " + v1.get(i));
        }
        System.out.println();
        System.out.print("[Version 2] The contents of v1 are:");
        for (int item : v1) {
            System.out.print(" " + item);
        }
        System.out.println();
        // 6. modify element
        v2.set(0, 5);       // modify v2 will actually modify v1
        System.out.println("The first element in v1 is: " + v1.get(0));
        v3.set(0, -1);
        System.out.println("The first element in v1 is: " + v1.get(0));
        // 7. sort
        Collections.sort(v1);
        // 8. add new element at the end of the vector
        v1.add(-1);
        v1.add(1, 6);
        // 9. delete the last element
        v1.remove(v1.size() - 1);
    }
}
```

### 2D Array

```c++
#include <iostream>

template <size_t n, size_t m>
void printArray(int (&a)[n][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Example I:" << endl;
    int a[2][5];
    // 2495072 0 1 0 1187757920
    // 32764 3891941 0 54610656 0 
    printArray(a);   
    cout << "Example II:" << endl;
    int b[2][5] = {{1, 2, 3}};
    // 1 2 3 0 0
    // 0 0 0 0 0 
    printArray(b);
    cout << "Example III:"<< endl;
    int c[][5] = {1, 2, 3, 4, 5, 6, 7};
    // 1 2 3 4 5 
    // 6 7 0 0 0
    printArray(c);
    cout << "Example IV:" << endl;
    int d[][5] = {{1, 2, 3, 4}, {5, 6}, {7}};
    // 1 2 3 4 0 
    // 5 6 0 0 0 
    // 7 0 0 0 0 
    printArray(d);
}
```

```java
// "static void main" must be defined in a public class.
public class Main {
    private static void printArray(int[][] a) {
        for (int i = 0; i < a.length; ++i) {
            System.out.println(a[i]);
        }
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; a[i] != null && j < a[i].length; ++j) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        System.out.println("Example I:");
        int[][] a = new int[2][5];
        // [I@4a574795
        // [I@f6f4d33
        // 0 0 0 0 0 
        // 0 0 0 0 0 
        printArray(a);
        System.out.println("Example II:");
        int[][] b = new int[2][];
        // null
        // null
        printArray(b);
        System.out.println("Example III:");
        b[0] = new int[3];
        b[1] = new int[5];
        // [I@38af3868
        // [I@77459877
        // 0 0 0 
        // 0 0 0 0 0 
        printArray(b);
    }
}
```

### String Compare Function
```c++

```

```java

```

### String Immutable or Mutable
```c++

```

```java

```

### String Extra Operations
```c++

```

```java

```

