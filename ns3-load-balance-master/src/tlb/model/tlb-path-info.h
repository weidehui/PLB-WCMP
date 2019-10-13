#ifndef TLB_PATH_INFO_H
#define TLB_PATH_INFO_H

#include "ns3/nstime.h"

namespace ns3 {

class TLBPathInfo
{
public:
  uint32_t pathId;
  uint32_t size;
  uint32_t ecnSize;
  Time minRtt;
  bool isRetransmission;
  bool isHighRetransmission;
  bool isTimeout;
  bool isVeryTimeout;
  bool isProbingTimeout;
  uint32_t flowCounter;
  Time timeStamp1;
  Time timeStamp2;
  Time timeStamp3;
  uint32_t dreValue;
  // uint32_t dreValueremote;

  // Added at Jan 11st
  /*
  uint32_t epAckSize;
  uint32_t epEcnSize;
  double epEcnPortion;
  Time epTimeStamp;
  */
  // --

  //Dehui
  //double lossrate;
  double pathweight;
  uint32_t thelosssize;
  Time rtt;
  // uint32_t unitysize;
  // uint32_t unitysizeremote;
  uint32_t sizeremote;

};

}

#endif
