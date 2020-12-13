#ifndef GUILDINFORMATIONSPADDOCKSMESSAGE_H
#define GUILDINFORMATIONSPADDOCKSMESSAGE_H

#include "src/protocol/types/data/game/paddock/PaddockContentInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildInformationsPaddocksMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInformationsPaddocksMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInformationsPaddocksMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInformationsPaddocksMessage(FuncTree tree);
  GuildInformationsPaddocksMessage();

  uint nbPaddockMax;
  QList<PaddockContentInformations> paddocksInformations;

private:
  void _nbPaddockMaxFunc(Reader *input);
  void _paddocksInformationstreeFunc(Reader *input);
  void _paddocksInformationsFunc(Reader *input);

  FuncTree _paddocksInformationstree;
};

#endif // GUILDINFORMATIONSPADDOCKSMESSAGE_H