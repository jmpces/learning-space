<!--=====================================================================================-->
<details>
<summary><b>Template</b></summary>
<br>
<ul>
    
this is a dropdown

</ul>
</details>

<!--=====================================================================================-->
<details>
<summary><b>Reading & Writing from a binary file</b></summary>
<br>
<ul>
    
**open modes**

| Open mode | Effects | Must the file Exist? |
| --- | --- | --- |
| ```ios::in \| ios::out``` | To open the file for input and output. | yes |
| ```ios::in \| ios::out \| ios::trunc``` | Opens the file for input and output. If the file already exists, it will be truncated. | no |
| ```ios::in \| ios::out \| ios::app``` | Opens the file for input and output. If the file does not exist, it will be created. Before each writing access, a seek to end is performed. | no |

---------
    
**pointers for file stream pointer or any other stream classes**
    
- ```tellp()``` - returns a long int that tells the current position of the put pointer (write)
- ```tellg()``` - returns a long int that tells the current position of the get pointer (read)
- ```seekp(pos,posflag)``` - modifies the current position of the put pointer (write) [If you do not specify a positioning flag, the position will be assumed to be relative to
the beginning of the file]
- ```seekg(pos,posflag)``` - modifies the current position of the get pointer (read) [If you do not specify a positioning flag, the position will be assumed to be relative to
the beginning of the file]

---------

**position flags**
    
- ```ios::beg``` - Beginning of the file
- ```ios::cur``` - Current position
- ```ios::end``` - End of the file

---------

**state flags**
    
- ios::eofbit - end of file reached
- ios::failbit - last read or write operation failed
- ios::badbit - an irrecoverable error occurred
- ios::goodbit - the stream is ok, e.g. no other state flag is set.

<br>
    
**method to discover current state flag, they return true when the corresponding flag has been raised.**
    
- eof()
- fail()
- bad()
- good()
    
<br>
    
**check for end of file**
```c++
if( fstr.eof() ) {}
// or
if( myfile.rdstate() == ios::badbit ) {}
```
    
<br>
    
**read current state**
```.rdstate() == <STATUS_FLAG>```
    
<br>

**clear current status flag**
```.clear()```

---------

**write format**
    
```c++
file.write(reinterpret_cast<const char*>(&VAR/ARRAY[INDEX]),sizeof(DATA_TYPE_OF_VAR/ARRAY)*NUM_OF_ELEMENT_YOU_WANT_TO_WRITE);
```
    
**read format**
    
```c++
file.read(reinterpret_cast<char*>(&VAR/ARRAY[INDEX]),sizeof(DATA_TYPE_OF_VAR/ARRAY)*NUM_OF_ELEMENT_YOU_WANT_TO_WRITE);
````
    
NOTE: for **single variables** the ```NUM_OF_ELEMENT_YOU_WANT_TO_WRITE``` is equal to ```1``` or you can omit the ```*NUM_OF_ELEMENT_YOU_WANT_TO_WRITE```

**reading**
```C++
std::ifstream binFile("binaryFile", std::ios::in | std::ios::binary);
if (!binFile.is_open()) throw std::argument_error("the given filename might not be existing");

unsigned char binValues[8];
binFile.read(reinterpret_cast<char*>(&binValues[0]),sizeof(unsigned char)*8);
```
    
**writing**
```C++
std::ofstream binFile("binaryFile", std::ios::out | std::ios::binary);
if (!binFile.is_open()) throw std::argument_error("the given filename might not be existing");
    
unsigned char binValues[8];
binFile.write(reinterpret_cast<const char*>(&binValues[0]),sizeof(unsigned char)*8);
```
    
**A sample Program**
```c++
#include <iostream>
#include <exception>

int main()
{
    #ifdef WRITE_PROG
        std::fstream writeBinFile("binaryFile", std::ios::in | std::ios::out | std::ios::binary);
        if (!writeBinFile.is_open()) throw std::logic_error("the given filename might not be existing");

        unsigned char binValues[8] { 't','h','i','s',' ','h','o','t' };
        long negative = -777;

        writeBinFile.write(reinterpret_cast<const char*>(&binValues[0]),sizeof(unsigned char)*4);
        writeBinFile.write(reinterpret_cast<const char*>(&negative),sizeof(long)*1);
        writeBinFile.write(reinterpret_cast<const char*>(&binValues[4]),sizeof(unsigned char)*4);
        writeBinFile.close();
    #endif

    #ifdef READ_PROG
        std::fstream readBinFile("binaryFile", std::ios::in | std::ios::out | std::ios::binary);
        if (!readBinFile.is_open()) throw std::logic_error("the given filename might not be existing");

        unsigned char readValues[8];
        long readNum;
        readBinFile.read(reinterpret_cast<char*>(&readValues[0]),sizeof(unsigned char)*4);
        readBinFile.read(reinterpret_cast<char*>(&readNum),sizeof(long)*1);
        readBinFile.read(reinterpret_cast<char*>(&readValues[4]),sizeof(unsigned char)*4);
        std::cout << "read = " << readValues << "\n";
        std::cout << "number = " << readNum << "\n";
        readBinFile.close();
    #endif
}
```
    
----------
    
**reading files by chunk**

- calling the ```write()``` method will automatically change the position of put pointer
- calling the ```read()``` method will automatically change the position of get pointer

```c++
#define CHUNK_SIZE 1024;
    
char *tbuffer = new char[CHUNK_SIZE]; // CHUNK_SIZE in bytes
char optional_initial_reads[16];

std::ifstream curr_file(filename,std::ios::binary);

curr_file.read(optional_initial_reads,16);
    
