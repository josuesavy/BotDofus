#ifndef CHARACTERCAPABILITIESMESSAGE_H
#define CHARACTERCAPABILITIESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterCapabilitiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCapabilitiesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCapabilitiesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCapabilitiesMessage(FuncTree tree);
  CharacterCapabilitiesMessage();

  uint guildEmblemSymbolCategories;

private:
  void _guildEmblemSymbolCategoriesFunc(Reader *input);
};

#endif // CHARACTERCAPABILITIESMESSAGE_H