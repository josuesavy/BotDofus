#ifndef EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE_H
#define EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeMultiCraftCrafterCanUseHisRessourcesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(FuncTree tree);
  ExchangeMultiCraftCrafterCanUseHisRessourcesMessage();

  bool allowed;

private:
  void _allowedFunc(Reader *input);
};

#endif // EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE_H