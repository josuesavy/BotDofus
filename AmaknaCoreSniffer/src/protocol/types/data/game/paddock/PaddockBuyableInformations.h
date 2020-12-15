#ifndef PADDOCKBUYABLEINFORMATIONS_H
#define PADDOCKBUYABLEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PaddockBuyableInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockBuyableInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockBuyableInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockBuyableInformations(FuncTree tree);
  PaddockBuyableInformations();
  bool operator==(const PaddockBuyableInformations &compared);

  double price;
  bool locked;

private:
  void _priceFunc(Reader *input);
  void _lockedFunc(Reader *input);
};

#endif // PADDOCKBUYABLEINFORMATIONS_H