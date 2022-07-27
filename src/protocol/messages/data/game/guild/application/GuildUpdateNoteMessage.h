#ifndef GUILDUPDATENOTEMESSAGE_H
#define GUILDUPDATENOTEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildUpdateNoteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildUpdateNoteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildUpdateNoteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildUpdateNoteMessage(FuncTree tree);
  GuildUpdateNoteMessage();

  double memberId;
  QString note;

private:
  void _memberIdFunc(Reader *input);
  void _noteFunc(Reader *input);
};

#endif // GUILDUPDATENOTEMESSAGE_H