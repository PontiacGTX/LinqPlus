# LinqPlus
A Single C++ header file that contains some of the functions that are used in C#'s Linq, using C++17 Standard

# Usage

the header and namespace should be included
```
#include "LinqPlus.h"

using namespace Linqp;

```

To be able to instantiate the LinqPlus class you should  call the from function
```

Vector<int> *vector = new Vector<int> { 1, 2, 3, 45, 6, 7, 8, 91, 12, 4, 1, 2 };


auto result = from(vector).Where([](int x) { return x >40;}).Select([](int x) { return  (double)x;  }).ToList();
auto vec = from(result).Distinct().ToVector();
auto foundHigher = from(vec).Any([](int x){ return x > 50.0 ; });
//to read a bmp image onto a color Vector
std::string imagePath ="image.bmp";
auto image = from(imagePath,0).ToColorVector();
//to read file's bytes
auto byteVector = from(imagePath,2).ReadAllBytes().ToVector();

```
# Limitations

For now I have only implemented how to read images using Bitmaps(.bmp) under Windows through GDIPlus API and Colors Could be output only as a `std::vector<Color>`


# Credit
I would like to thank to melak47 for the contribution to this project.
