
//
// F.Ratnikov (UMd), Aug. 9, 2005
// Adapted for CASTOR by L. Mundim
//

#ifndef CastorDbService_h
#define CastorDbService_h

#include <memory>
#include <map>

#include "DataFormats/HcalDetId/interface/HcalGenericDetId.h"
#include "CalibFormats/CastorObjects/interface/CastorChannelCoder.h"
#include "CalibFormats/CastorObjects/interface/QieShape.h"
#include "CalibFormats/CastorObjects/interface/CastorCoder.h"
#include "CalibFormats/CastorObjects/interface/CastorCalibrationsSet.h"
#include "CalibFormats/CastorObjects/interface/CastorCalibrationWidthsSet.h"

#include "CondFormats/CastorObjects/interface/AllObjects.h"

class CastorCalibrations;
class CastorCalibrationWidths;

class CastorDbService {
public:
  CastorDbService();

  const CastorCalibrations& getCastorCalibrations(const HcalGenericDetId& fId) const {
    return mCalibSet.getCalibrations(fId);
  }
  const CastorCalibrationWidths& getCastorCalibrationWidths(const HcalGenericDetId& fId) const {
    return mCalibWidthSet.getCalibrationWidths(fId);
  }

  const CastorPedestal* getPedestal(const HcalGenericDetId& fId) const;
  const CastorPedestalWidth* getPedestalWidth(const HcalGenericDetId& fId) const;
  const CastorGain* getGain(const HcalGenericDetId& fId) const;
  const CastorGainWidth* getGainWidth(const HcalGenericDetId& fId) const;
  const CastorQIECoder* getCastorCoder(const HcalGenericDetId& fId) const;
  const CastorQIEShape* getCastorShape() const;
  const CastorElectronicsMap* getCastorMapping() const;
  const CastorChannelStatus* getCastorChannelStatus(const HcalGenericDetId& fId) const;

  void setData(const CastorPedestals* fItem) { mPedestals = fItem; }
  void setData(const CastorPedestalWidths* fItem) { mPedestalWidths = fItem; }
  void setData(const CastorGains* fItem) { mGains = fItem; }
  void setData(const CastorGainWidths* fItem) { mGainWidths = fItem; }
  void setData(const CastorQIEData* fItem) { mQIEData = fItem; }
  void setData(const CastorChannelQuality* fItem) { mChannelQuality = fItem; }
  void setData(const CastorElectronicsMap* fItem) { mElectronicsMap = fItem; }

  void buildCalibrations();
  void buildCalibWidths();

private:
  bool makeCastorCalibration(const HcalGenericDetId& fId, CastorCalibrations* fObject, bool pedestalInADC) const;
  bool makeCastorCalibrationWidth(const HcalGenericDetId& fId,
                                  CastorCalibrationWidths* fObject,
                                  bool pedestalInADC) const;
  const CastorPedestals* mPedestals;
  const CastorPedestalWidths* mPedestalWidths;
  const CastorGains* mGains;
  const CastorGainWidths* mGainWidths;
  const CastorQIEData* mQIEData;
  const CastorChannelQuality* mChannelQuality;
  const CastorElectronicsMap* mElectronicsMap;
  CastorCalibrationsSet mCalibSet;
  CastorCalibrationWidthsSet mCalibWidthSet;
};

#endif
