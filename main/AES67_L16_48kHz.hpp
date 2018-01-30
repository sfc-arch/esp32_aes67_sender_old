#ifndef AES67_L16_48KHZ

#define AES67_L16_48KHZ

#include "AES67.hpp"

class AES67_L16_48kHz : public AES67
{
   // statics
   static const String PAYLOAD_FORMAT;
   static const unsigned int SAMPLING_RATE;
   static const unsigned short BIT;
   static const unsigned short PACKET_TIME;
   static const unsigned short PACKET_SAMPLE_COUNT;
   static const unsigned short MAX_CHANNELS;

 private:

 public:
   // structors
   AES67_L16_48kHz();
   AES67_L16_48kHz(
      unsigned short sequenceNumber,
      unsigned int timestamp,
      unsigned int ssrcIdentifier
   );
   AES67_L16_48kHz(
      AES67_L16_48kHz old,
      unsigned int timestamp
   );

   // others

   /*!
    * Creates sample payload by adding the given sample _payloadSampleCount times.
    */
   // void addSampleSample(unsigned int n);
   // AES67_L16_48kHz next(unsigned int timestamp);
};

#endif