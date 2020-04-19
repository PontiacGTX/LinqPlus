#ifndef LINQ_PLUS_H
#define LINQ_PLUS_H

#include <stdexcept>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <forward_list>
#include <map>
#include <deque>
#include <array>
#include <type_traits>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_map>
#include <charconv>

#pragma region WindowsLib
#ifdef _WIN32

#include <Windows.h>
#include <gdiplus.h>
#include <gdipluspixelformats.h>

#pragma comment(lib,"gdiplus.lib")
#endif // _WIN32
#pragma endregion 

#pragma region DefineSection
#define var auto
#define Template template
#define Vector std::vector 
#define Map std::map
#define Stack std::stack
#define Deque std::deque
#define List std::list
#define ForwardList std::forward_list
#define UnorderedMultimap std::unordered_multimap 
#define Multimap std::multimap
#define Pair std::pair
#define MakePair std::make_pair
typedef unsigned char byte;
#pragma endregion


namespace Linqp
{
#pragma warning(disable:4172)
	
#pragma region EnumClasses
    enum class Data
	{
		BMP = 0,
		Image =1,
		Data = 2,
		Read=3,
	};
#pragma endregion
/*
	template<typename T>
	class Array_t
	{
		static Array_t<T>* Begin;
		unsigned long long count;
	public:

		void* operator new[](size_t sz)
		{
			void* p = (Array_t*)calloc((sz / 16), (sz / 16) * sizeof(Array_t));
			Begin->Begin = (Array_t<T>*)p;
			Begin->count = (sz / 16);

			return p;
		}

		T& operator[](unsigned long long index)
		{
			if (index && index < count)
				return val;

			throw std::exception("Out of range");
		}

		friend std::ostream& operator<<(std::ostream& os, const Array_t<T>& arr)
		{
			os << arr.val;
			return os;
		}

		friend std::istream& operator<<(std::istream& is, const Array_t<T>& arr)
		{
			is >> arr.val;
			return is;
		}

		template<typename Type>
		friend  bool operator>(const Array_t<T>& lhs, const Type& rhs)
		{
			return lhs.val > rhs;
		}

		template<typename Type>
		friend  bool operator<(const Array_t<T>& lhs, const Type& rhs)
		{
			return lhs.val < rhs;
		}

		friend  bool operator>(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val > rhs.val;
		}

		friend  bool operator<(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val < rhs.val;
		}
		template<typename Type>
		friend  T operator+(const Array_t<T>& lhs, const Type& rhs)
		{
			return lhs.val + rhs;
		}
		template<typename Type>
		friend  T operator-(const Array_t<T>& lhs, const Type& rhs)
		{
			return lhs.val - rhs;
		}
		template<typename Type>
		friend  T operator*(const Array_t<T>& lhs, const Type& rhs)
		{
			return lhs.val * rhs;
		}
		template<typename Type>
		friend  T operator/(const Array_t<T>& lhs, const Type& rhs)
		{
			return lhs.val / rhs;
		}

		friend  T operator+(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val + rhs.val;
		}

		friend  T operator-(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val - rhs.val;
		}

		friend  T operator*(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val * rhs.val;
		}

		friend  T operator/(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val / rhs.val;
		}

		friend  bool  operator==(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return lhs.val == rhs.val;
		}
		friend  bool  operator!=(const Array_t<T>& lhs, const Array_t<T>& rhs)
		{
			return !(lhs.val == rhs.val);
		}

		inline T& operator+=(const Array_t& rhs)
		{
			this->val = this->val + rhs.val;

			return this->val;
		}

		inline T& operator-=(const Array_t& rhs)
		{
			this->val = this->val - rhs.val;

			return this->val;
		}
		inline T& operator*=(const Array_t& rhs)
		{
			this->val = this->val * rhs.val;

			return this->val;
		}
		inline T& operator/=(const Array_t& rhs)
		{
			this->val = this->val / rhs.val;

			return this->val;
		}
		template<typename Type>
		inline T& operator+=(const Type& rhs)
		{
			val = val + rhs;
			return val;
		}
		template<typename Type>
		inline T& operator-=(const Type& rhs)
		{
			val = val - rhs;

			return val;
		}
		template<typename Type>
		inline T& operator*=(const Type& rhs)
		{
			val = val * rhs;

			return val;
		}
		template<typename Type>
		inline T& operator/=(const Type& rhs)
		{
			val = val / rhs;

			return val;
		}
		unsigned long long Count()
		{
			return count;
		}
		Array_t<T>* begin() { return Begin; }
		Array_t<T>* end() { return (Begin + count); }
		T val;
		

		Array_t() :val(0) {};
		Array_t(T v)
		{
			val = v;
			count = Begin->count;
		};

		~Array_t<T>()
		{
			delete Begin;
		};
	};

	template<typename T>
	Array_t<T>* Array_t<T>::Begin = nullptr;
*/

#pragma region ColorClass
#ifdef WIN32

	class Color
	{
		#define BlueShift 0
		#define GreenShift 8
		#define RedShift 16
		#define AlphaShift 24
	public:
		Color() = default;
		Color(byte r, byte g, byte b, byte a) : R(r), G(g), B(b), A(a) { };
		explicit Color(byte r, byte g, byte b) : R(r), G(g), B(b), A(1) { };
		byte R;
		byte G;
		byte B;
		byte A; 
		static unsigned long OriginalWidth;
		static unsigned long OriginalHeight;
		byte GetR()
		{
			return R;
		}
		byte GetG()
		{
			return G;
		}
		byte GetB()
		{
			return B;
		}
		byte GetA()
		{
			return A;
		}
		DWORD GetARGB()
		{
			return (((DWORD)(B) << BlueShift) | ((DWORD)(G) << GreenShift) | ((DWORD)(R) << RedShift) | ((DWORD)(A) << AlphaShift));
		}
		DWORD GetRGB()
		{
			return ((COLORREF)(((BYTE)(R) | ((WORD)((BYTE)(A)) << 8)) | (((DWORD)(BYTE)(B)) << 16)));
		}
	};

