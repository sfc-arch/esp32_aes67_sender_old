#ifndef AES67_HPP

#define AES67_HPP

#include "Rtp.hpp"

class AES67 : public RTP
{
 private:
   // bool RTP_PADDING = false;
   // bool RTP_EXTENSION = false;
   // unsigned short RTP_CSRCCOUNT = 0;
   // unsigned short RTP_MARKER = 0;
   // unsigned short RTP_PAYLOADTYPE = 11;
   
 protected:
   String _payloadFormat;
   unsigned int _samplingRate;
   unsigned short _bit;
   unsigned short _packetTimeMicroseconds;
   unsigned short _packetSampleCount;
   unsigned short _maxChannels;
   String _payload;
   unsigned int * _samples;

 public:
   // structors
   AES67(
      String payloadFormat,
      unsigned int samplingRate,
      unsigned short bit,
      unsigned short packetTimeMicroseconds,
      unsigned short packetSampleCount,
      unsigned short maxChannels,
      unsigned short rtp_sequenceNumber,
      unsigned int rtp_timestamp,
      unsigned int rtp_ssrcIdentifier
   );
   AES67(
      unsigned short rtp_sequenceNumber,
      unsigned int rtp_timestamp,
      unsigned int rtp_ssrcIdentifier
   );
   ~AES67();

   // inline
   int samplingRate();

   //others
   // AES67 next(unsigned int timestamp);
   String info();
   String payload();
   void addSample(unsigned int sample, unsigned int position);
   void addSampleSample(unsigned int n);
   String createUdpPayload(); // create RTP packet inside, add payload, do toString()
};

#endif // :AES67_HPP