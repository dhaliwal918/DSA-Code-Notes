// Strings and Characters in C++ — Quick Notes
//
// This file is a compact reference with runnable examples.
// Read top-to-bottom, skim sections as needed.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using std::cout;
using std::endl;

// ------------------------------------------------------------
// 1) Characters (`char`)
// ------------------------------------------------------------
// - `char` typically stores a single byte (8 bits).
// - It can hold ASCII characters directly (e.g., 'A', 'z', '0', '\n').
// - For Unicode beyond basic ASCII, prefer UTF-8 encoded `std::string` or libraries.

void demoCharacters() {
  char letter = 'A';                 // character literal
  char newline = '\n';               // escape sequences like '\n', '\t', '\\', '\''
  char digitChar = '7';

  // Classification helpers from <cctype>
  bool isAlpha = std::isalpha(static_cast<unsigned char>(letter));
  bool isDigit = std::isdigit(static_cast<unsigned char>(digitChar));
  bool isLower = std::islower(static_cast<unsigned char>('b'));
  bool isUpper = std::isupper(static_cast<unsigned char>('B'));

  // Case conversion (use unsigned char cast to avoid UB for negative signed chars)
  char lowerA = static_cast<char>(std::tolower(static_cast<unsigned char>('A')));
  char uppera = static_cast<char>(std::toupper(static_cast<unsigned char>('a')));

  cout << "[Characters]\n";
  cout << "letter=" << letter << ", digitChar=" << digitChar << newline;
  cout << std::boolalpha
       << "isAlpha=" << isAlpha << ", isDigit=" << isDigit
       << ", isLower(b)=" << isLower << ", isUpper(B)=" << isUpper << endl;
  cout << "tolower('A')=" << lowerA << ", toupper('a')=" << uppera << "\n\n";
}

// ------------------------------------------------------------
// 2) String literals vs std::string vs std::string_view
// ------------------------------------------------------------
// - String literal: type is const char[N]; stored in read-only memory; immutable.
// - std::string: owning, mutable, dynamic-size string.
// - std::string_view: non-owning view (no allocation); use for read-only parameters.

void demoStringBasics() {
  const char *cLiteral = "hello";  // pointer to string literal (do not modify)
  std::string s = "hello";         // owning string
  std::string t = std::string(3, '!'); // "!!!"
  std::string_view sv = s;          // view into s (non-owning)

  cout << "[Basics]\n";
  cout << "cLiteral=" << cLiteral << ", s=" << s << ", t=" << t
       << ", sv=" << sv << "\n\n";
}

// ------------------------------------------------------------
// 3) Common std::string operations
// ------------------------------------------------------------
// Construction, size/length, concatenation, access, iteration, modification.

void demoStringOperations() {
  std::string s = "Hello";
  std::string r = "World";

  // size/length
  size_t n = s.size(); // same as s.length()

  // concatenation
  std::string combined = s + ", " + r + "!"; // uses operator+
  s += " there";                              // append in-place

  // access
  char first = combined[0];                   // unchecked
  char safe = combined.at(1);                 // bounds-checked, may throw

  // iteration
  cout << "[Operations]\n";
  cout << "Combined: " << combined << " (size=" << combined.size() << ")\n";
  cout << "s after += : " << s << "\n";
  cout << "Chars: ";
  for (char c : combined) cout << c << ' ';
  cout << "\nfirst=" << first << ", second=" << safe << "\n";

  // modification
  std::string m = combined;                   // copy
  m.push_back('?');
  m.pop_back();
  m.insert(5, " <-insert-> ");              // at position 5
  m.erase(5, 12);                             // erase 12 chars starting at 5
  m.replace(0, 5, "Hi");                    // replace first 5 chars with "Hi"
  cout << "modified m: " << m << "\n\n";
}

// ------------------------------------------------------------
// 4) Substrings, search, compare
// ------------------------------------------------------------

void demoSubstringSearchCompare() {
  std::string s = "abracadabra";

  // substring
  std::string sub = s.substr(3, 4); // from index 3, length 4 -> "acad"

  // find/ rfind / find_first_of / find_last_of
  size_t posA = s.find('a');         // first 'a'
  size_t posBra = s.find("bra");    // first occurrence of "bra"
  size_t lastA = s.rfind('a');       // last 'a'

  // compare
  int cmp = s.compare("abracadabra"); // 0 if equal, <0 if less, >0 if greater (lexicographical)

  cout << "[Substring/Search/Compare]\n";
  cout << "s=" << s << ", sub=" << sub << ", posA=" << posA
       << ", pos(\"bra\")=" << posBra << ", lastA=" << lastA
       << ", compare==0? " << std::boolalpha << (cmp == 0) << "\n\n";
}

// ------------------------------------------------------------
// 5) Conversions and numeric parsing/formatting
// ------------------------------------------------------------
// - c_str(): get const char* for interop
// - stoi/stol/stoll/stof/stod: parse numbers
// - string -> numbers and back