	unsigned long Color::OriginalWidth = 0;
	unsigned long Color::OriginalHeight = 0;


#endif //_WIN32
#pragma endregion

	Template<typename Iterator, typename T,typename IteratorTy=Iterator, typename Ty = T>
		class LinqPlus
	{
	public:
			
	private:
		
		
		std::function<bool(void)> deleteContainer;
		std::function<bool(void)> deleteauxContainer;
		std::function<void(Iterator, Iterator)>  funct;
		static unsigned long long Length;
		static unsigned long long SecondLength;
		Iterator BeginPtr;
		Iterator EndPtr;
		IteratorTy BeginPtrSecond;
		IteratorTy EndPtrSecond;
		std::string Path;
		int Datatype;
		int FType;
		bool heapAllocated = false;
#pragma region InnerFunctions
		template<typename Type,typename ...Args>
		inline auto AddToCurrent(const Type val,const Args...arg)
		{

			Type Arguments[sizeof...(arg) + 1] = { val,arg... };
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);

			unsigned size = sizeof(Arguments)/sizeof(Type);
			unsigned index = 0;
			while (index < size)
			{
				vec->push_back((T)Arguments[index]);
				index++;
			}
			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};

			
			Length = vec ->size();

			using IteratorT = typename std::vector<T>::const_iterator;
			IteratorT begin = vec->cbegin();
			IteratorT end = vec->cend();

