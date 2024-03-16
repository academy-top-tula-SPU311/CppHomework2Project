#include <iostream>
#include <iomanip>

void ArrayInit(int* array, int size);
void ArrayPrint(int* array, int size);
void ArrayReverce(int* array, int size);
int ArrayMaxIndex(int* array, int size, int begin = 0);
void ArraySubReverce(int* array, int size, int begin, int end);

void ArraySortCacke(int* array, int size);

void NumberToBase(int number, int base);

void Swap(int& a, int& b);

int StringCharIndex(const char* str, char symbol);
int StringCharCount(const char* str, char symbol);


int main()
{
    srand(time(nullptr));

    /*int size{ 10 };
    int* array = new int[size];
    ArrayInit(array, size);
    ArrayPrint(array, size);*/
    //ArrayReverce(array, size);
    //ArraySubReverce(array, size, 3, 8);
    /*ArraySortCacke(array, size);
    ArrayPrint(array, size);*/

    //NumberToBase(15873, 16);

    const int rows{ 7 };
    const int cols{ 12 };

    int matrix[rows][cols]{};

    int count{};

    /*for (int i{}; i < rows; i++)
    {
        if (i & 1)
            for (int j{ cols - 1 }; j >= 0; j--)
                matrix[i][j] = ++count;
        else
            for(int j{}; j < cols; j++)
                matrix[i][j] = ++count;
    }*/

    /*for (int j{}; j < cols; j++)
    {
        if (j & 1)
            for (int i{ rows - 1 }; i >= 0; i--)
                matrix[i][j] = ++count;
        else
            for (int i{}; i < rows; i++)
                matrix[i][j] = ++count;
    }*/

    bool ltor{ true };
    bool utod{ true };
    int left{};
    int right{ cols - 1 };
    int top{};
    int bottom{ rows - 1 };

    while (count < rows * cols)
    {
        if (ltor)
        {
            for (int j{ left }; j <= right; j++)
                matrix[top][j] = ++count;
            top++;
        }
        else
        {
            for (int j{ right }; j >= left; j--)
                matrix[bottom][j] = ++count;
            bottom--;
        }
            
        ltor = !ltor;

        if (utod)
        {
            for (int i{ top }; i <= bottom; i++)
                matrix[i][right] = ++count;
            right--;
        }
        else
        {
            for (int i{ bottom }; i >= top; i--)
                matrix[i][left] = ++count;
            left++;
        }
        utod = !utod;

            
    }

    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < cols; j++)
            std::cout << std::setw(3) << matrix[i][j];
        std::cout << "\n";
    }
}

void ArrayInit(int* array, int size)
{
    for (int i{}; i < size; i++)
        *(array + i) = rand() % 100;
}

void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void ArrayReverce(int* array, int size)
{
    for (int i{}; i < size / 2; i++)
        Swap(array[i], array[size - 1 - i]);
}

void ArraySubReverce(int* array, int size, int begin, int end)
{
    for (int i{}; i < (end - begin + 1) / 2; i++)
        Swap(array[begin + i], array[end - i]);
}

int ArrayMaxIndex(int* array, int size, int begin)
{
    int index{ begin };
    for (int i{ begin }; i < size; i++)
        if (array[i] > array[index])
            index = i;
    return index;
}

void ArraySortCacke(int* array, int size)
{
    int maxCacke;
    for (int i{}; i < size - 1; i++)
    {
        maxCacke = ArrayMaxIndex(array, size, i);
        ArraySubReverce(array, size, maxCacke, size - 1);
        ArraySubReverce(array, size, i, size - 1);
    }
}

void NumberToBase(int number, int base)
{
    if (number >= base)
        NumberToBase(number / base, base);
    int mod = number % base;
    
    if (mod < 10) 
        std::cout << mod;
    else 
        std::cout << (char)(55 + mod);
    //std::cout << (mod < 10) ? mod : (char)(55 + mod);
}

void Swap(int& a, int& b)
{
    int temp{ a };
    a = b;
    b = temp;
}

int StringCharIndex(const char* str, char symbol)
{
    //for(int i{}; i < strlen(str); )
    int i{};
    while (str[i])
    {
        if (str[i] == symbol) return i;
        i++;
    }
        
    return -1;
}

int StringCharCount(const char* str, char symbol)
{
    int count{};

    for (int i{}; i < strlen(str); i++)
        if (symbol == str[i]) count++;
    return count;
}
