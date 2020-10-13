#ifndef EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE_H
#define EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(FuncTree tree);
  ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage();

  bool allow;

private:
  void _allowFunc(Reader *input);
};

#endif // EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE_H