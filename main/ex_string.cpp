#include <Arduino.h>
#include "ex_string.hpp"

ExString::ExString(const char str) : String(str){};
ExString::ExString(const char *str) : String(str){};
ExString::ExString(const byte str) : String(str){};
ExString::ExString(const int str) : String(str){};
ExString::ExString(const long str) : String(str){};
ExString::ExString(const unsigned int str) : String(str){};
ExString::ExString(const unsigned long str) : String(str){};
ExString::ExString(const float str) : String(str){};
ExString::ExString(const double str) : String(str){};
ExString::ExString(const String str) : String(str){};

ExString ExString::operator*(const unsigned int count) noexcept
{
   ExString temp(*this);
   for (unsigned int i = 0; i < count - 1; i++)
   {
      temp += *this;
   };
   return temp;
};

ExString ExString::pad(ex_string_pad_direction direction, const unsigned int resultSize) noexcept
{
   return pad(direction, resultSize, ' ');
};

/*!
 * @fn
 * ここに関数の説明を書く
 * @brief 要約説明
 * @param (引数名) 引数の説明
 * @param (引数名) 引数の説明
 * @return 戻り値の説明
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 詳細な説明
 * Serial.println( ExString(str).pad(ExString::PadDirection::LEADING, 15) );
 * Serial.println( ExString(str).pad(ExString::PadDirection::TRAILING, 15) );
 * Serial.println( ExString(str).pad(ExString::PadDirection::LEADING, 15, '_') );
 * Serial.println( ExString(str).pad(ExString::PadDirection::TRAILING, 15, '_') );
 * Serial.println( ExString(str).pad(ExString::PadDirection::LEADING, 5) );
 * Serial.println( ExString(str).pad(ExString::PadDirection::TRAILING, 5) );
 * Serial.println( ExString(str).pad(ExString::PadDirection::LEADING, 5, '_') );
 * Serial.println( ExString(str).pad(ExString::PadDirection::TRAILING, 5, '_') );
 */
ExString ExString::pad(ex_string_pad_direction direction, const unsigned int resultSize, const char c) noexcept
{
   ExString temp(*this);
   int sub = resultSize - temp.length();

   if (sub < 0)
   {
      if (direction == PadDirection::LEADING)
      {
         // cut off from the front.
         temp.remove(0, resultSize);
      }
      else
      {
         temp.remove(abs(sub), resultSize);
      };
   }
   else if (sub > 0)
   {
      String pads = ExString(c) * sub;

      if (direction == PadDirection::LEADING)
      {
         temp = pads + temp;
      }
      else
      {
         temp.concat(pads);
      };
   };

   return temp;
};

ExString ExString::padLeft(const unsigned int resultSize, const char c = ' ') noexcept
   {return pad(PadDirection::LEADING, resultSize, c); };

ExString ExString::padRight(const unsigned int resultSize, const char c = ' ') noexcept
   {return pad(PadDirection::TRAILING, resultSize, c); };

unsigned int ExString::binaryToInt() {
   unsigned int result = 0;
   unsigned int i = 1;
   int index = this->length() - 1;

   for (; index >= 0; index--) {
      result = result + ((int)this->charAt(index) - '0') * i;
      i = i * 2;
   }

   return result;
};