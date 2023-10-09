### Overloading >> and << operator
```c++
#include <iostream>
#include <cstring>

class HexString
{
    public:

    unsigned char* data;
    size_t length;

    HexString(unsigned char* src, size_t n) : data(new unsigned char[n]), length(n)
    {
        memcpy(data,src,n);
    }

    HexString(size_t n) : data(new unsigned char[n]), length(n) {}

    ~HexString()
    {
        delete [] data;
    }
};

std::ostream& operator<<(std::ostream& outputStream, const HexString& instance)
{
    for(size_t i=0; i<instance.length; ++i)
            outputStream << static_cast<unsigned int>(instance.data[i]) << ' ';
        return outputStream;
}

std::istream& operator>>(std::istream& inputStream, HexString& instance)
{
    for(size_t i=0; i<instance.length; ++i)
        inputStream >> instance.data[i];
    return inputStream;
}

int main()
{
    unsigned char arr[] = { 0x80, 0xf7, 0x32, 0xfd };

    HexString hexcontain(arr,sizeof(arr));

    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << hexcontain << "\n";

    std::cin >> hexcontain;
    std::cout << hexcontain << "\n";
}
```