			return LinqPlus<IteratorT, T>(begin, end, deleteContainer, [this, &begin, &end](IteratorT first, IteratorT second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			}, Length);
		}
		template<typename Function_t>
		inline auto All(Function_t funct)
		{
			Iterator it = BeginPtr;
			Vector<T>* vec = new Vector<T>();
			while (it < EndPtr)
			{
				if (std::invoke(funct, *it))
				{
					vec->push_back(*it);
				}
				it++;
			}
		        if (deleteContainer)
			    deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};	
			using IteratorT = typename std::vector<T>::const_iterator;
			IteratorT begin = vec->cbegin();
			IteratorT end = vec->cend();
			return LinqPlus<IteratorT, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &begin, &end](IteratorT first, IteratorT second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			}, vec.size());
		}	
			
		template<typename Tt>
		inline std::string ToStringIn(Tt item)
		{
			std::stringstream ss;
			ss << item;
			return ss.str();
		}

		inline auto ToStr()
		{
			std::string str;

			Iterator begin = BeginPtr;
			while (begin != EndPtr)
			{
				str += ToStringIn(*begin);
				begin++;
			}
			return str;
		}	
			
		inline auto GetRange(unsigned long long begin, unsigned long long count)
		{
			Vector<T>* vec = new Vector<T>((BeginPtr) + begin,BeginPtr+(begin+count));
			Iterator beginIt = BeginPtr + begin;
		

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};

			Iterator beg = vec->cbegin();
			Iterator end = vec->cend();
			Length = vec->size();

			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer,[this,&beg,&end](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			},Length);
		}
		inline auto ReverseCollection()
		{
			Vector<T>* vec = new Vector<T>(BeginPtr,EndPtr);
			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};

			std::reverse(vec->begin(),vec->end());

			using IteratorT = typename std::vector<T>::const_iterator;
			IteratorT bgin = vec->cbegin();
			IteratorT end = vec->cend();
			Length = end - bgin;
			return LinqPlus<IteratorT, T>(bgin, end, deleteContainer, [this, &bgin, &end](IteratorT first, IteratorT second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			},Length);

		}
		template<typename Function_t>
		inline auto SelectIn(Function_t funct)
		{
			Iterator it = BeginPtr;
			using Type = typename std::invoke_result<decltype(funct), decltype(*it)>::type;
			using IteratorT = typename std::vector<Type>::const_iterator;
			
			
			Vector<Type>* newVec = new Vector<Type>();
			
			unsigned long long length = 0;

			while( it != EndPtr)
			{
				if (std::invoke(funct, *it))
				{
					newVec->push_back((Type)*it);
					length++;
				}
				it++ ;
			}
			
			if (deleteContainer)
				deleteContainer();

			length = newVec->size();
			deleteContainer = [newVec]()
			{
				delete newVec;
				return newVec->size()==0;
			};
			
			return LinqPlus<IteratorT, Type>(newVec->cbegin(), newVec->cend(),deleteContainer,  [](IteratorT first, IteratorT second)
			{
				if (first ==second)
					throw std::exception("Out of Range");


			}, length);
		}
		inline T GetMin()
		{
			Iterator it = BeginPtr;
			T min = 0;
			while (it < EndPtr)
			{
				if (*it < min)
					min = *it;
				it++;
			}
			if(heapAllocated)
				if (deleteContainer)
					deleteContainer();

			return min;
		}
		inline T GetFirst()
		{
			return *BeginPtr;
		}
		inline T GetLast()
		{
			return *(--EndPtr);
		}
		inline T GetMax()
		{
			Iterator it = BeginPtr;
			T max = 0;
			while (it < EndPtr)
			{
				if (*it > max)
					max = *it;
				it++;
			}
			return max;
		}
		inline bool ContainItem(T item)
		{
			Iterator it = BeginPtr;
			while (it < EndPtr)
			{
				if (funct(*it))
					return true;

				it++;
			}
			return false;
		}

		template<typename Function_t>
		inline auto ForEachIn(Function_t func)
		{
			Iterator It = BeginPtr;
			if constexpr (std::is_invocable<decltype(func), decltype(*It)>::value)
			{
				using Type = typename std::invoke_result<decltype(func), decltype(*It)>::type;


				const bool isVoid = std::is_same<Type, void>::value;
				Vector<Type>* vect;
				if constexpr (!isVoid)
				{
					vect = new Vector<Type>();
				}

				/*if  constexpr (std::is_reference<funct>::value && std::is_reference<*It>::value)
				{*/
					while (It < EndPtr)
					{
						if constexpr (!isVoid)
						{
							vect->push_back(std::invoke(func, *It));
						}
						else
						{
							std::invoke(func,  *It);
						}
						It++;
					}
				//}




				if (deleteContainer)
					deleteContainer();

				if constexpr (!isVoid)
				{


					deleteContainer = [vect]()
					{
						delete vect;
						return vect->size()==0;
					};

					using IteratorT = typename std::vector<Type>::const_iterator;
					IteratorT begin = vect->cend();
					IteratorT end = vect->cend();
					unsigned long long length = vect->size();
					return LinqPlus<IteratorT, T>(vect->cbegin(), vect->cend(), deleteContainer, [this, &begin, &end](IteratorT first, IteratorT second)
					{
						if (first == second)
							throw std::exception("Out of Range");

					}, length);
				}

			}
			if constexpr (std::is_invocable<decltype(func), decltype(It)>::value)
			{	
				using Type = typename std::invoke_result<decltype(func), decltype(It)>::type;
			
				const bool isVoid = std::is_same<Type, void>::value;
				Vector<Type>* vect;
				if constexpr (!isVoid)
				{
					vect = new Vector<Type>();
				}

				while (It < EndPtr)
				{
					if constexpr (!isVoid)
					{
						vect->push_back(std::invoke(func,  It));
					}
					else
					{
						std::invoke(func, It);
					}
					It++;
				}

				if (deleteContainer)
					deleteContainer();

				if constexpr (!isVoid)
				{


					deleteContainer = [vect]()
					{
						delete vect;
						return vect->size()==0;
					};

					using IteratorT = typename std::vector<Type>::const_iterator;
					IteratorT begin = vect->cend();
					IteratorT end = vect->cend();
					unsigned long long length = vect->size();
					return LinqPlus<IteratorT, T>(vect->cbegin(), vect->cend(), deleteContainer, [this, &begin, &end](IteratorT first, IteratorT second)
					{
						if (first == second)
							throw std::exception("Out of Range");

					}, length);
				}
			
			}
		}

		template<typename Function_t>
		inline bool ExistAny(Function_t funct)
		{
			
			Iterator it = BeginPtr;
			bool result = false;
			while (it < EndPtr)
			{
				if (std::invoke(funct, *it))
				{
					result = true;
					break;
				}
				it++;
			}

			if (deleteContainer && heapAllocated)
				deleteContainer();

			return result;
		}
		template<typename Function_t>
		inline auto FindIn(Function_t funct, unsigned long long length)
		{
			//using Type =typename std::invoke_result_t<Function_t, const T&>;
			Vector<T>* newVec = new Vector<T>();
			length = 0;

			
			
			for (auto it = BeginPtr; it != EndPtr; it++)
			{
				if (std::invoke(funct,*it))
				{
					newVec->push_back(*it);
					length++;
				}
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [newVec]()
			{
				delete newVec;
				return true;
			};

			using IteratorT = typename std::vector<T>::const_iterator;
			IteratorT bgin = newVec->cbegin();
			IteratorT end = newVec->cend();
			return LinqPlus<IteratorT, T>(newVec->cbegin(), newVec->cend(),deleteContainer, [this,&bgin, &end](IteratorT first, IteratorT second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			},length);
		}
			
		template<typename Function_t>
		inline auto GetAll(Function_t funct)
		{
			return All(funct);
		}	
			
		template<typename Function_t>
		inline auto OrderContainer(Function_t predicate)
		{
			Vector<T>* newVec = new Vector<T>(BeginPtr, EndPtr);

			
			std::sort(newVec->begin(), newVec->end(), predicate);
           
			if (deleteContainer)
				deleteContainer();

			deleteContainer = [newVec]()
			{
				delete newVec;
				return newVec->size()==0;
			};
			using IteratorT = typename std::vector<T>::const_iterator;
			IteratorT bgin = newVec->cbegin();
			IteratorT end = newVec->cend();
			return LinqPlus<IteratorT, T>(newVec->cbegin(), newVec->cend(), deleteContainer, [this, &bgin, &end](IteratorT first, IteratorT second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			}, Length);
		}
		inline auto OrderContainer()
		{
			Vector<T>* newVec = new Vector<T>(BeginPtr,EndPtr);

			std::sort(newVec->begin(), newVec->end(), [](T val, T val2) {return val > val2; });
			
			if(deleteContainer)
			deleteContainer();

			deleteContainer = [newVec]()
			{
				delete newVec;
				return newVec->size()==0;
			};
			using IteratorT = typename std::vector<T>::const_iterator;
			IteratorT bgin = newVec->cbegin();
			IteratorT end = newVec->cend();
			return LinqPlus<IteratorT, T>(newVec->cbegin(), newVec->cend(), deleteContainer, [this, &bgin, &end](IteratorT first, IteratorT second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			}, Length);
		}
		Template<typename Function_t>
		inline unsigned long long GetCount(Function_t& function)
		{
			unsigned long long total=0;
			Iterator it = BeginPtr;
			while (it != EndPtr)
			{
				if (std::invoke(function, *it))
					total++;

				it++;
			}
			if (deleteContainer && heapAllocated)
				deleteContainer();
			return total;
		}
		inline auto GetDistinct()
		{
			Vector<T>* vec = new Vector<T>();
			Iterator begin = BeginPtr;
			while (begin != EndPtr)
			{
				if (!(std::find(vec->begin(), vec->end(), *begin) != vec->end()))
				{
					vec->push_back(*begin);
				}
				begin++;
			}
			if (deleteContainer)
				deleteContainer();
			
			deleteContainer= [vec]()
			{
				delete vec;
				return vec->size()==0;
			};

			Iterator bgin = vec->cbegin();
			Iterator end = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &end](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");

			}, Length);
		}
		template<typename Function_t>
		inline auto Avg(Function_t func)
		{
			Iterator it = BeginPtr;
			using Type = typename std::invoke_result<decltype(func), decltype(*it)>::type;
			Type total = 0;
			unsigned long long length = 0;
			while (it < EndPtr)
			{
				total +=std::invoke(func,*it);
				length++;
				it++;
			}

			total /= length;
			return total;
		}
		inline T Avg()
		{
			T total = 0;
			unsigned long long length =0;
			Iterator it = BeginPtr;
			while (it < EndPtr)
			{
				total += *it;
				length++;
				it++;
			}
			total /= (T)length;
			return total;
		}
