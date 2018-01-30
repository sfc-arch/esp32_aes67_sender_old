#ifndef RTP_HPP

#define RTP_HPP

#include <Arduino.h>
#include "ex_string.hpp"

#define MAX_CSRC_SIZE 15
#define RTP_VERSION 2

#define VERSION_BITS 2
#define PADDING_BITS 1
#define EXTENSION_BITS 1
#define CSRC_COUNT_BITS 4
#define MARKER_BITS 1
#define PAYLOAD_TYPE_BITS 7
#define SEQUENCE_NUMBER_BITS 16
#define TIMESTAMP_BITS 32
#define SSRC_IDENTIFIER_BITS 32
#define CSRC_IDENTIFIER_BITS 32

class RTP
{
   // statics
   // static const unsigned short RTP_VERSION;
   // static const unsigned short MAX_CSRC_SIZE;
   // static const unsigned short BIT;
   // static const unsigned short PACKET_TIME;
   // static const unsigned short PACKET_SAMPLE_COUNT;
   // static const unsigned short MAX_CHANNELS;

 private:
   // member variables
   unsigned short _version = RTP_VERSION;
   bool _padding;
   bool _extension;
   unsigned short _csrcCount;
   unsigned short _marker;
   unsigned short _payloadType;
   unsigned short _sequenceNumber;
   unsigned int _timestamp;
   unsigned int _ssrcIdentifier;
   unsigned int _csrcIdentifiers[MAX_CSRC_SIZE];
   // bool _extentionHeaderIsPresent;
   String _payload = "";

 public:
   // structors
   RTP();
   RTP(String packet);
   RTP(
       bool padding,
       bool extension,
       unsigned short csrcCount,
       unsigned short marker,
       unsigned short payloadType,
       unsigned short sequenceNumber,
       unsigned int timestamp,
       unsigned int ssrcIdentifier);
   ~RTP();

   // inline
   unsigned short version();
   bool padding();
   bool extension();
   unsigned short csrcCount();
   unsigned short marker();
   unsigned short payloadType();
   unsigned short sequenceNumber();
   unsigned int timestamp();
   unsigned int ssrcIdentifier();
   // unsigned int csrcIdentifires();
   unsigned int (&csrcIdentifiers())[MAX_CSRC_SIZE];

   inline unsigned short setVersion(unsigned short version);
   inline bool setPadding(bool padding);
   inline bool setExtension(bool extension);
   inline unsigned short setCsrcCount(unsigned short csrcCount);
   inline unsigned short setMarker(unsigned short marker);
   inline unsigned short setPayloadType(unsigned short payloadType);
   inline unsigned short setSequenceNumber(unsigned short sequenceNumber);
   inline unsigned int setTimeStamp(unsigned int timestamp);
   inline unsigned int setSsrcIdentifier(unsigned int ssrcIdentifier);
   inline String setPayload(String payload);

   String versionBinary();
   String paddingBinary();
   String extensionBinary();
   String csrcCountBinary();
   String markerBinary();
   String payloadTypeBinary();
   String sequenceNumberBinary();
   String timestampBinary();
   String ssrcIdentifierBinary();

   //others
   unsigned int (&addCsrcIdentifier())[MAX_CSRC_SIZE];
   String csrcIdentifiersBinary();
   bool validProperties();
   String info();
   String toString();
};

inline unsigned short RTP::version() { return _version; };
inline bool RTP::padding() { return _padding; };
inline bool RTP::extension() { return _extension; };
inline unsigned short RTP::csrcCount() { return _csrcCount; };
inline unsigned short RTP::marker() { return _marker; };
inline unsigned short RTP::payloadType() { return _payloadType; };
inline unsigned short RTP::sequenceNumber() { return _sequenceNumber; };
inline unsigned int RTP::timestamp() { return _timestamp; };
inline unsigned int RTP::ssrcIdentifier() { return _ssrcIdentifier; };
inline unsigned int (&RTP::csrcIdentifiers())[MAX_CSRC_SIZE] { return _csrcIdentifiers; };

inline unsigned short RTP::setVersion(unsigned short version)
{
   _version = version;
   return _version;
};
inline bool RTP::setPadding(bool padding)
{
   _padding = padding;
   return _padding;
};
inline bool RTP::setExtension(bool extension)
{
   _extension = extension;
   return _extension;
};
inline unsigned short RTP::setCsrcCount(unsigned short csrcCount)
{
   _csrcCount = csrcCount;
   return _csrcCount;
};
inline unsigned short RTP::setMarker(unsigned short marker)
{
   _marker = marker;
   return _marker;
};
inline unsigned short RTP::setPayloadType(unsigned short payloadType)
{
   _payloadType = payloadType;
   return _payloadType;
};
inline unsigned short RTP::setSequenceNumber(unsigned short sequenceNumber)
{
   _sequenceNumber = sequenceNumber;
   return _sequenceNumber;
};
inline unsigned int RTP::setTimeStamp(unsigned int timestamp)
{
   _timestamp = timestamp;
   return _timestamp;
};
inline unsigned int RTP::setSsrcIdentifier(unsigned int ssrcIdentifier)
{
   _ssrcIdentifier = ssrcIdentifier;
   return _ssrcIdentifier;
};
inline String RTP::setPayload(String payload)
{
   _payload = payload;
   return _payload;
};

inline String RTP::versionBinary() { return ExString(String(_version, BIN)).padLeft(VERSION_BITS, '0'); };
inline String RTP::paddingBinary() { return ExString(String(_padding, BIN)).padLeft(PADDING_BITS, '0'); };
inline String RTP::extensionBinary() { return ExString(String(_extension, BIN)).padLeft(EXTENSION_BITS, '0'); };
inline String RTP::csrcCountBinary() { return ExString(String(_csrcCount, BIN)).padLeft(CSRC_COUNT_BITS, '0'); };
inline String RTP::markerBinary() { return ExString(String(_marker, BIN)).padLeft(MARKER_BITS, '0'); };
inline String RTP::payloadTypeBinary() { return ExString(String(_payloadType, BIN)).padLeft(PAYLOAD_TYPE_BITS, '0'); };
inline String RTP::sequenceNumberBinary() { return ExString(String(_sequenceNumber, BIN)).padLeft(SEQUENCE_NUMBER_BITS, '0'); };
inline String RTP::timestampBinary() { return ExString(String(_timestamp, BIN)).padLeft(TIMESTAMP_BITS, '0'); };
inline String RTP::ssrcIdentifierBinary() { return ExString(String(_ssrcIdentifier, BIN)).padLeft(SSRC_IDENTIFIER_BITS, '0'); };

#endif // :RTP_HPP

/** *** *** Structure *** ***

0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|V=2|P|X|  CC   |M|     PT      |       sequence number         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                           timestamp (not unix timestamp)      | # ジッター測ったりソース同士シンクロさせたり
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           synchronization source (SSRC) identifier            | # ミキサーが混ぜるときに使う ソース毎固定
+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
|            contributing source (CSRC) identifiers             | # mixerが混ぜたときに混ぜた↑を書く
|                             ....                              |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

## サンプルヘッダー

10 0 0 0000 0 0001011 1000001111101101
00000000000000000000000001111110
10101010101010101010101010101010
(CSRCはない CCも0だし)

*/