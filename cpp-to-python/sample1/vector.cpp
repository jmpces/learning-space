#include <iostream>
#include <cstring>

class IntVector{
    public:
        int *array;
        unsigned long length;
        unsigned long capacity;
        
        IntVector()
        {
            array = new int[16];
            length = 0;
            capacity = 16;
        }

        void append(int value)
        {
            if(length==capacity)
            {
                capacity*=2;
                int *reallocate_array = new int[capacity];
                memcpy(reallocate_array,array,length*sizeof(int));
                delete [] array;
                array = reallocate_array;
            }
            array[length++] = value;
        }

        void display()
        {
            for(size_t i=0; i<length; ++i)
                std::cout << array[i] << ' ';
            std::cout << "\n";
        }

        ~IntVector()
        {
            delete [] array;
        }
};

extern "C"
{
    IntVector* cpp_initialize()
    {
        return new IntVector();
    }

    int cpp_index(IntVector* obj, unsigned long int index)
    {
        return obj->array[index];
    }

    int* cpp_array(IntVector* obj)
    {
        return obj->array;
    }

    unsigned long cpp_length(IntVector* obj)
    {
        return obj->length;
    }

    void cpp_append(IntVector* obj, int value){
        obj->append(value);
    }

    void cpp_display(IntVector* obj)
    {
        obj->display();
    }

    void cpp_destroy(IntVector* instance)
    {
        delete instance;
    }
}

// compile and run
// g++ -c -fPIC vector.cpp -o IntVec.o -fsanitize=address
// g++ -shared -Wl,-soname,libIntVec.so -o libIntVec.so IntVec.o
// python3 vectortest.py