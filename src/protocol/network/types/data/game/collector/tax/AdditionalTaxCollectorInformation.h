#ifndef ADDITIONALTAXCOLLECTORINFORMATION_H
#define ADDITIONALTAXCOLLECTORINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AdditionalTaxCollectorInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AdditionalTaxCollectorInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AdditionalTaxCollectorInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AdditionalTaxCollectorInformation(FuncTree tree);
  AdditionalTaxCollectorInformation();
  bool operator==(const AdditionalTaxCollectorInformation &compared);

  double collectorCallerId;
  QString collectorCallerName;
  uint date;

private:
  void _collectorCallerIdFunc(Reader *input);
  void _collectorCallerNameFunc(Reader *input);
  void _dateFunc(Reader *input);
};

#endif // ADDITIONALTAXCOLLECTORINFORMATION_H