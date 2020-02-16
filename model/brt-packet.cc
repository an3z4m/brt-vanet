/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 Kerkacha Nabil
 */
#include "brt-packet.h"
#include "ns3/address-utils.h"
#include "ns3/packet.h"

namespace ns3 {
namespace brt {

NS_OBJECT_ENSURE_REGISTERED (BrtHeader);

BrtHeader::BrtHeader (Ipv4Address dst, uint32_t hopCount, uint32_t dstSeqNo)
  : m_dst (dst),
    m_hopCount (hopCount),
    m_dstSeqNo (dstSeqNo)
{
}

BrtHeader::~BrtHeader ()
{
}

TypeId
BrtHeader::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::brt::BrtHeader")
    .SetParent<Header> ()
    .SetGroupName ("Brt")
    .AddConstructor<BrtHeader> ();
  return tid;
}

TypeId
BrtHeader::GetInstanceTypeId () const
{
  return GetTypeId ();
}

uint32_t
BrtHeader::GetSerializedSize () const
{
  return 12;
}

void
BrtHeader::Serialize (Buffer::Iterator i) const
{
  WriteTo (i, m_dst);
  i.WriteHtonU32 (m_hopCount);
  i.WriteHtonU32 (m_dstSeqNo);

}

uint32_t
BrtHeader::Deserialize (Buffer::Iterator start)
{
  Buffer::Iterator i = start;

  ReadFrom (i, m_dst);
  m_hopCount = i.ReadNtohU32 ();
  m_dstSeqNo = i.ReadNtohU32 ();

  uint32_t dist = i.GetDistanceFrom (start);
  NS_ASSERT (dist == GetSerializedSize ());
  return dist;
}

void
BrtHeader::Print (std::ostream &os) const
{
  os << "DestinationIpv4: " << m_dst
     << " Hopcount: " << m_hopCount
     << " SequenceNumber: " << m_dstSeqNo;
}
}
}
