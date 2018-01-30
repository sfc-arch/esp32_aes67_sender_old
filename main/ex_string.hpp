#ifndef EX_STRING_HPP

#include <Arduino.h>
#define EX_STRING_HPP

class ExString : public String
{
 private:
 public:
   typedef enum PadDirection {
      LEADING = 1,
      TRAILING = 2
   } ex_string_pad_direction;

   // string, char, byte, int, long, unsigned int, unsigned long, float, double
   ExString(const char str);
   ExString(const char *str);
   ExString(const byte str);
   ExString(const int str);
   ExString(const long str);
   ExString(const unsigned int str);
   ExString(const unsigned long str);
   ExString(const float str);
   ExString(const double str);
   ExString(const String str);

   ExString operator*(unsigned int count) noexcept;
   ExString pad(ex_string_pad_direction direction, const unsigned int resultSize) noexcept;
   ExString pad(ex_string_pad_direction direction, const unsigned int resultSize, const char c) noexcept;
   ExString padLeft(const unsigned int resultSize, const char c) noexcept;
   ExString padRight(const unsigned int resultSize, const char c) noexcept;
   unsigned int binaryToInt(); 
};

#endif