#pragma endregion 
	public:
		
#pragma region Constructors
		LinqPlus() : BeginPtr(nullptr),EndPtr(nullptr), funct([]() {  }) { };
		LinqPlus(Iterator first, Iterator second, unsigned long long size)
		{
			Datatype = 0;
			BeginPtr = first;
			EndPtr = second;
			if (!Length &&  !size)
			{
				Length = second - (first);
				if (Length <= 0)
				{
					Length = 0;
				}
			}
			else
			{
				Length = size;
			}

		}
		LinqPlus(Iterator first,Iterator second, std::function<void(Iterator, Iterator)> function)
		{
			Datatype = 0;
			funct = function;
			BeginPtr = first;
			EndPtr = second;
			if (!Length) 
			{
				Length = second - (first);
				if (Length <= 0)
				{
					Length = 0;
				}
			};

			if (!Datatype)
			{
				bool case1 = *(BeginPtr + (Length - 4)) == '.';
				bool case2 = *(BeginPtr + (Length - 5)) == '.';
				if ( case1 || case2)
				{
					std::string format = "";
					if (case1)
					{
						unsigned long long n = 3;
						
						while(n>0&&n<4)
						{
							format += (*(BeginPtr + (Length - n)));
							n--;
						}
						if (format == "bmp" || format == "BMP")
							Datatype = (int)Data::BMP;
						else
						{
							Datatype = (int)Data::Data;
						}
					}
					if (case2)
					{
						unsigned long long n = 4;

						while (n > 0 && n < 5)
						{
							format += (*(BeginPtr + (Length - n)));
							n--;
						}
						if (format == "bmp" || format == "BMP")
							Datatype = (int)Data::BMP;
						else
						{
							Datatype = (int)Data::Data;
						}
					}
				}
				else
				{
					Datatype = -1;
				}
			}
		};
		LinqPlus(Iterator first, Iterator second, std::function<bool(void)> fn, sFunction<void(Iterator,Iterator)> fun, unsigned long long& size)
		{
			funct = fun;
			deleteContainer = fn;
			Length = size;
			BeginPtr = first;
			EndPtr = second;
		}
	        LinqPlus(Iterator first,Iterator second,unsigned long long& length )
		{
			funct = [](Iterator it,Iterator it1) { };
			BeginPtr = first;
			EndPtr = second;
			Length = length;
		};
		LinqPlus(Iterator first, Iterator second,std::function<bool(void)> f, unsigned long long& length,bool allocated)
		{
			heapAllocated = allocated;
			deleteContainer = f;
			BeginPtr = first;
			EndPtr = second;
			Length = length;
		};
		LinqPlus(Iterator first, Iterator second, const unsigned long long& length,  std::function<void(Iterator, Iterator)>  function)
		{
			funct = function;
			BeginPtr = first;
			EndPtr = second;
			Length = length;
		};
#pragma warning(disable:26495)
		LinqPlus(std::string path, int d, Iterator begin,Iterator end) : Path(path), Datatype(d), BeginPtr(begin), EndPtr(end),FType(d) { }//FType(d) remove if cause problems
		LinqPlus(Iterator beginFirst, Iterator endFirst, IteratorTy beginSecond, IteratorTy endSecond, std::function<bool(void)> func1, std::function<bool(void)> func2, unsigned long long len1, unsigned long long len2) 
		{ 
			BeginPtr = beginFirst;
			EndPtr = endFirst;
			BeginPtrSecond = beginSecond;
			EndPtrSecond = endSecond;
			deleteContainer = func1;
			deleteauxContainer = func2;
			Length = len1;
			SecondLength = len2;

		}
