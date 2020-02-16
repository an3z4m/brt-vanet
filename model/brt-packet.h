/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 Kerkacha Nabil
 */

#ifndef BRT_PACKET_H
#define BRT_PACKET_H

#include <iostream>
#include "ns3/header.h"
#include "ns3/ipv4-address.h"
#include "ns3/nstime.h"

namespace ns3 {
namespace brt {
/**
 * \ingroup brt
 * \brief BRT Update Packet Format
 * \verbatim
 |      0        |      1        |      2        |       3       |
  0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                      Destination Address                      |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                            HopCount                           |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |                       Sequence Number                         |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * \endverbatim
 */

class BrtHeader : public Header
{
public:
  /**
   * Constructor
   *
   * \param dst destination IP address
   * \param hopcount hop count
   * \param dstSeqNo destination sequence number
   */
  BrtHeader (Ipv4Address dst = Ipv4Address (), uint32_t hopcount = 0, uint32_t dstSeqNo = 0);
  virtual ~BrtHeader ();
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual uint32_t GetSerializedSize () const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);
  virtual void Print (std::ostream &os) const;

  /**
   * Set destination address
   * \param destination the destination IPv4 address
   */
  void
  SetDst (Ipv4Address destination)
  {
    m_dst = destination;
  }
  /**
   * Get destination address
   * \returns the destination IPv4 address
   */
  Ipv4Address
  GetDst () const
  {
    return m_dst;
  }
  /**
   * Set hop count
   * \param hopCount the hop count
   */
  void
  SetHopCount (uint32_t hopCount)
  {
    m_hopCount = hopCount;
  }
  /**
   * Get hop count
   * \returns the hop count
   */
  uint32_t
  GetHopCount () const
  {
    return m_hopCount;
  }
  /**
   * Set destination sequence number
   * \param sequenceNumber The sequence number
   */
  void
  SetDstSeqno (uint32_t sequenceNumber)
  {
    m_dstSeqNo = sequenceNumber;
  }
  /**
   * Get destination sequence number
   * \returns the destination sequence number
   */
  uint32_t
  GetDstSeqno () const
  {
    return m_dstSeqNo;
  }
private:
  Ipv4Address m_dst; ///< Destination IP Address
  uint32_t m_hopCount; ///< Number of Hops
  uint32_t m_dstSeqNo; ///< Destination Sequence Number
};
static inline std::ostream & operator<< (std::ostream& os, const BrtHeader & packet)
{
  packet.Print (os);
  return os;
}
}
}

#endif /* BRT_PACKET_H */
