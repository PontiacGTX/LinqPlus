# LinqPlus
A Single C++ header file that contains some of the functions that are used in C#'s Linq, using C++17 Standard

# Usage

the header and namespace should be included
```cpp

#include "LinqPlus.h"

using namespace Linqp;

```

To be able to instantiate the LinqPlus class you should  call the from function
```cpp

Vector<int> *vector = new Vector<int> { 1, 2, 3, 45, 6, 7, 8, 91, 12, 4, 1, 2 ,91,45,100,125,200};

//take an int vector take elements higher than 40 and cast to double then store it in a std::list
auto result = from(vector).Where([](int x) { return x >40;}).Select([](int x) { return  (double)x;  }).ToList();

//select distinct doubles into a vector of double
auto vec = from(result).Distinct().ToVector();

//check if exist any double higher than 50.0 in the vec std::vector<double>
auto foundHigher = from(vec).Any([](double x){ return x > 50.0 ; });

//to read a bmp image onto a color Vector
std::string imagePath ="image.bmp";
auto imagePixels = from(imagePath,Data::Image,true).ToColorVector();

//to read file's bytes
auto byteVector = from(imagePath,2,true).ReadAllBytes().ToVector();

//push std::string into a std::vector<std::string> then sort by descending order 

std::vector < std::string > strvec;
strvec.push_back("d");
strvec.push_back("c");
strvec.push_back("b");
strvec.push_back("a");

auto sortedStringVector = from(strvec).OrderBy([](const std::string& lhs, std::string& rhs) {return lhs < rhs; }).ToVector();

```
# Limitations


It requires that the user manages the heap allocated container assigned by either of the To{stdcontainer}() functions

`PairWith()` should only be used when the container in from() has a same length

# Credit
I would like to thank to melak47 for the contribution to this project.