#pragma endregion 
#pragma region Initializers
		Template<typename TT>
			auto PairWith(Vector<TT>*& container) -> LinqPlus<Iterator, T, typename Vector<TT>::const_iterator, TT>
		{
			
			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container->cbegin(); 
			IT end = container->cend();
			

			SecondLength = end - begin;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer,deleteauxContainer,LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(Vector<TT>& container) -> LinqPlus<Iterator, T, typename Vector<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container.cbegin();
			IT end = container.cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(List<TT>*& container) -> LinqPlus<Iterator, T, typename List<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container->cbegin();
			IT end = container->cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
		auto PairWith(List<TT>& container) -> LinqPlus<Iterator, T, typename List<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container.cbegin();
			IT end = container.cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(ForwardList<TT>*& container) -> LinqPlus<Iterator, T, typename ForwardList<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container->cbegin();
			IT end = container->cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(ForwardList<TT>& container) -> LinqPlus<Iterator, T, typename ForwardList<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container.cbegin();
			IT end = container.cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(Deque<TT>*& container) -> LinqPlus<Iterator, T, typename Deque<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container->cbegin();
			IT end = container->cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(Deque<TT>& container) -> LinqPlus<Iterator, T, typename Deque<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container.cbegin();
			IT end = container.cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
			auto PairWith(Stack<TT>*& container) -> LinqPlus<Iterator, T, typename Stack<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container->cbegin();
			IT end = container->cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
		Template<typename TT>
		    auto PairWith(Stack<TT>& container) -> LinqPlus<Iterator, T, typename Stack<TT>::const_iterator, TT>
		{

			using IT = typename std::vector<TT>::const_iterator;
			IT begin = container.cbegin();
			IT end = container.cend();


			SecondLength = begin - end;
			return LinqPlus<Iterator, T, IT, TT >(BeginPtr, EndPtr, begin, end, deleteContainer, deleteauxContainer, LinqPlus::Length, SecondLength);
		}
#pragma endregion 
#pragma region Functions
		

		Template<typename TT>
		inline auto Concat(Vector<TT>* container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT =  typename Vector<TT>::const_iterator ;
			IT start = container->cbegin();
			IT end = container->cend();
			while (start < end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this,&bgin,&endit ](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			},Length);
			
		}
		Template<typename TT,typename ...Args>
		inline auto Concat(const TT first, const Args&... arg)
		{

			TT arguments[sizeof...(arg) + 1] = { first, arg... };
			Vector<T>* vec = new Vector<T>(BeginPtr,EndPtr);
			unsigned size = sizeof(arguments)/sizeof(TT);
			unsigned index = 0;

			while (index < size)
			{
				vec->push_back((T)arguments[index]);
				index++;
			}


			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};

			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);
		}
		Template<typename TT>
		inline auto Concat(Vector<TT>& container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename Vector<TT>::const_iterator;
			IT start = container.cbegin();
			IT end = container.cend();
			while (start < end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(List<TT>& container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename List<TT>::const_iterator;
			IT start = container.cbegin();
			IT end = container.cend();
			while (start != end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};		
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(List<TT>* container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename List<TT>::const_iterator;
			IT start = container->cbegin();
			IT end = container->cend();
			while (start != end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(ForwardList<TT>& container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename ForwardList<TT>::const_iterator;
			IT start = container.cbegin();
			IT end = container.cend();
			while (start < end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(ForwardList<TT>* container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename ForwardList<TT>::const_iterator;
			IT start = container->cbegin();
			IT end = container->cend();
			while (start < end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(Deque<TT>& container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename Deque<TT>::const_iterator;
			IT start = container.cbegin();
			IT end = container.cend();
			while (start != end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(Deque<TT>* container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename Deque<TT>::const_iterator;
			IT start = container->cbegin();
			IT end = container->cend();
			while (start < end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = []()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(Stack<TT>& container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename Stack<TT>::const_iterator;
			IT start = container.cbegin();
			IT end = container.cend();
			while (start != end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(Stack<TT>* container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename Stack<TT>::const_iterator;
			IT start = container->cbegin();
			IT end = container->cend();
			while (start < end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = []()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
		Template<typename TT>
		inline auto Concat(std::string& container)
		{
			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);
			using IT = typename std::string::const_iterator;
			IT start = container.cbegin();
			IT end = container.cend();
			while (start != end)
			{
				vec->push_back((T)(*start));
				start++;
			}

			if (deleteContainer)
				deleteContainer();

			deleteContainer = [vec]()
			{
				delete vec;
				return vec->size()==0;
			};
			Iterator bgin = vec->cbegin();
			Iterator endit = vec->cend();
			Length = vec->size();
			return LinqPlus<Iterator, T>(vec->cbegin(), vec->cend(), deleteContainer, [this, &bgin, &endit](Iterator first, Iterator second)
			{
				if (first == second)
					throw std::exception("Out of Range");
			}, Length);

		}
			
		inline auto ToString()
		{
	            return ToStr();
		}

		
		Template<typename Type,typename ...Args>
		inline auto Append(const Type val, const Args&...arg)
		{
			return AddToCurrent(val,arg...);
		}
		Template<typename TT>
		inline auto Append(Vector<TT>* container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(Vector<TT>& container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(List<TT>* container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(List<TT>& container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(ForwardList<TT>* container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(ForwardList<TT>& container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(Deque<TT>* container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(Deque<TT>& container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(Stack<TT>* container)
		{
			return Concat(container);
		}
		Template<typename TT>
		inline auto Append(Stack<TT>& container)
		{
			return Concat(container);
		}



		inline auto Distinct()
		{
			return GetDistinct();
		}
		inline auto Contains(T item)
		{
			return ContainItem(item);
		}
		template<typename Function_t>
		inline auto OrderBy(Function_t predicate)
		{
			return OrderContainer(predicate);
		}
		inline auto OrderByDescending()
		{
			return OrderContainer();
		}
		inline auto Last()
		{
			return GetLast();
		}
		inline auto First()
		{
			return GetFirst();
		}
		template<typename Function_t>
		inline auto Where(Function_t funct)
		{
			return FindIn(funct,Length);
		}
		template<typename Function_t>
		inline auto Average(Function_t func)
		{
			return Avg(func);
		}	
		inline auto Average()
		{
			return  Avg();
		}
		inline bool Any() 
		{
			return Length > 0 || ((EndPtr - BeginPtr) >0);
		}
		template<typename Function_t>
		inline bool Any(Function_t&& f)
		{
			return ExistAny(f);
		}
		inline auto Count()
		{
			return Length;
		}
		Template<typename Function_t>
		inline auto Count(Function_t func)
		{
			return GetCount(func);
		}
		Template<typename Function_t>
			inline auto ForEach(Function_t func)
		{
			return ForEachIn(func);
		}

		template<typename Function_t>
		inline auto Select(Function_t funct)
		{
			//std::invoke_result_t<F, const value_type&>
			return SelectIn(funct);
		}
		inline auto Max()
		{
			return GetMax();
		}
		inline auto Min()
		{
			return GetMin();
		}
		inline auto Reverse()
		{
			return ReverseCollection();
		}
		inline auto ParseFileString()
		{
			std::string* content = new std::string();
			if (Path.empty())
			{
				std::string currentPath(BeginPtr, EndPtr);
				Path = currentPath;
			}
			std::ifstream* openFile = new std::ifstream(Path, std::ios::binary);
			size_t fileSize = 0;
			if (openFile->is_open())
			{
				openFile->seekg(0, std::fstream::end);
				fileSize = openFile->tellg();
				openFile->seekg(0, std::fstream::beg);

			}
			content->reserve(fileSize);
			content->insert(content.begin(), std::istreambuf_iterator<char>(*openFile), std::istreambuf_iterator<char>());
			delete openFile;

			deleteContainer = [content]()
			{
				delete content;
				return content->size()==0;
			};

			using IteratorT = std::string::iterator;
			using Type = std::string::value_type;
			content->shrink_to_fit();
			Length = content->size();
			IteratorT begin = content->cbegin();
			IteratorT end = content->cend();

			return LinqPlus<IteratorT, Type>(begin, end, deleteContainer, [&begin, &end, this](IteratorT begin, IteratorT end)
			{
				if (begin == end)
					throw std::exception("Out of Range");

			}, Length);
		}
		inline auto ReadAllBytes()
		{
			if (Datatype == (int)Data::BMP || Datatype == (int)Data::Data)
			{
				if (Path.empty())
				{
					std::string currentPath(BeginPtr, EndPtr);
					Path = currentPath;
				}
				const std::string path(Path);
				Vector<byte>* bytes = new Vector<byte>{};
				std::ifstream file(Path, std::ios::binary);
				file.unsetf(std::ios::skipws);
				file.seekg(0, std::ios::end);
				struct stat stat_buf;
				int rc = stat(Path.c_str(), &stat_buf);
				unsigned long long fileSize = file.tellg();

				file.seekg(0, std::ios::beg);
				bytes->reserve(fileSize);
				bytes->insert(bytes->begin(), std::istream_iterator<byte>(file), std::istream_iterator<byte>());

				deleteContainer = [bytes]()
				{
					delete bytes;
					return bytes->size()==0;
				};
				bytes->shrink_to_fit();
				Length = bytes->size();

				using IteratorT = typename std::vector<byte>::iterator::pointer;
				using Type = std::vector<byte>::iterator::value_type;
				IteratorT begin = bytes->data();
				IteratorT end = bytes->data() + bytes->size();

				return LinqPlus<IteratorT, Type>(begin, end, deleteContainer, [&begin, &end, this](IteratorT begin, IteratorT end)
				{
					if (begin == end)
						throw std::exception("Out of Range");

				}, Length);
			}
			else
				throw std::exception("Data Type not Supported");

		}
		inline auto Range(unsigned long long begin, unsigned long long count)
		{
			return GetRange(begin,count);
		}
#ifdef WIN32
		inline auto ToColorVector()
		{
			if (Datatype == (int)Data::BMP || (int)Data::Image)
			{
				var vecColor = new Vector<Color>();

				try
				{
					Gdiplus::GdiplusStartupInput gdiplusStartupInput;
					ULONG_PTR gdiplusToken;
					Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

					std::wstring file = std::wstring(Path.begin(), Path.end());
					Gdiplus::Image* image = Gdiplus::Image::FromFile(file.c_str());


					var width = image->GetWidth();
					var height = image->GetHeight();
					vecColor->reserve(width * height);
					Gdiplus::PixelFormat format = image->GetPixelFormat();
					Gdiplus::Bitmap* bmp = new Gdiplus::Bitmap(width, height, format);
					bmp = (Gdiplus::Bitmap*)image;

					Gdiplus::Color red = Gdiplus::Color::RedMask;
					Gdiplus::Color blue = Gdiplus::Color::BlueMask;
					Gdiplus::Color alpha = Gdiplus::Color::AlphaMask;
					Gdiplus::Color green = Gdiplus::Color::GreenMask;
					Linqp::Color  buffer(0, 0, 0, 0);
					buffer.OriginalHeight = height;
					buffer.OriginalWidth = width;
					for (unsigned x = 0; x < width; x++)
					{
						for (unsigned y = 0; y < height; y++)
						{
							bmp->GetPixel(x, y, &alpha);
							buffer.A = alpha.GetAlpha();
							buffer.R = alpha.GetRed();
							buffer.G = alpha.GetGreen();
							buffer.B = alpha.GetBlue();
							vecColor->emplace_back(buffer);

						}
					}
					delete bmp;
					image = nullptr;
					return vecColor;
				}
				catch (std::exception ex)
				{
					if (vecColor->size() >= 0)
						return vecColor;

				}
			}
			else
				throw std::exception("Data type not supported");
		}
#endif //_WIN32
#pragma endregion
#pragma region Containers
		inline Vector<T>* ToVector()
		{
			if (Length <= 0)
			{
				Vector<T>* empty = new Vector<T>();
				return empty;
			}

			Vector<T>* vec = new Vector<T>(BeginPtr, EndPtr);

			if (deleteContainer)
				var result = deleteContainer();
			return vec;
		}
		inline Stack<T>* ToStack()
		{
			Stack<T>* stack = new Stack<T>();

			for (auto it = (EndPtr-1);it > BeginPtr;it--)
				  stack->emplace(*it);

			if (deleteContainer)
			var result = deleteContainer();
			return stack;
		}
		inline List<T>* ToList()
		{
			List<T>* list = new List<T>(BeginPtr, EndPtr);
			if(deleteContainer)
			var result = deleteContainer();

			return list;
		}
		
		inline ForwardList<T>* ToForwardList()
		{
			ForwardList<T>* list = new ForwardList<T>(BeginPtr, EndPtr);
			if (deleteContainer)
				var result = deleteContainer();
			return list;
		}	
		inline Deque<T>* ToDeque()
		{
			
			Deque<T>* deque = new Deque<T>(BeginPtr, EndPtr);
			if (deleteContainer)
				var result = deleteContainer();
			return deque;
		}
		inline UnorderedMultimap<T, Ty>*& ToUnorderedMultimap()
		{
			try
			{
				UnorderedMultimap<T, Ty>* ummap = new UnorderedMultimap<T, Ty>();
				

				std::pair<T, Ty> buff;
				if ((EndPtr - BeginPtr) == (EndPtrSecond - BeginPtrSecond))
				{
					Iterator temp = BeginPtr;
					IteratorTy tempAux = BeginPtrSecond;
					while (temp != EndPtr)
					{
						buff = MakePair(*temp, *tempAux);
						ummap->insert(buff);

						temp++;
						tempAux++;
					}

					
				}
                    if (deleteContainer)
						var result = deleteContainer();
					if (deleteauxContainer)
						var result = deleteContainer();

					return ummap;
			}
			catch (std::exception ex)
			{
			   throw std::exception("There is no assigned second container to create a map");
			}
		}
		inline Multimap<T, Ty>*& ToMultimap()
			{
				Multimap<T, Ty> mmap = new Multimap<T, Ty>();
				if (deleteContainer)
					var result = deleteContainer();
				if (deleteauxContainer)
					var result = deleteContainer();

				std::pair<T, Ty> buff;
				if ((EndPtr - BeginPtr) == (EndPtrSecond - BeginPtrSecond))
				{
					Iterator temp = BeginPtr;
					IteratorTy tempAux = BeginPtrSecond;
					while (temp != EndPtr)
					{
						buff = MakePair(*temp, *tempAux);
						mmap->insert(buff);

						temp++;
						tempAux++;
					}
				}

				return mmap;
			}
		inline Map<T, Ty>*& ToMap()
		{

			Map<T, Ty>* map = new Map<T, Ty>();
			
			std::pair<T, Ty> buff; 
			if ((EndPtr - BeginPtr) == (EndPtrSecond - BeginPtrSecond))
			{
				Iterator temp=BeginPtr;
				IteratorTy tempAux = BeginPtrSecond;
				while (temp != EndPtr)
				{
					buff = MakePair(*temp,*tempAux);
					map->insert(buff);

						temp++; 
					tempAux++;
				}
				if (deleteContainer)
					var result = deleteContainer();
				if (deleteauxContainer)
					var result = deleteContainer();
			}
			else if ((EndPtr - BeginPtr) > (EndPtrSecond - BeginPtrSecond))
			{

			}
			else if ((EndPtr - BeginPtr) < (EndPtrSecond - BeginPtrSecond))
			{

			}
			return map;
		}	//Template<typename Type1 = std::tuple_element<0,P>, typename Type2= std::tuple_element<1,P>>
#pragma endregion 
		
	};




	template<typename Iterator, typename T, typename IteratorTy ,typename Ty>
	unsigned long long LinqPlus<Iterator, T,IteratorTy,Ty>::Length = 0;

	template<typename Iterator, typename T, typename IteratorTy, typename Ty>
	unsigned long long LinqPlus<Iterator, T, IteratorTy, Ty>::SecondLength = 0;

	
#pragma region MainInitializers
#pragma warning(disable:4715)

	Template<typename Iterator>
		LinqPlus<Iterator, typename std::iterator_traits<Iterator>::value_type>from(const Iterator& begin, const Iterator& end)
	{

		return LinqPlus<Iterator, typename std::iterator_traits<Iterator>::value_type>(begin, end,
			[](Iterator first, Iterator second)
		{
			if (first == second)
				throw std::exception("Out of Range");


		});
	}

	Template<typename Iterator>
		LinqPlus<Iterator, typename std::iterator_traits<Iterator>::value_type>from(const Iterator& begin, const Iterator& end, const unsigned long long& length)
	{
		return LinqPlus<Iterator, typename std::iterator_traits<Iterator>::value_type>(begin, end, length,
			[](Iterator first, Iterator second)
		{
			if (first == second)
				throw std::exception("Out of Range");

		});
	}

	Template<typename Iterator>
	LinqPlus<const Iterator, typename std::iterator_traits<Iterator>::value_type> from(const Iterator& begIt, unsigned long long& nlength)
	{

		return from(begIt, begIt + nlength);
	}

    Template<typename T, typename Length_Ty>
		LinqPlus<const T*, T> from(const T* Array, Length_Ty length)
	{
		
		return LinqPlus<const T*,T>(Array, Array + length,length, [](const T* first , const T* second)
		{
			if (first == second)
				throw std::exception("Out of Range");


		});
		
	}

	Template<typename T, size_t length>
		LinqPlus<const  T*, T> from(T(&Array)[length])
	{
		return LinqPlus<const T*, T>(Array, Array + length, length, [](const T* first, const T* second)
		{
			if (first == second)
				throw std::exception("Out of Range");


		});
	}

	Template<template<class> class Ty, typename T>
		inline auto from(const Ty<T>& container)-> decltype(from(container.cbegin(), container.cend()))
	{
		return from(container.cbegin(), container.cend());
	}

	Template<template<class, class, class, class> class TypeOrderedTree, typename TypeKey, typename TypeValue, typename TypeCompare, typename TypeAllocator>
		auto from(const TypeOrderedTree<TypeKey, TypeValue, TypeCompare, TypeAllocator>& orderedContainer)
		-> decltype(from(orderedContainer.cbegin(), orderedContainer.cend()))
	{
		return from(orderedContainer.cbegin(), orderedContainer.cend());
	}

	Template<template<class, class, class, class>
		class TypeOrderedTree, typename TypeKey, typename TypeValue, typename TypeCompare, typename TypeAllocator>
		auto from(const TypeOrderedTree<TypeKey, TypeValue, TypeCompare, TypeAllocator>*& orderedContainer)
		-> decltype(from((*orderedContainer).cbegin(), (*orderedContainer).cend()))
	{
		return from((*orderedContainer).cbegin(), (*orderedContainer).cend());
	}

	Template<template<class, class> class Ty, typename T, typename TypeAllocator>
		auto from(Ty<T, TypeAllocator>& container,const unsigned long long& length)
		-> decltype(from(container.cbegin(), container.cend()))
	{
		return from(container.cbegin(), container.cend(),length);
	}

	Template<template<class, class> class Ty, typename T, typename TypeAllocator>
		auto from(Ty<T, TypeAllocator>& container)
		-> decltype(from(container.cbegin(), container.cend()))
	{//here
		
		using Iterator = typename Ty<T,TypeAllocator>::const_iterator;
		return LinqPlus<Iterator, typename std::iterator_traits<Iterator>::value_type>(container.cbegin(), container.cend(),container.size());
	}

	Template<template<class, class> class Ty, typename T, typename TypeAllocator>
		auto from(Ty<T, TypeAllocator>*& container, const unsigned long long& length)
		-> decltype(from((*container).cbegin(), (*container).cend()))
	{
		return from((*container).cbegin(), (*container).cend(),length);
	}

	Template<template<class, class> class Ty, typename T, typename TypeAllocator>
		auto from(Ty<T, TypeAllocator>*& container)
		-> decltype(from((*container).cbegin(), (*container).cend()))
	{
		return from((*container).cbegin(), (*container).cend(),container->size());
	}

	Template<typename Type, typename ...Args>
		auto From(Type const& first, Args const&  ... second)
	{
		//Vector<Type>* vec = new Vector<Type>{  (Type) (second)... };
		
			Vector<Type>* vec = new Vector<Type>({ (Type)(second)... });

			vec->insert(vec->begin(), first);
			using It = typename Vector<Type>::const_iterator;
			std::function<bool(void)> f = [vec]()
			{
				delete vec;
				return true;
			};
			//std::iterator_traits<std::string::const_iterator>::pointer;
			It begin = vec->cbegin();
			It end = vec->cend();
			unsigned long long size = vec->size();
			return LinqPlus<It, Type>(begin, end, f, size, true);
	
	}

	Template<typename Type>
		auto from(std::initializer_list<Type>& list)
	{
		//using IteratorT =typename std::initializer_list<Type>::const_iterator;
		Vector<Type>* vec = new Vector<Type>(list);
	    using It = typename Vector<Type>::const_iterator;
		std::function<bool(void)> f = [vec]()
		{
			delete vec;
			return true;
		};
		//std::iterator_traits<std::string::const_iterator>::pointer;
		It begin = vec->cbegin();
		It end = vec->cend();
		unsigned long long size = vec->size();
		return LinqPlus<It, Type>(begin, end, f, size, true);
	}

	auto from(std::string& str)
	{
		return from(str.begin(), str.end());
	}
	auto from(std::string s,const int opt,bool file)
	{
		switch (opt)
		{
#ifdef WIN32
		case 0:
			using Ty = std::string::iterator::pointer ;
			using It = std::iterator_traits<std::string::const_iterator>::pointer;
				 
			return LinqPlus<It, Ty>(s, (int)Data::BMP, s.data(), s.data() + s.length());
		case 1:
			using Ty = std::string::iterator::pointer;
			using It = std::iterator_traits<std::string::const_iterator>::pointer;

			return LinqPlus<It, Ty>(s, (int)Data::Image, s.data(), s.data() + s.length());
#endif //WIN32
		case 2:
			using Ty = std::string::iterator::pointer;
			using It = std::iterator_traits<std::string::const_iterator>::pointer;

			return LinqPlus<It, Ty>(s, (int)Data::Data, s.data(), s.data() + s.length());
		default:
		break;
		}
    }
#pragma endregion


};

#endif LINQ_PLUS_H


