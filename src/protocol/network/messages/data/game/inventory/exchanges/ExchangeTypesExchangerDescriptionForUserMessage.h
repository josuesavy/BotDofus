#ifndef EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE_H
#define EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeTypesExchangerDescriptionForUserMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeTypesExchangerDescriptionForUserMessage(FuncTree tree);
  ExchangeTypesExchangerDescriptionForUserMessage();

  uint objectType;
  QList<uint> typeDescription;

private:
  void _objectTypeFunc(Reader *input);
  void _typeDescriptiontreeFunc(Reader *input);
  void _typeDescriptionFunc(Reader *input);

  FuncTree _typeDescriptiontree;
};

#endif // EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE_H