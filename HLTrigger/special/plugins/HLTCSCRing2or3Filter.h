#ifndef HLTCSCRing2or3Filter_h
#define HLTCSCRing2or3Filter_h

#include <vector>
#include <map>

#include "HLTrigger/HLTcore/interface/HLTFilter.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/CSCRecHit/interface/CSCRecHit2DCollection.h"
#include "Geometry/CSCGeometry/interface/CSCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"

namespace edm {
  class ConfigurationDescriptions;
}

class HLTCSCRing2or3Filter : public HLTFilter {
public:
  explicit HLTCSCRing2or3Filter(const edm::ParameterSet&);
  ~HLTCSCRing2or3Filter() override;
  bool hltFilter(edm::Event&,
                 const edm::EventSetup&,
                 trigger::TriggerFilterObjectWithRefs& filterproduct) const override;
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  edm::ESGetToken<CSCGeometry, MuonGeometryRecord> const muonGeometryRecordToken_;
  edm::EDGetTokenT<CSCRecHit2DCollection> cscrechitsToken;
  edm::InputTag m_input;
  unsigned int m_minHits;
  double m_xWindow, m_yWindow;
};

#endif
