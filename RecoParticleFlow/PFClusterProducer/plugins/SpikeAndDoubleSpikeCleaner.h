#ifndef __SpikeAndDoubleSpikeCleaner_H__
#define __SpikeAndDoubleSpikeCleaner_H__

#include "RecoParticleFlow/PFClusterProducer/interface/RecHitTopologicalCleanerBase.h"
#include "DataFormats/HcalRecHit/interface/HFRecHit.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

#include <unordered_map>

class SpikeAndDoubleSpikeCleaner : public RecHitTopologicalCleanerBase {
public:
  struct spike_cleaning {
    double _singleSpikeThresh;
    double _minS4S1_a;
    double _minS4S1_b;
    double _doubleSpikeS6S2;
    double _eneThreshMod;
    double _fracThreshMod;
    double _doubleSpikeThresh;
  };

  SpikeAndDoubleSpikeCleaner(const edm::ParameterSet& conf, edm::ConsumesCollector& cc);
  SpikeAndDoubleSpikeCleaner(const SpikeAndDoubleSpikeCleaner&) = delete;
  SpikeAndDoubleSpikeCleaner& operator=(const SpikeAndDoubleSpikeCleaner&) = delete;

  void clean(const edm::Handle<reco::PFRecHitCollection>& input, std::vector<bool>& mask) override;

private:
  const std::unordered_map<std::string, int> _layerMap;
  std::unordered_map<int, spike_cleaning> _thresholds;
};

DEFINE_EDM_PLUGIN(RecHitTopologicalCleanerFactory, SpikeAndDoubleSpikeCleaner, "SpikeAndDoubleSpikeCleaner");

#endif
