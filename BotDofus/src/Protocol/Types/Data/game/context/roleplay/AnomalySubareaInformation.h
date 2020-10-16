#ifndef ANOMALYSUBAREAINFORMATION_H
#define ANOMALYSUBAREAINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AnomalySubareaInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AnomalySubareaInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AnomalySubareaInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AnomalySubareaInformation(FuncTree tree);
  AnomalySubareaInformation();
  bool operator==(const AnomalySubareaInformation &compared);

  uint subAreaId;
  int rewardRate;
  bool hasAnomaly;
  double anomalyClosingTime;

private:
  void _subAreaIdFunc(Reader *input);
  void _rewardRateFunc(Reader *input);
  void _hasAnomalyFunc(Reader *input);
  void _anomalyClosingTimeFunc(Reader *input);
};

#endif // ANOMALYSUBAREAINFORMATION_H