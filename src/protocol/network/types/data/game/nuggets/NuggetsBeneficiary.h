#ifndef NUGGETSBENEFICIARY_H
#define NUGGETSBENEFICIARY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class NuggetsBeneficiary : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NuggetsBeneficiary(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NuggetsBeneficiary(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NuggetsBeneficiary(FuncTree tree);
  NuggetsBeneficiary();
  bool operator==(const NuggetsBeneficiary &compared);

  double beneficiaryPlayerId;
  int nuggetsQuantity;

private:
  void _beneficiaryPlayerIdFunc(Reader *input);
  void _nuggetsQuantityFunc(Reader *input);
};

#endif // NUGGETSBENEFICIARY_H