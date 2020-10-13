#ifndef PADDOCKTOSELLFILTERMESSAGE_H
#define PADDOCKTOSELLFILTERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PaddockToSellFilterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockToSellFilterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockToSellFilterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockToSellFilterMessage(FuncTree tree);
  PaddockToSellFilterMessage();

  int areaId;
  int atLeastNbMount;
  int atLeastNbMachine;
  double maxPrice;
  uint orderBy;

private:
  void _areaIdFunc(Reader *input);
  void _atLeastNbMountFunc(Reader *input);
  void _atLeastNbMachineFunc(Reader *input);
  void _maxPriceFunc(Reader *input);
  void _orderByFunc(Reader *input);
};

#endif // PADDOCKTOSELLFILTERMESSAGE_H