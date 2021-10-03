#ifndef ADDITIONALTAXCOLLECTORINFORMATIONS_H
#define ADDITIONALTAXCOLLECTORINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AdditionalTaxCollectorInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AdditionalTaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AdditionalTaxCollectorInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AdditionalTaxCollectorInformations(FuncTree tree);
  AdditionalTaxCollectorInformations();
  bool operator==(const AdditionalTaxCollectorInformations &compared);

  QString collectorCallerName;
  uint date;

private:
  void _collectorCallerNameFunc(Reader *input);
  void _dateFunc(Reader *input);
};

#endif // ADDITIONALTAXCOLLECTORINFORMATIONS_H