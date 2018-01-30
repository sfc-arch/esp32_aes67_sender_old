#include <Arduino.h>
#include "AES67.hpp"
#include "ex_string.hpp"

namespace aes67_cpp
{
bool RTP_PADDING = false;
bool RTP_EXTENSION = false;
unsigned short RTP_CSRCCOUNT = 0;
unsigned short RTP_MARKER = 0;
unsigned short RTP_PAYLOADTYPE = 11;
}

AES67::AES67(
    unsigned short rtp_sequenceNumber,
    unsigned int rtp_timestamp,
    unsigned int rtp_ssrcIdentifier) : RTP(aes67_cpp::RTP_PADDING,
                                           aes67_cpp::RTP_EXTENSION,
                                           aes67_cpp::RTP_CSRCCOUNT,
                                           aes67_cpp::RTP_MARKER,
                                           aes67_cpp::RTP_PAYLOADTYPE,
                                           rtp_sequenceNumber,
                                           rtp_timestamp,
                                           rtp_ssrcIdentifier){};

AES67::AES67(
    String payloadFormat,
    unsigned int samplingRate,
    unsigned short bit,
    unsigned short packetTimeMicroseconds,
    unsigned short packetSampleCount,
    unsigned short maxChannels,
    unsigned short rtp_sequenceNumber,
    unsigned int rtp_timestamp,
    unsigned int rtp_ssrcIdentifier) : RTP(aes67_cpp::RTP_PADDING,
                                           aes67_cpp::RTP_EXTENSION,
                                           aes67_cpp::RTP_CSRCCOUNT,
                                           aes67_cpp::RTP_MARKER,
                                           aes67_cpp::RTP_PAYLOADTYPE,
                                           rtp_sequenceNumber,
                                           rtp_timestamp,
                                           rtp_ssrcIdentifier)
{
   _payloadFormat = payloadFormat;
   _samplingRate = samplingRate;
   _bit = bit;
   _packetTimeMicroseconds = packetTimeMicroseconds;
   _packetSampleCount = packetSampleCount;
   _maxChannels = maxChannels;
   _samples = (unsigned int *)calloc(_packetSampleCount, sizeof(unsigned int));
};

AES67::~AES67() {
//    free(_samples);  // Problem with multi heap freeing.
};

String AES67::info()
{
   String str = "";
   str += "PayloadFormat: ";
   str += _payloadFormat;
   str += "\n";
   str += "Payload: ";
   str += payload();
   str += "\n";
   str += "Timestamp: ";
   str += timestampBinary();
   return str;
};

String AES67::payload()
{
   String str = "";
   for (int position = 0; position < _packetSampleCount; position++)
   {
      // Serial.println(_samples[position]);
      ExString sampleHex = String(_samples[position], BIN);
      str = str + sampleHex.pad(ExString::PadDirection::LEADING, _bit, '0');
      // str += " ";
   };
   return str;
};

/*!
 * Adds (updates) a sample at the given position of array.
 * Will ignore if the given position is out of bounds.
 */
void AES67::addSample(unsigned int sample, unsigned int position)
{
   if (position < _packetSampleCount)
   {
      _samples[position] = sample;
   };
   // return *this;
};

void AES67::addSampleSample(unsigned int n)
{
   for (int i = 0; i < _packetSampleCount; i++)
   {
      addSample(n, i);
   };
};

String AES67::createUdpPayload()
{
   setPayload(payload());
   return toString();
};