while(!curr_file.eof())
{
    curr_file.read(tbuffer,CHUNK_SIZE);
    size_t read_buffer_size = curr_file.gcount();

    if(!curr_file.eof())
    {
        // not last chunk operations
    }
    else
    {
        // last chunk operations
    }
} 
```

</ul>
</details>

<!--=====================================================================================-->
<details>
<summary><b>Smart Pointers</b></summary>
<br>
<ul>

```c++
#include <memory> // <- access all smart pointers
```

<!--=====================================================================================-->
<details>
<summary><b>unique_ptr</b></summary>
<br>
<ul>

```c++
std::unique_ptr<myClass> myObj = std::make_unique<myClass>();
```

- this smart pointer calls the delete automatically for a heap allocated object/array when the pointer goes out of scope
- unique pointers cannot be copied to another unique_ptr or other smart pointers, but you can copy it on a raw pointer using the ```.get()``` method
```c++
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int[]> arr1(new int[10]); // <- declaration, in some cases you might want to use the std::make_unique to be safer
    std::unique_ptr<int[]> arr2 = arr1; // <- error
    int* arr3 = arr1.get(); // <- allowed

    for(size_t i=0; i<10; ++i)
        arr1[i] = i+1;

    arr3[2] = -2;

    for(size_t i=0; i<10; ++i)
        std::cout << arr1[i] << " ";

    std::cout << "\n";
    return 0;
}

```

if you compile this with ```-fsanitize=address``` even though we did not ```delete``` the allocated array, the program will not throw an error

output: ```1 2 -2 4 5 6 7 8 9 10```

</ul>
</details>

<!--=====================================================================================-->
<details>
<summary><b>shared_ptr</b></summary>
<br>
<ul>

- this smart pointer contains reference counts and only free or call delete if the reference count goes to zero

```c++
#include <iostream>
#include <memory>

class Subject
{
    public:
        std::string name;
        short credits;
        int* arr;
        Subject(std::string name, short credits) : name(name), credits(credits), arr(new int[10])
        {
            for(size_t i=0; i<10; ++i) arr[i] = i;
        }
        ~Subject() { std::cout << "\tDestroyed = \n"; display(); }
        void display()
        {
            std::cout << "\tsubject name : " << name << "\n"
                      << "\tcredits      : " << credits << "\n\t";
            for(size_t i=0; i<10; ++i) std::cout << arr[i] << " ";
            std::cout << "\n";
            delete [] arr;
        }
};

int main()
{
    std::cout << "Enter main scope \n";
    {
        std::cout << "\tEnter inner scope 1 \n";
        std::shared_ptr<Subject> outside_ptr;
        {
            std::cout << "\t\tEnter inner scope 2 \n";
            std::shared_ptr<Subject> math = std::make_shared<Subject>("Math Modern Wolrd",3);
            
            outside_ptr = math;

            std::cout << "\t\tExit inner scope 2 \n";
        }
        std::cout << "\tExit inner scope 1 \n";
    }
    std::cout << "Exit main scope \n";
    return 0;
}

```

output
```
Enter main scope 
        Enter inner scope 1 
                Enter inner scope 2 
                Exit inner scope 2 
        Exit inner scope 1 
        Destroyed = 
        subject name : Math Modern Wolrd
        credits      : 3
Exit main scope 
```

</ul>
</details>
                   
</ul>
</details>

<!--=====================================================================================-->
<details>
<summary><b>down casting & dynamic_cast</b></summary>
<br>
    
- **Upcasting** - assigning a pointer of a ```derived class``` into a ```base class``` (usually done by the compiler implicitly so there is not problems with this)
- **Down casting** - the act for assigning a pointer of a ```base class``` to a ```derived class```, here we should use dynamic_cast for safe casting

<br>
    
**A sample program showing how to use a dynamic cast**
    
NOTE: dynamic_cast can only be used in polymorphic classes, or classes with virtual functions
    
```c++
#include <iostream>
#include <vector>

class person
{
    private:
        std::string name;
    
    public:
        person(const std::string& ID, const std::string& name, unsigned int age, char gender)
        : ID(ID), name(name), age(age), gender(gender) {}

        std::string ID;

        std::string getName() { return name; }
        virtual ~person() { /* Note: Destructors should always have a definition */ }
};

class student : public person
{
    public:
        student(const std::string& ID, const std::string& name, unsigned int age, char gender)
        : person(ID,name,age,gender), Student_ID("0xFFHG"+ID) {}

        std::string Student_ID;

        ~student() { /* an empty definition */ }
};

class teacher : public person
{
    public:
        teacher(const std::string& ID, const std::string& name, unsigned int age, char gender)
        : person(ID,name,age,gender), Teacher_ID("0xFAHJ"+ID) {}

        std::string Teacher_ID;

        ~teacher() { /* an empty definition */ }
};

int main()
{
    person* Micha = new student("0232-1232","Micha", 21, 'F');
    person* Aldino = new teacher("2445-8270","Aldino", 33, 'M');

    student* student1 = dynamic_cast<student*>(Micha);
    student* student2 = dynamic_cast<student*>(Aldino);

    // ---------- check if student 1 is a real student ----------
    if(student1!=NULL)
        std::cout << student1->getName() << " is a real student\n";
    else
        std::cout << "Detected a fake student\n";
    
    // ---------- check if student 2 is a real student ----------
    if(student2!=NULL)
        std::cout << student2->getName() << " is a real student\n";
    else
        std::cout << "Detected a fake student\n";
    
    return 0;
}
```
    
**Output if dynamic_cast is used**
```shell
Micha is a real student
Detected a fake student
```

**Output if static_cast is used**
```shell
Micha is a real student
Aldino is a real student
```
   
</details>
