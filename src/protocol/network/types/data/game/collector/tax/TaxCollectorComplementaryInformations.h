#ifndef TAXCOLLECTORCOMPLEMENTARYINFORMATIONS_H
#define TAXCOLLECTORCOMPLEMENTARYINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class TaxCollectorComplementaryInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorComplementaryInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorComplementaryInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorComplementaryInformations(FuncTree tree);
  TaxCollectorComplementaryInformations();
  bool operator==(const TaxCollectorComplementaryInformations &compared);
};

#endif // TAXCOLLECTORCOMPLEMENTARYINFORMATIONS_H