void demoConversions() {
  std::string s = "12345";
  const char *raw = s.c_str(); // null-terminated pointer
  int value = std::stoi(s);    // throws std::invalid_argument or std::out_of_range on failure

  long long big = std::stoll("9223372036854775807");
  double pi = std::stod("3.14159");

  // to_string for basic types
  std::string msg = "value=" + std::to_string(value) + ", pi=" + std::to_string(pi);

  cout << "[Conversions]\n";
  cout << "raw(c_str)=" << raw << ", parsed value=" << value << ", big=" << big
       << ", pi=" << pi << "\n";
  cout << msg << "\n\n";
}

// ------------------------------------------------------------
// 6) Input: std::cin vs std::getline
// ------------------------------------------------------------
// - operator>> reads until whitespace; std::getline reads entire line including spaces.
// - To mix them: after operator>>, consume the leftover newline before getline.

void demoInput() {
  cout << "[Input] (demo uses an istringstream instead of user input)\n";
  std::istringstream in("42\nHello world line\n");

  int x;
  in >> x;             // reads 42, leaves '\n' pending
  in.ignore(1);        // consume the '\n' (important when switching to getline)

  std::string line;
  std::getline(in, line);

  cout << "x=" << x << ", line=\"" << line << "\"\n\n";
}

// ------------------------------------------------------------
// 7) std::string_view for efficient read-only APIs
// ------------------------------------------------------------
// - Pass string-like input as std::string_view when you don't need ownership.
// - Avoid dangling: the viewed data must outlive the string_view.

size_t countVowels(std::string_view sv) {
  size_t count = 0;
  for (char ch : sv) {
    char c = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
  }
  return count;
}

void demoStringView() {
  std::string owned = "Documentation";
  std::string_view sv = owned; // ok: owned outlives sv
  size_t v1 = countVowels(sv);
  size_t v2 = countVowels("temporary literal"); // ok: literal static storage

  cout << "[string_view]\n";
  cout << "vowels('" << owned << "')=" << v1
       << ", vowels(literal)=" << v2 << "\n\n";
}

// ------------------------------------------------------------
// 8) Splitting and joining examples
// ------------------------------------------------------------

std::vector<std::string> splitOn(std::string_view sv, char delim) {
  std::vector<std::string> parts;
  std::string current;
  for (char ch : sv) {
    if (ch == delim) {
      parts.push_back(current);
      current.clear();
    } else {
      current.push_back(ch);
    }
  }
  parts.push_back(current);
  return parts;
}

std::string joinWith(const std::vector<std::string> &parts, std::string_view sep) {
  if (parts.empty()) return "";
  std::string out = parts.front();
  for (size_t i = 1; i < parts.size(); ++i) {
    out += sep;
    out += parts[i];
  }
  return out;
}

void demoSplitJoin() {
  cout << "[Split/Join]\n";
  auto parts = splitOn("one,two,three", ',');
  std::string joined = joinWith(parts, " | ");
  cout << "joined: " << joined << "\n\n";
}

// ------------------------------------------------------------
// 9) Trimming whitespace helpers
// ------------------------------------------------------------

std::string_view ltrim(std::string_view sv) {
  size_t i = 0;
  while (i < sv.size() && std::isspace(static_cast<unsigned char>(sv[i]))) i++;
  return sv.substr(i);
}

std::string_view rtrim(std::string_view sv) {
  size_t i = sv.size();
  while (i > 0 && std::isspace(static_cast<unsigned char>(sv[i - 1]))) i--;
  return sv.substr(0, i);
}

std::string_view trim(std::string_view sv) {
  return rtrim(ltrim(sv));
}

void demoTrim() {
  cout << "[Trim]\n";
  std::string_view raw = "  \t hello world  \n";
  std::string_view trimmed = trim(raw);
  cout << "raw=|" << raw << "|\ntrimmed=|" << trimmed << "|\n\n";
}

// ------------------------------------------------------------
// 10) Notes on performance and pitfalls
// ------------------------------------------------------------
// - Prefer `reserve` when you know the final size to avoid reallocations.
// - Avoid repeated concatenations in loops; consider building via `append`, `reserve`,
//   or using string streams.
// - `std::string_view` is non-owning; never return a view to a temporary.
// - For Unicode (emoji/non-ASCII), `char`/`std::string` hold bytes (often UTF-8). Some
//   operations (like size/indexing) become byte-based, not character-based.

void demoPerformance() {
  cout << "[Performance]\n";
  std::string builder;
  builder.reserve(1000);
  for (int i = 0; i < 10; ++i) {
    builder.append("item=");
    builder.append(std::to_string(i));
    builder.push_back('\n');
  }
  cout << builder << "\n";
}

int main() {
  demoCharacters();
  demoStringBasics();
  demoStringOperations();
  demoSubstringSearchCompare();
  demoConversions();
  demoInput();
  demoStringView();
  demoSplitJoin();
  demoTrim();
  demoPerformance();
  return 0;
}


