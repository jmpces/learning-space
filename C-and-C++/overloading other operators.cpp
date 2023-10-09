template <class T>
class Matrix {
private:
    std::vector<T> Data;
    int w, h;
    void SetW(int W) { w = W; };
public:
    Matrix() : w{ 0 }, h{ 0 } { };
    Matrix(int W, int H, const T& Value) { Fill(W, H, Value); }
    void Clear() { Data.clear(); };
    void Fill(int W, int H, const T& Value) { Data.clear(); Data.insert(Data.begin(), W * H, Value); SetW(W); h = H; };
    /* */ T& operator[](int Index) /* */ { return Data[Index]; }
    const T& operator[](int Index) const { return Data[Index]; }
    /* */ T& operator()(int I, int J) /* */ { return Data[J * w + I]; }
    const T& operator()(int I, int J) const { return Data[J * w + I]; }
    int GetW() const { return w; }
    int GetH() const { return h; }
    void ForEach(const std::function<void(T& Value)>& Func) {
        std::for_each(Data.begin(), Data.end(), Func);
    };
};