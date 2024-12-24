#ifndef GUILDSELECTCHESTTABREQUESTMESSAGE_H
#define GUILDSELECTCHESTTABREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildSelectChestTabRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildSelectChestTabRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildSelectChestTabRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildSelectChestTabRequestMessage(FuncTree tree);
  GuildSelectChestTabRequestMessage();

  uint tabNumber;

private:
  void _tabNumberFunc(Reader *input);
};

#endif // GUILDSELECTCHESTTABREQUESTMESSAGE_H