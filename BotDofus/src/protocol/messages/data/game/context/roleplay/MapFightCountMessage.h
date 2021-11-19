#ifndef MAPFIGHTCOUNTMESSAGE_H
#define MAPFIGHTCOUNTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MapFightCountMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapFightCountMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapFightCountMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapFightCountMessage(FuncTree tree);
  MapFightCountMessage();

  uint fightCount;

private:
  void _fightCountFunc(Reader *input);
};

#endif // MAPFIGHTCOUNTMESSAGE_H