# from ctypes import windll
from ctypes import *

lib = cdll.LoadLibrary('./libIntVec.so')

class IntVector(object):
    def __init__(self):
        """
        internal constructor
        """
        self.iterator = 0
        self.obj = lib.cpp_initialize()

    def __str__(self):
        """
        returns the string to be displayed when "print(self)" is called.
        """
        to_string = ""
        for num in self:
            to_string += (str(num) + " ")
        return to_string

    def __repr__(self):
        """
        returns the object to be displayed when ">>> self" is called like it was in python command line.
        """
        return self.__str__()

    def __getitem__(self,index):
        """
        operator[].
        """
        return lib.cpp_index(self.obj,c_ulong(index))

    def __len__(self):
        """
        returns the int length value when "len(self)" is called."""
        return self.size()

    def __iter__(self):
        """
        called once everytime "for x in self:" is used.
        """
        self.iterator = 0
        return self
    
    def __next__(self):
        """
        called manytimes when "for x in self:" is used.
        called once when "next(self)" is called.
        """
        cur_index = self.iterator
        if self.iterator < self.size():
            self.iterator += 1
            return self[cur_index]
        else:
            self.iterator = 0
            raise StopIteration

    def append(self,value):
        lib.cpp_append(self.obj,c_int(value))

    def size(self):
        return lib.cpp_length(self.obj)

    def array(self):
        return lib.cpp_array(self.obj)

    def display(self):
        lib.cpp_display(self.obj)

    def __del__(self):
        lib.cpp_destroy(self.obj)

def IntVectorCreate(arrayList):
    """
    function constructor
    """
    temp = IntVector()
    for n in arrayList:
        temp.append(n)
    return temp
