/*
4.5.11 L16

   L16 denotes uncompressed audio data samples, using 16-bit signed
   representation with 65,535 equally divided steps between minimum and
   maximum signal level, ranging from -32,768 to 32,767.  The value is
   represented in two's complement notation and transmitted in network
   byte order (most significant byte first).

   The MIME registration for L16 in RFC 3555 [7] specifies parameters
   that MAY be used with MIME or SDP to indicate that analog pre-
   emphasis was applied to the signal before quantization or to indicate
   that a multiple-channel audio stream follows a different channel
   ordering convention than is specified in Section 4.1.


               PT   encoding    media type  clock rate   channels
                    name                    (Hz)
               ___________________________________________________
               0    PCMU        A            8,000       1
               1    reserved    A
               2    reserved    A
               3    GSM         A            8,000       1
               4    G723        A            8,000       1
               5    DVI4        A            8,000       1
               6    DVI4        A           16,000       1
               7    LPC         A            8,000       1
               8    PCMA        A            8,000       1
               9    G722        A            8,000       1
            *  10   L16         A           44,100       2
            *  11   L16         A           44,100       1
               12   QCELP       A            8,000       1
               13   CN          A            8,000       1
               14   MPA         A           90,000       (see text)
               15   G728        A            8,000       1
               16   DVI4        A           11,025       1
               17   DVI4        A           22,050       1
               18   G729        A            8,000       1
               19   reserved    A
               20   unassigned  A
               21   unassigned  A
               22   unassigned  A
               23   unassigned  A
               dyn  G726-40     A            8,000       1
               dyn  G726-32     A            8,000       1
               dyn  G726-24     A            8,000       1
               dyn  G726-16     A            8,000       1
               dyn  G729D       A            8,000       1
               dyn  G729E       A            8,000       1
               dyn  GSM-EFR     A            8,000       1
               dyn  L8          A            var.        var.
               dyn  RED         A                        (see text)
               dyn  VDVI        A            var.        1

               Table 4: Payload types (PT) for audio encodings
*/

#include <Arduino.h>
#include "AES67_L16_48kHz.hpp"

// consts
const String AES67_L16_48kHz::PAYLOAD_FORMAT = "L16";
const unsigned int AES67_L16_48kHz::SAMPLING_RATE = 48000;
const unsigned short AES67_L16_48kHz::BIT = 16;
const unsigned short AES67_L16_48kHz::PACKET_TIME = 250;
const unsigned short AES67_L16_48kHz::PACKET_SAMPLE_COUNT = 12;
const unsigned short AES67_L16_48kHz::MAX_CHANNELS = 60;

AES67_L16_48kHz::AES67_L16_48kHz() : AES67(
   PAYLOAD_FORMAT,
   SAMPLING_RATE,
   BIT,
   PACKET_TIME,
   PACKET_SAMPLE_COUNT,
   MAX_CHANNELS,
   33773,
   126,
   2863311530
) {};

AES67_L16_48kHz::AES67_L16_48kHz(
   unsigned short sequenceNumber,
   unsigned int timestamp,
   unsigned int ssrcIdentifier
) : AES67(
   PAYLOAD_FORMAT,
   SAMPLING_RATE,
   BIT,
   PACKET_TIME,
   PACKET_SAMPLE_COUNT,
   MAX_CHANNELS,
   sequenceNumber,
   timestamp,
   ssrcIdentifier
) {};

AES67_L16_48kHz::AES67_L16_48kHz(
   AES67_L16_48kHz old,
   unsigned int timestamp
) : AES67(
   PAYLOAD_FORMAT,
   SAMPLING_RATE,
   BIT,
   PACKET_TIME,
   PACKET_SAMPLE_COUNT,
   MAX_CHANNELS,
   old.sequenceNumber(),
   timestamp,
   old.ssrcIdentifier()
) {};

// AES67 AES67_L16_48kHz::addSample(unsigned int sample)
// {
//    return *this;
// };

// void AES67_L16_48kHz::addSampleSample(unsigned int n)
// {
//    for (int i = 0; i < _packetSampleCount; i++)
//    {
//       addSample(n, i);
//    };
// };

// AES67_L16_48kHz AES67_L16_48kHz::next(unsigned int timestamp)
// {
//    AES67_L16_48kHz n(
//        sequenceNumber() + 1,
//        timestamp,
//        ssrcIdentifier());
//    // delete this;
//    return n;
// };
