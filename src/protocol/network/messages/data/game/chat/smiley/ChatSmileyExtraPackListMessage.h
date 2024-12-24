#ifndef CHATSMILEYEXTRAPACKLISTMESSAGE_H
#define CHATSMILEYEXTRAPACKLISTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ChatSmileyExtraPackListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatSmileyExtraPackListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatSmileyExtraPackListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatSmileyExtraPackListMessage(FuncTree tree);
  ChatSmileyExtraPackListMessage();

  QList<uint> packIds;

private:
  void _packIdstreeFunc(Reader *input);
  void _packIdsFunc(Reader *input);

  FuncTree _packIdstree;
};

#endif // CHATSMILEYEXTRAPACKLISTMESSAGE_H