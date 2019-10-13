/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef LINK_PROBE_H
#define LINK_PROBE_H

#include "ns3/object.h"
#include "ns3/nstime.h"

#include <map>
#include <vector>
#include <string>

namespace ns3 {

class LinkMonitor;

class LinkProbe : public Object
{
public:

  struct LinkStats
  {
    // The check time
    Time        checkTime;

    // The accumulated bytes transmitted on this link   链路累积传送的字节
    uint64_t    accumulatedTxBytes;

    // The utility of this link based on TX 链路利用率
    double      txLinkUtility;

    // The accumulated bytes dequeued on this link     出列的字节 
    uint64_t    accumulatedDequeueBytes;

    // The utility of this link based on dequeue  出列的链路利用率
    double      dequeueLinkUtility;

    uint32_t    packetsInQueue;

    uint32_t    bytesInQueue;

    uint32_t    packetsInQueueDisc;

    uint32_t    bytesInQueueDisc;
  };

  static TypeId GetTypeId (void);

  LinkProbe (Ptr<LinkMonitor> linkMonitor);

  std::map<uint32_t, std::vector<struct LinkStats> > GetLinkStats (void);

  void SetProbeName (std::string name);

  std::string GetProbeName (void);

  virtual void Start () = 0;

  virtual void Stop () = 0;

protected:
  // map <interface, list of link stats collected at different time point>
  // The later ones are inserted at the tail of the list
  std::map<uint32_t, std::vector<struct LinkStats> > m_stats;

  // Used to help identifying the probe
  std::string m_probeName;
};

}

#endif /* LINK_PROBE_H */

