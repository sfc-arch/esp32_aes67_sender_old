/*

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

#include <Arduino.h>
#include "Rtp.hpp"
#include "ex_string.hpp"

// consts
// const unsigned short RTP::RTP_VERSION = 2;
// const unsigned short RTP::MAX_CSRC_SIZE = 15;

RTP::RTP()
{
   _padding = false;
   _extension = false;
   _csrcCount = 0;
   _marker = 0;
   _payloadType = 0;
   _sequenceNumber = 0;
   _timestamp = 0;
   _ssrcIdentifier = 0;
   for (int i = 0; i < MAX_CSRC_SIZE; i++)
   {
      _csrcIdentifiers[i] = 0;
   };
};

RTP::RTP(
   bool padding,
   bool extension,
   unsigned short csrcCount,
   unsigned short marker,
   unsigned short payloadType,
   unsigned short sequenceNumber,
   unsigned int timestamp,
   unsigned int ssrcIdentifier)
{
   _padding = padding;
   _extension = extension;
   _csrcCount = csrcCount;
   _marker = marker;
   _payloadType = payloadType;
   _sequenceNumber = sequenceNumber;
   _timestamp = timestamp;
   _ssrcIdentifier = ssrcIdentifier;
   for (int i = 0; i < MAX_CSRC_SIZE; i++)
   {
      _csrcIdentifiers[i] = 0;
   };
};

RTP::~RTP()
{
   // if (_csrcIdentifiers != NULL) {
   //    free(_csrcIdentifiers);
   // };
};

String RTP::info()
{
   return
   "Version : " + versionBinary() + "\n" +
   "Padding : " + paddingBinary() + "\n" +
   "Extension : " + extensionBinary() + "\n" +
   "CSRC Count : " + csrcCountBinary() + "\n" +
   "Marker : " + markerBinary() + "\n" +
   "Payload Type : " + payloadTypeBinary() + "\n" +
   "Sequence Number : " + sequenceNumberBinary() + "\n" +
   "Timestamp : " + timestampBinary() + "\n" +
   "SSRC Identifier : " + ssrcIdentifierBinary() + "\n" +
   "Payload : " +  _payload;
};

String RTP::toString()
{
   String rtp("");

   rtp += versionBinary();
   rtp += paddingBinary();
   rtp += extensionBinary();
   rtp += csrcCountBinary();
   rtp += markerBinary();
   rtp += payloadTypeBinary();
   rtp += sequenceNumberBinary();
   rtp += timestampBinary();
   rtp += ssrcIdentifierBinary();
   rtp += _payload;

   return rtp;
};