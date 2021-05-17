#include <iostream>
#include <sstream>
using namespace std;

// By Kool_Kat_2216.



string doc_string(int ver, int minor, int p_level) {
  std::ostringstream d;
  d << " v" << ver << '.' << minor << '.' << p_level;
  return d.str();
}

string cpp_comp =
#ifdef __clang__
  "clang++";
#elif __INTEL_LLVM_COMPILER
  "ICC";
#elif __GNUC__
  "g++";
#elif _MSC_VER
  "Visual Studio";
#else
  "unknown compiler";
#endif

string cpp_version =
#ifdef __INTEL_LLVM_COMPILER 
  doc_string(__VERSION)
#elif __clang__
  doc_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
#elif __GNUC__
  doc_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif (_MSC_VER >= 1920)
  " 2019 and later";
#elif (_MSC_VER < 1920 && _MSC_VER >= 1910)
  " 2017";
#elif (_MSC_VER == 1900)
  " 2015";
#elif (_MSC_VER == 1800)
  " 2013";
#elif (_MSC_VER == 1700)
  " 2012";
#elif (_MSC_VER <= 1600)
  " 2010 and earlier";
#else
  " of unknown version";
#endif


string os = 
#ifdef __unix__
  "Unix ";
#elif __linux__
  "Linux ";
#elif __APPLE__
  "Apple ";
#elif _WIN32
  "Windows ";
#else
  "";
#endif

int main(void) {
  // cout << "This program currently supports GCC (GNU Compiler Collection), ICC (Intel's C++ Compiler), Visual Studio C++, and Clang.\n\n";
  cout << "This " << os << "machine is currently using " << cpp_comp << cpp_version << ".\n";
  return 0;
}
