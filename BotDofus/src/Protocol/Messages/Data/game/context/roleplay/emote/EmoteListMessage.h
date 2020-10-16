#ifndef EMOTELISTMESSAGE_H
#define EMOTELISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class EmoteListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmoteListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmoteListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmoteListMessage(FuncTree tree);
  EmoteListMessage();

  QList<uint> emoteIds;

private:
  void _emoteIdstreeFunc(Reader *input);
  void _emoteIdsFunc(Reader *input);

  FuncTree _emoteIdstree;
};

#endif // EMOTELISTMESSAGE_H