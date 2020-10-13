#ifndef EXCHANGESETCRAFTRECIPEMESSAGE_H
#define EXCHANGESETCRAFTRECIPEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeSetCraftRecipeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeSetCraftRecipeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeSetCraftRecipeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeSetCraftRecipeMessage(FuncTree tree);
  ExchangeSetCraftRecipeMessage();

  uint objectGID;

private:
  void _objectGIDFunc(Reader *input);
};

#endif // EXCHANGESETCRAFTRECIPEMESSAGE_H